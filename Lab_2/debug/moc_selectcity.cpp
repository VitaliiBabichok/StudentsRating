/****************************************************************************
** Meta object code from reading C++ file 'selectcity.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../IPZ_client/selectcity.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'selectcity.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SelectCity_t {
    QByteArrayData data[18];
    char stringdata0[392];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SelectCity_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SelectCity_t qt_meta_stringdata_SelectCity = {
    {
QT_MOC_LITERAL(0, 0, 10), // "SelectCity"
QT_MOC_LITERAL(1, 11, 12), // "BackCityMenu"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 28), // "on_BackSetCityButton_clicked"
QT_MOC_LITERAL(4, 54, 34), // "on_BackSetUniversityButton_cl..."
QT_MOC_LITERAL(5, 89, 33), // "on_BackSetSpecialtyButton_cli..."
QT_MOC_LITERAL(6, 123, 30), // "on_BackSetCourseButton_clicked"
QT_MOC_LITERAL(7, 154, 28), // "on_BackRatingsButton_clicked"
QT_MOC_LITERAL(8, 183, 22), // "on_RefreshCity_clicked"
QT_MOC_LITERAL(9, 206, 19), // "on_listCity_clicked"
QT_MOC_LITERAL(10, 226, 11), // "QModelIndex"
QT_MOC_LITERAL(11, 238, 5), // "index"
QT_MOC_LITERAL(12, 244, 21), // "on_listUniver_clicked"
QT_MOC_LITERAL(13, 266, 24), // "on_listSpecialty_clicked"
QT_MOC_LITERAL(14, 291, 21), // "on_listCourse_clicked"
QT_MOC_LITERAL(15, 313, 27), // "on_GetGroup_editingFinished"
QT_MOC_LITERAL(16, 341, 33), // "on_GetNameStudent_editingFini..."
QT_MOC_LITERAL(17, 375, 16) // "on_Reset_clicked"

    },
    "SelectCity\0BackCityMenu\0\0"
    "on_BackSetCityButton_clicked\0"
    "on_BackSetUniversityButton_clicked\0"
    "on_BackSetSpecialtyButton_clicked\0"
    "on_BackSetCourseButton_clicked\0"
    "on_BackRatingsButton_clicked\0"
    "on_RefreshCity_clicked\0on_listCity_clicked\0"
    "QModelIndex\0index\0on_listUniver_clicked\0"
    "on_listSpecialty_clicked\0on_listCourse_clicked\0"
    "on_GetGroup_editingFinished\0"
    "on_GetNameStudent_editingFinished\0"
    "on_Reset_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SelectCity[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   85,    2, 0x08 /* Private */,
       4,    0,   86,    2, 0x08 /* Private */,
       5,    0,   87,    2, 0x08 /* Private */,
       6,    0,   88,    2, 0x08 /* Private */,
       7,    0,   89,    2, 0x08 /* Private */,
       8,    0,   90,    2, 0x08 /* Private */,
       9,    1,   91,    2, 0x08 /* Private */,
      12,    1,   94,    2, 0x08 /* Private */,
      13,    1,   97,    2, 0x08 /* Private */,
      14,    1,  100,    2, 0x08 /* Private */,
      15,    0,  103,    2, 0x08 /* Private */,
      16,    0,  104,    2, 0x08 /* Private */,
      17,    0,  105,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void SelectCity::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SelectCity *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->BackCityMenu(); break;
        case 1: _t->on_BackSetCityButton_clicked(); break;
        case 2: _t->on_BackSetUniversityButton_clicked(); break;
        case 3: _t->on_BackSetSpecialtyButton_clicked(); break;
        case 4: _t->on_BackSetCourseButton_clicked(); break;
        case 5: _t->on_BackRatingsButton_clicked(); break;
        case 6: _t->on_RefreshCity_clicked(); break;
        case 7: _t->on_listCity_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 8: _t->on_listUniver_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 9: _t->on_listSpecialty_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 10: _t->on_listCourse_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 11: _t->on_GetGroup_editingFinished(); break;
        case 12: _t->on_GetNameStudent_editingFinished(); break;
        case 13: _t->on_Reset_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (SelectCity::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SelectCity::BackCityMenu)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject SelectCity::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_SelectCity.data,
    qt_meta_data_SelectCity,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *SelectCity::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SelectCity::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SelectCity.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int SelectCity::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void SelectCity::BackCityMenu()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
