#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
  // === DEFINITIONS =====================================================

  // --- Pathes
  filesep = QString(QDir::separator());
  progPath = QDir::currentPath() + filesep;
  projPath = QDir::currentPath();
  projPath = projPath.mid(0, projPath.toStdString().find_last_of(filesep.toStdString()));
  projPath = projPath.mid(0, projPath.toStdString().find_last_of(filesep.toStdString())) + filesep;

  // Number of Dual setups
  NDual = 1;

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
  QFile File(":/output.css");
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
    case 0:
      qInfo() << "No screen detected";
      break;
    case 1:
      qInfo() << "1 screen detected";
      break;
    default:
      qInfo() << Desktop.screenCount() << "screens detected";
      break;
  }

  for (int i = 0; i < Desktop.screenCount(); i++) {
    Screen.push_back(Desktop.availableGeometry(i));
    qInfo().nospace() << " [" << i << "] " << Desktop.availableGeometry(i);
  }

  // --- Geometry -----------------------------

  this->move(Screen[0].x(), Screen[0].y());

  // === Duals ===========================================================

  Duals.append(new Dual(Screen, projPath, 1));

  // === Settings ========================================================

  loadSettings();

  // === Serial connections ==============================================

  StSer tmp;
  tmp.port = "";
  Serial.append(tmp);

  // === Cameras =========================================================

  isCamera = true;
  // Cams = new Cameras;

  // === Connections =====================================================

  // Custom types registation
  qRegisterMetaType<SImage>();

  connect(ui->CheckSerial, SIGNAL(released()), this, SLOT(checkSerial()));

  connect(ui->Dual_1, SIGNAL(toggled(bool)), this, SLOT(toggleWindow(bool)));

  // === Startup =========================================================

  isSerial = false;
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
        S = "<" + MSG.css + ">" + MSG.text + "</p>";
        break;
      case QtWarningMsg:
        S = "<p class='warning'>" + MSG.text + "</p>";
        break;
      case QtCriticalMsg:
        S = "<p class='critical'>" + MSG.text + "</p>";
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
  QFile *SFile = new QFile(":/Settings.conf");

  if (!SFile->open(QIODevice::ReadOnly | QIODevice::Text)) {
    QFileInfo qfi(SFile->fileName());
    if (qfi.fileName() != "settings.conf") {
      qWarning() << "Unable to read \"" << SFile->fileName() << "\"";
    }
    else {
      qWarning() << "Unable to find \"" << SFile->fileName() << "\"";
    }
    return;
  };

  QTextStream stream(SFile);
  QString line;
  while (stream.readLineInto(&line)) {
    // --- Remove empty lines and comments
    if (line.isEmpty() || line.left(1) == "#") {
      continue;
    }

    // --- Parse command
    QStringList list = line.split(":");

    if (list.at(0) == "print") {
      // --- PRINT ------------------------

      qInfo() << qPrintable(list.at(1));
    }
    else if (list.at(0) == "ROI") {
      // --- REGION OF INTEREST ---------
      QStringList tmp = list.at(2).split(",");
      Duals[list.at(1).toInt() - 1]->ROI = QRect(tmp.at(0).toInt(), tmp.at(1).toInt(), tmp.at(2).toInt(), tmp.at(3).toInt());
    }
  }
}

/* ====================================================================== *\
|    CAMERAS                                                               |
\* ====================================================================== */

bool MainWindow::refreshCameras() {
  // --- Clean all
  // -- TO DO --

  // --- Refresh cameras
  // Cams->RefreshAvailableCameras();
  // Cams->displayCamerasInfos();

  // if (!Cams->List_FLIR.empty() && !isCamera) {
  //   connect(Cams->List_FLIR[0], SIGNAL(newImage(SImage)), Duals[0], SLOT(newImage(SImage)));
  //   return true;
  // }
  return false;
}

/* ====================================================================== *\
|    SERIAL CONNECTION                                                     |
\* ====================================================================== */

void MainWindow::checkSerial() {
  if (!isCamera) {
    isCamera = refreshCameras();
  }
  qInfo() << TITLE_2 << "Serial connections";

  // --- Get available ports

  const QList<QSerialPortInfo> infos = QSerialPortInfo::availablePorts();
  qInfo() << infos.length() << "serial connections detected";

  // --- Remove unused ports

  // !!! TO DO !!!

  // --- Assign new ports

  for (int i = 0; i < infos.length(); i++) {
    // --- Checks

    // Skip non-Arduino connections
    if (infos[i].description().left(7).toLower() != "arduino") {
      qInfo().nospace() << "[" << infos[i].portName() << "] is not a Dual ...";
      continue;
    }

    // Skip connections already attributed
    bool att = false;
    for (int j = 0; j < Serial.length(); j++) {
      if (Serial[j].port == infos[i].portName()) {
        att = true;
        break;
      }
    }
    if (att) {
      continue;
    }

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
      for (int i = 0; i < 10; i++) {
        conn->write("getId");
        conn->flush();
        QThread::msleep(100);
      }
    }
    else {
      qWarning() << "Failed to open port" << conn->portName();
    }
  }
}

bool MainWindow::getSerialId() {
  // Get sender connection
  QSerialPort *conn = qobject_cast<QSerialPort *>(sender());

  // Read response
  QByteArray readData = conn->readAll();
  while (conn->waitForReadyRead(0)) {
    readData.append(conn->readAll());
  }

  // Convert it to identifier
  QString res(readData);
  if (res.contains("dual")) {
    // Assign to the list of serial objects
    Serial[0].conn = conn;
    Serial[0].port = conn->portName();

    // Transfert serial port name to Dual
    Duals[0]->portName = conn->portName();
    conn->close();
    delete (conn);
    isSerial = true;
    if (isSerial && isCamera) {
      ui->Dual_1->setEnabled(true);
      ui->Dual_1->setChecked(true);
      toggleWindow(true);
    }
    return true;
  }
  else {
    qWarning() << "No Dual device connections detected";
    return false;
  }
}

// === Sates ===============================================================

void MainWindow::setIdle() {
  for (int i = 0; i < NDual; i++) {
    if (Duals[i]->initialized) {
      Duals[i]->setState(QString("Idle"));
    }
  }
}

void MainWindow::setXmas() {
  for (int i = 0; i < NDual; i++) {
    if (Duals[i]->initialized) {
      Duals[i]->setState(QString("Xmas"));
    }
  }
}

void MainWindow::setK2000() {
  for (int i = 0; i < NDual; i++) {
    if (Duals[i]->initialized) {
      Duals[i]->setState(QString("K2000"));
    }
  }
}

// === Window management ===================================================

void MainWindow::toggleWindow(bool b) {
  if (b) {
    Duals[0]->initialize();
    Duals[0]->show();
    Duals[0]->setState(QString("Active"));
  }
  else {
    Duals[0]->hide();
    Duals[0]->setState(QString("Idle"));
  }
}

void MainWindow::uncheckDual(int guiid) {
  ui->Dual_1->setChecked(false);
}

MainWindow::~MainWindow() {
  delete ui;
}
