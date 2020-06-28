/****************************************************************************
** Meta object code from reading C++ file 'tower.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "tower.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tower.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Tower_t {
    QByteArrayData data[3];
    char stringdata0[19];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Tower_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Tower_t qt_meta_stringdata_Tower = {
    {
QT_MOC_LITERAL(0, 0, 5), // "Tower"
QT_MOC_LITERAL(1, 6, 11), // "shootWeapon"
QT_MOC_LITERAL(2, 18, 0) // ""

    },
    "Tower\0shootWeapon\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Tower[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   19,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void Tower::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Tower *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->shootWeapon(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject Tower::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_Tower.data,
    qt_meta_data_Tower,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Tower::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Tower::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Tower.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Tower::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}
struct qt_meta_stringdata_Tower1_t {
    QByteArrayData data[3];
    char stringdata0[20];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Tower1_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Tower1_t qt_meta_stringdata_Tower1 = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Tower1"
QT_MOC_LITERAL(1, 7, 11), // "shootWeapon"
QT_MOC_LITERAL(2, 19, 0) // ""

    },
    "Tower1\0shootWeapon\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Tower1[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   19,    2, 0x09 /* Protected */,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void Tower1::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Tower1 *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->shootWeapon(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject Tower1::staticMetaObject = { {
    QMetaObject::SuperData::link<Tower::staticMetaObject>(),
    qt_meta_stringdata_Tower1.data,
    qt_meta_data_Tower1,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Tower1::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Tower1::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Tower1.stringdata0))
        return static_cast<void*>(this);
    return Tower::qt_metacast(_clname);
}

int Tower1::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Tower::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}
struct qt_meta_stringdata_Tower1_2_t {
    QByteArrayData data[3];
    char stringdata0[22];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Tower1_2_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Tower1_2_t qt_meta_stringdata_Tower1_2 = {
    {
QT_MOC_LITERAL(0, 0, 8), // "Tower1_2"
QT_MOC_LITERAL(1, 9, 11), // "shootWeapon"
QT_MOC_LITERAL(2, 21, 0) // ""

    },
    "Tower1_2\0shootWeapon\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Tower1_2[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   19,    2, 0x09 /* Protected */,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void Tower1_2::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Tower1_2 *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->shootWeapon(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject Tower1_2::staticMetaObject = { {
    QMetaObject::SuperData::link<Tower1::staticMetaObject>(),
    qt_meta_stringdata_Tower1_2.data,
    qt_meta_data_Tower1_2,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Tower1_2::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Tower1_2::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Tower1_2.stringdata0))
        return static_cast<void*>(this);
    return Tower1::qt_metacast(_clname);
}

int Tower1_2::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Tower1::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}
struct qt_meta_stringdata_Tower2_t {
    QByteArrayData data[3];
    char stringdata0[20];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Tower2_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Tower2_t qt_meta_stringdata_Tower2 = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Tower2"
QT_MOC_LITERAL(1, 7, 11), // "shootWeapon"
QT_MOC_LITERAL(2, 19, 0) // ""

    },
    "Tower2\0shootWeapon\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Tower2[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   19,    2, 0x09 /* Protected */,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void Tower2::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Tower2 *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->shootWeapon(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject Tower2::staticMetaObject = { {
    QMetaObject::SuperData::link<Tower::staticMetaObject>(),
    qt_meta_stringdata_Tower2.data,
    qt_meta_data_Tower2,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Tower2::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Tower2::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Tower2.stringdata0))
        return static_cast<void*>(this);
    return Tower::qt_metacast(_clname);
}

int Tower2::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Tower::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}
struct qt_meta_stringdata_Tower2_2_t {
    QByteArrayData data[3];
    char stringdata0[22];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Tower2_2_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Tower2_2_t qt_meta_stringdata_Tower2_2 = {
    {
QT_MOC_LITERAL(0, 0, 8), // "Tower2_2"
QT_MOC_LITERAL(1, 9, 11), // "shootWeapon"
QT_MOC_LITERAL(2, 21, 0) // ""

    },
    "Tower2_2\0shootWeapon\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Tower2_2[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   19,    2, 0x09 /* Protected */,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void Tower2_2::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Tower2_2 *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->shootWeapon(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject Tower2_2::staticMetaObject = { {
    QMetaObject::SuperData::link<Tower2::staticMetaObject>(),
    qt_meta_stringdata_Tower2_2.data,
    qt_meta_data_Tower2_2,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Tower2_2::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Tower2_2::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Tower2_2.stringdata0))
        return static_cast<void*>(this);
    return Tower2::qt_metacast(_clname);
}

int Tower2_2::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Tower2::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
