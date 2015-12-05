// ---------------------------------------------------------------------------
// Copyright: (C) VFX Research 2002 - 2014. All Rights Reserved.
// ---------------------------------------------------------------------------

#include "config.h"
#include "registrysettingsdlg.h"
#include "registryaddsitedlg.h"
                                                                                
#include "extensionlib.h"
#include <webpagelistwidget/webpagelistwidget.h>
#include "qlineedit.h"
#include "qradiobutton.h"
#include "qfiledialog.h"
#include "qstring.h"
#include "qcheckbox.h"
#include "q3listview.h"

// ----- Functions and Procedures -------------------------------------------

void  CRegistryAddSiteDialog::Init( void )
{
// Step 1: Set values to something sensible
m_psiteinfolist = NULL;
m_localstring = "";
}

// --------------------------------------------------------------------------
// Set the pointer to the current site info list
// --------------------------------------------------------------------------

void CRegistryAddSiteDialog::SetPointer( CExtensionSiteInfoList *psiteinfolist )
{
// Step 2: Set pointer
m_psiteinfolist = psiteinfolist;
}

// --------------------------------------------------------------------------
// Add new site
// --------------------------------------------------------------------------

void CRegistryAddSiteDialog::AddNewSite( void )
{
// Step 3: When the text changes have been completed
//         add the new site providing the site list exists
//	   and the add flag is clear

if ( NULL == m_psiteinfolist )
	{
	return;
	}

if ( m_psiteinfolist->FindSite( m_localstring ) != -1 )
	{	
	std::cout << "Site already exists\n";
	return;
	}

#ifdef DEBUG
cout << "Adding new site |" << m_localstring.data() << "|\n";
#endif

// Begin a new entry
m_psiteinfolist->Begin( m_localstring.data() );

// End the new entry
m_psiteinfolist->End();

if ( m_pupdatelistfunc != NULL )
	{
	m_pupdatelistfunc->SetSiteList();
	}
}

void  CRegistryAddSiteDialog::Deallocate( void )
{
// Nothing to do here
}

// ----- Widget events ------------------------------------------------------
                                                                                  
void  CRegistryAddSiteDialog::pushbuttonok_clicked( void )
{
AddNewSite();
done( REGISTRYADDSITE_OK );
};
                                                                                  
void  CRegistryAddSiteDialog::pushbuttoncancel_clicked( void )
{
done( REGISTRYADDSITE_CANCEL );
};
                                                                                  
void  CRegistryAddSiteDialog::pushbuttonapply_clicked( void )
{
AddNewSite();
}
                                                                                  
void  CRegistryAddSiteDialog::lineeditdescription_textChanged( const QString &strdata )
{
if ( strcmp( m_localstring.data(), strdata.ascii() ) != 0 )
	{
	m_localstring = std::string( strdata.ascii() );
	}
}
