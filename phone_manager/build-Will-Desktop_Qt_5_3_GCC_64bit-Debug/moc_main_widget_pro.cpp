/****************************************************************************
** Meta object code from reading C++ file 'main_widget_pro.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Will/main_widget_pro.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'main_widget_pro.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_main_widget_pro_t {
    QByteArrayData data[7];
    char stringdata[78];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_main_widget_pro_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_main_widget_pro_t qt_meta_stringdata_main_widget_pro = {
    {
QT_MOC_LITERAL(0, 0, 15),
QT_MOC_LITERAL(1, 16, 8),
QT_MOC_LITERAL(2, 25, 0),
QT_MOC_LITERAL(3, 26, 12),
QT_MOC_LITERAL(4, 39, 12),
QT_MOC_LITERAL(5, 52, 11),
QT_MOC_LITERAL(6, 64, 13)
    },
    "main_widget_pro\0turnPage\0\0current_page\0"
    "close_widget\0show_widget\0show_feedback"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_main_widget_pro[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x08 /* Private */,
       4,    0,   37,    2, 0x08 /* Private */,
       5,    0,   38,    2, 0x0a /* Public */,
       6,    0,   39,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void main_widget_pro::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        main_widget_pro *_t = static_cast<main_widget_pro *>(_o);
        switch (_id) {
        case 0: _t->turnPage((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->close_widget(); break;
        case 2: _t->show_widget(); break;
        case 3: _t->show_feedback(); break;
        default: ;
        }
    }
}

const QMetaObject main_widget_pro::staticMetaObject = {
    { &Shdow_Pro::staticMetaObject, qt_meta_stringdata_main_widget_pro.data,
      qt_meta_data_main_widget_pro,  qt_static_metacall, 0, 0}
};


const QMetaObject *main_widget_pro::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *main_widget_pro::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_main_widget_pro.stringdata))
        return static_cast<void*>(const_cast< main_widget_pro*>(this));
    return Shdow_Pro::qt_metacast(_clname);
}

int main_widget_pro::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Shdow_Pro::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
