#include "bank_api.h"

bank_api::bank_api(QObject *parent) : QObject(parent)
{

}

// ** Tarkistetaan kortti, kortin PIN, sekä onko korttiin liitetyllä tilillä credit ominaisuutta **
// cid = Kortin numero
// PIN = Kortin PIN-koodi
// (ref)isCredit = Palautettava true/false siitä onko credit tiliä liitettynä
// (ref)message = Palauttaa mahdollisen virheviestin
// Palauttaa true, jos PIN koodi on ok ja false jos ei ole ok tai virhe tapahtui
bool bank_api::checkPIN(QString cid, QString PIN, bool& isCredit, QString& message)
{
    //Alustukset
    isCredit = false;
    message = "";
    bool pinOK = false;

    // Luodaan sisäinen event loop
    QEventLoop eventLoop;

    // Luodaan JSON objekti ja lisätään data
    QJsonObject json;
    json.insert("cardId",cid);
    json.insert("pin",PIN);
    QNetworkRequest request(_site_url + "checkPinCredit");
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QByteArray data = _credentials.toLocal8Bit().toBase64();
    QString headerData = "Basic " + data;
    request.setRawHeader( "Authorization", headerData.toLocal8Bit() );
    QNetworkAccessManager *mgr  = new QNetworkAccessManager(this);

    // Liitetään finished signaali eventloopin quit slottiin
    connect(mgr, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));
    // Lähetetään pyyntö ja jäädään odottamaan finished signaalia
    QNetworkReply *reply = mgr->post(request, QJsonDocument(json).toJson());
    eventLoop.exec();

    if (reply->error() == QNetworkReply::NoError) {
        // Virheetön vastaus saatu: Parsitaan tulokset
        QString strReply = (QString)reply->readAll();
        json = QJsonDocument::fromJson(strReply.toUtf8()).object();
        pinOK = json["card"].toString() == "OK";
        isCredit = json["isCredit"].toString() == "Y";
    }
    else
    {
        // Virhe
        message = "Error: " + reply->errorString();
        qDebug() << "Error: " << reply->errorString();
    }

    // Siivotaan ja poistutaan
    delete reply;
    reply = nullptr;
    return pinOK;
}

// ** Talletetaan idAccount annetun kortin numeron, sekä mahdollisesti valitun credit-ominaisuuden perusteella **
// cid = Kortin numero
// useCredit = true jos credit-ominaisuutta halutaan käyttää, false jos debit-ominaisuutta
// (ref)creditLimit = Palautettava luottoraja
// Palauttaa true, jos tehtävä onnistui ja false jos virhe tapahtui
bool bank_api::saveIdAccount(QString cid, bool useCredit, double &creditLimit)
{
    //Alustukset
    bool ret = false;
    creditLimit = 0;

    // Luodaan sisäinen event loop
    QEventLoop eventLoop;

    // Luodaan JSON objekti ja lisätään data
    QJsonObject json;
    json.insert("cardId",cid);
    useCredit ? json.insert("useCredit", "Y") : json.insert("useCredit", "N");
    // Luodaan pyyntö
    QNetworkRequest request(_site_url + "getIdAccount");
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QByteArray data = _credentials.toLocal8Bit().toBase64();
    QString headerData = "Basic " + data;
    request.setRawHeader( "Authorization", headerData.toLocal8Bit() );
    QNetworkAccessManager *mgr  = new QNetworkAccessManager(this);

    // Liitetään finished signaali eventloopin quit slottiin
    connect(mgr, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));
    // Lähetetään pyyntö ja jäädään odottamaan finished signaalia
    QNetworkReply *reply = mgr->post(request, QJsonDocument(json).toJson());
    eventLoop.exec();

    if (reply->error() == QNetworkReply::NoError) {
        // Virheetön vastaus saatu: Parsitaan tulokset
        QString strReply = ((QString)reply->readAll());
        json = QJsonDocument::fromJson(strReply.toUtf8()).object();
        // Talletetaan idAccount luokan jäsenmuuttujaan
        idAccount = json["idAccount"].toInt();
        creditLimit = json["CreditLimit"].toDouble();
        ret = true;
    }
    else
    {
        // Virhe
        ret = false;
        idAccount = -1;
        qDebug() << "Error: " << reply->errorString();
    }

    // Siivotaan ja poistutaan
    delete reply;
    reply = nullptr;
    return ret;
}

// ** Yritetään nostaa määritelty summa tililtä **
// amount = Summa
// (ref)message = Viesti
// Palauttaa true, jos nosto onnistui ja false jos ei onnistunut tai virhe tapahtui
bool bank_api::withdrawMoney(int amount, QString &message)
{
    //Alustukset
    message = "";
    bool ret = false;

    // Luodaan sisäinen event loop
    QEventLoop eventLoop;

    // Luodaan JSON objekti ja lisätään data
    QJsonObject json;
    json.insert("idAccount",idAccount);
    json.insert("amount",amount);
    QNetworkRequest request(_site_url + "withdrawMoney");
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QByteArray data = _credentials.toLocal8Bit().toBase64();
    QString headerData = "Basic " + data;
    request.setRawHeader( "Authorization", headerData.toLocal8Bit() );
    QNetworkAccessManager *mgr  = new QNetworkAccessManager(this);

    // Liitetään finished signaali eventloopin quit slottiin
    connect(mgr, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));
    // Lähetetään pyyntö ja jäädään odottamaan finished signaalia
    QNetworkReply *reply = mgr->post(request, QJsonDocument(json).toJson());
    eventLoop.exec();

    if (reply->error() == QNetworkReply::NoError) {
        // Virheetön vastaus saatu: Parsitaan tulokset
        QString strReply = (QString)reply->readAll();
        json = QJsonDocument::fromJson(strReply.toUtf8()).object();
        ret = json["withdrawOK"].toString() == "Y";
        message = json["message"].toString();
    }
    else
    {
        // Virhe
        qDebug() << "Error: " << reply->errorString();
    }

    // Siivotaan ja poistutaan
    delete reply;
    reply = nullptr;
    return ret;
}

// ** Haetaan tilitapahtumat ja saldo **
// page = Sivu
// itemsPerPage = Tapahtumia per sivu
// (ptr)rows = Tapahtumarivit
// (ref)totalBalance = Saldo
// (ref)totalPages = Sivujen kokonaismäärä
// Palauttaa true, jos hakeminen onnistui ja false jos ei onnistunut tai virhe tapahtui
bool bank_api::getTransactions(int page, int itemsPerPage, QStringList &rows, QString &totalBalance, int &totalPages)
{
    //Alustukset
    rows.clear();
    totalBalance = "";
    totalPages = 0;
    bool ret = false;

    // Luodaan sisäinen event loop
    QEventLoop eventLoop;

    // Luodaan JSON objekti ja lisätään data
    QNetworkRequest request(_site_url + "getTransactions/" + QString::number(idAccount) + "&" + QString::number(page) + "&" + QString::number(itemsPerPage));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QByteArray data = _credentials.toLocal8Bit().toBase64();
    QString headerData = "Basic " + data;
    request.setRawHeader( "Authorization", headerData.toLocal8Bit() );
    QNetworkAccessManager *mgr  = new QNetworkAccessManager(this);

    // Liitetään finished signaali eventloopin quit slottiin
    connect(mgr, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));
    // Lähetetään pyyntö ja jäädään odottamaan finished signaalia
    QNetworkReply *reply = mgr->get(request);
    eventLoop.exec();

    if (reply->error() == QNetworkReply::NoError) {
        // Virheetön vastaus saatu: Parsitaan tulokset
        QString strReply = (QString)reply->readAll();
        QJsonArray jsonArray = QJsonDocument::fromJson(strReply.toUtf8()).array();
        if (jsonArray.count() > 0)
        {
            rows << "DATE\tACTION\tAMOUNT";
            foreach (const QJsonValue &value, jsonArray) {
                QJsonObject json = value.toObject();
                totalBalance = QString::number(json["TotalBalance"].toDouble(), 'f', 2);
                totalPages = json["PagesCount"].toInt();
                QDateTime dtime = QDateTime::fromString(json["DateTime"].toString(), Qt::ISODateWithMs);
                if(json["Amount"].toDouble() > 0) rows << dtime.toLocalTime().toString("dd.MM.yy hh:mm") + "\t" + json["Transaction"].toString() + "\t" + QString::number(json["Amount"].toDouble(), 'f', 2) + "€";
            }
            rows << "" << "ACCOUNT TOTAL BALANCE: " + totalBalance + "€";
        }
        ret = true;
    }
    else
    {
        // Virhe
        qDebug() << "Error: " << reply->errorString();
    }

    // Siivotaan ja poistutaan
    delete reply;
    reply = nullptr;
    return ret;
}

// ** Haetaan tilin haltijan tiedot
// (ptr)rows = Tapahtumarivit
// Palauttaa true, jos hakeminen onnistui ja false jos ei onnistunut tai virhe tapahtui
bool bank_api::getAccountHolder(QStringList &rows)
{
    //Alustukset
    bool ret = false;

    // Luodaan sisäinen event loop
    QEventLoop eventLoop;

    // Luodaan JSON objekti ja lisätään data
    QNetworkRequest request(_site_url + "getAccountHolder/" + QString::number(idAccount));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QByteArray data = _credentials.toLocal8Bit().toBase64();
    QString headerData = "Basic " + data;
    request.setRawHeader( "Authorization", headerData.toLocal8Bit() );
    QNetworkAccessManager *mgr  = new QNetworkAccessManager(this);

    // Liitetään finished signaali eventloopin quit slottiin
    connect(mgr, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));
    // Lähetetään pyyntö ja jäädään odottamaan finished signaalia
    QNetworkReply *reply = mgr->get(request);
    eventLoop.exec();

    if (reply->error() == QNetworkReply::NoError) {
        // Virheetön vastaus saatu: Parsitaan tulokset
        QString strReply = (QString)reply->readAll();
        QJsonObject json = QJsonDocument::fromJson(strReply.toUtf8()).object();
        rows << "" << "Account holder:" << "Name: " + json["name"].toString() << "Address: " + json["Address"].toString() << "Phone Number: " + json["PhoneNumber"].toString();
        ret = true;
    }
    else
    {
        // Virhe
        qDebug() << "Error: " << reply->errorString();
    }

    // Siivotaan ja poistutaan
    delete reply;
    reply = nullptr;
    return ret;
}

// ** Haetaan kortin haltijan tiedot
// cid = Kortin numero
// (ptr)rows = Tapahtumarivit
// Palauttaa true, jos hakeminen onnistui ja false jos ei onnistunut tai virhe tapahtui
bool bank_api::getCardHolder(QString cid, QStringList &rows)
{
    //Alustukset
    bool ret = false;

    // Luodaan sisäinen event loop
    QEventLoop eventLoop;

    // Luodaan JSON objekti ja lisätään data
    QNetworkRequest request(_site_url + "getCardHolder/" + cid);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QByteArray data = _credentials.toLocal8Bit().toBase64();
    QString headerData = "Basic " + data;
    request.setRawHeader( "Authorization", headerData.toLocal8Bit() );
    QNetworkAccessManager *mgr  = new QNetworkAccessManager(this);

    // Liitetään finished signaali eventloopin quit slottiin
    connect(mgr, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));
    // Lähetetään pyyntö ja jäädään odottamaan finished signaalia
    QNetworkReply *reply = mgr->get(request);
    eventLoop.exec();

    if (reply->error() == QNetworkReply::NoError) {
        // Virheetön vastaus saatu: Parsitaan tulokset
        QString strReply = (QString)reply->readAll();
        QJsonObject json = QJsonDocument::fromJson(strReply.toUtf8()).object();
        rows << "" << "Card holder:" << "Name: " + json["name"].toString() << "Address: " + json["Address"].toString() << "Phone Number: " + json["PhoneNumber"].toString();
        ret = true;
    }
    else
    {
        // Virhe
        qDebug() << "Error: " << reply->errorString();
    }

    // Siivotaan ja poistutaan
    delete reply;
    reply = nullptr;
    return ret;
}
