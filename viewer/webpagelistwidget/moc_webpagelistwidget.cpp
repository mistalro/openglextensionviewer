/****************************************************************************
** Meta object code from reading C++ file 'webpagelistwidget.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "webpagelistwidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'webpagelistwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CWebPageListView[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: signature, parameters, type, tag, flags
      35,   18,   17,   17, 0x05,
      65,   60,   17,   17, 0x05,
      89,   60,   17,   17, 0x05,
     107,   60,   17,   17, 0x05,
     126,   60,   17,   17, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_CWebPageListView[] = {
    "CWebPageListView\0\0column,ascending\0"
    "sortingChanged(int,bool)\0item\0"
    "mouseDoubleClicked(int)\0mousePressed(int)\0"
    "mouseReleased(int)\0mouseMoved(int)\0"
};

void CWebPageListView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CWebPageListView *_t = static_cast<CWebPageListView *>(_o);
        switch (_id) {
        case 0: _t->sortingChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 1: _t->mouseDoubleClicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->mousePressed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->mouseReleased((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->mouseMoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData CWebPageListView::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CWebPageListView::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_CWebPageListView,
      qt_meta_data_CWebPageListView, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CWebPageListView::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CWebPageListView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CWebPageListView::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CWebPageListView))
        return static_cast<void*>(const_cast< CWebPageListView*>(this));
    return QWidget::qt_metacast(_clname);
}

int CWebPageListView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void CWebPageListView::sortingChanged(int _t1, bool _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CWebPageListView::mouseDoubleClicked(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void CWebPageListView::mousePressed(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void CWebPageListView::mouseReleased(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void CWebPageListView::mouseMoved(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_END_MOC_NAMESPACE
