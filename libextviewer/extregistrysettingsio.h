// ---------------------------------------------------------------------------
// Copyright: (C) VFX Research 2002 - 2014. All Rights Reserved.
// ---------------------------------------------------------------------------

#ifndef _CEXTENSIONREGISTRYSETTINGSIO_H_
#define _CEXTENSIONREGISTRYSETTINGSIO_H_

// -------------------------------------------------------------------------
// Change flags (dirty flags)
// -------------------------------------------------------------------------

enum CExtensionRegistrySettingsIOChangeFlags
	{
	CEXTENSIONREGISTRYSETTINGSIO_CHANGEFLAG_DOWNLOADSTATUS = 0x0001,
	CEXTENSIONREGISTRYSETTINGSIO_CHANGEFLAG_DRYRUNMODE,
	};

#define CEXTENSIONREGISTRYSETTINGSIO_CHANGEFLAG_NUM 2

// --------------------------------------------------------------------------- 
// Main class definition for CExtensionRegistrySettingsIOData
// --------------------------------------------------------------------------- 

class CExtensionRegistrySettingsIOData
{
// ----- Class members ------------------------------------------------------- 
public:

int	m_downloadstatus;	// Download status
int	m_dryrunmode;		// Control flag for performing dry-run

// ----- Constructor and destructor ------------------------------------------ 

CExtensionRegistrySettingsIOData( void )
	{
	CExtensionRegistrySettingsIOData::Init();
	}

~CExtensionRegistrySettingsIOData( void )
	{
	CExtensionRegistrySettingsIOData::Deallocate();
	}

// ----- Functions and Procedures -------------------------------------------- 

void Init( void )
	{
	m_downloadstatus = 0;
	m_dryrunmode = 0;
	}

void Deallocate()
	{

	Init();
	}
// ----- Manage getting and setting values -----------------------------------

inline int GetDownloadstatus( void )
	{
	return( m_downloadstatus );
	}

inline void SetDownloadstatus( const int value )
	{
	m_downloadstatus = value;
	}

inline int GetDryrunmode( void )
	{
	return( m_dryrunmode );
	}

inline void SetDryrunmode( const int value )
	{
	m_dryrunmode = value;
	}

};

// ---------------------------------------------------------------------
// File IO class for ASCII data
// ---------------------------------------------------------------------

class CExtensionRegistrySettingsIODataAsciiIO : virtual public CVirtualFileSystemAscii,
				virtual public CExtensionRegistrySettingsIOData
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

class CExtensionRegistrySettingsIO: virtual public CExtensionRegistrySettingsIODataAsciiIO

{
// ----- Constructor and Destructor ----------------------------

public:
CExtensionRegistrySettingsIO( void )
	{
	Init();
	}

// ----- Functions ---------------------------------------------

void Init( void )
	{
	CExtensionRegistrySettingsIOData::Init();
	}
};

#endif	// _CEXTENSIONREGISTRYSETTINGSIO_H_
