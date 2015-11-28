// ---------------------------------------------------------------------------
// Copyright: (C) VFX Research 2002 - 2014. All Rights Reserved.
// ---------------------------------------------------------------------------

// --------------------------------------------------------------------------
// Various constants
// --------------------------------------------------------------------------
                                                                                
#define MODE_AUTOREADHEADERS  0x0001  // Automatically read headers
#define MODE_AUTOREADREGISTRY 0x0002  // Automatically read registry

// For m_autoloadconfigflags                                                                                
#define MODE_AUTOLOADCONFIG   0x0001  // Automatic load of configuration
#define MODE_AUTOLOADPROMPT   0x0002  // Automatic load prompt
#define MODE_AUTOLOADNOACTION 0x0004  // Automatic load no action

// For m_autosaveconfigflags

#define MODE_AUTOSAVECONFIG   0x0001  // Automatic save of configuration
#define MODE_AUTOSAVEPROMPT   0x0002  // Automatic save prompt
#define MODE_AUTOSAVENOACTION 0x0004  // Automatic save no action

// --------------------------------------------------------------------------
// Configuration data
// --------------------------------------------------------------------------
                                                                                
class CConfigurationFileSettings : virtual public CConfigurationFileSettingsIO
{
public:
CConfigurationFileSettings( void ) 
	{ 
	Init(); 
	};

~CConfigurationFileSettings( void ) 	
	{ 
	};
                                                                                
void Init( void );
                                                                                
void Deallocate( void )
	{
	m_configfile.clear();
	}

// ---- Functions and Procedures --------------------------------------------
                                                                                
void Duplicate( CConfigurationFileSettings &config )
        {
        m_configfile = config.m_configfile;
        m_autoreadheaderflags = config.m_autoreadheaderflags;
	m_newconfigflag = config.m_newconfigflag;
	m_autoloadconfigflags = config.m_autoloadconfigflags;
	m_autosaveconfigflags = config.m_autosaveconfigflags;
        }
                                                                                
void SetConfigPath( char *path )
        {
        m_configfile = path;
        m_newconfigflag = false;
        };
                                                                                
// ----- New Configuration flag ----------------------------------------------
                                                                                
int  GetNewConfigFlag( void )   { return( m_newconfigflag ); };
void SetNewConfigFlag( void )   { m_newconfigflag = true; };
void ClearNewConfigFlag( void ) { m_newconfigflag = false; };
                                                                                
// ----- Auto-read flags -----------------------------------------------------
                                                                                
int  GetAutoReadHeaderFlags( void )        { return m_autoreadheaderflags; };
void SetAutoReadHeaderFlags( int mode )    { m_autoreadheaderflags = mode; };
void ToggleAutoReadHeaderFlags( int bits ) { m_autoreadheaderflags ^= bits; };

// ----- Auto-save flags -----------------------------------------------------

int  GetAutoSaveConfigFlags( void )   { return m_autosaveconfigflags; };
void SetAutoSaveConfigFlags( int mode ) { m_autosaveconfigflags = mode; };
void ToggleAutoSaveConfigFlags( int bits ) { m_autosaveconfigflags ^= bits; };

// ----- Auto-load flags -----------------------------------------------------

int  GetAutoLoadConfigFlags( void )   { return m_autoloadconfigflags; };
void SetAutoLoadConfigFlags( int mode ) { m_autoloadconfigflags = mode; };
void ToggleAutoLoadConfigFlags( int bits ) { m_autoloadconfigflags ^= bits; };

};
