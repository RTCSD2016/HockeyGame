/****************************************************************************
** Meta object code from reading C++ file 'guimain.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../hockey/HockeyGame/guimain.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'guimain.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Hockey__GuiMain_t {
    QByteArrayData data[8];
    char stringdata0[78];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Hockey__GuiMain_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Hockey__GuiMain_t qt_meta_stringdata_Hockey__GuiMain = {
    {
QT_MOC_LITERAL(0, 0, 15), // "Hockey::GuiMain"
QT_MOC_LITERAL(1, 16, 13), // "keyPressEvent"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 10), // "QKeyEvent*"
QT_MOC_LITERAL(4, 42, 5), // "event"
QT_MOC_LITERAL(5, 48, 15), // "ResetButtonDown"
QT_MOC_LITERAL(6, 64, 1), // "b"
QT_MOC_LITERAL(7, 66, 11) // "UpdatePoint"

    },
    "Hockey::GuiMain\0keyPressEvent\0\0"
    "QKeyEvent*\0event\0ResetButtonDown\0b\0"
    "UpdatePoint"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Hockey__GuiMain[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x08 /* Private */,
       5,    1,   32,    2, 0x08 /* Private */,
       7,    0,   35,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::Bool,    6,
    QMetaType::Void,

       0        // eod
};

void Hockey::GuiMain::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GuiMain *_t = static_cast<GuiMain *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->keyPressEvent((*reinterpret_cast< QKeyEvent*(*)>(_a[1]))); break;
        case 1: _t->ResetButtonDown((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->UpdatePoint(); break;
        default: ;
        }
    }
}

const QMetaObject Hockey::GuiMain::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Hockey__GuiMain.data,
      qt_meta_data_Hockey__GuiMain,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Hockey::GuiMain::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Hockey::GuiMain::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Hockey__GuiMain.stringdata0))
        return static_cast<void*>(const_cast< GuiMain*>(this));
    return QWidget::qt_metacast(_clname);
}

int Hockey::GuiMain::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
