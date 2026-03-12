/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QComboBox *type;
    QLabel *label;
    QComboBox *USER_ID;
    QLabel *label_2;
    QLineEdit *Demand;
    QLabel *label_3;
    QTextEdit *ConverTextBox;
    QPushButton *pushButton;
    QLabel *label_4;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(896, 739);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        type = new QComboBox(centralwidget);
        type->setObjectName(QString::fromUtf8("type"));
        type->setGeometry(QRect(150, 40, 121, 41));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(28, 40, 131, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        font.setPointSize(16);
        label->setFont(font);
        USER_ID = new QComboBox(centralwidget);
        USER_ID->setObjectName(QString::fromUtf8("USER_ID"));
        USER_ID->setGeometry(QRect(740, 40, 121, 41));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(640, 40, 91, 41));
        label_2->setFont(font);
        Demand = new QLineEdit(centralwidget);
        Demand->setObjectName(QString::fromUtf8("Demand"));
        Demand->setGeometry(QRect(100, 120, 681, 51));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Arial"));
        font1.setPointSize(12);
        Demand->setFont(font1);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 120, 81, 51));
        label_3->setFont(font);
        ConverTextBox = new QTextEdit(centralwidget);
        ConverTextBox->setObjectName(QString::fromUtf8("ConverTextBox"));
        ConverTextBox->setGeometry(QRect(100, 190, 761, 511));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Arial"));
        font2.setPointSize(14);
        ConverTextBox->setFont(font2);
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(790, 120, 71, 51));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Arial"));
        font3.setPointSize(20);
        pushButton->setFont(font3);
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 400, 91, 41));
        label_4->setFont(font1);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 896, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QApplication::translate("MainWindow", "\346\234\215\345\212\241\347\261\273\345\236\213\357\274\232", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "\347\231\273\345\275\225ID\357\274\232", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "  \351\234\200\346\261\202\357\274\232", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "\342\206\265", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "\350\276\223\345\207\272\346\226\207\346\234\254\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
