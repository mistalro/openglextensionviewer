// ---------------------------------------------------------------------------
// Copyright: (C) VFX Research 2002 - 2014. All Rights Reserved.
// ---------------------------------------------------------------------------

#ifndef CONSTANTLISTWIDGET_H
#define CONSTANTLISTWIDGET_H

#include <Qt3Support>
#include <qnamespace.h>
#include <QWidget>
#include <QListView>
#include <QLineEdit>
#include <QPushButton>

#include "../../libextviewer/extensionlib.h"
#include "../derivedlistviewitem.h"

#ifdef CONSTANTLISTWIDGET_IS_WIDGET
#undef QT_WIDGET_PLUGIN_EXPORT
#define QT_WIDGET_WIDGET_PLUGIN_EXPORT
#endif

// --------------------------------------------------------------------------
// Definition of the custom list view as a Q-Object
// --------------------------------------------------------------------------

class CDerivedListViewConstant : public Q3ListView
{
	Q_OBJECT

public:
CDerivedListViewConstant( QWidget *parent = 0, const char *name = 0 ) : Q3ListView( parent, name )
	{

	}

public slots:

void setSorting( int column, bool ascending ) 
	{
	Q3ListView::setSorting( column, ascending );
	emit sortingChanged( column, ascending );
	}

signals:
void sortingChanged( int column, bool ascending );

private: 
};

// --------------------------------------------------------------------------
// Definition of the CExtensionConstantListView class
// --------------------------------------------------------------------------

class CExtensionConstantListView : public QWidget
{
	Q_OBJECT

public:
CDerivedListViewConstant	*m_plistview;   // Pointer to list view
CExtensionViewer   		*m_pextcreator;
CExtensionEntry			*m_pextentry;
vector <CDerivedListViewItem *> m_itemlist;
int 				 m_listempty;	// List is empty

// ----- Constructor and destructor -----------------------------------------

public:
CExtensionConstantListView( QWidget *parent = 0, const char *name = 0 );

// ----- Constants and procedures -------------------------------------------

void setItem( CDerivedListViewItem *pitem,
             CExtensionEntry &pextentry );

void deallocateList( void );
void allocateList( int listid, int index );
void setList(      int listid, int index );
void setAllItems(  int listid, int index );

void setPointer( CExtensionViewer *pextcreator )
	{
	m_pextcreator = pextcreator;
	};

Qt::SortOrder toggleSortOrder( void )
	{
	Qt::SortOrder mode;

	mode = m_plistview->sortOrder();

	if ( mode == Qt::AscendingOrder )
		mode = Qt::DescendingOrder;
	else
		mode = Qt::AscendingOrder;

	m_plistview->setSortOrder( mode );

	return( mode );	
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
};

#endif
