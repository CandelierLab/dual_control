#ifndef DUAL_H
#define DUAL_H

#include <QMainWindow>
#include <QDebug>
#include <QVector>
#include <QDesktopWidget>
#include <QSerialPort>
#include <QCloseEvent>
#include <QTimer>
#include <QDateTime>
#include <QDir>
#include <QThread>
#include <QRegularExpression>
#include <QImageWriter>
#include <QFileDialog>

#include "MsgHandler.h"
#include "STypes.h"

#define OUT qInfo() << QString("%1|").arg(guiid).toStdString().c_str()

using namespace std;
namespace Ui { class Dual; }

class Dual : public QMainWindow {

    Q_OBJECT

public:

    // --- Properties ---------------------------

    // Path
    QString path;

    // Camera
    QRect ROI;

    // Serial communication
    QString portName;

    // --- Methods ------------------------------

    explicit Dual(QVector<QRect> screens, QString path, int id, QWidget *parent = 0);

    void initialize();

    virtual void closeEvent(QCloseEvent*);
    ~Dual();

signals:

    void closed(int);

public slots:

    // Camera
    void newImage(SImage);
    void updateDisplay();

    // Images
    void snapshot();
    void GrabLoop();

    // Serial communication
    void readSerial();
    void toggleValve(bool);

    // Valves
    void setCircuitLeft(int);
    void setCircuitRight(int);

    // Motor control
    void toggleEnable(bool);
    void toggleDir(bool);
    void toggleRun(bool);
    void setPeriod();

    // LEDs
    void toggleIRLED(bool);
    void toggleVisLED(bool);

    // Project directories
    void BrowseProject();
    void autoset();

    // Protocols
    void BrowseProtocol();
    void toggleProtocol(bool);
    void ProtoLoop();
    void ProtocolLoop();
    void updateAge(QDate);

private:

    // --- Properties ---------------------------

    bool initialized;

    // UI
    Ui::Dual *ui;
    QVector<QRect> Screen;

    // Identification
    int guiid;
    QString ID;

    int NValves;

    // Images
    int DisplayRate;
    QPixmap pixmap;
    qint64 TimeStamp;

    // Serial connection
    QSerialPort *conn;
    QRegularExpression *rxcmd;

    // Run
    int SaveRate;
    QTimer *timerGrab;
    int nRun;
    qint64 nFrame;
    QString RunPath;
    QImageWriter *ImgWriter;

    // Protocols
    QVector<QString> Protocol;
    QTime ProtocolTime;
    QTimer *timerProtocol;

    // --- Methods ------------------------------

    // Directories
    QString filesep;
    void updatePath();


    // Serial communication
    void send(QString);
    const char* str(QString);

    // Commands and protocol
    void setValve(int, bool);
    QString comment;
    QString currentState;

};

#endif // DUAL_H
