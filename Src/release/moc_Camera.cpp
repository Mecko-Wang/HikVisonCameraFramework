/****************************************************************************
** Meta object code from reading C++ file 'Camera.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Camera.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Camera.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CMyCamera_t {
    QByteArrayData data[19];
    char stringdata0[224];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CMyCamera_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CMyCamera_t qt_meta_stringdata_CMyCamera = {
    {
QT_MOC_LITERAL(0, 0, 9), // "CMyCamera"
QT_MOC_LITERAL(1, 10, 20), // "frameReceivedSignal1"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 5), // "state"
QT_MOC_LITERAL(4, 38, 14), // "unsigned char*"
QT_MOC_LITERAL(5, 53, 4), // "data"
QT_MOC_LITERAL(6, 58, 20), // "frameReceivedSignal2"
QT_MOC_LITERAL(7, 79, 20), // "frameReceivedSignal3"
QT_MOC_LITERAL(8, 100, 20), // "frameReceivedSignal4"
QT_MOC_LITERAL(9, 121, 20), // "frameReceivedSignal5"
QT_MOC_LITERAL(10, 142, 8), // "sendMess"
QT_MOC_LITERAL(11, 151, 9), // "excelevel"
QT_MOC_LITERAL(12, 161, 8), // "excedata"
QT_MOC_LITERAL(13, 170, 11), // "flushWindow"
QT_MOC_LITERAL(14, 182, 8), // "plcState"
QT_MOC_LITERAL(15, 191, 13), // "sendDateToPlc"
QT_MOC_LITERAL(16, 205, 5), // "bool*"
QT_MOC_LITERAL(17, 211, 8), // "startNum"
QT_MOC_LITERAL(18, 220, 3) // "len"

    },
    "CMyCamera\0frameReceivedSignal1\0\0state\0"
    "unsigned char*\0data\0frameReceivedSignal2\0"
    "frameReceivedSignal3\0frameReceivedSignal4\0"
    "frameReceivedSignal5\0sendMess\0excelevel\0"
    "excedata\0flushWindow\0plcState\0"
    "sendDateToPlc\0bool*\0startNum\0len"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CMyCamera[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       9,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   59,    2, 0x06 /* Public */,
       6,    2,   64,    2, 0x06 /* Public */,
       7,    2,   69,    2, 0x06 /* Public */,
       8,    2,   74,    2, 0x06 /* Public */,
       9,    2,   79,    2, 0x06 /* Public */,
      10,    2,   84,    2, 0x06 /* Public */,
      13,    0,   89,    2, 0x06 /* Public */,
      14,    1,   90,    2, 0x06 /* Public */,
      15,    4,   93,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool, 0x80000000 | 4,    3,    5,
    QMetaType::Void, QMetaType::Bool, 0x80000000 | 4,    3,    5,
    QMetaType::Void, QMetaType::Bool, 0x80000000 | 4,    3,    5,
    QMetaType::Void, QMetaType::Bool, 0x80000000 | 4,    3,    5,
    QMetaType::Void, QMetaType::Bool, 0x80000000 | 4,    3,    5,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   11,   12,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, 0x80000000 | 16, QMetaType::Int, QMetaType::Int, QMetaType::Int,    3,   17,   18,    5,

       0        // eod
};

void CMyCamera::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CMyCamera *_t = static_cast<CMyCamera *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->frameReceivedSignal1((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< unsigned char*(*)>(_a[2]))); break;
        case 1: _t->frameReceivedSignal2((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< unsigned char*(*)>(_a[2]))); break;
        case 2: _t->frameReceivedSignal3((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< unsigned char*(*)>(_a[2]))); break;
        case 3: _t->frameReceivedSignal4((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< unsigned char*(*)>(_a[2]))); break;
        case 4: _t->frameReceivedSignal5((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< unsigned char*(*)>(_a[2]))); break;
        case 5: _t->sendMess((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 6: _t->flushWindow(); break;
        case 7: _t->plcState((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->sendDateToPlc((*reinterpret_cast< bool*(*)>(_a[1])),(*reinterpret_cast< const int(*)>(_a[2])),(*reinterpret_cast< const int(*)>(_a[3])),(*reinterpret_cast< const int(*)>(_a[4]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CMyCamera::*_t)(bool , unsigned char * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CMyCamera::frameReceivedSignal1)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (CMyCamera::*_t)(bool , unsigned char * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CMyCamera::frameReceivedSignal2)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (CMyCamera::*_t)(bool , unsigned char * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CMyCamera::frameReceivedSignal3)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (CMyCamera::*_t)(bool , unsigned char * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CMyCamera::frameReceivedSignal4)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (CMyCamera::*_t)(bool , unsigned char * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CMyCamera::frameReceivedSignal5)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (CMyCamera::*_t)(QString , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CMyCamera::sendMess)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (CMyCamera::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CMyCamera::flushWindow)) {
                *result = 6;
                return;
            }
        }
        {
            typedef void (CMyCamera::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CMyCamera::plcState)) {
                *result = 7;
                return;
            }
        }
        {
            typedef void (CMyCamera::*_t)(bool * , const int , const int , const int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CMyCamera::sendDateToPlc)) {
                *result = 8;
                return;
            }
        }
    }
}

const QMetaObject CMyCamera::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_CMyCamera.data,
      qt_meta_data_CMyCamera,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *CMyCamera::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CMyCamera::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CMyCamera.stringdata0))
        return static_cast<void*>(const_cast< CMyCamera*>(this));
    if (!strcmp(_clname, "CHOperator"))
        return static_cast< CHOperator*>(const_cast< CMyCamera*>(this));
    return QObject::qt_metacast(_clname);
}

int CMyCamera::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void CMyCamera::frameReceivedSignal1(bool _t1, unsigned char * _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CMyCamera::frameReceivedSignal2(bool _t1, unsigned char * _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void CMyCamera::frameReceivedSignal3(bool _t1, unsigned char * _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void CMyCamera::frameReceivedSignal4(bool _t1, unsigned char * _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void CMyCamera::frameReceivedSignal5(bool _t1, unsigned char * _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void CMyCamera::sendMess(QString _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void CMyCamera::flushWindow()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void CMyCamera::plcState(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void CMyCamera::sendDateToPlc(bool * _t1, const int _t2, const int _t3, const int _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
