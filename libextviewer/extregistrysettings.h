// ---------------------------------------------------------------------------
// Copyright: (C) VFX Research 2002 - 2014. All Rights Reserved.
// ---------------------------------------------------------------------------

// --------------------------------------------------------------------------
// States that the download engine can be in
// --------------------------------------------------------------------------

#define DOWNLOAD_NONE      0x0001   // Download not in progress
#define DOWNLOAD_ACTIVE    0x0002   // Download in progress
#define DOWNLOAD_INACTIVE  0x0004   // Download inactive
#define DOWNLOAD_COMPLETE  0x0008   // Download complete
#define DOWNLOAD_ERROR     0x0010   // Download failed
#define DOWNLOAD_CANCELLED 0x0020   // Download cancelled
#define DOWNLOAD_PAUSED    0x0040   // Download paused
                                                                                
// --------------------------------------------------------------------------
// Configuration data
// --------------------------------------------------------------------------

class CExtensionRegistrySettings : virtual public CExtensionRegistrySettingsIO
{
public:
                                                                                
// ----- Constructor and Destructor -----------------------------------------
                                                                                
CExtensionRegistrySettings( void ) { Init(); };
                                                                                
~CExtensionRegistrySettings( void ) { };
                                                                                
// ----- Functions and Procedures -------------------------------------------
                                                                                
void Init( void )
        {
        SetDownloadStatus( DOWNLOAD_NONE );
        };

void SetDownloadStatus( int mode )
        {
        m_downloadstatus = mode;
        }
                                                                                
int GetDownloadStatus( void )
        {
        return( m_downloadstatus );
        }
                                                                                
// ------ Create, read and save files to the OpenGL Registry -----
                                                                                
int   SaveLocalCache( const std::string &destpath, const std::string &data );
int   LoadLocalCache( std::string &name, std::string &localdir, std::string &data );
                                                                                
const char *ExtractExtensionName( const char *pbuf, 
				std::string &exname, std::string &exprefix, int &done );
                                                                                
const char *ExtractExtensionNameStrings(const char *pbuf, 
				std::string &namestrings, int &done );
                                                                                
const char *ExtractExtensionProceduresAndFunctions( const char *pbuf, 
				int winflag, int expos, int &done, 
				CExtensionHeaderFileSet &fileset );
                                                                                
const char *ExtractExtensionTokens( const char *pbuf, 
				int winflag, int expos, std::string &exprefix, 
			int &done, CExtensionHeaderFileSet &fileset );
                                                                                
const char *ExtractExtensionContributors( const char *pbuf, 
				std::string &contributors, int &done );

const char *ExtractExtensionContact(    const char *pbuf, 
				std::string &contact,      int &done );

const char *ExtractExtensionIPStatus(  const  char *pbuf, 
				std::string &pipstatus,     int &done );

const char *ExtractExtensionStatus(    const  char *pbuf, 
				std::string &status,       int &done );

const char *ExtractExtensionVersion(   const char *pbuf, 
				std::string &version,      int &done );

const char *ExtractExtensionNumber(    const  char *pbuf, 
				std::string &number,       int &done );

const char *ExtractExtensionDependencies( const char *pbuf, 
				std::string &dependencies, int &done );

const char *ExtractExtensionOverview( const char *pbuf, 
				std::string &overview,     int &done );

const char *ExtractExtensionIssues(   const char *pbuf,  
				std::string &issues,       int &done );                                                                                
void  ExtractExtensionInit( std::string &exname, int &winflag, int &expos,
				CExtensionHeaderFileSet &fileset);
                                                                                
void ReadExtensionBuffer( std::string &exbuf,
        			CRegistryFileProgressCallback &callback,
        			std::string &extname, int filepos, int filemax, 
				CExtensionHeaderFileSet &fileset );

void  CheckLocalPath( const std::string &path );

int  GetRegistryCount( std::string &path );

void ReadNewExtensions( std::string &localdir,
				CExtensionHeaderFileSet &fileset,
				CRegistryFileProgressCallback &callback );
};
