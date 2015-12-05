// ---------------------------------------------------------------------------
// Copyright: (C) VFX Research 2002 - 2014. All Rights Reserved.
// ---------------------------------------------------------------------------

#ifndef _CEXTENSIONVIEWERIO_H_
#define _CEXTENSIONVIEWERIO_H_

// -------------------------------------------------------------------------
// Change flags (dirty flags)
// -------------------------------------------------------------------------

enum CExtensionViewerIOChangeFlags
	{
	CEXTENSIONVIEWERIO_CHANGEFLAG_REGISTRYSETTINGS = 0x0001,
	CEXTENSIONVIEWERIO_CHANGEFLAG_HEADERFILESET,
	CEXTENSIONVIEWERIO_CHANGEFLAG_SITELIST,
	CEXTENSIONVIEWERIO_CHANGEFLAG_SCRIPTSETTINGS,
	CEXTENSIONVIEWERIO_CHANGEFLAG_OUTPUTSETTINGS,
	CEXTENSIONVIEWERIO_CHANGEFLAG_CONFIGFILESETTINGS,
	};

#define CEXTENSIONVIEWERIO_CHANGEFLAG_NUM 6

// --------------------------------------------------------------------------- 
// Main class definition for CExtensionViewerIOData
// --------------------------------------------------------------------------- 

class CExtensionViewerIOData
{
// ----- Class members ------------------------------------------------------- 
public:

CExtensionRegistrySettings	m_registrysettings;	// Registry settings
CExtensionHeaderFileSet	m_headerfileset;	// Extension configuration settings
CExtensionSiteInfoList	m_sitelist;		// Extension site info list
CExtensionScriptSettings	m_scriptsettings;	// Script settings
COutputFileSettings	m_outputfilesettings;	// Output settings
CConfigurationFileSettings	m_configfilesettings;	// Configuration file settings

// ----- Constructor and destructor ------------------------------------------ 

CExtensionViewerIOData( void )
	{
	CExtensionViewerIOData::Init();
	}

~CExtensionViewerIOData( void )
	{
	CExtensionViewerIOData::Deallocate();
	}

// ----- Functions and Procedures -------------------------------------------- 

void Init( void )
	{
	m_registrysettings.Init();
	m_headerfileset.Init();
	m_sitelist.Init();
	m_scriptsettings.Init();
	m_outputfilesettings.Init();
	m_configfilesettings.Init();
	}

void Deallocate()
	{
	m_registrysettings.Deallocate();
	m_headerfileset.Deallocate();
	m_sitelist.Deallocate();
	m_scriptsettings.Deallocate();
	m_outputfilesettings.Deallocate();
	m_configfilesettings.Deallocate();

	Init();
	}
// ----- Manage getting and setting values -----------------------------------

inline CExtensionRegistrySettings const & GetRegistrysettings( void )
	{
	return( m_registrysettings );
	}

inline void SetRegistrysettings( const CExtensionRegistrySettings & value )
	{
	m_registrysettings = value;
	}

inline CExtensionHeaderFileSet const & GetHeaderfileset( void )
	{
	return( m_headerfileset );
	}

inline void SetHeaderfileset( const CExtensionHeaderFileSet & value )
	{
	m_headerfileset = value;
	}

inline CExtensionSiteInfoList const & GetSitelist( void )
	{
	return( m_sitelist );
	}

inline void SetSitelist( const CExtensionSiteInfoList & value )
	{
	m_sitelist = value;
	}

inline CExtensionScriptSettings const & GetScriptsettings( void )
	{
	return( m_scriptsettings );
	}

inline void SetScriptsettings( const CExtensionScriptSettings & value )
	{
	m_scriptsettings = value;
	}

inline COutputFileSettings const & GetOutputsettings( void )
	{
	return( m_outputfilesettings );
	}

inline void SetOutputsettings( const COutputFileSettings & value )
	{
	m_outputfilesettings = value;
	}

inline CConfigurationFileSettings const & GetConfigfilesettings( void )
	{
	return( m_configfilesettings );
	}

inline void SetConfigfilesettings( const CConfigurationFileSettings & value )
	{
	m_configfilesettings = value;
	}

};

// ---------------------------------------------------------------------
// File IO class for ASCII data
// ---------------------------------------------------------------------

class CExtensionViewerIODataAsciiIO : virtual public CVirtualFileSystemAscii,
				virtual public CExtensionViewerIOData
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

class CExtensionViewerIO: virtual public CExtensionViewerIODataAsciiIO

{
// ----- Constructor and Destructor ----------------------------

public:
CExtensionViewerIO( void )
	{
	Init();
	}

// ----- Functions ---------------------------------------------

void Init( void )
	{
	CExtensionViewerIOData::Init();
	}
};

#endif	// _CEXTENSIONVIEWERIO_H_
