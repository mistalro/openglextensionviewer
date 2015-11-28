// ---------------------------------------------------------------------------
// Copyright: (C) VFX Research 2002 - 2014. All Rights Reserved.
// ---------------------------------------------------------------------------

#include "config.h"
                                                                                
#include <QFile>
#include <QDialog>
#include <QRadioButton>
#include "extensionviewdlg.h"
#include "extensionlib.h"

// --------------------------------------------------------------------------
// Set the filepath
//
// Inputs: filepath - Path to the text extension
//
// Outputs: None
//
// Results: None
//
// Effects: The path to the selected document is set
// --------------------------------------------------------------------------

void CExtensionViewDialog::SetExtensionPath( STRPATH filepath )
{
strcpy( m_filepath, filepath );
}

// --------------------------------------------------------------------------
// Configure the dialog data are required
//
// Inputs: None
//
// Outputs: None
//
// Results: None
//
// Effects: The widgets are configured with the required data
// --------------------------------------------------------------------------

void CExtensionViewDialog::SetDialogData( void )
{
QFile file( m_filepath );

if ( file.open( IO_ReadOnly ) )
	{
	QTextStream stream( &file );

	m_textedit->setText( stream.read() );

	file.close();
	}
else
	m_textedit->setText( "No information available\n" );
}

// ==========================================================================
// DIALOG CONTROLS
// ==========================================================================

void CExtensionViewDialog::pushbuttonok_clicked( void )
{
accept();
}

