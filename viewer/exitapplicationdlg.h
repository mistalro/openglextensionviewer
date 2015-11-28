// ---------------------------------------------------------------------------
// Copyright: (C) VFX Research 2002 - 2014. All Rights Reserved.
// ---------------------------------------------------------------------------

#ifndef EXITAPPLICATIONDIALOG_H
#define EXITAPPLICATIONDIALOG_H

using namespace std;

#include <cstdio>
#include <cstdlib>
#include <iostream>

#include "extensionlib.h"
#include "ui_exitapplicationbasedlg.h"

#define EXIT_YES    0x01
#define EXIT_NO     0x02
#define EXIT_CANCEL 0x03

class CExitApplicationDialog : public QDialog,
				public Ui_CExitApplicationBaseDialog
{
	Q_OBJECT
	
public:

// ----- Internal variables ---------------------------------------------------

// ----- Constructor and Destructor -------------------------------------------

CExitApplicationDialog() : Ui_CExitApplicationBaseDialog()
{
setupUi( this );
};
	 
~CExitApplicationDialog() { };

// ----- Functions and Procedures ---------------------------------------------
protected:

protected slots:

void pushbuttonyes_clicked( void )
	{
	done( EXIT_YES );
	}

void pushbuttonno_clicked( void )
	{
	done( EXIT_NO );
	}

void pushbuttoncancel_clicked( void )
	{
	done( EXIT_CANCEL );
	}
};

#endif // EXITAPPLICATIONDIALOG_H
