var express = require('express');
var path = require('path');
var cookieParser = require('cookie-parser');
var logger = require('morgan');

var indexRouter = require('./routes/index');
var usersRouter = require('./routes/users');
var bankRouter = require('./routes/bank');
var customerRouter = require('./routes/customer');
var accountRouter = require('./routes/account');
var cardRouter = require('./routes/card');
var accountCardRouter = require('./routes/account_card');
var transactionsRouter = require('./routes/transactions');

var app = express();

app.use(logger('dev'));
app.use(express.json());
app.use(express.urlencoded({ extended: false }));
app.use(cookieParser());
app.use(express.static(path.join(__dirname, 'public')));

app.use('/', indexRouter);
app.use('/users', usersRouter);
app.use('/bank', bankRouter);
app.use('/customer', customerRouter);
app.use('/account', accountRouter);
app.use('/card', cardRouter);
app.use('/account_card', accountCardRouter);
app.use('/transactions', transactionsRouter);

module.exports = app;
