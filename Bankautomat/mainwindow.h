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
    void UpdateTransactionsList();

private slots:
    void on_funbtn8_clicked();

    void on_funbtn1_clicked();

    void on_funbtn5_clicked();

    void on_funbtn2_clicked();

private:
    Ui::MainWindow *ui;
    bank_api *api;
    int transTotPages = 0;
    int transPage = 1;
    int RetryCount = 2;
};

#endif // MAINWINDOW_H
