// ---------------------------------------------------------------------------
// Copyright: (C) VFX Research 2002 - 2014. All Rights Reserved.
// ---------------------------------------------------------------------------

#include "config.h"
#include "registrysettingsdlg.h"
#include "registryaddsitedlg.h"

#include "extensionlib.h"
#include <webpagelistwidget/webpagelistwidget.h>
#include "qlineedit.h"
#include "qradiobutton.h"
#include "qfiledialog.h"
#include "qstring.h"
#include "qcheckbox.h"

//#define DEBUG

#ifdef DEBUG
#define TRACE() \
	{ cout << __FILE__ << ":" << __func__ << ":" << __LINE__ << endl; }

#define TRACE_STR(str) \
	{ cout << str << __FILE__ << ":" << __func__ << ":" << __LINE__ << endl; }
#else
#define TRACE() 
#define TRACE_STR(str) 
#endif

// --------------------------------------------------------------------------
// Load the current configuration settings
// --------------------------------------------------------------------------

void CRegistrySettingsDialog::LoadSettings( void )
{
TRACE();

m_localconfig.Duplicate( m_pextcreator->m_sitelist );
}

// --------------------------------------------------------------------------
// Save the current configuration settings
// --------------------------------------------------------------------------

void CRegistrySettingsDialog::SaveSettings( void )
{
TRACE();
m_pextcreator->m_sitelist.Duplicate( m_localconfig );
}

// --------------------------------------------------------------------------
// Set the pointer to the global data
// --------------------------------------------------------------------------

void CRegistrySettingsDialog::SetPointer( CExtensionViewer *pextcreator )
{
m_pextcreator = pextcreator;

TRACE();
LoadSettings();

m_webpagelistview->SetPointer( &m_localconfig );

SetDialogData();
};

// --------------------------------------------------------------------------
// Set the status of each check box
// --------------------------------------------------------------------------

void CRegistrySettingsDialog::SetCheckBoxes( void )
{
CExtensionSiteInfo *psiteinfo;
int flags;

TRACE();
psiteinfo = m_localconfig.GetSiteInfo( m_listpos );

if ( psiteinfo )
	{
	flags = psiteinfo->GetFlags( FLAG_READHEADERFILES );
	m_checkboxreadheaderfiles->setChecked( flags );

	flags = psiteinfo->GetFlags( FLAG_DOWNLOADHEADERFILES );
	m_checkboxdownloadheaderfiles->setChecked( flags );

	flags = psiteinfo->GetFlags( FLAG_READEXTENSIONSPEC );
	m_checkboxreadextensionspec->setChecked( flags );

	flags = psiteinfo->GetFlags( FLAG_DOWNLOADREGISTRY );
	m_checkboxdownloadregistry->setChecked( flags );
	}
else
	{
	m_checkboxreadextensionspec->setChecked(   false );
	m_checkboxreadheaderfiles->setChecked(     false );
	m_checkboxdownloadregistry->setChecked(    false );
	m_checkboxdownloadheaderfiles->setChecked( false );

	m_checkboxreadextensionspec->setEnabled(   false );
	m_checkboxreadheaderfiles->setEnabled(     false );
	m_checkboxdownloadregistry->setEnabled(    false );
	m_checkboxdownloadheaderfiles->setEnabled( false );
	}
}

// --------------------------------------------------------------------------
// Set the contents of the list view box from the site list
// --------------------------------------------------------------------------

void CRegistrySettingsDialog::SetSiteList( void )
{
TRACE();

m_webpagelistview->SetPointer( &m_localconfig );
m_webpagelistview->SetAllItems();
}

// --------------------------------------------------------------------------
// OpenGL Registry directory and documents
// --------------------------------------------------------------------------

void CRegistrySettingsDialog::SetInputFilesRegistry( void )
{
CExtensionSiteInfo *psiteinfo;
                                                                                
TRACE();
psiteinfo = m_localconfig.GetSiteInfo( m_listpos );
        
if ( psiteinfo ) 
	{
	m_editregistrylocaldir->setText( psiteinfo->GetIndexdirlocal().data() );
	m_editregistry->setText(          psiteinfo->GetIndexpagenet().data() );
	m_editregistrylocalcopy->setText( psiteinfo->GetIndexpagelocal().data() );
	m_lineeditfileextensionfilter->setText( psiteinfo->GetFiletypefilters().data() );
	}
else
	{
	m_editregistrylocaldir->setText( "" );
	m_editregistrylocaldir->setEnabled( false );

	m_editregistry->setText( "" );
	m_editregistry->setEnabled( false );
	
	m_editregistrylocalcopy->setText( "" );
	m_editregistrylocalcopy->setEnabled( false );

	m_lineeditfileextensionfilter->setText( "" );
	}
}

// --------------------------------------------------------------------------
// GL Extension header file
// --------------------------------------------------------------------------

void CRegistrySettingsDialog::SetInputFilesGL( void )
{
std::string strbuf;
int  version;

CExtensionSiteInfo *psiteinfo;
                                                                                
TRACE();
psiteinfo = m_localconfig.GetSiteInfo( m_listpos );
        
if ( psiteinfo )
	{
	m_editgl->setText(          psiteinfo->GetGlheadernet().data() );
	m_editgllocalcopy->setText( psiteinfo->GetGlheaderlocal().data() );

	version = m_pextcreator->m_headerfileset.m_gllist.m_version;

	if ( version == -1 )
		{
		strbuf = "Unknown";
		}
	else
		{
		stl_itoa( strbuf, version );
		}

	m_editglversion->setText( strbuf.data() );

	stl_itoa( strbuf, 
		m_pextcreator->m_headerfileset.m_gllist.m_extlist.GetCount() );

	m_editglcount->setText( strbuf.data() ); 
	}
else
	{
	m_editglversion->setText( "" );
	m_editglversion->setEnabled( false );

	m_editgl->setText( "" );
	m_editgl->setEnabled( false );

	m_editgllocalcopy->setText( "" );
	m_editgllocalcopy->setEnabled( false );

	m_editglcount->setText( "" );
	m_editglcount->setEnabled( false );
	}
}

// --------------------------------------------------------------------------
// WGL Extension header file 
// --------------------------------------------------------------------------

void CRegistrySettingsDialog::SetInputFilesWGL( void )
{
int  version;
CExtensionSiteInfo *psiteinfo;
std::string strbuf;
                                                                
TRACE();
psiteinfo = m_localconfig.GetSiteInfo( m_listpos );
        
if ( psiteinfo )
	{ 
	m_editwgl->setText(          psiteinfo->GetWglheadernet().data() );
	m_editwgllocalcopy->setText( psiteinfo->GetWglheaderlocal().data() );

	version = m_pextcreator->m_headerfileset.m_wgllist.m_version; 

	if ( version == -1 )
		{
		strbuf = "Unknown";
		}
	else
		{
		stl_itoa( strbuf, version );
		}

	m_editwglversion->setText( strbuf.data() );

	stl_itoa( strbuf, 
		m_pextcreator->m_headerfileset.m_wgllist.m_extlist.GetCount() );

	m_editwglcount->setText( strbuf.data() ); 
	}
else
	{
	m_editwglversion->setText( "" );
	m_editwglversion->setEnabled( false );

	m_editwgl->setText( "" );
	m_editwgl->setEnabled( false );

	m_editwgllocalcopy->setText( "" );
	m_editwgllocalcopy->setEnabled( false );

	m_editwglcount->setText( "" );
	m_editwglcount->setEnabled( false );
	}
}

// --------------------------------------------------------------------------
// GLX Extension header file 
// --------------------------------------------------------------------------

void CRegistrySettingsDialog::SetInputFilesGLX( void )
{
std::string strbuf;
int  version;
CExtensionSiteInfo *psiteinfo;
                                                                                
TRACE();
psiteinfo = m_localconfig.GetSiteInfo( m_listpos );
        
if ( psiteinfo )
	{
	m_editglx->setText(          psiteinfo->GetGlxheadernet().data() );
	m_editglxlocalcopy->setText( psiteinfo->GetGlxheaderlocal().data() );
                                                                                
	version = m_pextcreator->m_headerfileset.m_glxlist.m_version;

	if ( version == -1 )
		{
		strbuf = "Unknown";
		}
	else
		{
		stl_itoa( strbuf, version );
		}

	m_editglxversion->setText( strbuf.data() );

	stl_itoa( strbuf, m_pextcreator->m_headerfileset.m_glxlist.m_extlist.GetCount() );

	m_editglxcount->setText( strbuf.data() );
	}
else
	{
	m_editglxversion->setText( "" );
	m_editglxversion->setEnabled( false );

	m_editglx->setText( "" );
	m_editglx->setEnabled( false );

	m_editglxlocalcopy->setText( "" );
	m_editglxlocalcopy->setEnabled( false );

	m_editglxcount->setText( "" );
	m_editglxcount->setEnabled( false );
	}
}

// --------------------------------------------------------------------------
// Core ARB Extension header file 
// --------------------------------------------------------------------------

void CRegistrySettingsDialog::SetInputFilesCoreARB( void )
{
std::string strbuf;
int  version;
CExtensionSiteInfo *psiteinfo;

TRACE();
psiteinfo = m_localconfig.GetSiteInfo( m_listpos );

if ( psiteinfo )
        {
        m_editcorearb->setText(          psiteinfo->GetCoreheadernet().data() );
        m_editcorearblocalcopy->setText( psiteinfo->GetCoreheaderlocal().data() );

        version = m_pextcreator->m_headerfileset.m_corearblist.m_version;

        if ( version == -1 )
                {
                strbuf = "Unknown";
                }
        else
                {
                stl_itoa( strbuf, version );
                }

        m_editcorearbversion->setText( strbuf.data() );

        stl_itoa( strbuf, m_pextcreator->m_headerfileset.m_corearblist.m_extlist.GetCount() );

        m_editcorearbcount->setText( strbuf.data() );
        }
else
        {
        m_editcorearbversion->setText( "" );
        m_editcorearbversion->setEnabled( false );

        m_editcorearb->setText( "" );
        m_editcorearb->setEnabled( false );

        m_editcorearblocalcopy->setText( "" );
        m_editcorearblocalcopy->setEnabled( false );

        m_editcorearbcount->setText( "" );
        m_editcorearbcount->setEnabled( false );
        }
}

// --------------------------------------------------------------------------
// Set All Files
// --------------------------------------------------------------------------

void CRegistrySettingsDialog::SetDialogData( void)
{
TRACE();

SetSiteList();

SetCheckBoxes();
SetInputFilesRegistry();
SetInputFilesGL();
SetInputFilesWGL();
SetInputFilesGLX();
SetInputFilesCoreARB();
}

// ==========================================================================
// SHARED MENU OPTIONS
// ==========================================================================

// --------------------------------------------------------------------------
// OK button was pressed, so make changes
// --------------------------------------------------------------------------
 
void CRegistrySettingsDialog::pushbuttonok_clicked()
{
TRACE();

SaveSettings();
done( REGISTRYSETTINGS_OK );
}

// --------------------------------------------------------------------------
// Handle pushbutton APPLY event
// --------------------------------------------------------------------------

void CRegistrySettingsDialog::pushbuttonapply_clicked()
{
TRACE();

SaveSettings();
}

// --------------------------------------------------------------------------
// Cancel button was pressed, so make no changes
// --------------------------------------------------------------------------

void CRegistrySettingsDialog::pushbuttoncancel_clicked()
{
TRACE();

done( REGISTRYSETTINGS_CANCEL ); // No change
}

// --------------------------------------------------------------------------
// Reset button was pressed, so restore changes - Alternatively restore
// --------------------------------------------------------------------------

void CRegistrySettingsDialog::pushbuttonreset_clicked()
{
TRACE();

LoadSettings();
SetDialogData();
}

// --------------------------------------------------------------------------
// Add button was pressed, so pop up an add registry dialog window
// --------------------------------------------------------------------------

void CRegistrySettingsDialog::pushbuttonadd_clicked()
{
CRegistryAddSiteDialog addsitedlg;

TRACE();

addsitedlg.SetPointer( &m_localconfig );
addsitedlg.SetUpdateList( this );
addsitedlg.exec();

SetDialogData();
}

// --------------------------------------------------------------------------
// Remove button was pressed
// --------------------------------------------------------------------------

void CRegistrySettingsDialog::pushbuttonremove_clicked()
{
TRACE();

m_localconfig.Delete( m_listpos );

if ( m_listpos >= m_localconfig.GetCount() )
	{
	m_listpos --;
	}

if ( m_listpos < 0 )
	{
	m_listpos = 0;
	}

SetDialogData();
}

// --------------------------------------------------------------------------
// Core ARB button was clicked
// --------------------------------------------------------------------------

void CRegistrySettingsDialog::pushbuttoncorearb_clicked()
{
TRACE();

SetDialogData();
}

// ==========================================================================
// INPUT FILE OPTIONS
// ==========================================================================

// --------------------------------------------------------------------------
// Browse for the registry web page
// --------------------------------------------------------------------------

void CRegistrySettingsDialog::pushbuttonregistrywebpagebrowse_clicked()
{
QFileDialog filedlg;
QString     filepath;
CExtensionSiteInfo *psiteinfo;

TRACE();
                                                                                
filepath = filedlg.getSaveFileName(
        ".",
        "Index web page (*.html)",
        this,
        "Select html file",
        "Choose html file" );
                                                                                
if ( filepath.ascii() != NULL )
        {
        psiteinfo = m_localconfig.GetSiteInfo( m_listpos );
                                                                                
        psiteinfo->SetIndexpagelocal( (char *) filepath.ascii() );
                                                                                
        m_editregistrylocalcopy->setText( filepath );
        }
}

// --------------------------------------------------------------------------
// Browse for the registry local directory
// --------------------------------------------------------------------------

void CRegistrySettingsDialog::pushbuttonregistrylocaldirbrowse_clicked()
{
QFileDialog filedlg;
QString     filepath;
CExtensionSiteInfo *psiteinfo;

TRACE();

filedlg.setMode( QFileDialog::DirectoryOnly );
filedlg.setFilter( "Directories (*.*)" );

filepath = filedlg.getSaveFileName( 
	".",
	"Directory files (*.*)",
	this,
	"Select Directory Dialog",
	"Choose destination directory" );

if( filepath.ascii() != NULL )
	{
   	psiteinfo = m_localconfig.GetSiteInfo( m_listpos );
                                                                                
        psiteinfo->SetIndexdirlocal( (char *) filepath.ascii() );

        m_editregistrylocaldir->setText( filepath );
	}
}

// --------------------------------------------------------------------------
// Browse for registry file
// --------------------------------------------------------------------------

void CRegistrySettingsDialog::pushbuttonregistrybrowse_clicked( void )
{
QFileDialog filedlg;
QString     filepath;
CExtensionSiteInfo *psiteinfo;

TRACE();

if ( filepath.ascii() != NULL )
	{
        psiteinfo = m_localconfig.GetSiteInfo( m_listpos );

	psiteinfo->SetIndexpagenet( (char *) filepath.ascii() );

	m_editregistry->setText( filepath );
	}
}

// --------------------------------------------------------------------------
// Browse for the GLX header file
// --------------------------------------------------------------------------

void CRegistrySettingsDialog::pushbuttonglxbrowse_clicked( void )
{
QFileDialog filedlg;
QString     filepath;
CExtensionSiteInfo *psiteinfo;

TRACE();

filepath = filedlg.getSaveFileName(
	".",
	"Header files (*.h)",
	this,
	"Select header file",
	"Choose header file" );

if ( filepath.ascii() != NULL ) 
	{
        psiteinfo = m_localconfig.GetSiteInfo( m_listpos );
                                                                                
        psiteinfo->SetGlxheaderlocal( (char *) filepath.ascii() );
                                                                                
        m_editglxlocalcopy->setText( filepath );
	}
}

// --------------------------------------------------------------------------
// Browse for the GL header file
// --------------------------------------------------------------------------

void CRegistrySettingsDialog::pushbuttonglbrowse_clicked()
{
QFileDialog filedlg;
QString     filepath;
CExtensionSiteInfo *psiteinfo;

TRACE();

filepath = filedlg.getSaveFileName(
	".",
	"Header files (*.h)",
	this,
	"Select header file",
	"Choose header file" );

if ( filepath.ascii() != NULL )
	{
        psiteinfo = m_localconfig.GetSiteInfo( m_listpos );
                                                                                
        psiteinfo->SetGlheaderlocal( (char *) filepath.ascii() );
                                                                                
        m_editgllocalcopy->setText( filepath );
	}
}

// --------------------------------------------------------------------------
// Browse for the GL header file
// --------------------------------------------------------------------------

void CRegistrySettingsDialog::pushbuttonwglbrowse_clicked()
{
QFileDialog filedlg;
QString     filepath;
CExtensionSiteInfo *psiteinfo;

TRACE();

filepath = filedlg.getSaveFileName(
        ".",
        "Header files (*.h)",
        this,
        "Select header file",
        "Choose header file" );

if ( filepath.ascii() != NULL )
        {
        psiteinfo = m_localconfig.GetSiteInfo( m_listpos );

        psiteinfo->SetWglheaderlocal( (char *) filepath.ascii() );

        m_editwgllocalcopy->setText( filepath );
        }
}

// --------------------------------------------------------------------------
// Registry local directory has changed
// --------------------------------------------------------------------------

void CRegistrySettingsDialog::editregistrylocaldir_textChanged( const QString &string )
{
CExtensionSiteInfo *psiteinfo;

TRACE();

psiteinfo = m_localconfig.GetSiteInfo( m_listpos );

if ( psiteinfo && string.ascii() )
	{
	psiteinfo->SetIndexdirlocal( (char *) string.ascii() );
	SetSiteList();
	}
}

// --------------------------------------------------------------------------
// Registry web page net has changed
// --------------------------------------------------------------------------

void CRegistrySettingsDialog::editregistry_textChanged( const QString &string )
{
CExtensionSiteInfo *psiteinfo;
                                                                                
TRACE();

psiteinfo = m_localconfig.GetSiteInfo( m_listpos );

if ( psiteinfo && string.ascii() )
	{
	psiteinfo->SetIndexpagenet( (char *) string.ascii() );
	SetSiteList();
	}
}

// --------------------------------------------------------------------------
// Registry web page local copy has changed
// --------------------------------------------------------------------------

void CRegistrySettingsDialog::editregistrylocalcopy_textChanged( 
						const QString &string )
{
CExtensionSiteInfo *psiteinfo;
                                                                                
TRACE();

psiteinfo = m_localconfig.GetSiteInfo( m_listpos );
        
if ( psiteinfo && string.ascii() )
	{
	psiteinfo->SetIndexpagelocal( (char *) string.ascii() );
	SetSiteList();
	}
}

// --------------------------------------------------------------------------
// GL header file web link has changed
// --------------------------------------------------------------------------

void CRegistrySettingsDialog::editgl_textChanged( const QString &string )
{
CExtensionSiteInfo *psiteinfo;
                                                                                
TRACE();

psiteinfo = m_localconfig.GetSiteInfo( m_listpos );

if ( psiteinfo && string.ascii() )
	{
	psiteinfo->SetGlheadernet( (char *) string.ascii() );
	SetSiteList();
	}
}

// --------------------------------------------------------------------------
// GL header file local copy has changed
// --------------------------------------------------------------------------

void CRegistrySettingsDialog::editgllocalcopy_textChanged( const QString &string )
{
CExtensionSiteInfo *psiteinfo;
                                                                                
TRACE();

psiteinfo = m_localconfig.GetSiteInfo( m_listpos );
        
if ( psiteinfo && string.ascii() )
	{
	psiteinfo->SetGlheaderlocal( (char *) string.ascii() );
	SetSiteList();
	}
}

// --------------------------------------------------------------------------
// WGL header file web link has changed
// --------------------------------------------------------------------------

void CRegistrySettingsDialog::editwgl_textChanged( const QString &string )
{
CExtensionSiteInfo *psiteinfo;

TRACE();
                                                                                
psiteinfo = m_localconfig.GetSiteInfo( m_listpos );
        
if ( psiteinfo && string.ascii() )
	{
	psiteinfo->SetWglheadernet( (char *) string.ascii() );
	SetSiteList();
	}
}

// --------------------------------------------------------------------------
// WGL header file local copy has changed
// --------------------------------------------------------------------------

void CRegistrySettingsDialog::editwgllocalcopy_textChanged( const QString &string )
{
CExtensionSiteInfo *psiteinfo;
                                                                                
TRACE();

psiteinfo = m_localconfig.GetSiteInfo( m_listpos );
        
if ( psiteinfo && string.ascii() )
	{
	psiteinfo->SetWglheaderlocal( (char *) string.ascii() );
	SetSiteList();
	}
}

// --------------------------------------------------------------------------
// GLX header file web link has changed
// --------------------------------------------------------------------------

void CRegistrySettingsDialog::editglx_textChanged( const QString &string )
{
CExtensionSiteInfo *psiteinfo;
                                                                                
TRACE();

psiteinfo = m_localconfig.GetSiteInfo( m_listpos );
        
if ( psiteinfo && string.ascii() )
	{
	psiteinfo->SetGlxheadernet( (char *) string.ascii() );
	SetSiteList();
	}
}

// --------------------------------------------------------------------------
// WGL header file local copy has changed
// --------------------------------------------------------------------------

void CRegistrySettingsDialog::editglxlocalcopy_textChanged( 
						const QString &string )
{
CExtensionSiteInfo *psiteinfo;

TRACE();

psiteinfo = m_localconfig.GetSiteInfo( m_listpos );
        
if ( psiteinfo && string.ascii() )
	{
	psiteinfo->SetGlxheaderlocal( (char *) string.ascii() );
	SetSiteList();
	}
}

// --------------------------------------------------------------------------
// CORE ARB header file web link has changed
// --------------------------------------------------------------------------

void CRegistrySettingsDialog::editcorearb_textChanged( const QString &string)
{
CExtensionSiteInfo *psiteinfo;
                                                                                
TRACE();

psiteinfo = m_localconfig.GetSiteInfo( m_listpos );
        
if ( psiteinfo && string.ascii() )
	{
	psiteinfo->SetCoreheadernet( (char *) string.ascii() );
	SetSiteList();
	}
}

// --------------------------------------------------------------------------
// CORE ARB header file local copy
// --------------------------------------------------------------------------

void CRegistrySettingsDialog::editcorearblocalcopy_textChanged( const QString &string)
{
CExtensionSiteInfo *psiteinfo;
 
TRACE();

psiteinfo = m_localconfig.GetSiteInfo( m_listpos );

if ( psiteinfo && string.ascii() )
        {
        psiteinfo->SetCoreheaderlocal( (char *) string.ascii() );
        SetSiteList();
        }
}

// --------------------------------------------------------------------------
// File extension filter changed
// --------------------------------------------------------------------------

void CRegistrySettingsDialog::editfileextensionfilter_textChanged( const QString &string)
{
CExtensionSiteInfo *psiteinfo;

TRACE();

psiteinfo = m_localconfig.GetSiteInfo( m_listpos );

if ( psiteinfo && string.ascii() )
        {
	psiteinfo->SetFiletypefilters( (char *) string.ascii() );
	SetSiteList();	
	}
}

// --------------------------------------------------------------------------
// Check box for downloading from server was toggled
// --------------------------------------------------------------------------

void CRegistrySettingsDialog::checkboxdownloadregistry_toggled( bool value )
{
CExtensionSiteInfo *psiteinfo;

TRACE();

psiteinfo = m_localconfig.GetSiteInfo( m_listpos );

if ( psiteinfo )
	{
	if ( value )	
		{
		psiteinfo->SetFlags( FLAG_DOWNLOADREGISTRY );
		}
	else	
		{
		psiteinfo->ClearFlags( FLAG_DOWNLOADREGISTRY );
		}
	}	
}

// --------------------------------------------------------------------------
// Check box for downloading header files from server was toggled
// --------------------------------------------------------------------------

void CRegistrySettingsDialog::checkboxdownloadheaderfiles_toggled( bool value)
{
CExtensionSiteInfo *psiteinfo;

TRACE();

psiteinfo = m_localconfig.GetSiteInfo( m_listpos );

if ( psiteinfo )
	{
	if ( value )	
		{
		psiteinfo->SetFlags( FLAG_DOWNLOADHEADERFILES );
		}
	else	
		{
		psiteinfo->ClearFlags( FLAG_DOWNLOADHEADERFILES );
		}
	}	
}

// --------------------------------------------------------------------------
// Check box for reading header files was toggled
// --------------------------------------------------------------------------

void CRegistrySettingsDialog::checkboxreadheaderfiles_toggled( bool value )
{
CExtensionSiteInfo *psiteinfo;

psiteinfo = m_localconfig.GetSiteInfo( m_listpos );

TRACE();

if ( psiteinfo )
	{
	if ( value )	
		{
		psiteinfo->SetFlags( FLAG_READHEADERFILES );
		}
	else	
		{
		psiteinfo->ClearFlags( FLAG_READHEADERFILES );
		}
	}
}

// --------------------------------------------------------------------------
// Check box for reading extension specifications was toggled
// --------------------------------------------------------------------------

void CRegistrySettingsDialog::checkboxreadextensionspec_toggled( bool value )
{
CExtensionSiteInfo *psiteinfo;

psiteinfo = m_localconfig.GetSiteInfo( m_listpos );

TRACE();

if ( psiteinfo )
	{
	if ( value )	
		{
		psiteinfo->SetFlags( FLAG_READEXTENSIONSPEC );
		}
	else	
		{
		psiteinfo->ClearFlags( FLAG_READEXTENSIONSPEC );
		}
	}
}

// ---------------------------------------------------------------------------
// List view selection changed
// ---------------------------------------------------------------------------
                                                                                
void CRegistrySettingsDialog::webpagelistview_selectionChanged()
{
TRACE();

}

// ---------------------------------------------------------------------------
// List view mouse button pressed
// ---------------------------------------------------------------------------

void CRegistrySettingsDialog::webpagelistview_mousePressed( int item )
{
m_listpos = item;

TRACE();

SetDialogData();
}

// ---------------------------------------------------------------------------
// List view mouse button released
// ---------------------------------------------------------------------------

void CRegistrySettingsDialog::webpagelistview_mouseReleased( int /* item */ )
{
TRACE();

}

// ---------------------------------------------------------------------------
// List view mouse button double clicked
// ---------------------------------------------------------------------------

void CRegistrySettingsDialog::webpagelistview_mouseDoubleClicked( int item )
{
TRACE();

m_listpos = item;

SetDialogData();
}

// ---------------------------------------------------------------------------
// List view mouse button moved
// ---------------------------------------------------------------------------

void CRegistrySettingsDialog::webpagelistview_mouseMoved( int /* item */)
{
TRACE();

// m_listpos = item;
}
