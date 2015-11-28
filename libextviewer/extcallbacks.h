// ---------------------------------------------------------------------------
// Copyright: (C) VFX Research 2002 - 2014. All Rights Reserved.
// ---------------------------------------------------------------------------

// --------------------------------------------------------------------------
// Callback result codes
//
// The user can instruct the routine by returning a CALLBACK_CANCEL code
// Otherwise CALLBACK_CONTINUE should be returned
// --------------------------------------------------------------------------

#define CALLBACK_CONTINUE 0x0000
#define CALLBACK_CANCEL   0x0001     

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
// Callback classes
//
// These classes are defined so the extension library routines can send
// real-time progress reports to higher-level GUI interfaces. Since the
// extension library cannot know which API (MFC,.net,Qt,Motif) is being
// used, these functions are defined a virtual.
//
// It is up to the application routines to handle this information.
//
// --------------------------------------------------------------------------

// --------------------------------------------------------------------------
// Progress callback for downloading extension header files
// --------------------------------------------------------------------------

class CHeaderDownloadProgressCallback
{
public:
virtual int HeaderDownloadProgressCallback( const string &name, int mode ) = 0;

CHeaderDownloadProgressCallback( void ) { };
virtual ~CHeaderDownloadProgressCallback( void ) { };
};

// --------------------------------------------------------------------------
// Progress callback for reading extension header files
// --------------------------------------------------------------------------
                                                                                
class CHeaderFileProgressCallback
{
int m_downloadstatus;

public:
virtual int HeaderFileProgressCallback(
	const string &name, const string &extname, int pos, int max) = 0;
                                                                                
CHeaderFileProgressCallback( void ) 
	{
	m_downloadstatus = DOWNLOAD_NONE;
	};

virtual ~CHeaderFileProgressCallback( void ) { };
};

// --------------------------------------------------------------------------
// Progress callback for downloading registry files
// --------------------------------------------------------------------------
                                                                                
class CRegistryDownloadCallback
{
public:
int       m_downloadstatus;     // Current status of registry download

virtual int RegistryDownloadCallback( const string &str, int mode ) = 0;
                                                                                
CRegistryDownloadCallback( void ) { };
virtual ~CRegistryDownloadCallback( void ) { };
};

// --------------------------------------------------------------------------
// Callback for reading registry files
// --------------------------------------------------------------------------                                                                                
class CRegistryFileProgressCallback
{
public:
virtual int RegistryFileProgressCallback(
	const string &name, const string &extname, int pos, int max) = 0;
                                                                                
CRegistryFileProgressCallback( void ) { };
virtual ~CRegistryFileProgressCallback( void ) { };
};
 
// --------------------------------------------------------------------------
// Callback for generating output files
// --------------------------------------------------------------------------
                                                                               
class CGenerateProgressCallback
{
public:
virtual int GenerateProgressCallback( int filetype, int pos, int max ) = 0;
                                                                                
CGenerateProgressCallback( void ) { };
virtual ~CGenerateProgressCallback( void ) { };
};
                                                                                
// --------------------------------------------------------------------------
// Callback for displaying pixel format analysis
// --------------------------------------------------------------------------

class CCheckSystemProgressCallback
{
public:
virtual int CheckSystemProgressCallback( int pos, int max ) = 0;

CCheckSystemProgressCallback( void ) { };
virtual ~CCheckSystemProgressCallback( void ) { };
};

// --------------------------------------------------------------------------
// Callback to handle header list searches
// --------------------------------------------------------------------------

class CHeaderFileDataSearchCallback
{
public:
virtual int HeaderFileDataSearchCallback(int list,
                        const string &name, const string &value ) = 0;

CHeaderFileDataSearchCallback( void ) { };
virtual ~CHeaderFileDataSearchCallback( void ) { };
};

// --------------------------------------------------------------------------
// Callback to handle registry searches
// --------------------------------------------------------------------------

class CRegistryStringSearchCallback
{
public:
virtual int RegistryStringSearchCallback( int site, int linenumber,
			const string &path, const string &line, int mode ) = 0;

virtual int RegistryStringSearchProgressCallback( int pos, int max ) = 0;

CRegistryStringSearchCallback( void ) { };
virtual ~CRegistryStringSearchCallback( void ) { };
};

