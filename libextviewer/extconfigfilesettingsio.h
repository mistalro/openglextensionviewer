// ---------------------------------------------------------------------------
// Copyright: (C) VFX Research 2002 - 2014. All Rights Reserved.
// ---------------------------------------------------------------------------

#ifndef _CCONFIGURATIONFILESETTINGSIO_H_
#define _CCONFIGURATIONFILESETTINGSIO_H_

// -------------------------------------------------------------------------
// Change flags (dirty flags)
// -------------------------------------------------------------------------

enum CConfigurationFileSettingsIOChangeFlags
	{
	CCONFIGURATIONFILESETTINGSIO_CHANGEFLAG_NEWCONFIGFLAG = 0x0001,
	CCONFIGURATIONFILESETTINGSIO_CHANGEFLAG_CONFIGSETTINGSFILE,
	CCONFIGURATIONFILESETTINGSIO_CHANGEFLAG_AUTOREADHEADERFLAGS,
	CCONFIGURATIONFILESETTINGSIO_CHANGEFLAG_AUTOLOADCONFIGFLAGS,
	CCONFIGURATIONFILESETTINGSIO_CHANGEFLAG_AUTOSAVECONFIGFLAGS,
	};

#define CCONFIGURATIONFILESETTINGSIO_CHANGEFLAG_NUM 5

// --------------------------------------------------------------------------- 
// Main class definition for CConfigurationFileSettingsData
// --------------------------------------------------------------------------- 

class CConfigurationFileSettingsData
{
// ----- Class members ------------------------------------------------------- 
public:

int	m_newconfigflag;	// New configuration flag - no name
string	m_configfile;		// Configuration file
int	m_autoreadheaderflags;	// Automatically read header files
int	m_autoloadconfigflags;	// Automatically load configuration files
int	m_autosaveconfigflags;	// Automatically save configuration files

// ----- Constructor and destructor ------------------------------------------ 

CConfigurationFileSettingsData( void )
	{
	CConfigurationFileSettingsData::Init();
	}

~CConfigurationFileSettingsData( void )
	{
	CConfigurationFileSettingsData::Deallocate();
	}

// ----- Functions and Procedures -------------------------------------------- 

void Init( void )
	{
	m_newconfigflag = 0;
	m_configfile = "";
	m_autoreadheaderflags = 0;
	m_autoloadconfigflags = 0;
	m_autosaveconfigflags = 0;
	}

void Deallocate()
	{
	m_configfile.clear();

	Init();
	}
// ----- Manage getting and setting values -----------------------------------

inline int GetNewconfigflag( void )
	{
	return( m_newconfigflag );
	}

inline void SetNewconfigflag( const int value )
	{
	m_newconfigflag = value;
	}

inline string & GetConfigsettingsfile( void )
	{
	return( m_configfile );
	}

inline void SetConfigsettingsfile( const string  &value )
	{
	m_configfile = value;
	}

inline void SetConfigsettingsfile( const char *  &value )
	{
	m_configfile = value;
	}

inline int GetAutoreadheaderflags( void )
	{
	return( m_autoreadheaderflags );
	}

inline void SetAutoreadheaderflags( const int value )
	{
	m_autoreadheaderflags = value;
	}

inline int GetAutoloadconfigflags( void )
	{
	return( m_autoloadconfigflags );
	}

inline void SetAutoloadconfigflags( const int value )
	{
	m_autoloadconfigflags = value;
	}

inline int GetAutosaveconfigflags( void )
	{
	return( m_autosaveconfigflags );
	}

inline void SetAutosaveconfigflags( const int value )
	{
	m_autosaveconfigflags = value;
	}

};

// ---------------------------------------------------------------------
// File IO class for ASCII data
// ---------------------------------------------------------------------

class CConfigurationFileSettingsDataAsciiIO : virtual public CVirtualFileSystemAscii,
				virtual public CConfigurationFileSettingsData
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

class CConfigurationFileSettingsIO: virtual public CConfigurationFileSettingsDataAsciiIO

{
// ----- Constructor and Destructor ----------------------------

public:
CConfigurationFileSettingsIO( void )
	{
	Init();
	}

// ----- Functions ---------------------------------------------

void Init( void )
	{
	CConfigurationFileSettingsData::Init();
	}
};

#endif	// _CCONFIGURATIONFILESETTINGSIO_H_
