// ---------------------------------------------------------------------------
// Copyright: (C) VFX Research 2002 - 2014. All Rights Reserved.
// ---------------------------------------------------------------------------

#ifndef _CEXTENSIONHEADERFILESETIO_H_
#define _CEXTENSIONHEADERFILESETIO_H_

// -------------------------------------------------------------------------
// Change flags (dirty flags)
// -------------------------------------------------------------------------

enum CExtensionHeaderFileSetIOChangeFlags
	{
	CEXTENSIONHEADERFILESETIO_CHANGEFLAG_GLLIST = 0x0001,
	CEXTENSIONHEADERFILESETIO_CHANGEFLAG_WGLLIST,
	CEXTENSIONHEADERFILESETIO_CHANGEFLAG_GLXLIST,
	CEXTENSIONHEADERFILESETIO_CHANGEFLAG_COREARBLIST,
	CEXTENSIONHEADERFILESETIO_CHANGEFLAG_SYSTEMLIST,
	CEXTENSIONHEADERFILESETIO_CHANGEFLAG_NEWLIST,
	CEXTENSIONHEADERFILESETIO_CHANGEFLAG_IGNORELIST,
	CEXTENSIONHEADERFILESETIO_CHANGEFLAG_VENDORLIST,
	CEXTENSIONHEADERFILESETIO_CHANGEFLAG_VERSIONLIST,
	CEXTENSIONHEADERFILESETIO_CHANGEFLAG_SAVEDSTATES,
	};

#define CEXTENSIONHEADERFILESETIO_CHANGEFLAG_NUM 10

// --------------------------------------------------------------------------- 
// Main class definition for CExtensionHeaderFileSettingsIOData
// --------------------------------------------------------------------------- 

class CExtensionHeaderFileSettingsIOData
{
// ----- Class members ------------------------------------------------------- 
public:

CExtensionHeaderFileFuncGL	m_gllist;		// List for GL extensions found on system
CExtensionHeaderFileFuncWGL	m_wgllist;		// List for WGL extensions found on system
CExtensionHeaderFileFuncGLX	m_glxlist;		// List for WGL extensions found on system
CExtensionHeaderFileFuncCoreARB	m_corearblist;		// List for COREARB extensions found on system
CExtensionHeaderFileFuncSystem	m_systemlist;		// List for extensions found on system
CExtensionHeaderFileFuncNew	m_newlist;		// List for new extensions
CExtensionHeaderFileFuncIgnore	m_ignorelist;		// List for ignored extensions
CExtensionHeaderFileFuncVendor	m_vendorlist;		// List for vendors
CExtensionHeaderFileFuncVersion	m_versionlist;		// List for versions
int	m_savedstates;		// Number of saved states

// ----- Constructor and destructor ------------------------------------------ 

CExtensionHeaderFileSettingsIOData( void )
	{
	CExtensionHeaderFileSettingsIOData::Init();
	}

~CExtensionHeaderFileSettingsIOData( void )
	{
	CExtensionHeaderFileSettingsIOData::Deallocate();
	}

// ----- Functions and Procedures -------------------------------------------- 

void Init( void )
	{
	m_gllist.Init();
	m_wgllist.Init();
	m_glxlist.Init();
	m_corearblist.Init();
	m_systemlist.Init();
	m_newlist.Init();
	m_ignorelist.Init();
	m_vendorlist.Init();
	m_versionlist.Init();
	m_savedstates = 0;
	}

void Deallocate()
	{
	m_systemlist.Deallocate();
	m_newlist.Deallocate();
	m_ignorelist.Deallocate();
	m_vendorlist.Deallocate();
	m_versionlist.Deallocate();

	Init();
	}
// ----- Manage getting and setting values -----------------------------------

inline CExtensionHeaderFileFuncGL const & GetGllist( void )
	{
	return( m_gllist );
	}

inline void SetGllist( const CExtensionHeaderFileFuncGL & value )
	{
	m_gllist = value;
	}

inline CExtensionHeaderFileFuncWGL const & GetWgllist( void )
	{
	return( m_wgllist );
	}

inline void SetWgllist( const CExtensionHeaderFileFuncWGL & value )
	{
	m_wgllist = value;
	}

inline CExtensionHeaderFileFuncGLX const & GetGlxlist( void )
	{
	return( m_glxlist );
	}

inline void SetGlxlist( const CExtensionHeaderFileFuncGLX & value )
	{
	m_glxlist = value;
	}

inline CExtensionHeaderFileFuncCoreARB const & GetCorearblist( void )
	{
	return( m_corearblist );
	}

inline void SetCorearblist( const CExtensionHeaderFileFuncCoreARB & value )
	{
	m_corearblist = value;
	}

inline CExtensionHeaderFileFuncSystem const & GetSystemlist( void )
	{
	return( m_systemlist );
	}

inline void SetSystemlist( const CExtensionHeaderFileFuncSystem & value )
	{
	m_systemlist = value;
	}

inline CExtensionHeaderFileFuncNew const & GetNewlist( void )
	{
	return( m_newlist );
	}

inline void SetNewlist( const CExtensionHeaderFileFuncNew & value )
	{
	m_newlist = value;
	}

inline CExtensionHeaderFileFuncIgnore const & GetIgnorelist( void )
	{
	return( m_ignorelist );
	}

inline void SetIgnorelist( const CExtensionHeaderFileFuncIgnore & value )
	{
	m_ignorelist = value;
	}

inline CExtensionHeaderFileFuncVendor const & GetVendorlist( void )
	{
	return( m_vendorlist );
	}

inline void SetVendorlist( const CExtensionHeaderFileFuncVendor & value )
	{
	m_vendorlist = value;
	}

inline CExtensionHeaderFileFuncVersion const & GetVersionlist( void )
	{
	return( m_versionlist );
	}

inline void SetVersionlist( const CExtensionHeaderFileFuncVersion & value )
	{
	m_versionlist = value;
	}

inline int GetSavedstates( void )
	{
	return( m_savedstates );
	}

inline void SetSavedstates( const int value )
	{
	m_savedstates = value;
	}

};

// ---------------------------------------------------------------------
// File IO class for ASCII data
// ---------------------------------------------------------------------

class CExtensionHeaderFileSettingsIODataAsciiIO : virtual public CVirtualFileSystemAscii,
				virtual public CExtensionHeaderFileSettingsIOData
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

class CExtensionHeaderFileSetIO: virtual public CExtensionHeaderFileSettingsIODataAsciiIO

{
// ----- Constructor and Destructor ----------------------------

public:
CExtensionHeaderFileSetIO( void )
	{
	Init();
	}

// ----- Functions ---------------------------------------------

void Init( void )
	{
	CExtensionHeaderFileSettingsIOData::Init();
	}
};

#endif	// _CEXTENSIONHEADERFILESETIO_H_
