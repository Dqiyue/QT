/****************************************************************************
** Meta object code from reading C++ file 'showimage.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../Desktop/未命名文件夹/Will/showimage.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'showimage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ShowImage_t {
    QByteArrayData data[12];
    char stringdata[111];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ShowImage_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ShowImage_t qt_meta_stringdata_ShowImage = {
    {
QT_MOC_LITERAL(0, 0, 9),
QT_MOC_LITERAL(1, 10, 7),
QT_MOC_LITERAL(2, 18, 0),
QT_MOC_LITERAL(3, 19, 7),
QT_MOC_LITERAL(4, 27, 12),
QT_MOC_LITERAL(5, 40, 11),
QT_MOC_LITERAL(6, 52, 9),
QT_MOC_LITERAL(7, 62, 4),
QT_MOC_LITERAL(8, 67, 9),
QT_MOC_LITERAL(9, 77, 9),
QT_MOC_LITERAL(10, 87, 11),
QT_MOC_LITERAL(11, 99, 11)
    },
    "ShowImage\0get2end\0\0get2beg\0turn2default\0"
    "img_clicked\0init_path\0QDir\0show_next\0"
    "show_prev\0arise_scale\0spin_change"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ShowImage[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x06 /* Public */,
       3,    1,   62,    2, 0x06 /* Public */,
       4,    1,   65,    2, 0x06 /* Public */,
       5,    0,   68,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    2,   69,    2, 0x0a /* Public */,
       8,    0,   74,    2, 0x0a /* Public */,
       9,    0,   75,    2, 0x0a /* Public */,
      10,    1,   76,    2, 0x0a /* Public */,
      11,    0,   79,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 7, QMetaType::Int,    2,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,

       0        // eod
};

void ShowImage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ShowImage *_t = static_cast<ShowImage *>(_o);
        switch (_id) {
        case 0: _t->get2end((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->get2beg((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->turn2default((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->img_clicked(); break;
        case 4: _t->init_path((*reinterpret_cast< QDir(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 5: _t->show_next(); break;
        case 6: _t->show_prev(); break;
        case 7: _t->arise_scale((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->spin_change(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ShowImage::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ShowImage::get2end)) {
                *result = 0;
            }
        }
        {
            typedef void (ShowImage::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ShowImage::get2beg)) {
                *result = 1;
            }
        }
        {
            typedef void (ShowImage::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ShowImage::turn2default)) {
                *result = 2;
            }
        }
        {
            typedef void (ShowImage::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ShowImage::img_clicked)) {
                *result = 3;
            }
        }
    }
}

const QMetaObject ShowImage::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ShowImage.data,
      qt_meta_data_ShowImage,  qt_static_metacall, 0, 0}
};


const QMetaObject *ShowImage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ShowImage::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ShowImage.stringdata))
        return static_cast<void*>(const_cast< ShowImage*>(this));
    return QWidget::qt_metacast(_clname);
}

int ShowImage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
void ShowImage::get2end(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ShowImage::get2beg(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ShowImage::turn2default(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void ShowImage::img_clicked()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}
QT_END_MOC_NAMESPACE
