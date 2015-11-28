/****************************************************************************
** Meta object code from reading C++ file 'headerfileprogressdlg.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../headerfileprogressdlg.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'headerfileprogressdlg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CHeaderFileProgressDialog[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      27,   26,   26,   26, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_CHeaderFileProgressDialog[] = {
    "CHeaderFileProgressDialog\0\0"
    "pushbuttoncancel_clicked()\0"
};

void CHeaderFileProgressDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CHeaderFileProgressDialog *_t = static_cast<CHeaderFileProgressDialog *>(_o);
        switch (_id) {
        case 0: _t->pushbuttoncancel_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData CHeaderFileProgressDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CHeaderFileProgressDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_CHeaderFileProgressDialog,
      qt_meta_data_CHeaderFileProgressDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CHeaderFileProgressDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CHeaderFileProgressDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CHeaderFileProgressDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CHeaderFileProgressDialog))
        return static_cast<void*>(const_cast< CHeaderFileProgressDialog*>(this));
    if (!strcmp(_clname, "Ui_CHeaderFileProgressBaseDialog"))
        return static_cast< Ui_CHeaderFileProgressBaseDialog*>(const_cast< CHeaderFileProgressDialog*>(this));
    if (!strcmp(_clname, "CHeaderFileProgressCallback"))
        return static_cast< CHeaderFileProgressCallback*>(const_cast< CHeaderFileProgressDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int CHeaderFileProgressDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
