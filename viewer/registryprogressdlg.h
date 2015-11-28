// ---------------------------------------------------------------------------
// Copyright: (C) VFX Research 2002 - 2014. All Rights Reserved.
// ---------------------------------------------------------------------------

#ifndef REGISTRYPROGRESSDIALOG_H
#define REGISTRYPROGRESSDIALOG_H

using namespace std;

#include <cstdio>
#include <cstdlib>
#include <iostream>

#include <qapplication.h>
#include <q3listbox.h>
#include <qfiledialog.h>

#include "extensionlib.h"
#include ".ui/ui_registryprogressbasedlg.h"

class CRegistryProgressDialog : public QDialog,
				public Ui_CRegistryProgressBaseDialog,
				public CRegistryDownloadCallback
{
	Q_OBJECT
	
public:

// ----- Internal variables ---------------------------------------------------

int m_resultcode;

// ----- Constructor and Destructor -------------------------------------------

CRegistryProgressDialog() : Ui_CRegistryProgressBaseDialog() 
	{ 
	setupUi( this );
	m_resultcode = CALLBACK_CONTINUE;
	};
	 
~CRegistryProgressDialog() { };

// ----- Functions and Procedures ---------------------------------------------

int RegistryDownloadCallback( const string &str, int mode );

protected:

protected slots:
void pushbuttonok_clicked();
void pushbuttonpause_clicked();
void pushbuttoncancel_clicked();
void pushbuttonsave_clicked();
};

#endif // REGISTRYPROGRESSDIALOG_H
