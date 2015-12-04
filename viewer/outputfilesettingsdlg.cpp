// ---------------------------------------------------------------------------
// Copyright: (C) VFX Research 2002 - 2014. All Rights Reserved.
// ---------------------------------------------------------------------------

#include "config.h"
#include "outputfilesettingsdlg.h"
#include "extensionlib.h"
#include "qlineedit.h"
#include "qradiobutton.h"
#include "qfiledialog.h"
#include "qstring.h"

// --------------------------------------------------------------------------
// Load the current configuration settings
// --------------------------------------------------------------------------

void COutputFileSettingsDialog::LoadSettings( void )
{
m_localconfig = m_pextcreator->m_outputfilesettings;
m_scriptmode  = m_pextcreator->m_scriptsettings.m_scriptmode;
}

// --------------------------------------------------------------------------
// Save the current configuration settings
// --------------------------------------------------------------------------

void COutputFileSettingsDialog::SaveSettings( void )
{
m_pextcreator->m_outputfilesettings          = m_localconfig;
m_pextcreator->m_scriptsettings.m_scriptmode = m_scriptmode;
}

// --------------------------------------------------------------------------
// Set the pointer to the global data
// --------------------------------------------------------------------------

void COutputFileSettingsDialog::SetPointer( CExtensionViewer *pextcreator )
{
m_pextcreator = pextcreator;

LoadSettings();
SetDialogData();
};

// --------------------------------------------------------------------------
// Script files
// --------------------------------------------------------------------------

void COutputFileSettingsDialog::SetScriptFiles( void )
{
m_radiointernal->setChecked( !m_scriptmode );
m_radioexternal->setChecked( m_scriptmode );
m_editexternalscript->setText( m_localconfig.m_scriptfile.data() );
m_editexternalscript->setEnabled( m_scriptmode );
}

// --------------------------------------------------------------------------
// Output files
// --------------------------------------------------------------------------

void COutputFileSettingsDialog::SetOutputFiles( void )
{
m_editoutputheaderfile->setText( m_localconfig.m_outputheaderfile.data() );
m_editoutputsourcefile->setText( m_localconfig.m_outputsourcefile.data() );
m_editoutputclassname->setText( m_localconfig.m_classname.data() );
m_radioc->setChecked( !m_localconfig.m_cppmode );
m_radiocpp->setChecked( m_localconfig.m_cppmode );
m_radiouseglxprocaddressarb->setChecked( m_localconfig.m_useglxgetprocaddressARB );
}

// --------------------------------------------------------------------------
// Set All Files
// --------------------------------------------------------------------------

void COutputFileSettingsDialog::SetDialogData( void)
{
SetScriptFiles();
SetOutputFiles();
}

// ==========================================================================
// SHARED MENU OPTIONS
// ==========================================================================

// --------------------------------------------------------------------------
// OK button was pressed, so make changes
// --------------------------------------------------------------------------
 
void COutputFileSettingsDialog::pushbuttonok_clicked()
{
SaveSettings();
done( OUTPUTFILESETTINGS_OK );
}

// --------------------------------------------------------------------------
// Handle pushbutton APPLY event
// --------------------------------------------------------------------------

void COutputFileSettingsDialog::pushbuttonapply_clicked()
{
SaveSettings();
}

// --------------------------------------------------------------------------
// Cancel button was pressed, so make no changes
// --------------------------------------------------------------------------

void COutputFileSettingsDialog::pushbuttoncancel_clicked()
{
done( OUTPUTFILESETTINGS_CANCEL ); // No change
}

// --------------------------------------------------------------------------
// Reset button was pressed, so restore changes
// --------------------------------------------------------------------------

void COutputFileSettingsDialog::pushbuttonreset_clicked()
{
LoadSettings();
SetDialogData();
}

// --------------------------------------------------------------------------
// SCRIPT FILE OPTIONS
// --------------------------------------------------------------------------

void COutputFileSettingsDialog::pushbuttonexternalbrowse_clicked()
{
QFileDialog filedlg;
QString     filepath;

filepath = filedlg.getOpenFileName(
	".",
	"External script file (*.txt)",
	this,
	"Select script file",
	"Choose script file" );

if ( filepath.ascii() != NULL )
	{
	cout <<"Selected header file = " << (char *) filepath.ascii() << endl;

	m_localconfig.SetScriptfile( (char *) filepath.ascii() );
	m_editexternalscript->setText( filepath );
	}
}

void COutputFileSettingsDialog::editexternalscript_textChanged(
						 const QString &strdata ) 
{
string strpath;

strpath = strdata.ascii();

m_localconfig.SetScriptfile( strpath );
}

void COutputFileSettingsDialog::SetScriptMode( int mode )
{
if ( m_blockupdates == 0 )
	{
	m_blockupdates = 1;

	m_radiointernal->setChecked( !mode );
	m_radioexternal->setChecked( mode );

	m_editexternalscript->setEnabled( mode );
	m_blockupdates = 0;
	}
}

void COutputFileSettingsDialog::radiointernal_clicked()
{
SetScriptMode( 0 );
}

void COutputFileSettingsDialog::radioexternal_clicked()
{
SetScriptMode( 1 );
}

// ==========================================================================
// OUTPUT FILE OPTIONS
// ==========================================================================

void COutputFileSettingsDialog::pushbuttonheaderbrowse_clicked()
{
QFileDialog filedlg;
QString     filepath;

filepath = filedlg.getSaveFileName(
	".",
	"Output header file (*.h)",
	this,
	"Select header file",
	"Choose header file" );

if ( filepath.ascii() != NULL )
	{
	cout << "Selected header file = " << (char *) filepath.ascii() << endl;

	m_localconfig.SetOutputheader( (char *) filepath.ascii() );
	m_editoutputheaderfile->setText( filepath );
	}
}

void COutputFileSettingsDialog::pushbuttonsourcebrowse_clicked()
{
QFileDialog filedlg;
QString     filepath;

filepath = filedlg.getOpenFileName(
	".",
	"Output source file (*.h)",
	this,
	"Select source file",
	"Choose source file" );

if ( filepath.ascii() != NULL )
	{
	cout << "Selected source file = " << (char *) filepath.ascii() << endl;

	m_localconfig.SetOutputsource( (char *) filepath.ascii() );
	m_editoutputsourcefile->setText( filepath );
	}
}

void COutputFileSettingsDialog::SetProgrammingLanguage( int mode )
{
if ( m_blockupdates == 0 )
	{
	m_blockupdates = 1;

	m_radioc->setChecked( (mode==0) );
	m_radiocpp->setChecked( (mode==1) );

	m_localconfig.m_cppmode = mode;
	m_blockupdates = 0;
	}
}

void COutputFileSettingsDialog::radioc_clicked()
{
SetProgrammingLanguage( 0 );
}

void COutputFileSettingsDialog::radiocpp_clicked()
{
SetProgrammingLanguage( 1 );
}

void COutputFileSettingsDialog::radiouseglxgetprocaddressarb_clicked()
{
m_localconfig.m_useglxgetprocaddressARB = m_radiouseglxprocaddressarb->isChecked();
}

void COutputFileSettingsDialog::editoutputheaderfile_textChanged( 
						const QString &string )
{
m_localconfig.SetOutputheader( (char *) string.ascii() );
}

void COutputFileSettingsDialog::editoutputsourcefile_textChanged( 
						const QString &string )
{
m_localconfig.SetOutputsource( (char *) string.ascii() );
}

void COutputFileSettingsDialog::editoutputclassname_textChanged( 
						const QString &string )
{
m_localconfig.SetClassname( (char *) string.ascii() );
}
                                                                                
