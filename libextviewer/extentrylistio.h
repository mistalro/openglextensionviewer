// ---------------------------------------------------------------------------
// Copyright: (C) VFX Research 2002 - 2014. All Rights Reserved.
// ---------------------------------------------------------------------------

#ifndef _CEXTENSIONENTRYLISTIO_H_
#define _CEXTENSIONENTRYLISTIO_H_

// -------------------------------------------------------------------------
// Change flags (dirty flags)
// -------------------------------------------------------------------------

enum CExtensionEntryListIOChangeFlags
	{
	CEXTENSIONENTRYLISTIO_CHANGEFLAG_LISTDATA = 0x0001,
	};

#define CEXTENSIONENTRYLISTIO_CHANGEFLAG_NUM 1

// --------------------------------------------------------------------------- 
// Main class definition for CEntryListData
// --------------------------------------------------------------------------- 

class CEntryListData : public std::vector <CExtensionEntry>


{
// ----- Class members ------------------------------------------------------- 
public:

CExtensionEntry	m_listdata;		// List of items

// ----- Constructor and destructor ------------------------------------------ 

CEntryListData( void )
	{
	CEntryListData::Init();
	}

~CEntryListData( void )
	{
	CEntryListData::Deallocate();
	}

// ----- Functions and Procedures -------------------------------------------- 

void Init( void )
	{
	m_listdata.Init();
	}

void Deallocate()
	{
	vector <CExtensionEntry>::clear();

	Init();
	}
// ----- Manage getting and setting values -----------------------------------

inline CExtensionEntry const & GetListdata( void )
	{
	return( m_listdata );
	}

inline void SetListdata( const CExtensionEntry & value )
	{
	m_listdata = value;
	}

};

// ---------------------------------------------------------------------
// File IO class for ASCII data
// ---------------------------------------------------------------------

class CEntryListDataAsciiIO : virtual public CVirtualFileSystemAscii,
				virtual public CEntryListData
{
public:
// ----- File reading and writing -------------------------------------------

using CVirtualFileSystemAscii::ReadFile;

int ReadFile( std::ifstream &stream );
int ReadFileInternal( std::ifstream &stream );

using CVirtualFileSystemAscii::WriteFile;

int WriteFile( std::ofstream &stream, unsigned int depth );
int WriteFile( std::ofstream &stream, unsigned int depth, const char *pstr );
};

// ---------------------------------------------------------------------
// Combined IO class for Ascii and Binary data
// --------------------------------------------------------------------

class CExtensionEntryListIO: virtual public CEntryListDataAsciiIO

{
// ----- Constructor and Destructor ----------------------------

public:
CExtensionEntryListIO( void )
	{
	Init();
	}

// ----- Functions ---------------------------------------------

void Init( void )
	{
	CEntryListData::Init();
	}
};

#endif	// _CEXTENSIONENTRYLISTIO_H_
