// ---------------------------------------------------------------------------
// Copyright: (C) VFX Research 2002 - 2014. All Rights Reserved.
// ---------------------------------------------------------------------------

#define SCRIPT_INTERNAL 0x01
#define SCRIPT_EXTERNAL 0x02                                                                                
// --------------------------------------------------------------------------
// Permanent data variables
// --------------------------------------------------------------------------

class CExtensionScriptSettingsData
{
public:
// ----- Internal variables -------------------------------------------------

int      m_scriptinternalsize;  // Size of internal script
string   m_scriptinternal;      // Internal script
int m_scriptinternalpos;   // Line position of internal script
int      m_scriptexternalsize;  // Size of external script
string   m_scriptexternal;      // External script
int      m_scriptexternalpos;   // Line position of external script
int      m_scriptsize;          // Size of script
CFuncElementList m_prefunclist; // List of functions for script file
CTokenList       m_tokenlist;   // List of tokens to parse script file
CScriptTokenList m_script;      // The compiled script file
};

// --------------------------------------------------------------------------
// Temporary state variables for program execution
// --------------------------------------------------------------------------

class CExtensionScriptSettingsState
{
public:
int     m_nomacros;             // Macro output flag

time_t    m_ltime;              // Used for time
int       m_extpos;             // Index of current extension position
int       m_funcpos;            // Index of current extension function
int       m_constpos;           // Index of current extension constant
unsigned int m_versionpos;      // Index of current OpenGL version
int       m_registrypos;
unsigned int m_pos;
int       m_fileheader;         // Flag indicating file header
int       m_activegl;           // GL loop counter in use
int       m_activewgl;          // WGL loop counter in use
int       m_activeglx;          // GLX loop counter in use
int       m_activefunc;         // Function loop counter in use
int       m_activeversion;      // Version loop counter in use
int       m_activeconst;        // Constant loop counter in use
int       m_activeregistry;     // Registry loop counter in use
char     *m_filename;           // Filename

ofstream   m_outputstream;      // Output stream

CExtensionEntry *m_pextentry;    // Pointer to current extension entry
CExtensionEntryList  *m_pcurfunclist; // Pointer to current function list
int        m_extmode;
int        m_replacemode;       // Replacement mode for reading headers
int        m_result;            // Result code for if statements
int        m_casemode;          // Case mode
int        m_funcdepth;         // Function call depth
int        m_funccuraddr[32];     // Function call stack
int        m_funclastaddr[32];   // Function last instruction stack

CGenerateProgressCallback *m_callback; // Callback class for progress reports
};

// --------------------------------------------------------------------------
// Extension processing configuration script data
// --------------------------------------------------------------------------
                                                                                
class CExtensionScriptSettings : virtual public CExtensionScriptSettingsIO,
				virtual public CExtensionScriptSettingsData,
				virtual public CExtensionScriptSettingsState
{
public:
// ----- Constructor and Destructor -----------------------------------------
                                                                                
CExtensionScriptSettings( void ) { Init(); };
~CExtensionScriptSettings( void ) { };

CExtensionScriptSettings & operator = ( const CExtensionScriptSettings &src)
	{
	*( (CExtensionScriptSettingsData *) this) = src;

	return *this;
	}

// ----- Script files -------------------------------------------------------
                                                                                
void Init( void );
void ScriptInitInternal(void);
void ScriptInitTokens(void);

int  ScriptReadExternal( const string &path );
void ScriptSetExternal( const string &path);

int  ScriptWrite( const string &path, int which );
void ScriptDump( const string &strfile );

const char *ScriptReadToken( const char *pbuffer, const char *pend, 
			CScriptToken &scrtoken );

void ScriptParse( const char *pstart, int plen );
void ScriptSet( const char *path );

void ScriptSetFilename( const string &str );
void ScriptParse( void );

void ScriptSetMode ( int mode ) { m_scriptmode = mode; };
void ScriptCopyInternal( void );
int  ScriptFindEndif(  int startpos );
int  ScriptFindEnd(    int startpos );
int  ScriptFindEndfor( int startpos );
int  ScriptFindElse(   int startpos );

const char *ExtractVariable( const char *pchlist, char *tempbuf, int &len );
};
