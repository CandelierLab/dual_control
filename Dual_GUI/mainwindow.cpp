#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MainWindow) {

    // === DEFINITIONS =====================================================

    // --- Pathes
    filesep = QString(QDir::separator());
    progPath = QDir::currentPath() + filesep;
    projPath = QDir::currentPath();
    projPath = projPath.mid(0, projPath.toStdString().find_last_of(filesep.toStdString()));
    projPath = projPath.mid(0, projPath.toStdString().find_last_of(filesep.toStdString())) + filesep;

    // Number of Dual setups
    NDual = 4;

    // === USER INTERFACE ==================================================

    // --- Main window --------------------------

    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);

    // --- Shortcuts

    // Esc: Close
    s_Close = new QShortcut(Qt::Key_Escape, this);
    connect(s_Close, SIGNAL(activated()), QApplication::instance(), SLOT(quit()));

    // p: Reload settings
    s_Settings = new QShortcut(QKeySequence("P"), this);
    connect(s_Settings, SIGNAL(activated()), this, SLOT(loadSettings()));

    // i: Set all Duals to Idle state
    s_Idle = new QShortcut(QKeySequence("I"), this);
    connect(s_Idle, SIGNAL(activated()), this, SLOT(setIdle()));

    // x: Set all Duals to Xmas state
    s_Xmas = new QShortcut(QKeySequence("X"), this);
    connect(s_Xmas, SIGNAL(activated()), this, SLOT(setXmas()));

    // k: Set all Duals to K2000 state
    s_K2000 = new QShortcut(QKeySequence("K"), this);
    connect(s_K2000, SIGNAL(activated()), this, SLOT(setK2000()));

    // --- Messages -----------------------------

    // Style
    QFile File("output.css");
    File.open(QFile::ReadOnly);
    QTextDocument *OutDoc = new QTextDocument;
    OutDoc->setDefaultStyleSheet(File.readAll());
    OutDoc->setDefaultFont(QFontDatabase::systemFont(QFontDatabase::FixedFont));
    ui->Output->setDocument(OutDoc);

    // Timer
    QTimer *t_Msg = new QTimer();
    connect(t_Msg, SIGNAL(timeout()), this, SLOT(UpdateMessage()));
    t_Msg->start(50);

    qInfo() << TITLE_1 << "Initialization";

    // --- Get screen info -------------------

    qInfo() << TITLE_2 << "Screens";

    QDesktopWidget Desktop;
    switch (Desktop.screenCount()) {
        case 0: qInfo() << "No screen detected"; break;
        case 1: qInfo() << "1 screen detected"; break;
        default: qInfo() << Desktop.screenCount() << "screens detected"; break;
    }

    for (int i=0; i<Desktop.screenCount(); i++) {
        Screen.push_back(Desktop.availableGeometry(i));
        qInfo().nospace() << " [" << i << "] " << Desktop.availableGeometry(i);
    }

    // --- Geometry -----------------------------

    this->move(Screen[0].x(), Screen[0].y());

    // === Duals ===========================================================

    for (int i=1; i<=NDual; i++) {
         Duals.append(new Dual(Screen, projPath, i));
    }

    // === Settings ========================================================

    loadSettings();

    // === Serial connections ==============================================

    for (int i=0; i<NDual; i++) {
        StSer tmp;
        tmp.port = "";
        Serial.append(tmp);
    }

    // === Cameras =========================================================

    Cams = new Cameras;
    refreshCameras();

    // === Connections =====================================================

    // Custom types registation
    qRegisterMetaType<SImage>();

    connect(ui->CheckSerial, SIGNAL(released()), this, SLOT(checkSerial()));

    connect(ui->Dual_1, SIGNAL(toggled(bool)), this, SLOT(toggleWindow(bool)));
    connect(ui->Dual_2, SIGNAL(toggled(bool)), this, SLOT(toggleWindow(bool)));
    connect(ui->Dual_3, SIGNAL(toggled(bool)), this, SLOT(toggleWindow(bool)));
    connect(ui->Dual_4, SIGNAL(toggled(bool)), this, SLOT(toggleWindow(bool)));

    // === Startup =========================================================

    checkSerial();

}

/* ====================================================================== *\
|    MESSAGES                                                              |
\* ====================================================================== */

void MainWindow::UpdateMessage() {

    while (Messages.length()) {

        Message MSG = Messages.takeFirst();
        QString S;

        switch (MSG.type) {
        case QtDebugMsg:
            cout << MSG.text.toStdString() << endl;
            break;
        case QtInfoMsg:
            S = "<" + MSG.css + ">" + MSG.text + "</p>" ;
            break;
        case QtWarningMsg:
            S = "<p class='warning'>" + MSG.text + "</p>";
            break;
        case QtCriticalMsg:
            S= "<p class='critical'>" + MSG.text + "</p>";
            break;
        case QtFatalMsg:
            S = "<p class='fatal'>" + MSG.text + "</p>";
            break;
        }

        ui->Output->setHtml(ui->Output->toHtml().append(S));
        ui->Output->verticalScrollBar()->setValue(ui->Output->verticalScrollBar()->maximum());
    }
}

/* ====================================================================== *\
|    SETTINGS                                                              |
\* ====================================================================== */

void MainWindow::loadSettings() {

    QFile *SFile = new QFile(progPath + "Settings.conf");

    if (!SFile->open(QIODevice::ReadOnly | QIODevice::Text)) {

        QFileInfo qfi(SFile->fileName());
        if (qfi.fileName()!="settings.conf") {
            qWarning() << "Unable to read \"" << SFile->fileName() << "\"";
        } else {
            qWarning() << "Unable to find \"" << SFile->fileName() << "\"";
        }
        return;
    };

    QTextStream stream(SFile);
    QString line;
    while (stream.readLineInto(&line)) {

        // --- Remove empty lines and comments
        if (line.isEmpty() || line.left(1) == "#") { continue; }

        // --- Parse command
        QStringList list = line.split(":");

        if (list.at(0)=="print") {

            // --- PRINT ------------------------

            qInfo() << qPrintable(list.at(1));

        } else if (list.at(0)=="CamSN") {

            // --- CAMERA SERIAL NUMBER ---------

            CamNames.insert(list.at(1).toInt()-1, list.at(2));

        } else if (list.at(0)=="ROI") {

            // --- REGION OF INTEREST ---------
            QStringList tmp = list.at(2).split(",");
            Duals[list.at(1).toInt()-1]->ROI = QRect(tmp.at(0).toInt(), tmp.at(1).toInt(), tmp.at(2).toInt(), tmp.at(3).toInt());

        }
    }

}

/* ====================================================================== *\
|    CAMERAS                                                               |
\* ====================================================================== */

void MainWindow::refreshCameras() {

    // --- Clean all
    // -- TO DO --

    // --- Refresh cameras
    Cams->RefreshAvailableCameras();
    Cams->displayCamerasInfos();

    // --- Per camera operations
    for (int i=0; i<Cams->List.count(); i++) {
        for (int j=0; j<CamNames.count(); j++) {
            if (Cams->List[i].name == CamNames.value(j)) {
                connect(Cams->List_FLIR[i], SIGNAL(newImage(SImage)), Duals[j], SLOT(newImage(SImage)));
                break;
            }
        }

    }

}


/* ====================================================================== *\
|    SERIAL CONNECTION                                                     |
\* ====================================================================== */

void MainWindow::checkSerial() {

    qInfo() << TITLE_2 << "Serial connections";

    // --- Get available ports

    const QList<QSerialPortInfo> infos = QSerialPortInfo::availablePorts();
    qInfo() << infos.length() << "serial connections detected";

    // --- Remove unused ports

    // !!! TO DO !!!

    // --- Assign new ports

    for (int i=0; i<infos.length(); i++) {

        // --- Checks

        // Skip non-Arduino connections
        if (infos[i].description().left(7).toLower()!="arduino") { continue; }

        // Skip connections already attributed
        bool att = false;
        for (int j=0; j<Serial.length(); j++) {
            if (Serial[j].port == infos[i].portName()) { att = true; break; }
        }
        if (att) { continue; }

        // Is device busy ?
        if (infos[i].isBusy()) {
            qInfo().nospace() << "[" << infos[i].portName() << "] is busy ...";
            continue;
        }

        // --- Open connection and ask for id

        qInfo() << "Checking" << infos[i].portName();

        QSerialPort *conn = new QSerialPort(this);
        conn->setPortName(infos[i].portName());
        conn->setBaudRate(115200);
        conn->setDataBits(QSerialPort::Data8);
        conn->setParity(QSerialPort::NoParity);
        conn->setStopBits(QSerialPort::OneStop);
        conn->setFlowControl(QSerialPort::NoFlowControl);
        connect(conn, SIGNAL(readyRead()), this, SLOT(getSerialId()));

        if (conn->open(QIODevice::ReadWrite)) {
            for (int i=0 ; i<10 ; i++) {
                conn->write("getId");
                conn->flush();
                QThread::msleep(100);
            }
        } else {
            qWarning() << "Failed to open port" << conn->portName();
        }

    }

}

void MainWindow::getSerialId() {

    // Get sender connection
    QSerialPort* conn = qobject_cast<QSerialPort*>(sender());

    // Read response
    QByteArray readData = conn->readAll();
    while (conn->waitForReadyRead(0)) {
        readData.append(conn->readAll());
    }

    // Convert it to identifier
    QString res(readData);
    int guiid = res.left(1).toInt();

    qInfo() << "→" << conn->portName() << "is Dual" << guiid;

    // Assign to the list of serial objects
    Serial[guiid-1].conn = conn;
    Serial[guiid-1].port = conn->portName();

    // Transfert serial port name to Dual
    Duals[guiid-1]->portName = conn->portName();
    conn->close();
    delete(conn);

    // Update GUI button status
    switch (guiid) {
        case 1: ui->Dual_1->setEnabled(true); break;
        case 2: ui->Dual_2->setEnabled(true); break;
        case 3: ui->Dual_3->setEnabled(true); break;
        case 4: ui->Dual_4->setEnabled(true); break;
    }

}

// === Sates ===============================================================

void MainWindow::setIdle() {
    for (int i=0; i<NDual; i++) {
        if (Duals[i]->initialized) { Duals[i]->setState(QString("Idle")); }
    }
}

void MainWindow::setXmas() {
    for (int i=0; i<NDual; i++) {
        if (Duals[i]->initialized) { Duals[i]->setState(QString("Xmas")); }
    }
}

void MainWindow::setK2000() {
    for (int i=0; i<NDual; i++) {
        if (Duals[i]->initialized) { Duals[i]->setState(QString("K2000")); }
    }
}

// === Window management ===================================================

void MainWindow::toggleWindow(bool b) {

    QPushButton* bDual = qobject_cast<QPushButton*>(sender());
    int guiid = bDual->text().right(1).toInt();

    if (b) {
        Duals[guiid-1]->initialize();
        Duals[guiid-1]->show();
        Duals[guiid-1]->setState(QString("Active"));
    } else {
        Duals[guiid-1]->hide();
        Duals[guiid-1]->setState(QString("Idle"));
    }

}

void MainWindow::uncheckDual(int guiid) {

    switch (guiid) {
        case 1: ui->Dual_1->setChecked(false); break;
        case 2: ui->Dual_2->setChecked(false); break;
        case 3: ui->Dual_3->setChecked(false); break;
        case 4: ui->Dual_4->setChecked(false); break;
    }

}

MainWindow::~MainWindow() {
    delete ui;
}
