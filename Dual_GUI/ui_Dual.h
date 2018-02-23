/********************************************************************************
** Form generated from reading UI file 'Dual.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DUAL_H
#define UI_DUAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dual
{
public:
    QWidget *centralWidget;
    QTabWidget *Tabs;
    QWidget *Core;
    QLabel *label;
    QWidget *gridLayoutWidget;
    QGridLayout *ValveLayout;
    QLabel *labelValve2;
    QLabel *labelValve4;
    QSpinBox *pinValve3;
    QSpinBox *pinValve1;
    QPushButton *switchValve4;
    QSpinBox *pinValve2;
    QLabel *labelValve5;
    QPushButton *switchValve6;
    QSpinBox *pinValve6;
    QPushButton *switchValve3;
    QSpinBox *pinValve4;
    QLabel *labelValve6;
    QLabel *labelValve3;
    QPushButton *switchValve1;
    QPushButton *switchValve5;
    QSpinBox *pinValve5;
    QPushButton *switchValve2;
    QLabel *labelValve1;
    QLabel *labelValvePin;
    QLabel *labelValveStatus;
    QLabel *labelEmpty1;
    QPushButton *MotorEnable;
    QPushButton *MotorRun;
    QLabel *label_2;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout;
    QPushButton *ProjectPathButton;
    QLineEdit *ProjectPath;
    QLabel *label_3;
    QLineEdit *DataPath;
    QLabel *label_4;
    QPushButton *Autoset;
    QLabel *label_5;
    QWidget *formLayoutWidget_2;
    QFormLayout *formLayout_2;
    QCheckBox *MotorDir;
    QLabel *labelDirection;
    QLabel *labelPeriod;
    QLineEdit *MotorPeriod;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QWidget *gridLayoutWidget_4;
    QGridLayout *gridLayout_3;
    QLabel *labelDirectionPin;
    QLabel *labelStepPin;
    QSpinBox *pinStep;
    QSpinBox *pinDir;
    QSpinBox *pBottomSwitch;
    QLabel *labelLeftSwitchPin;
    QSpinBox *pTopSwitch;
    QLabel *labelRightSwitchPin;
    QLabel *pinM3Label;
    QSpinBox *pinMS3;
    QLabel *labelPinEnable;
    QSpinBox *pinEnable;
    QLabel *pinM2Label;
    QSpinBox *pinMS2;
    QLabel *pinM1Label;
    QSpinBox *pinMS1;
    QLabel *label_12;
    QWidget *gridLayoutWidget_6;
    QGridLayout *gridLayout_5;
    QSpinBox *pinVisLED;
    QLabel *label_14;
    QPushButton *VisLED;
    QLabel *label_15;
    QSpinBox *pinIRLED;
    QPushButton *IRLED;
    QLabel *label_13;
    QLabel *label_16;
    QLabel *label_17;
    QWidget *formLayoutWidget_3;
    QFormLayout *formLayout_3;
    QLabel *labelLeft;
    QComboBox *CircuitLeft;
    QLabel *labelRight;
    QComboBox *CircuitRight;
    QWidget *Camera;
    QLabel *Image;
    QWidget *Protocols;
    QWidget *gridLayoutWidget_3;
    QGridLayout *gridLayout_2;
    QPushButton *ProtocolPathButton;
    QLabel *label_9;
    QLineEdit *ProtocolPath;
    QPushButton *ProtocolRun;
    QLabel *ProtocolTime;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *spawningDateLabel;
    QDateEdit *spawningDate;
    QLabel *ageLabel;
    QLineEdit *Age;
    QLabel *stimulusLabel;
    QLineEdit *Stimulus;
    QLabel *concentrationLabel;
    QLineEdit *Concentration;
    QLabel *label_10;
    QLabel *label_11;
    QPushButton *Snapshot;
    QMenuBar *menuBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Dual)
    {
        if (Dual->objectName().isEmpty())
            Dual->setObjectName(QStringLiteral("Dual"));
        Dual->resize(800, 515);
        centralWidget = new QWidget(Dual);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        Tabs = new QTabWidget(centralWidget);
        Tabs->setObjectName(QStringLiteral("Tabs"));
        Tabs->setGeometry(QRect(10, 10, 782, 441));
        Core = new QWidget();
        Core->setObjectName(QStringLiteral("Core"));
        label = new QLabel(Core);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 241, 31));
        label->setTextFormat(Qt::RichText);
        label->setAlignment(Qt::AlignCenter);
        gridLayoutWidget = new QWidget(Core);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(20, 40, 221, 232));
        ValveLayout = new QGridLayout(gridLayoutWidget);
        ValveLayout->setSpacing(6);
        ValveLayout->setContentsMargins(11, 11, 11, 11);
        ValveLayout->setObjectName(QStringLiteral("ValveLayout"));
        ValveLayout->setContentsMargins(0, 0, 0, 0);
        labelValve2 = new QLabel(gridLayoutWidget);
        labelValve2->setObjectName(QStringLiteral("labelValve2"));

        ValveLayout->addWidget(labelValve2, 2, 0, 1, 1);

        labelValve4 = new QLabel(gridLayoutWidget);
        labelValve4->setObjectName(QStringLiteral("labelValve4"));

        ValveLayout->addWidget(labelValve4, 4, 0, 1, 1);

        pinValve3 = new QSpinBox(gridLayoutWidget);
        pinValve3->setObjectName(QStringLiteral("pinValve3"));
        pinValve3->setMaximumSize(QSize(50, 16777215));
        pinValve3->setValue(5);

        ValveLayout->addWidget(pinValve3, 3, 1, 1, 1);

        pinValve1 = new QSpinBox(gridLayoutWidget);
        pinValve1->setObjectName(QStringLiteral("pinValve1"));
        pinValve1->setMaximumSize(QSize(50, 16777215));
        pinValve1->setValue(7);

        ValveLayout->addWidget(pinValve1, 1, 1, 1, 1);

        switchValve4 = new QPushButton(gridLayoutWidget);
        switchValve4->setObjectName(QStringLiteral("switchValve4"));
        switchValve4->setMaximumSize(QSize(80, 16777215));
        switchValve4->setCheckable(true);
        switchValve4->setChecked(false);

        ValveLayout->addWidget(switchValve4, 4, 2, 1, 1);

        pinValve2 = new QSpinBox(gridLayoutWidget);
        pinValve2->setObjectName(QStringLiteral("pinValve2"));
        pinValve2->setMaximumSize(QSize(50, 16777215));
        pinValve2->setValue(6);

        ValveLayout->addWidget(pinValve2, 2, 1, 1, 1);

        labelValve5 = new QLabel(gridLayoutWidget);
        labelValve5->setObjectName(QStringLiteral("labelValve5"));

        ValveLayout->addWidget(labelValve5, 5, 0, 1, 1);

        switchValve6 = new QPushButton(gridLayoutWidget);
        switchValve6->setObjectName(QStringLiteral("switchValve6"));
        switchValve6->setMaximumSize(QSize(80, 16777215));
        switchValve6->setCheckable(true);
        switchValve6->setChecked(false);

        ValveLayout->addWidget(switchValve6, 6, 2, 1, 1);

        pinValve6 = new QSpinBox(gridLayoutWidget);
        pinValve6->setObjectName(QStringLiteral("pinValve6"));
        pinValve6->setMaximumSize(QSize(50, 16777215));
        pinValve6->setValue(2);

        ValveLayout->addWidget(pinValve6, 6, 1, 1, 1);

        switchValve3 = new QPushButton(gridLayoutWidget);
        switchValve3->setObjectName(QStringLiteral("switchValve3"));
        switchValve3->setMaximumSize(QSize(80, 16777215));
        switchValve3->setCheckable(true);
        switchValve3->setChecked(false);

        ValveLayout->addWidget(switchValve3, 3, 2, 1, 1);

        pinValve4 = new QSpinBox(gridLayoutWidget);
        pinValve4->setObjectName(QStringLiteral("pinValve4"));
        pinValve4->setMaximumSize(QSize(50, 16777215));
        pinValve4->setValue(4);

        ValveLayout->addWidget(pinValve4, 4, 1, 1, 1);

        labelValve6 = new QLabel(gridLayoutWidget);
        labelValve6->setObjectName(QStringLiteral("labelValve6"));

        ValveLayout->addWidget(labelValve6, 6, 0, 1, 1);

        labelValve3 = new QLabel(gridLayoutWidget);
        labelValve3->setObjectName(QStringLiteral("labelValve3"));

        ValveLayout->addWidget(labelValve3, 3, 0, 1, 1);

        switchValve1 = new QPushButton(gridLayoutWidget);
        switchValve1->setObjectName(QStringLiteral("switchValve1"));
        switchValve1->setMaximumSize(QSize(80, 16777215));
        switchValve1->setCheckable(true);
        switchValve1->setChecked(false);

        ValveLayout->addWidget(switchValve1, 1, 2, 1, 1);

        switchValve5 = new QPushButton(gridLayoutWidget);
        switchValve5->setObjectName(QStringLiteral("switchValve5"));
        switchValve5->setMaximumSize(QSize(80, 16777215));
        switchValve5->setCheckable(true);
        switchValve5->setChecked(false);

        ValveLayout->addWidget(switchValve5, 5, 2, 1, 1);

        pinValve5 = new QSpinBox(gridLayoutWidget);
        pinValve5->setObjectName(QStringLiteral("pinValve5"));
        pinValve5->setMaximumSize(QSize(50, 16777215));
        pinValve5->setValue(3);

        ValveLayout->addWidget(pinValve5, 5, 1, 1, 1);

        switchValve2 = new QPushButton(gridLayoutWidget);
        switchValve2->setObjectName(QStringLiteral("switchValve2"));
        switchValve2->setMaximumSize(QSize(80, 16777215));
        switchValve2->setCheckable(true);
        switchValve2->setChecked(false);

        ValveLayout->addWidget(switchValve2, 2, 2, 1, 1);

        labelValve1 = new QLabel(gridLayoutWidget);
        labelValve1->setObjectName(QStringLiteral("labelValve1"));

        ValveLayout->addWidget(labelValve1, 1, 0, 1, 1);

        labelValvePin = new QLabel(gridLayoutWidget);
        labelValvePin->setObjectName(QStringLiteral("labelValvePin"));
        labelValvePin->setAlignment(Qt::AlignCenter);

        ValveLayout->addWidget(labelValvePin, 0, 1, 1, 1);

        labelValveStatus = new QLabel(gridLayoutWidget);
        labelValveStatus->setObjectName(QStringLiteral("labelValveStatus"));
        labelValveStatus->setAlignment(Qt::AlignCenter);

        ValveLayout->addWidget(labelValveStatus, 0, 2, 1, 1);

        labelEmpty1 = new QLabel(gridLayoutWidget);
        labelEmpty1->setObjectName(QStringLiteral("labelEmpty1"));

        ValveLayout->addWidget(labelEmpty1, 0, 0, 1, 1);

        MotorEnable = new QPushButton(Core);
        MotorEnable->setObjectName(QStringLiteral("MotorEnable"));
        MotorEnable->setGeometry(QRect(470, 200, 71, 30));
        MotorEnable->setCheckable(true);
        MotorEnable->setChecked(true);
        MotorRun = new QPushButton(Core);
        MotorRun->setObjectName(QStringLiteral("MotorRun"));
        MotorRun->setGeometry(QRect(470, 240, 71, 31));
        MotorRun->setCheckable(true);
        label_2 = new QLabel(Core);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(470, 10, 291, 31));
        label_2->setTextFormat(Qt::RichText);
        label_2->setAlignment(Qt::AlignCenter);
        gridLayoutWidget_2 = new QWidget(Core);
        gridLayoutWidget_2->setObjectName(QStringLiteral("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(20, 319, 741, 71));
        gridLayout = new QGridLayout(gridLayoutWidget_2);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        ProjectPathButton = new QPushButton(gridLayoutWidget_2);
        ProjectPathButton->setObjectName(QStringLiteral("ProjectPathButton"));

        gridLayout->addWidget(ProjectPathButton, 0, 2, 1, 1);

        ProjectPath = new QLineEdit(gridLayoutWidget_2);
        ProjectPath->setObjectName(QStringLiteral("ProjectPath"));

        gridLayout->addWidget(ProjectPath, 0, 1, 1, 1);

        label_3 = new QLabel(gridLayoutWidget_2);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 0, 0, 1, 1);

        DataPath = new QLineEdit(gridLayoutWidget_2);
        DataPath->setObjectName(QStringLiteral("DataPath"));
        DataPath->setEnabled(false);

        gridLayout->addWidget(DataPath, 1, 1, 1, 1);

        label_4 = new QLabel(gridLayoutWidget_2);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 1, 0, 1, 1);

        Autoset = new QPushButton(gridLayoutWidget_2);
        Autoset->setObjectName(QStringLiteral("Autoset"));

        gridLayout->addWidget(Autoset, 1, 2, 1, 1);

        label_5 = new QLabel(Core);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 290, 101, 20));
        label_5->setTextFormat(Qt::RichText);
        label_5->setAlignment(Qt::AlignCenter);
        formLayoutWidget_2 = new QWidget(Core);
        formLayoutWidget_2->setObjectName(QStringLiteral("formLayoutWidget_2"));
        formLayoutWidget_2->setGeometry(QRect(550, 200, 211, 71));
        formLayout_2 = new QFormLayout(formLayoutWidget_2);
        formLayout_2->setSpacing(6);
        formLayout_2->setContentsMargins(11, 11, 11, 11);
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        formLayout_2->setContentsMargins(0, 0, 0, 0);
        MotorDir = new QCheckBox(formLayoutWidget_2);
        MotorDir->setObjectName(QStringLiteral("MotorDir"));
        MotorDir->setChecked(true);

        formLayout_2->setWidget(1, QFormLayout::FieldRole, MotorDir);

        labelDirection = new QLabel(formLayoutWidget_2);
        labelDirection->setObjectName(QStringLiteral("labelDirection"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, labelDirection);

        labelPeriod = new QLabel(formLayoutWidget_2);
        labelPeriod->setObjectName(QStringLiteral("labelPeriod"));

        formLayout_2->setWidget(2, QFormLayout::LabelRole, labelPeriod);

        MotorPeriod = new QLineEdit(formLayoutWidget_2);
        MotorPeriod->setObjectName(QStringLiteral("MotorPeriod"));
        MotorPeriod->setMaximumSize(QSize(66, 16777215));

        formLayout_2->setWidget(2, QFormLayout::FieldRole, MotorPeriod);

        label_6 = new QLabel(Core);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(460, 10, 311, 271));
        label_6->setFrameShape(QFrame::Box);
        label_6->setFrameShadow(QFrame::Raised);
        label_7 = new QLabel(Core);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(10, 10, 241, 271));
        label_7->setFrameShape(QFrame::Box);
        label_7->setFrameShadow(QFrame::Raised);
        label_8 = new QLabel(Core);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(10, 290, 761, 111));
        label_8->setFrameShape(QFrame::Box);
        label_8->setFrameShadow(QFrame::Raised);
        gridLayoutWidget_4 = new QWidget(Core);
        gridLayoutWidget_4->setObjectName(QStringLiteral("gridLayoutWidget_4"));
        gridLayoutWidget_4->setGeometry(QRect(470, 40, 291, 155));
        gridLayout_3 = new QGridLayout(gridLayoutWidget_4);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        labelDirectionPin = new QLabel(gridLayoutWidget_4);
        labelDirectionPin->setObjectName(QStringLiteral("labelDirectionPin"));
        QFont font;
        font.setPointSize(10);
        labelDirectionPin->setFont(font);

        gridLayout_3->addWidget(labelDirectionPin, 0, 0, 1, 1);

        labelStepPin = new QLabel(gridLayoutWidget_4);
        labelStepPin->setObjectName(QStringLiteral("labelStepPin"));
        labelStepPin->setFont(font);

        gridLayout_3->addWidget(labelStepPin, 0, 2, 1, 1);

        pinStep = new QSpinBox(gridLayoutWidget_4);
        pinStep->setObjectName(QStringLiteral("pinStep"));
        pinStep->setMaximumSize(QSize(50, 16777215));
        pinStep->setValue(9);

        gridLayout_3->addWidget(pinStep, 0, 3, 1, 1);

        pinDir = new QSpinBox(gridLayoutWidget_4);
        pinDir->setObjectName(QStringLiteral("pinDir"));
        pinDir->setMaximumSize(QSize(50, 16777215));
        pinDir->setValue(8);

        gridLayout_3->addWidget(pinDir, 0, 1, 1, 1);

        pBottomSwitch = new QSpinBox(gridLayoutWidget_4);
        pBottomSwitch->setObjectName(QStringLiteral("pBottomSwitch"));
        pBottomSwitch->setMaximumSize(QSize(50, 50));
        pBottomSwitch->setValue(19);

        gridLayout_3->addWidget(pBottomSwitch, 3, 1, 1, 1);

        labelLeftSwitchPin = new QLabel(gridLayoutWidget_4);
        labelLeftSwitchPin->setObjectName(QStringLiteral("labelLeftSwitchPin"));
        QFont font1;
        font1.setPointSize(9);
        labelLeftSwitchPin->setFont(font1);

        gridLayout_3->addWidget(labelLeftSwitchPin, 3, 2, 1, 1);

        pTopSwitch = new QSpinBox(gridLayoutWidget_4);
        pTopSwitch->setObjectName(QStringLiteral("pTopSwitch"));
        pTopSwitch->setMaximumSize(QSize(50, 16777215));
        pTopSwitch->setValue(20);

        gridLayout_3->addWidget(pTopSwitch, 3, 3, 1, 1);

        labelRightSwitchPin = new QLabel(gridLayoutWidget_4);
        labelRightSwitchPin->setObjectName(QStringLiteral("labelRightSwitchPin"));
        labelRightSwitchPin->setFont(font1);

        gridLayout_3->addWidget(labelRightSwitchPin, 3, 0, 1, 1);

        pinM3Label = new QLabel(gridLayoutWidget_4);
        pinM3Label->setObjectName(QStringLiteral("pinM3Label"));
        pinM3Label->setFont(font);

        gridLayout_3->addWidget(pinM3Label, 1, 0, 1, 1);

        pinMS3 = new QSpinBox(gridLayoutWidget_4);
        pinMS3->setObjectName(QStringLiteral("pinMS3"));
        pinMS3->setValue(10);

        gridLayout_3->addWidget(pinMS3, 1, 1, 1, 1);

        labelPinEnable = new QLabel(gridLayoutWidget_4);
        labelPinEnable->setObjectName(QStringLiteral("labelPinEnable"));
        labelPinEnable->setFont(font);

        gridLayout_3->addWidget(labelPinEnable, 2, 2, 1, 1);

        pinEnable = new QSpinBox(gridLayoutWidget_4);
        pinEnable->setObjectName(QStringLiteral("pinEnable"));
        pinEnable->setMaximumSize(QSize(50, 16777215));
        pinEnable->setValue(13);

        gridLayout_3->addWidget(pinEnable, 2, 3, 1, 1);

        pinM2Label = new QLabel(gridLayoutWidget_4);
        pinM2Label->setObjectName(QStringLiteral("pinM2Label"));
        pinM2Label->setFont(font);

        gridLayout_3->addWidget(pinM2Label, 1, 2, 1, 1);

        pinMS2 = new QSpinBox(gridLayoutWidget_4);
        pinMS2->setObjectName(QStringLiteral("pinMS2"));
        pinMS2->setMaximumSize(QSize(50, 16777215));
        pinMS2->setValue(11);

        gridLayout_3->addWidget(pinMS2, 1, 3, 1, 1);

        pinM1Label = new QLabel(gridLayoutWidget_4);
        pinM1Label->setObjectName(QStringLiteral("pinM1Label"));
        pinM1Label->setFont(font);

        gridLayout_3->addWidget(pinM1Label, 2, 0, 1, 1);

        pinMS1 = new QSpinBox(gridLayoutWidget_4);
        pinMS1->setObjectName(QStringLiteral("pinMS1"));
        pinMS1->setMaximumSize(QSize(50, 16777215));
        pinMS1->setValue(12);

        gridLayout_3->addWidget(pinMS1, 2, 1, 1, 1);

        label_12 = new QLabel(Core);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(260, 150, 191, 131));
        label_12->setFrameShape(QFrame::Box);
        label_12->setFrameShadow(QFrame::Raised);
        gridLayoutWidget_6 = new QWidget(Core);
        gridLayoutWidget_6->setObjectName(QStringLiteral("gridLayoutWidget_6"));
        gridLayoutWidget_6->setGeometry(QRect(270, 180, 171, 92));
        gridLayout_5 = new QGridLayout(gridLayoutWidget_6);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        gridLayout_5->setContentsMargins(0, 0, 0, 0);
        pinVisLED = new QSpinBox(gridLayoutWidget_6);
        pinVisLED->setObjectName(QStringLiteral("pinVisLED"));
        pinVisLED->setMaximumSize(QSize(50, 16777215));
        pinVisLED->setValue(18);

        gridLayout_5->addWidget(pinVisLED, 0, 1, 1, 1);

        label_14 = new QLabel(gridLayoutWidget_6);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setMaximumSize(QSize(60, 16777215));

        gridLayout_5->addWidget(label_14, 0, 0, 1, 1);

        VisLED = new QPushButton(gridLayoutWidget_6);
        VisLED->setObjectName(QStringLiteral("VisLED"));
        VisLED->setMaximumSize(QSize(50, 16777215));
        VisLED->setCheckable(true);

        gridLayout_5->addWidget(VisLED, 0, 2, 1, 1);

        label_15 = new QLabel(gridLayoutWidget_6);
        label_15->setObjectName(QStringLiteral("label_15"));

        gridLayout_5->addWidget(label_15, 1, 0, 1, 1);

        pinIRLED = new QSpinBox(gridLayoutWidget_6);
        pinIRLED->setObjectName(QStringLiteral("pinIRLED"));
        pinIRLED->setValue(21);

        gridLayout_5->addWidget(pinIRLED, 1, 1, 1, 1);

        IRLED = new QPushButton(gridLayoutWidget_6);
        IRLED->setObjectName(QStringLiteral("IRLED"));
        IRLED->setMaximumSize(QSize(50, 16777215));
        IRLED->setCheckable(true);

        gridLayout_5->addWidget(IRLED, 1, 2, 1, 1);

        label_13 = new QLabel(Core);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(270, 155, 171, 20));
        label_13->setTextFormat(Qt::RichText);
        label_13->setAlignment(Qt::AlignCenter);
        label_16 = new QLabel(Core);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(270, 10, 171, 31));
        label_16->setTextFormat(Qt::RichText);
        label_16->setAlignment(Qt::AlignCenter);
        label_17 = new QLabel(Core);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(260, 10, 191, 121));
        label_17->setFrameShape(QFrame::Box);
        label_17->setFrameShadow(QFrame::Raised);
        formLayoutWidget_3 = new QWidget(Core);
        formLayoutWidget_3->setObjectName(QStringLiteral("formLayoutWidget_3"));
        formLayoutWidget_3->setGeometry(QRect(280, 49, 160, 71));
        formLayout_3 = new QFormLayout(formLayoutWidget_3);
        formLayout_3->setSpacing(6);
        formLayout_3->setContentsMargins(11, 11, 11, 11);
        formLayout_3->setObjectName(QStringLiteral("formLayout_3"));
        formLayout_3->setContentsMargins(0, 0, 0, 0);
        labelLeft = new QLabel(formLayoutWidget_3);
        labelLeft->setObjectName(QStringLiteral("labelLeft"));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, labelLeft);

        CircuitLeft = new QComboBox(formLayoutWidget_3);
        CircuitLeft->setObjectName(QStringLiteral("CircuitLeft"));

        formLayout_3->setWidget(0, QFormLayout::FieldRole, CircuitLeft);

        labelRight = new QLabel(formLayoutWidget_3);
        labelRight->setObjectName(QStringLiteral("labelRight"));

        formLayout_3->setWidget(1, QFormLayout::LabelRole, labelRight);

        CircuitRight = new QComboBox(formLayoutWidget_3);
        CircuitRight->setObjectName(QStringLiteral("CircuitRight"));

        formLayout_3->setWidget(1, QFormLayout::FieldRole, CircuitRight);

        Tabs->addTab(Core, QString());
        label_17->raise();
        label_8->raise();
        label_7->raise();
        label_6->raise();
        label->raise();
        gridLayoutWidget->raise();
        MotorEnable->raise();
        MotorRun->raise();
        label_2->raise();
        gridLayoutWidget_2->raise();
        label_5->raise();
        formLayoutWidget_2->raise();
        gridLayoutWidget_4->raise();
        label_12->raise();
        gridLayoutWidget_6->raise();
        label_13->raise();
        label_16->raise();
        formLayoutWidget_3->raise();
        Camera = new QWidget();
        Camera->setObjectName(QStringLiteral("Camera"));
        Image = new QLabel(Camera);
        Image->setObjectName(QStringLiteral("Image"));
        Image->setGeometry(QRect(0, 7, 780, 390));
        Image->setFrameShape(QFrame::NoFrame);
        Image->setFrameShadow(QFrame::Raised);
        Image->setMidLineWidth(0);
        Image->setAlignment(Qt::AlignCenter);
        Tabs->addTab(Camera, QString());
        Protocols = new QWidget();
        Protocols->setObjectName(QStringLiteral("Protocols"));
        gridLayoutWidget_3 = new QWidget(Protocols);
        gridLayoutWidget_3->setObjectName(QStringLiteral("gridLayoutWidget_3"));
        gridLayoutWidget_3->setGeometry(QRect(10, 300, 761, 41));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_3);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        ProtocolPathButton = new QPushButton(gridLayoutWidget_3);
        ProtocolPathButton->setObjectName(QStringLiteral("ProtocolPathButton"));
        ProtocolPathButton->setFont(font);

        gridLayout_2->addWidget(ProtocolPathButton, 0, 2, 1, 1);

        label_9 = new QLabel(gridLayoutWidget_3);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout_2->addWidget(label_9, 0, 0, 1, 1);

        ProtocolPath = new QLineEdit(gridLayoutWidget_3);
        ProtocolPath->setObjectName(QStringLiteral("ProtocolPath"));
        ProtocolPath->setFont(font);

        gridLayout_2->addWidget(ProtocolPath, 0, 1, 1, 1);

        ProtocolRun = new QPushButton(Protocols);
        ProtocolRun->setObjectName(QStringLiteral("ProtocolRun"));
        ProtocolRun->setGeometry(QRect(100, 350, 321, 51));
        ProtocolRun->setCheckable(true);
        ProtocolTime = new QLabel(Protocols);
        ProtocolTime->setObjectName(QStringLiteral("ProtocolTime"));
        ProtocolTime->setGeometry(QRect(420, 350, 211, 51));
        QFont font2;
        font2.setFamily(QStringLiteral("DejaVu Sans"));
        font2.setPointSize(20);
        ProtocolTime->setFont(font2);
        ProtocolTime->setStyleSheet(QStringLiteral("color:black;"));
        ProtocolTime->setAlignment(Qt::AlignCenter);
        formLayoutWidget = new QWidget(Protocols);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(20, 50, 244, 136));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        spawningDateLabel = new QLabel(formLayoutWidget);
        spawningDateLabel->setObjectName(QStringLiteral("spawningDateLabel"));

        formLayout->setWidget(0, QFormLayout::LabelRole, spawningDateLabel);

        spawningDate = new QDateEdit(formLayoutWidget);
        spawningDate->setObjectName(QStringLiteral("spawningDate"));

        formLayout->setWidget(0, QFormLayout::FieldRole, spawningDate);

        ageLabel = new QLabel(formLayoutWidget);
        ageLabel->setObjectName(QStringLiteral("ageLabel"));

        formLayout->setWidget(1, QFormLayout::LabelRole, ageLabel);

        Age = new QLineEdit(formLayoutWidget);
        Age->setObjectName(QStringLiteral("Age"));
        Age->setEnabled(false);

        formLayout->setWidget(1, QFormLayout::FieldRole, Age);

        stimulusLabel = new QLabel(formLayoutWidget);
        stimulusLabel->setObjectName(QStringLiteral("stimulusLabel"));

        formLayout->setWidget(2, QFormLayout::LabelRole, stimulusLabel);

        Stimulus = new QLineEdit(formLayoutWidget);
        Stimulus->setObjectName(QStringLiteral("Stimulus"));

        formLayout->setWidget(2, QFormLayout::FieldRole, Stimulus);

        concentrationLabel = new QLabel(formLayoutWidget);
        concentrationLabel->setObjectName(QStringLiteral("concentrationLabel"));

        formLayout->setWidget(3, QFormLayout::LabelRole, concentrationLabel);

        Concentration = new QLineEdit(formLayoutWidget);
        Concentration->setObjectName(QStringLiteral("Concentration"));

        formLayout->setWidget(3, QFormLayout::FieldRole, Concentration);

        label_10 = new QLabel(Protocols);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(10, 10, 261, 191));
        label_10->setFrameShape(QFrame::Box);
        label_10->setFrameShadow(QFrame::Raised);
        label_11 = new QLabel(Protocols);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(20, 20, 141, 20));
        label_11->setTextFormat(Qt::RichText);
        label_11->setAlignment(Qt::AlignCenter);
        Tabs->addTab(Protocols, QString());
        label_10->raise();
        gridLayoutWidget_3->raise();
        ProtocolRun->raise();
        ProtocolTime->raise();
        formLayoutWidget->raise();
        label_11->raise();
        Snapshot = new QPushButton(centralWidget);
        Snapshot->setObjectName(QStringLiteral("Snapshot"));
        Snapshot->setGeometry(QRect(680, 6, 110, 29));
        Dual->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Dual);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 800, 27));
        Dual->setMenuBar(menuBar);
        statusBar = new QStatusBar(Dual);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Dual->setStatusBar(statusBar);

        retranslateUi(Dual);

        Tabs->setCurrentIndex(0);
        CircuitLeft->setCurrentIndex(1);
        CircuitRight->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(Dual);
    } // setupUi

    void retranslateUi(QMainWindow *Dual)
    {
        Dual->setWindowTitle(QApplication::translate("Dual", "Dual", 0));
        label->setText(QApplication::translate("Dual", "<b>Valves</b>", 0));
        labelValve2->setText(QApplication::translate("Dual", "Valve n\302\2602", 0));
        labelValve4->setText(QApplication::translate("Dual", "Valve n\302\2604", 0));
        switchValve4->setText(QApplication::translate("Dual", "Switch", 0));
        labelValve5->setText(QApplication::translate("Dual", "Valve n\302\2605", 0));
        switchValve6->setText(QApplication::translate("Dual", "Switch", 0));
        switchValve3->setText(QApplication::translate("Dual", "Switch", 0));
        labelValve6->setText(QApplication::translate("Dual", "Valve n\302\2606", 0));
        labelValve3->setText(QApplication::translate("Dual", "Valve n\302\2603", 0));
        switchValve1->setText(QApplication::translate("Dual", "Switch", 0));
        switchValve5->setText(QApplication::translate("Dual", "Switch", 0));
        switchValve2->setText(QApplication::translate("Dual", "Switch", 0));
        labelValve1->setText(QApplication::translate("Dual", "Valve n\302\2601", 0));
        labelValvePin->setText(QApplication::translate("Dual", "Pin #", 0));
        labelValveStatus->setText(QApplication::translate("Dual", "Status", 0));
        labelEmpty1->setText(QString());
        MotorEnable->setText(QApplication::translate("Dual", "Enable", 0));
        MotorRun->setText(QApplication::translate("Dual", "Run", 0));
        label_2->setText(QApplication::translate("Dual", "<html><head/><body><p><span style=\" font-weight:600;\">Motor</span></p></body></html>", 0));
        ProjectPathButton->setText(QApplication::translate("Dual", "Browse", 0));
        label_3->setText(QApplication::translate("Dual", "Project", 0));
        label_4->setText(QApplication::translate("Dual", "Data", 0));
        Autoset->setText(QApplication::translate("Dual", "Autoset", 0));
        label_5->setText(QApplication::translate("Dual", "<html><head/><body><p><span style=\" font-weight:600;\">Directories</span></p></body></html>", 0));
        labelDirection->setText(QApplication::translate("Dual", "Move upward", 0));
        labelPeriod->setText(QApplication::translate("Dual", "Pulse period (\302\265s)", 0));
        MotorPeriod->setText(QApplication::translate("Dual", "1250", 0));
        label_6->setText(QString());
        label_7->setText(QString());
        label_8->setText(QString());
        labelDirectionPin->setText(QApplication::translate("Dual", "Direction pin", 0));
        labelStepPin->setText(QApplication::translate("Dual", "Steps pin", 0));
        labelLeftSwitchPin->setText(QApplication::translate("Dual", "Top switch", 0));
        labelRightSwitchPin->setText(QApplication::translate("Dual", "Bottom switch", 0));
        pinM3Label->setText(QApplication::translate("Dual", "MS3 pin", 0));
        labelPinEnable->setText(QApplication::translate("Dual", "Enable pin", 0));
        pinM2Label->setText(QApplication::translate("Dual", "MS2 pin", 0));
        pinM1Label->setText(QApplication::translate("Dual", "MS1 pin", 0));
        label_12->setText(QString());
        label_14->setText(QApplication::translate("Dual", "Visible", 0));
        VisLED->setText(QApplication::translate("Dual", "ON", 0));
        label_15->setText(QApplication::translate("Dual", "IR", 0));
        IRLED->setText(QApplication::translate("Dual", "ON", 0));
        label_13->setText(QApplication::translate("Dual", "<html><head/><body><p><span style=\" font-weight:600;\">LEDs</span></p></body></html>", 0));
        label_16->setText(QApplication::translate("Dual", "<html><head/><body><p><span style=\" font-weight:600;\">Circuit</span></p></body></html>", 0));
        label_17->setText(QString());
        labelLeft->setText(QApplication::translate("Dual", "Left", 0));
        CircuitLeft->clear();
        CircuitLeft->insertItems(0, QStringList()
         << QApplication::translate("Dual", "Injection", 0)
         << QApplication::translate("Dual", "Buffer", 0)
         << QApplication::translate("Dual", "Stim", 0)
        );
        labelRight->setText(QApplication::translate("Dual", "Right", 0));
        CircuitRight->clear();
        CircuitRight->insertItems(0, QStringList()
         << QApplication::translate("Dual", "Injection", 0)
         << QApplication::translate("Dual", "Buffer", 0)
         << QApplication::translate("Dual", "Stim", 0)
        );
        Tabs->setTabText(Tabs->indexOf(Core), QApplication::translate("Dual", "Core", 0));
        Image->setText(QString());
        Tabs->setTabText(Tabs->indexOf(Camera), QApplication::translate("Dual", "Camera", 0));
        ProtocolPathButton->setText(QApplication::translate("Dual", "Browse", 0));
        label_9->setText(QApplication::translate("Dual", "File", 0));
        ProtocolPath->setText(QApplication::translate("Dual", "/home/ljp/Science/Projects/Behavior/Dual/Programs/Dual_GUI/BLBR.protocol", 0));
        ProtocolRun->setText(QApplication::translate("Dual", "Run protocol", 0));
        ProtocolTime->setText(QApplication::translate("Dual", "00:00:00", 0));
        spawningDateLabel->setText(QApplication::translate("Dual", "Spawning date", 0));
        ageLabel->setText(QApplication::translate("Dual", "Age", 0));
        stimulusLabel->setText(QApplication::translate("Dual", "Stimulus", 0));
        concentrationLabel->setText(QApplication::translate("Dual", "Concentration", 0));
        label_10->setText(QString());
        label_11->setText(QApplication::translate("Dual", "<html><head/><body><p><span style=\" font-weight:600;\">Run parameters</span></p></body></html>", 0));
        Tabs->setTabText(Tabs->indexOf(Protocols), QApplication::translate("Dual", "Protocols", 0));
        Snapshot->setText(QApplication::translate("Dual", "Snapshot", 0));
    } // retranslateUi

};

namespace Ui {
    class Dual: public Ui_Dual {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DUAL_H
