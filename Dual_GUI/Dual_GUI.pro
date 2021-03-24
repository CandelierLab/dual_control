#-------------------------------------------------
#
# Project created by QtCreator 2017-01-26T10:44:55
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets serialport

  CONFIG += c++11
  DESTDIR=build
  OBJECTS_DIR=build
  MOC_DIR=build
  UI_DIR=build
  RCC_DIR=build

  QMAKE_CXXFLAGS += -O3 -g -Wconversion
  QMAKE_LFLAGS += -no-pie
  QMAKE_CXXFLAGS_RELEASE -= -O1
  QMAKE_CXXFLAGS_RELEASE -= -O2
  QMAKE_CXXFLAGS_RELEASE += -O3
  QMAKE_LFLAGS_RELEASE -= -O1
  QMAKE_LFLAGS_RELEASE -= -O2
  QMAKE_LFLAGS_RELEASE += -O3


TARGET = Dual_GUI
TEMPLATE = app

SOURCES += main.cpp\
    MsgHandler.cpp \
    mainwindow.cpp \
    Dual.cpp \
    Camera_FLIR.cpp \
    Cameras.cpp

HEADERS  += MsgHandler.h \
    mainwindow.h \
    Dual.h \
    Camera_FLIR.h \
    Cameras.h \
    STypes.h

FORMS    += \
    mainwindow.ui \
    Dual.ui

RESOURCES += \
    Dual.qrc

# === Platform-specific libraries ==========================================

# --- LINUX
unix:!macx: LIBS += -L/opt/spinnaker/lib -lSpinnaker
unix:!macx: INCLUDEPATH += /opt/spinnaker/include
unix:!macx: DEPENDPATH += /opt/pinnaker/lib
