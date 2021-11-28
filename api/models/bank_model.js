const db = require('../database');
//luodaan bank-niminen objekti
//ja sen sisään tarvittavat funktiot
const bank = {
    getPinCheckCredit: function(postData, callback) {
        return db.query('call getPinCheckCredit(?)',
        [postData.cardid],callback);
    },
    getAccount: function(postData, callback) {
        return db.query('call getIdAccount(?,?)',
        [postData.cardid, postData.iscredit],callback);
    }
};
//exportilla viedään ulos bank objekti
module.exports = bank;