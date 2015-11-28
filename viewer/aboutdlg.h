// ---------------------------------------------------------------------------
// Copyright: (C) VFX Research 2002 - 2014. All Rights Reserved.
// ---------------------------------------------------------------------------
                                                                                
#ifndef ABOUTDIALOG_H
#define ABOUTDIALOG_H

#include <QObject>
#include <QDialog>
#include "config.h"
#include "extensionlib.h"
#include ".ui/ui_aboutbasedlg.h"

// --------------------------------------------------------------------------
// Definition of derived class
// --------------------------------------------------------------------------

class CAboutDialog : public QDialog,
			 public Ui_CAboutBaseDialog
{
	Q_OBJECT
public:
// ----- Constructor and Destructor -----------------------------------------

CAboutDialog(void ) : Ui_CAboutBaseDialog()
        {
	setupUi( this );
	};

~CAboutDialog() { };

// ----- Event handlers -----------------------------------------------------

protected slots:
void pushbuttonok_clicked( void )
	{
	accept();
	};
};

#endif // ABOUTDIALOG_H
