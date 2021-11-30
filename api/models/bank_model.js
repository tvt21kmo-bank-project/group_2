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
    }
};
//exportilla viedään ulos bank objekti
module.exports = bank;