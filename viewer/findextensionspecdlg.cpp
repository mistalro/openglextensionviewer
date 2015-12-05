// ---------------------------------------------------------------------------
// Copyright: (C) VFX Research 2002 - 2014. All Rights Reserved.
// ---------------------------------------------------------------------------

#include "config.h"

#include <q3listview.h>
#include <qcheckbox.h>
#include <qlineedit.h>
#include <qprogressbar.h>
#include "findextensionspecdlg.h"

#define BITMASK_STATE( MODE, FLAG, STATE ) \
	(STATE) ? (MODE) |= (FLAG) : (MODE) &= ~(FLAG)

// ---------------------------------------------------------------------------
// Constructor
// ---------------------------------------------------------------------------

CFindExtensionSpecDialog::CFindExtensionSpecDialog( QWidget*, const char* , bool, Qt::WFlags )
		: Ui_CFindExtensionSpecBaseDialog() 
{
setupUi( this );
SetUpdateFlag();

m_searchmode = 0;
}

// ---------------------------------------------------------------------------
// Update the GUI
// ---------------------------------------------------------------------------

void CFindExtensionSpecDialog::SetAllItems( void )
{
if ( CheckUpdateFlag() )
	{
	}
}

// ---------------------------------------------------------------------------
// Callback for searching for strings
// ---------------------------------------------------------------------------

int CFindExtensionSpecDialog::RegistryStringSearchCallback( int site, 
					int lineno, const std::string &file,
					const std::string &line, int mode ) 
{
std::string strbuf;
QString str;

CExtensionSiteInfo *psiteinfo;

stl_itoa( strbuf, lineno );

if ( mode & MODE_DISPLAYFULLPATHS)
	{
	str = QString( file.data() );
	}
else
	{
	str = QString( strrchr( file.data(), '/' ) );
	}

// No need to save result here
new Q3ListViewItem( m_listviewresults, 
			m_listviewresults->lastItem(),
			str, 
			QString(strbuf.data() ), 
			QString(line.data()) );

qApp->processEvents();
psiteinfo = m_pcreator->GetSiteInfo( site );

m_lineeditsite->setText( QString(psiteinfo->GetDescription().data() ));

m_lineeditsearchstatus->setText( QString("Ready #1") );

return m_cancelsearch;
}

// ---------------------------------------------------------------------------
// Callback for search progress
// ---------------------------------------------------------------------------

int CFindExtensionSpecDialog::RegistryStringSearchProgressCallback( int pos, int max )
{
m_progressbarsearch->setValue( pos );
m_progressbarsearch->setMaximum( max );

return m_cancelsearch;
}

// ---------------------------------------------------------------------------
// The line edit text changed
// ---------------------------------------------------------------------------

void CFindExtensionSpecDialog::lineeditsearchstring_textChanged( const QString &/* strdata */ )
{
#ifdef DEBUG
cout << "String changed |" << strdata.data() << "|\n";
#endif
}

// ---------------------------------------------------------------------------
// User pressed a column in the listview
// ---------------------------------------------------------------------------

void CFindExtensionSpecDialog::listview_setSorting( int /* column */, bool /* ascending */)
{
if ( CheckUpdateFlag() )
	{
	ClearUpdateFlag();
	SetUpdateFlag();
	}
}

// ---------------------------------------------------------------------------
// User clicked an item in the list view
// ---------------------------------------------------------------------------

void CFindExtensionSpecDialog::listview_clicked(Q3ListViewItem * /*pitem*/)
{
#ifdef DEBUG
cout << "List view clicked\n";
#endif
}

// ---------------------------------------------------------------------------
// Find string button was clicked
// ---------------------------------------------------------------------------

void CFindExtensionSpecDialog::pushbuttonfind_clicked()
{
std::string strdata;

// Clear list
m_listviewresults->clear(); 

// Get the search string
strdata =(char *)  m_lineeditstring->text().ascii(); // Get Function string

#ifdef DEBUG
cout << "Searching for |" << strdata.data() << "|\n";
#endif

// Sanity check on length
if ( strdata.size() == 0 )
	{
	return;
	}

// Ensure search is not going to be cancelled
m_cancelsearch = false;

// Perform the search 
#ifdef DEBUG
cout << "Doing search\n";
#endif

m_lineeditsearchstatus->setEchoMode( QLineEdit::Normal );
m_lineeditsearchstatus->setText( QString("Searching") );
m_pcreator->SearchExtensionSpecs( m_searchmode, strdata, *this );
m_lineeditsearchstatus->setText( QString("Ready #2") );

// Reset the progress bar
// Note: Maximum = Minimum = 0 and Value = -1 goes into Knight-Rider mode
m_progressbarsearch->setValue( 0 );
m_progressbarsearch->setMaximum(100 );

// Display something even if nothing was found
if ( m_listviewresults->childCount()  == 0 )
	{
	Q3ListViewItem( m_listviewresults, "No match found" );
	}

// Clear the site flag
m_lineeditsite->clear();
}

// ---------------------------------------------------------------------------
// The Cancel search button was pressed
// ---------------------------------------------------------------------------

void CFindExtensionSpecDialog::pushbuttoncancelsearch_clicked()
{
m_cancelsearch = true;

#ifdef DEBUG
cout << "Cancel clicked\n";
#endif

Q3ListViewItem( m_listviewresults, 
			m_listviewresults->lastItem(),
			QString( "Cancelled by user") );
m_lineeditsearchstatus->setText( QString("Cancelled") );

// Reset the progress bar
m_progressbarsearch->setValue(  0 );
m_progressbarsearch->setMaximum(100 );
}

// ---------------------------------------------------------------------------
// The Clear button was pressed
// ---------------------------------------------------------------------------

void CFindExtensionSpecDialog::pushbuttonclear_clicked()
{
#ifdef DEBUG
cout << "Clear clicked\n";
#endif

m_listviewresults->clear();
}

// ---------------------------------------------------------------------------
// The OK button was pressed
// ---------------------------------------------------------------------------

void CFindExtensionSpecDialog::pushbuttonok_clicked()
{
#ifdef DEBUG
cout << "OK clicked\n";
#endif

hide();
}

// --------------------------------------------------------------------------
// Radio button match case toggled
// --------------------------------------------------------------------------

void CFindExtensionSpecDialog::radiobuttonmatchcase_toggled( bool state )
{
#ifdef DEBUG
cout << "Radio button match case toggled: " << state << "\n";
#endif

BITMASK_STATE( m_searchmode, MODE_MATCHCASE, state );
}

// --------------------------------------------------------------------------
// Radio button find first toggled
// --------------------------------------------------------------------------

void CFindExtensionSpecDialog::radiobuttonfindfirst_toggled( bool state )
{
#ifdef DEBUG
cout << "Radio button find first toggled: " << state << "\n";
#endif

BITMASK_STATE( m_searchmode, MODE_FIRSTMATCH, state );
}

// --------------------------------------------------------------------------
// Radio button display full paths toggled
// --------------------------------------------------------------------------

void CFindExtensionSpecDialog::radiobuttononematchperfile_toggled( bool state )
{
#ifdef DEBUG
cout << "Radio button one match per file toggled: " << state << "\n";
#endif

BITMASK_STATE( m_searchmode, MODE_ONEMATCHPERFILE, state );
}

// --------------------------------------------------------------------------
// Radio button display full paths toggled
// --------------------------------------------------------------------------

void CFindExtensionSpecDialog::radiobuttondisplayfullpaths_toggled( bool state )
{
#ifdef DEBUG
cout << "Radio button display full paths: " << state << "\n";
#endif

BITMASK_STATE( m_searchmode, MODE_DISPLAYFULLPATHS, state );
}
