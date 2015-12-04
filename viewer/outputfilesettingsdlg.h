// ---------------------------------------------------------------------------
// Copyright: (C) VFX Research 2002 - 2014. All Rights Reserved.
// ---------------------------------------------------------------------------

#ifndef OUTPUTFILESETTINGSDIALOG_H
#define OUTPUTFILESETTINGSDIALOG_H

using namespace std;

#include <cstdio>
#include <cstdlib>
#include <iostream>

#include "extensionlib.h"
#include ".ui/ui_outputfilesettingsbasedlg.h"

#define OUTPUTFILESETTINGS_OK     0x0001
#define OUTPUTFILESETTINGS_CANCEL 0x0000

// --------------------------------------------------------------------------
// Class to represent all the global settings
// --------------------------------------------------------------------------

class COutputFileSettingsDialog : public QDialog,
				public Ui_COutputFileSettingsBaseDialog
{
	Q_OBJECT
	
public:

// ----- Internal variables ---------------------------------------------------

CExtensionViewer *m_pextcreator;
COutputFileSettings   m_localconfig;
int m_scriptmode;
int m_blockupdates;

// ----- Constructor and Destructor -------------------------------------------

COutputFileSettingsDialog() : Ui_COutputFileSettingsBaseDialog() 
	{ 
	setupUi( this );

	m_pextcreator = NULL;	
	m_scriptmode = 0;
	m_blockupdates = 0;
	};
	 
~COutputFileSettingsDialog() 
	{ 
	};

// ----- Functions and Procedures ---------------------------------------------

void SetPointer( CExtensionViewer *pextcreator );
void SetInputFilesRegistry( void );
void SetInputFilesGL( void );
void SetInputFilesWGL( void );
void SetInputFilesGLX( void );
void SetScriptFiles( void );
void SetOutputFiles( void );
void SetDialogData( void );
void SetScriptMode( int value );
void SetProgrammingLanguage( int mode );
void LoadSettings( void );
void SaveSettings( void );

// ----- Widget events ------------------------------------------------------

protected:

protected slots:
void editexternalscript_textChanged( const QString & );
void editoutputheaderfile_textChanged( const QString & );
void editoutputsourcefile_textChanged( const QString & );
void editoutputclassname_textChanged( const QString & );

void pushbuttonok_clicked( void );
void pushbuttonapply_clicked( void );
void pushbuttoncancel_clicked( void );
void pushbuttonreset_clicked( void );
void pushbuttonexternalbrowse_clicked( void );
void pushbuttonheaderbrowse_clicked( void ); 
void pushbuttonsourcebrowse_clicked( void );

void radiointernal_clicked();
void radioexternal_clicked();
void radioc_clicked();
void radiocpp_clicked();
void radiouseglxgetprocaddressarb_clicked();
};

#endif // OUTPUTFILESETTINGSDIALOG_H
