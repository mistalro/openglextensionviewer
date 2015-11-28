// ---------------------------------------------------------------------------
// Copyright: (C) VFX Research 2002 - 2014. All Rights Reserved.
// ---------------------------------------------------------------------------

#include <qlineedit.h>
#include <qpushbutton.h>
#include <qfiledialog.h>
#include <qlistview.h>
#include <qlineedit.h>
#include <qpushbutton.h>
#include <qlayout.h>
#include "webpagelistwidget.h"
#include "webpagelistview.h"                                                                                
// --------------------------------------------------------------------------
// Constructor
// --------------------------------------------------------------------------
                                                                                
#define CONNECTOR( X ) \
        connect( m_plistview, SIGNAL( X ), SIGNAL( X ) )

// --------------------------------------------------------------------------
// Utility string
// --------------------------------------------------------------------------

static char strnone[] = "None";
                                                                                
// --------------------------------------------------------------------------
// Set a single row
// --------------------------------------------------------------------------
                                                                                
void CDerivedListViewWebPage::SetItem( CDerivedListViewItem *pitem,
                                  CExtensionSiteInfo &pextsiteinfo )
{
int  colpos;
                                                                                
// ----- Function entries ---------------------------------------------------
        
colpos = 0;
                                                                                
if ( m_listempty)
        {
        pitem->setText( colpos++, strnone);
        pitem->setText( colpos++, strnone);
        pitem->setText( colpos++, strnone);
        }
else
        {
        pitem->setText( colpos++, pextsiteinfo.m_description.data() );
        pitem->setText( colpos++, pextsiteinfo.m_indexpagenet.data() );
        pitem->setText( colpos++, pextsiteinfo.m_indexdirlocal.data() );
        }
};

// --------------------------------------------------------------------------
// Set list
// --------------------------------------------------------------------------
                                                                                
void CDerivedListViewWebPage::SetList( void )
{
CDerivedListViewItem *pitem;
int num;

setAllColumnsShowFocus( true );
                                                                                
// ----- Remove old items -----

for ( int pn = m_itemlist.size()-1; pn >= 0; pn-- )
	{
	pitem = m_itemlist[pn];

	delete pitem;
	}

m_itemlist.clear();
clear();

// ----- Add new items ------

num = m_psiteinfolist->GetCount(); // Assign list size here
                                                                                
m_listempty = (num == 0);

for ( int pn = 0; pn < num; pn++ )
	{
	pitem = new CDerivedListViewItem(this);

        SetItem( pitem, m_psiteinfolist->at(pn) );

	insertItem( pitem );

	m_itemlist.push_back(pitem);
	}
};
                                                                                
// --------------------------------------------------------------------------
// Set All Items
// --------------------------------------------------------------------------
                                                                                
void CDerivedListViewWebPage::SetAllItems( void )
{
SetList();
};

// --------------------------------------------------------------------------
// Find List Index
// --------------------------------------------------------------------------

int CDerivedListViewWebPage::FindListIndex( CDerivedListViewItem *pitem )
{
for ( int pn = 0; pn < m_psiteinfolist->GetCount(); pn++ )
	{
	if ( m_itemlist[pn] == pitem )
		{
		return( pn );
		}
	}
                                                                                
return( -1 );
}

// --------------------------------------------------------------------------
// Mouse events
// --------------------------------------------------------------------------

void CDerivedListViewWebPage::contentsMouseDoubleClickEvent( QMouseEvent *event )
{
Q3ListViewItem *pitem = itemAt( event->pos() );
CDerivedListViewItem *pderived = (CDerivedListViewItem *) ((void *) pitem );

if (NULL == pderived)
	{
	return;
	}

int index = FindListIndex( pderived );
                                                                               
if ( index > -1 )
	{
        emit mouseDoubleClicked( index );
	setSelected(pitem,TRUE);
        }
}
                                                                                
void CDerivedListViewWebPage::contentsMouseMoveEvent( QMouseEvent *event )
{
Q3ListViewItem *pitem = itemAt( event->pos() );
CDerivedListViewItem *pderived = (CDerivedListViewItem *) ((void *) pitem );

if (NULL == pderived)
	{
	return;
	}

int index = FindListIndex( pderived );
                                                                                
if ( index > -1 )
	{
        emit mouseMoved( index );
	setSelected(pitem,TRUE);
	}
}
                                                                                
void CDerivedListViewWebPage::contentsMousePressEvent( QMouseEvent *event )
{
Q3ListViewItem *pitem = itemAt( event->pos() );
CDerivedListViewItem *pderived = (CDerivedListViewItem *) ((void *) pitem );
                                                                                
if (NULL == pderived)
	{
	return;
	}

int index = FindListIndex( pderived );
                                                                              
if ( index > -1 )
	{
	emit mousePressed( index );
	setSelected(pitem,TRUE);
	}
}
                                                                                
void CDerivedListViewWebPage::contentsMouseReleaseEvent( QMouseEvent *event )
{
Q3ListViewItem *pitem = itemAt( event->pos() );
CDerivedListViewItem *pderived = (CDerivedListViewItem *) ((void *) pitem );

int index = FindListIndex( pderived );
                                                                                
if ( index > -1 )
	{
	emit mouseReleased( index );
	setSelected(pitem,TRUE);
	}
}

Qt::SortOrder CDerivedListViewWebPage::toggleSortOrder( void )	
{
Qt::SortOrder mode;

mode = sortOrder();

if ( mode == Qt::AscendingOrder )
	{
	mode = Qt::DescendingOrder;
	}
else
	{
	mode = Qt::AscendingOrder;
	}

setSortOrder( mode );

return( mode );
}

