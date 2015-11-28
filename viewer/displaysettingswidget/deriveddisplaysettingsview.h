// ---------------------------------------------------------------------------
// Copyright: (C) VFX Research 2002 - 2014. All Rights Reserved.
// ---------------------------------------------------------------------------

#ifndef _DERIVEDDISPLAYSETTINGSWIDGET_H_
#define _DERIVEDDISPLAYSETTINGSWIDGET_H_

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

#ifdef DISPLAYSETTINGSWIDGET_IS_WIDGET
#undef QT_WIDGET_PLUGIN_EXPORT
#define QT_WIDGET_WIDGET_PLUGIN_EXPORT
#endif

// --------------------------------------------------------------------------
// Definition of the custom list view as a Q-Object
// --------------------------------------------------------------------------

class CDerivedDisplaySettingsListView : public Q3ListView
{
	Q_OBJECT

CDisplaySettingsList 	       *m_pdslist;
vector <CDerivedListViewItem *> m_itemlist;
int				m_listempty;

public:
CDerivedDisplaySettingsListView( QWidget *parent = 0, const char *name = 0 ) : Q3ListView( parent, name )
	{
	Init();
	}

~CDerivedDisplaySettingsListView( void )
	{
	Deallocate();
	}

// ----- Functions and Procedures ------------------------------------------

void Init( void )
	{
	m_pdslist = NULL;
	m_listempty = 1;
	}

void Deallocate( void )
	{
	DeallocateList();
	}

void SetItem( CDerivedListViewItem *pitem, CDisplaySettings &dsentry);

void SetAllItems( void );
void AllocateList( void );
void DeallocateList( void );
void SetList( void );
void SetAllLists( void );

int FindListIndex( CDerivedListViewItem *pitem );

void SetPointer( CDisplaySettingsList *pdslist )
	{
	m_pdslist = pdslist;
	}

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

#endif	// _DERIVEDDISPLAYSETTINGSVIEW_H_

