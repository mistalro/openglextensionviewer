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

#include "deriveddisplaysettingsview.h"
#include "displaysettingswidget.h"

// --------------------------------------------------------------------------
// Set single row
// --------------------------------------------------------------------------

void CDerivedDisplaySettingsListView::SetItem( CDerivedListViewItem *pitem, 
		CDisplaySettings &displaysettings)
{
int  colpos = 0;
char buffer[1024];

// ----- Index ----------------------------------------------------------

sprintf( buffer, "%03d", displaysettings.m_index);
pitem->setText( colpos++, buffer );

// ----- Depth -----------------------------------------------------

if ( displaysettings.m_bitsperpel > 0 )
	{
	sprintf( buffer, "%d", displaysettings.m_bitsperpel);
	pitem->setText( colpos++, buffer );
	}
else
	{
	pitem->setText( colpos++, "Any" );
	}

// ----- Width -----------------------------------------------------

sprintf( buffer, "%d", displaysettings.m_pelswidth );
pitem->setText( colpos++, buffer );

// ----- Height -------------------------------------------------

sprintf( buffer, "%d", displaysettings.m_pelsheight );
pitem->setText( colpos++, buffer );

// ----- Vertical Refresh -----------------------------------------------

if ( displaysettings.m_displayvertfreq > 0)
	{
	sprintf( buffer, "%d", displaysettings.m_displayvertfreq );
	pitem->setText( colpos++, buffer );
	}
else
	{
	pitem->setText( colpos++, "Unknown" );
	}

// ----- Horizontal Refresh ------------------------------------------------

if ( displaysettings.m_displayhorizfreq > 0 )
	{
	sprintf( buffer, "%d", displaysettings.m_displayhorizfreq );
	pitem->setText( colpos++, buffer );
	}
else	
	{
	pitem->setText( colpos++, "Unknown" );
	}

// ----- Bandwidth -----------------------------------------------

if ( displaysettings.m_displaybandwidth > 0 )
	{
	sprintf( buffer, "%d", displaysettings.m_displaybandwidth );
	pitem->setText( colpos++, buffer );
	}
else
	{
	pitem->setText( colpos++, "Unknown" );
	}
};

// --------------------------------------------------------------------------
// Deallocate list
// --------------------------------------------------------------------------

void CDerivedDisplaySettingsListView::DeallocateList( void )
{
for ( unsigned int pn = 0; pn < m_itemlist.size(); pn++ )
	{
	if ( m_itemlist[pn] != NULL )
		{
		takeItem( m_itemlist[pn] );

		delete m_itemlist[pn];
		m_itemlist[pn] = NULL;
		}
	}

	m_itemlist.clear();
};

// --------------------------------------------------------------------------
// Allocate list
// --------------------------------------------------------------------------

void CDerivedDisplaySettingsListView::AllocateList( void )
{
CDerivedListViewItem *pitem;

int num = m_pdslist->GetCount();

m_listempty = (num == 0 );

for ( int pn = 0; pn < num; pn++ )
	{
        pitem = new CDerivedListViewItem( this );
	
	m_itemlist.push_back(pitem);
	}
};

// --------------------------------------------------------------------------
// Set list
// --------------------------------------------------------------------------

void CDerivedDisplaySettingsListView::SetList( void )
{
setAllColumnsShowFocus( true );

for ( unsigned int pn = 0; pn < m_itemlist.size(); pn++ )
	{
        SetItem( m_itemlist[pn], m_pdslist->GetListItem( pn ) );
	}
};

// --------------------------------------------------------------------------
// Update list
// --------------------------------------------------------------------------

void CDerivedDisplaySettingsListView::SetAllItems( void )
{
DeallocateList();
AllocateList();
SetList();
};

// --------------------------------------------------------------------------
// Find List Index
// --------------------------------------------------------------------------

int CDerivedDisplaySettingsListView::FindListIndex( CDerivedListViewItem *pitem )
{
for ( int pn = 0; pn < m_pdslist->GetCount(); pn++ )
        {
        if ( m_itemlist[pn] == pitem )
                {
                return( pn );
                }
        }

return( -1 );
}

// --------------------------------------------------------------------------
// Toggle sorting
// --------------------------------------------------------------------------

Qt::SortOrder CDerivedDisplaySettingsListView::toggleSortOrder( void )
{
Qt::SortOrder mode = sortOrder();

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
};

