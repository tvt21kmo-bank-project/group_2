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
    //Timer
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::timerTick);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete api;
    delete timer;
    ui = nullptr;
    api = nullptr;
    timer = nullptr;
}

void MainWindow::timerTick()
{
    //Tick
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
            //3 = Withdraw-valikon painike: 100
            QString message = "";
            bool ret = api->withdrawMoney(100, message);
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
            QString message = "";
            bool isCredit = false;
            bool isPINvalid = false;

            isPINvalid = api->checkPIN(ui->editCard->text(), ui->editPIN->text(), isCredit, message);

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
                if (message != "") ui->ErrorMessage->setText(message);
                else {
                    ui->ErrorMessage->setText("Invalid credientials, " + QString::number(RetryCount) + " try/tries left.");
                    RetryCount--;
                }
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
            if (transPage < transTotPages) {
                transPage++;
                UpdateTransactionsList();
            }
        }
    }
}



// * Numeronäppäimistö *
void MainWindow::NumberKeyClicked(char key)
{
    switch (ui->stackedWidget->currentIndex())
    {
        case 0: {
            //0 = Kirjautumisnäyttö: Käytetään PIN kenttää
            if (ui->editCard->text().length() > 0) {
                QString pin = ui->editPIN->text();
                if (key >= '0' && key <= '9' && pin.length() < ui->editPIN->maxLength())
                    ui->editPIN->setText(pin + key);
                else if (key == 'C') ui->editPIN->clear();
                //else ui->editPIN->clear();  //hastag (not used)
            }
            break;
        }
    }
}

// Slotit
void MainWindow::on_btn1_clicked() { NumberKeyClicked('1'); }
void MainWindow::on_btn2_clicked() { NumberKeyClicked('2'); }
void MainWindow::on_bnt3_clicked() { NumberKeyClicked('3'); }
void MainWindow::on_btn4_clicked() { NumberKeyClicked('4'); }
void MainWindow::on_btn5_clicked() { NumberKeyClicked('5'); }
void MainWindow::on_btn6_clicked() { NumberKeyClicked('6'); }
void MainWindow::on_btn7_clicked() { NumberKeyClicked('7'); }
void MainWindow::on_btn8_clicked() { NumberKeyClicked('8'); }
void MainWindow::on_btn9_clicked() { NumberKeyClicked('9'); }
void MainWindow::on_btnhast_clicked() { NumberKeyClicked('#'); }
void MainWindow::on_btn0_clicked() { NumberKeyClicked('0'); }
void MainWindow::on_btnC_clicked() { NumberKeyClicked('C'); }
