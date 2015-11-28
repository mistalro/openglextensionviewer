// ---------------------------------------------------------------------------
// Copyright: (C) VFX Research 2002 - 2014. All Rights Reserved.
// ---------------------------------------------------------------------------

#include <Qt3Support>
#include <qnamespace.h>

#include <qlineedit.h>
#include <qpushbutton.h>
#include <qfiledialog.h>
#include <qlistview.h>
#include <qlineedit.h>

#include <qlayout.h>
#include <qboxlayout.h>
#include "extfunctionlistwidget.h"

// --------------------------------------------------------------------------
// Constructor
// --------------------------------------------------------------------------

CExtensionFunctionListView::CExtensionFunctionListView( QWidget *parent, 
				const char *name ) : QWidget( parent, name )
{
QVBoxLayout *layout = new QVBoxLayout( this );
                                                                                
m_plistview = new CDerivedListViewFunction( this, "m_plistview" );
                                                                                
layout->addWidget( m_plistview );

connect( m_plistview, SIGNAL( sortingChanged( int, bool ) ),
                      SIGNAL( sortingChanged( int, bool ) ) );

setFocusProxy( m_plistview );

m_plistview->addColumn( "Return" );
m_plistview->addColumn( "Name" );
m_plistview->addColumn( "Parameters" );
m_plistview->addColumn( "Short Parameter List" );
m_plistview->addColumn( "Prototype" );

m_plistview->setShowSortIndicator( TRUE );
}

static char strnone[] = "None";

// --------------------------------------------------------------------------
// Set a single row
// --------------------------------------------------------------------------

void CExtensionFunctionListView::setItem( CDerivedListViewItem *pitem, 
					  CExtensionEntry &extentry )
{
int  colpos;

// ----- Function entries ---------------------------------------------------

colpos = 0;

if ( m_listempty)
	{
	pitem->setText( colpos++, strnone);
	pitem->setText( colpos++, strnone);
	pitem->setText( colpos++, strnone);
	pitem->setText( colpos++, strnone);
	pitem->setText( colpos++, strnone);
	}
else
	{	
	pitem->setText( colpos++, extentry.m_prefix.data() );
	pitem->setText( colpos++, extentry.m_name.data() );
	pitem->setText( colpos++, extentry.m_value.data() );

	pitem->setText( colpos++, extentry.m_header.data() );
	pitem->setText( colpos++, extentry.m_pfnproc.data() );
	}

};

// --------------------------------------------------------------------------
// Deallocate list
// --------------------------------------------------------------------------

void CExtensionFunctionListView::deallocateList( void )
{
for ( unsigned int pn = 0; pn < m_itemlist.size(); pn++ )
	{
	if ( m_itemlist[pn] != NULL )
        	{
		m_plistview->takeItem( m_itemlist[pn] );
		delete m_itemlist[pn];
		m_itemlist[pn] = NULL;
		}
	}

m_itemlist.clear();
};

// --------------------------------------------------------------------------
// Allocate list
// --------------------------------------------------------------------------

void CExtensionFunctionListView::allocateList( int listid, int index )
{
CExtensionEntry *pextentry;
CDerivedListViewItem *pitem;

pextentry = m_pextcreator->GetExtensionEntry( listid, index );

m_listempty = (pextentry->m_funcnum == 0 );

for ( int pn = 0; pn < pextentry->m_funcnum; pn++)
	{
	// Pointer to list items
	pitem = new CDerivedListViewItem( m_plistview); 

	m_itemlist.push_back(pitem );
	}
};

// --------------------------------------------------------------------------
// Set list
//
// CExtensionEntry defines an extension in terms of indices into global
// list of functions and constants
//
//	funcstart
//	funcnum
//	conststart
//	constnum
//
// CExtensionEntrylist defines a list of extensions (CExtensionEntry)
//
// CExtensionHeaderFileData defines a complete set of data for a header file
//
//	m_version         - version
//	m_selectednum     - number of selected extensions
//	m_selectedfuncnum - number of selected extension functions
//	m_extpos          - position in list
//
//	m_extlist	- List of extensions
//	m_constlist	- List of constants
//	m_funclist	- List of functions
//
//	m_prefix	- extension prefix
//	m_funcprefix	- function prefix
//	m_prototype	- prototypes

// --------------------------------------------------------------------------

void CExtensionFunctionListView::setList( int listid, int index )
{
CExtensionEntry *pextentry = NULL; 
CExtensionEntryList  *pfunclist = NULL;

// Get the global list of functions from the selected list
pfunclist = m_pextcreator->GetFunctionList(listid);

// Get the extension entry from the list
pextentry = m_pextcreator->GetExtensionEntry(listid, index);

// Update the widget
m_plistview->setAllColumnsShowFocus( true );

// For each function
for ( int pn = 0; pn < pextentry->EntryGetFuncCount(); pn++ )
	{
        setItem( m_itemlist[pn], pfunclist->at(pextentry->m_funcstart+pn) );
	}
};

// --------------------------------------------------------------------------
// Update list
// --------------------------------------------------------------------------

void CExtensionFunctionListView::setAllItems( int listid, int index )
{
deallocateList();
allocateList( listid, index);
setList( listid, index);
};
