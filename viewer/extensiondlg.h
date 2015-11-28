// ---------------------------------------------------------------------------
// Copyright: (C) VFX Research 2002 - 2014. All Rights Reserved.
// ---------------------------------------------------------------------------

#ifndef EXTENSIONDIALOG_H
#define EXTENSIONDIALOG_H

#include "extensionlib.h"
#include "ui_extensionbasedlg.h"

#include <qapplication.h>
#include <qprogressbar.h>
#include <qlineedit.h>

// --------------------------------------------------------------------------
// Definition of derived class
// --------------------------------------------------------------------------

class CExtensionDialog : public QDialog,
			public Ui_CExtensionBaseDialog
{
	Q_OBJECT
	
public:

// ----- Internal variables -------------------------------------------------

int m_listid;				// Which list
int m_index;				// Which extension in list
CExtensionViewer *m_pextcreator; 	// Extension data
CExtensionEntry   *m_pextentry;		// Pointer to data
int m_noupdateflag;			// Update flag to prevent recursion

// ----- Constructor and Destructor -----------------------------------------

CExtensionDialog() : Ui_CExtensionBaseDialog() 
	{ 
	setupUi( this );
	m_listid = -1;
	m_index  = -1;
	m_pextcreator = NULL;
	m_noupdateflag = 0;
	};
	 
~CExtensionDialog() { };

// ----- Functions and Procedures -------------------------------------------

void SetPointer( CExtensionViewer *pdata );
void SetExtensionName( const char *pstr );
void SetIndex( int index, int listid );
void SetDialogData( void );
void SetComboBox( void );
void SetSelected( int value );

void IncrementIndex( void );
void DecrementIndex( void );

// ----- User interface events ----------------------------------------------

public slots:
void pushbuttonok_clicked( void );
void pushbuttonnext_clicked( void );
void pushbuttonprevious_clicked( void );
void pushbuttonremove_clicked( void );
void pushbuttonadd_clicked( void );
void pushbuttonfind_clicked();

void radioselected_toggled( bool value );
void radiocasesensitive_toggled( bool value );
void radiosearchforwards_toggled( bool value );
void radiowholewords_toggled( bool value );

void editextensionname_textChanged( const QString & );
void editfindtext_textChanged( const QString & );

void combobox_activated( const QString & );
};

#endif // EXTENSIONDIALOG_H
