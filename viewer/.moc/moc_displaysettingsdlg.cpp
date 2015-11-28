/****************************************************************************
** Meta object code from reading C++ file 'displaysettingsdlg.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../displaysettingsdlg.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'displaysettingsdlg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CDisplaySettingsDialog[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      30,   24,   23,   23, 0x09,
      68,   24,   23,   23, 0x09,
     104,   24,   23,   23, 0x09,
     136,  132,   23,   23, 0x09,
     211,  132,   23,   23, 0x09,
     289,  286,   23,   23, 0x09,
     360,  286,   23,   23, 0x09,
     428,  426,   23,   23, 0x09,
     473,   23,   23,   23, 0x09,
     499,   23,   23,   23, 0x09,
     524,   23,   23,   23, 0x09,
     547,  426,   23,   23, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_CDisplaySettingsDialog[] = {
    "CDisplaySettingsDialog\0\0value\0"
    "combodisplaysettings_highlighted(int)\0"
    "combodisplaysettings_activated(int)\0"
    "radioreversed_toggled(bool)\0,,,\0"
    "listviewdisplaysettings_mouseButtonClicked(int,Q3ListViewItem*,QPoint,"
    "int)\0"
    "listviewdisplaysettings_mouseButtonPressed(int,Q3ListViewItem*,QPoint,"
    "int)\0"
    ",,\0"
    "listviewdisplaysettings_rightButtonClicked(Q3ListViewItem*,QPoint,int)\0"
    "listviewdisplaysettings_doubleClicked(Q3ListViewItem*,QPoint,int)\0"
    ",\0listviewdisplaysettings_setSorting(int,bool)\0"
    "pushbuttonprint_clicked()\0"
    "pushbuttonsave_clicked()\0"
    "pushbuttonok_clicked()\0"
    "listviewdisplaysettings_sortingChanged(int,bool)\0"
};

void CDisplaySettingsDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CDisplaySettingsDialog *_t = static_cast<CDisplaySettingsDialog *>(_o);
        switch (_id) {
        case 0: _t->combodisplaysettings_highlighted((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->combodisplaysettings_activated((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->radioreversed_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->listviewdisplaysettings_mouseButtonClicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< Q3ListViewItem*(*)>(_a[2])),(*reinterpret_cast< const QPoint(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 4: _t->listviewdisplaysettings_mouseButtonPressed((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< Q3ListViewItem*(*)>(_a[2])),(*reinterpret_cast< const QPoint(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 5: _t->listviewdisplaysettings_rightButtonClicked((*reinterpret_cast< Q3ListViewItem*(*)>(_a[1])),(*reinterpret_cast< const QPoint(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 6: _t->listviewdisplaysettings_doubleClicked((*reinterpret_cast< Q3ListViewItem*(*)>(_a[1])),(*reinterpret_cast< const QPoint(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 7: _t->listviewdisplaysettings_setSorting((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 8: _t->pushbuttonprint_clicked(); break;
        case 9: _t->pushbuttonsave_clicked(); break;
        case 10: _t->pushbuttonok_clicked(); break;
        case 11: _t->listviewdisplaysettings_sortingChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData CDisplaySettingsDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CDisplaySettingsDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_CDisplaySettingsDialog,
      qt_meta_data_CDisplaySettingsDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CDisplaySettingsDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CDisplaySettingsDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CDisplaySettingsDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CDisplaySettingsDialog))
        return static_cast<void*>(const_cast< CDisplaySettingsDialog*>(this));
    if (!strcmp(_clname, "Ui_CDisplaySettingsBaseDialog"))
        return static_cast< Ui_CDisplaySettingsBaseDialog*>(const_cast< CDisplaySettingsDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int CDisplaySettingsDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
