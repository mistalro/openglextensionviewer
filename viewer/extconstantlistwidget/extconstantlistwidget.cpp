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

#include "extconstantlistwidget.h"

// --------------------------------------------------------------------------
// Constructor
// --------------------------------------------------------------------------

CExtensionConstantListView::CExtensionConstantListView( QWidget *parent, 
				const char *name ) : QWidget( parent, name )
{
QVBoxLayout *layout = new QVBoxLayout( this );

m_plistview = new CDerivedListViewConstant( this, "m_plistview" );

layout->addWidget( m_plistview );

connect( m_plistview, SIGNAL( sortingChanged( int, bool ) ),
                      SIGNAL( sortingChanged( int, bool ) ) );

setFocusProxy( m_plistview );

m_plistview->addColumn( "Name" );
m_plistview->addColumn( "Value" );

m_plistview->setShowSortIndicator( TRUE );
}

// --------------------------------------------------------------------------
// Set a single row for constant entries
// --------------------------------------------------------------------------

void CExtensionConstantListView::setItem( CDerivedListViewItem *pitem, 
					CExtensionEntry &pextentry )
{
static char strnone[] = "None";

if ( 0 < m_listempty )
	{
	pitem->setText( 0, strnone );
	pitem->setText( 1, strnone );
	}
else
	{
	pitem->setText( 0, pextentry.m_name.data() );
	pitem->setText( 1, pextentry.m_value.data() );
	}
};

// --------------------------------------------------------------------------
// Deallocate list
// --------------------------------------------------------------------------

void CExtensionConstantListView::deallocateList( void )
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
m_plistview->erase();
};

// --------------------------------------------------------------------------
// Allocate list
// --------------------------------------------------------------------------

void CExtensionConstantListView::allocateList( int listid, int index )
{
CExtensionEntry *pextentry;
CDerivedListViewItem *pitem;

pextentry = m_pextcreator->GetExtensionEntry( listid, index );

m_listempty = ( pextentry->m_constnum == 0 );

for ( int pn = 0; pn < pextentry->m_constnum; pn++ )
	{
        pitem = new CDerivedListViewItem( m_plistview );

	m_itemlist.push_back(pitem);
	}
};

// --------------------------------------------------------------------------
// Set list
// --------------------------------------------------------------------------

void CExtensionConstantListView::setList( int listid, int index )
{
CExtensionEntry *pextentry = NULL;
CExtensionEntryList  *pconstlist = NULL;

// Get the global list of constants
pconstlist = m_pextcreator->m_headerfileset.GetConstantList(listid);

// Get the extension entry
pextentry = m_pextcreator->GetExtensionEntry(listid,index);

// Update the widget
m_plistview->setAllColumnsShowFocus( true );

for ( int pn = 0; pn < pextentry->m_constnum; pn++ )
	{ 
	setItem( m_itemlist[pn], *&pconstlist->at(pextentry->m_conststart+pn) );
	
	}
};

// --------------------------------------------------------------------------
// Update list
// --------------------------------------------------------------------------

void CExtensionConstantListView::setAllItems( int listid, int index )
{
deallocateList();
allocateList( listid, index );
setList( listid, index);
};
