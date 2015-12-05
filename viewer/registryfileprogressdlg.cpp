// ---------------------------------------------------------------------------
// Copyright: (C) VFX Research 2002 - 2014. All Rights Reserved.
// ---------------------------------------------------------------------------

#include "config.h"

#include <qvariant.h>
#include <qdialog.h>
#include <qprogressbar.h>
#include <qlineedit.h>
#include <qpushbutton.h>
#include <qeventloop.h>
#include <qapplication.h>

#include "extensionlib.h"
#include "registryfileprogressdlg.h"

// --------------------------------------------------------------------------
// Callback function for reading registry callback
// --------------------------------------------------------------------------

int CRegistryFileProgressDialog::RegistryFileProgressCallback( 
		const std::string &name, const std::string &extname, int pos, int max )
{
m_progressbar->setValue( pos );
m_progressbar->setMaximum( max );
m_editregistryfile->setText( name.data() );
m_editregistryfile->repaint(0);
m_editextensionstring->setText( extname.data() );
m_editextensionstring->repaint(0);
m_pushbuttoncancel->repaint(0);

qApp->processEvents();

return( 0 );
}

// --------------------------------------------------------------------------
// Handle cancel events
// --------------------------------------------------------------------------

void CRegistryFileProgressDialog::pushbuttoncancel_clicked( void )
{
#ifdef DEBUG
std::cout << "Cancel pressed\n";
#endif

m_resultcode = CALLBACK_CANCEL;
}

