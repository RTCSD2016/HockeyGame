/****************************************************************************
** Meta object code from reading C++ file 'gameobjects.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../hockey/HockeyGame/gameobjects.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gameobjects.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Hockey__RedRobot_t {
    QByteArrayData data[4];
    char stringdata0[37];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Hockey__RedRobot_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Hockey__RedRobot_t qt_meta_stringdata_Hockey__RedRobot = {
    {
QT_MOC_LITERAL(0, 0, 16), // "Hockey::RedRobot"
QT_MOC_LITERAL(1, 17, 6), // "Update"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 11) // "messagetype"

    },
    "Hockey::RedRobot\0Update\0\0messagetype"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Hockey__RedRobot[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   19,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,

       0        // eod
};

void Hockey::RedRobot::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        RedRobot *_t = static_cast<RedRobot *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->Update((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject Hockey::RedRobot::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Hockey__RedRobot.data,
      qt_meta_data_Hockey__RedRobot,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Hockey::RedRobot::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Hockey::RedRobot::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Hockey__RedRobot.stringdata0))
        return static_cast<void*>(const_cast< RedRobot*>(this));
    if (!strcmp(_clname, "GameObject"))
        return static_cast< GameObject*>(const_cast< RedRobot*>(this));
    return QObject::qt_metacast(_clname);
}

int Hockey::RedRobot::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}
struct qt_meta_stringdata_Hockey__GreenRobot_t {
    QByteArrayData data[4];
    char stringdata0[39];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Hockey__GreenRobot_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Hockey__GreenRobot_t qt_meta_stringdata_Hockey__GreenRobot = {
    {
QT_MOC_LITERAL(0, 0, 18), // "Hockey::GreenRobot"
QT_MOC_LITERAL(1, 19, 6), // "Update"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 11) // "messagetype"

    },
    "Hockey::GreenRobot\0Update\0\0messagetype"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Hockey__GreenRobot[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   19,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,

       0        // eod
};

void Hockey::GreenRobot::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GreenRobot *_t = static_cast<GreenRobot *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->Update((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject Hockey::GreenRobot::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Hockey__GreenRobot.data,
      qt_meta_data_Hockey__GreenRobot,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Hockey::GreenRobot::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Hockey::GreenRobot::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Hockey__GreenRobot.stringdata0))
        return static_cast<void*>(const_cast< GreenRobot*>(this));
    if (!strcmp(_clname, "GameObject"))
        return static_cast< GameObject*>(const_cast< GreenRobot*>(this));
    return QObject::qt_metacast(_clname);
}

int Hockey::GreenRobot::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
