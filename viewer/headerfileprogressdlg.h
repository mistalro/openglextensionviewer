// ---------------------------------------------------------------------------
// Copyright: (C) VFX Research 2002 - 2014. All Rights Reserved.
// ---------------------------------------------------------------------------

#ifndef HEADERFILEPROGRESSDIALOG_H
#define HEADERFILEPROGRESSDIALOG_H

#include "extensionlib.h"
#include ".ui/ui_headerfileprogressbasedlg.h"
#include <qdialog.h>
#include <qprogressbar.h>
#include <qlineedit.h>

class CHeaderFileProgressDialog : public QDialog,
				public Ui_CHeaderFileProgressBaseDialog,
				  public CHeaderFileProgressCallback
{
	Q_OBJECT
	
public:

// ----- Internal variables ---------------------------------------------------

int m_resultcode;

// ----- Constructor and Destructor -------------------------------------------

CHeaderFileProgressDialog() : QDialog(), 
			Ui_CHeaderFileProgressBaseDialog(),
			CHeaderFileProgressCallback()
	{ 
	setupUi( this );
	m_resultcode = CALLBACK_CONTINUE;
	};
	 
~CHeaderFileProgressDialog() { };

// ----- Functions and Procedures ---------------------------------------------

int HeaderFileProgressCallback( const string &name, const string &extname, int pos, int max );

protected:

protected slots:
void pushbuttoncancel_clicked( void );
};

#endif // HEADERFILEPROGRESSDIALOG_H
