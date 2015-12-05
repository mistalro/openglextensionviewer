// ---------------------------------------------------------------------------
// Copyright: (C) VFX Research 2002 - 2014. All Rights Reserved.
// ---------------------------------------------------------------------------

#ifndef WEBPAGELISTVIEW_H
#define WEBPAGELISTVIEW_H
                                                                                
#include <Qt3Support>
#include <qnamespace.h>
#include <qwidget.h>
#include <qlistview.h>
#include <qpushbutton.h>
#include "../../libextviewer/extensionlib.h"
#include "../derivedlistviewitem.h"                                                                                
#include "webpagelistview.h"

// --------------------------------------------------------------------------
// Definition of the custom list view as a Q-Object
// --------------------------------------------------------------------------
                                                                                
class CDerivedListViewWebPage : public Q3ListView
{
        Q_OBJECT
public:
                                                                                
CExtensionSiteInfoList *m_psiteinfolist;
int 		  	 m_listempty;
std::vector <CDerivedListViewItem *> m_itemlist;
                                                                                
// ----- Constructor and destructor -----------------------------------------
                                                                                
CDerivedListViewWebPage( QWidget *parent = 0, const char *name = 0 ) : Q3ListView( parent, name )
        {
        Init();
        }
                                                                                
CDerivedListViewWebPage( void )
        {
        Deallocate();
        }
                                                                                
// ----- Functions and Procedures -------------------------------------------
                                                                                
void Init( void )
        {
        m_psiteinfolist = NULL;
        m_listempty   = 1;
        };
                                                                                
void Deallocate( void )
	{
	}

void SetItem( CDerivedListViewItem *pitem,
             CExtensionSiteInfo &pextsiteinfo );
                                                                                
void SetList(      void );
void SetAllItems( void );
                                                                                
int  FindListIndex( CDerivedListViewItem *pitem );
                                                                                
void SetPointer( CExtensionSiteInfoList *psiteinfolist )
        {
        m_psiteinfolist = psiteinfolist;
        };

Qt::SortOrder toggleSortOrder( void );                                                                                
// ----- Events -------------------------------------------------------------
                                                                                
void contentsMouseDoubleClickEvent( QMouseEvent *event );
void contentsMouseMoveEvent( QMouseEvent *event );
void contentsMousePressEvent( QMouseEvent *event );
void contentsMouseReleaseEvent( QMouseEvent *event );
                                                                                
public slots:
                                                                                
void setSorting( int column, bool ascending )
        {
        Q3ListView::setSorting( column, ascending );
        emit sortingChanged( column, ascending );
        }

signals:
void sortingChanged( int column, bool ascending );
                                                                                
void mouseDoubleClicked( int item );
void mousePressed( int item );
void mouseReleased( int item );
void mouseMoved( int item );
};

#endif
