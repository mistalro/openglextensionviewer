// ---------------------------------------------------------------------------
// Copyright: (C) VFX Research 2002 - 2014. All Rights Reserved.
// ---------------------------------------------------------------------------
                                                                                
#ifndef HEADERDOWNLOADPROGRESSDIALOG_H
#define HEADERDOWNLOADPROGRESSDIALOG_H
                                                                                
using namespace std;
                                                                                
#include <cstdio>
#include <cstdlib>
#include <iostream>
                                                                                
#include <qapplication.h>
#include <q3listbox.h>
#include "extensionlib.h"
#include ".ui/ui_headerdownloadprogressbasedlg.h"
                                                                                
class CHeaderDownloadProgressDialog : public QDialog,
				public Ui_CHeaderDownloadProgressBaseDialog,
		      		public CHeaderDownloadProgressCallback
{
	Q_OBJECT

public:

// ----- Internal variables -------------------------------------------------

int m_resultcode;

// ----- Constructor and Destructor -----------------------------------------

CHeaderDownloadProgressDialog() : Ui_CHeaderDownloadProgressBaseDialog()
	{
	setupUi( this );
	m_resultcode = CALLBACK_CONTINUE;
	};

~CHeaderDownloadProgressDialog() { };

// ----- Functions and Procedures -------------------------------------------

int HeaderDownloadProgressCallback( const string &str, int mode );

protected:

protected slots:

void pushbuttonok_clicked();
void pushbuttonpause_clicked();
void pushbuttoncancel_clicked();
};

#endif // HEADERDOWNLOADPROGRESSDIALOG_H
