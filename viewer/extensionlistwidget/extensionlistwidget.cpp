// ---------------------------------------------------------------------------
// Copyright: (C) VFX Research 2002 - 2014. All Rights Reserved.
// ---------------------------------------------------------------------------

#include <qpushbutton.h>
#include <qfiledialog.h>

#include "extensionlistwidget.h"

// --------------------------------------------------------------------------
// Constructor
// --------------------------------------------------------------------------

CExtensionListBox::CExtensionListBox( QWidget *parent, const char *name )
    : Q3ListBox( parent, name )
{
m_dragging = FALSE;

setAcceptDrops( TRUE );
}

// --------------------------------------------------------------------------
// Destructor
// --------------------------------------------------------------------------
/*
CExtensionListBox::~CExtensionListBox( void )
{

};
*/

// --------------------------------------------------------------------------
// Entered widget
// --------------------------------------------------------------------------

void CExtensionListBox::dragEnterEvent( QDragEnterEvent *event )
{
event->accept( Q3TextDrag::canDecode(event) );
//      printf( "Drag Enter Event\n" );
}

// --------------------------------------------------------------------------
// Moved inside widget
// --------------------------------------------------------------------------
                                                                                
void CExtensionListBox::dragMoveEvent( QDragMoveEvent * /* event */ )
{
//      printf( "Drag Move Event\n" );
}

// --------------------------------------------------------------------------
// Departed widget
// --------------------------------------------------------------------------
                                                                              
void CExtensionListBox::dragLeaveEvent( QDragLeaveEvent * /* event */ )
{
//      printf( "Drag Leave Event\n" );
}

// --------------------------------------------------------------------------
// Drop event
// --------------------------------------------------------------------------

void CExtensionListBox::dropEvent( QDropEvent *event )
{
QString text;
                                                                                
if ( (event->source() != this ) && Q3TextDrag::decode( event, text ) )
	{
        emit itemsDropped( text );
        }
}
                                                                                
// --------------------------------------------------------------------------
// Mouse press event
// --------------------------------------------------------------------------

void CExtensionListBox::mousePressEvent( QMouseEvent *event )
{
Q3ListBox::mousePressEvent( event );

m_dragging = TRUE;
}

// --------------------------------------------------------------------------
// Mouse release event
// --------------------------------------------------------------------------
                                                                                
void CExtensionListBox::mouseReleaseEvent( QMouseEvent *event )
{
Q3ListBox::mouseReleaseEvent( event );

m_dragging = FALSE;
}
                                                                                
// --------------------------------------------------------------------------
// Mouse move event
// --------------------------------------------------------------------------

void CExtensionListBox::mouseMoveEvent( QMouseEvent * )
{
QString string;
int pmax, first;
                  
first = 1;
                                                             
if ( m_dragging )
	{
        pmax = count();
                                                                                
        for ( int pn = 0; pn < pmax; pn++ )
		{
		if ( isSelected(pn) )
                	{
			if ( first )
				{
				first = 0;
				}
			else
				{
				string += " ";
				}

                        string += text(pn);
                        }
		}
                                                                                
        Q3DragObject *d = new Q3TextDrag( string, this );
        d->dragCopy(); // do NOT delete d.
        m_dragging = FALSE;
        }
}
