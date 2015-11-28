// ---------------------------------------------------------------------------
// Copyright: (C) VFX Research 2002 - 2014. All Rights Reserved.
// ---------------------------------------------------------------------------

#ifndef EXTENSIONLISTWIDGET_H
#define EXTENSIONLISTWIDGET_H

#include <Qt3Support>
#include <Q3DragObject>
#include <qnamespace.h>
#include <qwidget.h>
#include <qlistview.h>
#include <qpushbutton.h>
#include <qlineedit.h>

#include "../../libextviewer/extensionlib.h"
#include "../derivedlistviewitem.h"

#ifdef EXTENSIONLISTWIDGET_IS_WIDGET
#undef QT_WIDGET_PLUGIN_EXPORT
#define QT_WIDGET_WIDGET_PLUGIN_EXPORT
#endif

class CExtensionListBoxItem : public Q3ListBoxItem
{
public:
};

// --------------------------------------------------------------------------
// Definition of the CPixelFormatListBox class
// --------------------------------------------------------------------------

class CExtensionListBox : public Q3ListBox
{
	Q_OBJECT

public:
int m_dragging;
	
// ----- Constructor and destructor -----------------------------------------

public:
CExtensionListBox( QWidget *parent = 0, const char *name = 0 );

// ----- Functions and procedures -------------------------------------------

void dragEnterEvent( QDragEnterEvent *event );
void dragMoveEvent( QDragMoveEvent *event );
void dragLeaveEvent( QDragLeaveEvent *event );
void dropEvent( QDropEvent *event );

void mousePressEvent( QMouseEvent *event );
void mouseReleaseEvent( QMouseEvent *event );
void mouseMoveEvent( QMouseEvent * );

public slots:

signals: 

void itemsDropped( QString &string );
//private slots:

public:
};

#endif
