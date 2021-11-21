const db = require('../database');
const bcrypt = require('bcryptjs');
const saltRounds = 10;

const card = {
  getById: function(id, callback) {
    return db.query('select * from card where idCard=?', [id], callback);
  },
  getAll: function(callback) {
    return db.query('select * from card', callback);
  },
  add: function(card, callback) {
    bcrypt.hash(card.pin, saltRounds, function(err, hash) {
    return db.query(
      'insert into card (CardId,Pin,idCustomer) values(?,?,?)', 
      [card.cardid, hash, card.idcustomer],
      callback
    )});
  },
  delete: function(id, callback) {
    return db.query('delete from card where idCard=?', [id], callback);
  },
  update: function(id, card, callback) {
    bcrypt.hash(card.pin, saltRounds, function(err, hash) {
    return db.query(
      'update card set CardId=?, Pin=?, idCustomer=? where idCard=?',
      [card.cardid, hash, card.idcustomer, id], 
      callback
    )});
  },
  checkpin: function(id, callback) {
    return db.query('select Pin from card where idCard=?', [id], callback);
  }
};
module.exports = card;