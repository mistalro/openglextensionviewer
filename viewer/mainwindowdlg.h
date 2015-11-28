// ---------------------------------------------------------------------------
// Copyright: (C) VFX Research 2002 - 2014. All Rights Reserved.
// ---------------------------------------------------------------------------

#ifndef _MAINWINDOWDIALOG_H_
#define _MAINWINDOWDIALOG_H_

#include "config.h"
#include "q3listbox.h"
#include ".ui/ui_mainwindowbasedlg.h"
#include "extensiondlg.h"
#include "pixelformatdlg.h"
#include "displaysettingsdlg.h"
#include "scripteditordlg.h"
#include "outputfilesettingsdlg.h"
#include "registrysettingsdlg.h"
#include "updateextensionsdlg.h"
#include "configfilesettingsdlg.h"
#include "findfuncconstdlg.h"
#include "findextensionspecdlg.h"
#include "exitapplicationdlg.h"
#include "registryprogressdlg.h"
#include "registryfileprogressdlg.h"

#define LISTBOX_GLX_AVAILABLE    0x0001
#define LISTBOX_GLX_SELECTED     0x0002
#define LISTBOX_GL_AVAILABLE     0x0003
#define LISTBOX_GL_SELECTED      0x0004
#define LISTBOX_WGL_AVAILABLE    0x0005
#define LISTBOX_WGL_SELECTED     0x0006
#define LISTBOX_VENDOR_AVAILABLE 0x0007
#define LISTBOX_VENDOR_SELECTED  0x0008
#define LISTBOX_NEW              0x0009
#define LISTBOX_IGNORE           0x000A
#define LISTBOX_SYSTEM           0x000B

class CMainWindowDialog : public QMainWindow,
			public Ui_CMainWindowBaseDialog
{
    Q_OBJECT
   
    
public:

// ----- Local members ------------------------------------------------------

CExtensionViewer          m_extcreator;          // Extension manager
CDisplaySettingsList       m_displaysettingslist; // Screen settings
CPixelFormatDescriptorList *m_ppixelformatdescriptorlist;

// ----- Pointers to modeless dialog windows --------------------------------

CExtensionDialog          *m_pextensiondialog;
CScriptEditorDialog         *m_pscripteditordialog;
COutputFileSettingsDialog   *m_poutputsettingsdialog;
CPixelFormatDialog          *m_ppixelformatdialog;
CDisplaySettingsDialog      *m_pdisplaysettingsdialog;
CRegistrySettingsDialog     *m_pregistrysettingsdialog;
CConfigFileSettingsDialog   *m_pconfigfilesettingsdialog;
CFindFuncConstDialog        *m_pfindfuncconstdialog;
CFindExtensionSpecDialog    *m_pfindextensionspecdialog;
CRegistryProgressDialog     *m_pregistryprogressdialog;
CRegistryFileProgressDialog *m_pregistryfileprogressdialog;

int                        m_processbusy;

// ----- Constructor and desstructor ----------------------------------------

    CMainWindowDialog(QWidget* parent = 0, const char* name = 0, Qt::WFlags fl = 0 );
    ~CMainWindowDialog();
    /*$PUBLIC_FUNCTIONS$*/

// ----- Functions and procedures -------------------------------------------

void ListBoxSet( CExtensionListBox &listbox, CExtensionEntryList &extlist, 
			int selmode );
void ListBoxSet( int listid );
void ListBoxSetAll(); 

void ListBoxClearSelected( CExtensionListBox &listbox, int listid );
void ListBoxClearSelected( int listid );
void ListBoxClearSelected();

void ListBoxRemoveSelected( CExtensionListBox &listbox, int listid );

void ListBoxDeleteSelected( CExtensionListBox &listbox, int listid );
void ListBoxDeleteSelected( int listid );
void ListBoxDeleteSelected();

void ListBoxCopySelected( CExtensionListBox &listbox, int listid );
void ListBoxCopySelected( int listid );
void ListBoxCopy();

void ListBoxAddSelected( CExtensionListBox &listbox, int listid, int matchmode );
void ListBoxAddSelected( int listid );
void ListBoxAddSelected();

void ListBoxViewExtension( Q3ListBoxItem *pitem );

void CheckDryRunMode(void);
int  CheckNewExtensions( void );

void AutoLoadConfigurationFile( void );
void AutoSaveConfigurationFile( void );

void CleanupOnExit( void );

// ----- Slots for events ---------------------------------------------------

public slots:
    /*$PUBLIC_SLOTS$*/
  
    void closeEvent(QCloseEvent *e);
    void fileNew();
    void fileOpen();
    void fileOpenAndMerge();
    void fileSave();
    void fileSaveAs();
    void fileExit();

    void menubar_editundo_activated();
    void menubar_editredo_activated();
    void menubar_editclearall_activated();
    void menubar_editadd_activated();
    void menubar_editselectall_activated();
    void menubar_editremove_activated();
    void menubar_editchecksystem_activated();
    void menubar_editgenerateoutputfiles_activated();

    void menubar_optionsfilesdirectorysettings_activated();
    void menubar_optionsscriptsettings_activated();
    void menubar_optionsoutputsettings_activated();
    void menubar_optionsconfigurationfiles_activated();

    void menubar_headerfilesdownloadfiles_activated();
    void menubar_headerfilesreadfiles_activated();

    void menubar_registrydownloadpages_activated();
    void menubar_registrydownloadall_activated();
    void menubar_registrydownloadselected_activated();
    void menubar_registrydownloadnew_activated();
    void menubar_registryreadall_activated();
    void menubar_registryreadselected_activated();
    void menubar_registryreadnew_activated();

    void menubar_viewpixelformats_activated();
    void menubar_viewvideoresolutions_activated();

    void menubar_searchfindfuncconst_activated();
    void menubar_searchfindextensionspecs_activated();

    void menubar_activated( int );
   
    void helpIndex();
    void helpContents();
    void helpAbout();
  
    void listglavailable_doubleClicked( Q3ListBoxItem * );
    void listglselected_doubleClicked( Q3ListBoxItem * );
    void listwglavailable_doubleClicked( Q3ListBoxItem * );
    void listwglselected_doubleClicked( Q3ListBoxItem * );
    void listglxavailable_doubleClicked( Q3ListBoxItem * );
    void listglxselected_doubleClicked( Q3ListBoxItem * );
    void listvendoravailable_doubleClicked( Q3ListBoxItem * );
    void listvendorselected_doubleClicked( Q3ListBoxItem * );
    void listsystem_doubleClicked( Q3ListBoxItem * );
    void listnew_doubleClicked( Q3ListBoxItem * );
    void listignore_doubleClicked( Q3ListBoxItem * );    

    void listglavailable_itemsDropped( QString &string );
    void listglselected_itemsDropped( QString &string );
    void listglxavailable_itemsDropped( QString &string );
    void listglxselected_itemsDropped( QString &string );
    void listwglavailable_itemsDropped( QString &string );
    void listwglselected_itemsDropped( QString &string );
    void listvendoravailable_itemsDropped( QString &string );
    void listvendorselected_itemsDropped( QString &string );
    void listnew_itemsDropped( QString &string );
    void listignore_itemsDropped( QString &string );
    void listsystem_itemsDropped( QString &string );

    void pushbuttonclearall_clicked();
    void pushbuttonremove_clicked();
    void pushbuttonadd_clicked();
    void pushbuttonselectall_clicked();
    void pushbuttonundo_clicked();
    void pushbuttonredo_clicked();
    void pushbuttonchecksystem_clicked();
    void pushbuttongenerate_clicked();
    void pushbuttonexit_clicked();

protected:
    /*$PROTECTED_FUNCTIONS$*/

protected slots:
    /*$PROTECTED_SLOTS$*/

};

#endif

