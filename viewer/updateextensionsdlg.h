// ---------------------------------------------------------------------------
// Copyright: (C) VFX Research 2002 - 2014. All Rights Reserved.
// ---------------------------------------------------------------------------

#ifndef UPDATEEXTENSIONSDIALOG_H
#define UPDATEEXTENSIONSDIALOG_H

#define UPDATE_OK     0x001
#define UPDATE_CANCEL 0x002
#define UPDATE_APPLY  0x003
#define UPDATE_RESET  0x004

#include ".ui/ui_updateextensionsbasedlg.h"
#include "extensionlib.h"

class CUpdateExtensionsDialog : public QDialog,
				public Ui_CUpdateExtensionsBaseDialog
{
	Q_OBJECT
	
public:

// ----- Internal variables -------------------------------------------------

CExtensionViewer *m_pextcreator;  // Global data
int 		   m_updatemode;   // Local copy
int		   m_blockupdates; // Block recursive updates of widgets

// ----- Constructor and Destructor -----------------------------------------

CUpdateExtensionsDialog() : Ui_CUpdateExtensionsBaseDialog() 
	{
	setupUi( this );
	m_blockupdates = 0;
	 };
	 
~CUpdateExtensionsDialog() { };

// ----- Functions and Procedures -------------------------------------------

void SaveSettings( void );
void LoadSettings( void );
void SetPointer( CExtensionViewer *pextcreator );
void SetList( void );
void SetAllCheckBoxes( void );
void SetState( int flag, int mode );

// ----- User Interface Handlers --------------------------------------------

protected:

protected slots:
void checkboxreadheaders_toggled( bool value );
void checkboxdownloadheaders_toggled( bool value );
void checkboxreadregistry_toggled( bool value );
void checkboxdownloadregistry_toggled( bool value );
void checkboxignoreextensions_toggled( bool value );

void listboxextensionsnotfound_doubleClicked( Q3ListBoxItem *pitem );

void pushbuttonok_clicked();
void pushbuttoncancel_clicked();
void pushbuttonapply_clicked();
void pushbuttonreset_clicked();
};

#endif // UPDATEEXTENSIONSDIALOG_H
