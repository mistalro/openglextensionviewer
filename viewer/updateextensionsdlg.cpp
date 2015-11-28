// ---------------------------------------------------------------------------
// Copyright: (C) VFX Research 2002 - 2014. All Rights Reserved.
// ---------------------------------------------------------------------------

#include "config.h"
#include "q3listbox.h"
#include <qdialog.h>
#include <qradiobutton.h>
#include <qcheckbox.h>

#include "extensionlib.h"
#include "extensiondlg.h"
#include "updateextensionsdlg.h"

// --------------------------------------------------------------------------
// Save Settings
// --------------------------------------------------------------------------

void CUpdateExtensionsDialog::SaveSettings( void )
{
m_pextcreator->m_sitelist.SetUpdateMode( m_updatemode );
}

// --------------------------------------------------------------------------
// Load Settings
// --------------------------------------------------------------------------

void CUpdateExtensionsDialog::LoadSettings( void )
{
m_updatemode = m_pextcreator->m_sitelist.GetUpdateMode();
}

// --------------------------------------------------------------------------
// Set Pointer to Data
// --------------------------------------------------------------------------

void CUpdateExtensionsDialog::SetPointer( CExtensionViewer *pextcreator )
{
m_pextcreator = pextcreator;

LoadSettings();
SetList();
SetAllCheckBoxes();
}

// --------------------------------------------------------------------------
// Set List data
// --------------------------------------------------------------------------

void CUpdateExtensionsDialog::SetList( void )
{
int pn;
CExtensionEntryList *plist = &m_pextcreator->m_headerfileset.m_newlist;

for ( pn = 0; pn < plist->GetCount(); pn++ )
	m_listboxextensionsnotfound->insertItem( 
				plist->at(pn).m_name.data(), -1 );

}

// --------------------------------------------------------------------------
// Set all the user interface checkboxes
// --------------------------------------------------------------------------

void CUpdateExtensionsDialog::SetAllCheckBoxes( void )
{
if ( m_blockupdates == 0 )
	{
	m_blockupdates = 1;

	m_checkboxreadheaders->setChecked( 
		(m_updatemode & MODE_READHEADERS) == MODE_READHEADERS );

	m_checkboxreadregistry->setChecked( 
		(m_updatemode & MODE_READREGISTRY) == MODE_READREGISTRY );

	m_checkboxdownloadheaders->setChecked(
		(m_updatemode & MODE_UPDATEHEADERS) == MODE_UPDATEHEADERS);

	m_checkboxdownloadregistry->setChecked( 
		(m_updatemode & MODE_UPDATEREGISTRY) == MODE_UPDATEREGISTRY );

	m_checkboxignoreextensions->setChecked( 
		(m_updatemode & MODE_IGNORETHESE) == MODE_IGNORETHESE );

	m_blockupdates = 0;
	}
}

// --------------------------------------------------------------------------
// Set the state of the selected update mode flag
// --------------------------------------------------------------------------

void CUpdateExtensionsDialog::SetState( int flag, int mode )
{
if ( mode )
	m_updatemode |= flag;
else
	m_updatemode &= ~flag;
}

// ==========================================================================
// USER INTERFACE CALLS
// ==========================================================================

// --------------------------------------------------------------------------
// Checkbox for reading headers changed state
// --------------------------------------------------------------------------

void CUpdateExtensionsDialog::checkboxreadheaders_toggled( bool state )
{
SetState( MODE_READHEADERS, state );
SetAllCheckBoxes();
}

// --------------------------------------------------------------------------
// Checkbox for downloading headers changed state
// --------------------------------------------------------------------------

void CUpdateExtensionsDialog::checkboxdownloadheaders_toggled( bool state )
{
SetState( MODE_UPDATEHEADERS, state );
SetAllCheckBoxes();
}

// --------------------------------------------------------------------------
// Checkbox for reading registry files changed state
// --------------------------------------------------------------------------

void CUpdateExtensionsDialog::checkboxreadregistry_toggled( bool state )
{
SetState( MODE_READREGISTRY, state );
SetAllCheckBoxes();
}

// --------------------------------------------------------------------------
// Checkbox for downloading registry files changed state
// --------------------------------------------------------------------------

void CUpdateExtensionsDialog::checkboxdownloadregistry_toggled( bool state )
{
SetState( MODE_UPDATEREGISTRY, state );
SetAllCheckBoxes();
}

// --------------------------------------------------------------------------
// Checkbox for ignoring registry files changed state
// --------------------------------------------------------------------------

void CUpdateExtensionsDialog::checkboxignoreextensions_toggled( bool state )
{
SetState( MODE_IGNORETHESE, state );

if ( state )
	{
	SetState( MODE_READHEADERS, false );
	SetState( MODE_UPDATEHEADERS, false );
	SetState( MODE_READREGISTRY, false );
	SetState( MODE_UPDATEREGISTRY, false );
	}

SetAllCheckBoxes();
}

// --------------------------------------------------------------------------
// List box has been double clicked
// --------------------------------------------------------------------------

void CUpdateExtensionsDialog::listboxextensionsnotfound_doubleClicked( 
							Q3ListBoxItem *pitem) 
{
CExtensionDialog extdialog;

extdialog.SetPointer( m_pextcreator );
extdialog.SetExtensionName( (char *) pitem->text().ascii() );

extdialog.exec();
}

// --------------------------------------------------------------------------
// OK button
// --------------------------------------------------------------------------

void CUpdateExtensionsDialog::pushbuttonok_clicked( void ) 
{
SaveSettings();
done( UPDATE_OK );
}

// --------------------------------------------------------------------------
// Cancel button
// --------------------------------------------------------------------------

void CUpdateExtensionsDialog::pushbuttoncancel_clicked( void )
{
done( UPDATE_CANCEL );
}

// --------------------------------------------------------------------------
// Apply button
// --------------------------------------------------------------------------

void CUpdateExtensionsDialog::pushbuttonapply_clicked( void )
{
SaveSettings();
}

// --------------------------------------------------------------------------
// Reset button
// --------------------------------------------------------------------------

void CUpdateExtensionsDialog::pushbuttonreset_clicked( void )
{
LoadSettings();
}

