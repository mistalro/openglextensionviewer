// ---------------------------------------------------------------------------
// Copyright: (C) VFX Research 2002 - 2014. All Rights Reserved.
// ---------------------------------------------------------------------------

#include <qlineedit.h>
#include <qpushbutton.h>
#include <qfiledialog.h>
#include <qlistview.h>
#include <qlineedit.h>
#include <qlayout.h>

#include "derivedpixelformatview.h"
#include "pixelformatwidget.h" 

// --------------------------------------------------------------------------
// Constructor
// --------------------------------------------------------------------------

CPixelFormatListView::CPixelFormatListView( QWidget *parent, const char *name )
    
{
QVBoxLayout *layout = new QVBoxLayout( this );
//layout->setMargin(0);

m_plistview = new CDerivedPixelFormatListView( this, "m_plistview" );

layout->addWidget( m_plistview );

connect( m_plistview, SIGNAL( sortingChanged( int, bool ) ),
                      SIGNAL( sortingChanged( int, bool ) ) );

setFocusProxy( m_plistview );

m_plistview->addColumn( "Index" );
m_plistview->addColumn( "Pixel type" );
m_plistview->addColumn( "Color bits" );
m_plistview->addColumn( "Red bits/shift" );
m_plistview->addColumn( "Green bits/shift" );
m_plistview->addColumn( "Blue bits/shift" );
m_plistview->addColumn( "Alpha bits/shift" );
m_plistview->addColumn( "Accumulation bits" );
m_plistview->addColumn( "Depth bits" );
m_plistview->addColumn( "Stencil bits" );
m_plistview->addColumn( "Flags" );
m_plistview->addColumn( "Plane level" );

//setGeometry( QRect( 10, 60, 580, 400 ) );
m_plistview->setShowSortIndicator( TRUE );
m_plistview->setAllColumnsShowFocus( TRUE );
m_plistview->setSelectionMode( Q3ListView::Single );
}
