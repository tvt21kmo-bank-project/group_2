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
                console.log("Account linked to the card found: " + dbResult[0][0].idAccount);
                response.json(dbResult[0][0]);
            }
            else
            {
                console.log("Account linked to the card did not found");
                response.json({idAccount: -1, CreditLimit: "NA"});
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
                console.log("Account: " + request.body.idAccount + ", withdrawOK: " + dbResult[0][0].withdrawOK + ", message: " + dbResult[0][0].message);
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
            if(dbResult.length > 0) {
                if (dbResult[0].length > 0) {
                    console.log("Transactions found from idAccount " + request.params.idAccount);
                    response.json(dbResult[0]);
                }
                else if (dbResult[1].length > 0)
                {
                    console.log("Transactions did not found from idAccount " + request.params.idAccount);
                    response.json(dbResult[1]);
                }
            }
            else
            {
                console.log("Account did not found");
                response.json({message: 'Account did not found!'});
            } 
        }
    })
});

router.get('/getAccountHolder/:idAccount',
function(request, response) {
    bank.getAccountHolder(request.params.idAccount, function(err, dbResult) {
        if (err) {
            response.json(err);
        }
        else
        {
            if(dbResult.length > 0) {
                console.log("Account" + request.params.idAccount + ", Name: " + dbResult[0].name + ", Address: " + dbResult[0].Address + ", Phone: " + dbResult[0].PhoneNumber);
                response.json(dbResult[0]);
            }
            else
            {
                console.log("Account did not found");
                response.json({name: '', Address: '', PhoneNuber: ''});
            }
        }
    })
});

router.get('/getCardHolder/:CardId',
function(request, response) {
    bank.getCardHolder(request.params.CardId, function(err, dbResult) {
        if (err) {
            response.json(err);
        }
        else
        {
            if(dbResult.length > 0) {
                console.log("Card: " + request.params.CardId + ", Name: " + dbResult[0].name + ", Address: " + dbResult[0].Address + ", Phone: " + dbResult[0].PhoneNumber);
                response.json(dbResult[0]);
            }
            else
            {
                console.log("Card did not found");
                response.json({name: '', Address: '', PhoneNuber: ''});
            }
        }
    })
})

module.exports = router;