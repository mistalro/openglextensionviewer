/****************************************************************************
** Meta object code from reading C++ file 'pixelformatdlg.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../pixelformatdlg.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'pixelformatdlg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CPixelFormatDialog[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      26,   20,   19,   19, 0x09,
      58,   20,   19,   19, 0x09,
      92,   20,   19,   19, 0x09,
     127,  123,   19,   19, 0x09,
     198,  123,   19,   19, 0x09,
     272,  269,   19,   19, 0x09,
     339,  269,   19,   19, 0x09,
     403,  401,   19,   19, 0x09,
     444,   19,   19,   19, 0x09,
     470,   19,   19,   19, 0x09,
     495,   19,   19,   19, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_CPixelFormatDialog[] = {
    "CPixelFormatDialog\0\0value\0"
    "combopixelformat_activated(int)\0"
    "combopixelformat_highlighted(int)\0"
    "radiopixelformat_toggled(bool)\0,,,\0"
    "listviewpixelformat_mouseButtonClicked(int,Q3ListViewItem*,QPoint,int)\0"
    "listviewpixelformat_mouseButtonPressed(int,Q3ListViewItem*,QPoint,int)\0"
    ",,\0"
    "listviewpixelformat_rightButtonClicked(Q3ListViewItem*,QPoint,int)\0"
    "listviewpixelformat_doubleClicked(Q3ListViewItem*,QPoint,int)\0"
    ",\0listviewpixelformat_setSorting(int,bool)\0"
    "pushbuttonprint_clicked()\0"
    "pushbuttonsave_clicked()\0"
    "pushbuttonok_clicked()\0"
};

void CPixelFormatDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CPixelFormatDialog *_t = static_cast<CPixelFormatDialog *>(_o);
        switch (_id) {
        case 0: _t->combopixelformat_activated((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->combopixelformat_highlighted((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->radiopixelformat_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->listviewpixelformat_mouseButtonClicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< Q3ListViewItem*(*)>(_a[2])),(*reinterpret_cast< const QPoint(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 4: _t->listviewpixelformat_mouseButtonPressed((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< Q3ListViewItem*(*)>(_a[2])),(*reinterpret_cast< const QPoint(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 5: _t->listviewpixelformat_rightButtonClicked((*reinterpret_cast< Q3ListViewItem*(*)>(_a[1])),(*reinterpret_cast< const QPoint(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 6: _t->listviewpixelformat_doubleClicked((*reinterpret_cast< Q3ListViewItem*(*)>(_a[1])),(*reinterpret_cast< const QPoint(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 7: _t->listviewpixelformat_setSorting((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 8: _t->pushbuttonprint_clicked(); break;
        case 9: _t->pushbuttonsave_clicked(); break;
        case 10: _t->pushbuttonok_clicked(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData CPixelFormatDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CPixelFormatDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_CPixelFormatDialog,
      qt_meta_data_CPixelFormatDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CPixelFormatDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CPixelFormatDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CPixelFormatDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CPixelFormatDialog))
        return static_cast<void*>(const_cast< CPixelFormatDialog*>(this));
    if (!strcmp(_clname, "Ui_CPixelFormatBaseDialog"))
        return static_cast< Ui_CPixelFormatBaseDialog*>(const_cast< CPixelFormatDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int CPixelFormatDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
