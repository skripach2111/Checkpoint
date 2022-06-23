/****************************************************************************
** Meta object code from reading C++ file 'connectioncontroller.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../Checkpoint_Worker_Auth/connectioncontroller.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'connectioncontroller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ConnectionController_t {
    QByteArrayData data[38];
    char stringdata0[440];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ConnectionController_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ConnectionController_t qt_meta_stringdata_ConnectionController = {
    {
QT_MOC_LITERAL(0, 0, 20), // "ConnectionController"
QT_MOC_LITERAL(1, 21, 12), // "disconnected"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 9), // "connected"
QT_MOC_LITERAL(4, 45, 15), // "errorConnection"
QT_MOC_LITERAL(5, 61, 7), // "message"
QT_MOC_LITERAL(6, 69, 21), // "comingCheckpointModel"
QT_MOC_LITERAL(7, 91, 16), // "comingStateModel"
QT_MOC_LITERAL(8, 108, 26), // "workerAuthoriazationResult"
QT_MOC_LITERAL(9, 135, 3), // "fio"
QT_MOC_LITERAL(10, 139, 8), // "position"
QT_MOC_LITERAL(11, 148, 10), // "lvl_access"
QT_MOC_LITERAL(12, 159, 4), // "date"
QT_MOC_LITERAL(13, 164, 4), // "time"
QT_MOC_LITERAL(14, 169, 5), // "state"
QT_MOC_LITERAL(15, 175, 5), // "color"
QT_MOC_LITERAL(16, 181, 7), // "connect"
QT_MOC_LITERAL(17, 189, 10), // "disconnect"
QT_MOC_LITERAL(18, 200, 4), // "send"
QT_MOC_LITERAL(19, 205, 7), // "COMMAND"
QT_MOC_LITERAL(20, 213, 7), // "command"
QT_MOC_LITERAL(21, 221, 13), // "slotReadyRead"
QT_MOC_LITERAL(22, 235, 16), // "slotDisconnected"
QT_MOC_LITERAL(23, 252, 13), // "slotConnected"
QT_MOC_LITERAL(24, 266, 9), // "slotError"
QT_MOC_LITERAL(25, 276, 28), // "QAbstractSocket::SocketError"
QT_MOC_LITERAL(26, 305, 11), // "getSettings"
QT_MOC_LITERAL(27, 317, 4), // "name"
QT_MOC_LITERAL(28, 322, 11), // "setSettings"
QT_MOC_LITERAL(29, 334, 5), // "value"
QT_MOC_LITERAL(30, 340, 18), // "getCheckpointModel"
QT_MOC_LITERAL(31, 359, 14), // "getStatesModel"
QT_MOC_LITERAL(32, 374, 10), // "authWorker"
QT_MOC_LITERAL(33, 385, 10), // "checkpoint"
QT_MOC_LITERAL(34, 396, 5), // "login"
QT_MOC_LITERAL(35, 402, 8), // "password"
QT_MOC_LITERAL(36, 411, 16), // "CheckpointModel*"
QT_MOC_LITERAL(37, 428, 11) // "StateModel*"

    },
    "ConnectionController\0disconnected\0\0"
    "connected\0errorConnection\0message\0"
    "comingCheckpointModel\0comingStateModel\0"
    "workerAuthoriazationResult\0fio\0position\0"
    "lvl_access\0date\0time\0state\0color\0"
    "connect\0disconnect\0send\0COMMAND\0command\0"
    "slotReadyRead\0slotDisconnected\0"
    "slotConnected\0slotError\0"
    "QAbstractSocket::SocketError\0getSettings\0"
    "name\0setSettings\0value\0getCheckpointModel\0"
    "getStatesModel\0authWorker\0checkpoint\0"
    "login\0password\0CheckpointModel*\0"
    "StateModel*"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ConnectionController[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       4,  152, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  104,    2, 0x06 /* Public */,
       3,    0,  105,    2, 0x06 /* Public */,
       4,    1,  106,    2, 0x06 /* Public */,
       6,    0,  109,    2, 0x06 /* Public */,
       7,    0,  110,    2, 0x06 /* Public */,
       8,    7,  111,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      16,    0,  126,    2, 0x0a /* Public */,
      17,    0,  127,    2, 0x0a /* Public */,
      18,    1,  128,    2, 0x0a /* Public */,
      21,    0,  131,    2, 0x0a /* Public */,
      22,    0,  132,    2, 0x0a /* Public */,
      23,    0,  133,    2, 0x0a /* Public */,
      24,    1,  134,    2, 0x0a /* Public */,
      26,    1,  137,    2, 0x0a /* Public */,
      28,    2,  140,    2, 0x0a /* Public */,

 // methods: name, argc, parameters, tag, flags
      30,    0,  145,    2, 0x02 /* Public */,
      31,    0,  146,    2, 0x02 /* Public */,
      32,    2,  147,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::Bool,    9,   10,   11,   12,   13,   14,   15,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 19,   20,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 25,    2,
    QMetaType::QVariant, QMetaType::QString,   27,
    QMetaType::Void, QMetaType::QString, QMetaType::QVariant,   27,   29,

 // methods: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,   33,   14,

 // properties: name, type, flags
      34, QMetaType::QString, 0x00095103,
      35, QMetaType::QString, 0x00095103,
      33, 0x80000000 | 36, 0x0009500b,
      14, 0x80000000 | 37, 0x0009500b,

       0        // eod
};

void ConnectionController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ConnectionController *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->disconnected(); break;
        case 1: _t->connected(); break;
        case 2: _t->errorConnection((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->comingCheckpointModel(); break;
        case 4: _t->comingStateModel(); break;
        case 5: _t->workerAuthoriazationResult((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5])),(*reinterpret_cast< QString(*)>(_a[6])),(*reinterpret_cast< bool(*)>(_a[7]))); break;
        case 6: _t->connect(); break;
        case 7: _t->disconnect(); break;
        case 8: _t->send((*reinterpret_cast< COMMAND(*)>(_a[1]))); break;
        case 9: _t->slotReadyRead(); break;
        case 10: _t->slotDisconnected(); break;
        case 11: _t->slotConnected(); break;
        case 12: _t->slotError((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        case 13: { QVariant _r = _t->getSettings((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = std::move(_r); }  break;
        case 14: _t->setSettings((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QVariant(*)>(_a[2]))); break;
        case 15: _t->getCheckpointModel(); break;
        case 16: _t->getStatesModel(); break;
        case 17: _t->authWorker((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 12:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractSocket::SocketError >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ConnectionController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ConnectionController::disconnected)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ConnectionController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ConnectionController::connected)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (ConnectionController::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ConnectionController::errorConnection)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (ConnectionController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ConnectionController::comingCheckpointModel)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (ConnectionController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ConnectionController::comingStateModel)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (ConnectionController::*)(QString , QString , QString , QString , QString , QString , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ConnectionController::workerAuthoriazationResult)) {
                *result = 5;
                return;
            }
        }
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< CheckpointModel* >(); break;
        case 3:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< StateModel* >(); break;
        }
    }

#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<ConnectionController *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->_login; break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->_password; break;
        case 2: *reinterpret_cast< CheckpointModel**>(_v) = _t->getCheckpoint(); break;
        case 3: *reinterpret_cast< StateModel**>(_v) = _t->getState(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<ConnectionController *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setLogin(*reinterpret_cast< QString*>(_v)); break;
        case 1: _t->setPassword(*reinterpret_cast< QString*>(_v)); break;
        case 2:
            if (_t->modelCheckpoint != *reinterpret_cast< CheckpointModel**>(_v)) {
                _t->modelCheckpoint = *reinterpret_cast< CheckpointModel**>(_v);
            }
            break;
        case 3:
            if (_t->modelState != *reinterpret_cast< StateModel**>(_v)) {
                _t->modelState = *reinterpret_cast< StateModel**>(_v);
            }
            break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject ConnectionController::staticMetaObject = { {
    QMetaObject::SuperData::link<QQuickItem::staticMetaObject>(),
    qt_meta_stringdata_ConnectionController.data,
    qt_meta_data_ConnectionController,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ConnectionController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ConnectionController::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ConnectionController.stringdata0))
        return static_cast<void*>(this);
    return QQuickItem::qt_metacast(_clname);
}

int ConnectionController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QQuickItem::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 4;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void ConnectionController::disconnected()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void ConnectionController::connected()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void ConnectionController::errorConnection(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void ConnectionController::comingCheckpointModel()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void ConnectionController::comingStateModel()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void ConnectionController::workerAuthoriazationResult(QString _t1, QString _t2, QString _t3, QString _t4, QString _t5, QString _t6, bool _t7)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t5))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t6))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t7))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
