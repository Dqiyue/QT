/****************************************************************************
** Meta object code from reading C++ file 'real_phone_picture.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Will/real_phone_picture.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'real_phone_picture.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Real_Phone_Picture_t {
    QByteArrayData data[8];
    char stringdata[86];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Real_Phone_Picture_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Real_Phone_Picture_t qt_meta_stringdata_Real_Phone_Picture = {
    {
QT_MOC_LITERAL(0, 0, 18),
QT_MOC_LITERAL(1, 19, 9),
QT_MOC_LITERAL(2, 29, 0),
QT_MOC_LITERAL(3, 30, 9),
QT_MOC_LITERAL(4, 40, 11),
QT_MOC_LITERAL(5, 52, 11),
QT_MOC_LITERAL(6, 64, 12),
QT_MOC_LITERAL(7, 77, 8)
    },
    "Real_Phone_Picture\0turn2next\0\0turn2prev\0"
    "scalethepix\0changelabel\0close_window\0"
    "img_spin"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Real_Phone_Picture[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x08 /* Private */,
       3,    0,   45,    2, 0x08 /* Private */,
       4,    1,   46,    2, 0x08 /* Private */,
       5,    1,   49,    2, 0x08 /* Private */,
       6,    0,   52,    2, 0x08 /* Private */,
       7,    0,   53,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Real_Phone_Picture::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Real_Phone_Picture *_t = static_cast<Real_Phone_Picture *>(_o);
        switch (_id) {
        case 0: _t->turn2next(); break;
        case 1: _t->turn2prev(); break;
        case 2: _t->scalethepix((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->changelabel((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->close_window(); break;
        case 5: _t->img_spin(); break;
        default: ;
        }
    }
}

const QMetaObject Real_Phone_Picture::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Real_Phone_Picture.data,
      qt_meta_data_Real_Phone_Picture,  qt_static_metacall, 0, 0}
};


const QMetaObject *Real_Phone_Picture::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Real_Phone_Picture::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Real_Phone_Picture.stringdata))
        return static_cast<void*>(const_cast< Real_Phone_Picture*>(this));
    return QWidget::qt_metacast(_clname);
}

int Real_Phone_Picture::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
