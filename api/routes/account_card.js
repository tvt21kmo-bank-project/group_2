const express = require('express');
const router = express.Router();
const accountcard = require('../models/account_card_model');

router.get('/',
function(request, response) {
    accountcard.getAll(function(err, dbResult) {
      if (err) {
        response.json(err);
      } else {
        response.json(dbResult);
      }
    });
});


router.post('/', 
function(request, response) {
    accountcard.add(request.body, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(request.body);
    }
  });
});


router.delete('/:idAccount&:idCard', 
function(request, response) {
    accountcard.delete(request.params.idAccount, request.params.idCard, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(dbResult);
    }
  });
});

module.exports = router;