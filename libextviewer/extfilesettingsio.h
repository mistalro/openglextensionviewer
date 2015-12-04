// ---------------------------------------------------------------------------
// Copyright: (C) VFX Research 2002 - 2014. All Rights Reserved.
// ---------------------------------------------------------------------------

#ifndef _COUTPUTFILESETTINGSIO_H_
#define _COUTPUTFILESETTINGSIO_H_

// -------------------------------------------------------------------------
// Change flags (dirty flags)
// -------------------------------------------------------------------------

enum COutputFileSettingsIOChangeFlags
	{
	COUTPUTFILESETTINGSIO_CHANGEFLAG_OUTPUTHEADER = 0x0001,
	COUTPUTFILESETTINGSIO_CHANGEFLAG_OUTPUTSOURCE,
	COUTPUTFILESETTINGSIO_CHANGEFLAG_SCRIPTFILE,
	COUTPUTFILESETTINGSIO_CHANGEFLAG_CLASSNAME,
	COUTPUTFILESETTINGSIO_CHANGEFLAG_CLASSNAMEDCOLON,
	COUTPUTFILESETTINGSIO_CHANGEFLAG_CPPMODE,
	};

#define COUTPUTFILESETTINGSIO_CHANGEFLAG_NUM 6

// --------------------------------------------------------------------------- 
// Main class definition for COutputFileSettingsIOData
// --------------------------------------------------------------------------- 

class COutputFileSettingsIOData
{
// ----- Class members ------------------------------------------------------- 
public:

string	m_outputheaderfile;	// New configuration file - no name
string	m_outputsourcefile;	// Output source file
string	m_scriptfile;		// Script file
string	m_classname;		// Name of new class
string	m_classnamedcolon;	// Name of new class with double colon
int	m_cppmode;		// Output C++ or C files
int     m_useglxgetprocaddressARB; // Function get get ARB

// ----- Constructor and destructor ------------------------------------------ 

COutputFileSettingsIOData( void )
	{
	COutputFileSettingsIOData::Init();
	}

~COutputFileSettingsIOData( void )
	{
	COutputFileSettingsIOData::Deallocate();
	}

// ----- Functions and Procedures -------------------------------------------- 

void Init( void )
	{
	m_outputheaderfile = "";
	m_outputsourcefile = "";
	m_scriptfile = "";
	m_classname = "";
	m_classnamedcolon = "";
	m_cppmode = 0;
	m_useglxgetprocaddressARB = 0;
	}

void Deallocate()
	{
	m_outputheaderfile.clear();
	m_outputsourcefile.clear();
	m_scriptfile.clear();
	m_classname.clear();
	m_classnamedcolon.clear();

	Init();
	}
// ----- Manage getting and setting values -----------------------------------

inline string & GetOutputheader( void )
	{
	return( m_outputheaderfile );
	}

inline void SetOutputheader( const string  &value )
	{
	m_outputheaderfile = value;
	}

inline void SetOutputheader( const char *  &value )
	{
	m_outputheaderfile = value;
	}

inline string & GetOutputsource( void )
	{
	return( m_outputsourcefile );
	}

inline void SetOutputsource( const string  &value )
	{
	m_outputsourcefile = value;
	}

inline void SetOutputsource( const char *  &value )
	{
	m_outputsourcefile = value;
	}

inline string & GetScriptfile( void )
	{
	return( m_scriptfile );
	}

inline void SetScriptfile( const string  &value )
	{
	m_scriptfile = value;
	}

inline void SetScriptfile( const char *  &value )
	{
	m_scriptfile = value;
	}

inline string & GetClassname( void )
	{
	return( m_classname );
	}

inline void SetClassname( const string  &value )
	{
	m_classname = value;
	}

inline void SetClassname( const char *  &value )
	{
	m_classname = value;
	}

inline string & GetClassnamedcolon( void )
	{
	return( m_classnamedcolon );
	}

inline void SetClassnamedcolon( const string  &value )
	{
	m_classnamedcolon = value;
	}

inline void SetClassnamedcolon( const char *  &value )
	{
	m_classnamedcolon = value;
	}

inline int GetCppmode( void )
	{
	return( m_cppmode );
	}

inline void SetCppmode( const int value )
	{
	m_cppmode = value;
	}

inline void SetUseglxgetprocaddressarb( const int value )
	{
	m_useglxgetprocaddressARB = value;
	}

inline int GetUseglxgetprocaddressarb( void )
	{
	return( m_useglxgetprocaddressARB );
	}
};

// ---------------------------------------------------------------------
// File IO class for ASCII data
// ---------------------------------------------------------------------

class COutputFileSettingsIODataAsciiIO : virtual public CVirtualFileSystemAscii,
				virtual public COutputFileSettingsIOData
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

class COutputFileSettingsIO: virtual public COutputFileSettingsIODataAsciiIO

{
// ----- Constructor and Destructor ----------------------------

public:
COutputFileSettingsIO( void )
	{
	Init();
	}

// ----- Functions ---------------------------------------------

void Init( void )
	{
	COutputFileSettingsIOData::Init();
	}
};

#endif	// _COUTPUTFILESETTINGSIO_H_
