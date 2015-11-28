// ---------------------------------------------------------------------------
// Copyright: (C) VFX Research 2002 - 2014. All Rights Reserved.
// ---------------------------------------------------------------------------

#ifndef REGISTRYADDSITEDIALOG_H
#define REGISTRYADDSITEDIALOG_H

using namespace std;

#include <cstdio>
#include <cstdlib>
#include <iostream>

#include "extensionlib.h"
#include ".ui/ui_registryaddsitebasedlg.h"
#include "registryupdatefunc.h"

#define REGISTRYADDSITE_OK     0x0001
#define REGISTRYADDSITE_CANCEL 0x0002

// --------------------------------------------------------------------------
// Class to handle the addition of new sites
// --------------------------------------------------------------------------

class CRegistryAddSiteDialog : public QDialog,
				public Ui_CRegistryAddSiteBaseDialog
{
	Q_OBJECT

public:

// ----- Internal variables -------------------------------------------------

CExtensionSiteInfoList *m_psiteinfolist;
string			m_localstring;
CRegistryUpdateListFunc *m_pupdatelistfunc;

// ----- Constructor and Destructor -----------------------------------------


CRegistryAddSiteDialog( void ) : Ui_CRegistryAddSiteBaseDialog()
	{
	setupUi( this );
	Init();	
	}

// ----- Functions and Procedures -------------------------------------------

void SetPointer( CExtensionSiteInfoList *psiteinfolist );

void SetUpdateList( CRegistryUpdateListFunc *pupdatelistfunc )
	{
	m_pupdatelistfunc = pupdatelistfunc;
	}

void AddNewSite( void );

void Init( void );

void Deallocate( void );

// ----- Widget events ------------------------------------------------------

protected slots:
void pushbuttonok_clicked( void );
void pushbuttoncancel_clicked( void );
void pushbuttonapply_clicked( void );
void lineeditdescription_textChanged( const QString &string );
};


#endif 
