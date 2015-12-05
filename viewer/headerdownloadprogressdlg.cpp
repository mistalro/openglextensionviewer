// ---------------------------------------------------------------------------
// Copyright: (C) VFX Research 2002 - 2014. All Rights Reserved.
// ---------------------------------------------------------------------------

#include "config.h"
#include "headerdownloadprogressdlg.h"

int CHeaderDownloadProgressDialog::HeaderDownloadProgressCallback( 
				const std::string &str, int /* mode */ )
{
m_listboxlog->insertItem( str.data(), -1 );

m_listboxlog->setCurrentItem( m_listboxlog->count()-1 );
m_listboxlog->ensureCurrentVisible();

qApp->processEvents();

return( m_resultcode );
}

void CHeaderDownloadProgressDialog::pushbuttonpause_clicked()
{
m_resultcode = 0;
}

void CHeaderDownloadProgressDialog::pushbuttonok_clicked()
{
accept();
}

void CHeaderDownloadProgressDialog::pushbuttoncancel_clicked()
{

}
