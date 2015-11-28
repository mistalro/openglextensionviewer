// ---------------------------------------------------------------------------
// Copyright: (C) VFX Research 2002 - 2014. All Rights Reserved.
// ---------------------------------------------------------------------------

#include "config.h"
#include "q3listview.h"
#include "pixelformatdlg.h"
#include "pixelformatwidget/pixelformatwidget.h"

// ---------------------------------------------------------------------------
// Constructor
// ---------------------------------------------------------------------------

CPixelFormatDialog::CPixelFormatDialog() : Ui_CPixelFormatBaseDialog() 
{
setupUi( this );

//m_listviewpixelformat->setFullWidth( FALSE );

connect( m_listviewpixelformat, 
	SIGNAL( sortingChanged( int, bool) ), 
	this, 
	SLOT( listviewpixelformat_setSorting( int,bool) ) );

SetUpdateFlag();
}

// ---------------------------------------------------------------------------
// Update the GUI
// ---------------------------------------------------------------------------

void CPixelFormatDialog::SetAllItems( void )
{
string strbuf;

if ( CheckUpdateFlag() )
	{
	stl_itoa( strbuf, m_pfdlist->GetCount2() );

	m_pixelformatcount->setText( strbuf.data() );
	m_radiopixelformat->setChecked( m_pfdlist->GetReverseMode() );

	//m_pixelformat->setSorting( -1, TRUE );

	m_listviewpixelformat->SetAllItems();
	}
}

// ---------------------------------------------------------------------------
// User pressed a column in the listview
// ---------------------------------------------------------------------------

void CPixelFormatDialog::listviewpixelformat_setSorting( int column, bool ascending )
{
if ( CheckUpdateFlag() )
	{
	ClearUpdateFlag();
	m_radiopixelformat->setChecked( !ascending );
	m_combopixelformat->setCurrentItem( column );
	SetUpdateFlag();
	}
}

// ---------------------------------------------------------------------------
// User made a definite selection in the combo box
// ---------------------------------------------------------------------------

void CPixelFormatDialog::combopixelformat_activated( int value )
{
if  ( CheckUpdateFlag() )
	{
	m_listviewpixelformat->setSortColumn( value );
	}	
}

// ---------------------------------------------------------------------------
// User is going through the choices
// ---------------------------------------------------------------------------
         
void CPixelFormatDialog::combopixelformat_highlighted( int /* value */ )
{
//LEGACY
}
  
// ---------------------------------------------------------------------------
// User toggled the radio button
// ---------------------------------------------------------------------------

void CPixelFormatDialog::radiopixelformat_toggled( bool value )
{
if ( CheckUpdateFlag() )
	{
	m_listviewpixelformat->setSortOrder( (Qt::SortOrder) value );
	}
}

// ---------------------------------------------------------------------------
// The Print button was pressed
// ---------------------------------------------------------------------------

void CPixelFormatDialog::pushbuttonprint_clicked()
{
QPrinter printer;

QPrintDialog printdlg( &printer, this /*, "Print Dialog" */ );

printdlg.exec();
}

// ---------------------------------------------------------------------------
// The list was mouse button clicked
// ---------------------------------------------------------------------------

void CPixelFormatDialog::listviewpixelformat_mouseButtonClicked( 
			int, Q3ListViewItem *, const QPoint &, int )
{
cout << "ListView - Mouse button clicked" << endl;
}

// ---------------------------------------------------------------------------
// The list was mouse button pressed
// ---------------------------------------------------------------------------

void CPixelFormatDialog::listviewpixelformat_mouseButtonPressed( int, 
			Q3ListViewItem *, const QPoint &pos, int item )
{
cout << "ListView - Button pressed ("
	<< pos.x() << ", "<< pos.y() << " = " <<item << "\n" << endl;
}

// ---------------------------------------------------------------------------
// The list was right button clicked
// ---------------------------------------------------------------------------

void CPixelFormatDialog::listviewpixelformat_rightButtonClicked( 
			Q3ListViewItem *, const QPoint &pos, int item)
{
cout << "ListView: Right Button clicked ("
	<< pos.x() << ", " << pos.y() << " = " << item << endl;
}

// ---------------------------------------------------------------------------
// The list was doubleclicked
// ---------------------------------------------------------------------------


void CPixelFormatDialog::listviewpixelformat_doubleClicked( 
				Q3ListViewItem *, const QPoint &pos, int item )
{
cout << "ListView: Double Clicked (" << pos.x() << ", " << pos.y() << 
	" = " << item << endl;
}

// ---------------------------------------------------------------------------
// The Save button was pressed
// ---------------------------------------------------------------------------

void CPixelFormatDialog::pushbuttonsave_clicked()
{
QFileDialog filedlg;
QString     filepath;

filepath = filedlg.getSaveFileName(
                           ".",
                           "Text files (*.txt)",
                           this,
                           "Save File Dialog",
                           "Choose destination file" );

if ( filepath.ascii() != NULL )
	{
	m_pfdlist->SavePixelFormatList( string( filepath.ascii() ) );
	}
}

// ---------------------------------------------------------------------------
// The OK button was pressed
// ---------------------------------------------------------------------------

void CPixelFormatDialog::pushbuttonok_clicked()
{
hide();
}
