/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTextBrowser *Output;
    QPushButton *CheckSerial;
    QPushButton *Dual_1;
    QPushButton *Dual_2;
    QPushButton *Dual_3;
    QPushButton *Dual_4;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(250, 1053);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        Output = new QTextBrowser(centralWidget);
        Output->setObjectName(QStringLiteral("Output"));
        Output->setGeometry(QRect(10, 131, 231, 911));
        QFont font;
        font.setPointSize(4);
        Output->setFont(font);
        Output->setFrameShape(QFrame::NoFrame);
        Output->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        CheckSerial = new QPushButton(centralWidget);
        CheckSerial->setObjectName(QStringLiteral("CheckSerial"));
        CheckSerial->setGeometry(QRect(10, 10, 231, 27));
        Dual_1 = new QPushButton(centralWidget);
        Dual_1->setObjectName(QStringLiteral("Dual_1"));
        Dual_1->setEnabled(false);
        Dual_1->setGeometry(QRect(10, 50, 111, 27));
        Dual_1->setCheckable(true);
        Dual_2 = new QPushButton(centralWidget);
        Dual_2->setObjectName(QStringLiteral("Dual_2"));
        Dual_2->setEnabled(false);
        Dual_2->setGeometry(QRect(130, 50, 111, 27));
        Dual_2->setCheckable(true);
        Dual_3 = new QPushButton(centralWidget);
        Dual_3->setObjectName(QStringLiteral("Dual_3"));
        Dual_3->setEnabled(false);
        Dual_3->setGeometry(QRect(10, 90, 111, 27));
        Dual_3->setCheckable(true);
        Dual_4 = new QPushButton(centralWidget);
        Dual_4->setObjectName(QStringLiteral("Dual_4"));
        Dual_4->setEnabled(false);
        Dual_4->setGeometry(QRect(130, 90, 111, 27));
        Dual_4->setCheckable(true);
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        CheckSerial->setText(QApplication::translate("MainWindow", "Check serial connections", 0));
        Dual_1->setText(QApplication::translate("MainWindow", "Dual 1", 0));
        Dual_2->setText(QApplication::translate("MainWindow", "Dual 2", 0));
        Dual_3->setText(QApplication::translate("MainWindow", "Dual 3", 0));
        Dual_4->setText(QApplication::translate("MainWindow", "Dual 4", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
