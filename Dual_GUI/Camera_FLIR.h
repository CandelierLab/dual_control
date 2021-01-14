#ifndef CAMERA_FLIR_H
#define CAMERA_FLIR_H

#include <QDebug>
#include <QElapsedTimer>
#include <QImage>
#include <QObject>
#include <QThread>
#include <QTime>

#include "SpinGenApi/SpinnakerGenApi.h"
#include "Spinnaker.h"

#include "MsgHandler.h"
#include "STypes.h"

using namespace Spinnaker;
using namespace Spinnaker::GenApi;
using namespace Spinnaker::GenICam;
using namespace std;

/* =================================================================== *\
 |    Camera_FLIR Class                                                  |
 \* =================================================================== */

class Camera_FLIR : public QObject {
  Q_OBJECT

 public:
  // Constructor and destructor
  Camera_FLIR(CameraPtr, int);
  ~Camera_FLIR();

  int id;
  QString name;

  bool grabState;

 public slots:

  void display_info();
  void grab();

 signals:

  void newImage(SImage);
  void finished();
  void closed();

 private:
  // --- Internal FLIR pointer
  CameraPtr pCam;
};

#endif
