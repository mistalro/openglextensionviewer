// ---------------------------------------------------------------------------
// Copyright: (C) VFX Research 2002 - 2014. All Rights Reserved.
// ---------------------------------------------------------------------------

// --------------------------------------------------------------------------
// Class to store all the information for a single header file
// --------------------------------------------------------------------------
                                                                                
class CExtensionHeaderFileData 
{
public:
int            m_version;         // Version
int            m_selectednum; 	  // Number of selected extensions
int            m_selectedfuncnum; // Number of selected extension functions
int            m_extpos;

CExtensionEntryList m_extlist;     // List of extensions
CExtensionEntryList m_constlist;   // List of constants for all extensions
CExtensionEntryList m_funclist;    // List of functions for all constants

std::string    m_prefix;      // Prefix used by extension GL_ WGL_ GLX_
std::string    m_funcprefix;  // Prefix used by function  gl  wgl  glX
std::string    m_prototype;   // Prefix for prototypes    GLX_GLXEXT_PROTOTYPES

// ----- Constructor and destructor -----------------------------------------

CExtensionHeaderFileData( void )
        {
	Init();
	};

~CExtensionHeaderFileData( void )
        {
        };

// ----- Functions and procedures -------------------------------------------

void Init();                                                                                
void Deallocate( void )
	{
	m_extlist.Deallocate();
	m_constlist.Deallocate();
	m_funclist.Deallocate();

	m_prefix.clear();
	m_funcprefix.clear();
	m_prototype.clear();
	}

void Duplicate( const CExtensionHeaderFileData &src )
	{
	m_version = src.m_version;
	m_extlist.Duplicate( src.m_extlist );
	m_constlist.Duplicate( src.m_constlist );
	m_funclist.Duplicate( src.m_funclist );
	
	m_prefix     = src.m_prefix;
	m_funcprefix = src.m_funcprefix;
	m_prototype  = src.m_prototype;
	}

void SetVersion( int value )
        {
        m_version = value;
        };
                                                                                
int GetVersion( void )
        {
        return( m_version );
        };
                                                                                
void Sort( void )
        {
        m_extlist.Sort();
        };
        
int ClearNameFlag(const std::string &name, int flag )
        {
        return( m_extlist.ClearNameFlag( name, flag ) );
        };
                                                                                
int SetFullNameFlag( const std::string &name, int flag, int matchmode )
        {
        return( m_extlist.SetFullNameFlag( name, flag, matchmode ) );
        };
                                                                                
void AddExtensionString( const std::string &pextstring )
	{
	m_extlist.AddExtensionString( pextstring );
	};

void RemoveExtensionString( const std::string &pextstring )
	{
	m_extlist.RemoveExtensionString( pextstring );
	};

int  GetCount( void )
        {
        return( m_extlist.size() );
        };
                                                                                
void RemoveName( const std::string &name )
        {
        m_extlist.RemoveName( name );
        };
                                                                                
int FindName( const std::string &name )
        {
        return( m_extlist.FindName( name ) );
        };
                                                                                
void SelectByName( const std::string &name )
        {
        return( m_extlist.SelectByName( name ) );
        };
                                                                                
int GetIndexFlag( int pos, int flag )
        {
        return( m_extlist.GetIndexFlag( pos, flag ) );
        };
                                                                                
int GetNameFlag( const std::string &name, int flag );
                                                                                
void SetNameFlag( const std::string &name, int flag )
        {
        m_extlist.SetNameFlag( name, flag );
        };
                                                                                
void SetIndexFlag( int pos, int flag )
        {
        m_extlist.SetIndexFlag( pos, flag );
        };
                        
void SetParameters( const std::string &prefix, 
			const std::string &funcprefix, 
			const std::string &prototype );                                                        
void SelectExtensionString( const std::string &extstring, 
		CExtensionEntryList &ignorelist, 
		CExtensionEntryList &newlist, 
		int mode, int matchmode, int updatemode )
        {
        m_extlist.SelectExtensionString( extstring, 
		ignorelist, newlist, mode, matchmode, updatemode );
        };
              
void UnselectExtensionString( const std::string &pextstring, 
				int mode, int matchmode )
	{
	m_extlist.UnselectExtensionString( pextstring,
		mode, matchmode );
	};
 
void DeleteIndex( int index );
                                                                                
int DeleteName( const std::string &name );
                                                                                
void ClearAllFlags( int mode )
        {
        m_extlist.ClearAllFlags( mode );
        };
                                                                                
void SetAllFlags( int mode )
        {
        m_extlist.SetAllFlags( mode );
        };
                                                                                
void VendorListAdd( const char *name, CExtensionEntryList &extlist );
                                                                                
void CountFunctions( void );
                                                                                
int CheckValidExtension( const char *chptr );
void ReadVersion( char *curline, CExtensionEntryList &versionlist );
void TerminateFirstNewLine( char *curline );
void ReadFileVersion( char *curline);

int ReadExtensionBlockHeader( char *curline,
     const char *filename, 
        CHeaderFileProgressCallback &callback,
	std::ifstream &stream,
     int filelen, CExtensionEntryList &vendorlist, int pextlen );

void ReadFileConstants( char *curline, char *lastline, 
			char *name, int pextlen);

void ReadFileFunctions( char *curline, char *lastline, char *name, std::ifstream &stream );
void ReadFileFunctionPrototypes( char *curline, std::ifstream &stream );

int ReadHeaderFile( const std::string &filename,
        CHeaderFileProgressCallback &callback,
        CExtensionEntryList &versionlist, 
	CExtensionEntryList &vendorlist );
                                                                                
int AddStart( const std::string &exname )
        {
        return( m_extlist.AddStart( exname,
                m_funclist.size(), m_constlist.size() ) );
        };
                                                                                
void AddPrefixNameValueProto( 	std::string &pnewreturnbuf, 
				std::string &ptempbuf,
                        	std::string &pshortproto, 
				std::string &pnewlongproto )
        {
        m_funclist.AddPrefixNameValueProto(
        pnewreturnbuf, ptempbuf, pshortproto, pnewlongproto );
        };
                                                                                
void AddConstNameValue( std::string &tempbuf, 
			std::string &curword, int expos )
        {
        m_constlist.AddNameValue( tempbuf.data(), curword.data() );
        m_extlist.IncrementConstNum( expos);
        };
                                                                                
int  FindConstName( const std::string &name )
        {
        return( m_constlist.FindName( name ) );
        };
                                                                                
void IncrementConstNum( int expos )
        {
        m_extlist.IncrementConstNum( expos );
        };
                                                                                
void IncrementFuncNum( int expos )
        {
        m_extlist.IncrementFuncNum( expos );
        };
                                                                                
void SaveState( void )
        {
        m_extlist.SaveState();
        };
                                                                                
void UndoState( void )
        {
        m_extlist.UndoState();
        };
                                                                                
void RedoState( void )
        {
        m_extlist.RedoState();
        };

void SetListName( const std::string &name )
	{
	m_extlist.SetListName( name );
	};

std::string &GeListName( void )
	{	
	return( m_extlist.m_listname );
	};

void SearchString( int mode, const std::string &strsearch, 
		CHeaderFileDataSearchCallback &callback )
	{
	if ( mode & SEARCH_CONSTANTS )	// Search constants
		{
		m_constlist.SearchString(mode, strsearch, callback);   
		}

	if ( mode & SEARCH_FUNCTIONS )  // Search functions
		{
		m_funclist.SearchString(mode, strsearch, callback);
		}
	}
};
