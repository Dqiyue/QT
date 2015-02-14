/****************************************************************************
** Meta object code from reading C++ file 'main_menu.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Will/main_menu.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'main_menu.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Main_Menu_t {
    QByteArrayData data[6];
    char stringdata[57];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Main_Menu_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Main_Menu_t qt_meta_stringdata_Main_Menu = {
    {
QT_MOC_LITERAL(0, 0, 9),
QT_MOC_LITERAL(1, 10, 11),
QT_MOC_LITERAL(2, 22, 0),
QT_MOC_LITERAL(3, 23, 11),
QT_MOC_LITERAL(4, 35, 8),
QT_MOC_LITERAL(5, 44, 12)
    },
    "Main_Menu\0show_widget\0\0hide_widget\0"
    "show_min\0close_widget"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Main_Menu[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x06 /* Public */,
       3,    0,   35,    2, 0x06 /* Public */,
       4,    0,   36,    2, 0x06 /* Public */,
       5,    0,   37,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Main_Menu::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Main_Menu *_t = static_cast<Main_Menu *>(_o);
        switch (_id) {
        case 0: _t->show_widget(); break;
        case 1: _t->hide_widget(); break;
        case 2: _t->show_min(); break;
        case 3: _t->close_widget(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Main_Menu::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Main_Menu::show_widget)) {
                *result = 0;
            }
        }
        {
            typedef void (Main_Menu::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Main_Menu::hide_widget)) {
                *result = 1;
            }
        }
        {
            typedef void (Main_Menu::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Main_Menu::show_min)) {
                *result = 2;
            }
        }
        {
            typedef void (Main_Menu::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Main_Menu::close_widget)) {
                *result = 3;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject Main_Menu::staticMetaObject = {
    { &QMenu::staticMetaObject, qt_meta_stringdata_Main_Menu.data,
      qt_meta_data_Main_Menu,  qt_static_metacall, 0, 0}
};


const QMetaObject *Main_Menu::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Main_Menu::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Main_Menu.stringdata))
        return static_cast<void*>(const_cast< Main_Menu*>(this));
    return QMenu::qt_metacast(_clname);
}

int Main_Menu::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMenu::qt_metacall(_c, _id, _a);
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
void Main_Menu::show_widget()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void Main_Menu::hide_widget()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void Main_Menu::show_min()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void Main_Menu::close_widget()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}
QT_END_MOC_NAMESPACE
