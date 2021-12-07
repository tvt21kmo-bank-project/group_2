#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    api = new bank_api();
    ui->editCard->setFocus();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_funbtn8_clicked()
{
    switch (ui->stackedWidget->currentIndex())
    {
        case 0:
            bool isCredit = false;
            bool isPINvalid = api->checkPIN(ui->editCard->text(), ui->editPIN->text(), isCredit);

            if (isPINvalid)
            {
               if (isCredit)
                  ui->stackedWidget->setCurrentIndex(1);
               else
                  ui->stackedWidget->setCurrentIndex(2);
            }
            break;
    }
}
