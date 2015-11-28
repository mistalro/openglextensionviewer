// ---------------------------------------------------------------------------
// Copyright: (C) VFX Research 2002 - 2014. All Rights Reserved.
// ---------------------------------------------------------------------------

#ifndef DISPLAYSETTINGSDIALOG_H
#define DISPLAYSETTINGSDIALOG_H

using namespace std;

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include "extensionlib.h"
#include "displaysettingswidget/displaysettingswidget.h"
#include ".ui/ui_displaysettingsbasedlg.h"

class CDisplaySettingsDialog : public QDialog,
				public Ui_CDisplaySettingsBaseDialog
		
{
	Q_OBJECT

	CDisplaySettingsList *m_pdslist;	// Pointer to system data	
	int			m_updateflag;  // Update flag	

public:

// ----- Constructor and Destructor -------------------------------------------

CDisplaySettingsDialog( QWidget* parent = 0, const char* name = 0, 
			bool modal = FALSE, Qt::WFlags fl = 0 );
	 
~CDisplaySettingsDialog() { };

// ----- Functions and Procedures ---------------------------------------------

void SetPointer( CDisplaySettingsList *pdslist )
	{
	m_displaysettingslist->SetPointer( pdslist );
	m_pdslist = pdslist;
	};

void SetAllItems( void );
                                                                                
void ClearUpdateFlag( void ) { m_updateflag = 1; };
void SetUpdateFlag( void )   { m_updateflag = 1; };
int  CheckUpdateFlag( void ) { return m_updateflag; };
                                                                                
protected slots:

void combodisplaysettings_highlighted( int value );
void combodisplaysettings_activated( int value );

void radioreversed_toggled( bool value );

void listviewdisplaysettings_mouseButtonClicked(
                int, Q3ListViewItem *, const QPoint &, int );
void listviewdisplaysettings_mouseButtonPressed(
                int, Q3ListViewItem *, const QPoint &, int );
void listviewdisplaysettings_rightButtonClicked(
                Q3ListViewItem *, const QPoint &, int );
void listviewdisplaysettings_doubleClicked(
                Q3ListViewItem *, const QPoint &, int );

void listviewdisplaysettings_setSorting(int, bool);

void pushbuttonprint_clicked();
void pushbuttonsave_clicked();
void pushbuttonok_clicked();

void listviewdisplaysettings_sortingChanged( int, bool );
};

#endif // DISPLAYSETTINGSDIALOG_H
