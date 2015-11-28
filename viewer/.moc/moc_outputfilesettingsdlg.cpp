/****************************************************************************
** Meta object code from reading C++ file 'outputfilesettingsdlg.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../outputfilesettingsdlg.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'outputfilesettingsdlg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_COutputFileSettingsDialog[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      27,   26,   26,   26, 0x09,
      67,   26,   26,   26, 0x09,
     109,   26,   26,   26, 0x09,
     151,   26,   26,   26, 0x09,
     192,   26,   26,   26, 0x09,
     215,   26,   26,   26, 0x09,
     241,   26,   26,   26, 0x09,
     268,   26,   26,   26, 0x09,
     294,   26,   26,   26, 0x09,
     329,   26,   26,   26, 0x09,
     362,   26,   26,   26, 0x09,
     395,   26,   26,   26, 0x09,
     419,   26,   26,   26, 0x09,
     443,   26,   26,   26, 0x09,
     460,   26,   26,   26, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_COutputFileSettingsDialog[] = {
    "COutputFileSettingsDialog\0\0"
    "editexternalscript_textChanged(QString)\0"
    "editoutputheaderfile_textChanged(QString)\0"
    "editoutputsourcefile_textChanged(QString)\0"
    "editoutputclassname_textChanged(QString)\0"
    "pushbuttonok_clicked()\0pushbuttonapply_clicked()\0"
    "pushbuttoncancel_clicked()\0"
    "pushbuttonreset_clicked()\0"
    "pushbuttonexternalbrowse_clicked()\0"
    "pushbuttonheaderbrowse_clicked()\0"
    "pushbuttonsourcebrowse_clicked()\0"
    "radiointernal_clicked()\0radioexternal_clicked()\0"
    "radioc_clicked()\0radiocpp_clicked()\0"
};

void COutputFileSettingsDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        COutputFileSettingsDialog *_t = static_cast<COutputFileSettingsDialog *>(_o);
        switch (_id) {
        case 0: _t->editexternalscript_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->editoutputheaderfile_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->editoutputsourcefile_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->editoutputclassname_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->pushbuttonok_clicked(); break;
        case 5: _t->pushbuttonapply_clicked(); break;
        case 6: _t->pushbuttoncancel_clicked(); break;
        case 7: _t->pushbuttonreset_clicked(); break;
        case 8: _t->pushbuttonexternalbrowse_clicked(); break;
        case 9: _t->pushbuttonheaderbrowse_clicked(); break;
        case 10: _t->pushbuttonsourcebrowse_clicked(); break;
        case 11: _t->radiointernal_clicked(); break;
        case 12: _t->radioexternal_clicked(); break;
        case 13: _t->radioc_clicked(); break;
        case 14: _t->radiocpp_clicked(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData COutputFileSettingsDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject COutputFileSettingsDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_COutputFileSettingsDialog,
      qt_meta_data_COutputFileSettingsDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &COutputFileSettingsDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *COutputFileSettingsDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *COutputFileSettingsDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_COutputFileSettingsDialog))
        return static_cast<void*>(const_cast< COutputFileSettingsDialog*>(this));
    if (!strcmp(_clname, "Ui_COutputFileSettingsBaseDialog"))
        return static_cast< Ui_COutputFileSettingsBaseDialog*>(const_cast< COutputFileSettingsDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int COutputFileSettingsDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
