/****************************************************************************
** Meta object code from reading C++ file 'SBarcodeDecoder.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../Checkpoint_Worker_Auth/src/SBarcodeDecoder.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SBarcodeDecoder.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SBarcodeDecoder_t {
    QByteArrayData data[8];
    char stringdata0[93];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SBarcodeDecoder_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SBarcodeDecoder_t qt_meta_stringdata_SBarcodeDecoder = {
    {
QT_MOC_LITERAL(0, 0, 15), // "SBarcodeDecoder"
QT_MOC_LITERAL(1, 16, 17), // "isDecodingChanged"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 10), // "isDecoding"
QT_MOC_LITERAL(4, 46, 15), // "capturedChanged"
QT_MOC_LITERAL(5, 62, 8), // "captured"
QT_MOC_LITERAL(6, 71, 7), // "process"
QT_MOC_LITERAL(7, 79, 13) // "capturedImage"

    },
    "SBarcodeDecoder\0isDecodingChanged\0\0"
    "isDecoding\0capturedChanged\0captured\0"
    "process\0capturedImage"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SBarcodeDecoder[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,
       4,    1,   32,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,   35,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::QString,    5,

 // slots: parameters
    QMetaType::Void, QMetaType::QImage,    7,

       0        // eod
};

void SBarcodeDecoder::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SBarcodeDecoder *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->isDecodingChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->capturedChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->process((*reinterpret_cast< const QImage(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (SBarcodeDecoder::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SBarcodeDecoder::isDecodingChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (SBarcodeDecoder::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SBarcodeDecoder::capturedChanged)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject SBarcodeDecoder::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_SBarcodeDecoder.data,
    qt_meta_data_SBarcodeDecoder,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *SBarcodeDecoder::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SBarcodeDecoder::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SBarcodeDecoder.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int SBarcodeDecoder::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void SBarcodeDecoder::isDecodingChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void SBarcodeDecoder::capturedChanged(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
