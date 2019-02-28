/****************************************************************************
** Meta object code from reading C++ file 'cplc.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../cplc.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cplc.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CPlc_t {
    QByteArrayData data[17];
    char stringdata0[142];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CPlc_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CPlc_t qt_meta_stringdata_CPlc = {
    {
QT_MOC_LITERAL(0, 0, 4), // "CPlc"
QT_MOC_LITERAL(1, 5, 8), // "sendMess"
QT_MOC_LITERAL(2, 14, 0), // ""
QT_MOC_LITERAL(3, 15, 9), // "excelevel"
QT_MOC_LITERAL(4, 25, 8), // "excedata"
QT_MOC_LITERAL(5, 34, 9), // "plcStates"
QT_MOC_LITERAL(6, 44, 5), // "state"
QT_MOC_LITERAL(7, 50, 8), // "initFunc"
QT_MOC_LITERAL(8, 59, 11), // "deleteLater"
QT_MOC_LITERAL(9, 71, 10), // "plcConnect"
QT_MOC_LITERAL(10, 82, 13), // "plcDisconnect"
QT_MOC_LITERAL(11, 96, 8), // "writePlc"
QT_MOC_LITERAL(12, 105, 5), // "bool*"
QT_MOC_LITERAL(13, 111, 8), // "startNum"
QT_MOC_LITERAL(14, 120, 3), // "len"
QT_MOC_LITERAL(15, 124, 4), // "data"
QT_MOC_LITERAL(16, 129, 12) // "registerName"

    },
    "CPlc\0sendMess\0\0excelevel\0excedata\0"
    "plcStates\0state\0initFunc\0deleteLater\0"
    "plcConnect\0plcDisconnect\0writePlc\0"
    "bool*\0startNum\0len\0data\0registerName"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CPlc[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   54,    2, 0x06 /* Public */,
       5,    1,   59,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   62,    2, 0x08 /* Private */,
       8,    0,   63,    2, 0x08 /* Private */,
       9,    0,   64,    2, 0x08 /* Private */,
      10,    0,   65,    2, 0x08 /* Private */,
      11,    5,   66,    2, 0x08 /* Private */,
      11,    4,   77,    2, 0x28 /* Private | MethodCloned */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    3,    4,
    QMetaType::Void, QMetaType::Bool,    6,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 12, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::QByteArray,    6,   13,   14,   15,   16,
    QMetaType::Void, 0x80000000 | 12, QMetaType::Int, QMetaType::Int, QMetaType::Int,    6,   13,   14,   15,

       0        // eod
};

void CPlc::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CPlc *_t = static_cast<CPlc *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendMess((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: _t->plcStates((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->initFunc(); break;
        case 3: _t->deleteLater(); break;
        case 4: _t->plcConnect(); break;
        case 5: _t->plcDisconnect(); break;
        case 6: _t->writePlc((*reinterpret_cast< bool*(*)>(_a[1])),(*reinterpret_cast< const int(*)>(_a[2])),(*reinterpret_cast< const int(*)>(_a[3])),(*reinterpret_cast< const int(*)>(_a[4])),(*reinterpret_cast< const QByteArray(*)>(_a[5]))); break;
        case 7: _t->writePlc((*reinterpret_cast< bool*(*)>(_a[1])),(*reinterpret_cast< const int(*)>(_a[2])),(*reinterpret_cast< const int(*)>(_a[3])),(*reinterpret_cast< const int(*)>(_a[4]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CPlc::*_t)(QString , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CPlc::sendMess)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (CPlc::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CPlc::plcStates)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject CPlc::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_CPlc.data,
      qt_meta_data_CPlc,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *CPlc::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CPlc::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CPlc.stringdata0))
        return static_cast<void*>(const_cast< CPlc*>(this));
    return QObject::qt_metacast(_clname);
}

int CPlc::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void CPlc::sendMess(QString _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CPlc::plcStates(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
