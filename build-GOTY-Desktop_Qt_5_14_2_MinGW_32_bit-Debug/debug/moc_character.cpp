/****************************************************************************
** Meta object code from reading C++ file 'character.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../GOTY(18-4-22)/character.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'character.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_character_t {
    QByteArrayData data[11];
    char stringdata0[135];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_character_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_character_t qt_meta_stringdata_character = {
    {
QT_MOC_LITERAL(0, 0, 9), // "character"
QT_MOC_LITERAL(1, 10, 5), // "shoot"
QT_MOC_LITERAL(2, 16, 0), // ""
QT_MOC_LITERAL(3, 17, 6), // "moveUp"
QT_MOC_LITERAL(4, 24, 40), // "QVector<QVector<QVector<chara..."
QT_MOC_LITERAL(5, 65, 7), // "charLoc"
QT_MOC_LITERAL(6, 73, 24), // "QVector<QVector<bool> >&"
QT_MOC_LITERAL(7, 98, 8), // "presence"
QT_MOC_LITERAL(8, 107, 8), // "moveDown"
QT_MOC_LITERAL(9, 116, 9), // "moveRight"
QT_MOC_LITERAL(10, 126, 8) // "moveLeft"

    },
    "character\0shoot\0\0moveUp\0"
    "QVector<QVector<QVector<character*> > >&\0"
    "charLoc\0QVector<QVector<bool> >&\0"
    "presence\0moveDown\0moveRight\0moveLeft"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_character[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x0a /* Public */,
       3,    2,   40,    2, 0x0a /* Public */,
       8,    2,   45,    2, 0x0a /* Public */,
       9,    2,   50,    2, 0x0a /* Public */,
      10,    2,   55,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4, 0x80000000 | 6,    5,    7,
    QMetaType::Void, 0x80000000 | 4, 0x80000000 | 6,    5,    7,
    QMetaType::Void, 0x80000000 | 4, 0x80000000 | 6,    5,    7,
    QMetaType::Void, 0x80000000 | 4, 0x80000000 | 6,    5,    7,

       0        // eod
};

void character::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<character *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->shoot(); break;
        case 1: _t->moveUp((*reinterpret_cast< QVector<QVector<QVector<character*> > >(*)>(_a[1])),(*reinterpret_cast< QVector<QVector<bool> >(*)>(_a[2]))); break;
        case 2: _t->moveDown((*reinterpret_cast< QVector<QVector<QVector<character*> > >(*)>(_a[1])),(*reinterpret_cast< QVector<QVector<bool> >(*)>(_a[2]))); break;
        case 3: _t->moveRight((*reinterpret_cast< QVector<QVector<QVector<character*> > >(*)>(_a[1])),(*reinterpret_cast< QVector<QVector<bool> >(*)>(_a[2]))); break;
        case 4: _t->moveLeft((*reinterpret_cast< QVector<QVector<QVector<character*> > >(*)>(_a[1])),(*reinterpret_cast< QVector<QVector<bool> >(*)>(_a[2]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject character::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_character.data,
    qt_meta_data_character,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *character::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *character::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_character.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "QGraphicsPixmapItem"))
        return static_cast< QGraphicsPixmapItem*>(this);
    return QObject::qt_metacast(_clname);
}

int character::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
