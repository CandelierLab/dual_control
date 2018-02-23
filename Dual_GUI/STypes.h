#ifndef STYPES_H
#define STYPES_H

#include <QThread>
#include <QString>
#include <QImage>

struct SImage {
    QString CameraName;
    qint64 frameId;
    qint64 timestamp;
    qint64 gain;
    QImage Img;
};

struct SCamera {
    QString type;
    QString name;
    int index;
    QThread *thread;
};

Q_DECLARE_METATYPE(SCamera)
Q_DECLARE_METATYPE(SImage)

#endif
