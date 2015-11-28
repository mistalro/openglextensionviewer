// ---------------------------------------------------------------------------
// Copyright: (C) VFX Research 2002 - 2014. All Rights Reserved.
// ---------------------------------------------------------------------------

#ifndef _CEXTENSIONSCRIPTSETTINGSIO_H_
#define _CEXTENSIONSCRIPTSETTINGSIO_H_

// -------------------------------------------------------------------------
// Change flags (dirty flags)
// -------------------------------------------------------------------------

enum CExtensionScriptSettingsIOChangeFlags
	{
	CEXTENSIONSCRIPTSETTINGSIO_CHANGEFLAG_SCRIPTMODE = 0x0001,
	};

#define CEXTENSIONSCRIPTSETTINGSIO_CHANGEFLAG_NUM 1

// --------------------------------------------------------------------------- 
// Main class definition for CExtensionScriptSettingsIOData
// --------------------------------------------------------------------------- 

class CExtensionScriptSettingsIOData
{
// ----- Class members ------------------------------------------------------- 
public:

int	m_scriptmode;		// Indicator flag for using external scripts

// ----- Constructor and destructor ------------------------------------------ 

CExtensionScriptSettingsIOData( void )
	{
	CExtensionScriptSettingsIOData::Init();
	}

~CExtensionScriptSettingsIOData( void )
	{
	CExtensionScriptSettingsIOData::Deallocate();
	}

// ----- Functions and Procedures -------------------------------------------- 

void Init( void )
	{
	m_scriptmode = 0;
	}

void Deallocate()
	{

	Init();
	}
// ----- Manage getting and setting values -----------------------------------

inline int GetScriptmode( void )
	{
	return( m_scriptmode );
	}

inline void SetScriptmode( const int value )
	{
	m_scriptmode = value;
	}

};

// ---------------------------------------------------------------------
// File IO class for ASCII data
// ---------------------------------------------------------------------

class CExtensionScriptSettingsIODataAsciiIO : virtual public CVirtualFileSystemAscii,
				virtual public CExtensionScriptSettingsIOData
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

class CExtensionScriptSettingsIO: virtual public CExtensionScriptSettingsIODataAsciiIO

{
// ----- Constructor and Destructor ----------------------------

public:
CExtensionScriptSettingsIO( void )
	{
	Init();
	}

// ----- Functions ---------------------------------------------

void Init( void )
	{
	CExtensionScriptSettingsIOData::Init();
	}
};

#endif	// _CEXTENSIONSCRIPTSETTINGSIO_H_
