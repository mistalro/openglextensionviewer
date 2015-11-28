/****************************************************************************
** Meta object code from reading C++ file 'aboutdlg.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../aboutdlg.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'aboutdlg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CAboutDialog[] = {

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
      14,   13,   13,   13, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_CAboutDialog[] = {
    "CAboutDialog\0\0pushbuttonok_clicked()\0"
};

void CAboutDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CAboutDialog *_t = static_cast<CAboutDialog *>(_o);
        switch (_id) {
        case 0: _t->pushbuttonok_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData CAboutDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CAboutDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_CAboutDialog,
      qt_meta_data_CAboutDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CAboutDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CAboutDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CAboutDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CAboutDialog))
        return static_cast<void*>(const_cast< CAboutDialog*>(this));
    if (!strcmp(_clname, "Ui_CAboutBaseDialog"))
        return static_cast< Ui_CAboutBaseDialog*>(const_cast< CAboutDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int CAboutDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
