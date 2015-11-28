/****************************************************************************
** FileChooser meta object code from reading C++ file 'filechooser.h'
**
** Created: Sun Sep 5 02:14:28 2004
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.3   edited Aug 5 16:40 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../../widget/filechooser.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#include <qvariant.h>
const char *FileChooser::className() const
{
    return "FileChooser";
}

QMetaObject *FileChooser::metaObj = 0;
static QMetaObjectCleanUp cleanUp_FileChooser( "FileChooser", &FileChooser::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString FileChooser::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "FileChooser", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString FileChooser::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "FileChooser", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* FileChooser::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QWidget::staticMetaObject();
#ifndef QT_NO_PROPERTIES
    static const QMetaEnum::Item enum_0[] = {
	{ "File",  (int) FileChooser::File },
	{ "Directory",  (int) FileChooser::Directory }
    };
    static const QMetaEnum enum_tbl[] = {
	{ "Mode", 2, enum_0, FALSE }
    };
#endif // QT_NO_PROPERTIES
    static const QUParameter param_slot_0[] = {
	{ "fn", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_0 = {"setFileName", 1, param_slot_0 };
    static const QUParameter param_slot_1[] = {
	{ "m", &static_QUType_enum, 
#ifndef QT_NO_PROPERTIES
	  &enum_tbl[0]
#else
	  0
#endif // QT_NO_PROPERTIES
	  , QUParameter::In }
    };
    static const QUMethod slot_1 = {"setMode", 1, param_slot_1 };
    static const QUMethod slot_2 = {"chooseFile", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "setFileName(const QString&)", &slot_0, QMetaData::Public },
	{ "setMode(Mode)", &slot_1, QMetaData::Public },
	{ "chooseFile()", &slot_2, QMetaData::Private }
    };
    static const QUParameter param_signal_0[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod signal_0 = {"fileNameChanged", 1, param_signal_0 };
    static const QMetaData signal_tbl[] = {
	{ "fileNameChanged(const QString&)", &signal_0, QMetaData::Public }
    };
#ifndef QT_NO_PROPERTIES
    static const QMetaProperty props_tbl[2] = {
 	{ "Mode","mode", 0x0107, &FileChooser::metaObj, &enum_tbl[0], -1 },
	{ "QString","fileName", 0x3000103, &FileChooser::metaObj, 0, -1 }
    };
#endif // QT_NO_PROPERTIES
    metaObj = QMetaObject::new_metaobject(
	"FileChooser", parentObject,
	slot_tbl, 3,
	signal_tbl, 1,
#ifndef QT_NO_PROPERTIES
	props_tbl, 2,
	enum_tbl, 1,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_FileChooser.setMetaObject( metaObj );
    return metaObj;
}

void* FileChooser::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "FileChooser" ) )
	return this;
    return QWidget::qt_cast( clname );
}

// SIGNAL fileNameChanged
void FileChooser::fileNameChanged( const QString& t0 )
{
    activate_signal( staticMetaObject()->signalOffset() + 0, t0 );
}

bool FileChooser::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: setFileName((const QString&)static_QUType_QString.get(_o+1)); break;
    case 1: setMode((Mode)static_QUType_enum.get(_o+1)); break;
    case 2: chooseFile(); break;
    default:
	return QWidget::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool FileChooser::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: fileNameChanged((const QString&)static_QUType_QString.get(_o+1)); break;
    default:
	return QWidget::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool FileChooser::qt_property( int id, int f, QVariant* v)
{
    switch ( id - staticMetaObject()->propertyOffset() ) {
    case 0: switch( f ) {
	case 0: setMode((Mode&)v->asInt()); break;
	case 1: *v = QVariant( (int)this->mode() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 1: switch( f ) {
	case 0: setFileName(v->asString()); break;
	case 1: *v = QVariant( this->fileName() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    default:
	return QWidget::qt_property( id, f, v );
    }
    return TRUE;
}

bool FileChooser::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
