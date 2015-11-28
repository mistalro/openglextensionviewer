// ---------------------------------------------------------------------------
// Copyright: (C) VFX Research 2002 - 2014. All Rights Reserved.
// ---------------------------------------------------------------------------

#ifndef SCRIPTEDITORDIALOG_H
#define SCRIPTEDITORDIALOG_H

using namespace std;

#include <cstdio>
#include <cstdlib>
#include <iostream>

//#ifndef _EXTCREATOR_
//#define _EXTCREATOR_
#include "extensionlib.h"
#include ".ui/ui_scripteditorbasedlg.h"
//#endif

class CScriptEditorDialog : public QDialog, 
				public Ui_CScriptEditorBaseDialog
{
	Q_OBJECT
	
public:

// ----- Internal variables ---------------------------------------------------

CExtensionViewer *m_pextcreator;
QString            m_scriptcopy;

// ----- Constructor and Destructor -------------------------------------------

CScriptEditorDialog() : Ui_CScriptEditorBaseDialog() 
	{ 
	setupUi( this );
	};
	 
~CScriptEditorDialog() { };

// ----- Functions and Procedures ---------------------------------------------

void LoadTextEditInternal();
void LoadTextEditExternal();
void SaveTextEditExternal();
void WriteExternalScript(const char *path, int index );

void SetPointer( CExtensionViewer *pcreator )
	{
	m_pextcreator = pcreator;
	};

void SetDialogData( void )
	{
	LoadTextEditInternal();
	LoadTextEditExternal();	
	}

// ----- User Interface Handlers --------------------------------------------

protected slots:
void pushbuttoncopy_clicked();
void pushbuttonsave_clicked();
void pushbuttonclear_clicked();
void pushbuttonrestore_clicked();
void pushbuttoncancel_clicked();
void pushbuttonapply_clicked();
void pushbuttonok_clicked();
};

#endif // SCRIPTEDITORDIALOG_H
