// ---------------------------------------------------------------------------
// Copyright: (C) VFX Research 2002 - 2014. All Rights Reserved.
// ---------------------------------------------------------------------------

#ifndef _CEXTENSIONENTRYIO_H_
#define _CEXTENSIONENTRYIO_H_

// -------------------------------------------------------------------------
// Change flags (dirty flags)
// -------------------------------------------------------------------------

enum CExtensionEntryIOChangeFlags
	{
	CEXTENSIONENTRYIO_CHANGEFLAG_PREFIX = 0x0001,
	CEXTENSIONENTRYIO_CHANGEFLAG_NAME,
	CEXTENSIONENTRYIO_CHANGEFLAG_VALUE,
	CEXTENSIONENTRYIO_CHANGEFLAG_HEADER,
	CEXTENSIONENTRYIO_CHANGEFLAG_PFNPROC,
	CEXTENSIONENTRYIO_CHANGEFLAG_FUNCSTART,
	CEXTENSIONENTRYIO_CHANGEFLAG_FUNCNUM,
	CEXTENSIONENTRYIO_CHANGEFLAG_CONSTSTART,
	CEXTENSIONENTRYIO_CHANGEFLAG_CONSTNUM,
	CEXTENSIONENTRYIO_CHANGEFLAG_FLAGS,
	};

#define CEXTENSIONENTRYIO_CHANGEFLAG_NUM 10

// --------------------------------------------------------------------------- 
// Main class definition for CExtensionEntryData
// --------------------------------------------------------------------------- 

class CExtensionEntryData
{
// ----- Class members ------------------------------------------------------- 
public:

std::string	m_prefix;		// Result of extension/function eg. void
std::string	m_name;		// Name of extension/function
std::string	m_value;		// For constants/function prototypes
std::string	m_header;		// For header prototype
std::string	m_pfnproc;		// Prototype name of function eg. PFN
int	m_funcstart;		// Offset to first function in list
int	m_funcnum;		// Number of functions in this extension
int	m_conststart;		// Offset to first constant in list
int	m_constnum;		// Offset to first constant in list
int	m_flags;		// Flags used for selection

// ----- Constructor and destructor ------------------------------------------ 

CExtensionEntryData( void )
	{
	CExtensionEntryData::Init();
	}

~CExtensionEntryData( void )
	{
	CExtensionEntryData::Deallocate();
	}

// ----- Functions and Procedures -------------------------------------------- 

void Init( void )
	{
	m_prefix = "";
	m_name = "";
	m_value = "";
	m_header = "";
	m_pfnproc = "";
	m_funcstart = 0;
	m_funcnum = 0;
	m_conststart = 0;
	m_constnum = 0;
	m_flags = 0;
	}

void Deallocate()
	{
	m_name.clear();

	Init();
	}
// ----- Manage getting and setting values -----------------------------------

inline std::string & GetPrefix( void )
	{
	return( m_prefix );
	}

inline void SetPrefix( const std::string  &value )
	{
	m_prefix = value;
	}

inline void SetPrefix( const char *  &value )
	{
	m_prefix = value;
	}

inline std::string & GetName( void )
	{
	return( m_name );
	}

inline void SetName( const std::string  &value )
	{
	m_name = value;
	}

inline void SetName( const char *  &value )
	{
	m_name = value;
	}

inline std::string & GetValue( void )
	{
	return( m_value );
	}

inline void SetValue( const std::string  &value )
	{
	m_value = value;
	}

inline void SetValue( const char *  &value )
	{
	m_value = value;
	}

inline std::string & GetHeader( void )
	{
	return( m_header );
	}

inline void SetHeader( const std::string  &value )
	{
	m_header = value;
	}

inline void SetHeader( const char *  &value )
	{
	m_header = value;
	}

inline std::string & GetPfnproc( void )
	{
	return( m_pfnproc );
	}

inline void SetPfnproc( const std::string  &value )
	{
	m_pfnproc = value;
	}

inline void SetPfnproc( const char *  &value )
	{
	m_pfnproc = value;
	}

inline int GetFuncstart( void )
	{
	return( m_funcstart );
	}

inline void SetFuncstart( const int value )
	{
	m_funcstart = value;
	}

inline int GetFuncnum( void )
	{
	return( m_funcnum );
	}

inline void SetFuncnum( const int value )
	{
	m_funcnum = value;
	}

inline int GetConststart( void )
	{
	return( m_conststart );
	}

inline void SetConststart( const int value )
	{
	m_conststart = value;
	}

inline int GetConstnum( void )
	{
	return( m_constnum );
	}

inline void SetConstnum( const int value )
	{
	m_constnum = value;
	}

inline int GetFlags( void )
	{
	return( m_flags );
	}

inline void SetFlags( const int value )
	{
	m_flags = value;
	}

};

// ---------------------------------------------------------------------
// File IO class for ASCII data
// ---------------------------------------------------------------------

class CExtensionEntryDataAsciiIO : virtual public CVirtualFileSystemAscii,
				virtual public CExtensionEntryData
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

class CExtensionEntryIO: virtual public CExtensionEntryDataAsciiIO

{
// ----- Constructor and Destructor ----------------------------

public:
CExtensionEntryIO( void )
	{
	Init();
	}

// ----- Functions ---------------------------------------------

void Init( void )
	{
	CExtensionEntryData::Init();
	}
};

#endif	// _CEXTENSIONENTRYIO_H_
