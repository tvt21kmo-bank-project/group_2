const db = require('../database');

const accountcard = {
  getAll: function(callback) {
    return db.query('select * from accountcard', callback);
  },
  add: function(accountcard, callback) {
    return db.query(
      'insert into accountcard (idAccount,idCard) values(?,?)',
      [accountcard.idaccount, accountcard.idcard],
      callback
    );
  },
  delete: function(id1, id2, callback) {
    return db.query(
    'delete from accountcard where idAccount=? and idCard=?', 
    [id1,id2], 
    callback);
  },
};
module.exports = accountcard;