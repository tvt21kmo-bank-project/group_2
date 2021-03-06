const mysql = require('mysql');
const dotenv = require('dotenv');

dotenv.config();

const connection = mysql.createPool(process.env.MYSQL);

module.exports = connection;