// ---------------------------------------------------------------------------
// Copyright: (C) VFX Research 2002 - 2014. All Rights Reserved.
// ---------------------------------------------------------------------------
                                                                                
#ifndef CHECKSYSTEMPROGRESSDIALOG_H
#define CHECKSYSTEMPROGRESSDIALOG_H

#include <cstdio>
#include <cstdlib>
#include <iostream>

#include <qapplication.h>
#include <qlineedit.h>

#include "extensionlib.h"
#include "ui_checksystemprogressbasedlg.h"

class CCheckSystemProgressDialog : public QDialog,
				public Ui_CCheckSystemProgressBaseDialog,
				   public CCheckSystemProgressCallback
{
	Q_OBJECT

public:
// ----- Internal variables -------------------------------------------------

int m_resultcode;

// ----- Construct and destructor -------------------------------------------

CCheckSystemProgressDialog() : Ui_CCheckSystemProgressBaseDialog()
	{
	setupUi( this );
	m_resultcode = CALLBACK_CONTINUE;
	};

~CCheckSystemProgressDialog() { };

// ----- Functions and Procedures -------------------------------------------

int CheckSystemProgressCallback( int pos, int max );

protected:

protected slots:
};

#endif // CHECKSYSTEMDOWNLOADPROGRESSDIALOG_H
