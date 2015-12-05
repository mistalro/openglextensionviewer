// ---------------------------------------------------------------------------
// Copyright: (C) VFX Research 2002 - 2014. All Rights Reserved.
// ---------------------------------------------------------------------------

#include <QtCore>

#include "extensiondlg.h"
#include "extensionviewdlg.h"
#include "qfile.h"
#include "qdialog.h"
#include "qcombobox.h"
#include "qradiobutton.h"
#include "extensionlib.h"
#include "extfunctionlistwidget/extfunctionlistwidget.h"
#include "extconstantlistwidget/extconstantlistwidget.h"

// --------------------------------------------------------------------------
// Set the pointer to the global data
//
// Inputs: pcreator - Pointer to global data structure
//
// Outputs: None
//
// Results: None
//
// Effects: The pointer is set
// --------------------------------------------------------------------------

void CExtensionDialog::SetPointer( CExtensionViewer *pcreator )
{
m_pextcreator = pcreator;
}

// --------------------------------------------------------------------------
// Set the current extension name
// 
// Inputs: pstr - Pointer to the extension name
//
// Outputs: None
//
// Results: None
//
// Effects: The pointer is set
// --------------------------------------------------------------------------

void CExtensionDialog::SetExtensionName( const char *pstr )
{
int newindex = 0, newlistid = 0;

// The two index values are set accordingly
m_pextcreator->m_headerfileset.FindExtensionListIndex( 
	pstr, newindex, newlistid );

if ( (newindex != -1) && (newlistid != -1) )
	{
	SetIndex( newindex, newlistid );
	}
}

// --------------------------------------------------------------------------
// Set the index of the first extension list displayed
//
// Inputs: index - The index into the selected list
//         listid - The index of the selected list
//
// Outputs: None
//
// Results: None
//
// Effects: The index and listid's are set
// --------------------------------------------------------------------------

void CExtensionDialog::SetIndex( int index, int listid )
{
m_index  = index;
m_listid = listid;

#ifdef DEBUG
cout << "Setting index << " << index << "|" << listid << endl;
#endif

if ( m_pextcreator != NULL )
	{
	m_noupdateflag = 1;
	SetDialogData();
	m_noupdateflag = 0;
	}
}

// --------------------------------------------------------------------------
// Configure the dialog data as required
//
// Inputs: None
//
// Outputs: None
//
// Results: None
//
// Effects: The widgets are configured with the required data
// --------------------------------------------------------------------------

void CExtensionDialog::SetDialogData( void )
{
std::string srcpath, text, strbuf;
int index, result;

#ifdef DEBUG
cout << "SetDialogData" << endl;
#endif

// Get the extension entry from the current list ID and the current list index
m_pextentry = m_pextcreator->GetExtensionEntry( m_listid, m_index );

if ( NULL == m_pextentry )
	{
	m_radioselected->setChecked( FALSE );
	m_radiosearchforwards->setChecked( FALSE );
	m_editfunctioncount->setText( "0" );
	m_editconstantcount->setText( "0" );
        m_textedit->setText( "" );
	m_combobox->clearEdit();
	
	return;
	}

// ----- Name string --------------------------------------------------------

m_noupdateflag = 1;

m_editextensionname->setText( m_pextentry->m_name.data() ); 

m_radioselected->setChecked( 
		(m_pextentry->EntryGetFlag( FLAG_OUTPUT) == FLAG_OUTPUT) );

m_radiosearchforwards->setChecked( TRUE );

index = m_index;

if ( m_listid > LIST_GL )
	{
	index += m_pextcreator->GetExtensionEntryList( LIST_GL )->GetCount();
	}

if ( m_listid > LIST_WGL )
	{
	index += m_pextcreator->GetExtensionEntryList( LIST_WGL )->GetCount();
	}

#ifdef DEBUG
cout << "Setting combo box " << index << "\n";
#endif

m_combobox->setCurrentItem( index );

SetComboBox();
m_combobox->setCurrentText( m_editextensionname->text() );

// ----- Number of functions ------------------------------------------------

stl_itoa( strbuf, m_pextentry->EntryGetFuncCount() );
m_editfunctioncount->setText( strbuf.data() );

if ( m_listid != LIST_SYSTEM )
	{
	m_listfunction->setPointer( m_pextcreator );
	m_listfunction->setAllItems( m_listid, m_index );
	}

// ----- Number of constants ------------------------------------------------

stl_itoa( strbuf, m_pextentry->EntryGetConstCount() );
m_editconstantcount->setText( strbuf.data() );

if ( m_listid != LIST_SYSTEM )
	{
	m_listconstant->setPointer( m_pextcreator );
	m_listconstant->setAllItems( m_listid, m_index );
       	}

// ----- Find the path to the ASCII file specification and copy it to -------
// ----- the text buffer 
        
result = m_pextcreator->ReadRegistryWebpage( text, m_pextentry->m_name );

if ( result == READ_EXTENSION_SUCCESS )
	{
#ifdef DEBUG
	cout << "Setting text\n";
#endif
        m_textedit->setText( text.data() );
	}
else
	{
#ifdef DEBUG
	cout << "Nothing left\n";
#endif
       	m_textedit->setText( "No information available\n" );
	}

// ----- Initialise the Combo box with a set of extension names from the ----
// ----- current set

m_combobox->setMaxVisibleItems(20);

m_noupdateflag = 0;
}

// --------------------------------------------------------------------------
// Set Combo box data
// 
// Inputs:  None
//
// Outputs: None
//
// Results: None
//
// Effects: The combo box is configured with a set of extension names from 
//          the current list
// --------------------------------------------------------------------------

void CExtensionDialog::SetComboBox( void )
{
CExtensionEntryList *plist;
int pos, max, listid;

m_combobox->clear();

for ( listid = LIST_GL; listid <= LIST_GLX; listid++ )
	{
	plist = m_pextcreator->GetExtensionEntryList( listid );

	max = plist->GetCount();

	for ( pos = 0; pos < max; pos++ )
		{
		m_combobox->addItem( plist->at(pos).m_name.data(), -1 );
		}
	}

m_combobox->setCurrentItem( m_index );
m_combobox->setMaxVisibleItems(20);
}

// --------------------------------------------------------------------------
// Increment the extension index
//
// Inputs:  None
//
// Outputs: None
//
// Results: None
//
// Effects: The index is incremented. If the index reaches the end of the
//          current header file list, the list is shifted to the next
//          header file, and the index is set to the start of the list
// --------------------------------------------------------------------------

void CExtensionDialog::IncrementIndex( void )
{
int listnum;

#ifdef DEBUG
cout << "IncrementIndex"<< endl;
#endif

listnum = m_pextcreator->GetExtensionEntryListNum( m_listid );

m_index++; 	

if ( m_index == listnum )
	{
	m_index = 0;
	m_listid++;

	if ( m_listid == LIST_MAX )
		{
		m_listid = LIST_MIN;
		}
	}
}

// --------------------------------------------------------------------------
// Decrement the extension index
//
// Inputs:  None
//
// Outputs: None
//
// Results: None
//
// Effects: The index is decremented. If the index reaches the end of the 
//          current header file list, the list is shifted to the previous
//          header file, and the index is set to the end of the list.
// --------------------------------------------------------------------------

void CExtensionDialog::DecrementIndex( void )
{
m_index--;

#ifdef DEBUG
cout << "DecrementIndex" << endl;
#endif

if ( m_index < 0 )
	{
	m_listid--;

	if ( m_listid < 0 )
		{
		m_listid = LIST_MAX-1;
		}

	m_index = m_pextcreator->GetExtensionEntryListNum( m_listid )-1;
	}
}

// --------------------------------------------------------------------------
// If the radio button or either of the 'add' or 'remove' push buttons are
// pressed, then set or clear the selected flag
//
// Inputs: mode - Whether the extension is to used or not
//
// Outputs: None
//
// Results: None
//
// Effects: The selected extension is either selected or unselected
// --------------------------------------------------------------------------

void CExtensionDialog::SetSelected( int mode )
{
#ifdef DEBUG
cout << "SetSelected" << endl;
#endif

if ( !m_pextentry )
	{
	return;
	}

if ( mode )
	{
	m_pextentry->EntrySetFlag( FLAG_OUTPUT);
	}
else
	{
	m_pextentry->EntryClearFlag( FLAG_OUTPUT);
	}
}

// ==========================================================================
// DIALOG CONTROLS 
// ==========================================================================

void CExtensionDialog::pushbuttonprevious_clicked( void )
{
DecrementIndex();
SetDialogData();
}

void CExtensionDialog::pushbuttonnext_clicked( void )
{
IncrementIndex();
SetDialogData();
}

void CExtensionDialog::pushbuttonok_clicked(void )
{
accept();
}

void CExtensionDialog::pushbuttonremove_clicked( void )
{
SetSelected(0);
SetDialogData();
}

void CExtensionDialog::pushbuttonadd_clicked( void )
{
SetSelected(1);
SetDialogData();
}

void CExtensionDialog::radioselected_toggled( bool value )
{
SetSelected( value );
SetDialogData();
}

void CExtensionDialog::radiowholewords_toggled( bool /* value */ )
{
// Notes: Nothing to do here - handled by QWidget
}

void CExtensionDialog::radiocasesensitive_toggled( bool /* value */ )
{
// Notes: Nothing to do here - handled by QWidget
}

void CExtensionDialog::radiosearchforwards_toggled( bool /* value */ )
{
// Notes: Nothing to do here - handled by QWidget
}

void CExtensionDialog::editextensionname_textChanged( const QString &string )
{
#ifdef DEBUG
cout << "Extension name changed" << endl;
#endif

if ( 0 != m_noupdateflag )
	{
	return;
	}

SetExtensionName( (char *) string.ascii() );
}

void CExtensionDialog::combobox_activated( const QString &string )
{
#ifdef DEBUG
cout << "Combo box activated" << endl;
#endif

if ( 0 != m_noupdateflag )
	{
	return;
	}

SetExtensionName( (char *) string.ascii() );
}

void CExtensionDialog::editfindtext_textChanged( const QString &string )
{
QTextDocument::FindFlags flags = 0;

if ( m_noupdateflag )
	{
	return;
	}

#ifdef DEBUG
cout << "Find text changed" << endl;
#endif

if ( m_radiocasesensitive->isOn() )
	{
	flags |= QTextDocument::FindCaseSensitively;
	}

if ( m_radiowholewords->isOn() )
	{
	flags |= QTextDocument::FindWholeWords;
	}

if ( !( m_radiosearchforwards->isOn() ) )
	{
	flags |= QTextDocument::FindBackward;
	}
	
m_textedit->find( string, flags );
}

void CExtensionDialog::pushbuttonfind_clicked( void )
{
QTextDocument::FindFlags flags = QTextDocument::FindCaseSensitively;

		//TRUE, FALSE, TRUE, NULL, NULL );
m_textedit->find( m_editfindtext->text(), flags );
}
