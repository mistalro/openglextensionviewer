// ---------------------------------------------------------------------------
// Copyright: (C) VFX Research 2002 - 2014. All Rights Reserved.
// ---------------------------------------------------------------------------

using namespace std;
                                                                                
#include <qlabel.h>
#include <q3listbox.h>
#include <qfiledialog.h>
#include <qvariant.h>
#include <qdialog.h>
#include <qprogressbar.h>
#include <qlineedit.h>
#include <qapplication.h>
#include <qtabwidget.h>
#include <string.h>
                                                                                
#include "extensionlib.h"
#include "extensionlistwidget/extensionlistwidget.h"
#include "mainwindowdlg.h"                      // -- Main Window
#include "pixelformatdlg.h"                     // -- Pixel formats
#include "displaysettingsdlg.h"
#include "registryfileprogressdlg.h"
#include "extensiondlg.h"
#include "scripteditordlg.h"                    // -- Script files
#include "generateprogressdlg.h"
#include "registryprogressdlg.h"
#include "registryfileprogressdlg.h"
#include "headerdownloadprogressdlg.h"
#include "headerfileprogressdlg.h"
#include "checksystemprogressdlg.h"
#include "outputfilesettingsdlg.h"
#include "registrysettingsdlg.h"
#include "updateextensionsdlg.h"
#include "exitapplicationdlg.h"
#include "aboutdlg.h"                                                                                
int g_verbose = 0;

// ---------------------------------------------------------------------------
// Constructor
// ---------------------------------------------------------------------------
                                                                                
CMainWindowDialog::CMainWindowDialog(QWidget* parent, 
					const char*, WFlags fl)
        : QMainWindow( parent, fl )
{
setupUi( this );

m_ppixelformatdescriptorlist = NULL;

m_pextensiondialog          = NULL;
m_pscripteditordialog       = NULL;
m_poutputsettingsdialog     = NULL;
m_ppixelformatdialog        = NULL;
m_pdisplaysettingsdialog    = NULL;
m_pregistrysettingsdialog   = NULL;
m_pconfigfilesettingsdialog = NULL;
m_pfindfuncconstdialog      = NULL;
m_pfindextensionspecdialog  = NULL;
m_pregistryprogressdialog   = NULL;
m_pregistryfileprogressdialog = NULL;
m_processbusy = 0;

setMinimumSize(1024,800);

// Load Configuration file here
AutoLoadConfigurationFile();

ListBoxSetAll();
}
                                                                                
// --------------------------------------------------------------------------
// Destructor
// --------------------------------------------------------------------------
                                                                                
CMainWindowDialog::~CMainWindowDialog()
{
                                                                                
}
                                                                                
// --------------------------------------------------------------------------
// Automatically load configuration files
// --------------------------------------------------------------------------

// The problem here is that we need to do two things:
//
// (1) Load the configuration file
//
// (2) If the autoload mode is set, then keep the configuration file
//
// However, the configuration file also stores the set of flags 
// indicating whether header files should be automatically read,
// and which of those extensions already selected.
//
// However, by reading the header files, the selection flags are lost
//
// These can be reloaded by calling
//
// CExtensionHeaderFileSet::Load 
//
// --------------------------------------------------------------------------

void CMainWindowDialog::AutoLoadConfigurationFile()
{
int result;

// Load the configuration file to get the configuration flags
result = m_extcreator.ConfigurationFileLoadAndMerge();

// Abort if the file wasn't loaded
if ( !result )
	{
#ifdef DEBUG
	cout << "No file loaded\n";
#endif
	return;
	}

// Get the auto-load flags
result = m_extcreator.GetAutoLoadConfigFlags();

#ifdef DEBUG
cout << "Loaded " << m_extcreator.m_sitelist.size() << "Items\n";
#endif

// Depending upon the auto-load flags, either ask for a file, use the
// default configuration file or just leave the configuration as default.
switch ( result )
	{
	case MODE_AUTOLOADPROMPT:	// Prompt the user
#ifdef DEBUG
		cout << "Autoload prompt\n";
#endif
		fileOpen();
		break;

	case MODE_AUTOLOADCONFIG:	// Already done
#ifdef DEBUG
		cout << "Autoload config\n";
#endif
		break;

	case MODE_AUTOLOADNOACTION:	// Leave configuration as default
	default:
#ifdef DEBUG
		cout << "Autoload no action\n";
#endif
		// Clear existing configuration
		m_extcreator.ConfigurationFileNew();  
		break;
	}

// Get the flags for the auto-reading of header files
result = m_extcreator.GetAutoReadHeaderFlags();

// In theory this should be optional, but in practise it is absolutely
// necessary to read this files in order to do any work, so the following
// line is commented out.
// if ( result & MODE_AUTOREADHEADERS )
//	{
	menubar_headerfilesreadfiles_activated();
//	}
	
#ifdef OPTION_AUTOREADREGISTRY
if ( result & MODE_AUTOREADREGISTRY )
	{
	// Automatically read registry from local files
	// Presently, disabled as we don't know how long it may take
	menubar_registryreadall_activated();
	}
#endif
}

// --------------------------------------------------------------------------
// Automatically save configuration files
// --------------------------------------------------------------------------                                                                                
void CMainWindowDialog::AutoSaveConfigurationFile()
{
CExitApplicationDialog exitdialog;
int result;
                                                                               
// ----- Determine how autosaving of configuration files should be handled
                                                                               
switch ( m_extcreator.GetAutoSaveConfigFlags() )
        {
        case MODE_AUTOSAVEPROMPT:
                result = exitdialog.exec();
                break;
                                                                               
        case MODE_AUTOSAVECONFIG:
                result = EXIT_YES;              // Always savec configuration
                break;
                                                                               
        case MODE_AUTOSAVENOACTION:
        default:
                result = EXIT_NO;
                break;
        }
                                                                               
switch ( result )
        {
        case EXIT_YES:
                m_extcreator.ConfigurationFileSave();
                qApp->exit(0);
                break;

        case EXIT_NO:
                qApp->exit(0);
                break;

        case EXIT_CANCEL:
        default:
                break;
        }
}

// --------------------------------------------------------------------------
// Cleanup on exit
// --------------------------------------------------------------------------

void CMainWindowDialog::CleanupOnExit( void )
{
if ( m_pregistryfileprogressdialog )
	{
	m_pregistryfileprogressdialog->pushbuttoncancel_clicked();
	}
}

// --------------------------------------------------------------------------
// Attempt to end application was made
// --------------------------------------------------------------------------
                                                                                
void CMainWindowDialog::closeEvent(QCloseEvent* qce)
{
AutoSaveConfigurationFile();
qce->accept();
}

// ===========================================================================
// MENU BAR OPTIONS
// ===========================================================================
                                                                                
// ---------------------------------------------------------------------------
// Menu option - Menu was selected
// ---------------------------------------------------------------------------
                                                                                
void CMainWindowDialog::menubar_activated( int )
{
                                                                                
}
                                                                                
// ===========================================================================
// FILE OPTIONS
// ===========================================================================
                                                                                
// ---------------------------------------------------------------------------
// Create a new configuration file
// ---------------------------------------------------------------------------
                                                                                
static const char *str_unknown = "unknown";

void CMainWindowDialog::fileNew()
{
m_extcreator.ConfigurationFileNew();
                            
ListBoxSetAll();

// All configuration options have been reset, update the various dialog
// windows

if ( m_pextensiondialog )
	{
	m_pextensiondialog->SetExtensionName( str_unknown );
	m_pextensiondialog->SetDialogData();
	}

if ( m_pscripteditordialog )
	{
	m_pscripteditordialog->SetDialogData();
	}

if ( m_poutputsettingsdialog )
	{
	m_poutputsettingsdialog->SetDialogData();	
	}

if ( m_pregistrysettingsdialog )
	{
	m_pregistrysettingsdialog->SetDialogData();
	}

if ( m_pconfigfilesettingsdialog )
	{
	m_pconfigfilesettingsdialog->SetDialogData();
	}
}

// ---------------------------------------------------------------------------
// Open a configuration file
// ---------------------------------------------------------------------------
                                                                                
void CMainWindowDialog::fileOpen()
{
QFileDialog filedlg;
QString     filepath;
string 	    temp;
                                                                                
filepath = filedlg.getOpenFileName(
                           ".",
                           "*.cfg, *.txt",
                           this,
                           "Load configuration",
                           "Choose configuration file to open and read" );
                                                                                
if ( filepath.ascii() != NULL )
        {
        temp = (char *) filepath.ascii();
                                                                                
        m_extcreator.ConfigurationFileLoad( temp );

	ListBoxSetAll();
        }
}
                                                                                
// ---------------------------------------------------------------------------
// Open and merge a configuration file
// ---------------------------------------------------------------------------
                                                                                
void CMainWindowDialog::fileOpenAndMerge()
{
QFileDialog filedlg;
QString     filepath;
string 	    temp;
                                      
filepath = filedlg.getOpenFileName(
                           ".",
                           "Configuration files (*.cfg)",
                           this,
                           "Load and merge configuration",
                           "Choose configuration file to open and merge" );
                                                                                
if ( filepath.ascii() != NULL )
        {
        temp = (char *) filepath.ascii();
                                                                                
        m_extcreator.ConfigurationFileLoadAndMerge( temp );

	ListBoxSetAll();
        }
}

// ---------------------------------------------------------------------------
// Save the current configuration
// ---------------------------------------------------------------------------
                                                                                
void CMainWindowDialog::fileSave()
{
QFileDialog filedlg;
QString     filepath;
string 	    temp;

if ( m_extcreator.m_configfilesettings.GetNewConfigFlag() )
        {
        filepath = filedlg.getSaveFileName(
                ".",
                "*.cfg, *.txt",
                this,
                "Save configuration",
                "Choose configuration file to save" );
                                                                                
        if ( filepath.ascii() != NULL )
                {
                temp = (char *) filepath.ascii();
                                                                                
                m_extcreator.ConfigurationFileSaveAs( temp );
                }
        }
else
	{
        m_extcreator.ConfigurationFileSave();
	}
}

// ---------------------------------------------------------------------------
// Save the current configuration to a file
// ---------------------------------------------------------------------------
                                                                                
void CMainWindowDialog::fileSaveAs()
{
QFileDialog filedlg;
QString     filepath;
string      temp;

filepath = filedlg.getSaveFileName(
        ".",
        "Configuration files (*.cfg)",
        this,
        "Save configuration",
        "Choose configuration file to save as" );

if ( filepath.ascii() != NULL )
        {
        temp = (char *) filepath.ascii();
                                                                                
        m_extcreator.ConfigurationFileSaveAs( temp );
        }
}

// ---------------------------------------------------------------------------
// Exit the application
// ---------------------------------------------------------------------------

void CMainWindowDialog::fileExit()
{
AutoSaveConfigurationFile();
}

// ===========================================================================
// EDIT MENU
// ===========================================================================
                                                                                
// ---------------------------------------------------------------------------
// Menu option - Undo the last edit command
// ---------------------------------------------------------------------------
                                                                                
void CMainWindowDialog::menubar_editundo_activated()
{
m_extcreator.m_headerfileset.UndoState();
}
                                                                                
// ---------------------------------------------------------------------------
// Menu option - Redo the last edit command
// ---------------------------------------------------------------------------
                                                                                
void CMainWindowDialog::menubar_editredo_activated()
{
m_extcreator.m_headerfileset.RedoState();
}
                                                                                
// ---------------------------------------------------------------------------
// Menu option - Clear All
// ---------------------------------------------------------------------------
                                                                                
void CMainWindowDialog::menubar_editclearall_activated()
{
m_extcreator.m_headerfileset.SaveState();

switch ( m_tabcontrol->currentPageIndex() )
	{
	case 0: // GL
		m_extcreator.m_headerfileset.ListClearAllFlags( LIST_GL );
		ListBoxSet( LISTBOX_GL_SELECTED );
		break;

	case 1: // WGL
		m_extcreator.m_headerfileset.ListClearAllFlags( LIST_WGL );
		ListBoxSet( LISTBOX_WGL_SELECTED );
		break;
	
	case 2: // GLX
		m_extcreator.m_headerfileset.ListClearAllFlags( LIST_GLX );
		ListBoxSet( LISTBOX_GLX_SELECTED );
		break;

	case 3: // Vendor
		m_extcreator.m_headerfileset.ListClearAllFlags( LIST_VENDOR );
		ListBoxSet( LISTBOX_VENDOR_SELECTED );
		break;

	case 4:	// New/Ignored
		m_extcreator.m_headerfileset.ListClearAllFlags( LIST_NEW );
		m_extcreator.m_headerfileset.ListClearAllFlags( LIST_IGNORE );
		ListBoxSet( LISTBOX_NEW );
		ListBoxSet( LISTBOX_IGNORE );
		break;

	case 5: // System
		m_extcreator.m_headerfileset.ListClearAllFlags( LIST_SYSTEM );
		ListBoxSet( LISTBOX_SYSTEM );
		break;
	
	default:
		break;
	}
}

// ---------------------------------------------------------------------------
// Menu option - Add Selected
// ---------------------------------------------------------------------------
                                                                                
void CMainWindowDialog::menubar_editadd_activated()
{
m_extcreator.m_headerfileset.SaveState();
ListBoxAddSelected();
ListBoxSetAll();
}
                                                                                
// ---------------------------------------------------------------------------
// Menu option - Select All
// ---------------------------------------------------------------------------
                                                                                
void CMainWindowDialog::menubar_editselectall_activated()
{
m_extcreator.m_headerfileset.SaveState();

switch ( m_tabcontrol->currentPageIndex() )
        {
        case 0: // GL
		m_extcreator.m_headerfileset.ListSetAllFlags( LIST_GL );
		ListBoxSet( LISTBOX_GL_SELECTED );
                break;
                                                                                
        case 1: // WGL
		m_extcreator.m_headerfileset.ListSetAllFlags( LIST_WGL );
		ListBoxSet( LISTBOX_WGL_SELECTED );
                break;
                break;
                                                                                
        case 2: // GLX
		m_extcreator.m_headerfileset.ListSetAllFlags( LIST_GLX );
		ListBoxSet( LISTBOX_GLX_SELECTED );
                break;
                                                                                
        case 3: // Vendor
		m_extcreator.m_headerfileset.ListSetAllFlags( LIST_VENDOR );
		ListBoxSet( LISTBOX_VENDOR_SELECTED );
                break;
                                                                                
        case 4: // New/Ignored
		ListBoxSet( LISTBOX_NEW );
		ListBoxSet( LISTBOX_IGNORE );
                break;
                                                                                
        case 5: // System
		ListBoxSet( LISTBOX_SYSTEM );
                break;
                                                                                
        default:
                break;
        }
}

// --------------------------------------------------------------------------
// Menu option - Remove 
// --------------------------------------------------------------------------

void CMainWindowDialog::menubar_editremove_activated()
{
m_extcreator.m_headerfileset.SaveState();

ListBoxDeleteSelected();
ListBoxSetAll();
}

// --------------------------------------------------------------------------
// Menu option - Check System
// --------------------------------------------------------------------------

void CMainWindowDialog::menubar_editchecksystem_activated()
{
CCheckSystemProgressDialog checksystemdialog;

if (0 == m_processbusy)
	{
	m_processbusy = 1;

	if ( m_ppixelformatdescriptorlist == NULL )
       	{
       		m_ppixelformatdescriptorlist = new CPixelFormatDescriptorList;
        }

	// Display the progress dialog
		{
       		CCheckSystemProgressDialog checksystemdialog;
   		checksystemdialog.show();

        	m_ppixelformatdescriptorlist->GetAllFormats( checksystemdialog, 1);
        	}

	// Save state for undo
	m_extcreator.m_headerfileset.SaveState();

	// Clear current state
	m_extcreator.m_headerfileset.ListClearAllFlags();

	// Read through the pixel formats
	m_extcreator.m_headerfileset.ReadPixelFormatList( *m_ppixelformatdescriptorlist );

	ListBoxSetAll();

	m_processbusy = 0;
	}
}

// --------------------------------------------------------------------------
// Menu option - Check System
// --------------------------------------------------------------------------

void CMainWindowDialog::menubar_editgenerateoutputfiles_activated()
{
CGenerateProgressDialog generateprogressdlg;
					
if ( m_processbusy == 0 )
	{                                                    
	m_processbusy = 1;

	generateprogressdlg.show();
	generateprogressdlg.SetFilenames( 
		m_extcreator.m_outputfilesettings.m_outputheaderfile.data(),
       	        m_extcreator.m_outputfilesettings.m_outputsourcefile.data() );

	m_extcreator.WriteGeneratedFiles( generateprogressdlg );

	m_processbusy = 0;
	}
}

// ===========================================================================
// SEARCH MENU
// ===========================================================================

// ---------------------------------------------------------------------------
// Search function and constant lists
// ---------------------------------------------------------------------------

void CMainWindowDialog::menubar_searchfindfuncconst_activated()
{
if ( !m_pfindfuncconstdialog )
	{
	m_pfindfuncconstdialog = new CFindFuncConstDialog;

	m_pfindfuncconstdialog->SetPointer( &m_extcreator );
	}
else
	{
	m_pfindfuncconstdialog->raise();
	}

m_pfindfuncconstdialog->show();
}

// ---------------------------------------------------------------------------
// Search extension specifications
// ---------------------------------------------------------------------------

void CMainWindowDialog::menubar_searchfindextensionspecs_activated()
{
if ( !m_pfindextensionspecdialog )
	{
	m_pfindextensionspecdialog = new CFindExtensionSpecDialog;

	m_pfindextensionspecdialog->SetPointer( &m_extcreator );
	}
else
	{
	m_pfindextensionspecdialog->raise();
	}
	
m_pfindextensionspecdialog->show();
}

// ===========================================================================
// OPTIONS MENU
// ===========================================================================

// ---------------------------------------------------------------------------
// Menu option - File and Directory settings
// ---------------------------------------------------------------------------

void CMainWindowDialog::menubar_optionsfilesdirectorysettings_activated() 
{ 
if ( !m_pregistrysettingsdialog )
	{
	m_pregistrysettingsdialog = new CRegistrySettingsDialog;

	m_pregistrysettingsdialog->SetPointer( &m_extcreator );
	}
else
	{
	m_pregistrysettingsdialog->raise();
	}
	
m_pregistrysettingsdialog->show();
}

// ---------------------------------------------------------------------------
// Menu option - Script settings
// ---------------------------------------------------------------------------

void CMainWindowDialog::menubar_optionsscriptsettings_activated() 
{ 
if ( !m_pscripteditordialog )
        {
        m_pscripteditordialog = new CScriptEditorDialog;
                                                                                
        m_pscripteditordialog->SetPointer( &m_extcreator );
        }
else
	{
        m_pscripteditordialog->raise();
	}
                                                                                
m_pscripteditordialog->SetDialogData();
m_pscripteditordialog->show();
}

// ---------------------------------------------------------------------------
// Menu option - Script settings
// ---------------------------------------------------------------------------

void CMainWindowDialog::menubar_optionsoutputsettings_activated() 
{ 
if ( !m_poutputsettingsdialog )
	{
	m_poutputsettingsdialog = new COutputFileSettingsDialog;

	m_poutputsettingsdialog->SetPointer( &m_extcreator );
	}
else
	{
	m_poutputsettingsdialog->raise();
	}

m_poutputsettingsdialog->show();
}

// ---------------------------------------------------------------------------
// Menu option - Configuration files
// ---------------------------------------------------------------------------

void CMainWindowDialog::menubar_optionsconfigurationfiles_activated()
{
if ( !m_pconfigfilesettingsdialog )
	{
	m_pconfigfilesettingsdialog = new CConfigFileSettingsDialog;

	m_pconfigfilesettingsdialog->SetPointer( &m_extcreator );
	}
else
	{
	m_pconfigfilesettingsdialog->raise();
	}

m_pconfigfilesettingsdialog->show();
}

// ===========================================================================
// HEADER FILE OPTIONS
// ===========================================================================

// ---------------------------------------------------------------------------
// Menu option - Read header files
// ---------------------------------------------------------------------------

void CMainWindowDialog::menubar_headerfilesreadfiles_activated() 
{ 
CHeaderFileProgressDialog headerfileprogressdlg;
int result = 0;

headerfileprogressdlg.show();
headerfileprogressdlg.raise();
headerfileprogressdlg.activateWindow();

result = m_extcreator.ReadAllHeaderFiles( headerfileprogressdlg );

if ( result != FLAG_ALL )
	{
	m_extcreator.m_headerfileset.ClearLists( FLAG_ALL );
	}

ListBoxSetAll();
}

// ---------------------------------------------------------------------------
// Check dry-run mode
// ---------------------------------------------------------------------------

void CMainWindowDialog::CheckDryRunMode( void )
{
QMessageBox msgbox;
int result = 0;

msgbox.setText( "Perform dry-run?");
msgbox.setInformativeText( "Dry run will only download top-level file.");
msgbox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
msgbox.setDefaultButton(QMessageBox::No);

result = msgbox.exec();

m_extcreator.m_registrysettings.SetDryrunmode( (result == QMessageBox::Yes) );
}

// ---------------------------------------------------------------------------
// Menu option - Download header files
// ---------------------------------------------------------------------------

void CMainWindowDialog::menubar_headerfilesdownloadfiles_activated() 
{ 
CHeaderDownloadProgressDialog headerfiledownloaddlg;

CheckDryRunMode();

headerfiledownloaddlg.show();
headerfiledownloaddlg.raise();
headerfiledownloaddlg.activateWindow();

m_extcreator.DownloadAllRegistryHeaders( headerfiledownloaddlg );

ListBoxSetAll();
}

// ===========================================================================
// REGISTRY OPTIONS
// ===========================================================================

void CMainWindowDialog::menubar_registrydownloadpages_activated()
{
if ( !m_pregistryprogressdialog )
	{
	m_pregistryprogressdialog = new CRegistryProgressDialog;
	}

CheckDryRunMode();

m_pregistryprogressdialog->show();
m_extcreator.DownloadAllRegistryWebpages( *m_pregistryprogressdialog, DOWNLOAD_TOPLEVEL );
m_pregistryprogressdialog->exec();
}

// ---------------------------------------------------------------------------
// Menu option - Download all registry files
// ---------------------------------------------------------------------------

void CMainWindowDialog::menubar_registrydownloadall_activated() 
{ 
if ( !m_pregistryprogressdialog )
	{
	m_pregistryprogressdialog = new CRegistryProgressDialog;
	}

CheckDryRunMode();

m_pregistryprogressdialog->show();
m_extcreator.DownloadAllRegistryWebpages( *m_pregistryprogressdialog, DOWNLOAD_ALL );
m_pregistryprogressdialog->exec();
}

// ---------------------------------------------------------------------------
// Menu option - Download selected registry extension files
// ---------------------------------------------------------------------------

void CMainWindowDialog::menubar_registrydownloadselected_activated() 
{ 
if ( !m_pregistryprogressdialog )
	{
	m_pregistryprogressdialog = new CRegistryProgressDialog;
	}

CheckDryRunMode();

m_pregistryprogressdialog->show();
m_extcreator.DownloadRegistryWebpage( 0, *m_pregistryprogressdialog, DOWNLOAD_SELECTED );
m_pregistryprogressdialog->exec();
}

// ---------------------------------------------------------------------------
// Menu option - Download new registry extension files
// ---------------------------------------------------------------------------

void CMainWindowDialog::menubar_registrydownloadnew_activated() 
{ 
if ( !m_pregistryprogressdialog )
	{
	m_pregistryprogressdialog = new CRegistryProgressDialog;
	}

CheckDryRunMode();

m_pregistryprogressdialog->show();
m_extcreator.DownloadRegistryWebpage( 0, *m_pregistryprogressdialog, DOWNLOAD_NEW );
m_pregistryprogressdialog->exec();
}

// ---------------------------------------------------------------------------
// Menu option - Read all registry extensions
// ---------------------------------------------------------------------------
                                                                                
void CMainWindowDialog::menubar_registryreadall_activated()
{
if ( !m_pregistryfileprogressdialog )
	{
	m_pregistryfileprogressdialog = new CRegistryFileProgressDialog;
	}

m_pregistryfileprogressdialog->show();
                                                                                
m_extcreator.ReadAllRegistrySites( *m_pregistryfileprogressdialog, READ_ALL );
                                                                                
m_extcreator.m_headerfileset.ListSortAll();

ListBoxSetAll();
}

// ---------------------------------------------------------------------------
// Menu option - Read selected registry extension files
// ---------------------------------------------------------------------------

void CMainWindowDialog::menubar_registryreadselected_activated() 
{ 
if ( !m_pregistryfileprogressdialog )
	{
	m_pregistryfileprogressdialog = new CRegistryFileProgressDialog;
	}

m_pregistryfileprogressdialog->show();

m_extcreator.ReadAllRegistrySites( *m_pregistryfileprogressdialog, READ_SELECTED );

ListBoxSetAll();
}

// ---------------------------------------------------------------------------
// Menu option - Read new registry extension files
// ---------------------------------------------------------------------------

void CMainWindowDialog::menubar_registryreadnew_activated()
{
if ( !m_pregistryfileprogressdialog )
	{
	m_pregistryfileprogressdialog = new CRegistryFileProgressDialog;
	}

m_pregistryprogressdialog->show();

m_extcreator.ReadAllRegistrySites( *m_pregistryfileprogressdialog, READ_NEW );

ListBoxSetAll();
}

// ---------------------------------------------------------------------------
// Menu option - View pixel format lists
// ---------------------------------------------------------------------------

void CMainWindowDialog::menubar_viewpixelformats_activated() 
{ 
CCheckSystemProgressDialog progressdlg;

if ( m_ppixelformatdescriptorlist == NULL )
	{
	m_ppixelformatdescriptorlist = new CPixelFormatDescriptorList;
	}

progressdlg.show();
m_ppixelformatdescriptorlist->GetAllFormats( progressdlg, -1 );

if ( !m_ppixelformatdialog )
	{
	m_ppixelformatdialog = new CPixelFormatDialog;

	m_ppixelformatdialog->SetPointer( m_ppixelformatdescriptorlist );

	m_ppixelformatdialog->SetAllItems();
	}
else
	{
	m_ppixelformatdialog->raise();
	}

m_ppixelformatdialog->show();
}

// ---------------------------------------------------------------------------
// Menu option - View video resolutions
// ---------------------------------------------------------------------------

void CMainWindowDialog::menubar_viewvideoresolutions_activated() 
{ 
m_displaysettingslist.GetAllDisplaySettings();

if ( !m_pdisplaysettingsdialog )
	{
	m_pdisplaysettingsdialog = new CDisplaySettingsDialog;

	m_pdisplaysettingsdialog->SetPointer( &m_displaysettingslist );	
	m_pdisplaysettingsdialog->SetAllItems();
	}
else
	{
	m_pdisplaysettingsdialog->raise();
	}

m_pdisplaysettingsdialog->show();
}

// ===========================================================================
// HELP OPTIONS
// ===========================================================================

// ---------------------------------------------------------------------------
// Menu option - Help Index
// ---------------------------------------------------------------------------

void CMainWindowDialog::helpIndex() 
{ 
}

// ---------------------------------------------------------------------------
// Menu option - Help Contents
// ---------------------------------------------------------------------------

void CMainWindowDialog::helpContents() 
{ 
}

// ---------------------------------------------------------------------------
// Menu option - Help About
// ---------------------------------------------------------------------------

void CMainWindowDialog::helpAbout() 
{ 
CAboutDialog aboutdialog;

aboutdialog.exec();
}

// ===========================================================================
// GL LIST EVENTS
// ===========================================================================

void CMainWindowDialog::listglavailable_itemsDropped( QString &string )
{
#ifdef DEBUG
cout << "GL Available dropped ("<< string.ascii() <<")\n";
#endif

m_extcreator.m_headerfileset.SaveState();
m_extcreator.m_headerfileset.ListUnselectExtensionString( 
	LIST_GL, (char *) string.ascii(), FLAG_OUTPUT, MATCH_EXACTLY);

ListBoxSetAll();
}

void CMainWindowDialog::listglselected_itemsDropped( QString &string )
{
#ifdef DEBUG
cout << "GL Selected dropped ("<<string.ascii()<< ")\n";
#endif

m_extcreator.m_headerfileset.SaveState();
m_extcreator.m_headerfileset.ListSelectExtensionString( 
	LIST_GL, (char *) string.ascii(), FLAG_OUTPUT, 
	MATCH_EXACTLY, UPDATE_NONE );

ListBoxSetAll();
}

void CMainWindowDialog::listglxavailable_itemsDropped( QString &string )
{
#ifdef DEBUG
cout << "GLX Available dropped ("<<string.ascii()<<")\n";
#endif

m_extcreator.m_headerfileset.SaveState();
m_extcreator.m_headerfileset.ListUnselectExtensionString( 
	LIST_GLX, (char *) string.ascii(), FLAG_OUTPUT, MATCH_EXACTLY );

ListBoxSetAll();
}

void CMainWindowDialog::listglxselected_itemsDropped( QString &string )
{
#ifdef DEBUG
cout << "GLX Selected dropped (" << string.ascii() << ")\n";
#endif

m_extcreator.m_headerfileset.SaveState();
m_extcreator.m_headerfileset.ListSelectExtensionString( 
	LIST_GLX, (char *) string.ascii(), FLAG_OUTPUT, 
	MATCH_EXACTLY, UPDATE_NONE );

ListBoxSetAll();
}

void CMainWindowDialog::listwglavailable_itemsDropped( QString &string )
{
#ifdef DEBUG
cout << "WGL Available dropped (" << string.ascii() << "\n";
#endif

m_extcreator.m_headerfileset.SaveState();
m_extcreator.m_headerfileset.ListUnselectExtensionString( 
	LIST_WGL, (char *) string.ascii(), FLAG_OUTPUT, MATCH_EXACTLY );

ListBoxSetAll();
}

void CMainWindowDialog::listwglselected_itemsDropped( QString &string )
{
#ifdef DEBUG
cout << "WGL Selected dropped (" << string.ascii() << ")\n";
#endif

m_extcreator.m_headerfileset.SaveState();
m_extcreator.m_headerfileset.ListSelectExtensionString( 
	LIST_WGL, (char *) string.ascii(), 
	FLAG_OUTPUT, MATCH_EXACTLY, UPDATE_NONE );

ListBoxSetAll();
}

void CMainWindowDialog::listvendoravailable_itemsDropped( QString &string )
{
#ifdef DEBUG
cout << "Vendor Available dropped ("<< string.ascii() <<")\n";
#endif

m_extcreator.m_headerfileset.SaveState();

m_extcreator.m_headerfileset.ListUnselectExtensionString( 
	LIST_VENDOR, (char *) string.ascii(), FLAG_OUTPUT, MATCH_EXACTLY);

m_extcreator.m_headerfileset.ListUnselectExtensionString( 
	LIST_GL, (char *) string.ascii(), FLAG_OUTPUT, MATCH_BEGINNING);

m_extcreator.m_headerfileset.ListUnselectExtensionString( 
	LIST_GLX, (char *) string.ascii(), FLAG_OUTPUT, MATCH_BEGINNING);

m_extcreator.m_headerfileset.ListUnselectExtensionString( 
	LIST_WGL, (char *) string.ascii(), FLAG_OUTPUT, MATCH_BEGINNING);

ListBoxSetAll();
}

void CMainWindowDialog::listvendorselected_itemsDropped( QString &string )
{
#ifdef DEBUG
cout<< "Vendor Selected dropped ("<< string.ascii() <<")\n";
#endif

m_extcreator.m_headerfileset.SaveState();

m_extcreator.m_headerfileset.ListSelectExtensionString( 
	LIST_VENDOR, (char *) string.ascii(), FLAG_OUTPUT, 
		MATCH_EXACTLY, UPDATE_NONE);

m_extcreator.m_headerfileset.ListSelectExtensionString( 
	LIST_GL, (char *) string.ascii(), 
		FLAG_OUTPUT, MATCH_BEGINNING, UPDATE_NONE);

m_extcreator.m_headerfileset.ListSelectExtensionString( 
	LIST_GLX, (char *) string.ascii(), 
		FLAG_OUTPUT, MATCH_BEGINNING, UPDATE_NONE);

m_extcreator.m_headerfileset.ListSelectExtensionString( 
	LIST_WGL, (char *) string.ascii(), 
		FLAG_OUTPUT, MATCH_BEGINNING, UPDATE_NONE);

ListBoxSetAll();
}

void CMainWindowDialog::listnew_itemsDropped( QString &string )
{
#ifdef DEBUG
cout << "New dropped ("<< string.ascii()<<")\n";
#endif

m_extcreator.m_headerfileset.ListRemoveExtensionString( 
	LIST_IGNORE, (char *) string.ascii() );

ListBoxSetAll();
}

void CMainWindowDialog::listignore_itemsDropped( QString &string )
{
#ifdef DEBUG
cout << "Ignore dropped (" <<string.ascii() << ")\n";
#endif

m_extcreator.m_headerfileset.ListAddExtensionString( 
	LIST_IGNORE, (char *) string.ascii() );

ListBoxSetAll();
}

void CMainWindowDialog::listsystem_itemsDropped( QString &string )
{
#ifdef DEBUG
cout << "Items dropped ("<<string.ascii()<< ")\n";
#else
Q_UNUSED( string);
#endif
}

// ---------------------------------------------------------------------------
// Available list item was double-clicked
// ---------------------------------------------------------------------------

void CMainWindowDialog::listglavailable_doubleClicked( Q3ListBoxItem *pitem ) 
{ 
ListBoxViewExtension( pitem );
}

// ---------------------------------------------------------------------------
// Selected list item was double-clicked
// ---------------------------------------------------------------------------

void CMainWindowDialog::listglselected_doubleClicked( Q3ListBoxItem *pitem ) 
{ 
ListBoxViewExtension( pitem );
}

// ===========================================================================
// WGL LIST EVENTS
// ===========================================================================

// ---------------------------------------------------------------------------
// Available list item was double clicked
// ---------------------------------------------------------------------------

void CMainWindowDialog::listwglavailable_doubleClicked( Q3ListBoxItem *pitem ) 
{ 
ListBoxViewExtension( pitem );
}

// ---------------------------------------------------------------------------
// Selected list item was double clicked
// ---------------------------------------------------------------------------

void CMainWindowDialog::listwglselected_doubleClicked( Q3ListBoxItem *pitem ) 
{ 
ListBoxViewExtension( pitem );
}

// ===========================================================================
// GLX LIST EVENTS
// ===========================================================================

// ---------------------------------------------------------------------------
// Available list item was double clicked
// ---------------------------------------------------------------------------

void CMainWindowDialog::listglxavailable_doubleClicked( Q3ListBoxItem *pitem ) 
{ 
ListBoxViewExtension( pitem );
}

// ---------------------------------------------------------------------------
// Selected list item was double clicked
// ---------------------------------------------------------------------------

void CMainWindowDialog::listglxselected_doubleClicked( Q3ListBoxItem *pitem ) 
{
ListBoxViewExtension( pitem );
}

// ===========================================================================
// VENDOR LIST EVENTS
// ===========================================================================

// ---------------------------------------------------------------------------
// Available vendor list was double clicked
// ---------------------------------------------------------------------------

void CMainWindowDialog::listvendoravailable_doubleClicked( Q3ListBoxItem *pitem ) 
{ 
Q_UNUSED(pitem);
}

// ---------------------------------------------------------------------------
// Selected vendor list was double clicked
// ---------------------------------------------------------------------------

void CMainWindowDialog::listvendorselected_doubleClicked( Q3ListBoxItem *pitem ) 
{ 
Q_UNUSED(pitem);
}

// ---------------------------------------------------------------------------
// System list was double clicked
// ---------------------------------------------------------------------------

void CMainWindowDialog::listsystem_doubleClicked( Q3ListBoxItem *pitem )
{
ListBoxViewExtension( pitem );
}

// ---------------------------------------------------------------------------
// New list was double clicked
// ---------------------------------------------------------------------------

void CMainWindowDialog::listnew_doubleClicked( Q3ListBoxItem *pitem )
{
ListBoxViewExtension( pitem );
}

// ---------------------------------------------------------------------------
// Ignore list was double clicked
// ---------------------------------------------------------------------------

void CMainWindowDialog::listignore_doubleClicked( Q3ListBoxItem *pitem )
{
ListBoxViewExtension( pitem );
}

// ===========================================================================
// PUSH BUTTON EVENTS
// ===========================================================================

// ---------------------------------------------------------------------------
// Clear all lists
// ---------------------------------------------------------------------------

void CMainWindowDialog::pushbuttonclearall_clicked() 
{ 
menubar_editclearall_activated();
}

// ---------------------------------------------------------------------------
// Remove selected items from list
// ---------------------------------------------------------------------------

void CMainWindowDialog::pushbuttonremove_clicked() 
{ 
menubar_editremove_activated();
}

// ---------------------------------------------------------------------------
// Add selected items to list
// ---------------------------------------------------------------------------

void CMainWindowDialog::pushbuttonadd_clicked() 
{ 
menubar_editadd_activated();
}

// ---------------------------------------------------------------------------
// Select all items
// ---------------------------------------------------------------------------

void CMainWindowDialog::pushbuttonselectall_clicked() 
{ 
menubar_editselectall_activated();
}

// ---------------------------------------------------------------------------
// Undo last edit command
// ---------------------------------------------------------------------------

void CMainWindowDialog::pushbuttonundo_clicked() 
{ 
m_extcreator.m_headerfileset.UndoState();
ListBoxSetAll();
}

// ---------------------------------------------------------------------------
// Redo last edit command
// ---------------------------------------------------------------------------

void CMainWindowDialog::pushbuttonredo_clicked() 
{ 
m_extcreator.m_headerfileset.RedoState();

ListBoxSetAll();
}

// ---------------------------------------------------------------------------
// Check extensions available on system
//
// Inputs: None
//
// Outputs: None
//
// Results: Either UPDATE_OK or UPDATE_CANCEL
//
// Effects: 
// ---------------------------------------------------------------------------

int CMainWindowDialog::CheckNewExtensions( void )
{
CUpdateExtensionsDialog updatedialog;
int result, mode = 0;

#ifdef DEBUG
cout << "New extension count = " << m_extcreator.m_headerfileset.ListGetCount( LIST_NEW) << endl;
#endif
 
if ( m_extcreator.m_headerfileset.ListGetCount( LIST_NEW) > 0 )	
	{
	updatedialog.SetPointer( &m_extcreator );

	result = updatedialog.exec();

	if ( result == UPDATE_OK )
		{
		mode = m_extcreator.m_sitelist.GetUpdateMode();

#ifdef DEBUG
		cout << "Result: Update OK\n";
		cout << "Update must do:\n";

		if ( mode & MODE_UPDATEHEADERS )
			{
			cout << "Update headers\n";
			}

		if ( mode & MODE_READHEADERS )
			{
			cout << "Read headers\n";
			}

		if ( mode & MODE_UPDATEREGISTRY )
			{
			cout << "Update registry\n";
			}

		if ( mode & MODE_READREGISTRY )
			{
			cout << "Read the registry\n";		
			}

		if ( mode & MODE_IGNORETHESE )
			{
			cout << "Ignore these extensions\n";
			}
#endif

		// ----- Activate the processes automatically ---------------

		if ( mode & MODE_UPDATEHEADERS )
			{
			menubar_headerfilesdownloadfiles_activated();
			}

		if ( mode & MODE_READHEADERS )
			{
			menubar_headerfilesreadfiles_activated();
			}

		if ( mode & MODE_UPDATEREGISTRY )
			{
			menubar_registrydownloadall_activated();
			}

		if ( mode & MODE_READREGISTRY )
			{
			menubar_registryreadnew_activated();
			}

		if ( mode & MODE_IGNORETHESE )
			{
			m_extcreator.m_headerfileset.IgnoreNewExtensions();
			}
		}
	else
		{
		if ( result == UPDATE_CANCEL )
			{
#ifdef DEBUG
			cout << "Result: Update Cancelled" << endl;
#endif
			}

		mode = 0;
		}
	}

return( mode );
}

void CMainWindowDialog::pushbuttonchecksystem_clicked() 
{ 
menubar_editchecksystem_activated();
}

// ---------------------------------------------------------------------------
// Generate output files
// ---------------------------------------------------------------------------

void CMainWindowDialog::pushbuttongenerate_clicked() 
{ 
menubar_editgenerateoutputfiles_activated();
}

// ---------------------------------------------------------------------------
// Exit application
// ---------------------------------------------------------------------------

void CMainWindowDialog::pushbuttonexit_clicked() 
{ 
if ( m_extcreator.m_registrysettings.GetDownloadStatus() == DOWNLOAD_ACTIVE )
	{
	return;
	}

fileExit();
}
