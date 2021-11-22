const db = require('../database');

const transactions = {
  getById: function(id, callback) {
    return db.query('select * from transactions where idTransactions=?', [id], callback);
  },
  getAll: function(callback) {
    return db.query('select * from transactions', callback);
  },
  add: function(transactions, callback) {
    return db.query(
      'insert into transactions (Transaction,DateTime,Amount,idAccount) values(?,NOW(),?,?)',
      [transactions.transaction, transactions.amount, transactions.idAccount],
      callback
    );
  },
  delete: function(id, callback) {
    return db.query('delete from transactions where idTransaction=?', [id], callback);
  },
  update: function(id, transactions, callback) {
    return db.query(
      'update transactions set Transaction=?,Amount=?, idAccount=? where idTransaction=?',
      [transactions.transaction, transactions.amount, transactions.idAccount, id],
      callback
    );
  }
};
module.exports = transactions;