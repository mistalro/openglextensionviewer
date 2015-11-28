// ---------------------------------------------------------------------------
// Copyright: (C) VFX Research 2002 - 2014. All Rights Reserved.
// ---------------------------------------------------------------------------
                                                                                
#ifndef _CONFIGFILESETTINGSDIALOG_H_
#define _CONFIGFILESETTINGSDIAlOG_H_

#include "extensionlib.h"
#include <QObject>
#include ".ui/ui_configfilesettingsbasedlg.h"

#define CONFIGFILESETTINGS_OK     0x0001
#define CONFIGFILESETTINGS_CANCEL 0x0002

class CConfigFileSettingsDialog : public QDialog,
				 public Ui_CConfigFileSettingsBaseDialog
{
	Q_OBJECT

// ----- Internal variables -------------------------------------------------

CExtensionViewer        *m_pextcreator;
CConfigurationFileSettings  m_localconfig;
int 			  m_doupdate;

// ----- Constructor and Destructor -----------------------------------------
public:                                                                                
CConfigFileSettingsDialog() : Ui_CConfigFileSettingsBaseDialog()
        {
	setupUi( this );
	Init();
        };
                                                                                
~CConfigFileSettingsDialog() { };
                                                                                
// ----- Functions and Procedures -------------------------------------------
        
void Init( void )
	{
	m_doupdate    = true;
	m_pextcreator = NULL;
	}                                                                        
void SaveSettings();
void LoadSettings();
void SetPointer( CExtensionViewer *pextcreator );
void SetAutoLoadFlag( int value );
void SetAutoSaveFlag( int value );
void SetLoadRadioButtons( void );
void SetSaveRadioButtons( void );

void SetDialogData( void );

// ----- User Interface Handlers --------------------------------------------

protected slots:
void lineeditconfigfile_textChanged( const QString &string );
void pushbuttonbrowse_clicked();
void radiobuttonloadauto_clicked();
void radiobuttonloadprompt_clicked();
void radiobuttonloadnoaction_clicked();
void radiobuttonsaveauto_clicked();
void radiobuttonsaveprompt_clicked();
void radiobuttonsavenoaction_clicked();
void pushbuttonok_clicked();
void pushbuttoncancel_clicked();
void pushbuttonapply_clicked();
void pushbuttonreset_clicked();

};

#endif // _CONFIGFILES ETTINGSDIALOG_H_
