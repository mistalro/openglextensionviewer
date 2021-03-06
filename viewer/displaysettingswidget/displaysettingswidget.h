// ---------------------------------------------------------------------------
// Copyright: (C) VFX Research 2002 - 2014. All Rights Reserved.
// ---------------------------------------------------------------------------

#ifndef DISPLAYSETTINGSWIDGET_H
#define DISPLAYSETTINGSWIDGET_H

#include <Qt3Support>
#include <qnamespace.h>
#include <qwidget.h>
#include <qlistview.h>
#include <qlineedit.h>
#include <qpushbutton.h>
#include <qplugin.h>

#include <ios>
#include <iostream>
#include <string>

using namespace std;

#include "../../libextviewer/extensionlib.h"
#include "../derivedlistviewitem.h"
#include "deriveddisplaysettingsview.h"

#ifdef DISPLAYSETTINGSWIDGET_IS_WIDGET
#undef QT_WIDGET_PLUGIN_EXPORT
#define QT_WIDGET_WIDGET_PLUGIN_EXPORT
#endif

// --------------------------------------------------------------------------
// Definition of the CDisplaySettingsListView class
// --------------------------------------------------------------------------

class CDisplaySettingsListView : public Q3ListView
{
	Q_OBJECT

public:
CDerivedDisplaySettingsListView *m_plistview; // Display settings

// ----- Constructor and destructor -----------------------------------------

CDisplaySettingsListView( QWidget *parent = 0, const char *name = 0 );

// ----- Functions and procedures -------------------------------------------

void SetList( void )
        {
        m_plistview->SetList();
        };

void SetPointer( CDisplaySettingsList *pflist )
        {
        m_plistview->SetPointer( pflist );
        };

void SetAllItems( void )
        {
        m_plistview->SetAllItems();
        };

Qt::SortOrder toggleSortOrder( void )
        {
        return( m_plistview->toggleSortOrder() );
        };

int sortOrder( void )
        {
        return( m_plistview->sortOrder() );
        };

void setSortOrder( int value )
        {
        m_plistview->setSortOrder( (Qt::SortOrder) value );
        };

void setSortColumn( int mode )
        {
        m_plistview->setSortColumn( mode );
        };

int sortColumn( int /* mode */)
        {
        return( m_plistview->sortColumn() );
        }
        
virtual void setSorting( int column, bool ascending )
        {
        emit sortingChanged( column, ascending );
        }

public slots:

signals: 
	void sortingChanged( int column, bool ascending );
};

#endif
