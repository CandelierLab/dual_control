#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDebug>
#include <QDesktopWidget>
#include <QDir>
#include <QFile>
#include <QFontDatabase>
#include <QHashIterator>
#include <QMainWindow>
#include <QScrollBar>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QShortcut>
#include <QThread>
#include <QTimer>
#include <QVector>

#include "Cameras.h"
#include "Dual.h"
#include "MsgHandler.h"

// === Custom structures ===================================================

struct StSer
{
  QString port;
  QSerialPort *conn;
};

// === Mainwindow class ====================================================

namespace Ui {
class MainWindow;
}

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

  void setIdle();
  void setXmas();
  void setK2000();

 private:
  QString filesep, progPath, projPath;
  int NDual;

  // --- Windows management -------------------

  Ui::MainWindow *ui;
  QVector<QRect> Screen;

  QShortcut *s_Close;
  QShortcut *s_Settings;
  QShortcut *s_Idle;
  QShortcut *s_Xmas;
  QShortcut *s_K2000;

  // --- Dual windows -------------------------

  QVector<StSer> Serial;
  QVector<Dual *> Duals;

  // --- Cameras ------------------------------

  Cameras *Cams;
  QHash<int, QString> CamNames;
};

#endif  // MAINWINDOW_H
