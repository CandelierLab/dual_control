/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QPushButton *CheckSerial;
    QPushButton *Dual_1;
    QTextBrowser *Output;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(139, 480);
        MainWindow->setMaximumSize(QSize(139, 480));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        CheckSerial = new QPushButton(centralWidget);
        CheckSerial->setObjectName(QString::fromUtf8("CheckSerial"));

        gridLayout->addWidget(CheckSerial, 0, 0, 1, 1);

        Dual_1 = new QPushButton(centralWidget);
        Dual_1->setObjectName(QString::fromUtf8("Dual_1"));
        Dual_1->setEnabled(false);
        Dual_1->setCheckable(true);

        gridLayout->addWidget(Dual_1, 1, 0, 1, 1);

        Output = new QTextBrowser(centralWidget);
        Output->setObjectName(QString::fromUtf8("Output"));
        QFont font;
        font.setPointSize(4);
        Output->setFont(font);
        Output->setFrameShape(QFrame::NoFrame);
        Output->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

        gridLayout->addWidget(Output, 2, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        CheckSerial->setText(QCoreApplication::translate("MainWindow", "Check connections", nullptr));
        Dual_1->setText(QCoreApplication::translate("MainWindow", "Dual 1", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
