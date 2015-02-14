/****************************************************************************
** Meta object code from reading C++ file 'file_manager.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Will/file_manager.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'file_manager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_File_Manager_t {
    QByteArrayData data[21];
    char stringdata[231];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_File_Manager_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_File_Manager_t qt_meta_stringdata_File_Manager = {
    {
QT_MOC_LITERAL(0, 0, 12),
QT_MOC_LITERAL(1, 13, 9),
QT_MOC_LITERAL(2, 23, 0),
QT_MOC_LITERAL(3, 24, 8),
QT_MOC_LITERAL(4, 33, 9),
QT_MOC_LITERAL(5, 43, 8),
QT_MOC_LITERAL(6, 52, 5),
QT_MOC_LITERAL(7, 58, 11),
QT_MOC_LITERAL(8, 70, 2),
QT_MOC_LITERAL(9, 73, 15),
QT_MOC_LITERAL(10, 89, 17),
QT_MOC_LITERAL(11, 107, 16),
QT_MOC_LITERAL(12, 124, 7),
QT_MOC_LITERAL(13, 132, 5),
QT_MOC_LITERAL(14, 138, 3),
QT_MOC_LITERAL(15, 142, 14),
QT_MOC_LITERAL(16, 157, 4),
QT_MOC_LITERAL(17, 162, 15),
QT_MOC_LITERAL(18, 178, 13),
QT_MOC_LITERAL(19, 192, 17),
QT_MOC_LITERAL(20, 210, 20)
    },
    "File_Manager\0open_file\0\0get_file\0"
    "pull_file\0del_file\0index\0get_pro_fin\0"
    "ec\0get_pro_fin_two\0get_pro_fin_three\0"
    "get_pro_fin_four\0pro_fin\0cdDir\0dir\0"
    "del_phone_file\0name\0copy_file_to_pc\0"
    "resume_layout\0resume_layout_two\0"
    "get_back_to_last_dir"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_File_Manager[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   89,    2, 0x0a /* Public */,
       3,    0,   90,    2, 0x0a /* Public */,
       4,    0,   91,    2, 0x0a /* Public */,
       5,    1,   92,    2, 0x0a /* Public */,
       7,    1,   95,    2, 0x0a /* Public */,
       9,    1,   98,    2, 0x0a /* Public */,
      10,    1,  101,    2, 0x0a /* Public */,
      11,    1,  104,    2, 0x0a /* Public */,
      12,    1,  107,    2, 0x0a /* Public */,
      13,    1,  110,    2, 0x0a /* Public */,
      15,    1,  113,    2, 0x0a /* Public */,
      17,    1,  116,    2, 0x0a /* Public */,
      18,    1,  119,    2, 0x0a /* Public */,
      19,    1,  122,    2, 0x0a /* Public */,
      20,    0,  125,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::QString,   14,
    QMetaType::Void, QMetaType::QString,   16,
    QMetaType::Void, QMetaType::QString,   16,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void,

       0        // eod
};

void File_Manager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        File_Manager *_t = static_cast<File_Manager *>(_o);
        switch (_id) {
        case 0: _t->open_file(); break;
        case 1: _t->get_file(); break;
        case 2: _t->pull_file(); break;
        case 3: _t->del_file((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->get_pro_fin((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->get_pro_fin_two((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->get_pro_fin_three((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->get_pro_fin_four((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->pro_fin((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->cdDir((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 10: _t->del_phone_file((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 11: _t->copy_file_to_pc((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 12: _t->resume_layout((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->resume_layout_two((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: _t->get_back_to_last_dir(); break;
        default: ;
        }
    }
}

const QMetaObject File_Manager::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_File_Manager.data,
      qt_meta_data_File_Manager,  qt_static_metacall, 0, 0}
};


const QMetaObject *File_Manager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *File_Manager::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_File_Manager.stringdata))
        return static_cast<void*>(const_cast< File_Manager*>(this));
    return QWidget::qt_metacast(_clname);
}

int File_Manager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
