/****************************************************************************
** Meta object code from reading C++ file 'headerdownloadprogressdlg.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../headerdownloadprogressdlg.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'headerdownloadprogressdlg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CHeaderDownloadProgressDialog[] = {

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
      31,   30,   30,   30, 0x09,
      54,   30,   30,   30, 0x09,
      80,   30,   30,   30, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_CHeaderDownloadProgressDialog[] = {
    "CHeaderDownloadProgressDialog\0\0"
    "pushbuttonok_clicked()\0pushbuttonpause_clicked()\0"
    "pushbuttoncancel_clicked()\0"
};

void CHeaderDownloadProgressDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CHeaderDownloadProgressDialog *_t = static_cast<CHeaderDownloadProgressDialog *>(_o);
        switch (_id) {
        case 0: _t->pushbuttonok_clicked(); break;
        case 1: _t->pushbuttonpause_clicked(); break;
        case 2: _t->pushbuttoncancel_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData CHeaderDownloadProgressDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CHeaderDownloadProgressDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_CHeaderDownloadProgressDialog,
      qt_meta_data_CHeaderDownloadProgressDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CHeaderDownloadProgressDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CHeaderDownloadProgressDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CHeaderDownloadProgressDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CHeaderDownloadProgressDialog))
        return static_cast<void*>(const_cast< CHeaderDownloadProgressDialog*>(this));
    if (!strcmp(_clname, "Ui_CHeaderDownloadProgressBaseDialog"))
        return static_cast< Ui_CHeaderDownloadProgressBaseDialog*>(const_cast< CHeaderDownloadProgressDialog*>(this));
    if (!strcmp(_clname, "CHeaderDownloadProgressCallback"))
        return static_cast< CHeaderDownloadProgressCallback*>(const_cast< CHeaderDownloadProgressDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int CHeaderDownloadProgressDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
