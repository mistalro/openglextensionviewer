/****************************************************************************
** Meta object code from reading C++ file 'findfuncconstdlg.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../findfuncconstdlg.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'findfuncconstdlg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CFindFuncConstDialog[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      22,   21,   21,   21, 0x0a,
      55,   21,   21,   21, 0x0a,
      88,   21,   21,   21, 0x0a,
     114,   21,   21,   21, 0x0a,
     137,   21,   21,   21, 0x0a,
     175,   21,   21,   21, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_CFindFuncConstDialog[] = {
    "CFindFuncConstDialog\0\0"
    "pushbuttonfindconstant_clicked()\0"
    "pushbuttonfindfunction_clicked()\0"
    "pushbuttonclear_clicked()\0"
    "pushbuttonok_clicked()\0"
    "lineeditconstant_textChanged(QString)\0"
    "lineeditfunction_textChanged(QString)\0"
};

void CFindFuncConstDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CFindFuncConstDialog *_t = static_cast<CFindFuncConstDialog *>(_o);
        switch (_id) {
        case 0: _t->pushbuttonfindconstant_clicked(); break;
        case 1: _t->pushbuttonfindfunction_clicked(); break;
        case 2: _t->pushbuttonclear_clicked(); break;
        case 3: _t->pushbuttonok_clicked(); break;
        case 4: _t->lineeditconstant_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->lineeditfunction_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData CFindFuncConstDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CFindFuncConstDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_CFindFuncConstDialog,
      qt_meta_data_CFindFuncConstDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CFindFuncConstDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CFindFuncConstDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CFindFuncConstDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CFindFuncConstDialog))
        return static_cast<void*>(const_cast< CFindFuncConstDialog*>(this));
    if (!strcmp(_clname, "Ui_CFindFuncConstBaseDialog"))
        return static_cast< Ui_CFindFuncConstBaseDialog*>(const_cast< CFindFuncConstDialog*>(this));
    if (!strcmp(_clname, "CHeaderFileDataSearchCallback"))
        return static_cast< CHeaderFileDataSearchCallback*>(const_cast< CFindFuncConstDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int CFindFuncConstDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
