// ---------------------------------------------------------------------------
// Copyright: (C) VFX Research 2002 - 2014. All Rights Reserved.
// ---------------------------------------------------------------------------

#include "config.h"
#include "registryprogressdlg.h"

// ---------------------------------------------------------------------------
// Callback for the registry file download
//
// Inputs: string - Character string
//         mode   - Optional control flags
//
// Outputs: None
//
// Results: The curernt result code - This can be any of the following:
//
//          CALLBACK_CONTINUE - Keep downloading
//          CALLBACK_CANCEL   - Stop downloading
//
// Effects: The selected text is placed in the list box, and the result 
//          code returned
// --------------------------------------------------------------------------

int CRegistryProgressDialog::RegistryDownloadCallback( 
					const std::string &str, int /* mode */ )
{        
if ( 0 < str.length() )	
	{
	m_listboxregistrylog->insertItem( str.data(), -1 );

	m_listboxregistrylog->setCurrentItem( m_listboxregistrylog->count()-1 );
	m_listboxregistrylog->ensureCurrentVisible();
	}
	
qApp->processEvents();

return(m_resultcode);
}

// --------------------------------------------------------------------------
// Pause button was pressed
// --------------------------------------------------------------------------

void CRegistryProgressDialog::pushbuttonpause_clicked()
{
m_resultcode = 0;		
}

// --------------------------------------------------------------------------
// OK button was pressed
// --------------------------------------------------------------------------

void CRegistryProgressDialog::pushbuttonok_clicked()
{
accept();
}

// --------------------------------------------------------------------------
// Cancel button was pressed
// -------------------------------------------------------------------------- 

void CRegistryProgressDialog::pushbuttoncancel_clicked()
{
#ifdef DEBUG
std::cout << "Cancel pressed\n";
#endif
}

// --------------------------------------------------------------------------
// Save button was pressed
// -------------------------------------------------------------------------- 

void CRegistryProgressDialog::pushbuttonsave_clicked()
{
QFileDialog filedlg;
QString     filepath, text;
std::ofstream    stream;
Q3ListBoxItem *pitem;
int pos, max;

filepath = filedlg.getSaveFileName(
	".",
	"Text files (*.txt)",
	this,
	"Select text file",
	"Choose text file" );

if ( filepath.ascii() != NULL )
	{
	stream.open( filepath.ascii() );

	if ( stream.is_open() )
		{
		max = m_listboxregistrylog->count();

		for ( pos = 0; pos < max; pos++ )
			{
			pitem = m_listboxregistrylog->item( pos);
			text = pitem->text();
	
			stream.write( text.ascii(), text.length() );	
			stream.write( "\n", 1 );
			}

		stream.close();
		}
	}
}

