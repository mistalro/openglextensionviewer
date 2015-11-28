// ---------------------------------------------------------------------------
// Copyright: (C) VFX Research 2002 - 2014. All Rights Reserved.
// ---------------------------------------------------------------------------
                                                                                
#ifndef FINDFUNCCONSTDIALOG_H
#define FINDFUNCCONSTDIALOG_H

using namespace std;

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include "extensionlib.h"
#include ".ui/ui_findfuncconstbasedlg.h"

// ----------------------------------------------------------------------------
// Definition of the CPFListView class
// ----------------------------------------------------------------------------

class CFindFuncConstDialog : public QDialog,
				public Ui_CFindFuncConstBaseDialog,
				public CHeaderFileDataSearchCallback
{
	Q_OBJECT
	
CExtensionViewer *m_pcreator;
int m_updateflag;

// ----- Constructor and Destructor -------------------------------------------
public:

CFindFuncConstDialog();
	 
~CFindFuncConstDialog() { };

// ----- Functions and Procedures ---------------------------------------------

void SetPointer( CExtensionViewer *pcreator )
	{
	m_pcreator = pcreator;
	};

void ClearUpdateFlag( void ) 
	{ 
	m_updateflag = 1; 
	};

void SetUpdateFlag( void )   
	{ 
	m_updateflag = 1; 
	};

int  CheckUpdateFlag( void ) 
	{ 
	return m_updateflag; 
	};

void SetAllItems( void );

int HeaderFileDataSearchCallback( int list, 
			const string &name, const string &value );

void listview_setSorting( int column, bool ascending );

// ----- User interface stuff -----------------------------------------------

public slots:
void pushbuttonfindconstant_clicked();
void pushbuttonfindfunction_clicked();
void pushbuttonclear_clicked();
void pushbuttonok_clicked();
void lineeditconstant_textChanged( const QString & );
void lineeditfunction_textChanged( const QString & );
};

#endif // FINDFUNCCONSTDIALOG_H
