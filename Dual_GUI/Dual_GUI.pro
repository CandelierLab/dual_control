#-------------------------------------------------
#
# Project created by QtCreator 2017-01-26T10:44:55
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets serialport

CONFIG += c++11

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

DISTFILES += \
    output.css \
    Settings.conf

# === Platform-specific libraries ==========================================

# --- LINUX
unix:!macx: LIBS += -L/usr/local/Spinnaker/lib -lSpinnaker
unix:!macx: LIBS += -Wl,-rpath-link=/usr/local/Spinnaker/lib
unix:!macx: INCLUDEPATH += /usr/local/Spinnaker/include
unix:!macx: DEPENDPATH += /usr/local/Spinnaker/lib
