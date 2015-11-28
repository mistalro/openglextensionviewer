/****************************************************************************
** Meta object code from reading C++ file 'scripteditordlg.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../scripteditordlg.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'scripteditordlg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CScriptEditorDialog[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      21,   20,   20,   20, 0x09,
      46,   20,   20,   20, 0x09,
      71,   20,   20,   20, 0x09,
      97,   20,   20,   20, 0x09,
     125,   20,   20,   20, 0x09,
     152,   20,   20,   20, 0x09,
     178,   20,   20,   20, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_CScriptEditorDialog[] = {
    "CScriptEditorDialog\0\0pushbuttoncopy_clicked()\0"
    "pushbuttonsave_clicked()\0"
    "pushbuttonclear_clicked()\0"
    "pushbuttonrestore_clicked()\0"
    "pushbuttoncancel_clicked()\0"
    "pushbuttonapply_clicked()\0"
    "pushbuttonok_clicked()\0"
};

void CScriptEditorDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CScriptEditorDialog *_t = static_cast<CScriptEditorDialog *>(_o);
        switch (_id) {
        case 0: _t->pushbuttoncopy_clicked(); break;
        case 1: _t->pushbuttonsave_clicked(); break;
        case 2: _t->pushbuttonclear_clicked(); break;
        case 3: _t->pushbuttonrestore_clicked(); break;
        case 4: _t->pushbuttoncancel_clicked(); break;
        case 5: _t->pushbuttonapply_clicked(); break;
        case 6: _t->pushbuttonok_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData CScriptEditorDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CScriptEditorDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_CScriptEditorDialog,
      qt_meta_data_CScriptEditorDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CScriptEditorDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CScriptEditorDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CScriptEditorDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CScriptEditorDialog))
        return static_cast<void*>(const_cast< CScriptEditorDialog*>(this));
    if (!strcmp(_clname, "Ui_CScriptEditorBaseDialog"))
        return static_cast< Ui_CScriptEditorBaseDialog*>(const_cast< CScriptEditorDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int CScriptEditorDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
