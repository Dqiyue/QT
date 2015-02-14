/****************************************************************************
** Meta object code from reading C++ file 'phoneshow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Will/phoneshow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'phoneshow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Phoneshow_t {
    QByteArrayData data[6];
    char stringdata[47];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Phoneshow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Phoneshow_t qt_meta_stringdata_Phoneshow = {
    {
QT_MOC_LITERAL(0, 0, 9),
QT_MOC_LITERAL(1, 10, 5),
QT_MOC_LITERAL(2, 16, 0),
QT_MOC_LITERAL(3, 17, 10),
QT_MOC_LITERAL(4, 28, 9),
QT_MOC_LITERAL(5, 38, 8)
    },
    "Phoneshow\0exitT\0\0phone_exit\0phoneshow\0"
    "showexit"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Phoneshow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x06 /* Public */,
       3,    0,   35,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   36,    2, 0x0a /* Public */,
       5,    0,   37,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Phoneshow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Phoneshow *_t = static_cast<Phoneshow *>(_o);
        switch (_id) {
        case 0: _t->exitT(); break;
        case 1: _t->phone_exit(); break;
        case 2: _t->phoneshow(); break;
        case 3: _t->showexit(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Phoneshow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Phoneshow::exitT)) {
                *result = 0;
            }
        }
        {
            typedef void (Phoneshow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Phoneshow::phone_exit)) {
                *result = 1;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject Phoneshow::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Phoneshow.data,
      qt_meta_data_Phoneshow,  qt_static_metacall, 0, 0}
};


const QMetaObject *Phoneshow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Phoneshow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Phoneshow.stringdata))
        return static_cast<void*>(const_cast< Phoneshow*>(this));
    return QWidget::qt_metacast(_clname);
}

int Phoneshow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
    return _id;
}

// SIGNAL 0
void Phoneshow::exitT()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void Phoneshow::phone_exit()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
