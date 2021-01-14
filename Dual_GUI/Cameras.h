#ifndef CAMERAS_H
#define CAMERAS_H

#include <QDebug>
#include <QImage>
#include <QObject>
#include <QThread>
#include <QVector>

#include "Camera_FLIR.h"
#include "MsgHandler.h"
#include "STypes.h"

using namespace std;

/* =================================================================== *\
|    Cameras Class                                                      |
\* =================================================================== */

class Cameras : public QObject {
  Q_OBJECT

 public:
  // Constructor & destructor
  Cameras();
  ~Cameras();

  QVector<SCamera> List;
  QVector<Camera_FLIR*> List_FLIR;

 public slots:

  void RefreshAvailableCameras();
  void displayCamerasInfos();

 signals:

 private:
  // --- FLIR Cameras

  // Internal properties
  SystemPtr FLIR_system;
  CameraList FLIR_camList;

  // Check method
  void checkAvailableFLIR();
};

#endif
