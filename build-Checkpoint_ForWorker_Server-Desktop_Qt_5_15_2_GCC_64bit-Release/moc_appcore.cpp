/****************************************************************************
** Meta object code from reading C++ file 'appcore.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../Checkpoint_For_Worker_Server/appcore.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'appcore.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_AppCore_t {
    QByteArrayData data[14];
    char stringdata0[190];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AppCore_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AppCore_t qt_meta_stringdata_AppCore = {
    {
QT_MOC_LITERAL(0, 0, 7), // "AppCore"
QT_MOC_LITERAL(1, 8, 16), // "startServerError"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 7), // "message"
QT_MOC_LITERAL(4, 34, 21), // "startServerSuccessful"
QT_MOC_LITERAL(5, 56, 12), // "inputMessage"
QT_MOC_LITERAL(6, 69, 10), // "serverStop"
QT_MOC_LITERAL(7, 80, 18), // "clientDisconnected"
QT_MOC_LITERAL(8, 99, 15), // "clientConnected"
QT_MOC_LITERAL(9, 115, 9), // "slotStart"
QT_MOC_LITERAL(10, 125, 8), // "slotStop"
QT_MOC_LITERAL(11, 134, 22), // "slotClientDisconnected"
QT_MOC_LITERAL(12, 157, 14), // "slotReadClient"
QT_MOC_LITERAL(13, 172, 17) // "slotNewConnection"

    },
    "AppCore\0startServerError\0\0message\0"
    "startServerSuccessful\0inputMessage\0"
    "serverStop\0clientDisconnected\0"
    "clientConnected\0slotStart\0slotStop\0"
    "slotClientDisconnected\0slotReadClient\0"
    "slotNewConnection"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AppCore[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   69,    2, 0x06 /* Public */,
       4,    0,   72,    2, 0x06 /* Public */,
       5,    1,   73,    2, 0x06 /* Public */,
       6,    0,   76,    2, 0x06 /* Public */,
       7,    0,   77,    2, 0x06 /* Public */,
       8,    0,   78,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    0,   79,    2, 0x0a /* Public */,
      10,    0,   80,    2, 0x0a /* Public */,
      11,    0,   81,    2, 0x0a /* Public */,
      12,    0,   82,    2, 0x0a /* Public */,
      13,    0,   83,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void AppCore::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<AppCore *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->startServerError((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->startServerSuccessful(); break;
        case 2: _t->inputMessage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->serverStop(); break;
        case 4: _t->clientDisconnected(); break;
        case 5: _t->clientConnected(); break;
        case 6: _t->slotStart(); break;
        case 7: _t->slotStop(); break;
        case 8: _t->slotClientDisconnected(); break;
        case 9: _t->slotReadClient(); break;
        case 10: _t->slotNewConnection(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (AppCore::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AppCore::startServerError)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (AppCore::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AppCore::startServerSuccessful)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (AppCore::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AppCore::inputMessage)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (AppCore::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AppCore::serverStop)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (AppCore::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AppCore::clientDisconnected)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (AppCore::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AppCore::clientConnected)) {
                *result = 5;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject AppCore::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_AppCore.data,
    qt_meta_data_AppCore,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *AppCore::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AppCore::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AppCore.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int AppCore::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void AppCore::startServerError(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void AppCore::startServerSuccessful()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void AppCore::inputMessage(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void AppCore::serverStop()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void AppCore::clientDisconnected()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void AppCore::clientConnected()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
