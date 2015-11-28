// ---------------------------------------------------------------------------
// Copyright: (C) VFX Research 2002 - 2014. All Rights Reserved.
// ---------------------------------------------------------------------------

#include "config.h"
#include "qtextedit.h"
#include "qmessagebox.h"
#include "qfiledialog.h"
#include "qtabwidget.h"
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include "extensionlib.h"
#include "scripteditordlg.h"

// --------------------------------------------------------------------------
// Load the internal script
// --------------------------------------------------------------------------

void CScriptEditorDialog::LoadTextEditInternal( void )
{
if ( m_pextcreator->m_scriptsettings.m_scriptinternal.length() != 0 )
	{
	m_texteditinternal->setText( m_pextcreator->m_scriptsettings.m_scriptinternal.data() );
	}
else
	{
	m_texteditinternal->setText( "No file available");
	}
}

// --------------------------------------------------------------------------
// Load the external script
// --------------------------------------------------------------------------

void CScriptEditorDialog::LoadTextEditExternal( void )
{
if ( m_pextcreator->m_scriptsettings.m_scriptexternal.length() != 0 )
	{
	m_texteditexternal->setText( m_pextcreator->m_scriptsettings.m_scriptexternal.data() );
	}
else
	{
	m_texteditexternal->setText( "No file available");
	}
}

// --------------------------------------------------------------------------
// Write the external file
// --------------------------------------------------------------------------

void CScriptEditorDialog::WriteExternalScript( const char *path, int index )
{
int done = 0, result = 0;
QMessageBox messagebox;

while ( !done  )
	{
	if ( 0 < index )
		{
		result = m_pextcreator->m_scriptsettings.ScriptWrite( 
			path, SCRIPT_EXTERNAL );
		}
	else
		{
		result = m_pextcreator->m_scriptsettings.ScriptWrite(
			path, SCRIPT_INTERNAL );
                }                                                                

	if ( 0 < result )
		{
		done++;
		}
	else
                {
                result = messagebox.warning( this, // Parent
                         "File save",           // Caption
                        "Could not write file", // Text
                        QMessageBox::Cancel,
                        QMessageBox::Retry,
                        QMessageBox::NoButton ); // Button text
                                                                                
                switch ( result )
                        {
                        case QMessageBox::Cancel: // Cancel
				done++;
                                break;
                                                                                
                        case QMessageBox::Retry:
				break;

                        default:
                                break;
                        }
                }
        }
}

// ==========================================================================
// GUI OPERATIONS
// ==========================================================================

// --------------------------------------------------------------------------
// The copy button was pressed
// --------------------------------------------------------------------------

void CScriptEditorDialog::pushbuttoncopy_clicked() 
{
m_pextcreator->m_scriptsettings.ScriptCopyInternal();

LoadTextEditInternal();
LoadTextEditExternal();
}

// --------------------------------------------------------------------------
// The save button was pressed
// --------------------------------------------------------------------------

void CScriptEditorDialog::pushbuttonsave_clicked()
{
int index;
QFileDialog filedlg;
QString     filepath;
QMessageBox messagebox;                                                                                
index = m_tabscript->currentPageIndex();

filepath = filedlg.getSaveFileName(
                           ".",
                           "Script files (*.txt)",
                           this,
                           "Save File Dialog",
                           "Choose save file" );
                                                                                
if ( filepath.ascii() != NULL )
	WriteExternalScript( (char *) filepath.ascii(), index );
}

// --------------------------------------------------------------------------
// The clear button was pressed - clear the selected window
// --------------------------------------------------------------------------

void CScriptEditorDialog::pushbuttonclear_clicked()
{
int index;

index = m_tabscript->currentPageIndex();

if ( index )
	{
	m_texteditexternal->clear();
	}
else
	{
	m_texteditinternal->clear();
	}
}

// --------------------------------------------------------------------------
// The restore button was pressed - copy the data from the current state
// --------------------------------------------------------------------------

void CScriptEditorDialog::pushbuttonrestore_clicked()
{
int index;

index = m_tabscript->currentPageIndex();

if ( index )
	{
	LoadTextEditExternal();
	}
else	
	{
	LoadTextEditInternal();
	}
}

// --------------------------------------------------------------------------
// The cancel button was pressed - discard all changes
// --------------------------------------------------------------------------

void CScriptEditorDialog::pushbuttoncancel_clicked()
{
reject();
}

// --------------------------------------------------------------------------
// The apply button was pressed - save changes
// --------------------------------------------------------------------------

void CScriptEditorDialog::pushbuttonapply_clicked()
{
QString strtext;
string strdata;

strtext = m_texteditexternal->text();

strdata = strtext.ascii();
m_pextcreator->m_scriptsettings.ScriptSetExternal( strdata );

WriteExternalScript( m_pextcreator->m_outputfilesettings.m_scriptfile.data(), 1 );
}

// --------------------------------------------------------------------------
// The OK button was pressed - save changes and exit dialog
// --------------------------------------------------------------------------

void CScriptEditorDialog::pushbuttonok_clicked()
{
pushbuttonapply_clicked();
accept();
}
