/****************************************************************************
** Meta object code from reading C++ file 'tittle_widget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Will/tittle_widget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tittle_widget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Tittle_Widget_t {
    QByteArrayData data[10];
    char stringdata[93];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Tittle_Widget_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Tittle_Widget_t qt_meta_stringdata_Tittle_Widget = {
    {
QT_MOC_LITERAL(0, 0, 13),
QT_MOC_LITERAL(1, 14, 10),
QT_MOC_LITERAL(2, 25, 0),
QT_MOC_LITERAL(3, 26, 8),
QT_MOC_LITERAL(4, 35, 7),
QT_MOC_LITERAL(5, 43, 7),
QT_MOC_LITERAL(6, 51, 11),
QT_MOC_LITERAL(7, 63, 7),
QT_MOC_LITERAL(8, 71, 8),
QT_MOC_LITERAL(9, 80, 12)
    },
    "Tittle_Widget\0show_close\0\0show_min\0"
    "showMax\0showNor\0change_skin\0current\0"
    "turnPage\0current_page"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Tittle_Widget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x06 /* Public */,
       3,    0,   55,    2, 0x06 /* Public */,
       4,    0,   56,    2, 0x06 /* Public */,
       5,    0,   57,    2, 0x06 /* Public */,
       6,    1,   58,    2, 0x06 /* Public */,
       8,    1,   61,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    1,   64,    2, 0x0a /* Public */,
       6,    0,   67,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,    9,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void,

       0        // eod
};

void Tittle_Widget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Tittle_Widget *_t = static_cast<Tittle_Widget *>(_o);
        switch (_id) {
        case 0: _t->show_close(); break;
        case 1: _t->show_min(); break;
        case 2: _t->showMax(); break;
        case 3: _t->showNor(); break;
        case 4: _t->change_skin((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->turnPage((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->turnPage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->change_skin(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Tittle_Widget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Tittle_Widget::show_close)) {
                *result = 0;
            }
        }
        {
            typedef void (Tittle_Widget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Tittle_Widget::show_min)) {
                *result = 1;
            }
        }
        {
            typedef void (Tittle_Widget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Tittle_Widget::showMax)) {
                *result = 2;
            }
        }
        {
            typedef void (Tittle_Widget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Tittle_Widget::showNor)) {
                *result = 3;
            }
        }
        {
            typedef void (Tittle_Widget::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Tittle_Widget::change_skin)) {
                *result = 4;
            }
        }
        {
            typedef void (Tittle_Widget::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Tittle_Widget::turnPage)) {
                *result = 5;
            }
        }
    }
}

const QMetaObject Tittle_Widget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Tittle_Widget.data,
      qt_meta_data_Tittle_Widget,  qt_static_metacall, 0, 0}
};


const QMetaObject *Tittle_Widget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Tittle_Widget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Tittle_Widget.stringdata))
        return static_cast<void*>(const_cast< Tittle_Widget*>(this));
    return QWidget::qt_metacast(_clname);
}

int Tittle_Widget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
void Tittle_Widget::show_close()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void Tittle_Widget::show_min()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void Tittle_Widget::showMax()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void Tittle_Widget::showNor()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void Tittle_Widget::change_skin(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void Tittle_Widget::turnPage(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_END_MOC_NAMESPACE
