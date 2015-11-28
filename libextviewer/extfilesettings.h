// ---------------------------------------------------------------------------
// Copyright: (C) VFX Research 2002 - 2014. All Rights Reserved.
// ---------------------------------------------------------------------------

// --------------------------------------------------------------------------
// Various constants
// --------------------------------------------------------------------------
                                                                                
#define MODE_MERGE      0x0001      // Merge mode for reading header files
#define MODE_REPLACE    0x0002      // Replace mode for reading header files
                                                                                
#define MODE_CASENORMAL 0x0000      // Normal case mode
#define MODE_CASEUPPER  0x0001      // Upper case
#define MODE_CASELOWER  0x0002      // Lower case
                                                                                
#define CALLBACK_DIRECTORY 0x0001   // Directory
#define CALLBACK_FILE      0x0002   // File
#define CALLBACK_VERBOSE   0x0004   // Verbose
#define CALLBACK_QUITONERROR 0x0008 // Quit on Error                                                              
// --------------------------------------------------------------------------
// Configuration data
// --------------------------------------------------------------------------

class COutputFileSettings : virtual public COutputFileSettingsIO
{
public:
// ----- Constructor and Destructor -----------------------------------------
                                                                                
COutputFileSettings( void ) { Init(); };
                                                                                
~COutputFileSettings( void ) 
	{ 
	};
                                                                                
void Init( void );
                                                                                
// ----- Configuration files ------------------------------------------------

void Duplicate( COutputFileSettings &config )
	{
	m_cppmode          = config.m_cppmode;
	m_outputheaderfile = config.m_outputheaderfile;
	m_outputsourcefile = config.m_outputsourcefile;
	m_scriptfile	   = config.m_scriptfile;
	m_classname  	   = config.m_classname;
	m_classnamedcolon  = config.m_classnamedcolon;
	};
                                                                                
void SetFileSettings( COutputFileSettings &config );
void GetFileSettings( COutputFileSettings &config );
};
