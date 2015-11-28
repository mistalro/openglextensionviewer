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

// --------------------------------------------------------------------------
// Constructor
// --------------------------------------------------------------------------

#define CONNECTOR( X ) \
	connect( m_plistview, SIGNAL( X ), SIGNAL( X ) )

CWebPageListView::CWebPageListView( QWidget *parent, 
				const char *name ) : QWidget( parent, name )
{
QVBoxLayout *layout = new QVBoxLayout( this );
                                                                                
m_plistview = new CDerivedListViewWebPage( this, "m_plistview" );
                                                                                
layout->addWidget( m_plistview );

CONNECTOR( sortingChanged( int, bool ) );

CONNECTOR( mouseDoubleClicked( int ) );
CONNECTOR( mousePressed( int ) );
CONNECTOR( mouseReleased( int ) );
CONNECTOR( mouseMoved( int ) );

setFocusProxy( m_plistview );

m_plistview->addColumn( "Description" );
m_plistview->addColumn( "Web Page" );
m_plistview->addColumn( "Local Directory" );

m_plistview->setShowSortIndicator( TRUE );
m_plistview->setAllColumnsShowFocus( TRUE );
m_plistview->setSelectionMode( Q3ListView::Single );
}
