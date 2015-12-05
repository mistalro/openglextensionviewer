// ---------------------------------------------------------------------------
// Copyright: (C) VFX Research 2002 - 2014. All Rights Reserved.
// ---------------------------------------------------------------------------

// --------------------------------------------------------------------------
// Define the paths needed by each site info
// --------------------------------------------------------------------------
                                                                                
#define INFO_DESCRIPTION    0x0000      // Description
#define INFO_INDEXPAGENET   0x0001      // Index page on the Internet
#define INFO_INDEXDIRLOCAL  0x0002      // Local directory
#define INFO_GLHEADERNET    0x0003      // GL Header on the network
#define INFO_GLHEADERLOCAL  0x0004      // GL Header local copy
#define INFO_GLXHEADERNET   0x0005      // GLX Header on the network
#define INFO_GLXHEADERLOCAL 0x0006      // GLX Header local copy
#define INFO_WGLHEADERNET   0x0007      // WGL Header on the network
#define INFO_WGLHEADERLOCAL 0x0008      // WGL Header local copy
#define INFO_INDEXPAGELOCAL 0x0009      // Index page local
                                                
#define FLAG_DOWNLOADHEADERFILES 0x0001  // Download headers from site
#define FLAG_DOWNLOADREGISTRY   0x0002  // Download registry from site
#define FLAG_READHEADERFILES    0x0004  // Read header files  
#define FLAG_READEXTENSIONSPEC  0x0008  // Read extension specification

// --------------------------------------------------------------------------
// Definition of web page entry
// --------------------------------------------------------------------------
                                                                                
class CExtensionSiteInfo : virtual public CExtensionSiteInfoIO
{
public:

// ----- Constructor and destructor -----------------------------------------
                                                                                
CExtensionSiteInfo( void )
        {
        Init();
        };
                                                                                
void Init( void )
        {
	m_downloadflags = 0;
        };
                                                                                
~CExtensionSiteInfo()
        {
        };

// ----- Functions and Procedures -------------------------------------------

void Deallocate( void )
	{

	};

void Display( void )
	{

	};

void Duplicate( CExtensionSiteInfo &siteinfo )
	{
	*this = siteinfo;
	};                                                                                

void SetFlags( int mode )
	{
	m_downloadflags |= mode;
	}

void ClearFlags( int mode )
	{
	m_downloadflags &= ~mode;
	}

int GetFlags( int mode )
	{
	return( (m_downloadflags & mode) == mode ); 
	}

void SetInfo( int itemid, const char *path );

void DumpData( void );

int  FindExtensionLocalPath(    std::string &pextpath, 
				std::string &pextname );
                                                                                
int  FindRegistryExtensionPath( std::string &pregfile,
                                std::string &pextname, 
				std::string &pextpath );
                                                                                
int  FindRegistryExtensionPathIndex(
				const std::string &regpath,
                                std::string &pextname, 
				std::string &pextpath, int index );

int DownloadRegistryHeaders( CHeaderDownloadProgressCallback &callback );

int CreateLocalRegistryDir( CRegistryDownloadCallback &callback, int mode );

int ReadRegistryWebpage(std::string &strdata, const std::string &targetname);

void GenerateWebPath( std::string &srcpath,
			std::string &destpath,
                        const std::string &extpath);

void GenerateTransferPaths( std::string &srcpath,
                            std::string &destpath,
                            const std::string &extpath );

int CheckFileExtensionSave( const std::string &extpath );

int WebsiteMatch( CExtensionSiteInfo &siteinfo );

int SortCompare( CExtensionSiteInfo &siteinfo )
	{
	return (m_downloadflags<siteinfo.m_downloadflags);
	};

int operator < (const CExtensionSiteInfo &siteinfo )
	{
	return (m_downloadflags<siteinfo.m_downloadflags);
	}

int operator > (const CExtensionSiteInfo &siteinfo )
	{
	return (m_downloadflags>siteinfo.m_downloadflags);
	}

inline void GenerateDestinationPath( std::string &path )
	{
	path = GetIndexdirlocal().data();
	path += "/";
	path += GetIndexpagelocal().data();
	}
};
