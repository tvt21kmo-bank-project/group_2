const db = require('../database');

const customer = {
  getById: function(id, callback) {
    return db.query('select * from customer where idCustomer=?', [id], callback);
  },
  getAll: function(callback) {
    return db.query('select * from customer', callback);
  },
  add: function(customer, callback) {
    return db.query(
      'insert into customer (Name,Address,PhoneNumber) values(?,?,?)',
      [customer.name, customer.address, customer.phonenumber],
      callback
    );
  },
  delete: function(id, callback) {
    return db.query('delete from customer where idCustomer=?', [id], callback);
  },
  update: function(id, customer, callback) {
    return db.query(
      'update customer set Name=?,Address=?, PhoneNumber=? where idCustomer=?',
      [customer.name, customer.address, customer.phonenumber, id],
      callback
    );
  }
};
module.exports = customer;