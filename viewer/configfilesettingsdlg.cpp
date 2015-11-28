// ---------------------------------------------------------------------------
// Copyright: (C) VFX Research 2002 - 2014. All Rights Reserved.
// ---------------------------------------------------------------------------

using namespace std;
                                                                                
#include "config.h"

#include <QRadioButton>
#include <QLineEdit>
#include <QString>
#include <QFileDialog>
#include <QDialog>

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include "extensionlib.h"
#include "configfilesettingsdlg.h"
                                                                                
// --------------------------------------------------------------------------
// Save settings
// --------------------------------------------------------------------------

void CConfigFileSettingsDialog::LoadSettings( void )
{
m_localconfig.Duplicate( m_pextcreator->m_configfilesettings );
}

// --------------------------------------------------------------------------
// Load settings
// --------------------------------------------------------------------------

void CConfigFileSettingsDialog::SaveSettings( void )
{
m_pextcreator->m_configfilesettings.Duplicate( m_localconfig );
}

// --------------------------------------------------------------------------
// Set application pointer
// --------------------------------------------------------------------------

void CConfigFileSettingsDialog::SetPointer( CExtensionViewer *pextcreator )
{
m_pextcreator = pextcreator;

LoadSettings();

SetDialogData();
}

// --------------------------------------------------------------------------
// Set load radio buttons
// --------------------------------------------------------------------------

void CConfigFileSettingsDialog::SetLoadRadioButtons( void )
{
int state; 

state = m_localconfig.m_autoloadconfigflags;

m_radiobuttonloadauto->setChecked( 
		(state & MODE_AUTOLOADCONFIG) == MODE_AUTOLOADCONFIG  );

m_radiobuttonloadprompt->setChecked( 
		(state & MODE_AUTOLOADPROMPT) == MODE_AUTOLOADPROMPT );

m_radiobuttonloadnoaction->setChecked(
                (state & MODE_AUTOLOADNOACTION) == MODE_AUTOLOADNOACTION);
}

// --------------------------------------------------------------------------
// Set save radio buttons
// --------------------------------------------------------------------------

void CConfigFileSettingsDialog::SetSaveRadioButtons( void )
{
int state;

state = m_localconfig.m_autosaveconfigflags;

m_radiobuttonsaveauto->setChecked(
		(state & MODE_AUTOSAVECONFIG) == MODE_AUTOSAVECONFIG  );

m_radiobuttonsaveprompt->setChecked(
		(state & MODE_AUTOSAVEPROMPT) == MODE_AUTOSAVEPROMPT );

m_radiobuttonsavenoaction->setChecked(
                (state & MODE_AUTOSAVENOACTION) == MODE_AUTOSAVENOACTION);
}

// --------------------------------------------------------------------------
// Set auto-load flag
// --------------------------------------------------------------------------
                                                                                
void CConfigFileSettingsDialog::SetAutoLoadFlag( int value )
{
if ( m_doupdate )
        {
        m_localconfig.m_autoloadconfigflags = value;
                                                                                
        m_doupdate = false;
                                                                                
        SetLoadRadioButtons();
                                                                                
        m_doupdate = true;
        }
}
                                                                                
// --------------------------------------------------------------------------
// Set auto-save flag
// --------------------------------------------------------------------------
                                                                                
void CConfigFileSettingsDialog::SetAutoSaveFlag( int value )
{
if ( m_doupdate )
        {
        m_localconfig.m_autosaveconfigflags = value;
                                                                                
        m_doupdate = false;
                                                                                
        SetSaveRadioButtons();
                                                                                
        m_doupdate = true;
        }
}
                                                                                
// --------------------------------------------------------------------------
// Set dialog data
// --------------------------------------------------------------------------

void CConfigFileSettingsDialog::SetDialogData( void )
{
// ----- Set configuration file box

m_lineeditconfigfile->setText( m_localconfig.m_configfile.data() );

SetLoadRadioButtons();
SetSaveRadioButtons();
}

// ==========================================================================
// USER INTERFACE HANDLERS
// ==========================================================================

// --------------------------------------------------------------------------
// Configuration file text box has changed
// --------------------------------------------------------------------------

void CConfigFileSettingsDialog::lineeditconfigfile_textChanged( 	
						const QString &string )
{
m_localconfig.m_configfile = (char *) string.ascii();
}

// --------------------------------------------------------------------------
// Browse for new configuration file
// --------------------------------------------------------------------------

void CConfigFileSettingsDialog::pushbuttonbrowse_clicked( void )
{
QFileDialog filedlg;
QString     filepath;
                                                                                
filedlg.setDirectory(".");
filedlg.setFilter( "*.cfg,*.txt");
filedlg.setCaption( "Select Directory Dialog");
                                                                                
if( filepath.ascii() != NULL )
        {
	m_localconfig.m_configfile = (char *) filepath.ascii();

        m_lineeditconfigfile->setText( filepath );
        }
}

// --------------------------------------------------------------------------
// Radio button load automatically clicked
// --------------------------------------------------------------------------

void CConfigFileSettingsDialog::radiobuttonloadauto_clicked( void )
{
SetAutoLoadFlag( MODE_AUTOLOADCONFIG );
}

// --------------------------------------------------------------------------
// Radio button load on prompt clicked
// --------------------------------------------------------------------------

void CConfigFileSettingsDialog::radiobuttonloadprompt_clicked( void )
{
SetAutoLoadFlag( MODE_AUTOLOADPROMPT );
}

// --------------------------------------------------------------------------
// Radio button load no action
// --------------------------------------------------------------------------

void CConfigFileSettingsDialog::radiobuttonloadnoaction_clicked( void )
{
SetAutoLoadFlag( MODE_AUTOLOADNOACTION );
}

// --------------------------------------------------------------------------
// Radio button save automatically clicked
// --------------------------------------------------------------------------

void CConfigFileSettingsDialog::radiobuttonsaveauto_clicked( void )
{
SetAutoSaveFlag( MODE_AUTOSAVECONFIG );
}

// --------------------------------------------------------------------------
// Radio button save on prompt clicked
// --------------------------------------------------------------------------

void CConfigFileSettingsDialog::radiobuttonsaveprompt_clicked( void )
{
SetAutoSaveFlag( MODE_AUTOSAVEPROMPT );
}

// --------------------------------------------------------------------------
// Radio button save no action
// --------------------------------------------------------------------------

void CConfigFileSettingsDialog::radiobuttonsavenoaction_clicked( void )
{
SetAutoSaveFlag( MODE_AUTOSAVENOACTION );
}

// --------------------------------------------------------------------------
// OK button was pressed, so make changes
// --------------------------------------------------------------------------

void CConfigFileSettingsDialog::pushbuttonok_clicked( void )
{
SaveSettings();
done( CONFIGFILESETTINGS_OK );
}

// --------------------------------------------------------------------------
// Push button apply clicked
// --------------------------------------------------------------------------

void CConfigFileSettingsDialog::pushbuttonapply_clicked( void )
{
SaveSettings();
}

// --------------------------------------------------------------------------
// Push button cancel clicked
// --------------------------------------------------------------------------

void CConfigFileSettingsDialog::pushbuttoncancel_clicked( void )
{
done( CONFIGFILESETTINGS_CANCEL ); // No change
}

// --------------------------------------------------------------------------
// Push button reset clicked
// --------------------------------------------------------------------------

void CConfigFileSettingsDialog::pushbuttonreset_clicked( void )
{
LoadSettings();
SetDialogData();
}
