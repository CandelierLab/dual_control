#include <QApplication>

#include "MsgHandler.h"
#include "mainwindow.h"

int main(int argc, char *argv[]) {
  // Message handler
  qInstallMessageHandler(MsgHandler);

  QApplication a(argc, argv);

  MainWindow w;
  w.show();

  return a.exec();
}
