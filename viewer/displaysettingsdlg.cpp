// ---------------------------------------------------------------------------
// Copyright: (C) VFX Research 2002 - 2014. All Rights Reserved.
// ---------------------------------------------------------------------------

#include "config.h"

#include <QListView>
#include <QFileDialog>
#include <QPrintDialog>
#include <QPrinter>
#include "displaysettingsdlg.h"
#include "displaysettingswidget/displaysettingswidget.h"
#include "extensionlib.h"                                                                                
// ---------------------------------------------------------------------------
// Constructor
// ---------------------------------------------------------------------------
                                                                                
CDisplaySettingsDialog::CDisplaySettingsDialog( 
			QWidget * /* parent */, const char* /* name */,
                        bool /* modal */, Qt::WFlags /* fl */ )
                : Ui_CDisplaySettingsBaseDialog()
{
setupUi( this );

//m_listviewdisplaysettings->setFullWidth( FALSE );

connect( m_displaysettingslist,
	SIGNAL( sortingChanged( int, bool) ),
	this,
	SLOT( listviewdisplaysettings_sortingChanged( int,bool) ) );
                                                                               
SetUpdateFlag();
}

// ---------------------------------------------------------------------------
// Update the GUI
// ---------------------------------------------------------------------------
                                                                                
void CDisplaySettingsDialog::SetAllItems( void )
{
string strbuf;

if ( CheckUpdateFlag() )
        {
	stl_itoa( strbuf, m_pdslist->GetCount() );

        m_editdisplaymodecount->setText( strbuf.data() );
        m_radioreversed->setChecked( m_pdslist->GetReverseMode() );

	//m_displaysettings->setSorting( -1, TRUE );
                                                                                
        m_displaysettingslist->SetAllItems();
        }
}
                                                                                
// ---------------------------------------------------------------------------
// User pressed a column in the listview
// ---------------------------------------------------------------------------
                                                                                
void CDisplaySettingsDialog::listviewdisplaysettings_sortingChanged( 	
						int column, bool ascending )
{
if ( CheckUpdateFlag() )
        {
        ClearUpdateFlag();
        m_radioreversed->setChecked( !ascending );
        m_combodisplaysettings->setCurrentItem( column );
        SetUpdateFlag();
        }
}
                                                                                
// ---------------------------------------------------------------------------
// User pressed a column in the listview
// ---------------------------------------------------------------------------

void CDisplaySettingsDialog::listviewdisplaysettings_setSorting( int column, bool ascending )
{
if ( CheckUpdateFlag() )
        {
        ClearUpdateFlag();
        m_radioreversed->setChecked( !ascending );
        m_combodisplaysettings->setCurrentItem( column );
        SetUpdateFlag();
        }
}

// ---------------------------------------------------------------------------
// User made a definite selection
// ---------------------------------------------------------------------------
                                                                                
void CDisplaySettingsDialog::combodisplaysettings_activated( int value )
{
if  ( CheckUpdateFlag() )
        {
        m_displaysettingslist->setSortColumn( value );
        }
}

void CDisplaySettingsDialog::combodisplaysettings_highlighted( int /* value */ )
{
//LEGACY
}

// ---------------------------------------------------------------------------
// User toggled the radio button
// ---------------------------------------------------------------------------
                                                                                
void CDisplaySettingsDialog::radioreversed_toggled( bool value )
{
if ( CheckUpdateFlag() )
        {
        m_displaysettingslist->setSortOrder( (Qt::SortOrder) value );
        }
}
                                                                                
// ---------------------------------------------------------------------------
// The Print button was pressed
// ---------------------------------------------------------------------------
                                                                                
void CDisplaySettingsDialog::pushbuttonprint_clicked()
{
QPrinter printer;
                                                                                
QPrintDialog printdlg( &printer, this /*, "Print Dialog" */ );
                                                                                
printdlg.exec();
}

// ---------------------------------------------------------------------------
// The list was mouse button clicked
// ---------------------------------------------------------------------------

void CDisplaySettingsDialog::listviewdisplaysettings_mouseButtonClicked(
                        int, Q3ListViewItem *, const QPoint &, int )
{
cout << "ListView - Mouse button clicked" << endl;
}

// ---------------------------------------------------------------------------
// The list was mouse button pressed
// ---------------------------------------------------------------------------

void CDisplaySettingsDialog::listviewdisplaysettings_mouseButtonPressed( int,
                        Q3ListViewItem *, const QPoint &pos, int item )
{
cout << "ListView - Button pressed ("
        << pos.x() << ", "<< pos.y() << " = " <<item << "\n" << endl;
}

// ---------------------------------------------------------------------------
// The list was right button clicked
// ---------------------------------------------------------------------------

void CDisplaySettingsDialog::listviewdisplaysettings_rightButtonClicked(
                        Q3ListViewItem *, const QPoint &pos, int item)
{
cout << "ListView: Right Button clicked ("
        << pos.x() << ", " << pos.y() << " = " << item << endl;
}

// ---------------------------------------------------------------------------
// The list was doubleclicked
// ---------------------------------------------------------------------------


void CDisplaySettingsDialog::listviewdisplaysettings_doubleClicked(
                                Q3ListViewItem *, const QPoint &pos, int item )
{
cout << "ListView: Double Clicked (" << pos.x() << ", " << pos.y() <<
        " = " << item << endl;
}

// ---------------------------------------------------------------------------
// The Save button was pressed
// ---------------------------------------------------------------------------
                                                                                
void CDisplaySettingsDialog::pushbuttonsave_clicked()
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
        m_pdslist->SaveDisplaySettingsList( (char *) filepath.ascii() );
        }
}
                                                                                
// ---------------------------------------------------------------------------
// The OK button was pressed
// ---------------------------------------------------------------------------
                                                                                
void CDisplaySettingsDialog::pushbuttonok_clicked()
{
hide();
}
