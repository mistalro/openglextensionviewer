// ---------------------------------------------------------------------------
// Copyright: (C) VFX Research 2002 - 2014. All Rights Reserved.
// ---------------------------------------------------------------------------

#ifndef REGISTRYFILEDIALOG_H
#define REGISTRYFILEDIALOG_H

#include "extensionlib.h"
#include ".ui/ui_registryfileprogressbasedlg.h"
#include <qdialog.h>
#include <qprogressbar.h>
#include <qlineedit.h>

class CRegistryFileProgressDialog : 
				public QDialog,
				public Ui_CRegistryFileProgressBaseDialog,
			        public CRegistryFileProgressCallback
{
	Q_OBJECT
	
public:

// ----- Internal variables ---------------------------------------------------

int m_resultcode;

// ----- Constructor and Destructor -------------------------------------------

CRegistryFileProgressDialog( void ) : Ui_CRegistryFileProgressBaseDialog() 
	{ 
	setupUi( this );
	m_resultcode = CALLBACK_CONTINUE;
	};
	 
~CRegistryFileProgressDialog() { };

// ----- Functions and Procedures ---------------------------------------------

int RegistryFileProgressCallback( const std::string &name, 
				const std::string &extname, 
				int pos, int max );	

protected:

public slots:
void pushbuttoncancel_clicked( void );
};

#endif // REGISTRYFILEDIALOG_H
