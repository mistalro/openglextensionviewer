// ---------------------------------------------------------------------------
// Copyright: (C) VFX Research 2002 - 2014. All Rights Reserved.
// ---------------------------------------------------------------------------

#ifndef GENERATEPROGRESSDIALOG_H
#define GENERATEPROGRESSDIALOG_H

#include "extensionlib.h"
#include "ui_generateprogressbasedlg.h"

#include <QApplication>
#include <QProgressBar>
#include <QLineEdit>

class CGenerateProgressDialog : public QDialog,
				public Ui_CGenerateProgressBaseDialog,
				public CGenerateProgressCallback
{
	Q_OBJECT
	
public:

// ----- Internal variables ---------------------------------------------------

// ----- Constructor and Destructor -------------------------------------------

CGenerateProgressDialog() : Ui_CGenerateProgressBaseDialog()
	{ 
	setupUi( this );
	};
	 
~CGenerateProgressDialog() { };

void SetFilenames( const char *header, const char *source );

int GenerateProgressCallback( int filetype, int pos, int max );

void pushbuttonok_clicked( void );

// ----- Functions and Procedures ---------------------------------------------

protected:

protected slots:
};

#endif // GENERATEPROGRESSDIALOG_H
