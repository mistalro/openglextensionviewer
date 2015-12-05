// ---------------------------------------------------------------------------
// Copyright: (C) VFX Research 2002 - 2014. All Rights Reserved.
// ---------------------------------------------------------------------------
                                                                                
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
#include "headerdownloadprogressdlg.h"
#include "headerfileprogressdlg.h"
#include "checksystemprogressdlg.h"
#include "outputfilesettingsdlg.h"
#include "registrysettingsdlg.h"
#include "updateextensionsdlg.h"
#include "exitapplicationdlg.h"
#include "aboutdlg.h"                                                                                
#undef DEBUG

// ---------------------------------------------------------------------------
// Set a single list box from an extension list
//
// Inputs: listbox - The custom derived Q3ListBox class
//         extlist - The extension list
//         selmode - Selection mode
//
// Outputs: None
//
// Results: None
//
// Effects: The custom Q3ListBox widget is updated
// ---------------------------------------------------------------------------
                                                                                
void CMainWindowDialog::ListBoxSet( CExtensionListBox &listbox,
                                CExtensionEntryList &extlist, int selmode )
{
int pn, count;
                                                                                
listbox.clear();
                                                                                
count = 0;

if ( selmode )
        {
        for ( pn = 0; pn < extlist.GetCount(); pn++ )
		{
                if ( extlist.at(pn).m_flags & FLAG_OUTPUT )
                        {
			listbox.insertItem(
				extlist.at(pn).m_name.data(), -1 );
                                                                                
			count++;
                        }
		}
        }
else
        {
#ifdef DEBUG
cout << "No selection mode" << endl;
#endif
        for ( pn = 0; pn < extlist.GetCount(); pn++ )
                {
#ifdef DEBUG
cout << "Inserting item " << pn << " | " << extlist.at(pn).m_name.data() << "|" << endl;
#endif
		listbox.insertItem(
			extlist.at(pn).m_name.data(), -1 );

                count++;
                }
        }                                                                 

if ( count == 0 )
	{
       	listbox.insertItem( "None", -1 );
	}
                                                                                
listbox.sort( TRUE );
}

// ---------------------------------------------------------------------------
// Set the selected list
//
// Inputs: listid - Which list to update
//
// Outputs: None
//
// Results: None
//
// Effects: The selected listbox is updated
// ---------------------------------------------------------------------------
                                                                                
void CMainWindowDialog::ListBoxSet( int listid )
{
switch ( listid )
        {
        case LISTBOX_GLX_AVAILABLE:
                ListBoxSet( *m_listglxavailable,
                        m_extcreator.m_headerfileset.m_glxlist.m_extlist, 0);
                break;
                                                                                
        case LISTBOX_GLX_SELECTED:
                ListBoxSet( *m_listglxselected,
                        m_extcreator.m_headerfileset.m_glxlist.m_extlist, 1);
                break;
                                                                                
        case LISTBOX_GL_AVAILABLE:
                ListBoxSet( *m_listglavailable,
                        m_extcreator.m_headerfileset.m_gllist.m_extlist,0 );
                break;
                                                                                
        case LISTBOX_GL_SELECTED:
                ListBoxSet( *m_listglselected,
                        m_extcreator.m_headerfileset.m_gllist.m_extlist, 1 );
                break;
                                                                                
        case LISTBOX_WGL_AVAILABLE:
                ListBoxSet( *m_listwglavailable,
                        m_extcreator.m_headerfileset.m_wgllist.m_extlist,0 );
                break;
                                                                                
        case LISTBOX_WGL_SELECTED:
                ListBoxSet( *m_listwglselected,
                        m_extcreator.m_headerfileset.m_wgllist.m_extlist, 1 );
                break;
                                                                                
        case LISTBOX_NEW:
                ListBoxSet( *m_listnew, 
			m_extcreator.m_headerfileset.m_newlist, 0 );
                break;
                                                                                
        case LISTBOX_IGNORE:
                ListBoxSet( *m_listignore, 
			m_extcreator.m_headerfileset.m_ignorelist, 0 );
                break;
                                                                                
        case LISTBOX_VENDOR_AVAILABLE:
                ListBoxSet( *m_listvendoravailable,
                        m_extcreator.m_headerfileset.m_vendorlist,0 );
                break;
                                                                                
        case LISTBOX_VENDOR_SELECTED:
                ListBoxSet( *m_listvendorselected,
                        m_extcreator.m_headerfileset.m_vendorlist,1 );
                break;
                                                                                
        case LISTBOX_SYSTEM:
                ListBoxSet( *m_listsystem, 
			m_extcreator.m_headerfileset.m_systemlist, 0 );
                break;
                                                                                
        default:
                break;
        }
}
 
// ---------------------------------------------------------------------------
// Set all lists
//
// Inputs: None
//
// Outputs: None
//
// Results: None
//
// Effects: All the list boxes are updated
// ---------------------------------------------------------------------------
                                                                                
void CMainWindowDialog::ListBoxSetAll( void )
{
ListBoxSet( LISTBOX_GL_AVAILABLE );
ListBoxSet( LISTBOX_GL_SELECTED );
ListBoxSet( LISTBOX_GLX_AVAILABLE );
ListBoxSet( LISTBOX_GLX_SELECTED );
ListBoxSet( LISTBOX_WGL_AVAILABLE );
ListBoxSet( LISTBOX_WGL_SELECTED );
ListBoxSet( LISTBOX_VENDOR_AVAILABLE );
ListBoxSet( LISTBOX_VENDOR_SELECTED  );
ListBoxSet( LISTBOX_NEW );
ListBoxSet( LISTBOX_IGNORE );
ListBoxSet( LISTBOX_SYSTEM );
}

// --------------------------------------------------------------------------
// For every item selected in the selected list, unselect that item
//
// Inputs: listbox - Which listbox to update
//         listid  - Which list to update
//
// Outputs: None
//
// Results: None
//
// Effects: The selected items in the list are unselected for output
// --------------------------------------------------------------------------
                                                                                
void CMainWindowDialog::ListBoxClearSelected(
                CExtensionListBox &listbox, int listid)
{
for (unsigned int pn = 0; pn < listbox.count(); pn++ )
	{
        if ( listbox.isSelected( pn ) )
                {
                char *pname = (char *) listbox.item(pn)->text().ascii();
                                                                                
                m_extcreator.m_headerfileset.ListClearNameFlag( listid, pname, FLAG_OUTPUT );
                }
	}
}

// --------------------------------------------------------------------------
// Remove the selected items to the selected list
//
// Inputs: listid - Which list
//
// Outputs: None
//
// Results: None
//
// Effects: The selectems items in the list are unselected
// --------------------------------------------------------------------------
                                                                                
void CMainWindowDialog::ListBoxClearSelected( int listid )
{
switch ( listid )
        {
        case LISTBOX_GL_SELECTED:
                ListBoxClearSelected( *m_listglselected, LIST_GL );
                break;
                                                                                
        case LISTBOX_GLX_SELECTED:
                ListBoxClearSelected( *m_listglxselected, LIST_GLX );
                break;
                                                                                
        case LISTBOX_WGL_SELECTED:
                ListBoxClearSelected( *m_listwglselected, LIST_WGL );
                break;
                                                                                
        case LISTBOX_VENDOR_SELECTED:
                ListBoxClearSelected( *m_listvendorselected, LIST_VENDOR );
                break;
                                                                                
        case LISTBOX_IGNORE:
        //      ListBoxClearSelected( *m_listignore, LIST_IGNORE );
                break;
                                                                                
        case LISTBOX_SYSTEM:
                ListBoxClearSelected( *m_listsystem, LIST_SYSTEM );
                break;
                                                                                
        default:
                break;
        }
}

// --------------------------------------------------------------------------
// For every item selected in the available list, select that item
//
// Inputs: listbox - The custom Q3ListBox widget
//         listid  - Which list
//         which   - Selection mode
//
// Outputs: None
//
// Results: None
//
// Effects: The selected items are selected for output
// --------------------------------------------------------------------------
                                                                                
void CMainWindowDialog::ListBoxAddSelected( CExtensionListBox &listbox,
                                                int listid, int which )
{
for (unsigned int pn = 0; pn < listbox.count(); pn++ )
        {
        if ( listbox.isSelected( pn ) )
                {
                m_extcreator.m_headerfileset.ListSetFullNameFlag(
                                listid, 
                		(char *) listbox.item(pn)->text().ascii(),
				FLAG_OUTPUT, which );
                }
        }
}

// --------------------------------------------------------------------------
// For every item selected in the custom Q3ListBox widget, copy it to the
// selected list
//
// Inputs:  listbox - The custom derived Q3ListBox widget
//          listid  - Which list
//
// Outputs: None
//
// Results: None
//
// Effects: The selected items in the list are copied to the selected list
// --------------------------------------------------------------------------
                                                                                
void CMainWindowDialog::ListBoxCopySelected( CExtensionListBox &listbox,
                                                int listid )
{
for (unsigned int pn = 0; pn < listbox.count(); pn++ )
        {
        if ( listbox.isSelected( pn ) )
                {
                char *pname = (char *) listbox.item(pn)->text().ascii();

                m_extcreator.m_headerfileset.ListAddName( listid, pname );
                }
        }
}
                                                                                
// --------------------------------------------------------------------------
// For every item selected in the custom Q3ListBox widget, remove it from
// the selected list
//
// Inputs: listbox - The custom derived Q3ListBox widget
//         listid  - Which list
//
// Outputs: None
//
// Results: None
//
// Effects: The selected items in the list are removed from the selected list
// --------------------------------------------------------------------------
                                                                                
void CMainWindowDialog::ListBoxRemoveSelected( CExtensionListBox &listbox,
                                                int listid )
{
for (unsigned int pn = 0; pn < listbox.count(); pn++ )
        {
        string str = string( (char *) listbox.item(pn)->text().ascii() );
                                                                                
        if ( listbox.isSelected( pn ) )
                m_extcreator.m_headerfileset.ListRemoveName( listid, str );
        }
}

void CMainWindowDialog::ListBoxDeleteSelected( CExtensionListBox &listbox,
                                                int listid )
{
for (unsigned int pn = 0; pn < listbox.count(); pn++ )
        {
	char *pname = (char *) listbox.item(pn)->text().ascii();
                                                                                
        if ( listbox.isSelected( pn ) )
                {
                m_extcreator.m_headerfileset.ListDeleteExtensionName( listid, pname );
                }
        }
}

// --------------------------------------------------------------------------
// Add the selected items to the selected list
// --------------------------------------------------------------------------
                                                                                
void CMainWindowDialog::ListBoxAddSelected( int listid )
{
switch ( listid )
        {
        case LISTBOX_GL_SELECTED:
                ListBoxAddSelected( *m_listglavailable,
                                        LIST_GL, MATCH_EXACTLY );
                break;
                                                                                
        case LISTBOX_GLX_SELECTED:
                ListBoxAddSelected( *m_listglxavailable,
                                        LIST_GLX, MATCH_EXACTLY  );
                break;
                                                                                
        case LISTBOX_WGL_SELECTED:
                ListBoxAddSelected( *m_listwglavailable,
                                        LIST_WGL, MATCH_EXACTLY );
                break;
                                                                                
        case LISTBOX_VENDOR_SELECTED:
                ListBoxAddSelected( *m_listvendoravailable,
                                        LIST_GL, MATCH_BEGINNING );
                                                                                
                ListBoxAddSelected( *m_listvendoravailable,
                                        LIST_GLX, MATCH_BEGINNING );
                                                                                
                ListBoxAddSelected( *m_listvendoravailable,
                                        LIST_WGL, MATCH_BEGINNING );
                                                                                
                ListBoxAddSelected( *m_listvendoravailable,
                                        LIST_VENDOR, MATCH_EXACTLY );
                break;
                                                                                
        case LISTBOX_NEW:
                ListBoxCopySelected( *m_listnew, LIST_IGNORE );
                break;
                                                                                
        default:
                break;
        }
}

void CMainWindowDialog::ListBoxDeleteSelected( int listid )
{
switch( listid )
        {
	case LISTBOX_GL_SELECTED:
		ListBoxDeleteSelected( *m_listglselected, LIST_GL );
		break;

	case LISTBOX_GLX_SELECTED:
		ListBoxDeleteSelected( *m_listglxselected, LIST_GLX );
		break;

	case LISTBOX_WGL_SELECTED:
		ListBoxDeleteSelected( *m_listwglselected, LIST_WGL );
		break;

	case LISTBOX_VENDOR_SELECTED:
		ListBoxDeleteSelected( *m_listvendorselected, LIST_VENDOR);
		break;

        case LISTBOX_IGNORE:
                ListBoxDeleteSelected( *m_listignore, LIST_IGNORE );
                break;
                                                                                
        default:
                break;
        }
}

// ---------------------------------------------------------------------------
// Unselect items from lists
// ---------------------------------------------------------------------------
                                                                                
void CMainWindowDialog::ListBoxClearSelected( void )
{
ListBoxClearSelected( LISTBOX_GL_SELECTED );
ListBoxClearSelected( LISTBOX_GLX_SELECTED );
ListBoxClearSelected( LISTBOX_WGL_SELECTED );
ListBoxClearSelected( LISTBOX_VENDOR_SELECTED );
                                                                                
ListBoxSetAll();
}
                                                                                
// ---------------------------------------------------------------------------
// Remove selected items from lists
// ---------------------------------------------------------------------------
                                                                                
void CMainWindowDialog::ListBoxDeleteSelected( void )
{
ListBoxClearSelected( LISTBOX_GL_SELECTED );
ListBoxClearSelected( LISTBOX_GLX_SELECTED );
ListBoxClearSelected( LISTBOX_WGL_SELECTED );
ListBoxDeleteSelected( LISTBOX_IGNORE );
}
                                                                                
// ---------------------------------------------------------------------------
// Add selected items to lists
// ---------------------------------------------------------------------------
                                                                                
void CMainWindowDialog::ListBoxAddSelected( void )
{
ListBoxAddSelected( LISTBOX_GL_SELECTED );
ListBoxAddSelected( LISTBOX_GLX_SELECTED );
ListBoxAddSelected( LISTBOX_WGL_SELECTED );
ListBoxAddSelected( LISTBOX_VENDOR_SELECTED );
ListBoxAddSelected( LISTBOX_NEW );
ListBoxSetAll();
}

// ---------------------------------------------------------------------------
// Examine selected extension
//
// Inputs: pitem - Pointer to the list box item - used to get extension name
//         listid - Index number of list
//
// Outputs: None
//
// Results: None
//
// Effects: A dialog window is opened, and set to the selected extension:
// ---------------------------------------------------------------------------
                                                                                
void CMainWindowDialog::ListBoxViewExtension( Q3ListBoxItem *pitem )
{
if (NULL == m_pextensiondialog)
	{
	m_pextensiondialog = new CExtensionDialog();

	m_pextensiondialog->SetPointer( &m_extcreator );
	}

m_pextensiondialog->raise();
m_pextensiondialog->show();
m_pextensiondialog->SetDialogData();
m_pextensiondialog->SetExtensionName( pitem->text().ascii() );
}
