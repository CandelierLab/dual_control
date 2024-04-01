/********************************************************************************
** Form generated from reading UI file 'Dual.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DUAL_H
#define UI_DUAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dual
{
public:
    QAction *actionQuit;
    QWidget *centralWidget;
    QGridLayout *gridLayout_9;
    QTabWidget *Tabs;
    QWidget *Core;
    QGridLayout *gridLayout_11;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_6;
    QGridLayout *ValveLayout;
    QLabel *labelValve6;
    QPushButton *switchValve4;
    QPushButton *switchValve5;
    QPushButton *switchValve2;
    QLabel *labelValve1;
    QLabel *labelValve2;
    QSpinBox *pinValve6;
    QLabel *labelValve4;
    QLabel *labelValve5;
    QPushButton *switchValve1;
    QSpinBox *pinValve1;
    QSpinBox *pinValve4;
    QLabel *labelValveStatus;
    QSpinBox *pinValve3;
    QPushButton *switchValve6;
    QPushButton *switchValve3;
    QLabel *labelValve3;
    QSpinBox *pinValve5;
    QSpinBox *pinValve2;
    QLabel *labelValvePin;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_4;
    QGridLayout *gridLayout_3;
    QPushButton *MotorEnable;
    QSpinBox *pTopSwitch;
    QLabel *labelStepPin;
    QSpinBox *pinStep;
    QLabel *labelPinEnable;
    QSpinBox *pinMS3;
    QCheckBox *MotorDir;
    QLabel *labelRightSwitchPin;
    QLabel *pinM2Label;
    QSpinBox *pBottomSwitch;
    QLabel *labelDirection;
    QSpinBox *pinEnable;
    QPushButton *MotorRun;
    QLabel *labelDirectionPin;
    QSpinBox *pinDir;
    QLabel *labelPeriod;
    QLabel *pinM1Label;
    QSpinBox *pinMS1;
    QLabel *labelLeftSwitchPin;
    QLineEdit *MotorPeriod;
    QLabel *pinM3Label;
    QSpinBox *pinMS2;
    QGroupBox *groupBox_5;
    QGridLayout *gridLayout_10;
    QHBoxLayout *horizontalLayout;
    QLabel *label_14;
    QSpinBox *pinVisLED;
    QPushButton *VisLED;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_15;
    QSpinBox *pinIRLED;
    QPushButton *IRLED;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_8;
    QHBoxLayout *horizontalLayout_3;
    QLabel *labelLeft;
    QComboBox *CircuitLeft;
    QHBoxLayout *horizontalLayout_4;
    QLabel *labelRight;
    QComboBox *CircuitRight;
    QWidget *Camera;
    QGridLayout *gridLayout_7;
    QLabel *Image;
    QPushButton *Snapshot;
    QWidget *Protocols;
    QGridLayout *gridLayout_2;
    QFormLayout *formLayout;
    QLabel *label_11;
    QLabel *spawningDateLabel;
    QDateEdit *spawningDate;
    QLabel *ageLabel;
    QLineEdit *Age;
    QLabel *stimulusLabel;
    QLineEdit *Stimulus;
    QLabel *concentrationLabel;
    QLineEdit *Concentration;
    QLabel *label_9;
    QSplitter *splitter_3;
    QLineEdit *ProtocolPath;
    QPushButton *ProtocolPathButton;
    QPushButton *ProtocolRun;
    QLabel *ProtocolTime;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_5;
    QGridLayout *gridLayout;
    QLabel *label_3;
    QLineEdit *ProjectPath;
    QPushButton *Autoset;
    QLabel *label_4;
    QPushButton *ProjectPathButton;
    QLineEdit *DataPath;
    QMenuBar *menuBar;
    QMenu *menuQuit;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Dual)
    {
        if (Dual->objectName().isEmpty())
            Dual->setObjectName(QString::fromUtf8("Dual"));
        Dual->resize(800, 480);
        actionQuit = new QAction(Dual);
        actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
        centralWidget = new QWidget(Dual);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout_9 = new QGridLayout(centralWidget);
        gridLayout_9->setSpacing(6);
        gridLayout_9->setContentsMargins(11, 11, 11, 11);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        Tabs = new QTabWidget(centralWidget);
        Tabs->setObjectName(QString::fromUtf8("Tabs"));
        Core = new QWidget();
        Core->setObjectName(QString::fromUtf8("Core"));
        gridLayout_11 = new QGridLayout(Core);
        gridLayout_11->setSpacing(6);
        gridLayout_11->setContentsMargins(11, 11, 11, 11);
        gridLayout_11->setObjectName(QString::fromUtf8("gridLayout_11"));
        groupBox_3 = new QGroupBox(Core);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setMaximumSize(QSize(650, 411));
        gridLayout_6 = new QGridLayout(groupBox_3);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        ValveLayout = new QGridLayout();
        ValveLayout->setSpacing(6);
        ValveLayout->setObjectName(QString::fromUtf8("ValveLayout"));
        labelValve6 = new QLabel(groupBox_3);
        labelValve6->setObjectName(QString::fromUtf8("labelValve6"));
        labelValve6->setAlignment(Qt::AlignCenter);

        ValveLayout->addWidget(labelValve6, 6, 0, 1, 1);

        switchValve4 = new QPushButton(groupBox_3);
        switchValve4->setObjectName(QString::fromUtf8("switchValve4"));
        switchValve4->setMaximumSize(QSize(80, 16777215));
        switchValve4->setCheckable(true);
        switchValve4->setChecked(false);

        ValveLayout->addWidget(switchValve4, 4, 2, 1, 1);

        switchValve5 = new QPushButton(groupBox_3);
        switchValve5->setObjectName(QString::fromUtf8("switchValve5"));
        switchValve5->setMaximumSize(QSize(80, 16777215));
        switchValve5->setCheckable(true);
        switchValve5->setChecked(false);

        ValveLayout->addWidget(switchValve5, 5, 2, 1, 1);

        switchValve2 = new QPushButton(groupBox_3);
        switchValve2->setObjectName(QString::fromUtf8("switchValve2"));
        switchValve2->setMaximumSize(QSize(80, 16777215));
        switchValve2->setCheckable(true);
        switchValve2->setChecked(false);

        ValveLayout->addWidget(switchValve2, 2, 2, 1, 1);

        labelValve1 = new QLabel(groupBox_3);
        labelValve1->setObjectName(QString::fromUtf8("labelValve1"));
        labelValve1->setEnabled(true);
        labelValve1->setAlignment(Qt::AlignCenter);

        ValveLayout->addWidget(labelValve1, 1, 0, 1, 1);

        labelValve2 = new QLabel(groupBox_3);
        labelValve2->setObjectName(QString::fromUtf8("labelValve2"));
        labelValve2->setAlignment(Qt::AlignCenter);

        ValveLayout->addWidget(labelValve2, 2, 0, 1, 1);

        pinValve6 = new QSpinBox(groupBox_3);
        pinValve6->setObjectName(QString::fromUtf8("pinValve6"));
        pinValve6->setEnabled(false);
        pinValve6->setMaximumSize(QSize(50, 16777215));
        pinValve6->setValue(19);

        ValveLayout->addWidget(pinValve6, 6, 1, 1, 1);

        labelValve4 = new QLabel(groupBox_3);
        labelValve4->setObjectName(QString::fromUtf8("labelValve4"));
        labelValve4->setAlignment(Qt::AlignCenter);

        ValveLayout->addWidget(labelValve4, 4, 0, 1, 1);

        labelValve5 = new QLabel(groupBox_3);
        labelValve5->setObjectName(QString::fromUtf8("labelValve5"));
        labelValve5->setAlignment(Qt::AlignCenter);

        ValveLayout->addWidget(labelValve5, 5, 0, 1, 1);

        switchValve1 = new QPushButton(groupBox_3);
        switchValve1->setObjectName(QString::fromUtf8("switchValve1"));
        switchValve1->setMaximumSize(QSize(80, 16777215));
        switchValve1->setCheckable(true);
        switchValve1->setChecked(false);

        ValveLayout->addWidget(switchValve1, 1, 2, 1, 1);

        pinValve1 = new QSpinBox(groupBox_3);
        pinValve1->setObjectName(QString::fromUtf8("pinValve1"));
        pinValve1->setEnabled(false);
        pinValve1->setMaximumSize(QSize(50, 16777215));
        pinValve1->setValue(14);

        ValveLayout->addWidget(pinValve1, 1, 1, 1, 1);

        pinValve4 = new QSpinBox(groupBox_3);
        pinValve4->setObjectName(QString::fromUtf8("pinValve4"));
        pinValve4->setEnabled(false);
        pinValve4->setMaximumSize(QSize(50, 16777215));
        pinValve4->setValue(17);

        ValveLayout->addWidget(pinValve4, 4, 1, 1, 1);

        labelValveStatus = new QLabel(groupBox_3);
        labelValveStatus->setObjectName(QString::fromUtf8("labelValveStatus"));
        labelValveStatus->setMaximumSize(QSize(16777215, 20));
        labelValveStatus->setAlignment(Qt::AlignCenter);

        ValveLayout->addWidget(labelValveStatus, 0, 2, 1, 1);

        pinValve3 = new QSpinBox(groupBox_3);
        pinValve3->setObjectName(QString::fromUtf8("pinValve3"));
        pinValve3->setEnabled(false);
        pinValve3->setMaximumSize(QSize(50, 16777215));
        pinValve3->setValue(16);

        ValveLayout->addWidget(pinValve3, 3, 1, 1, 1);

        switchValve6 = new QPushButton(groupBox_3);
        switchValve6->setObjectName(QString::fromUtf8("switchValve6"));
        switchValve6->setMaximumSize(QSize(80, 16777215));
        switchValve6->setCheckable(true);
        switchValve6->setChecked(false);

        ValveLayout->addWidget(switchValve6, 6, 2, 1, 1);

        switchValve3 = new QPushButton(groupBox_3);
        switchValve3->setObjectName(QString::fromUtf8("switchValve3"));
        switchValve3->setMaximumSize(QSize(80, 16777215));
        switchValve3->setCheckable(true);
        switchValve3->setChecked(false);

        ValveLayout->addWidget(switchValve3, 3, 2, 1, 1);

        labelValve3 = new QLabel(groupBox_3);
        labelValve3->setObjectName(QString::fromUtf8("labelValve3"));
        labelValve3->setAlignment(Qt::AlignCenter);

        ValveLayout->addWidget(labelValve3, 3, 0, 1, 1);

        pinValve5 = new QSpinBox(groupBox_3);
        pinValve5->setObjectName(QString::fromUtf8("pinValve5"));
        pinValve5->setEnabled(false);
        pinValve5->setMaximumSize(QSize(50, 16777215));
        pinValve5->setValue(18);

        ValveLayout->addWidget(pinValve5, 5, 1, 1, 1);

        pinValve2 = new QSpinBox(groupBox_3);
        pinValve2->setObjectName(QString::fromUtf8("pinValve2"));
        pinValve2->setEnabled(false);
        pinValve2->setMaximumSize(QSize(50, 16777215));
        pinValve2->setValue(15);

        ValveLayout->addWidget(pinValve2, 2, 1, 1, 1);

        labelValvePin = new QLabel(groupBox_3);
        labelValvePin->setObjectName(QString::fromUtf8("labelValvePin"));
        labelValvePin->setMaximumSize(QSize(16777215, 20));
        labelValvePin->setAlignment(Qt::AlignCenter);

        ValveLayout->addWidget(labelValvePin, 0, 1, 1, 1);


        gridLayout_6->addLayout(ValveLayout, 0, 0, 1, 1);


        gridLayout_11->addWidget(groupBox_3, 0, 0, 1, 1);

        groupBox = new QGroupBox(Core);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMaximumSize(QSize(650, 401));
        gridLayout_4 = new QGridLayout(groupBox);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        MotorEnable = new QPushButton(groupBox);
        MotorEnable->setObjectName(QString::fromUtf8("MotorEnable"));
        MotorEnable->setCheckable(true);
        MotorEnable->setChecked(true);

        gridLayout_3->addWidget(MotorEnable, 4, 1, 1, 1);

        pTopSwitch = new QSpinBox(groupBox);
        pTopSwitch->setObjectName(QString::fromUtf8("pTopSwitch"));
        pTopSwitch->setEnabled(false);
        pTopSwitch->setMaximumSize(QSize(50, 16777215));
        pTopSwitch->setValue(9);

        gridLayout_3->addWidget(pTopSwitch, 3, 3, 1, 1);

        labelStepPin = new QLabel(groupBox);
        labelStepPin->setObjectName(QString::fromUtf8("labelStepPin"));
        QFont font;
        font.setPointSize(10);
        labelStepPin->setFont(font);
        labelStepPin->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(labelStepPin, 2, 2, 1, 1);

        pinStep = new QSpinBox(groupBox);
        pinStep->setObjectName(QString::fromUtf8("pinStep"));
        pinStep->setEnabled(false);
        pinStep->setMaximumSize(QSize(50, 16777215));
        pinStep->setValue(7);

        gridLayout_3->addWidget(pinStep, 2, 3, 1, 1);

        labelPinEnable = new QLabel(groupBox);
        labelPinEnable->setObjectName(QString::fromUtf8("labelPinEnable"));
        labelPinEnable->setFont(font);
        labelPinEnable->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(labelPinEnable, 1, 2, 1, 1);

        pinMS3 = new QSpinBox(groupBox);
        pinMS3->setObjectName(QString::fromUtf8("pinMS3"));
        pinMS3->setEnabled(false);
        pinMS3->setValue(4);

        gridLayout_3->addWidget(pinMS3, 1, 1, 1, 1);

        MotorDir = new QCheckBox(groupBox);
        MotorDir->setObjectName(QString::fromUtf8("MotorDir"));
        MotorDir->setChecked(true);

        gridLayout_3->addWidget(MotorDir, 4, 3, 1, 1);

        labelRightSwitchPin = new QLabel(groupBox);
        labelRightSwitchPin->setObjectName(QString::fromUtf8("labelRightSwitchPin"));
        QFont font1;
        font1.setPointSize(9);
        labelRightSwitchPin->setFont(font1);
        labelRightSwitchPin->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(labelRightSwitchPin, 3, 0, 1, 1);

        pinM2Label = new QLabel(groupBox);
        pinM2Label->setObjectName(QString::fromUtf8("pinM2Label"));
        pinM2Label->setFont(font);
        pinM2Label->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(pinM2Label, 0, 2, 1, 1);

        pBottomSwitch = new QSpinBox(groupBox);
        pBottomSwitch->setObjectName(QString::fromUtf8("pBottomSwitch"));
        pBottomSwitch->setEnabled(false);
        pBottomSwitch->setMaximumSize(QSize(50, 50));
        pBottomSwitch->setValue(8);

        gridLayout_3->addWidget(pBottomSwitch, 3, 1, 1, 1);

        labelDirection = new QLabel(groupBox);
        labelDirection->setObjectName(QString::fromUtf8("labelDirection"));
        labelDirection->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(labelDirection, 4, 2, 1, 1);

        pinEnable = new QSpinBox(groupBox);
        pinEnable->setObjectName(QString::fromUtf8("pinEnable"));
        pinEnable->setEnabled(false);
        pinEnable->setMaximumSize(QSize(50, 16777215));
        pinEnable->setValue(5);

        gridLayout_3->addWidget(pinEnable, 1, 3, 1, 1);

        MotorRun = new QPushButton(groupBox);
        MotorRun->setObjectName(QString::fromUtf8("MotorRun"));
        MotorRun->setCheckable(true);

        gridLayout_3->addWidget(MotorRun, 5, 1, 1, 1);

        labelDirectionPin = new QLabel(groupBox);
        labelDirectionPin->setObjectName(QString::fromUtf8("labelDirectionPin"));
        labelDirectionPin->setFont(font);
        labelDirectionPin->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(labelDirectionPin, 2, 0, 1, 1);

        pinDir = new QSpinBox(groupBox);
        pinDir->setObjectName(QString::fromUtf8("pinDir"));
        pinDir->setEnabled(false);
        pinDir->setMaximumSize(QSize(50, 16777215));
        pinDir->setValue(6);

        gridLayout_3->addWidget(pinDir, 2, 1, 1, 1);

        labelPeriod = new QLabel(groupBox);
        labelPeriod->setObjectName(QString::fromUtf8("labelPeriod"));
        labelPeriod->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(labelPeriod, 5, 2, 1, 1);

        pinM1Label = new QLabel(groupBox);
        pinM1Label->setObjectName(QString::fromUtf8("pinM1Label"));
        pinM1Label->setMaximumSize(QSize(136, 16777215));
        pinM1Label->setFont(font);
        pinM1Label->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(pinM1Label, 0, 0, 1, 1);

        pinMS1 = new QSpinBox(groupBox);
        pinMS1->setObjectName(QString::fromUtf8("pinMS1"));
        pinMS1->setEnabled(false);
        pinMS1->setMaximumSize(QSize(50, 16777215));
        pinMS1->setValue(2);

        gridLayout_3->addWidget(pinMS1, 0, 1, 1, 1);

        labelLeftSwitchPin = new QLabel(groupBox);
        labelLeftSwitchPin->setObjectName(QString::fromUtf8("labelLeftSwitchPin"));
        labelLeftSwitchPin->setFont(font1);
        labelLeftSwitchPin->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(labelLeftSwitchPin, 3, 2, 1, 1);

        MotorPeriod = new QLineEdit(groupBox);
        MotorPeriod->setObjectName(QString::fromUtf8("MotorPeriod"));
        MotorPeriod->setMaximumSize(QSize(66, 16777215));

        gridLayout_3->addWidget(MotorPeriod, 5, 3, 1, 1);

        pinM3Label = new QLabel(groupBox);
        pinM3Label->setObjectName(QString::fromUtf8("pinM3Label"));
        pinM3Label->setFont(font);
        pinM3Label->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(pinM3Label, 1, 0, 1, 1);

        pinMS2 = new QSpinBox(groupBox);
        pinMS2->setObjectName(QString::fromUtf8("pinMS2"));
        pinMS2->setEnabled(false);
        pinMS2->setMaximumSize(QSize(50, 16777215));
        pinMS2->setValue(3);

        gridLayout_3->addWidget(pinMS2, 0, 3, 1, 1);


        gridLayout_4->addLayout(gridLayout_3, 0, 0, 1, 1);


        gridLayout_11->addWidget(groupBox, 0, 1, 1, 1);

        groupBox_5 = new QGroupBox(Core);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        groupBox_5->setMaximumSize(QSize(650, 16777215));
        gridLayout_10 = new QGridLayout(groupBox_5);
        gridLayout_10->setSpacing(6);
        gridLayout_10->setContentsMargins(11, 11, 11, 11);
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_14 = new QLabel(groupBox_5);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setMaximumSize(QSize(60, 16777215));
        label_14->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_14);

        pinVisLED = new QSpinBox(groupBox_5);
        pinVisLED->setObjectName(QString::fromUtf8("pinVisLED"));
        pinVisLED->setEnabled(false);
        pinVisLED->setMaximumSize(QSize(50, 16777215));
        pinVisLED->setValue(10);

        horizontalLayout->addWidget(pinVisLED);

        VisLED = new QPushButton(groupBox_5);
        VisLED->setObjectName(QString::fromUtf8("VisLED"));
        VisLED->setMaximumSize(QSize(50, 16777215));
        VisLED->setCheckable(true);

        horizontalLayout->addWidget(VisLED);


        gridLayout_10->addLayout(horizontalLayout, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_15 = new QLabel(groupBox_5);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_15);

        pinIRLED = new QSpinBox(groupBox_5);
        pinIRLED->setObjectName(QString::fromUtf8("pinIRLED"));
        pinIRLED->setEnabled(false);
        pinIRLED->setValue(11);

        horizontalLayout_2->addWidget(pinIRLED);

        IRLED = new QPushButton(groupBox_5);
        IRLED->setObjectName(QString::fromUtf8("IRLED"));
        IRLED->setMaximumSize(QSize(50, 16777215));
        IRLED->setCheckable(true);

        horizontalLayout_2->addWidget(IRLED);


        gridLayout_10->addLayout(horizontalLayout_2, 1, 0, 1, 1);


        gridLayout_11->addWidget(groupBox_5, 1, 1, 1, 1);

        groupBox_4 = new QGroupBox(Core);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setMaximumSize(QSize(650, 131));
        gridLayout_8 = new QGridLayout(groupBox_4);
        gridLayout_8->setSpacing(6);
        gridLayout_8->setContentsMargins(11, 11, 11, 11);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        labelLeft = new QLabel(groupBox_4);
        labelLeft->setObjectName(QString::fromUtf8("labelLeft"));
        labelLeft->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(labelLeft);

        CircuitLeft = new QComboBox(groupBox_4);
        CircuitLeft->addItem(QString());
        CircuitLeft->addItem(QString());
        CircuitLeft->addItem(QString());
        CircuitLeft->setObjectName(QString::fromUtf8("CircuitLeft"));

        horizontalLayout_3->addWidget(CircuitLeft);


        gridLayout_8->addLayout(horizontalLayout_3, 0, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        labelRight = new QLabel(groupBox_4);
        labelRight->setObjectName(QString::fromUtf8("labelRight"));
        labelRight->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(labelRight);

        CircuitRight = new QComboBox(groupBox_4);
        CircuitRight->addItem(QString());
        CircuitRight->addItem(QString());
        CircuitRight->addItem(QString());
        CircuitRight->setObjectName(QString::fromUtf8("CircuitRight"));

        horizontalLayout_4->addWidget(CircuitRight);


        gridLayout_8->addLayout(horizontalLayout_4, 1, 0, 1, 1);


        gridLayout_11->addWidget(groupBox_4, 1, 0, 1, 1);

        Tabs->addTab(Core, QString());
        Camera = new QWidget();
        Camera->setObjectName(QString::fromUtf8("Camera"));
        gridLayout_7 = new QGridLayout(Camera);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        Image = new QLabel(Camera);
        Image->setObjectName(QString::fromUtf8("Image"));
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Image->sizePolicy().hasHeightForWidth());
        Image->setSizePolicy(sizePolicy);
        Image->setFrameShape(QFrame::NoFrame);
        Image->setFrameShadow(QFrame::Raised);
        Image->setMidLineWidth(0);
        Image->setAlignment(Qt::AlignCenter);

        gridLayout_7->addWidget(Image, 0, 0, 1, 1);

        Snapshot = new QPushButton(Camera);
        Snapshot->setObjectName(QString::fromUtf8("Snapshot"));

        gridLayout_7->addWidget(Snapshot, 1, 0, 1, 1);

        Tabs->addTab(Camera, QString());
        Protocols = new QWidget();
        Protocols->setObjectName(QString::fromUtf8("Protocols"));
        gridLayout_2 = new QGridLayout(Protocols);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label_11 = new QLabel(Protocols);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setMaximumSize(QSize(16777215, 20));
        label_11->setTextFormat(Qt::RichText);
        label_11->setAlignment(Qt::AlignCenter);

        formLayout->setWidget(0, QFormLayout::FieldRole, label_11);

        spawningDateLabel = new QLabel(Protocols);
        spawningDateLabel->setObjectName(QString::fromUtf8("spawningDateLabel"));

        formLayout->setWidget(1, QFormLayout::LabelRole, spawningDateLabel);

        spawningDate = new QDateEdit(Protocols);
        spawningDate->setObjectName(QString::fromUtf8("spawningDate"));

        formLayout->setWidget(1, QFormLayout::FieldRole, spawningDate);

        ageLabel = new QLabel(Protocols);
        ageLabel->setObjectName(QString::fromUtf8("ageLabel"));

        formLayout->setWidget(2, QFormLayout::LabelRole, ageLabel);

        Age = new QLineEdit(Protocols);
        Age->setObjectName(QString::fromUtf8("Age"));
        Age->setEnabled(false);

        formLayout->setWidget(2, QFormLayout::FieldRole, Age);

        stimulusLabel = new QLabel(Protocols);
        stimulusLabel->setObjectName(QString::fromUtf8("stimulusLabel"));

        formLayout->setWidget(3, QFormLayout::LabelRole, stimulusLabel);

        Stimulus = new QLineEdit(Protocols);
        Stimulus->setObjectName(QString::fromUtf8("Stimulus"));

        formLayout->setWidget(3, QFormLayout::FieldRole, Stimulus);

        concentrationLabel = new QLabel(Protocols);
        concentrationLabel->setObjectName(QString::fromUtf8("concentrationLabel"));

        formLayout->setWidget(4, QFormLayout::LabelRole, concentrationLabel);

        Concentration = new QLineEdit(Protocols);
        Concentration->setObjectName(QString::fromUtf8("Concentration"));

        formLayout->setWidget(4, QFormLayout::FieldRole, Concentration);

        label_9 = new QLabel(Protocols);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        formLayout->setWidget(5, QFormLayout::LabelRole, label_9);

        splitter_3 = new QSplitter(Protocols);
        splitter_3->setObjectName(QString::fromUtf8("splitter_3"));
        splitter_3->setOrientation(Qt::Horizontal);
        ProtocolPath = new QLineEdit(splitter_3);
        ProtocolPath->setObjectName(QString::fromUtf8("ProtocolPath"));
        ProtocolPath->setFont(font);
        splitter_3->addWidget(ProtocolPath);
        ProtocolPathButton = new QPushButton(splitter_3);
        ProtocolPathButton->setObjectName(QString::fromUtf8("ProtocolPathButton"));
        ProtocolPathButton->setFont(font);
        splitter_3->addWidget(ProtocolPathButton);

        formLayout->setWidget(5, QFormLayout::FieldRole, splitter_3);

        ProtocolRun = new QPushButton(Protocols);
        ProtocolRun->setObjectName(QString::fromUtf8("ProtocolRun"));
        ProtocolRun->setCheckable(true);

        formLayout->setWidget(7, QFormLayout::LabelRole, ProtocolRun);

        ProtocolTime = new QLabel(Protocols);
        ProtocolTime->setObjectName(QString::fromUtf8("ProtocolTime"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("DejaVu Sans"));
        font2.setPointSize(20);
        ProtocolTime->setFont(font2);
        ProtocolTime->setStyleSheet(QString::fromUtf8("color:black;"));
        ProtocolTime->setAlignment(Qt::AlignCenter);

        formLayout->setWidget(7, QFormLayout::FieldRole, ProtocolTime);

        groupBox_2 = new QGroupBox(Protocols);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setMaximumSize(QSize(16777215, 161));
        gridLayout_5 = new QGridLayout(groupBox_2);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_3, 0, 0, 1, 1);

        ProjectPath = new QLineEdit(groupBox_2);
        ProjectPath->setObjectName(QString::fromUtf8("ProjectPath"));

        gridLayout->addWidget(ProjectPath, 0, 1, 1, 1);

        Autoset = new QPushButton(groupBox_2);
        Autoset->setObjectName(QString::fromUtf8("Autoset"));

        gridLayout->addWidget(Autoset, 1, 2, 1, 1);

        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_4, 1, 0, 1, 1);

        ProjectPathButton = new QPushButton(groupBox_2);
        ProjectPathButton->setObjectName(QString::fromUtf8("ProjectPathButton"));

        gridLayout->addWidget(ProjectPathButton, 0, 2, 1, 1);

        DataPath = new QLineEdit(groupBox_2);
        DataPath->setObjectName(QString::fromUtf8("DataPath"));
        DataPath->setEnabled(false);

        gridLayout->addWidget(DataPath, 1, 1, 1, 1);


        gridLayout_5->addLayout(gridLayout, 0, 0, 1, 1);


        formLayout->setWidget(6, QFormLayout::SpanningRole, groupBox_2);


        gridLayout_2->addLayout(formLayout, 0, 0, 1, 1);

        Tabs->addTab(Protocols, QString());

        gridLayout_9->addWidget(Tabs, 1, 0, 1, 1);

        Dual->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Dual);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 800, 20));
        menuQuit = new QMenu(menuBar);
        menuQuit->setObjectName(QString::fromUtf8("menuQuit"));
        Dual->setMenuBar(menuBar);
        statusBar = new QStatusBar(Dual);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        Dual->setStatusBar(statusBar);

        menuBar->addAction(menuQuit->menuAction());
        menuQuit->addAction(actionQuit);

        retranslateUi(Dual);

        Tabs->setCurrentIndex(0);
        CircuitLeft->setCurrentIndex(1);
        CircuitRight->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(Dual);
    } // setupUi

    void retranslateUi(QMainWindow *Dual)
    {
        Dual->setWindowTitle(QCoreApplication::translate("Dual", "Dual", nullptr));
        actionQuit->setText(QCoreApplication::translate("Dual", "Quit", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("Dual", "Valves", nullptr));
        labelValve6->setText(QCoreApplication::translate("Dual", "Valve n\302\2606", nullptr));
        switchValve4->setText(QCoreApplication::translate("Dual", "Switch", nullptr));
        switchValve5->setText(QCoreApplication::translate("Dual", "Switch", nullptr));
        switchValve2->setText(QCoreApplication::translate("Dual", "Switch", nullptr));
        labelValve1->setText(QCoreApplication::translate("Dual", "Valve n\302\2601", nullptr));
        labelValve2->setText(QCoreApplication::translate("Dual", "Valve n\302\2602", nullptr));
        labelValve4->setText(QCoreApplication::translate("Dual", "Valve n\302\2604", nullptr));
        labelValve5->setText(QCoreApplication::translate("Dual", "Valve n\302\2605", nullptr));
        switchValve1->setText(QCoreApplication::translate("Dual", "Switch", nullptr));
        labelValveStatus->setText(QCoreApplication::translate("Dual", "Status", nullptr));
        switchValve6->setText(QCoreApplication::translate("Dual", "Switch", nullptr));
        switchValve3->setText(QCoreApplication::translate("Dual", "Switch", nullptr));
        labelValve3->setText(QCoreApplication::translate("Dual", "Valve n\302\2603", nullptr));
        labelValvePin->setText(QCoreApplication::translate("Dual", "Pin #", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Dual", "Motor", nullptr));
        MotorEnable->setText(QCoreApplication::translate("Dual", "Enable", nullptr));
        labelStepPin->setText(QCoreApplication::translate("Dual", "Steps pin", nullptr));
        labelPinEnable->setText(QCoreApplication::translate("Dual", "Enable pin", nullptr));
        labelRightSwitchPin->setText(QCoreApplication::translate("Dual", "Bottom switch", nullptr));
        pinM2Label->setText(QCoreApplication::translate("Dual", "MS2 pin", nullptr));
        labelDirection->setText(QCoreApplication::translate("Dual", "Move upward", nullptr));
        MotorRun->setText(QCoreApplication::translate("Dual", "Run", nullptr));
        labelDirectionPin->setText(QCoreApplication::translate("Dual", "Direction pin", nullptr));
        labelPeriod->setText(QCoreApplication::translate("Dual", "Pulse period (\302\265s)", nullptr));
        pinM1Label->setText(QCoreApplication::translate("Dual", "MS1 pin", nullptr));
        labelLeftSwitchPin->setText(QCoreApplication::translate("Dual", "Top switch", nullptr));
        MotorPeriod->setText(QCoreApplication::translate("Dual", "1250", nullptr));
        pinM3Label->setText(QCoreApplication::translate("Dual", "MS3 pin", nullptr));
        groupBox_5->setTitle(QCoreApplication::translate("Dual", "LEDs", nullptr));
        label_14->setText(QCoreApplication::translate("Dual", "Visible", nullptr));
        VisLED->setText(QCoreApplication::translate("Dual", "ON", nullptr));
        label_15->setText(QCoreApplication::translate("Dual", "IR", nullptr));
        IRLED->setText(QCoreApplication::translate("Dual", "ON", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("Dual", "Circuit", nullptr));
        labelLeft->setText(QCoreApplication::translate("Dual", "Left", nullptr));
        CircuitLeft->setItemText(0, QCoreApplication::translate("Dual", "Injection", nullptr));
        CircuitLeft->setItemText(1, QCoreApplication::translate("Dual", "Buffer", nullptr));
        CircuitLeft->setItemText(2, QCoreApplication::translate("Dual", "Stim", nullptr));

        labelRight->setText(QCoreApplication::translate("Dual", "Right", nullptr));
        CircuitRight->setItemText(0, QCoreApplication::translate("Dual", "Injection", nullptr));
        CircuitRight->setItemText(1, QCoreApplication::translate("Dual", "Buffer", nullptr));
        CircuitRight->setItemText(2, QCoreApplication::translate("Dual", "Stim", nullptr));

        Tabs->setTabText(Tabs->indexOf(Core), QCoreApplication::translate("Dual", "Core", nullptr));
        Image->setText(QString());
        Snapshot->setText(QCoreApplication::translate("Dual", "Snapshot", nullptr));
        Tabs->setTabText(Tabs->indexOf(Camera), QCoreApplication::translate("Dual", "Camera", nullptr));
        label_11->setText(QCoreApplication::translate("Dual", "<html><head/><body><p><span style=\" font-weight:600;\">Run parameters</span></p></body></html>", nullptr));
        spawningDateLabel->setText(QCoreApplication::translate("Dual", "Spawning date", nullptr));
        ageLabel->setText(QCoreApplication::translate("Dual", "Age", nullptr));
        stimulusLabel->setText(QCoreApplication::translate("Dual", "Stimulus", nullptr));
        concentrationLabel->setText(QCoreApplication::translate("Dual", "Concentration", nullptr));
        label_9->setText(QCoreApplication::translate("Dual", "File", nullptr));
        ProtocolPath->setText(QCoreApplication::translate("Dual", "/home/ubuntu/Documents/dual_control/Dual_GUI/BLBR.protocol", nullptr));
        ProtocolPathButton->setText(QCoreApplication::translate("Dual", "Browse", nullptr));
        ProtocolRun->setText(QCoreApplication::translate("Dual", "Run protocol", nullptr));
        ProtocolTime->setText(QCoreApplication::translate("Dual", "00:00:00", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("Dual", "Directories", nullptr));
        label_3->setText(QCoreApplication::translate("Dual", "Project", nullptr));
        Autoset->setText(QCoreApplication::translate("Dual", "Autoset", nullptr));
        label_4->setText(QCoreApplication::translate("Dual", "Data", nullptr));
        ProjectPathButton->setText(QCoreApplication::translate("Dual", "Browse", nullptr));
        Tabs->setTabText(Tabs->indexOf(Protocols), QCoreApplication::translate("Dual", "Protocols", nullptr));
        menuQuit->setTitle(QCoreApplication::translate("Dual", "Menu", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dual: public Ui_Dual {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DUAL_H
