/****************************************************************************
** Meta object code from reading C++ file 'content_widget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Will/content_widget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'content_widget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Content_Widget_t {
    QByteArrayData data[13];
    char stringdata[135];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Content_Widget_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Content_Widget_t qt_meta_stringdata_Content_Widget = {
    {
QT_MOC_LITERAL(0, 0, 14),
QT_MOC_LITERAL(1, 15, 5),
QT_MOC_LITERAL(2, 21, 0),
QT_MOC_LITERAL(3, 22, 11),
QT_MOC_LITERAL(4, 34, 12),
QT_MOC_LITERAL(5, 47, 8),
QT_MOC_LITERAL(6, 56, 12),
QT_MOC_LITERAL(7, 69, 14),
QT_MOC_LITERAL(8, 84, 18),
QT_MOC_LITERAL(9, 103, 11),
QT_MOC_LITERAL(10, 115, 8),
QT_MOC_LITERAL(11, 124, 7),
QT_MOC_LITERAL(12, 132, 2)
    },
    "Content_Widget\0fresh\0\0shot_screen\0"
    "catch_screen\0turnPage\0current_page\0"
    "refresh_screen\0update_song_number\0"
    "song_number\0turnHome\0pro_fin\0ec"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Content_Widget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   55,    2, 0x0a /* Public */,
       4,    0,   56,    2, 0x0a /* Public */,
       5,    1,   57,    2, 0x0a /* Public */,
       7,    0,   60,    2, 0x0a /* Public */,
       8,    1,   61,    2, 0x0a /* Public */,
      10,    0,   64,    2, 0x0a /* Public */,
      11,    1,   65,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   12,

       0        // eod
};

void Content_Widget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Content_Widget *_t = static_cast<Content_Widget *>(_o);
        switch (_id) {
        case 0: _t->fresh(); break;
        case 1: _t->shot_screen(); break;
        case 2: _t->catch_screen(); break;
        case 3: _t->turnPage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->refresh_screen(); break;
        case 5: _t->update_song_number((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->turnHome(); break;
        case 7: _t->pro_fin((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Content_Widget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Content_Widget::fresh)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject Content_Widget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Content_Widget.data,
      qt_meta_data_Content_Widget,  qt_static_metacall, 0, 0}
};


const QMetaObject *Content_Widget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Content_Widget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Content_Widget.stringdata))
        return static_cast<void*>(const_cast< Content_Widget*>(this));
    return QWidget::qt_metacast(_clname);
}

int Content_Widget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void Content_Widget::fresh()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
