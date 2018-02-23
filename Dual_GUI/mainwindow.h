#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDebug>
#include <QMainWindow>
#include <QDir>
#include <QShortcut>
#include <QScrollBar>
#include <QVector>
#include <QDesktopWidget>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QTimer>
#include <QFile>
#include <QFontDatabase>
#include <QHashIterator>
#include <QThread>

#include "MsgHandler.h"
#include "Cameras.h"
#include "Dual.h"

// === Custom structures ===================================================

struct StSer {
   QString port;
   QSerialPort *conn;
};

// === Mainwindow class ====================================================

namespace Ui { class MainWindow; }

class MainWindow : public QMainWindow {

    Q_OBJECT

public:

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:

    // Messages
    void UpdateMessage();

    // Settings
    void loadSettings();

    // --- Cameras
    void refreshCameras();

    // Serial connection
    void checkSerial();
    void getSerialId();
    void toggleWindow(bool);
    void uncheckDual(int);


private:

    QString filesep, progPath, projPath;
    int NDual;

    // --- Windows management -------------------

    Ui::MainWindow *ui;
    QVector<QRect> Screen;

    QShortcut *s_Close;
    QShortcut *s_Settings;

    // --- Dual windows -------------------------

    QVector<StSer> Serial;
    QVector<Dual*> Duals;

    // --- Cameras ------------------------------

    Cameras *Cams;
    QHash<int, QString> CamNames;

};

#endif // MAINWINDOW_H

