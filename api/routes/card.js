const express = require('express');
const router = express.Router();
const bcrypt = require('bcryptjs');
const card = require('../models/card_model');

router.get('/:id?',
 function(request, response) {
  if (request.params.id) {
    card.getById(request.params.id, function(err, dbResult) {
      if (err) {
        response.json(err);
      } else {
        response.json(dbResult[0]);
      }
    });
  } else {
    card.getAll(function(err, dbResult) {
      if (err) {
        response.json(err);
      } else {
        response.json(dbResult);
      }
    });
  }
});


router.post('/', 
function(request, response) {
    card.add(request.body, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(request.body);
    }
  });
});

router.post('/checkpin/:id?', 
function(request, response) {
    card.checkpin(request.params.id, function(err, dbResult) {
    if (err) {
        response.json(err);
    }
    else
    {
        if(dbResult.length > 0) {
            bcrypt.compare(request.body.pin,dbResult[0].Pin, function(err,compareResult) {
                if(compareResult) {
                    console.log("PIN OK");
                    response.send(true);
                  }
                  else {
                      console.log("WRONG PIN!");
                      response.send(false);
                  }	                    
                }
            );
        }
        else {
            console.log("Card does not exists");
            response.send(false);
        }
    }
  });
})

router.delete('/:id', 
function(request, response) {
    card.delete(request.params.id, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(dbResult);
    }
  });
});


router.put('/:id', 
function(request, response) {
    card.update(request.params.id, request.body, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(dbResult);
    }
  });
});

module.exports = router;