#include "bank_api.h"

bank_api::bank_api(QObject *parent) : QObject(parent)
{

}

bool bank_api::checkPIN(QString cid, QString PIN, bool& isCredit)
{
    //Alustukset
    isCredit = false;
    bool pinOK = false;

    // Luodaan sisäinen event loop
    QEventLoop eventLoop;

    // Luodaan JSON objekti ja lisätään data
    QJsonObject json;
    json.insert("cardId",cid);
    json.insert("pin",PIN);
    // Url ja autentikointi
    QString site_url="http://localhost:3000/bank/checkPinCredit";
    QString credentials="newAdmin:newPass";
    // Luodaan pyyntö
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QByteArray data = credentials.toLocal8Bit().toBase64();
    QString headerData = "Basic " + data;
    request.setRawHeader( "Authorization", headerData.toLocal8Bit() );
    QNetworkAccessManager *mgr  = new QNetworkAccessManager(this);

    // Liitetään finished signaali eventloopin quit slottiin
    connect(mgr, SIGNAL(finished (QNetworkReply*)), &eventLoop, SLOT(quit()));
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
        qDebug() << "Error: " << reply->errorString();
    }

    // Siivotaan ja poistutaan
    delete reply;
    reply = nullptr;
    return pinOK;
}
