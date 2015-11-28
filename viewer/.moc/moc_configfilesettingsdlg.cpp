/****************************************************************************
** Meta object code from reading C++ file 'configfilesettingsdlg.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../configfilesettingsdlg.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'configfilesettingsdlg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CConfigFileSettingsDialog[] = {

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
      34,   27,   26,   26, 0x09,
      74,   26,   26,   26, 0x09,
     101,   26,   26,   26, 0x09,
     131,   26,   26,   26, 0x09,
     163,   26,   26,   26, 0x09,
     197,   26,   26,   26, 0x09,
     227,   26,   26,   26, 0x09,
     259,   26,   26,   26, 0x09,
     293,   26,   26,   26, 0x09,
     316,   26,   26,   26, 0x09,
     343,   26,   26,   26, 0x09,
     369,   26,   26,   26, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_CConfigFileSettingsDialog[] = {
    "CConfigFileSettingsDialog\0\0string\0"
    "lineeditconfigfile_textChanged(QString)\0"
    "pushbuttonbrowse_clicked()\0"
    "radiobuttonloadauto_clicked()\0"
    "radiobuttonloadprompt_clicked()\0"
    "radiobuttonloadnoaction_clicked()\0"
    "radiobuttonsaveauto_clicked()\0"
    "radiobuttonsaveprompt_clicked()\0"
    "radiobuttonsavenoaction_clicked()\0"
    "pushbuttonok_clicked()\0"
    "pushbuttoncancel_clicked()\0"
    "pushbuttonapply_clicked()\0"
    "pushbuttonreset_clicked()\0"
};

void CConfigFileSettingsDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CConfigFileSettingsDialog *_t = static_cast<CConfigFileSettingsDialog *>(_o);
        switch (_id) {
        case 0: _t->lineeditconfigfile_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->pushbuttonbrowse_clicked(); break;
        case 2: _t->radiobuttonloadauto_clicked(); break;
        case 3: _t->radiobuttonloadprompt_clicked(); break;
        case 4: _t->radiobuttonloadnoaction_clicked(); break;
        case 5: _t->radiobuttonsaveauto_clicked(); break;
        case 6: _t->radiobuttonsaveprompt_clicked(); break;
        case 7: _t->radiobuttonsavenoaction_clicked(); break;
        case 8: _t->pushbuttonok_clicked(); break;
        case 9: _t->pushbuttoncancel_clicked(); break;
        case 10: _t->pushbuttonapply_clicked(); break;
        case 11: _t->pushbuttonreset_clicked(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData CConfigFileSettingsDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CConfigFileSettingsDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_CConfigFileSettingsDialog,
      qt_meta_data_CConfigFileSettingsDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CConfigFileSettingsDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CConfigFileSettingsDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CConfigFileSettingsDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CConfigFileSettingsDialog))
        return static_cast<void*>(const_cast< CConfigFileSettingsDialog*>(this));
    if (!strcmp(_clname, "Ui_CConfigFileSettingsBaseDialog"))
        return static_cast< Ui_CConfigFileSettingsBaseDialog*>(const_cast< CConfigFileSettingsDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int CConfigFileSettingsDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
