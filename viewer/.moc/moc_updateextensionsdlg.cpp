/****************************************************************************
** Meta object code from reading C++ file 'updateextensionsdlg.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../updateextensionsdlg.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'updateextensionsdlg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CUpdateExtensionsDialog[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      31,   25,   24,   24, 0x09,
      65,   25,   24,   24, 0x09,
     103,   25,   24,   24, 0x09,
     138,   25,   24,   24, 0x09,
     177,   25,   24,   24, 0x09,
     222,  216,   24,   24, 0x09,
     278,   24,   24,   24, 0x09,
     301,   24,   24,   24, 0x09,
     328,   24,   24,   24, 0x09,
     354,   24,   24,   24, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_CUpdateExtensionsDialog[] = {
    "CUpdateExtensionsDialog\0\0value\0"
    "checkboxreadheaders_toggled(bool)\0"
    "checkboxdownloadheaders_toggled(bool)\0"
    "checkboxreadregistry_toggled(bool)\0"
    "checkboxdownloadregistry_toggled(bool)\0"
    "checkboxignoreextensions_toggled(bool)\0"
    "pitem\0listboxextensionsnotfound_doubleClicked(Q3ListBoxItem*)\0"
    "pushbuttonok_clicked()\0"
    "pushbuttoncancel_clicked()\0"
    "pushbuttonapply_clicked()\0"
    "pushbuttonreset_clicked()\0"
};

void CUpdateExtensionsDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CUpdateExtensionsDialog *_t = static_cast<CUpdateExtensionsDialog *>(_o);
        switch (_id) {
        case 0: _t->checkboxreadheaders_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->checkboxdownloadheaders_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->checkboxreadregistry_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->checkboxdownloadregistry_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->checkboxignoreextensions_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->listboxextensionsnotfound_doubleClicked((*reinterpret_cast< Q3ListBoxItem*(*)>(_a[1]))); break;
        case 6: _t->pushbuttonok_clicked(); break;
        case 7: _t->pushbuttoncancel_clicked(); break;
        case 8: _t->pushbuttonapply_clicked(); break;
        case 9: _t->pushbuttonreset_clicked(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData CUpdateExtensionsDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CUpdateExtensionsDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_CUpdateExtensionsDialog,
      qt_meta_data_CUpdateExtensionsDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CUpdateExtensionsDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CUpdateExtensionsDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CUpdateExtensionsDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CUpdateExtensionsDialog))
        return static_cast<void*>(const_cast< CUpdateExtensionsDialog*>(this));
    if (!strcmp(_clname, "Ui_CUpdateExtensionsBaseDialog"))
        return static_cast< Ui_CUpdateExtensionsBaseDialog*>(const_cast< CUpdateExtensionsDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int CUpdateExtensionsDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
