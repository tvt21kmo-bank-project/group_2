const db = require('../database');
//luodaan bank-niminen objekti
//ja sen sisään tarvittavat funktiot
const bank = {
    getPinCheckCredit: function(postData, callback) {
        return db.query('call getPinCheckCredit(?)',
        [postData.cardId],callback);
    },
    getAccount: function(postData, callback) {
        return db.query('call getIdAccount(?,?)',
        [postData.cardId, postData.useCredit],callback);
    },
    withdrawMoney: function(postData, callback) {
        return db.query('call withdrawMoney(?,?)',
        [postData.idAccount, postData.amount], callback);
    },
    getTransactions: function(id, page, actionsPerPage, callback) {
        return db.query('call getTransactions(?,?,?)',
        [id, page, actionsPerPage], callback);
    },
    getAccountHolder: function(id, callback) {
        return db.query('SELECT name, Address, PhoneNumber FROM customer c INNER JOIN account a on c.idCustomer=a.idCustomer WHERE idAccount=?', id,callback);
    },
    getCardHolder: function(CardId, callback) {
        return db.query('SELECT name, Address, PhoneNumber FROM customer c INNER JOIN card d on c.idCustomer=d.idCustomer WHERE cardId=?', CardId, callback);
    }
};
//exportilla viedään ulos bank objekti
module.exports = bank;