#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    api = new bank_api();
    ui->stackedWidget->setCurrentIndex(0);
    ui->editCard->setFocus();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete api;
    ui = nullptr;
    api = nullptr;
}

// Päivittää tilitapahtuma-listan
void MainWindow::UpdateTransactionsList()
{
    ui->listTransactions->clear();
    QStringList rows;
    QString totalBalance = "0.00";      //Ei toistaiseksi käytössä
    //Päivitetään listan
    api->getTransactions(transPage, 10, rows, totalBalance, transTotPages);
    ui->listTransactions->addItems(rows);
}

// Funktiopainiketta 1 on painettu
void MainWindow::on_funbtn1_clicked()
{
    switch (ui->stackedWidget->currentIndex())
    {
        case 1: {
            //1 = Credit/debit-näytön painike: Credit
            api->saveIdAccount(ui->editCard->text(), true);
            ui->stackedWidget->setCurrentIndex(2);
            break;
        }
        case 2: {
            //2 = Päävalikon painike: Withdraw
            ui->stackedWidget->setCurrentIndex(3);
            break;
        }
        case 3: {
            //3 = Withdraw-valikon painike: 20
            QString message = "";
            bool ret = api->withdrawMoney(20, message);
            ui->wmessage->setText(message);
            ret ? ui->wmessage->setStyleSheet("QLabel { color:black; }") : ui->wmessage->setStyleSheet("QLabel { color:red; }");
        }
    }
}

//Funktiopainiketta 2 on painettu
void MainWindow::on_funbtn2_clicked()
{
    switch (ui->stackedWidget->currentIndex())
    {
        case 2: {
            //2 = Päävalikon painike: Transactions
            ui->stackedWidget->setCurrentIndex(5);
            UpdateTransactionsList();
            break;
        }
        case 3: {
             //3 = Withdraw-valikon painike: 40
             QString message = "";
             bool ret = api->withdrawMoney(40, message);
              ui->wmessage->setText(message);
              ret ? ui->wmessage->setStyleSheet("QLabel { color:black; }") : ui->wmessage->setStyleSheet("QLabel { color:red; }");
        }
    }
}

//Funktiopainiketta 3 on painettu
void MainWindow::on_funbtn3_clicked()
{
    switch (ui->stackedWidget->currentIndex())
    {
        case 3: {
             //3 = Withdraw-valikon painike: 60
             QString message = "";
             bool ret = api->withdrawMoney(60, message);
              ui->wmessage->setText(message);
              ret ? ui->wmessage->setStyleSheet("QLabel { color:black; }") : ui->wmessage->setStyleSheet("QLabel { color:red; }");
        }
    }
}

//Funktiopainiketta 4 on painettu
void MainWindow::on_funbtn4_clicked()
{
    switch (ui->stackedWidget->currentIndex())
    {
        case 3: {
             //3 = Withdraw-valikon painike: BACK
        ui->stackedWidget->setCurrentIndex(2);
        break;
        }
        case 5: {
            //5 = Transaction-valikon painike: BACK
        ui->stackedWidget->setCurrentIndex(2);
         break;
         }
         case 4: {
            //4 = Balance-valikon painike: BACK
         ui->stackedWidget->setCurrentIndex(2);
        break;
        }
         case 6: {
             //6 = Other Amount-valikon painike: BACK
         ui->stackedWidget->setCurrentIndex(3);
         break;
        }
        case 2: {
            //2 = MainPage -valikon painike: INFO
        ui->stackedWidget->setCurrentIndex(7);
        break;
        }
        case 7: {
            //6 = Other Amount-valikon painike: BACK
        ui->stackedWidget->setCurrentIndex(2);
        break;
        }
    }
}

//Funktiopainiketta 5 on painettu
void MainWindow::on_funbtn5_clicked()
{
    switch (ui->stackedWidget->currentIndex())
    {
        case 1: {
            //1 = Credit/debit-näytön painike: Debit
            api->saveIdAccount(ui->editCard->text(), false);
            ui->stackedWidget->setCurrentIndex(2);
            break;
        }
        case 5: {
            //5 = Tilitapahtuma-näytön painike: UP
            if (transPage > 1) {
                transPage--;
                UpdateTransactionsList();
            }
        }
        case 3: {
            //3 = Withdraw-valikon painike: 100
         QString message = "";
         bool ret = api->withdrawMoney(100, message);
          ui->wmessage->setText(message);
          ret ? ui->wmessage->setStyleSheet("QLabel { color:black; }") : ui->wmessage->setStyleSheet("QLabel { color:red; }");
        }
         case 2: {
             // = MainPage-valikon painike: Balance
          ui->stackedWidget->setCurrentIndex(4);
         break;
        }
    }
}

//Funktiopainiketta 6 on painettu
void MainWindow::on_funbtn6_clicked()
{
    switch (ui->stackedWidget->currentIndex())
    {
        case 3: {
             //3 = Withdraw-valikon painike: 200
             QString message = "";
             bool ret = api->withdrawMoney(200, message);
              ui->wmessage->setText(message);
              ret ? ui->wmessage->setStyleSheet("QLabel { color:black; }") : ui->wmessage->setStyleSheet("QLabel { color:red; }");
        }
    }
}

//Funktiopainiketta 7 on painettu
void MainWindow::on_funbtn7_clicked()
{
    switch (ui->stackedWidget->currentIndex())
    {
        case 3: {
             //3 = Withdraw-valikon painike: 500
             QString message = "";
             bool ret = api->withdrawMoney(500, message);
              ui->wmessage->setText(message);
              ret ? ui->wmessage->setStyleSheet("QLabel { color:black; }") : ui->wmessage->setStyleSheet("QLabel { color:red; }");
        }
    }
}

//Funktiopainiketta 8 on painettu
void MainWindow::on_funbtn8_clicked()
{
    switch (ui->stackedWidget->currentIndex())
    {
        case 0: {
            //0 = Kirjautumisnäytön painike: OK
            //Tarkistetaan PIN
            if (ui->editCard->text().length() < 8 || ui->editPIN->text().length() < 4) break;
            bool isCredit = false;
            bool isPINvalid = false;

            isPINvalid = api->checkPIN(ui->editCard->text(), ui->editPIN->text(), isCredit);

            if (isPINvalid)
            {
               if (isCredit)
                  ui->stackedWidget->setCurrentIndex(1);
               else
               {
                  api->saveIdAccount(ui->editCard->text(), false);
                  ui->stackedWidget->setCurrentIndex(2);
               }
            }
            else if (RetryCount > 0) {              
                ui->ErrorMessage->setText("Invalid credientials, " + QString::number(RetryCount) + " try/tries left.");
                RetryCount--;
                ui->editPIN->clear();
                ui->editPIN->setFocus();
            }
            else
            {
               ui->ErrorMessage->setText("Your Account is Locked, please contact your bank for further details.");
            }
            break;
        }
        case 2: {
            //2 = Päävalikon painike: LOGOUT
            ui->editCard->clear();
            ui->editPIN->clear();
            ui->stackedWidget->setCurrentIndex(0);
            ui->editCard->setFocus();
            break;
        }
        case 5: {
            //5 = Tilitapahtuma-näytön painike: DOWN
            if (transPage < transTotPages){
                transPage++;
                UpdateTransactionsList();
                break;
            }
        }
        case 3: {
            //3 = Withdrawal-valikon painike: Other Amount
        ui->stackedWidget->setCurrentIndex(6);
        break;
   }
}
