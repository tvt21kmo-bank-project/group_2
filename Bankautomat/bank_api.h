#ifndef BANK_API_H
#define BANK_API_H

#include <QObject>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>

class bank_api : public QObject
{
    Q_OBJECT
public:
    explicit bank_api(QObject *parent = nullptr);
    bool checkPIN(QString cid, QString PIN, bool& isPIN);
private:
    int idAccount = 0;
};

#endif // BANK_API_H
