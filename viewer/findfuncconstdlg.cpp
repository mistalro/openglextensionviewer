// ---------------------------------------------------------------------------
// Copyright: (C) VFX Research 2002 - 2014. All Rights Reserved.
// ---------------------------------------------------------------------------

#include "config.h"

#include "qlineedit.h"
#include "q3listview.h"
#include "findfuncconstdlg.h"

// ---------------------------------------------------------------------------
// Constructor
// ---------------------------------------------------------------------------

CFindFuncConstDialog::CFindFuncConstDialog(void)
		: Ui_CFindFuncConstBaseDialog()
{
setupUi( this );
SetUpdateFlag();
}

// ---------------------------------------------------------------------------
// Update the GUI
// ---------------------------------------------------------------------------

void CFindFuncConstDialog::SetAllItems( void )
{
if ( CheckUpdateFlag() )
	{
	}
}

// ---------------------------------------------------------------------------
// Callback for searching for strings
// ---------------------------------------------------------------------------

int CFindFuncConstDialog::HeaderFileDataSearchCallback( int list, 
				const string &name, const string &value )
{
Q3ListViewItem *pitem;

Q_UNUSED(list);

pitem = new Q3ListViewItem( m_listviewresults, name.data(), value.data() );

Q_UNUSED(pitem);

return(1);
}

// ---------------------------------------------------------------------------
// User pressed a column in the listview
// ---------------------------------------------------------------------------

void CFindFuncConstDialog::listview_setSorting( int column, bool ascending )
{
Q_UNUSED(column);
Q_UNUSED(ascending);

if ( CheckUpdateFlag() )
	{
	ClearUpdateFlag();
	SetUpdateFlag();
	}
}

// ---------------------------------------------------------------------------
// Line edit constant was changed
// ---------------------------------------------------------------------------

void CFindFuncConstDialog::lineeditconstant_textChanged( const QString &string )
{
Q_UNUSED(string);
}

// ---------------------------------------------------------------------------
// Line edit function was changed
// ---------------------------------------------------------------------------

void CFindFuncConstDialog::lineeditfunction_textChanged( const QString &string )
{
Q_UNUSED(string);
}

// ---------------------------------------------------------------------------
// Find constant button was clicked
// ---------------------------------------------------------------------------

void CFindFuncConstDialog::pushbuttonfindconstant_clicked()
{
string strdata;

m_listviewresults->clear(); // Clear list
strdata = m_lineeditconstant->text().ascii(); // Get Constant string

m_pcreator->SearchString( SEARCH_CONSTANTS, strdata, *this );
}

// ---------------------------------------------------------------------------
// Find function button was clicked
// ---------------------------------------------------------------------------

void CFindFuncConstDialog::pushbuttonfindfunction_clicked()
{
string strdata;

m_listviewresults->clear(); // Clear list
strdata = m_lineeditfunction->text().ascii(); // Get Function string

m_pcreator->SearchString( SEARCH_FUNCTIONS, strdata, *this );
}

// ---------------------------------------------------------------------------
// Clear button was clicked
// ---------------------------------------------------------------------------

void CFindFuncConstDialog::pushbuttonclear_clicked()
{
m_listviewresults->clear(); // Clear list
}

// ---------------------------------------------------------------------------
// The OK button was pressed
// ---------------------------------------------------------------------------

void CFindFuncConstDialog::pushbuttonok_clicked()
{
hide();
}
