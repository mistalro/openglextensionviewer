// ---------------------------------------------------------------------------
// Copyright: (C) VFX Research 2002 - 2014. All Rights Reserved.
// ---------------------------------------------------------------------------

#ifndef DERIVEDPIXELFORMATVIEW_H_
#define DERIVEDPIXELFORMATVIEW_H_

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

#ifdef PIXELFORMATVIEW_IS_WIDGET
#undef QT_WIDGET_PLUGIN_EXPORT
#define QT_WIDGET_WIDGET_PLUGIN_EXPORT
#endif

// --------------------------------------------------------------------------
// Definition of the custom list view as a Q-Object
// --------------------------------------------------------------------------

class CDerivedPixelFormatListView : public Q3ListView
{
	Q_OBJECT

CPixelFormatDescriptorList     *m_pfdlist;
vector <CDerivedListViewItem *> m_itemlist;
int 			        m_listempty;

// ----- Constructor and destructor -----------------------------------------

public:
CDerivedPixelFormatListView( QWidget *parent = 0, const char *name = 0 ) : Q3ListView( parent, name )
	{
	Init();
	}

CDerivedPixelFormatListView( void )
	{
	Deallocate();
	}

// ----- Functions and Procedures ------------------------------------------- 

void Init( void )
	{
	m_pfdlist = NULL;	
	m_listempty = 1;
	};

void Deallocate( void )
	{
	DeallocateList();
	};

void SetItem( CDerivedListViewItem *pitem, CPixelFormatDescriptor &pfdentry );

void SetAllItems( void );
void AllocateList( void );
void DeallocateList( void );
void SetList( void );
void SetAllLists( void );

int FindListIndex( CDerivedListViewItem *pitem );

void SetPointer( CPixelFormatDescriptorList *pfdlist )
	{
	m_pfdlist = pfdlist;
	};

Qt::SortOrder toggleSortOrder( void );

// ----- Events -------------------------------------------------------------

public slots:

void setSorting( int column, bool ascending ) 
	{
	Q3ListView::setSorting( column, ascending );
	emit sortingChanged( column, ascending );
	}

signals:
void sortingChanged( int column, bool ascending );
};

#endif // _DERIVEDPIXELFORMATVIEW_H_
