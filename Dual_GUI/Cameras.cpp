#include "Cameras.h"

/* ====================================================================== *\
|    Constructor                                                           |
\* ====================================================================== */

Cameras::Cameras() {}

Cameras::~Cameras() {
  // Clean FLIR internal pointers
  FLIR_camList.Clear();
  FLIR_system->ReleaseInstance();
}

/* ====================================================================== *\
|    Availability checks                                                   |
\* ====================================================================== */

void Cameras::RefreshAvailableCameras() {
  // Clear current cameras
  List.clear();
  List_FLIR.clear();

  // Successive checks
  checkAvailableFLIR();

  // Summary
  switch (List.count()) {
    case 0:
      qInfo() << "No camera detected";
      break;
    case 1:
      qInfo() << "1 camera detected";
      break;
    default:
      qInfo().nospace() << List.count() << " cameras detected";
      break;
  }
}

void Cameras::checkAvailableFLIR() {
  qInfo() << TITLE_2 << "Cameras";

  FLIR_system = System::GetInstance();
  FLIR_camList = FLIR_system->GetCameras();
  unsigned int FLIR_nCam = FLIR_camList.GetSize();

  // --- Create camera objects

  for (int i = 0; i < FLIR_nCam; i++) {
    // Create camera object and thread
    Camera_FLIR *Cam = new Camera_FLIR(FLIR_camList.GetByIndex(i), List.count());
    QThread *t_Cam = new QThread;
    Cam->moveToThread(t_Cam);

    // Connections
    connect(t_Cam, SIGNAL(started()), Cam, SLOT(grab()));
    connect(Cam, SIGNAL(finished()), t_Cam, SLOT(quit()));
    connect(Cam, SIGNAL(closed()), t_Cam, SLOT(quit()));
    connect(Cam, SIGNAL(closed()), t_Cam, SLOT(deleteLater()));

    // Start the camera
    t_Cam->start();

    // Update List_FLIR
    List_FLIR.push_back(Cam);

    // Update List
    SCamera SCam;
    SCam.type = QString("FLIR");
    SCam.index = i;
    SCam.name = List_FLIR.last()->name;
    SCam.thread = t_Cam;
    List.push_back(SCam);
  }
}

/* ====================================================================== *\
|    Display                                                               |
\* ====================================================================== */

void Cameras::displayCamerasInfos() {
  for (int i = 0; i < List.count(); i++) {
    if (List[i].type == "FLIR") {
      List_FLIR[List[i].index]->display_info();
    }
  }
}
