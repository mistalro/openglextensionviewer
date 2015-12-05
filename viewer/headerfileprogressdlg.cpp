// ---------------------------------------------------------------------------
// Copyright: (C) VFX Research 2002 - 2014. All Rights Reserved.
// ---------------------------------------------------------------------------

#include <qapplication.h>
#include <qeventloop.h>
#include <qpushbutton.h>
#include <qlineedit.h>
#include <qprogressbar.h>
#include <qvariant.h>
#include <qdialog.h>
#include "config.h"

#include "extensionlib.h"
#include "headerfileprogressdlg.h"

// --------------------------------------------------------------------------
// Callback function for reading header files
// --------------------------------------------------------------------------

int CHeaderFileProgressDialog::HeaderFileProgressCallback( 
	const std::string &name, const std::string &extname, int pos, int max )
{
m_progressheaderfile->setValue( pos );
m_progressheaderfile->setMaximum( max );         
m_editheaderfile->setText( name.data() );
m_editheaderfile->repaint(0);
m_editextensionstring->setText( extname.data() );
m_editextensionstring->repaint(0);
m_pushbuttoncancel->repaint(0);
                                                                                
qApp->processEvents();
                                                                                
return(m_resultcode);
}

// --------------------------------------------------------------------------
// Handle cancel events
// --------------------------------------------------------------------------                                                                                
void CHeaderFileProgressDialog::pushbuttoncancel_clicked( void )
{
m_resultcode = CALLBACK_CANCEL;
};
