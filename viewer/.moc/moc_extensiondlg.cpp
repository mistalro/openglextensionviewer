/****************************************************************************
** Meta object code from reading C++ file 'extensiondlg.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../extensiondlg.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'extensiondlg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CExtensionDialog[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      18,   17,   17,   17, 0x0a,
      41,   17,   17,   17, 0x0a,
      66,   17,   17,   17, 0x0a,
      95,   17,   17,   17, 0x0a,
     122,   17,   17,   17, 0x0a,
     146,   17,   17,   17, 0x0a,
     177,  171,   17,   17, 0x0a,
     205,  171,   17,   17, 0x0a,
     238,  171,   17,   17, 0x0a,
     272,  171,   17,   17, 0x0a,
     302,   17,   17,   17, 0x0a,
     341,   17,   17,   17, 0x0a,
     375,   17,   17,   17, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_CExtensionDialog[] = {
    "CExtensionDialog\0\0pushbuttonok_clicked()\0"
    "pushbuttonnext_clicked()\0"
    "pushbuttonprevious_clicked()\0"
    "pushbuttonremove_clicked()\0"
    "pushbuttonadd_clicked()\0"
    "pushbuttonfind_clicked()\0value\0"
    "radioselected_toggled(bool)\0"
    "radiocasesensitive_toggled(bool)\0"
    "radiosearchforwards_toggled(bool)\0"
    "radiowholewords_toggled(bool)\0"
    "editextensionname_textChanged(QString)\0"
    "editfindtext_textChanged(QString)\0"
    "combobox_activated(QString)\0"
};

void CExtensionDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CExtensionDialog *_t = static_cast<CExtensionDialog *>(_o);
        switch (_id) {
        case 0: _t->pushbuttonok_clicked(); break;
        case 1: _t->pushbuttonnext_clicked(); break;
        case 2: _t->pushbuttonprevious_clicked(); break;
        case 3: _t->pushbuttonremove_clicked(); break;
        case 4: _t->pushbuttonadd_clicked(); break;
        case 5: _t->pushbuttonfind_clicked(); break;
        case 6: _t->radioselected_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->radiocasesensitive_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->radiosearchforwards_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->radiowholewords_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: _t->editextensionname_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 11: _t->editfindtext_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 12: _t->combobox_activated((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData CExtensionDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CExtensionDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_CExtensionDialog,
      qt_meta_data_CExtensionDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CExtensionDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CExtensionDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CExtensionDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CExtensionDialog))
        return static_cast<void*>(const_cast< CExtensionDialog*>(this));
    if (!strcmp(_clname, "Ui_CExtensionBaseDialog"))
        return static_cast< Ui_CExtensionBaseDialog*>(const_cast< CExtensionDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int CExtensionDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
