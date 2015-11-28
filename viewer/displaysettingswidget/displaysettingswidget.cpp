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
// Constructor
// --------------------------------------------------------------------------

CDisplaySettingsListView::CDisplaySettingsListView( QWidget *parent, const char *name )
{
QVBoxLayout *layout = new QVBoxLayout( this );
//layout->setMargin(0);
                                                                                
m_plistview = new CDerivedDisplaySettingsListView( this, "m_plistview" );
                                                                                
layout->addWidget( m_plistview );

connect( m_plistview, 
	SIGNAL( sortingChanged( int, bool ) ),
	SIGNAL( sortingChanged( int, bool ) ) );

setFocusProxy( m_plistview );

m_plistview->addColumn( "Index" );
m_plistview->addColumn( "Depth" );
m_plistview->addColumn( "Width" );
m_plistview->addColumn( "Height" );
m_plistview->addColumn( "Vertical Refresh" );
m_plistview->addColumn( "Horizontal Refresh" );
m_plistview->addColumn( "Bandwidth" );

//setGeometry( QRect( 10, 60, 580, 400 ) );
m_plistview->setShowSortIndicator( TRUE );
}
