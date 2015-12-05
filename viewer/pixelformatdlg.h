// ---------------------------------------------------------------------------
// Copyright: (C) VFX Research 2002 - 2014. All Rights Reserved.
// ---------------------------------------------------------------------------
                                                                                
#ifndef PIXELFORMATSDIALOG_H
#define PIXELFORMATSDIALOG_H

#include <cstdio>
#include <cstdlib>
#include <iostream>

#include "extensionlib.h"
#include "pixelformatwidget.h"
#include ".ui/ui_pixelformatbasedlg.h"

// ----------------------------------------------------------------------------
// Definition of the CPFListView class
// ----------------------------------------------------------------------------

class CPixelFormatDialog : public QDialog,
				public Ui_CPixelFormatBaseDialog
{
	Q_OBJECT
	
CPixelFormatDescriptorList *m_pfdlist; // Pointer to system data
int 			    m_updateflag;	 // Update flag

// ----- Constructor and Destructor -------------------------------------------
public:

CPixelFormatDialog();
	 
~CPixelFormatDialog() 
	{ 
	};

// ----- Functions and Procedures ---------------------------------------------

void SetPointer( CPixelFormatDescriptorList *pfdlist )
	{
	m_listviewpixelformat->SetPointer( pfdlist );
	m_pfdlist = pfdlist;
	};

void ClearUpdateFlag( void ) { m_updateflag = 1; };
void SetUpdateFlag( void )   { m_updateflag = 1; };
int  CheckUpdateFlag( void ) { return m_updateflag; };

void SetAllItems( void );

// ----- User interface stuff -----------------------------------------------

protected slots:
void combopixelformat_activated( int value );
void combopixelformat_highlighted( int value );
                                                                           
void radiopixelformat_toggled( bool value );

void listviewpixelformat_mouseButtonClicked( 
		int, Q3ListViewItem *, const QPoint &, int );
void listviewpixelformat_mouseButtonPressed( 
		int, Q3ListViewItem *, const QPoint &, int );
void listviewpixelformat_rightButtonClicked( 
		Q3ListViewItem *, const QPoint &, int );
void listviewpixelformat_doubleClicked( 
		Q3ListViewItem *, const QPoint &, int );

void listviewpixelformat_setSorting( int, bool );

void pushbuttonprint_clicked();
void pushbuttonsave_clicked();
void pushbuttonok_clicked();
};

#endif // PIXELFORMATSDIALOG_H
