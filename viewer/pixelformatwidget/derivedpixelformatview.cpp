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
#include "derivedpixelformatview.h"
#include "pixelformatwidget.h" 

// --------------------------------------------------------------------------
// Set a single row
// --------------------------------------------------------------------------

void CDerivedPixelFormatListView::SetItem( CDerivedListViewItem *pitem,
				CPixelFormatDescriptor &pixelformat )
{
int  colpos = 0;
char buffer[1024];

// ----- Index ----------------------------------------------------------

sprintf( buffer, "%03d", pixelformat.m_index);
pitem->setText( colpos++, buffer );

// ----- Pixel type -----------------------------------------------------

if ( pixelformat.m_iPixelType == FLAG_RGBA )
	{
    	pitem->setText( colpos++, "RGBA" );
	}
else
	if ( pixelformat.m_iPixelType == FLAG_INDEX )
		{
    		pitem->setText( colpos++, "INDEX" );
		}
else
	{
    	pitem->setText( colpos++, "Unknown" );
	}

// ----- Color bits -----------------------------------------------------

sprintf( buffer, "%d", pixelformat.m_cColorBits );
pitem->setText( colpos++, buffer );

// ----- Red bits/shift -------------------------------------------------

sprintf( buffer, "%d/%d", pixelformat.m_cRedBits, pixelformat.m_cRedShift );
pitem->setText( colpos++, buffer );

// ----- Green bits/shift -----------------------------------------------

sprintf( buffer, "%d/%d", pixelformat.m_cGreenBits, pixelformat.m_cGreenShift );pitem->setText( colpos++, buffer );

// ----- Blue bits/shift ------------------------------------------------

sprintf( buffer, "%d/%d", pixelformat.m_cBlueBits, pixelformat.m_cBlueShift );
pitem->setText( colpos++, buffer );

// ----- Alpha bits/shift -----------------------------------------------

sprintf( buffer, "%d/%d", pixelformat.m_cAlphaBits, pixelformat.m_cAlphaShift);
pitem->setText( colpos++, buffer );

// ----- Accumulation bits ----------------------------------------------

sprintf( buffer, "%d, (%d,%d,%d,%d )", pixelformat.m_cAccumBits,
    pixelformat.m_cAccumRedBits,
    pixelformat.m_cAccumGreenBits,
    pixelformat.m_cAccumBlueBits, pixelformat.m_cAccumAlphaBits );

pitem->setText( colpos++, buffer );

// ----- Depth bits -----------------------------------------------------

sprintf( buffer, "%d", pixelformat.m_cDepthBits );
pitem->setText( colpos++, buffer );

// ----- Stencil bits ---------------------------------------------------

sprintf( buffer, "%d", pixelformat.m_cStencilBits );
pitem->setText( colpos++, buffer );

// ----- Flags ----------------------------------------------------------

sprintf( buffer, "%08X", pixelformat.m_dwFlags );

buffer[0] = 0;

#ifdef _WIN32
if ( pixelformat.m_dwFlags & PFD_DRAW_TO_WINDOW )
    strcat(buffer, " PFD_DRAW_TO_WINDOW" );

if ( pixelformat.m_dwFlags & PFD_DRAW_TO_BITMAP )
    strcat(buffer, " PFD_DRAW_TO_BITMAP" );

if ( pixelformat.m_dwFlags & PFD_SUPPORT_GDI )
    strcat(buffer, " PFD_SUPPORT_GDI" );

if ( pixelformat.m_dwFlags & PFD_SUPPORT_OPENGL )
    strcat(buffer, " PFD_SUPPORT_OPENGL" );

if ( pixelformat.m_dwFlags & PFD_GENERIC_ACCELERATED )
    strcat(buffer, " PFD_GENERIC_ACCELERATED" );

if ( pixelformat.m_dwFlags & PFD_NEED_PALETTE )
    strcat(buffer, " PFD_NEED_PALETTE" );

if ( pixelformat.m_dwFlags & PFD_NEED_SYSTEM_PALETTE )
    strcat(buffer, " PFD_NEED_SYSTEM_PALETTE" );

if ( pixelformat.m_dwFlags & PFD_DOUBLEBUFFER )
    strcat(buffer, " PFD_DOUBLEBUFFER" );

if ( pixelformat.m_dwFlags & PFD_STEREO )
    strcat(buffer, " PFD_STEREO" );

if ( pixelformat.m_dwFlags & PFD_SWAP_LAYER_BUFFERS )
    strcat(buffer, " PFD_SWAP_LAYER_BUFFERS" );
#endif

if ( pixelformat.m_dwFlags & FLAG_DIRECT )
    strcat( buffer, " Direct" );

if ( pixelformat.m_dwFlags & FLAG_DOUBLEBUFFER )
    strcat( buffer, " Doublebuffer" );

if ( pixelformat.m_dwFlags & FLAG_STEREO )
    strcat( buffer, " Stereo" );

pitem->setText( colpos++, buffer );

// ----- Image plane ----------------------------------------------------

#ifdef _WIN32
if ( pixelformat.m_iLayerType == FLAG_MAINPLANE )
	{
        pitem->setText( colpos++, "PFD_MAIN_PLANE" );
	{
else
        if ( pixelformat.m_iLayerType == FLAG_OVERLAYPLANE )
		{
                pitem->setText( colpos++, "PFD_OVERLAY_PLANE" );
		}
else
        if ( pixelformat.m_iLayerType == FLAG_UNDERLAYPLANE )
		{
                pitem->setText( colpos++, "PFD_UNDERLAY_PLANE" );
		}
#endif

pitem->setText( colpos++, "Main Plane" );
}

// --------------------------------------------------------------------------
// Deallocate list
// --------------------------------------------------------------------------

void CDerivedPixelFormatListView::DeallocateList( void )
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

erase();
};

// --------------------------------------------------------------------------
// Allocate list
// --------------------------------------------------------------------------

void CDerivedPixelFormatListView::AllocateList( void )
{
CDerivedListViewItem *item;

int num = m_pfdlist->GetCount2();

m_listempty = (num == 0 );

for ( int pn = 0; pn < num; pn++ )
	{
	item = new CDerivedListViewItem( this );

	m_itemlist.push_back( item);
	}
};

// --------------------------------------------------------------------------
// Set list
// --------------------------------------------------------------------------

void CDerivedPixelFormatListView::SetList( void )
{
setAllColumnsShowFocus( true );

for ( int pn = 0; pn < m_pfdlist->GetCount2(); pn++ )
	{
        SetItem( m_itemlist[pn], m_pfdlist->m_pixelformatlist[pn] );
	}
};

// --------------------------------------------------------------------------
// Set All Items
// --------------------------------------------------------------------------

void CDerivedPixelFormatListView::SetAllItems( void )
{
DeallocateList();
AllocateList();
SetList();
};

// --------------------------------------------------------------------------
// Find List Index
// --------------------------------------------------------------------------

int CDerivedPixelFormatListView::FindListIndex( CDerivedListViewItem *pitem )
{
for ( int pn = 0; pn < m_pfdlist->GetCount2(); pn++ )
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

Qt::SortOrder CDerivedPixelFormatListView::toggleSortOrder( void )
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
