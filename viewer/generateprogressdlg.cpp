// ---------------------------------------------------------------------------
// Copyright: (C) VFX Research 2002 - 2014. All Rights Reserved.
// ---------------------------------------------------------------------------

#include "config.h"
#include "generateprogressdlg.h"

// --------------------------------------------------------------------------
// Set the filenames of the output files
// --------------------------------------------------------------------------

void CGenerateProgressDialog::SetFilenames( 
			const char *header, const char *source )
{
m_editheader->setText( header );
m_editheader->repaint(0);
m_editsource->setText( source );
m_editsource->repaint(0);
}
        
// --------------------------------------------------------------------------
// Callback for displaying the progress of the generation of the output files
// --------------------------------------------------------------------------

int CGenerateProgressDialog::GenerateProgressCallback( 
					int filetype, int pos, int max )
{
if ( filetype )
	{
	m_progressheader->setValue( pos );
	m_progressheader->setMaximum( max );
	}
else
	{
	m_progresssource->setValue( pos );
	m_progresssource->setMaximum( max );
        }                                                                        
qApp->processEvents();
return( 0 );
}

// --------------------------------------------------------------------------- 
// The OK button was pressed
// ---------------------------------------------------------------------------
                                                                               
void CGenerateProgressDialog::pushbuttonok_clicked()
{
accept();
}

