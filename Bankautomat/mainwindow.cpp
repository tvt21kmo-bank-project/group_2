#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_19_clicked()
{
    //frame1, tarkista, onko id ja pin oikein, jos on -> siirry frame2
}

void MainWindow::on_pushButton_15_clicked()
{
    //frame2, cancel painike: tyhjentää teksti kentät
}
