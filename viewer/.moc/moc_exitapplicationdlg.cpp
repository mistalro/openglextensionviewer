/****************************************************************************
** Meta object code from reading C++ file 'exitapplicationdlg.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../exitapplicationdlg.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'exitapplicationdlg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CExitApplicationDialog[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      24,   23,   23,   23, 0x09,
      48,   23,   23,   23, 0x09,
      71,   23,   23,   23, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_CExitApplicationDialog[] = {
    "CExitApplicationDialog\0\0pushbuttonyes_clicked()\0"
    "pushbuttonno_clicked()\0"
    "pushbuttoncancel_clicked()\0"
};

void CExitApplicationDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CExitApplicationDialog *_t = static_cast<CExitApplicationDialog *>(_o);
        switch (_id) {
        case 0: _t->pushbuttonyes_clicked(); break;
        case 1: _t->pushbuttonno_clicked(); break;
        case 2: _t->pushbuttoncancel_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData CExitApplicationDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CExitApplicationDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_CExitApplicationDialog,
      qt_meta_data_CExitApplicationDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CExitApplicationDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CExitApplicationDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CExitApplicationDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CExitApplicationDialog))
        return static_cast<void*>(const_cast< CExitApplicationDialog*>(this));
    if (!strcmp(_clname, "Ui_CExitApplicationBaseDialog"))
        return static_cast< Ui_CExitApplicationBaseDialog*>(const_cast< CExitApplicationDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int CExitApplicationDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
