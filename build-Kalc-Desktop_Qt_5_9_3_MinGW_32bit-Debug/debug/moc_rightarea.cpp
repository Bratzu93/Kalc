/****************************************************************************
** Meta object code from reading C++ file 'rightarea.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Kalc/rightarea.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'rightarea.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_RightArea_t {
    QByteArrayData data[18];
    char stringdata0[191];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RightArea_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RightArea_t qt_meta_stringdata_RightArea = {
    {
QT_MOC_LITERAL(0, 0, 9), // "RightArea"
QT_MOC_LITERAL(1, 10, 7), // "AddItem"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 8), // "selected"
QT_MOC_LITERAL(4, 28, 1), // "i"
QT_MOC_LITERAL(5, 30, 13), // "addFirstPress"
QT_MOC_LITERAL(6, 44, 14), // "addSecondPress"
QT_MOC_LITERAL(7, 59, 10), // "ClearPress"
QT_MOC_LITERAL(8, 70, 9), // "savePress"
QT_MOC_LITERAL(9, 80, 10), // "sommaPress"
QT_MOC_LITERAL(10, 91, 9), // "diffPress"
QT_MOC_LITERAL(11, 101, 9), // "moltPress"
QT_MOC_LITERAL(12, 111, 8), // "divPress"
QT_MOC_LITERAL(13, 120, 11), // "traslaPress"
QT_MOC_LITERAL(14, 132, 12), // "_traslaPress"
QT_MOC_LITERAL(15, 145, 12), // "internoPress"
QT_MOC_LITERAL(16, 158, 17), // "Punto_VicinoPress"
QT_MOC_LITERAL(17, 176, 14) // "SommaSegmPress"

    },
    "RightArea\0AddItem\0\0selected\0i\0"
    "addFirstPress\0addSecondPress\0ClearPress\0"
    "savePress\0sommaPress\0diffPress\0moltPress\0"
    "divPress\0traslaPress\0_traslaPress\0"
    "internoPress\0Punto_VicinoPress\0"
    "SommaSegmPress"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RightArea[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   89,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,   90,    2, 0x0a /* Public */,
       5,    0,   93,    2, 0x0a /* Public */,
       6,    0,   94,    2, 0x0a /* Public */,
       7,    0,   95,    2, 0x0a /* Public */,
       8,    0,   96,    2, 0x0a /* Public */,
       9,    0,   97,    2, 0x0a /* Public */,
      10,    0,   98,    2, 0x0a /* Public */,
      11,    0,   99,    2, 0x0a /* Public */,
      12,    0,  100,    2, 0x0a /* Public */,
      13,    0,  101,    2, 0x0a /* Public */,
      14,    0,  102,    2, 0x0a /* Public */,
      15,    0,  103,    2, 0x0a /* Public */,
      16,    0,  104,    2, 0x0a /* Public */,
      17,    0,  105,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void RightArea::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        RightArea *_t = static_cast<RightArea *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->AddItem(); break;
        case 1: _t->selected((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->addFirstPress(); break;
        case 3: _t->addSecondPress(); break;
        case 4: _t->ClearPress(); break;
        case 5: _t->savePress(); break;
        case 6: _t->sommaPress(); break;
        case 7: _t->diffPress(); break;
        case 8: _t->moltPress(); break;
        case 9: _t->divPress(); break;
        case 10: _t->traslaPress(); break;
        case 11: _t->_traslaPress(); break;
        case 12: _t->internoPress(); break;
        case 13: _t->Punto_VicinoPress(); break;
        case 14: _t->SommaSegmPress(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (RightArea::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RightArea::AddItem)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject RightArea::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_RightArea.data,
      qt_meta_data_RightArea,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *RightArea::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RightArea::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_RightArea.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int RightArea::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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

// SIGNAL 0
void RightArea::AddItem()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
