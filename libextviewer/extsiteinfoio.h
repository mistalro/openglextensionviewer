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

string	m_description;		// Description
string	m_indexdirlocal;	// OpenGL registry local directory
string	m_indexpagenet;		// OpenGL registry web page
string	m_indexpagelocal;	// OpenGL registry local copy
string	m_glheadernet;		// OpenGL registry header file
string	m_glheaderlocal;	// OpenGL header local copy
string	m_glxheadernet;		// GLX registry header file
string	m_glxheaderlocal;	// GLX header local copy
string	m_wglheadernet;		// WGL registry header file
string	m_wglheaderlocal;	// WGL header local copy
string	m_coreheadernet;	// Core ARB header file
string	m_coreheaderlocal;	// Core ARB header local copy
int	m_downloadflags;	// Download flags
string	m_filetypefilter;	// File type filters

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

inline string & GetDescription( void )
	{
	return( m_description );
	}

inline void SetDescription( const string  &value )
	{
	m_description = value;
	}

inline void SetDescription( const char *  &value )
	{
	m_description = value;
	}

inline string & GetIndexdirlocal( void )
	{
	return( m_indexdirlocal );
	}

inline void SetIndexdirlocal( const string  &value )
	{
	m_indexdirlocal = value;
	}

inline void SetIndexdirlocal( const char *  &value )
	{
	m_indexdirlocal = value;
	}

inline string & GetIndexpagenet( void )
	{
	return( m_indexpagenet );
	}

inline void SetIndexpagenet( const string  &value )
	{
	m_indexpagenet = value;
	}

inline void SetIndexpagenet( const char *  &value )
	{
	m_indexpagenet = value;
	}

inline string & GetIndexpagelocal( void )
	{
	return( m_indexpagelocal );
	}

inline void SetIndexpagelocal( const string  &value )
	{
	m_indexpagelocal = value;
	}

inline void SetIndexpagelocal( const char *  &value )
	{
	m_indexpagelocal = value;
	}

inline string & GetGlheadernet( void )
	{
	return( m_glheadernet );
	}

inline void SetGlheadernet( const string  &value )
	{
	m_glheadernet = value;
	}

inline void SetGlheadernet( const char *  &value )
	{
	m_glheadernet = value;
	}

inline string & GetGlheaderlocal( void )
	{
	return( m_glheaderlocal );
	}

inline void SetGlheaderlocal( const string  &value )
	{
	m_glheaderlocal = value;
	}

inline void SetGlheaderlocal( const char *  &value )
	{
	m_glheaderlocal = value;
	}

inline string & GetGlxheadernet( void )
	{
	return( m_glxheadernet );
	}

inline void SetGlxheadernet( const string  &value )
	{
	m_glxheadernet = value;
	}

inline void SetGlxheadernet( const char *  &value )
	{
	m_glxheadernet = value;
	}

inline string & GetGlxheaderlocal( void )
	{
	return( m_glxheaderlocal );
	}

inline void SetGlxheaderlocal( const string  &value )
	{
	m_glxheaderlocal = value;
	}

inline void SetGlxheaderlocal( const char *  &value )
	{
	m_glxheaderlocal = value;
	}

inline string & GetWglheadernet( void )
	{
	return( m_wglheadernet );
	}

inline void SetWglheadernet( const string  &value )
	{
	m_wglheadernet = value;
	}

inline void SetWglheadernet( const char *  &value )
	{
	m_wglheadernet = value;
	}

inline string & GetWglheaderlocal( void )
	{
	return( m_wglheaderlocal );
	}

inline void SetWglheaderlocal( const string  &value )
	{
	m_wglheaderlocal = value;
	}

inline void SetWglheaderlocal( const char *  &value )
	{
	m_wglheaderlocal = value;
	}

inline string & GetCoreheadernet( void )
	{
	return( m_coreheadernet );
	}

inline void SetCoreheadernet( const string  &value )
	{
	m_coreheadernet = value;
	}

inline void SetCoreheadernet( const char *  &value )
	{
	m_coreheadernet = value;
	}

inline string & GetCoreheaderlocal( void )
	{
	return( m_coreheaderlocal );
	}

inline void SetCoreheaderlocal( const string  &value )
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

inline string & GetFiletypefilters( void )
	{
	return( m_filetypefilter );
	}

inline void SetFiletypefilters( const string  &value )
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

int ReadFile( ifstream &stream );
int ReadFileInternal( ifstream &stream );

using CVirtualFileSystemAscii::WriteFile;

int WriteFile( ofstream &stream, unsigned int depth );
int WriteFile( ofstream &stream, unsigned int depth, const char *pstr );
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
