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
    void NumberKeyClicked(char key);

private slots:
    void on_funbtn8_clicked();

    void on_funbtn1_clicked();

    void on_funbtn5_clicked();

    void on_funbtn2_clicked();

    void timerTick();

    void on_btn1_clicked();

    void on_btn2_clicked();

    void on_bnt3_clicked();

    void on_btn4_clicked();

    void on_btn5_clicked();

    void on_btn6_clicked();

    void on_btn7_clicked();

    void on_btn8_clicked();

    void on_btn9_clicked();

    void on_btnhast_clicked();

    void on_btn0_clicked();

    void on_btnC_clicked();

private:
    Ui::MainWindow *ui;
    bank_api *api;
    int transTotPages = 0;
    int transPage = 1;
    int RetryCount = 2;
    QTimer *timer;
};

#endif // MAINWINDOW_H
