// ---------------------------------------------------------------------------
// Copyright: (C) VFX Research 2002 - 2014. All Rights Reserved.
// ---------------------------------------------------------------------------

#ifndef _CEXTENSIONSITEINFOIO_H_
#define _CEXTENSIONSITEINFOIO_H_

// -------------------------------------------------------------------------
// Change flags (dirty flags)
// -------------------------------------------------------------------------

enum CExtensionSiteInfoIOChangeFlags
	{
	CEXTENSIONSITEINFOIO_CHANGEFLAG_DESCRIPTION = 0x0001,
	CEXTENSIONSITEINFOIO_CHANGEFLAG_INDEXDIRLOCAL,
	CEXTENSIONSITEINFOIO_CHANGEFLAG_INDEXPAGENET,
	CEXTENSIONSITEINFOIO_CHANGEFLAG_INDEXPAGELOCAL,
	CEXTENSIONSITEINFOIO_CHANGEFLAG_GLHEADERNET,
	CEXTENSIONSITEINFOIO_CHANGEFLAG_GLHEADERLOCAL,
	CEXTENSIONSITEINFOIO_CHANGEFLAG_GLXHEADERNET,
	CEXTENSIONSITEINFOIO_CHANGEFLAG_GLXHEADERLOCAL,
	CEXTENSIONSITEINFOIO_CHANGEFLAG_WGLHEADERNET,
	CEXTENSIONSITEINFOIO_CHANGEFLAG_WGLHEADERLOCAL,
	CEXTENSIONSITEINFOIO_CHANGEFLAG_COREHEADERNET,
	CEXTENSIONSITEINFOIO_CHANGEFLAG_COREHEADERLOCAL,
	CEXTENSIONSITEINFOIO_CHANGEFLAG_DOWNLOADFLAGS,
	CEXTENSIONSITEINFOIO_CHANGEFLAG_FILETYPEFILTERS,
	};

#define CEXTENSIONSITEINFOIO_CHANGEFLAG_NUM 14

// --------------------------------------------------------------------------- 
// Main class definition for CExtensionSiteInfoIOData
// --------------------------------------------------------------------------- 

class CExtensionSiteInfoIOData
{
// ----- Class members ------------------------------------------------------- 
public:

std::string	m_description;		// Description
std::string	m_indexdirlocal;	// OpenGL registry local directory
std::string	m_indexpagenet;		// OpenGL registry web page
std::string	m_indexpagelocal;	// OpenGL registry local copy
std::string	m_glheadernet;		// OpenGL registry header file
std::string	m_glheaderlocal;	// OpenGL header local copy
std::string	m_glxheadernet;		// GLX registry header file
std::string	m_glxheaderlocal;	// GLX header local copy
std::string	m_wglheadernet;		// WGL registry header file
std::string	m_wglheaderlocal;	// WGL header local copy
std::string	m_coreheadernet;	// Core ARB header file
std::string	m_coreheaderlocal;	// Core ARB header local copy
int	m_downloadflags;	// Download flags
std::string	m_filetypefilter;	// File type filters

// ----- Constructor and destructor ------------------------------------------ 

CExtensionSiteInfoIOData( void )
	{
	CExtensionSiteInfoIOData::Init();
	}

~CExtensionSiteInfoIOData( void )
	{
	CExtensionSiteInfoIOData::Deallocate();
	}

// ----- Functions and Procedures -------------------------------------------- 

void Init( void )
	{
	m_description = "";
	m_indexdirlocal = "";
	m_indexpagenet = "";
	m_indexpagelocal = "";
	m_glheadernet = "";
	m_glheaderlocal = "";
	m_glxheadernet = "";
	m_glxheaderlocal = "";
	m_wglheadernet = "";
	m_wglheaderlocal = "";
	m_coreheadernet = "";
	m_coreheaderlocal = "";
	m_downloadflags = 0;
	m_filetypefilter = "";
	}

void Deallocate()
	{
	m_description.clear();
	m_indexdirlocal.clear();
	m_indexpagenet.clear();
	m_indexpagelocal.clear();
	m_glheadernet.clear();
	m_glheaderlocal.clear();
	m_glxheadernet.clear();
	m_glxheaderlocal.clear();
	m_wglheadernet.clear();
	m_wglheaderlocal.clear();
	m_coreheadernet.clear();
	m_coreheaderlocal.clear();
	m_filetypefilter.clear();

	Init();
	}
// ----- Manage getting and setting values -----------------------------------

inline std::string & GetDescription( void )
	{
	return( m_description );
	}

inline void SetDescription( const std::string  &value )
	{
	m_description = value;
	}

inline void SetDescription( const char *  &value )
	{
	m_description = value;
	}

inline std::string & GetIndexdirlocal( void )
	{
	return( m_indexdirlocal );
	}

inline void SetIndexdirlocal( const std::string  &value )
	{
	m_indexdirlocal = value;
	}

inline void SetIndexdirlocal( const char *  &value )
	{
	m_indexdirlocal = value;
	}

inline std::string & GetIndexpagenet( void )
	{
	return( m_indexpagenet );
	}

inline void SetIndexpagenet( const std::string  &value )
	{
	m_indexpagenet = value;
	}

inline void SetIndexpagenet( const char *  &value )
	{
	m_indexpagenet = value;
	}

inline std::string & GetIndexpagelocal( void )
	{
	return( m_indexpagelocal );
	}

inline void SetIndexpagelocal( const std::string  &value )
	{
	m_indexpagelocal = value;
	}

inline void SetIndexpagelocal( const char *  &value )
	{
	m_indexpagelocal = value;
	}

inline std::string & GetGlheadernet( void )
	{
	return( m_glheadernet );
	}

inline void SetGlheadernet( const std::string  &value )
	{
	m_glheadernet = value;
	}

inline void SetGlheadernet( const char *  &value )
	{
	m_glheadernet = value;
	}

inline std::string & GetGlheaderlocal( void )
	{
	return( m_glheaderlocal );
	}

inline void SetGlheaderlocal( const std::string  &value )
	{
	m_glheaderlocal = value;
	}

inline void SetGlheaderlocal( const char *  &value )
	{
	m_glheaderlocal = value;
	}

inline std::string & GetGlxheadernet( void )
	{
	return( m_glxheadernet );
	}

inline void SetGlxheadernet( const std::string  &value )
	{
	m_glxheadernet = value;
	}

inline void SetGlxheadernet( const char *  &value )
	{
	m_glxheadernet = value;
	}

inline std::string & GetGlxheaderlocal( void )
	{
	return( m_glxheaderlocal );
	}

inline void SetGlxheaderlocal( const std::string  &value )
	{
	m_glxheaderlocal = value;
	}

inline void SetGlxheaderlocal( const char *  &value )
	{
	m_glxheaderlocal = value;
	}

inline std::string & GetWglheadernet( void )
	{
	return( m_wglheadernet );
	}

inline void SetWglheadernet( const std::string  &value )
	{
	m_wglheadernet = value;
	}

inline void SetWglheadernet( const char *  &value )
	{
	m_wglheadernet = value;
	}

inline std::string & GetWglheaderlocal( void )
	{
	return( m_wglheaderlocal );
	}

inline void SetWglheaderlocal( const std::string  &value )
	{
	m_wglheaderlocal = value;
	}

inline void SetWglheaderlocal( const char *  &value )
	{
	m_wglheaderlocal = value;
	}

inline std::string & GetCoreheadernet( void )
	{
	return( m_coreheadernet );
	}

inline void SetCoreheadernet( const std::string  &value )
	{
	m_coreheadernet = value;
	}

inline void SetCoreheadernet( const char *  &value )
	{
	m_coreheadernet = value;
	}

inline std::string & GetCoreheaderlocal( void )
	{
	return( m_coreheaderlocal );
	}

inline void SetCoreheaderlocal( const std::string  &value )
	{
	m_coreheaderlocal = value;
	}

inline void SetCoreheaderlocal( const char *  &value )
	{
	m_coreheaderlocal = value;
	}

inline int GetDownloadflags( void )
	{
	return( m_downloadflags );
	}

inline void SetDownloadflags( const int value )
	{
	m_downloadflags = value;
	}

inline std::string & GetFiletypefilters( void )
	{
	return( m_filetypefilter );
	}

inline void SetFiletypefilters( const std::string  &value )
	{
	m_filetypefilter = value;
	}

inline void SetFiletypefilters( const char *  &value )
	{
	m_filetypefilter = value;
	}

};

// ---------------------------------------------------------------------
// File IO class for ASCII data
// ---------------------------------------------------------------------

class CExtensionSiteInfoIODataAsciiIO : virtual public CVirtualFileSystemAscii,
				virtual public CExtensionSiteInfoIOData
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

class CExtensionSiteInfoIO: virtual public CExtensionSiteInfoIODataAsciiIO

{
// ----- Constructor and Destructor ----------------------------

public:
CExtensionSiteInfoIO( void )
	{
	Init();
	}

// ----- Functions ---------------------------------------------

void Init( void )
	{
	CExtensionSiteInfoIOData::Init();
	}
};

#endif	// _CEXTENSIONSITEINFOIO_H_
