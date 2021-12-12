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
    bool checkPIN(QString cid, QString PIN, bool& isPIN, QString& message);
    bool saveIdAccount(QString cid, bool useCredit);
    bool withdrawMoney(int amount, QString &message);
    bool getTransactions(int page, int itemsPerPage, QStringList &rows, QString &totalBalance, int &totalPages);
private:
    const QString _credentials="newAdmin:newPass";
    const QString _site_url="http://localhost:3000/bank/";
    int idAccount = -1;
};

#endif // BANK_API_H
