const express = require('express');
const router = express.Router();
const bcrypt = require('bcryptjs');
const bank = require('../models/bank_model');

router.post('/checkPinCredit', 
function(request, response) {
    bank.getPinCheckCredit(request.body, function(err, dbResult) {
        if (err) {
            response.json(err);
        }
        else
        {
            if(dbResult.length > 0 && dbResult[0].length > 0) {
                bcrypt.compare(request.body.pin,dbResult[0][0].Pin, function(err,compareResult) {
                    if(compareResult) {
                        console.log("PIN OK");
                        response.json({card: 'OK', isCredit: dbResult[0][0].isCredit});
                    }
                    else {
                        console.log("WRONG PIN!");
                        response.json({card: 'NOK', isCredit: 'NA'});
                    }	                    
                    }
                );
            }
            else {
                console.log("Card does not exists");
                response.json({card: 'NA', isCredit: 'NA'});
            }
        }
    });
});

router.post('/getIdAccount',
function(request, response) {
    bank.getAccount(request.body, function(err, dbResult) {
        if (err) {
            response.json(err);
        }
        else
        {
            if(dbResult.length > 0 && dbResult[0].length > 0) {
                console.log("Account linked to the card found");
                response.json(dbResult[0][0]);
            }
            else
            {
                console.log("Account linked to the card did not found");
                response.json({idAccount: -1});
            }
        }
    });
});

router.post('/withdrawMoney',
function(request, response) {
    bank.withdrawMoney(request.body, function(err, dbResult) {
        if (err) {
            response.json(err);
        }
        else
        {
            if(dbResult.length > 0 && dbResult[0].length > 0) {
                console.log("Account linked to the card found. Result: " + dbResult[0][0]);
                response.json(dbResult[0][0]);
            }
            else
            {
                console.log("Account did not found");
                response.json({withdrawOK: 'N', message: 'Account did not found!'});
            } 
        }
    })
});

router.get('/getTransactions/:idAccount&:page&:actionsPerPage',
function(request, response) {
    bank.getTransactions(request.params.idAccount, request.params.page, request.params.actionsPerPage, function(err, dbResult) {
        if (err) {
            response.json(err);
        }
        else
        {
            if(dbResult.length > 0 && dbResult[0].length > 0) {
                console.log("Transactions found. Result: " + dbResult[0][0]);
                response.json(dbResult[0]);
            }
            else
            {
                console.log("Transactions did not found");
                response.json({message: 'Transactions did not found!'});
            } 
        }
    })
})

module.exports = router;