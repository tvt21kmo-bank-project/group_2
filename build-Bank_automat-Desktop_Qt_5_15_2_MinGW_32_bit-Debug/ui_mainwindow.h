/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *bnt3;
    QPushButton *btn2;
    QPushButton *btn1;
    QPushButton *btn4;
    QPushButton *btn5;
    QPushButton *btn6;
    QPushButton *btn7;
    QPushButton *btn8;
    QPushButton *btn9;
    QPushButton *btnhast;
    QPushButton *btn0;
    QPushButton *btnC;
    QPushButton *funbtn1;
    QPushButton *funbtn2;
    QPushButton *funbtn3;
    QPushButton *funbtn4;
    QPushButton *funbtn5;
    QPushButton *funbtn6;
    QPushButton *funbtn7;
    QPushButton *funbtn8;
    QStackedWidget *stackedWidget;
    QWidget *LogIn;
    QLineEdit *editCard;
    QLineEdit *editPIN;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_2;
    QLabel *label_6;
    QLabel *ErrorMessage;
    QWidget *CreditorDebit;
    QLabel *label_23;
    QLabel *label_24;
    QLabel *label_25;
    QWidget *MainPage;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QWidget *Withdrawal;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_19;
    QLabel *label_21;
    QLabel *label_22;
    QLabel *label_17;
    QLabel *label_18;
    QLabel *label_13;
    QLabel *wmessage;
    QLabel *label_20;
    QWidget *Balance;
    QLabel *label_27;
    QLabel *label_28;
    QListWidget *listWidget;
    QWidget *Transactions;
    QListWidget *listTransactions;
    QLabel *label_30;
    QLabel *label_31;
    QLabel *label_32;
    QLabel *label_33;
    QWidget *OtherAmount;
    QLabel *label_34;
    QLineEdit *Amount;
    QLabel *label_29;
    QLabel *label_35;
    QLabel *label_36;
    QLabel *wmessage2;
    QWidget *ClientInfo;
    QLabel *label_5;
    QTextBrowser *textBrowser;
    QLabel *label_37;
    QLabel *label_321;
    QLabel *label_331;
    QLabel *label;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(425, 560);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(65, 65, 65);"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        bnt3 = new QPushButton(centralWidget);
        bnt3->setObjectName(QString::fromUtf8("bnt3"));
        bnt3->setGeometry(QRect(250, 310, 41, 41));
        bnt3->setStyleSheet(QString::fromUtf8("\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgb(99, 99, 99);"));
        btn2 = new QPushButton(centralWidget);
        btn2->setObjectName(QString::fromUtf8("btn2"));
        btn2->setGeometry(QRect(190, 310, 41, 41));
        btn2->setStyleSheet(QString::fromUtf8("\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgb(99, 99, 99);"));
        btn1 = new QPushButton(centralWidget);
        btn1->setObjectName(QString::fromUtf8("btn1"));
        btn1->setGeometry(QRect(130, 310, 41, 41));
        QFont font;
        font.setBold(false);
        font.setWeight(50);
        btn1->setFont(font);
        btn1->setStyleSheet(QString::fromUtf8("\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgb(99, 99, 99);"));
        btn4 = new QPushButton(centralWidget);
        btn4->setObjectName(QString::fromUtf8("btn4"));
        btn4->setGeometry(QRect(130, 360, 41, 41));
        btn4->setStyleSheet(QString::fromUtf8("\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgb(99, 99, 99);"));
        btn5 = new QPushButton(centralWidget);
        btn5->setObjectName(QString::fromUtf8("btn5"));
        btn5->setGeometry(QRect(190, 360, 41, 41));
        btn5->setStyleSheet(QString::fromUtf8("\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgb(99, 99, 99);"));
        btn6 = new QPushButton(centralWidget);
        btn6->setObjectName(QString::fromUtf8("btn6"));
        btn6->setGeometry(QRect(250, 360, 41, 41));
        btn6->setStyleSheet(QString::fromUtf8("\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgb(99, 99, 99);"));
        btn7 = new QPushButton(centralWidget);
        btn7->setObjectName(QString::fromUtf8("btn7"));
        btn7->setGeometry(QRect(130, 410, 41, 41));
        btn7->setStyleSheet(QString::fromUtf8("\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgb(99, 99, 99);"));
        btn8 = new QPushButton(centralWidget);
        btn8->setObjectName(QString::fromUtf8("btn8"));
        btn8->setGeometry(QRect(190, 410, 41, 41));
        btn8->setStyleSheet(QString::fromUtf8("\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgb(99, 99, 99);"));
        btn9 = new QPushButton(centralWidget);
        btn9->setObjectName(QString::fromUtf8("btn9"));
        btn9->setGeometry(QRect(250, 410, 41, 41));
        btn9->setStyleSheet(QString::fromUtf8("\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgb(99, 99, 99);"));
        btnhast = new QPushButton(centralWidget);
        btnhast->setObjectName(QString::fromUtf8("btnhast"));
        btnhast->setGeometry(QRect(130, 460, 41, 41));
        btnhast->setStyleSheet(QString::fromUtf8("\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgb(99, 99, 99);"));
        btn0 = new QPushButton(centralWidget);
        btn0->setObjectName(QString::fromUtf8("btn0"));
        btn0->setGeometry(QRect(190, 460, 41, 41));
        btn0->setStyleSheet(QString::fromUtf8("\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgb(99, 99, 99);"));
        btnC = new QPushButton(centralWidget);
        btnC->setObjectName(QString::fromUtf8("btnC"));
        btnC->setGeometry(QRect(250, 460, 41, 41));
        btnC->setStyleSheet(QString::fromUtf8("\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgb(99, 99, 99);"));
        funbtn1 = new QPushButton(centralWidget);
        funbtn1->setObjectName(QString::fromUtf8("funbtn1"));
        funbtn1->setGeometry(QRect(20, 140, 31, 31));
        funbtn1->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(99, 99, 99);"));
        funbtn2 = new QPushButton(centralWidget);
        funbtn2->setObjectName(QString::fromUtf8("funbtn2"));
        funbtn2->setGeometry(QRect(20, 180, 31, 31));
        funbtn2->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(99, 99, 99);"));
        funbtn3 = new QPushButton(centralWidget);
        funbtn3->setObjectName(QString::fromUtf8("funbtn3"));
        funbtn3->setGeometry(QRect(20, 220, 31, 31));
        funbtn3->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(99, 99, 99);"));
        funbtn4 = new QPushButton(centralWidget);
        funbtn4->setObjectName(QString::fromUtf8("funbtn4"));
        funbtn4->setGeometry(QRect(20, 260, 31, 31));
        funbtn4->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(99, 99, 99);"));
        funbtn5 = new QPushButton(centralWidget);
        funbtn5->setObjectName(QString::fromUtf8("funbtn5"));
        funbtn5->setGeometry(QRect(370, 140, 31, 31));
        funbtn5->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(99, 99, 99);"));
        funbtn6 = new QPushButton(centralWidget);
        funbtn6->setObjectName(QString::fromUtf8("funbtn6"));
        funbtn6->setGeometry(QRect(370, 180, 31, 31));
        funbtn6->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(99, 99, 99);"));
        funbtn7 = new QPushButton(centralWidget);
        funbtn7->setObjectName(QString::fromUtf8("funbtn7"));
        funbtn7->setGeometry(QRect(370, 220, 31, 31));
        funbtn7->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(99, 99, 99);"));
        funbtn8 = new QPushButton(centralWidget);
        funbtn8->setObjectName(QString::fromUtf8("funbtn8"));
        funbtn8->setGeometry(QRect(370, 260, 31, 31));
        funbtn8->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(99, 99, 99);"));
        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(70, 20, 276, 281));
        stackedWidget->setCursor(QCursor(Qt::ArrowCursor));
        stackedWidget->setStyleSheet(QString::fromUtf8("\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgb(99, 99, 99);"));
        stackedWidget->setFrameShape(QFrame::StyledPanel);
        stackedWidget->setFrameShadow(QFrame::Plain);
        LogIn = new QWidget();
        LogIn->setObjectName(QString::fromUtf8("LogIn"));
        editCard = new QLineEdit(LogIn);
        editCard->setObjectName(QString::fromUtf8("editCard"));
        editCard->setGeometry(QRect(120, 110, 113, 21));
        editCard->setMaxLength(15);
        editPIN = new QLineEdit(LogIn);
        editPIN->setObjectName(QString::fromUtf8("editPIN"));
        editPIN->setEnabled(true);
        editPIN->setGeometry(QRect(120, 150, 113, 21));
        editPIN->setMaxLength(15);
        editPIN->setEchoMode(QLineEdit::Password);
        editPIN->setReadOnly(true);
        label_3 = new QLabel(LogIn);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(50, 110, 51, 16));
        label_4 = new QLabel(LogIn);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(80, 40, 121, 21));
        label_2 = new QLabel(LogIn);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(50, 150, 61, 16));
        label_6 = new QLabel(LogIn);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(250, 250, 21, 16));
        ErrorMessage = new QLabel(LogIn);
        ErrorMessage->setObjectName(QString::fromUtf8("ErrorMessage"));
        ErrorMessage->setGeometry(QRect(50, 200, 181, 31));
        ErrorMessage->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        ErrorMessage->setWordWrap(true);
        stackedWidget->addWidget(LogIn);
        CreditorDebit = new QWidget();
        CreditorDebit->setObjectName(QString::fromUtf8("CreditorDebit"));
        label_23 = new QLabel(CreditorDebit);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setGeometry(QRect(10, 125, 31, 21));
        label_24 = new QLabel(CreditorDebit);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setGeometry(QRect(240, 125, 31, 21));
        label_25 = new QLabel(CreditorDebit);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setGeometry(QRect(100, 70, 81, 20));
        stackedWidget->addWidget(CreditorDebit);
        MainPage = new QWidget();
        MainPage->setObjectName(QString::fromUtf8("MainPage"));
        label_7 = new QLabel(MainPage);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(10, 120, 61, 31));
        label_8 = new QLabel(MainPage);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(220, 120, 47, 31));
        label_9 = new QLabel(MainPage);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(220, 240, 47, 31));
        label_10 = new QLabel(MainPage);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(10, 160, 81, 31));
        label_11 = new QLabel(MainPage);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(10, 240, 47, 31));
        stackedWidget->addWidget(MainPage);
        Withdrawal = new QWidget();
        Withdrawal->setObjectName(QString::fromUtf8("Withdrawal"));
        label_15 = new QLabel(Withdrawal);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(10, 200, 31, 31));
        label_16 = new QLabel(Withdrawal);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(10, 240, 31, 31));
        label_19 = new QLabel(Withdrawal);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(180, 240, 81, 31));
        label_21 = new QLabel(Withdrawal);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setGeometry(QRect(10, 160, 31, 31));
        label_22 = new QLabel(Withdrawal);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setGeometry(QRect(10, 120, 31, 31));
        label_17 = new QLabel(Withdrawal);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(250, 120, 31, 31));
        label_18 = new QLabel(Withdrawal);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(250, 160, 21, 31));
        label_13 = new QLabel(Withdrawal);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(100, 80, 71, 21));
        wmessage = new QLabel(Withdrawal);
        wmessage->setObjectName(QString::fromUtf8("wmessage"));
        wmessage->setGeometry(QRect(50, 200, 181, 31));
        wmessage->setAlignment(Qt::AlignCenter);
        wmessage->setWordWrap(true);
        label_20 = new QLabel(Withdrawal);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setGeometry(QRect(250, 200, 21, 31));
        stackedWidget->addWidget(Withdrawal);
        Balance = new QWidget();
        Balance->setObjectName(QString::fromUtf8("Balance"));
        label_27 = new QLabel(Balance);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        label_27->setGeometry(QRect(120, 60, 41, 20));
        label_28 = new QLabel(Balance);
        label_28->setObjectName(QString::fromUtf8("label_28"));
        label_28->setGeometry(QRect(10, 245, 31, 21));
        listWidget = new QListWidget(Balance);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(10, 80, 261, 161));
        stackedWidget->addWidget(Balance);
        Transactions = new QWidget();
        Transactions->setObjectName(QString::fromUtf8("Transactions"));
        listTransactions = new QListWidget(Transactions);
        listTransactions->setObjectName(QString::fromUtf8("listTransactions"));
        listTransactions->setGeometry(QRect(20, 20, 235, 231));
        label_30 = new QLabel(Transactions);
        label_30->setObjectName(QString::fromUtf8("label_30"));
        label_30->setGeometry(QRect(10, 240, 31, 31));
        label_31 = new QLabel(Transactions);
        label_31->setObjectName(QString::fromUtf8("label_31"));
        label_31->setGeometry(QRect(110, 0, 61, 20));
        label_32 = new QLabel(Transactions);
        label_32->setObjectName(QString::fromUtf8("label_32"));
        label_32->setGeometry(QRect(260, 120, 16, 31));
        label_33 = new QLabel(Transactions);
        label_33->setObjectName(QString::fromUtf8("label_33"));
        label_33->setGeometry(QRect(235, 240, 31, 31));
        stackedWidget->addWidget(Transactions);
        OtherAmount = new QWidget();
        OtherAmount->setObjectName(QString::fromUtf8("OtherAmount"));
        label_34 = new QLabel(OtherAmount);
        label_34->setObjectName(QString::fromUtf8("label_34"));
        label_34->setGeometry(QRect(100, 10, 81, 20));
        Amount = new QLineEdit(OtherAmount);
        Amount->setObjectName(QString::fromUtf8("Amount"));
        Amount->setEnabled(true);
        Amount->setGeometry(QRect(80, 110, 113, 21));
        Amount->setMaxLength(5);
        Amount->setReadOnly(true);
        label_29 = new QLabel(OtherAmount);
        label_29->setObjectName(QString::fromUtf8("label_29"));
        label_29->setGeometry(QRect(100, 80, 71, 20));
        label_35 = new QLabel(OtherAmount);
        label_35->setObjectName(QString::fromUtf8("label_35"));
        label_35->setGeometry(QRect(10, 240, 31, 31));
        label_36 = new QLabel(OtherAmount);
        label_36->setObjectName(QString::fromUtf8("label_36"));
        label_36->setGeometry(QRect(250, 240, 21, 31));
        wmessage2 = new QLabel(OtherAmount);
        wmessage2->setObjectName(QString::fromUtf8("wmessage2"));
        wmessage2->setGeometry(QRect(40, 190, 191, 31));
        wmessage2->setWordWrap(true);
        stackedWidget->addWidget(OtherAmount);
        ClientInfo = new QWidget();
        ClientInfo->setObjectName(QString::fromUtf8("ClientInfo"));
        label_5 = new QLabel(ClientInfo);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(100, 30, 71, 16));
        textBrowser = new QTextBrowser(ClientInfo);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(10, 60, 256, 171));
        label_37 = new QLabel(ClientInfo);
        label_37->setObjectName(QString::fromUtf8("label_37"));
        label_37->setGeometry(QRect(10, 240, 31, 31));
        label_321 = new QLabel(ClientInfo);
        label_321->setObjectName(QString::fromUtf8("label_321"));
        label_321->setGeometry(QRect(260, 120, 16, 31));
        label_331 = new QLabel(ClientInfo);
        label_331->setObjectName(QString::fromUtf8("label_331"));
        label_331->setGeometry(QRect(235, 240, 31, 31));
        stackedWidget->addWidget(ClientInfo);
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(170, 0, 81, 21));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 425, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        bnt3->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        btn2->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        btn1->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        btn4->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        btn5->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        btn6->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        btn7->setText(QCoreApplication::translate("MainWindow", "7", nullptr));
        btn8->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
        btn9->setText(QCoreApplication::translate("MainWindow", "9", nullptr));
        btnhast->setText(QCoreApplication::translate("MainWindow", "#", nullptr));
        btn0->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        btnC->setText(QCoreApplication::translate("MainWindow", "C", nullptr));
        funbtn1->setText(QString());
        funbtn2->setText(QString());
        funbtn3->setText(QString());
        funbtn4->setText(QString());
        funbtn5->setText(QString());
        funbtn6->setText(QString());
        funbtn7->setText(QString());
        funbtn8->setText(QString());
        editCard->setText(QString());
        label_3->setText(QCoreApplication::translate("MainWindow", "CARD ID:", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "INSERT CREDIENTIALS", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "PIN:", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "OK", nullptr));
        ErrorMessage->setText(QString());
        label_23->setText(QCoreApplication::translate("MainWindow", "Credit", nullptr));
        label_24->setText(QCoreApplication::translate("MainWindow", "Debit", nullptr));
        label_25->setText(QCoreApplication::translate("MainWindow", "Credit or Debit?", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "WITDRAWAL", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "BALANCE", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "LOG OUT", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "TRANSACTIONS", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "INFO", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "60", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "BACK", nullptr));
        label_19->setText(QCoreApplication::translate("MainWindow", "OTHER AMOUNT", nullptr));
        label_21->setText(QCoreApplication::translate("MainWindow", "40", nullptr));
        label_22->setText(QCoreApplication::translate("MainWindow", "20", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "100", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "200", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "WITHDRAWAL", nullptr));
        wmessage->setText(QString());
        label_20->setText(QCoreApplication::translate("MainWindow", "500", nullptr));
        label_27->setText(QCoreApplication::translate("MainWindow", "Balance", nullptr));
        label_28->setText(QCoreApplication::translate("MainWindow", "BACK", nullptr));
        label_30->setText(QCoreApplication::translate("MainWindow", "BACK", nullptr));
        label_31->setText(QCoreApplication::translate("MainWindow", "Transactions", nullptr));
        label_32->setText(QCoreApplication::translate("MainWindow", "UP", nullptr));
        label_33->setText(QCoreApplication::translate("MainWindow", "DOWN", nullptr));
        label_29->setText(QCoreApplication::translate("MainWindow", "Insert amount", nullptr));
        label_35->setText(QCoreApplication::translate("MainWindow", "BACK", nullptr));
        label_36->setText(QCoreApplication::translate("MainWindow", "OK", nullptr));
        wmessage2->setText(QString());
        label_5->setText(QCoreApplication::translate("MainWindow", "CLIENT INFO", nullptr));
        label_37->setText(QCoreApplication::translate("MainWindow", "BACK", nullptr));
        label_321->setText(QCoreApplication::translate("MainWindow", "UP", nullptr));
        label_331->setText(QCoreApplication::translate("MainWindow", "DOWN", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "BANK MIGUELO", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
