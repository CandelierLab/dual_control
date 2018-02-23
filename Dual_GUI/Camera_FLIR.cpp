#include "Camera_FLIR.h"

using namespace std;

/* ====================================================================== *\
|    Constructor & destructor                                              |
\* ====================================================================== */

Camera_FLIR::Camera_FLIR(CameraPtr cPtr, int identifier):
    pCam(cPtr), id(identifier) {

    // --- Initialization
    grabState = false;

    // --- Get camera identifier
    INodeMap &nodeMap = pCam->GetTLDeviceNodeMap();
    CCategoryPtr category = nodeMap.GetNode("DeviceInformation");
    if (IsAvailable(category) && IsReadable(category)) {
        FeatureList_t features;
        category->GetFeatures(features);

        QRegExp rx(" (\\w+)\-");
        QString model("");
        if (rx.indexIn(QString(features.at(3)->ToString())) != -1) { model += rx.cap(1) + " "; }
        name = model + features.at(1)->ToString();
    }

}

Camera_FLIR::~Camera_FLIR() {

    pCam->DeInit();
    Q_EMIT closed();

}

/* ====================================================================== *\
|    Camera settings                                                       |
\* ====================================================================== */


/* ====================================================================== *\
|    Camera information output                                             |
\* ====================================================================== */

void Camera_FLIR::display_info() {

    // --- Device info

    INodeMap &nodeMap = pCam->GetTLDeviceNodeMap();
    CCategoryPtr category = nodeMap.GetNode("DeviceInformation");

    if (IsAvailable(category) && IsReadable(category)) {

        FeatureList_t features;
        category->GetFeatures(features);

        qInfo().nospace() << "<table class='cameraInfo'>"
                << "<tr>"
                << "<th rowspan=3>Camera " << id << "</th>"
                << "<td>" << features.at(1)->GetName() << "</td>"       // DeviceSerialNumber
                << "<td>" << features.at(1)->ToString() << "</td>"
                << "</tr><tr>"
                << "<td>" << features.at(3)->GetName() << "</td>"       // DeviceModelName
                << "<td>" << features.at(3)->ToString() << "</td>"
                << "</tr><tr>"
                << "<td>" << features.at(12)->GetName() << "</td>"      // DeviceCurrentSpeed
                << "<td>" << features.at(12)->ToString() << "</td>"
                << "</tr>"
                << "</table>";

        /*
        FeatureList_t::const_iterator it;
        for (it = features.begin(); it != features.end(); ++it) {

            CNodePtr pfeatureNode = *it;
            CValuePtr pValue = (CValuePtr)pfeatureNode;
            qInfo() << pfeatureNode->GetName() << ":" << (IsReadable(pValue) ? pValue->ToString() : "Node not readable");

        }
        */

    } else { qWarning() << "Device info not available"; }

}

/* ====================================================================== *\
|    Frame grabber                                                         |
\* ====================================================================== */

void Camera_FLIR::grab() {

    // Thread info
    qInfo().nospace() << THREAD << qPrintable(name) << " lives in thread: " << QThread::currentThreadId();

    // --- Camera & nodemaps definitions -----------------------------------

    pCam->Init();
    //INodeMap &nodeMapTLDevice = pCam->GetTLDeviceNodeMap();
    INodeMap &nodeMap = pCam->GetNodeMap();

    pCam->GainAuto.SetValue(Spinnaker::GainAutoEnums::GainAuto_Off);

    // --- Configure ChunkData ---------------------------------------------

    // --- Activate chunk mode

    CBooleanPtr ptrChunkModeActive = nodeMap.GetNode("ChunkModeActive");

    if (!IsAvailable(ptrChunkModeActive) || !IsWritable(ptrChunkModeActive)) {
        qWarning() << "Unable to activate chunk mode. Aborting.";
        return;
    }

    ptrChunkModeActive->SetValue(true);

    qInfo() << "Chunk mode activated";

    // --- Chunk data types

    NodeList_t entries;

    // Retrieve the selector node
    CEnumerationPtr ptrChunkSelector = nodeMap.GetNode("ChunkSelector");

    if (!IsAvailable(ptrChunkSelector) || !IsReadable(ptrChunkSelector)) {
        qWarning() << "Unable to retrieve chunk selector. Aborting.";
        return;
    }

    // Retrieve entries
    ptrChunkSelector->GetEntries(entries);

    for (int i = 0; i < entries.size(); i++) {

        // Select entry to be enabled
        CEnumEntryPtr ptrChunkSelectorEntry = entries.at(i);

        // Go to next node if problem occurs
        if (!IsAvailable(ptrChunkSelectorEntry) || !IsReadable(ptrChunkSelectorEntry)) { continue; }

        ptrChunkSelector->SetIntValue(ptrChunkSelectorEntry->GetValue());

        // Retrieve corresponding boolean
        CBooleanPtr ptrChunkEnable = nodeMap.GetNode("ChunkEnable");

        // Enable the boolean, thus enabling the corresponding chunk data
        if (IsWritable(ptrChunkEnable)) {
            ptrChunkEnable->SetValue(true);
        }

    }

    // --- Acquisition parameters ------------------------------------------

    // === Continuous mode ======================

    CEnumerationPtr ptrAcquisitionMode = nodeMap.GetNode("AcquisitionMode");
    if (!IsAvailable(ptrAcquisitionMode) || !IsWritable(ptrAcquisitionMode)) {
        qWarning() << "Unable to set acquisition mode to continuous (enum retrieval)";
        return;
    }

    // Retrieve entry node from enumeration node
    CEnumEntryPtr ptrAcquisitionModeContinuous = ptrAcquisitionMode->GetEntryByName("Continuous");
    if (!IsAvailable(ptrAcquisitionModeContinuous) || !IsReadable(ptrAcquisitionModeContinuous)) {
        qWarning() << "Unable to set acquisition mode to continuous (entry retrieval)";
        return;
    }

    // Retrieve integer value from entry node
    int64_t acquisitionModeContinuous = ptrAcquisitionModeContinuous->GetValue();

    // Set integer value from entry node as new value of enumeration node
    ptrAcquisitionMode->SetIntValue(acquisitionModeContinuous);

    qInfo() << "Acquisition mode set to continuous";

    // === Exposure time ========================

    CEnumerationPtr exposureAuto = nodeMap.GetNode("ExposureAuto");
    exposureAuto->SetIntValue(exposureAuto->GetEntryByName("Off")->GetValue());

    CEnumerationPtr exposureMode = nodeMap.GetNode("ExposureMode");
    exposureMode->SetIntValue(exposureMode->GetEntryByName("Timed")->GetValue());

    CFloatPtr exposureTime = nodeMap.GetNode("ExposureTime");
    exposureTime->SetValue(6500);

    qInfo() << "Exposure time set to 6.5ms";

    // --- Acquire images --------------------------------------------------

    grabState = true;
    qInfo() << "Starting image acquisition";

    pCam->BeginAcquisition();

    while (grabState) {

        ImagePtr pImg = pCam->GetNextImage();

        if (pImg->IsIncomplete()) {

            qWarning() << "Image incomplete with image status " << pImg->GetImageStatus();

        } else {

            SImage SImg;

            // --- Get image and convert to QImage
            unsigned char* Raw = (unsigned char*)pImg->GetData();
            SImg.Img = QImage(Raw, pImg->GetWidth(), pImg->GetHeight(), QImage::Format_Indexed8);
            for (unsigned int i=0 ; i<=255; i++) { SImg.Img.setColor(i, qRgb(i,i,i)); }

            // --- Get ChunkData
            ChunkData chunkData = pImg->GetChunkData();
            SImg.CameraName = name;
            SImg.timestamp = (qint64) chunkData.GetTimestamp();
            SImg.frameId = (qint64) chunkData.GetFrameID();
            SImg.gain = (qint64) chunkData.GetGain();

            // --- Send new image
            emit newImage(SImg);

        }

        pImg->Release();

    }

    pCam->EndAcquisition();
    pCam->DeInit();

    emit finished();
}
