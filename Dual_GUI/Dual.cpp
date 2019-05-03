#include "Dual.h"
#include "ui_Dual.h"

Dual::Dual(QVector<QRect> screens, QString path, int id, QWidget *parent):
    Screen(screens), path(path), guiid(id), QMainWindow(parent), ui(new Ui::Dual) {

    // === DEFINITIONS =====================================================

    // --- Pathes
    filesep = QString(QDir::separator());

    // Hardware
    NValves = 6;

    // Camera
    ROI.setRect(0,0,100,100);
    DisplayRate = 30;           // Display rate (Hz)

    // Run
    SaveRate = 10;              // Image saving rate (Hz)
    nRun = 0;
    nFrame = 0;
    comment = QString();

    // Image writer
    ImgWriter = new QImageWriter;
    ImgWriter->setFormat("pgm");

    // Misc
    initialized = false;
    rxcmd = new QRegularExpression("^\\[[^\\]]+\\]$");

    // === USER INTERFACE ==================================================

    ui->setupUi(this);

    ui->Image->setScaledContents(true);

    // === Windows layout ==================================================

    // --- Set window geometry ----------------

    int irow = int(guiid>2);
    int icol = 1- (guiid%2);

    int wmain = 250;
    int szsh = 2;
    int szsv = 40;

    this->setGeometry(
            Screen[0].x() + wmain + szsh + icol*(Screen[0].width()-wmain)/2,
            Screen[0].y() + irow*Screen[0].height()/2,
            (Screen[0].width()-wmain)/2 - 2-szsh,
            Screen[0].height()/2 - szsv);

    // --- Set window title ---------------------

    this->setWindowTitle("Dual n°" + QString::number(guiid));

    // --- Set data path ------------------------

    ui->ProjectPath->setText(path);
    updatePath();

    // --- Set date -----------------------------

    ui->spawningDate->setDate(QDate::currentDate());

    // --- Connections --------------------------

    connect(ui->ProjectPathButton, SIGNAL(clicked()), this, SLOT(BrowseProject()));
    connect(ui->Autoset, SIGNAL(clicked()), this, SLOT(autoset()));
    connect(ui->ProtocolPathButton, SIGNAL(clicked()), this, SLOT(BrowseProtocol()));
    connect(ui->Snapshot, SIGNAL(clicked()), this, SLOT(snapshot()));

    connect(ui->switchValve1, SIGNAL(toggled(bool)), this, SLOT(toggleValve(bool)));
    connect(ui->switchValve2, SIGNAL(toggled(bool)), this, SLOT(toggleValve(bool)));
    connect(ui->switchValve3, SIGNAL(toggled(bool)), this, SLOT(toggleValve(bool)));
    connect(ui->switchValve4, SIGNAL(toggled(bool)), this, SLOT(toggleValve(bool)));
    connect(ui->switchValve5, SIGNAL(toggled(bool)), this, SLOT(toggleValve(bool)));
    connect(ui->switchValve6, SIGNAL(toggled(bool)), this, SLOT(toggleValve(bool)));
    connect(ui->CircuitLeft, SIGNAL(currentIndexChanged(int)), this, SLOT(setCircuitLeft(int)));
    connect(ui->CircuitRight, SIGNAL(currentIndexChanged(int)), this, SLOT(setCircuitRight(int)));

    connect(ui->IRLED, SIGNAL(toggled(bool)), this, SLOT(toggleIRLED(bool)));
    connect(ui->VisLED, SIGNAL(toggled(bool)), this, SLOT(toggleVisLED(bool)));

    connect(ui->MotorEnable, SIGNAL(toggled(bool)), this, SLOT(toggleEnable(bool)));
    connect(ui->MotorDir, SIGNAL(toggled(bool)), this, SLOT(toggleDir(bool)));
    connect(ui->MotorPeriod, SIGNAL(editingFinished()), this, SLOT(setPeriod()));
    connect(ui->MotorRun, SIGNAL(toggled(bool)), this, SLOT(toggleRun(bool)));

    connect(ui->ProtocolRun, SIGNAL(toggled(bool)), this, SLOT(toggleProtocol(bool)));
    connect(ui->spawningDate, SIGNAL(dateChanged(QDate)), this, SLOT(updateAge(QDate)));

    // === TIMERS ==========================================================

    // --- Camera grab timer

    timerGrab = new QTimer(this);
    connect(timerGrab, SIGNAL(timeout()), this, SLOT(GrabLoop()));

    // --- Camera display timer

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateDisplay()));
    timer->start(1000/DisplayRate);

    // --- Protocol timer
    timerProtocol = new QTimer(this);
    connect(timerProtocol, SIGNAL(timeout()), this, SLOT(ProtocolLoop()));

}

// === INITIALIZATTION =====================================================

void Dual::initialize() {

    // Skip if already initialized
    if (initialized) { return; }

    // Initialization message
    qInfo() << TITLE_1 << "Dual" << guiid;

    // --- Serial connection --------------------

    conn = new QSerialPort(this);
    conn->setPortName(this->portName);
    conn->setBaudRate(115200);
    conn->setDataBits(QSerialPort::Data8);
    conn->setParity(QSerialPort::NoParity);
    conn->setStopBits(QSerialPort::OneStop);
    conn->setFlowControl(QSerialPort::NoFlowControl);

    if (conn->open(QIODevice::ReadWrite)) {
        for (int i=0 ; i<10 ; i++) {
            conn->write("getId");
            conn->flush();
            QThread::msleep(100);
        }
    } else {
        qWarning() << "Failed to open port" << conn->portName();
        return;
    }


    OUT << "Init. serial connection";

    // Connect serial read output
    connect(conn, SIGNAL(readyRead()), this, SLOT(readSerial()));

    // --- Directories --------------------------

    autoset();

    // --- Initialization -----------------------

    initialized = true;

}

const char* Dual::str(QString s) {

    return s.toStdString().c_str();

}

// === DIRECTORIES =========================================================

void Dual::BrowseProject() {

    QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"), "/home", QFileDialog::ShowDirsOnly);
    if (dir.length()) {
        ui->ProjectPath->setText(dir + filesep);
        updatePath();
    }

}

void Dual::updatePath() {

    QDateTime now = QDateTime::currentDateTime();
    ui->DataPath->setText(ui->ProjectPath->text() + "Data" + filesep + now.toString("yyyy-MM-dd") + filesep);
    autoset();

}

void Dual::autoset() {

    // Create data folder?
    if (!QDir(ui->DataPath->text()).exists()) { QDir().mkdir(ui->DataPath->text()); }

    // Find last run
    nRun = 0;
    QDir DataDir(ui->DataPath->text());
    QFileInfoList FIL = DataDir.entryInfoList(QDir::AllDirs | QDir::NoDotAndDotDot, QDir::DirsFirst);
    foreach(const QFileInfo &elm, FIL) {
        if(QDir(elm.absoluteFilePath()).exists()) {

            QStringList tmp = elm.fileName().split(" ", QString::SkipEmptyParts);
            if (tmp.count()==2 || !tmp.at(0).compare("Run")) {
                tmp = tmp.at(1).split(".");
                if (tmp.at(0).toInt()==guiid && tmp.at(1).toInt()>nRun) { nRun = tmp.at(1).toInt(); }
            }

        }
    }

    if (nRun) {
        ui->statusBar->showMessage(QString("Last run: %1.%2").arg(guiid).arg(nRun, 2, 10, QLatin1Char('0')));
    } else {
        ui->statusBar->showMessage(QString("No run for today"));
    }
}

void Dual::updateAge(QDate) {

    ui->Age->setText(QString::number(ui->spawningDate->date().daysTo(QDate::currentDate())));

}

// === CAMERA ==============================================================

void Dual::newImage(SImage SImg) {

    pixmap = QPixmap::fromImage(SImg.Img.copy(ROI));
    TimeStamp = SImg.timestamp;

}

void Dual::updateDisplay() {

    ui->Image->setPixmap(pixmap);

}

void Dual::GrabLoop() {

    // --- Save image

    ImgWriter->setFileName(QString(RunPath + filesep + "Frame_%1.pgm").arg(nFrame, 6, 10, QLatin1Char('0')));
    ImgWriter->write(pixmap.toImage());

    // Append metadata
    QFile ImgFile(ImgWriter->fileName());
    if (ImgFile.open(QIODevice::WriteOnly | QIODevice::Append)) {
        QTextStream tmp(&ImgFile);
        tmp << endl << "#" + QString("Timestamp:%1").arg(TimeStamp);

        if (comment.length()) {

            // Set image comment
            tmp << endl << "#" + QString("%1").arg(comment);

            // Save milestone
            QFile fmiles(RunPath + filesep + "Milestones.txt");
            if (fmiles.open(QIODevice::WriteOnly | QIODevice::Append)) {
                QTextStream stream(&fmiles);
                stream << nFrame << "\t" << TimeStamp << "\t" << comment << endl;
            }

            // Update current state
            currentState = comment;

            // Reset comment
            comment = QString();
        }

    }

    // --- Update

    // Status bar
    ui->statusBar->showMessage(QString("Run %1.%2 - Frame %3 - %4").arg(guiid).arg(nRun, 2, 10, QLatin1Char('0')).arg(nFrame, 6, 10, QLatin1Char('0')).arg(currentState));

    // Frame number
    nFrame++;

}

void Dual::snapshot() {

    // Create snapshot directory?
    QString SnapPath(ui->DataPath->text() + "Snapshots" + filesep);
    if (!QDir(ui->DataPath->text()).exists()) { QDir().mkdir(ui->DataPath->text()); }
    if (!QDir(SnapPath).exists()) { QDir().mkdir(SnapPath); }

    // Get last image number
    int nSnap = 0;
    QDir SnapDir(SnapPath);
    QStringList flist = SnapDir.entryList(QDir::NoDotAndDotDot | QDir::Files);
    foreach(QString file, flist) {
        QStringList tmp = file.split("_", QString::SkipEmptyParts);
        tmp = tmp.at(1).split(".");
        if (tmp.at(0).toInt()>nSnap) { nSnap = tmp.at(0).toInt(); }
    }
    nSnap++;
    qDebug() << nSnap;

    // Save snapshot
    ImgWriter->setFileName(QString(SnapPath + "Image_%1.pgm").arg(nSnap, 6, 10, QLatin1Char('0')));
    ImgWriter->write(pixmap.toImage());

    // Update status message
    ui->statusBar->showMessage(QString("Last image: %1").arg(nSnap, 6, 10, QLatin1Char('0')));

}


// === PROTOCOLS ===========================================================

void Dual::BrowseProtocol() {

    QString pfile = QFileDialog::getOpenFileName(this, tr("Open protocol file"), QDir::currentPath(), "Protocol files (*.protocol);; All files (*.*)");
    if (pfile.length()) { ui->ProtocolPath->setText(pfile); }

}

void Dual::toggleProtocol(bool b) {

    if (ui->ProtocolRun->isChecked()) {

        // --- Load protocol
        QFile *PFile = new QFile(ui->ProtocolPath->text());

        if (!PFile->open(QIODevice::ReadOnly | QIODevice::Text)) {
            qWarning() << "Unable to load \"" << PFile->fileName() << "\"";
            return;
        };

        QTextStream stream(PFile);
        Protocol.clear();
        QString line;
        while (stream.readLineInto(&line)) {

            // --- Remove empty lines and comments
            if (line.isEmpty() || line.left(1) == "#") { continue; }

            Protocol.append(line);
        }

        // --- Start protocol
        ui->ProtocolTime->setStyleSheet("QLabel { color: firebrick;}");
        ProtocolTime.start();
        timerProtocol->start(1000);
        ProtoLoop();

        // Disable Circuit Combo Boxes
        ui->CircuitLeft->setDisabled(true);
        ui->CircuitRight->setDisabled(true);

    } else {

        // Clear Protocol
        ui->ProtocolTime->setText("00:00:00");
        ui->ProtocolTime->setStyleSheet("QLabel { color: black;}");
        Protocol.clear();
        timerProtocol->stop();

        // Stop motor
        ui->MotorRun->setChecked(false);

        // Stop camera
        timerGrab->stop();

        // Enable circuit Combo Boxes
        ui->CircuitLeft->setDisabled(false);
        ui->CircuitRight->setDisabled(false);

    }

}

void Dual::ProtocolLoop() {
    // Synchronous loop (every 1s) for display

    // Ellapsed time
    int m = ProtocolTime.elapsed();
    int hours = floor(m/3600000); m -= hours*3600000;
    int minutes = floor(m/60000); m -= minutes*60000;
    int seconds = floor(m/1000);

    ui->ProtocolTime->setText(QString("%1").arg(hours, 2, 10, QChar('0')) + ":" +
                              QString("%1").arg(minutes, 2, 10, QChar('0')) + ":" +
                              QString("%1").arg(seconds, 2, 10, QChar('0')));

}

// -------------------------------------------------------------------------
void Dual::ProtoLoop() {
// Asynchronous loop for processing protocol commands

    // --- End of protocol
    if (!Protocol.count()) {
        ui->ProtocolRun->setChecked(false);
        return;
    }

    // Loop by default
    bool brem = true;
    bool bcont = true;

    // --- Parse first command
    QStringList list = Protocol[0].split(":");

    if (list.at(0)=="print") {

        // --- PRINT ----------------------------

        OUT << qPrintable(list.at(1));

    } else if (list.at(0)=="data") {

        // --- DATA ---------------------------

        if (list.at(1)=="create directory") {

            // Reset run number
            nRun++;

            // Create run directory
            if (!QDir(ui->DataPath->text()).exists()) { QDir().mkdir(ui->DataPath->text()); }
            RunPath = QString(ui->DataPath->text() + "Run %1.%2" + filesep).arg(guiid).arg(nRun, 2, 10, QLatin1Char('0'));
            if (!QDir(RunPath).exists()) { QDir().mkdir(RunPath); }

            // Save protocol file
            QFile::copy(ui->ProtocolPath->text(), RunPath + filesep + "Protocol.txt");

            // Save parameters
            QFile fparam(RunPath + filesep + "Parameters.txt");
            if (fparam.open(QIODevice::ReadWrite)) {
                QTextStream stream(&fparam);
                stream << "Spawning_date\t" << ui->spawningDate->date().toString("yyyy-MM-dd") << endl;
                stream << "Age\t" << ui->Age->text() << endl;
                stream << "Stimulus\t" << ui->Stimulus->text() << endl;
                stream << "Concentration\t" << ui->Concentration->text() << endl;
            }

        }


    } else if (list.at(0)=="blink") {

        // --- BLINK ----------------------------

        send(QString("blink:%1").arg(list.at(1).toUpper()));


    } else if (list.at(0)=="light") {

        // --- LIGHT ----------------------------

        if (list.at(1)=="VIS") {
            send(QString("light:VIS:%1").arg(list.at(2).toUpper()));
        }

        if (list.at(1)=="IR") {
            send(QString("light:IR:%1").arg(list.at(2).toUpper()));
        }

    } else if (list.at(0)=="camera") {

        // --- CAMERA ---------------------------

        if (list.at(1)=="start") {

            nFrame = 0;
            timerGrab->start(1000/SaveRate);

        } else if (list.at(1)=="stop") {

            timerGrab->stop();

        } else if (list.at(1)=="comment") {

            comment = list.at(2);

        }

    } else if (list.at(0)=="wait") {

        // --- WAIT -----------------------------

        QTimer::singleShot(list.at(1).toInt(), this, SLOT(ProtoLoop()));
        bcont = false;

    } else if (list.at(0)=="switch") {

        // --- VALVES ---------------------------

        // --- Left
        if (list.at(1)=="L") {
            if (list.at(2)=="Buffer") {
                ui->switchValve1->setChecked(false);
                ui->switchValve2->setChecked(false);
            } else if (list.at(2)=="Stimulus") {
                ui->switchValve1->setChecked(false);
                ui->switchValve2->setChecked(true);
            } else if (list.at(2)=="Circuit") {
                ui->switchValve1->setChecked(true);
                ui->switchValve2->setChecked(false);
            }
        }

        // --- Right
        if (list.at(1)=="R") {
            if (list.at(2)=="Buffer") {
                ui->switchValve3->setChecked(false);
                ui->switchValve4->setChecked(false);
            } else if (list.at(2)=="Stimulus") {
                ui->switchValve3->setChecked(false);
                ui->switchValve4->setChecked(true);
            } else if (list.at(2)=="Circuit") {
                ui->switchValve3->setChecked(true);
                ui->switchValve4->setChecked(false);
            }
        }

        // --- Trash
        if (list.at(1)=="T") {
            if (list.at(2)=="Trash") {
                ui->switchValve5->setChecked(false);
                ui->switchValve6->setChecked(false);
            } else if (list.at(2)=="Circuit") {
                ui->switchValve5->setChecked(true);
                ui->switchValve6->setChecked(true);
            }
        }

    } else if (list.at(0)=="run") {

        // --- RUN ------------------------------

        // Set direction
        if (list.at(1)=="up") { ui->MotorDir->setChecked(true); }
        if (list.at(1)=="down") { ui->MotorDir->setChecked(false); }

        // Set speed
        ui->MotorPeriod->setText(list.at(2));
        emit ui->MotorPeriod->editingFinished();

        if (list.count()>=4 && list.at(3)=="for") {
            QTimer::singleShot(list.at(4).toInt(), this, SLOT(ProtoLoop()));

            // Update commands
            brem = false;
            Protocol.removeFirst();
            Protocol.prepend(QString("stop"));

        }

        // Run !
        ui->MotorRun->setChecked(true);

        // Wait for the run end
        bcont = false;

    } else if (list.at(0)=="stop") {

        ui->MotorRun->setChecked(false);

    } else {

        qDebug() << "Unknown command:" << Protocol[0];
        return;

    }

    // --- Remove first command
    if (brem) { Protocol.removeFirst(); }

    // --- Continue
    if (bcont) { ProtoLoop(); }

}

// === SERIAL COMMUNICATION ================================================

void Dual::send(QString cmd) {
    conn->write(cmd.toStdString().c_str());
    conn->flush();
    QThread::msleep(10);
}

// === SLOTS ===============================================================

void Dual::readSerial() {

    // --- Read response
    QByteArray readData = conn->readAll();
    while (conn->waitForReadyRead(10)) {
        readData.append(conn->readAll());
    }
    QStringList res = QString(readData).split("\r\n", QString::SkipEmptyParts);

    // --- Filter responses
    for (int i=0; i<res.size(); i++) {

        // --- Commands
        QRegularExpressionMatch match = rxcmd->match(res[i]);
        if (match.hasMatch()) {

            if(res[i]=="[STOP]") {
                ui->MotorRun->setChecked(false);
                if (ui->ProtocolRun->isChecked()) { ProtoLoop(); }
            }

            continue;
        }

        // --- Display
        if (res[i] != QString::number(this->guiid)) {
            OUT << res[i].toStdString().c_str();
        }
    }

}

// --- VALVES --------------------------------------------------------------

void Dual::toggleValve(bool b) {

    // Get sender
    QPushButton* B = qobject_cast<QPushButton*>(sender());

    // Get valve number
    int nV = B->objectName().right(1).toInt();

    // Set valve status
    setValve(nV, b);

}

void Dual::setValve(int nV, bool b) {

    // Get valve pin
    int pV;
    switch (nV) {
    case 1: pV = ui->pinValve1->value(); break;
    case 2: pV = ui->pinValve2->value(); break;
    case 3: pV = ui->pinValve3->value(); break;
    case 4: pV = ui->pinValve4->value(); break;
    case 5: pV = ui->pinValve5->value(); break;
    case 6: pV = ui->pinValve6->value(); break;
    }

    // Send command
    send(QString("setVal:%1:").arg(pV) + (b?"ON":"OFF"));

}

void Dual::setCircuitLeft(int i) {

    switch (i) {

    case 0:     // Injection
        ui->switchValve1->setDown(true);
        ui->switchValve1->toggled(true);
        ui->switchValve2->setDown(false);
        ui->switchValve2->toggled(false);
        ui->switchValve5->setDown(true);
        ui->switchValve5->toggled(true);
        if (ui->CircuitRight->currentIndex()>0) { ui->CircuitRight->setCurrentIndex(0); }
        break;

    case 1:     // Buffer
        ui->switchValve1->setDown(false);
        ui->switchValve1->toggled(false);
        ui->switchValve2->setDown(false);
        ui->switchValve2->toggled(false);
        ui->switchValve5->setDown(false);
        ui->switchValve5->toggled(false);
        if (ui->CircuitRight->currentIndex()==0) { ui->CircuitRight->setCurrentIndex(1); }
        break;

    case 2:     // Stimulus
        ui->switchValve1->setDown(false);
        ui->switchValve1->toggled(false);
        ui->switchValve2->setDown(true);
        ui->switchValve2->toggled(true);
        ui->switchValve5->setDown(false);
        ui->switchValve5->toggled(false);
        if (ui->CircuitRight->currentIndex()==0) { ui->CircuitRight->setCurrentIndex(1); }
        break;

    }
}

void Dual::setCircuitRight(int i) {

    switch (i) {

    case 0:     // Injection
        ui->switchValve3->setDown(true);
        ui->switchValve3->toggled(true);
        ui->switchValve4->setDown(false);
        ui->switchValve4->toggled(false);
        ui->switchValve6->setDown(true);
        ui->switchValve6->toggled(true);
        if (ui->CircuitLeft->currentIndex()>0) { ui->CircuitLeft->setCurrentIndex(0); }
        break;

    case 1:     // Buffer
        ui->switchValve3->setDown(false);
        ui->switchValve3->toggled(false);
        ui->switchValve4->setDown(false);
        ui->switchValve4->toggled(false);
        ui->switchValve6->setDown(false);
        ui->switchValve6->toggled(false);
        if (ui->CircuitLeft->currentIndex()==0) { ui->CircuitLeft->setCurrentIndex(1); }
        break;

    case 2:     // Stimulus
        ui->switchValve3->setDown(false);
        ui->switchValve3->toggled(false);
        ui->switchValve4->setDown(true);
        ui->switchValve4->toggled(true);
        ui->switchValve6->setDown(false);
        ui->switchValve6->toggled(false);
        if (ui->CircuitLeft->currentIndex()==0) { ui->CircuitLeft->setCurrentIndex(1); }
        setValve(6, false);
        break;

    }
}

// --- LEDs ----------------------------------------------------------------

void Dual::toggleIRLED(bool b) {

    // Send command
    send(QString("light:IR:") + (b?"ON":"OFF"));

}

void Dual::toggleVisLED(bool b) {

    // Send command
    send(QString("light:VIS:") + (b?"ON":"OFF"));

}

// --- MOTOR ---------------------------------------------------------------

void Dual::toggleEnable(bool b) {

    send(QString("setVal:%1:").arg(ui->pinEnable->value()) + (b?"OFF":"ON"));

}

void Dual::toggleDir(bool b) {

    send(QString("setVal:%1:").arg(ui->pinDir->value()) + (b?"ON":"OFF"));

}

void Dual::setPeriod() {

    send(QString("stepPeriod:%1").arg(ui->MotorPeriod->text()));

}

void Dual::toggleRun(bool b) {

    if (b) { send(QString("run")); }
    else { send(QString("stop")); }

}

// --- STATE ---------------------------------------------------------------

void Dual::setState(QString S) {

    send(QString("state:%1").arg(S));
    OUT << "State is " << S;

    if (S=="Active") {
        QThread::msleep(50);
        send(QString("setVal:%1:%2").arg(ui->pinDir->value()).arg(ui->MotorDir->isChecked()?"ON":"OFF"));
    }

}

// === Window closing ======================================================

void Dual::closeEvent(QCloseEvent *event) {
    setState(QString("Idle"));
    emit closed(guiid);
    event->accept();
}

Dual::~Dual() {
    delete ui;
}
