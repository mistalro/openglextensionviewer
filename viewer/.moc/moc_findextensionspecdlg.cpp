/****************************************************************************
** Meta object code from reading C++ file 'findextensionspecdlg.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../findextensionspecdlg.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'findextensionspecdlg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CFindExtensionSpecDialog[] = {

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
      26,   25,   25,   25, 0x09,
      68,   25,   25,   25, 0x09,
     101,   25,   25,   25, 0x09,
     124,   25,   25,   25, 0x09,
     149,   25,   25,   25, 0x09,
     181,  175,   25,   25, 0x09,
     216,  175,   25,   25, 0x09,
     251,  175,   25,   25, 0x09,
     293,  175,   25,   25, 0x09,
     340,  334,   25,   25, 0x09,
     391,  374,   25,   25, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_CFindExtensionSpecDialog[] = {
    "CFindExtensionSpecDialog\0\0"
    "lineeditsearchstring_textChanged(QString)\0"
    "pushbuttoncancelsearch_clicked()\0"
    "pushbuttonok_clicked()\0pushbuttonfind_clicked()\0"
    "pushbuttonclear_clicked()\0state\0"
    "radiobuttonmatchcase_toggled(bool)\0"
    "radiobuttonfindfirst_toggled(bool)\0"
    "radiobuttondisplayfullpaths_toggled(bool)\0"
    "radiobuttononematchperfile_toggled(bool)\0"
    "pitem\0listview_clicked(Q3ListViewItem*)\0"
    "column,ascending\0listview_setSorting(int,bool)\0"
};

void CFindExtensionSpecDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CFindExtensionSpecDialog *_t = static_cast<CFindExtensionSpecDialog *>(_o);
        switch (_id) {
        case 0: _t->lineeditsearchstring_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->pushbuttoncancelsearch_clicked(); break;
        case 2: _t->pushbuttonok_clicked(); break;
        case 3: _t->pushbuttonfind_clicked(); break;
        case 4: _t->pushbuttonclear_clicked(); break;
        case 5: _t->radiobuttonmatchcase_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->radiobuttonfindfirst_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->radiobuttondisplayfullpaths_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->radiobuttononematchperfile_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->listview_clicked((*reinterpret_cast< Q3ListViewItem*(*)>(_a[1]))); break;
        case 10: _t->listview_setSorting((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData CFindExtensionSpecDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CFindExtensionSpecDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_CFindExtensionSpecDialog,
      qt_meta_data_CFindExtensionSpecDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CFindExtensionSpecDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CFindExtensionSpecDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CFindExtensionSpecDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CFindExtensionSpecDialog))
        return static_cast<void*>(const_cast< CFindExtensionSpecDialog*>(this));
    if (!strcmp(_clname, "Ui_CFindExtensionSpecBaseDialog"))
        return static_cast< Ui_CFindExtensionSpecBaseDialog*>(const_cast< CFindExtensionSpecDialog*>(this));
    if (!strcmp(_clname, "CRegistryStringSearchCallback"))
        return static_cast< CRegistryStringSearchCallback*>(const_cast< CFindExtensionSpecDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int CFindExtensionSpecDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
