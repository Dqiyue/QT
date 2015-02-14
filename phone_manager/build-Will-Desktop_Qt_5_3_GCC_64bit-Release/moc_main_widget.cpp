/****************************************************************************
** Meta object code from reading C++ file 'main_widget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Will/main_widget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'main_widget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Main_Widget_t {
    QByteArrayData data[18];
    char stringdata[211];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Main_Widget_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Main_Widget_t qt_meta_stringdata_Main_Widget = {
    {
QT_MOC_LITERAL(0, 0, 11),
QT_MOC_LITERAL(1, 12, 8),
QT_MOC_LITERAL(2, 21, 0),
QT_MOC_LITERAL(3, 22, 12),
QT_MOC_LITERAL(4, 35, 11),
QT_MOC_LITERAL(5, 47, 7),
QT_MOC_LITERAL(6, 55, 13),
QT_MOC_LITERAL(7, 69, 33),
QT_MOC_LITERAL(8, 103, 6),
QT_MOC_LITERAL(9, 110, 12),
QT_MOC_LITERAL(10, 123, 8),
QT_MOC_LITERAL(11, 132, 15),
QT_MOC_LITERAL(12, 148, 7),
QT_MOC_LITERAL(13, 156, 11),
QT_MOC_LITERAL(14, 168, 13),
QT_MOC_LITERAL(15, 182, 11),
QT_MOC_LITERAL(16, 194, 10),
QT_MOC_LITERAL(17, 205, 5)
    },
    "Main_Widget\0turnPage\0\0current_page\0"
    "change_skin\0current\0iconIsActived\0"
    "QSystemTrayIcon::ActivationReason\0"
    "reason\0close_widget\0btn_able\0"
    "real_start_view\0fitsize\0show_widget\0"
    "show_feedback\0show_my_app\0is_pressed\0"
    "fresh"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Main_Widget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   69,    2, 0x08 /* Private */,
       4,    1,   72,    2, 0x08 /* Private */,
       6,    1,   75,    2, 0x08 /* Private */,
       9,    0,   78,    2, 0x08 /* Private */,
      10,    0,   79,    2, 0x08 /* Private */,
      11,    0,   80,    2, 0x08 /* Private */,
      12,    0,   81,    2, 0x08 /* Private */,
      13,    0,   82,    2, 0x0a /* Public */,
      14,    0,   83,    2, 0x0a /* Public */,
      15,    1,   84,    2, 0x0a /* Public */,
      17,    0,   87,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   16,
    QMetaType::Void,

       0        // eod
};

void Main_Widget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Main_Widget *_t = static_cast<Main_Widget *>(_o);
        switch (_id) {
        case 0: _t->turnPage((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->change_skin((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->iconIsActived((*reinterpret_cast< QSystemTrayIcon::ActivationReason(*)>(_a[1]))); break;
        case 3: _t->close_widget(); break;
        case 4: _t->btn_able(); break;
        case 5: _t->real_start_view(); break;
        case 6: _t->fitsize(); break;
        case 7: _t->show_widget(); break;
        case 8: _t->show_feedback(); break;
        case 9: _t->show_my_app((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: _t->fresh(); break;
        default: ;
        }
    }
}

const QMetaObject Main_Widget::staticMetaObject = {
    { &Shdow_Pro::staticMetaObject, qt_meta_stringdata_Main_Widget.data,
      qt_meta_data_Main_Widget,  qt_static_metacall, 0, 0}
};


const QMetaObject *Main_Widget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Main_Widget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Main_Widget.stringdata))
        return static_cast<void*>(const_cast< Main_Widget*>(this));
    return Shdow_Pro::qt_metacast(_clname);
}

int Main_Widget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Shdow_Pro::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
