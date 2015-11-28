/****************************************************************************
** Meta object code from reading C++ file 'webpagelistview.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "webpagelistview.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'webpagelistview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CDerivedListViewWebPage[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: signature, parameters, type, tag, flags
      42,   25,   24,   24, 0x05,
      72,   67,   24,   24, 0x05,
      96,   67,   24,   24, 0x05,
     114,   67,   24,   24, 0x05,
     133,   67,   24,   24, 0x05,

 // slots: signature, parameters, type, tag, flags
     149,   25,   24,   24, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_CDerivedListViewWebPage[] = {
    "CDerivedListViewWebPage\0\0column,ascending\0"
    "sortingChanged(int,bool)\0item\0"
    "mouseDoubleClicked(int)\0mousePressed(int)\0"
    "mouseReleased(int)\0mouseMoved(int)\0"
    "setSorting(int,bool)\0"
};

void CDerivedListViewWebPage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CDerivedListViewWebPage *_t = static_cast<CDerivedListViewWebPage *>(_o);
        switch (_id) {
        case 0: _t->sortingChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 1: _t->mouseDoubleClicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->mousePressed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->mouseReleased((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->mouseMoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->setSorting((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData CDerivedListViewWebPage::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CDerivedListViewWebPage::staticMetaObject = {
    { &Q3ListView::staticMetaObject, qt_meta_stringdata_CDerivedListViewWebPage,
      qt_meta_data_CDerivedListViewWebPage, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CDerivedListViewWebPage::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CDerivedListViewWebPage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CDerivedListViewWebPage::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CDerivedListViewWebPage))
        return static_cast<void*>(const_cast< CDerivedListViewWebPage*>(this));
    return Q3ListView::qt_metacast(_clname);
}

int CDerivedListViewWebPage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Q3ListView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void CDerivedListViewWebPage::sortingChanged(int _t1, bool _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CDerivedListViewWebPage::mouseDoubleClicked(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void CDerivedListViewWebPage::mousePressed(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void CDerivedListViewWebPage::mouseReleased(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void CDerivedListViewWebPage::mouseMoved(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_END_MOC_NAMESPACE
