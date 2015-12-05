// ---------------------------------------------------------------------------
// Copyright: (C) VFX Research 2002 - 2014. All Rights Reserved.
// ---------------------------------------------------------------------------

#include "checksystemprogressdlg.h"

#include <qdialog.h>
#include <qprogressbar.h>
#include <qlineedit.h>

// ---------------------------------------------------------------------------
// Callback for displaying the progress of the analysis of the pixel formats
// ---------------------------------------------------------------------------

int CCheckSystemProgressDialog::CheckSystemProgressCallback( int pos, int max )
{
std::string strpos, strmax, strbuf;

stl_itoa( strpos, pos );
stl_itoa( strmax, max );

strbuf = strpos + "/" + strmax;

m_lineeditcount->setText( strbuf.data() );
m_progressbar->setProgress( pos, max );

qApp->processEvents();

return( 0 );
}

