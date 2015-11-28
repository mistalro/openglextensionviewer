// --------------------------------------------------------------------------
// Copyright: (C) VFX Research 2002 - 2014. All Rights Reserved.
// --------------------------------------------------------------------------
                                                                                
#ifndef EXTENSIONVIEWDIALOG_H
#define EXTENSIONVIEWDIALOG_H

#include "extensionlib.h"
#include "ui_extensionviewbasedlg.h"                                                                                 
#include <qapplication.h>
#include <qprogressbar.h>
#include <qtextedit.h>

// --------------------------------------------------------------------------
// Definition of derived class
// --------------------------------------------------------------------------

class CExtensionViewDialog : public QDialog,
				public Ui_CExtensionViewBaseDialog
{
        Q_OBJECT
                                                                                
public:
                                                                                
// ----- Internal variables -------------------------------------------------
                                                                               
STRPATH m_filepath;
 
// ----- Constructor and Destructor -----------------------------------------
                                                                                
CExtensionViewDialog() : Ui_CExtensionViewBaseDialog()
        {
	setupUi( this );
	m_filepath[0] = '\0';
        };
                                                                                
~CExtensionViewDialog() { };
                                                                                
// ----- Functions and Procedures -------------------------------------------
                                                                                
void SetExtensionPath( STRPATH filepath );                                                                                
void SetDialogData( void );

void pushbuttonok_clicked( void );
                                                                                
protected slots:
};
                                                                                
#endif // EXTENSIONVIEWDIALOG_H
 

