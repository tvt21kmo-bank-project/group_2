#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    api = new bank_api();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_funbtn8_clicked()
{
    bool isCredit = false;
    bool test = api->checkPIN(ui->editCard->text(), ui->editPIN->text(), isCredit);
}
