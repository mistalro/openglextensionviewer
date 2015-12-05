// ---------------------------------------------------------------------------
// Copyright: (C) VFX Research 2002 - 2014. All Rights Reserved.
// ---------------------------------------------------------------------------

#ifndef FINDEXTENSIONSPECDIALOG_H
#define FINDEXTENSIONSPECDIALOG_H

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include "extensionlib.h"
#include ".ui/ui_findextensionspecbasedlg.h"

// ----------------------------------------------------------------------------
// Definition of the CPFListView class
// ----------------------------------------------------------------------------

class CFindExtensionSpecDialog : public QDialog,
				public Ui_CFindExtensionSpecBaseDialog,
				public CRegistryStringSearchCallback
{
	Q_OBJECT
	
CExtensionViewer *m_pcreator;
int m_updateflag;
int m_cancelsearch;
int m_searchmode;

// ----- Constructor and Destructor -------------------------------------------
public:

CFindExtensionSpecDialog( QWidget* parent = 0, const char* name = 0, 
			bool modal = FALSE, Qt::WFlags fl = 0 );
	 
~CFindExtensionSpecDialog() { };

// ----- Functions and Procedures ---------------------------------------------

void SetPointer( CExtensionViewer *pcreator )
	{
	m_pcreator = pcreator;
	};

void ClearUpdateFlag( void ) { m_updateflag = 1; };
void SetUpdateFlag( void )   { m_updateflag = 1; };
int  CheckUpdateFlag( void ) { return m_updateflag; };

void SetAllItems( void );

int RegistryStringSearchCallback( 
	int site, int lineno, const std::string &file,
	const std::string &line, int mode );

int RegistryStringSearchProgressCallback( int pos, int max );

// ----- User interface stuff -----------------------------------------------

protected slots:
void lineeditsearchstring_textChanged( const QString & );

void pushbuttoncancelsearch_clicked();
void pushbuttonok_clicked();
void pushbuttonfind_clicked();
void pushbuttonclear_clicked();

void radiobuttonmatchcase_toggled(bool state);
void radiobuttonfindfirst_toggled(bool state);
void radiobuttondisplayfullpaths_toggled(bool state);
void radiobuttononematchperfile_toggled( bool state );

void listview_clicked(Q3ListViewItem *pitem);
void listview_setSorting( int column, bool ascending );
};

#endif // FINDEXTENSIONSPECDIALOG_H
