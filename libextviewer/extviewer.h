// ---------------------------------------------------------------------------
// Copyright: (C) VFX Research 2002 - 2014. All Rights Reserved.
// ---------------------------------------------------------------------------

#define UNUSED(X)  do {(void) (X); } while (0)

#define DOWNLOAD_ALL      0x001
#define DOWNLOAD_SELECTED 0x002
#define DOWNLOAD_NEW      0x003
#define DOWNLOAD_TOPLEVEL 0x004

#define READ_ALL      0x001
#define READ_SELECTED 0x002
#define READ_NEW      0x003

#define MODE_MATCHCASE        0x0001
#define MODE_FIRSTMATCH       0x0002
#define MODE_DISPLAYFULLPATHS 0x0004
#define MODE_ONEMATCHPERFILE  0x0008

#define READ_EXTENSION_SUCCESS 1
#define READ_EXTENSION_NOREGISTRY -1
#define READ_EXTENSION_NOENTRY -2
#define READ_EXTENSION_NOFILE -3

// --------------------------------------------------------------------------
// Extension Viewer class
// --------------------------------------------------------------------------

class CExtensionViewer : virtual public CExtensionViewerIO
{
public:
// --------------------------------------------------------------------------
// Values used at generation time
// --------------------------------------------------------------------------

// ----- Constructor and destructor -----------------------------------------

CExtensionViewer( void ) { Init(); };
~CExtensionViewer( void );

// ----- Function prototypes ------------------------------------------------

void Init(void);

// ----- Configuration variables -----------------------------

void ConfigurationFileNew( void );  
int  ConfigurationFileLoad( void );       
int  ConfigurationFileLoadAndMerge();
int  ConfigurationFileSave( void );

int  ConfigurationFileLoad( const std::string &path ) 
	{
	return CExtensionViewerIO::ReadFile( path );
	}
  
int  ConfigurationFileLoadAndMerge( const std::string &path )
	{
	return CExtensionViewerIO::ReadFile( path );
	}

int  ConfigurationFileSaveAs( const std::string &path )
	{
	return CExtensionViewerIO::WriteFile( path );
	}

// ----- Get registry site information --------------------------------------

CExtensionSiteInfo *GetSiteInfo( int site )
	{
	return( m_sitelist.GetSiteInfo( site ) );
	}

int GetSiteCount( void )
	{
	return( m_sitelist.GetCount() );
	}

// ----- Get Extension list information -------------------------------------

CExtensionEntryList *GetExtensionEntryList( int listid )
	{
	return( m_headerfileset.GetExtensionList( listid ) );
	}

int GetExtensionEntryListNum( int listid )
	{
	return( m_headerfileset.GetExtensionListNum( listid ) );
	}

CExtensionEntry *GetExtensionEntry( int listid, int index )
	{
	return( m_headerfileset.GetExtensionEntry( listid, index ) );
	}

CExtensionEntryList *GetConstantList( int listid )
	{
	return( m_headerfileset.GetConstantList( listid ) );
	}

CExtensionEntryList *GetFunctionList( int listid )
	{
	return( m_headerfileset.GetFunctionList( listid ) );
	}

// ----- Download headers and the registry -------------------------

int  DownloadRegistryHeaders( int site, 
			CHeaderDownloadProgressCallback &callback );

int DownloadAllRegistryHeaders( CHeaderDownloadProgressCallback &callback );

int DownloadRegistryIndexPage( int site, std::string &regbuf, 
			CRegistryDownloadCallback &callback, int mode );

void DownloadRegistryWebpage( int site, 
			CRegistryDownloadCallback &callback, int mode );

void DownloadRegistryExtensions( int site,
                	const std::string &regbuf,
                	CRegistryDownloadCallback &callback, int mode);

void DownloadRegistryExtension( const std::string &fullpath,
                                const std::string &destpath );

void DownloadAllRegistryWebpages( 
			CRegistryDownloadCallback &callback, int mode );

void GenerateTransferPaths( const std::string &srcpath,
                            const std::string &destpath,
                            const std::string &extpath );

int CheckExtensionDownload( const std::string &extname, int mode );

int CreateLocalRegistryDir(int site,
                CRegistryDownloadCallback &callback, int mode );

// ----- Read the data files ------------------------------------------------

int  ReadHeaderFiles( int site, CHeaderFileProgressCallback &callback, int mode );

int  ReadAllHeaderFiles( CHeaderFileProgressCallback &callback );

void ReadExtensionFile( std::string &, CRegistryFileProgressCallback &callback,
		int filepos, int filemax  );

int  ReadRegistry( int site, 
		CRegistryFileProgressCallback &callback, int mode );

int ReadAllRegistrySites( CRegistryFileProgressCallback &callback, int mode )
	{
	int site, sitemax;
	
	sitemax = GetSiteCount();

	for ( site = 0; site < sitemax; site++ )
		ReadRegistry( site, callback, mode );

	return(1);
	}		

// ----- Script file output ----------------------------------------------

void DebugLevel0( CScriptToken *pstoken, int curaddr, int lastaddr );
int  ProcessScript( int startaddr, int finishaddr );
int  ProcessScriptToken( int &curaddr, int &lastaddr, CScriptToken **pstoken );

int  WriteGeneratedFiles( CGenerateProgressCallback &callback );          

// ----- Autolaoding and saving of configuration files

int GetAutoSaveConfigFlags( void )
	{
	return( m_configfilesettings.GetAutoSaveConfigFlags() );
	};

int GetAutoLoadConfigFlags( void )
	{
	return( m_configfilesettings.GetAutoLoadConfigFlags() );
	};

int GetAutoReadHeaderFlags( void )
	{
	return( m_configfilesettings.GetAutoReadHeaderFlags() );
	};

// ----- Search the std::string --------------------------------------------------

int SearchString( int mode, const std::string &strsearch,
                  CHeaderFileDataSearchCallback &callback )
	{
	return( m_headerfileset.SearchAllLists( mode, strsearch, callback ) );
	};

int SearchExtensionSpecs( int mode, const std::string &strdata,
		CRegistryStringSearchCallback &callback );

int  SearchRegistry( int site, const std::string &strdata,
                CRegistryStringSearchCallback &callback, int mode );

int RegistryFileStringSearch( const std::string &path,
                                int site, const std::string &strdata,
                CRegistryStringSearchCallback &callback, int mode );

int ReadRegistryWebpage(std::string &strdata, const std::string &targetname );
};
