#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "bank_api.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

//private slots:
  //  void on_funbtn4_clicked();

private slots:
    void on_funbtn8_clicked();

private:
    Ui::MainWindow *ui;
    bank_api *api;
};

#endif // MAINWINDOW_H
