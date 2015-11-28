// ---------------------------------------------------------------------------
// Copyright: (C) VFX Research 2002 - 2014. All Rights Reserved.
// ---------------------------------------------------------------------------

#ifndef _CEXTENSIONSITEINFOLISTIO_H_
#define _CEXTENSIONSITEINFOLISTIO_H_

// -------------------------------------------------------------------------
// Change flags (dirty flags)
// -------------------------------------------------------------------------

enum CExtensionSiteInfoListIOChangeFlags
	{
	CEXTENSIONSITEINFOLISTIO_CHANGEFLAG_LISTDATA = 0x0001,
	};

#define CEXTENSIONSITEINFOLISTIO_CHANGEFLAG_NUM 1

// --------------------------------------------------------------------------- 
// Main class definition for CExtensionSiteInfoListIOData
// --------------------------------------------------------------------------- 

class CExtensionSiteInfoListIOData : public vector <CExtensionSiteInfo>


{
// ----- Class members ------------------------------------------------------- 
public:


// ----- Constructor and destructor ------------------------------------------ 

CExtensionSiteInfoListIOData( void )
	{
	CExtensionSiteInfoListIOData::Init();
	}

~CExtensionSiteInfoListIOData( void )
	{
	CExtensionSiteInfoListIOData::Deallocate();
	}

// ----- Functions and Procedures -------------------------------------------- 

void Init( void )
	{
	}

void Deallocate()
	{
	vector <CExtensionSiteInfo>::clear();

	Init();
	}
};

// ---------------------------------------------------------------------
// File IO class for ASCII data
// ---------------------------------------------------------------------

class CExtensionSiteInfoListIODataAsciiIO : virtual public CVirtualFileSystemAscii,
				virtual public CExtensionSiteInfoListIOData
{
public:
// ----- File reading and writing -------------------------------------------

using CVirtualFileSystemAscii::ReadFile;

int ReadFile( ifstream &stream );
int ReadFileInternal( ifstream &stream );

using CVirtualFileSystemAscii::WriteFile;

int WriteFile( ofstream &stream, unsigned int depth );
int WriteFile( ofstream &stream, unsigned int depth, const char *pstr );
};

// ---------------------------------------------------------------------
// Combined IO class for Ascii and Binary data
// --------------------------------------------------------------------

class CExtensionSiteInfoListIO: virtual public CExtensionSiteInfoListIODataAsciiIO

{
// ----- Constructor and Destructor ----------------------------

public:
CExtensionSiteInfoListIO( void )
	{
	Init();
	}

// ----- Functions ---------------------------------------------

void Init( void )
	{
	CExtensionSiteInfoListIOData::Init();
	}
};

#endif	// _CEXTENSIONSITEINFOLISTIO_H_
