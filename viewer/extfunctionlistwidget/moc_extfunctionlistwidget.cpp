/****************************************************************************
** Meta object code from reading C++ file 'extfunctionlistwidget.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "extfunctionlistwidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'extfunctionlistwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CDerivedListViewFunction[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      43,   26,   25,   25, 0x05,

 // slots: signature, parameters, type, tag, flags
      68,   26,   25,   25, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_CDerivedListViewFunction[] = {
    "CDerivedListViewFunction\0\0column,ascending\0"
    "sortingChanged(int,bool)\0setSorting(int,bool)\0"
};

void CDerivedListViewFunction::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CDerivedListViewFunction *_t = static_cast<CDerivedListViewFunction *>(_o);
        switch (_id) {
        case 0: _t->sortingChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 1: _t->setSorting((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData CDerivedListViewFunction::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CDerivedListViewFunction::staticMetaObject = {
    { &Q3ListView::staticMetaObject, qt_meta_stringdata_CDerivedListViewFunction,
      qt_meta_data_CDerivedListViewFunction, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CDerivedListViewFunction::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CDerivedListViewFunction::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CDerivedListViewFunction::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CDerivedListViewFunction))
        return static_cast<void*>(const_cast< CDerivedListViewFunction*>(this));
    return Q3ListView::qt_metacast(_clname);
}

int CDerivedListViewFunction::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Q3ListView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void CDerivedListViewFunction::sortingChanged(int _t1, bool _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
static const uint qt_meta_data_CExtensionFunctionListView[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      45,   28,   27,   27, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_CExtensionFunctionListView[] = {
    "CExtensionFunctionListView\0\0"
    "column,ascending\0sortingChanged(int,bool)\0"
};

void CExtensionFunctionListView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CExtensionFunctionListView *_t = static_cast<CExtensionFunctionListView *>(_o);
        switch (_id) {
        case 0: _t->sortingChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData CExtensionFunctionListView::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CExtensionFunctionListView::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_CExtensionFunctionListView,
      qt_meta_data_CExtensionFunctionListView, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CExtensionFunctionListView::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CExtensionFunctionListView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CExtensionFunctionListView::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CExtensionFunctionListView))
        return static_cast<void*>(const_cast< CExtensionFunctionListView*>(this));
    return QWidget::qt_metacast(_clname);
}

int CExtensionFunctionListView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void CExtensionFunctionListView::sortingChanged(int _t1, bool _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
