/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_LrcNet_t {
    QByteArrayData data[6];
    char stringdata[42];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LrcNet_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LrcNet_t qt_meta_stringdata_LrcNet = {
    {
QT_MOC_LITERAL(0, 0, 6),
QT_MOC_LITERAL(1, 7, 6),
QT_MOC_LITERAL(2, 14, 0),
QT_MOC_LITERAL(3, 15, 7),
QT_MOC_LITERAL(4, 23, 8),
QT_MOC_LITERAL(5, 32, 9)
    },
    "LrcNet\0onDone\0\0onReady\0onDone_d\0"
    "onReady_d"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LrcNet[] = {

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
       1,    0,   34,    2, 0x08 /* Private */,
       3,    0,   35,    2, 0x08 /* Private */,
       4,    0,   36,    2, 0x08 /* Private */,
       5,    0,   37,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void LrcNet::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        LrcNet *_t = static_cast<LrcNet *>(_o);
        switch (_id) {
        case 0: _t->onDone(); break;
        case 1: _t->onReady(); break;
        case 2: _t->onDone_d(); break;
        case 3: _t->onReady_d(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject LrcNet::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_LrcNet.data,
      qt_meta_data_LrcNet,  qt_static_metacall, 0, 0}
};


const QMetaObject *LrcNet::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LrcNet::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_LrcNet.stringdata))
        return static_cast<void*>(const_cast< LrcNet*>(this));
    return QObject::qt_metacast(_clname);
}

int LrcNet::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
struct qt_meta_stringdata_Plist_t {
    QByteArrayData data[13];
    char stringdata[150];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Plist_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Plist_t qt_meta_stringdata_Plist = {
    {
QT_MOC_LITERAL(0, 0, 5),
QT_MOC_LITERAL(1, 6, 10),
QT_MOC_LITERAL(2, 17, 0),
QT_MOC_LITERAL(3, 18, 3),
QT_MOC_LITERAL(4, 22, 6),
QT_MOC_LITERAL(5, 29, 14),
QT_MOC_LITERAL(6, 44, 3),
QT_MOC_LITERAL(7, 48, 16),
QT_MOC_LITERAL(8, 65, 16),
QT_MOC_LITERAL(9, 82, 16),
QT_MOC_LITERAL(10, 99, 16),
QT_MOC_LITERAL(11, 116, 16),
QT_MOC_LITERAL(12, 133, 16)
    },
    "Plist\0plistClick\0\0row\0column\0"
    "slot_plist_rig\0pos\0slot_plist_rig_1\0"
    "slot_plist_rig_2\0slot_plist_rig_3\0"
    "slot_plist_rig_4\0slot_plist_rig_5\0"
    "slot_plist_rig_6"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Plist[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   54,    2, 0x0a /* Public */,
       5,    1,   59,    2, 0x0a /* Public */,
       7,    0,   62,    2, 0x0a /* Public */,
       8,    0,   63,    2, 0x0a /* Public */,
       9,    0,   64,    2, 0x0a /* Public */,
      10,    0,   65,    2, 0x0a /* Public */,
      11,    0,   66,    2, 0x0a /* Public */,
      12,    0,   67,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,
    QMetaType::Void, QMetaType::QPoint,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Plist::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Plist *_t = static_cast<Plist *>(_o);
        switch (_id) {
        case 0: _t->plistClick((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->slot_plist_rig((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 2: _t->slot_plist_rig_1(); break;
        case 3: _t->slot_plist_rig_2(); break;
        case 4: _t->slot_plist_rig_3(); break;
        case 5: _t->slot_plist_rig_4(); break;
        case 6: _t->slot_plist_rig_5(); break;
        case 7: _t->slot_plist_rig_6(); break;
        default: ;
        }
    }
}

const QMetaObject Plist::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Plist.data,
      qt_meta_data_Plist,  qt_static_metacall, 0, 0}
};


const QMetaObject *Plist::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Plist::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Plist.stringdata))
        return static_cast<void*>(const_cast< Plist*>(this));
    return QObject::qt_metacast(_clname);
}

int Plist::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
struct qt_meta_stringdata_infoDialog_t {
    QByteArrayData data[5];
    char stringdata[42];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_infoDialog_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_infoDialog_t qt_meta_stringdata_infoDialog = {
    {
QT_MOC_LITERAL(0, 0, 10),
QT_MOC_LITERAL(1, 11, 10),
QT_MOC_LITERAL(2, 22, 0),
QT_MOC_LITERAL(3, 23, 9),
QT_MOC_LITERAL(4, 33, 8)
    },
    "infoDialog\0slot_close\0\0slot_next\0"
    "slot_las"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_infoDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x0a /* Public */,
       3,    0,   30,    2, 0x0a /* Public */,
       4,    0,   31,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void infoDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        infoDialog *_t = static_cast<infoDialog *>(_o);
        switch (_id) {
        case 0: _t->slot_close(); break;
        case 1: _t->slot_next(); break;
        case 2: _t->slot_las(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject infoDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_infoDialog.data,
      qt_meta_data_infoDialog,  qt_static_metacall, 0, 0}
};


const QMetaObject *infoDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *infoDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_infoDialog.stringdata))
        return static_cast<void*>(const_cast< infoDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int infoDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
struct qt_meta_stringdata_setDialog_t {
    QByteArrayData data[9];
    char stringdata[103];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_setDialog_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_setDialog_t qt_meta_stringdata_setDialog = {
    {
QT_MOC_LITERAL(0, 0, 9),
QT_MOC_LITERAL(1, 10, 10),
QT_MOC_LITERAL(2, 21, 0),
QT_MOC_LITERAL(3, 22, 10),
QT_MOC_LITERAL(4, 33, 9),
QT_MOC_LITERAL(5, 43, 18),
QT_MOC_LITERAL(6, 62, 9),
QT_MOC_LITERAL(7, 72, 14),
QT_MOC_LITERAL(8, 87, 15)
    },
    "setDialog\0slot_close\0\0slot_reset\0"
    "slot_path\0slot_path_to_cache\0slot_sync\0"
    "slot_open_path\0slot_clearCache"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_setDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x0a /* Public */,
       3,    0,   50,    2, 0x0a /* Public */,
       4,    0,   51,    2, 0x0a /* Public */,
       5,    0,   52,    2, 0x0a /* Public */,
       6,    0,   53,    2, 0x0a /* Public */,
       7,    0,   54,    2, 0x0a /* Public */,
       8,    0,   55,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void setDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        setDialog *_t = static_cast<setDialog *>(_o);
        switch (_id) {
        case 0: _t->slot_close(); break;
        case 1: _t->slot_reset(); break;
        case 2: _t->slot_path(); break;
        case 3: _t->slot_path_to_cache(); break;
        case 4: _t->slot_sync(); break;
        case 5: _t->slot_open_path(); break;
        case 6: _t->slot_clearCache(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject setDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_setDialog.data,
      qt_meta_data_setDialog,  qt_static_metacall, 0, 0}
};


const QMetaObject *setDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *setDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_setDialog.stringdata))
        return static_cast<void*>(const_cast< setDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int setDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
struct qt_meta_stringdata_yunDialog_t {
    QByteArrayData data[18];
    char stringdata[187];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_yunDialog_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_yunDialog_t qt_meta_stringdata_yunDialog = {
    {
QT_MOC_LITERAL(0, 0, 9),
QT_MOC_LITERAL(1, 10, 10),
QT_MOC_LITERAL(2, 21, 0),
QT_MOC_LITERAL(3, 22, 9),
QT_MOC_LITERAL(4, 32, 1),
QT_MOC_LITERAL(5, 34, 1),
QT_MOC_LITERAL(6, 36, 9),
QT_MOC_LITERAL(7, 46, 10),
QT_MOC_LITERAL(8, 57, 12),
QT_MOC_LITERAL(9, 70, 13),
QT_MOC_LITERAL(10, 84, 13),
QT_MOC_LITERAL(11, 98, 27),
QT_MOC_LITERAL(12, 126, 4),
QT_MOC_LITERAL(13, 131, 10),
QT_MOC_LITERAL(14, 142, 9),
QT_MOC_LITERAL(15, 152, 11),
QT_MOC_LITERAL(16, 164, 13),
QT_MOC_LITERAL(17, 178, 8)
    },
    "yunDialog\0slot_timer\0\0updateDwn\0c\0m\0"
    "down_done\0down_ready\0onSearchDone\0"
    "onSearchReady\0onSearchError\0"
    "QNetworkReply::NetworkError\0code\0"
    "slot_close\0slot_stop\0slot_search\0"
    "slot_download\0slot_try"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_yunDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x0a /* Public */,
       3,    2,   75,    2, 0x0a /* Public */,
       6,    0,   80,    2, 0x0a /* Public */,
       7,    0,   81,    2, 0x0a /* Public */,
       8,    0,   82,    2, 0x0a /* Public */,
       9,    0,   83,    2, 0x0a /* Public */,
      10,    1,   84,    2, 0x0a /* Public */,
      13,    0,   87,    2, 0x0a /* Public */,
      14,    0,   88,    2, 0x0a /* Public */,
      15,    0,   89,    2, 0x0a /* Public */,
      16,    0,   90,    2, 0x0a /* Public */,
      17,    0,   91,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::LongLong, QMetaType::LongLong,    4,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void yunDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        yunDialog *_t = static_cast<yunDialog *>(_o);
        switch (_id) {
        case 0: _t->slot_timer(); break;
        case 1: _t->updateDwn((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2]))); break;
        case 2: _t->down_done(); break;
        case 3: _t->down_ready(); break;
        case 4: _t->onSearchDone(); break;
        case 5: _t->onSearchReady(); break;
        case 6: _t->onSearchError((*reinterpret_cast< QNetworkReply::NetworkError(*)>(_a[1]))); break;
        case 7: _t->slot_close(); break;
        case 8: _t->slot_stop(); break;
        case 9: _t->slot_search(); break;
        case 10: _t->slot_download(); break;
        case 11: _t->slot_try(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply::NetworkError >(); break;
            }
            break;
        }
    }
}

const QMetaObject yunDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_yunDialog.data,
      qt_meta_data_yunDialog,  qt_static_metacall, 0, 0}
};


const QMetaObject *yunDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *yunDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_yunDialog.stringdata))
        return static_cast<void*>(const_cast< yunDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int yunDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    return _id;
}
struct qt_meta_stringdata_aboutDialog_t {
    QByteArrayData data[4];
    char stringdata[25];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_aboutDialog_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_aboutDialog_t qt_meta_stringdata_aboutDialog = {
    {
QT_MOC_LITERAL(0, 0, 11),
QT_MOC_LITERAL(1, 12, 7),
QT_MOC_LITERAL(2, 20, 0),
QT_MOC_LITERAL(3, 21, 3)
    },
    "aboutDialog\0openUrl\0\0url"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_aboutDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   19,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,

       0        // eod
};

void aboutDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        aboutDialog *_t = static_cast<aboutDialog *>(_o);
        switch (_id) {
        case 0: _t->openUrl((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject aboutDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_aboutDialog.data,
      qt_meta_data_aboutDialog,  qt_static_metacall, 0, 0}
};


const QMetaObject *aboutDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *aboutDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_aboutDialog.stringdata))
        return static_cast<void*>(const_cast< aboutDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int aboutDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[18];
    char stringdata[188];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10),
QT_MOC_LITERAL(1, 11, 9),
QT_MOC_LITERAL(2, 21, 0),
QT_MOC_LITERAL(3, 22, 11),
QT_MOC_LITERAL(4, 34, 9),
QT_MOC_LITERAL(5, 44, 11),
QT_MOC_LITERAL(6, 56, 9),
QT_MOC_LITERAL(7, 66, 8),
QT_MOC_LITERAL(8, 75, 10),
QT_MOC_LITERAL(9, 86, 9),
QT_MOC_LITERAL(10, 96, 9),
QT_MOC_LITERAL(11, 106, 9),
QT_MOC_LITERAL(12, 116, 33),
QT_MOC_LITERAL(13, 150, 6),
QT_MOC_LITERAL(14, 157, 9),
QT_MOC_LITERAL(15, 167, 8),
QT_MOC_LITERAL(16, 176, 7),
QT_MOC_LITERAL(17, 184, 3)
    },
    "MainWindow\0slot_play\0\0slot_check_\0"
    "slot_min_\0slot_about_\0slot_set_\0"
    "slot_set\0slot_pause\0slot_next\0slot_last\0"
    "slot_tray\0QSystemTrayIcon::ActivationReason\0"
    "reason\0slot_exit\0slot_yun\0openUrl\0url"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x0a /* Public */,
       3,    0,   80,    2, 0x0a /* Public */,
       4,    0,   81,    2, 0x0a /* Public */,
       5,    0,   82,    2, 0x0a /* Public */,
       6,    0,   83,    2, 0x0a /* Public */,
       7,    0,   84,    2, 0x0a /* Public */,
       8,    0,   85,    2, 0x0a /* Public */,
       9,    0,   86,    2, 0x0a /* Public */,
      10,    0,   87,    2, 0x0a /* Public */,
      11,    1,   88,    2, 0x0a /* Public */,
      14,    0,   91,    2, 0x0a /* Public */,
      15,    0,   92,    2, 0x0a /* Public */,
      16,    1,   93,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   17,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->slot_play(); break;
        case 1: _t->slot_check_(); break;
        case 2: _t->slot_min_(); break;
        case 3: _t->slot_about_(); break;
        case 4: _t->slot_set_(); break;
        case 5: _t->slot_set(); break;
        case 6: _t->slot_pause(); break;
        case 7: _t->slot_next(); break;
        case 8: _t->slot_last(); break;
        case 9: _t->slot_tray((*reinterpret_cast< QSystemTrayIcon::ActivationReason(*)>(_a[1]))); break;
        case 10: _t->slot_exit(); break;
        case 11: _t->slot_yun(); break;
        case 12: _t->openUrl((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, 0, 0}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
