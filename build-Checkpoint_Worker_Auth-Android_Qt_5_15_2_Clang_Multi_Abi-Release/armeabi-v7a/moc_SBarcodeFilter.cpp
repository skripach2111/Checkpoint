/****************************************************************************
** Meta object code from reading C++ file 'SBarcodeFilter.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../Checkpoint_Worker_Auth/src/SBarcodeFilter.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SBarcodeFilter.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SBarcodeFilter_t {
    QByteArrayData data[10];
    char stringdata0[107];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SBarcodeFilter_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SBarcodeFilter_t qt_meta_stringdata_SBarcodeFilter = {
    {
QT_MOC_LITERAL(0, 0, 14), // "SBarcodeFilter"
QT_MOC_LITERAL(1, 15, 11), // "QML.Element"
QT_MOC_LITERAL(2, 27, 4), // "auto"
QT_MOC_LITERAL(3, 32, 15), // "capturedChanged"
QT_MOC_LITERAL(4, 48, 0), // ""
QT_MOC_LITERAL(5, 49, 8), // "captured"
QT_MOC_LITERAL(6, 58, 18), // "captureRectChanged"
QT_MOC_LITERAL(7, 77, 11), // "captureRect"
QT_MOC_LITERAL(8, 89, 11), // "setCaptured"
QT_MOC_LITERAL(9, 101, 5) // "clean"

    },
    "SBarcodeFilter\0QML.Element\0auto\0"
    "capturedChanged\0\0captured\0captureRectChanged\0"
    "captureRect\0setCaptured\0clean"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SBarcodeFilter[] = {

 // content:
       8,       // revision
       0,       // classname
       1,   14, // classinfo
       4,   16, // methods
       2,   46, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // classinfo: key, value
       1,    2,

 // signals: name, argc, parameters, tag, flags
       3,    1,   36,    4, 0x06 /* Public */,
       6,    1,   39,    4, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    1,   42,    4, 0x08 /* Private */,
       9,    0,   45,    4, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QRectF,    7,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void,

 // properties: name, type, flags
       5, QMetaType::QString, 0x00495001,
       7, QMetaType::QRectF, 0x00495103,

 // properties: notify_signal_id
       0,
       1,

       0        // eod
};

void SBarcodeFilter::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SBarcodeFilter *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->capturedChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->captureRectChanged((*reinterpret_cast< const QRectF(*)>(_a[1]))); break;
        case 2: _t->setCaptured((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->clean(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (SBarcodeFilter::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SBarcodeFilter::capturedChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (SBarcodeFilter::*)(const QRectF & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SBarcodeFilter::captureRectChanged)) {
                *result = 1;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<SBarcodeFilter *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->captured(); break;
        case 1: *reinterpret_cast< QRectF*>(_v) = _t->captureRect(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<SBarcodeFilter *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 1: _t->setCaptureRect(*reinterpret_cast< QRectF*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject SBarcodeFilter::staticMetaObject = { {
    QMetaObject::SuperData::link<QAbstractVideoFilter::staticMetaObject>(),
    qt_meta_stringdata_SBarcodeFilter.data,
    qt_meta_data_SBarcodeFilter,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *SBarcodeFilter::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SBarcodeFilter::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SBarcodeFilter.stringdata0))
        return static_cast<void*>(this);
    return QAbstractVideoFilter::qt_metacast(_clname);
}

int SBarcodeFilter::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractVideoFilter::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 2;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void SBarcodeFilter::capturedChanged(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void SBarcodeFilter::captureRectChanged(const QRectF & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
