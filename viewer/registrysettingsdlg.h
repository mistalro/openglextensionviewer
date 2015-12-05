// ---------------------------------------------------------------------------
// Copyright: (C) VFX Research 2002 - 2014. All Rights Reserved.
// ---------------------------------------------------------------------------

#ifndef REGISTRYSETTINGSDIALOG_H
#define REGISTRYSETTINGSDIALOG_H

#include <cstdio>
#include <cstdlib>
#include <iostream>

#include "extensionlib.h"
#include ".ui/ui_registrysettingsbasedlg.h"
#include "webpagelistwidget.h"
#include "registryupdatefunc.h"

#define REGISTRYSETTINGS_OK     0x0001
#define REGISTRYSETTINGS_CANCEL 0x0000

// --------------------------------------------------------------------------
// Class to represent all the global settings
// --------------------------------------------------------------------------

class CRegistrySettingsDialog : public QDialog,
				public Ui_CRegistrySettingsBaseDialog,
				public CRegistryUpdateListFunc
{
	Q_OBJECT
	
public:

// ----- Internal variables ---------------------------------------------------

CExtensionViewer *m_pextcreator;
CExtensionSiteInfoList  m_localconfig;
int m_scriptmode;
int m_blockupdates;
int m_listpos;

// ----- Constructor and Destructor -------------------------------------------

CRegistrySettingsDialog() : Ui_CRegistrySettingsBaseDialog() 
	{ 
	setupUi( this );
	m_pextcreator = NULL;	
	m_blockupdates = 0;
	m_listpos = 0;
	m_webpagelistview->setFocus();
	};
	 
~CRegistrySettingsDialog() 
	{ 
	};

// ----- Functions and Procedures ---------------------------------------------

void SetPointer( CExtensionViewer *m_pextcreator );
void SetCheckBoxes( void );
void SetInputFilesRegistry( void );
void SetInputFilesGL( void );
void SetInputFilesWGL( void );
void SetInputFilesGLX( void );
void SetInputFilesCoreARB( void );
void SetScriptFiles( void );
void SetOutputFiles( void );
void SetScriptMode( int value );
void SetProgrammingLanguage( int mode );
void SetSiteList( void );

void SetDialogData( void );

void LoadSettings( void );
void SaveSettings( void );

// ----- Widget events ------------------------------------------------------

protected:

protected slots:
void reject( void ) { };

void pushbuttonok_clicked( void );
void pushbuttonapply_clicked( void );
void pushbuttoncancel_clicked( void );
void pushbuttonreset_clicked( void );
void pushbuttonadd_clicked( void );
void pushbuttonremove_clicked( void );
void pushbuttonglxbrowse_clicked( void );
void pushbuttonglbrowse_clicked( void );
void pushbuttonregistrybrowse_clicked( void );
void pushbuttonwglbrowse_clicked( void );
void pushbuttoncorearb_clicked( void );

void pushbuttonregistrywebpagebrowse_clicked( void );
void pushbuttonregistrylocaldirbrowse_clicked( void );

void editregistrylocaldir_textChanged( const QString & );
void editregistry_textChanged( const QString & );
void editregistrylocalcopy_textChanged( const QString & );
void editgl_textChanged( const QString & );
void editgllocalcopy_textChanged( const QString & );
void editwgl_textChanged( const QString & );
void editwgllocalcopy_textChanged( const QString & );
void editglx_textChanged( const QString & );
void editglxlocalcopy_textChanged( const QString & );
void editcorearb_textChanged(const QString &);
void editcorearblocalcopy_textChanged(const QString &);

void editfileextensionfilter_textChanged(const QString &);

void webpagelistview_selectionChanged();
void webpagelistview_mouseDoubleClicked( int item );
void webpagelistview_mousePressed( int item );
void webpagelistview_mouseReleased( int item );
void webpagelistview_mouseMoved( int item );

void checkboxdownloadheaderfiles_toggled( bool );
void checkboxreadheaderfiles_toggled( bool );
void checkboxreadextensionspec_toggled( bool );
void checkboxdownloadregistry_toggled( bool );
};

#endif // REGISTRYSETTINGSDIALOG_H
