/****************************************************************************
** Meta object code from reading C++ file 'Camera_FLIR.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "Camera_FLIR.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Camera_FLIR.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Camera_FLIR_t {
    QByteArrayData data[8];
    char stringdata0[63];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Camera_FLIR_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Camera_FLIR_t qt_meta_stringdata_Camera_FLIR = {
    {
QT_MOC_LITERAL(0, 0, 11), // "Camera_FLIR"
QT_MOC_LITERAL(1, 12, 8), // "newImage"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 6), // "SImage"
QT_MOC_LITERAL(4, 29, 8), // "finished"
QT_MOC_LITERAL(5, 38, 6), // "closed"
QT_MOC_LITERAL(6, 45, 12), // "display_info"
QT_MOC_LITERAL(7, 58, 4) // "grab"

    },
    "Camera_FLIR\0newImage\0\0SImage\0finished\0"
    "closed\0display_info\0grab"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Camera_FLIR[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,
       4,    0,   42,    2, 0x06 /* Public */,
       5,    0,   43,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   44,    2, 0x0a /* Public */,
       7,    0,   45,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Camera_FLIR::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Camera_FLIR *_t = static_cast<Camera_FLIR *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->newImage((*reinterpret_cast< SImage(*)>(_a[1]))); break;
        case 1: _t->finished(); break;
        case 2: _t->closed(); break;
        case 3: _t->display_info(); break;
        case 4: _t->grab(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< SImage >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Camera_FLIR::*_t)(SImage );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Camera_FLIR::newImage)) {
                *result = 0;
            }
        }
        {
            typedef void (Camera_FLIR::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Camera_FLIR::finished)) {
                *result = 1;
            }
        }
        {
            typedef void (Camera_FLIR::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Camera_FLIR::closed)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject Camera_FLIR::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Camera_FLIR.data,
      qt_meta_data_Camera_FLIR,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Camera_FLIR::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Camera_FLIR::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Camera_FLIR.stringdata0))
        return static_cast<void*>(const_cast< Camera_FLIR*>(this));
    return QObject::qt_metacast(_clname);
}

int Camera_FLIR::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void Camera_FLIR::newImage(SImage _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Camera_FLIR::finished()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void Camera_FLIR::closed()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
