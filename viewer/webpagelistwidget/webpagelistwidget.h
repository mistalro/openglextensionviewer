// ---------------------------------------------------------------------------
// Copyright: (C) VFX Research 2002 - 2014. All Rights Reserved.
// ---------------------------------------------------------------------------

#ifndef WEBPAGELISTWIDGET_H
#define WEBPAGELISTWIDGET_H

#include <qwidget.h>
#include <qlistview.h>

class QLineEdit;
class QPushButton;
class QListView;
class QListViewItem;

#ifdef WEBPAGELISTWIDGET_IS_WIDGET
#undef QT_WIDGET_PLUGIN_EXPORT
#define QT_WIDGET_WIDGET_PLUGIN_EXPORT
#endif

#include "../../libextviewer/extensionlib.h"
#include "webpagelistview.h"

// --------------------------------------------------------------------------
// Definition of the CWebPageListView class
// --------------------------------------------------------------------------

class CWebPageListView : public QWidget
{
	Q_OBJECT

// ----- Internal variables -------------------------------------------------

public:
CDerivedListViewWebPage		*m_plistview;   // Pointer to list view

// ----- Constructor and destructor -----------------------------------------

public:
CWebPageListView( QWidget *parent = 0, const char *name = 0 );

// ----- Functions and procedures -------------------------------------------

void SetList( void )
	{
	m_plistview->SetList();
	};

void SetPointer( CExtensionSiteInfoList *pptr )
	{
	m_plistview->SetPointer( pptr );
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

int sortColumn( int /* mode */ )
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

	void mouseDoubleClicked( int item );
	void mousePressed( int item );
	void mouseReleased( int item );
	void mouseMoved( int item );
};

#endif
