// ---------------------------------------------------------------------------
// Copyright: (C) VFX Research 2002 - 2014. All Rights Reserved.
// ---------------------------------------------------------------------------

using namespace std;

#include "extensionlib.h"
#include <string.h>
                                                                                
// ==========================================================================
// INITIALISATION
// ==========================================================================

// --------------------------------------------------------------------------
// Default initialiser
//
// Inputs: None
//
// Outputs: None
//
// Results: None
//
// Effects: The data structure is initialised
// --------------------------------------------------------------------------

void CExtensionViewer::Init( void ) 
{
m_registrysettings.Init();
m_headerfileset.Init();
m_sitelist.WebsiteInit();
m_scriptsettings.Init();
m_outputfilesettings.Init();
m_configfilesettings.Init();
}

// --------------------------------------------------------------------------
// Default deconstructor
//
// Inputs: None
//
// Outputs: None
//
// Results: None
//
// Effects: The WSA sockets are shutdown
// --------------------------------------------------------------------------

CExtensionViewer::~CExtensionViewer( void )
{
// Nothing to do here
}

// --------------------------------------------------------------------------
// New configuration file
//
// Inputs:   None
//
// Outputs:  None
//
// Results:  None
//
// Effects:  All settings are reset and the flag is set
// --------------------------------------------------------------------------
                                                                                
void CExtensionViewer::ConfigurationFileNew( void )
{
Init();
m_configfilesettings.SetNewConfigFlag();
}

// --------------------------------------------------------------------------
// Load default configuration file
//
// Inputs:  None
//
// Outputs: None
//
// Results: None
//
// Effects: The selected configuration is loaded
// --------------------------------------------------------------------------

int CExtensionViewer::ConfigurationFileLoad( void )
{
#ifdef DEBUG
cout << "Loading |" << m_configfilesettings.m_configfile << "|" << endl;
#endif

return ConfigurationFileLoad( m_configfilesettings.m_configfile );
}
                                                                                
// --------------------------------------------------------------------------
// Load default configuration file
//
// Inputs:  None
//
// Outputs: None
//
// Results: None
//
// Effects: The selected configuration is loaded
// --------------------------------------------------------------------------

int CExtensionViewer::ConfigurationFileLoadAndMerge( void )
{
#ifdef DEBUG
cout << "Saving |" << m_configfilesettings.m_configfile << "|" << endl;
#endif

return ConfigurationFileLoadAndMerge( m_configfilesettings.m_configfile );
}

// --------------------------------------------------------------------------
// Save Configuration file
//
// Inputs: None
//
// Outputs: None
//
// Results: Non-zero on success, zero on failure
//
// Effects: The configuration file is written
// --------------------------------------------------------------------------

int CExtensionViewer::ConfigurationFileSave( void )
{
return ConfigurationFileSaveAs( m_configfilesettings.m_configfile );
}

// --------------------------------------------------------------------------
// Extract the hostname and file path from a HTTP link
//
// Inputs: pstr      - Pointer to the HTTP string
//         phostname - Pointer to the host name
//         pfile     - Pointer to the file name
//
// Outputs: phostname - Hostname
//          pfile     - File path
//
// Results: None
//
// Effects: None
//
// Notes:   The path is like: http://www.nvidia.com/developers/index.html
//
//          In this case, the hostname is: http://www.nvidia.com and the
//          file name is: developers/index.html
// --------------------------------------------------------------------------

void ExtractHostName( const string &psrc, string &hostname, string &hostfile )
{
const char *pchcur;

pchcur = psrc.data();

// ----- Extract the hostname -----

hostname.clear();

while ( (*pchcur) && (*pchcur != '/') )		// The http:
	{
	hostname += *pchcur++;
	}

hostname += *pchcur++;				// The /

while ( (*pchcur) && (*pchcur == '/') )		// The /
	{
	hostname += *pchcur++;
	}

while ( (*pchcur) && (*pchcur != '/') )		// The www.website.com
	{
	hostname += *pchcur++;
	}

hostfile.clear();

while ( *pchcur )				// The /webpagepath/index.html
	{
	hostfile += *pchcur++;		
	}
}

// -------------------------------------------------------------------------
// Download the OpenGL extension header files
//
// Inputs: None
//
// Outputs: None
//
// Results: None
//
// Effects: The OpenGL headers are downloaded from the specified web pages
//          files
// -------------------------------------------------------------------------

int CExtensionViewer::DownloadRegistryHeaders( int site,
                                CHeaderDownloadProgressCallback &callback )
{
m_registrysettings.SetDownloadStatus( DOWNLOAD_ACTIVE );

CExtensionSiteInfo *psiteinfo = GetSiteInfo(site);

int result = psiteinfo->DownloadRegistryHeaders( callback );

m_registrysettings.SetDownloadStatus( DOWNLOAD_COMPLETE );

return result;
}

// --------------------------------------------------------------------------
// Download all registry headers
//
// Inputs: callback - Callback for progress messages
//
// Outputs: None
//
// Results: None
// 
// Effects: None
// --------------------------------------------------------------------------

int CExtensionViewer::DownloadAllRegistryHeaders(
                                CHeaderDownloadProgressCallback &callback )
{
int result = FLAG_WGL | FLAG_GL | FLAG_GLX;

m_registrysettings.SetDownloadStatus( DOWNLOAD_ACTIVE );

for ( int site = 0; site < GetSiteCount(); site++ )
        {
	CExtensionSiteInfo *psiteinfo = GetSiteInfo(site);

        result &= psiteinfo->DownloadRegistryHeaders( callback );
        }

m_registrysettings.SetDownloadStatus( DOWNLOAD_COMPLETE );

return result;
}

// --------------------------------------------------------------------------
// Download all registry webpages
//
// Inputs: callback - Callback function
//         mode     - Which download mode to use
//
// Outputs: None
//
// Results: None
//
// Effects: The selected webpages are downloaded
// --------------------------------------------------------------------------

void CExtensionViewer::DownloadAllRegistryWebpages(
                CRegistryDownloadCallback &callback, int mode )
{
// Set active flag
m_registrysettings.SetDownloadStatus( DOWNLOAD_ACTIVE );

for ( int site = 0; site < GetSiteCount(); site++ )
        {
        CExtensionSiteInfo *psiteinfo = GetSiteInfo( site );

        if  ( psiteinfo->GetFlags( FLAG_DOWNLOADREGISTRY) )
                {
                DownloadRegistryWebpage( site, callback, mode );
                }
        }

m_registrysettings.SetDownloadStatus( DOWNLOAD_COMPLETE );
}

// --------------------------------------------------------------------------
// Read registry file
// --------------------------------------------------------------------------

int CExtensionViewer::ReadRegistryWebpage(string &strdata,
                                        const string &targetname )
{
int done = 0, success = 0;

for (int site = 0; site < GetSiteCount() && !done; site++ )
        {
	CExtensionSiteInfo *psiteinfo = GetSiteInfo( site );

        success = psiteinfo->ReadRegistryWebpage(strdata, targetname);
        }

return success;
}

// --------------------------------------------------------------------------
// Read the header files from all extension sites
// -------------------------------------------------------------------------- 

int CExtensionViewer::ReadAllHeaderFiles(
                        CHeaderFileProgressCallback &callback )
{
int mode = MODE_REPLACE;

for (int site = 0; site < GetSiteCount(); site++ )
        {
        CExtensionSiteInfo *psiteinfo = GetSiteInfo( site );

        if (psiteinfo->GetFlags( FLAG_READHEADERFILES ) )
                {
                m_headerfileset.ReadHeaderFiles(
                        callback,
                        psiteinfo->GetGlheaderlocal(),
                        psiteinfo->GetWglheaderlocal(),
                        psiteinfo->GetGlxheaderlocal(), 
			psiteinfo->GetCoreheaderlocal(), mode );

                mode = MODE_MERGE;
                }
        }

return FLAG_ALL;
}

// --------------------------------------------------------------------------
// Create local registry directory
//
// Parameters: site     - index into site list
//	       callback - log dialog callback function
//             mode     - which mode
//
// Results: -1 no directory and directory could not be created
//	     0 no directory and directory was created
//           1 directory already exists
// --------------------------------------------------------------------------

int CExtensionViewer::CreateLocalRegistryDir(int site,
		CRegistryDownloadCallback &callback, int mode )
{
CExtensionSiteInfo *psiteinfo;
int result;

// Get pointer to site information using index
psiteinfo = GetSiteInfo( site );

// Set active flag
m_registrysettings.SetDownloadStatus( DOWNLOAD_ACTIVE );

// Attempt to create the local directory
result = psiteinfo->CreateLocalRegistryDir( callback, mode );

if ( result == -1 )
	{
	m_registrysettings.SetDownloadStatus( DOWNLOAD_ERROR );
	}
else
	{
	m_registrysettings.SetDownloadStatus( DOWNLOAD_COMPLETE );
	}

return result;
}

// --------------------------------------------------------------------------
// Download the registry index page
// --------------------------------------------------------------------------

static string info_downloadingregistry( "Downloading registry..." );

int CExtensionViewer::DownloadRegistryIndexPage( int site, 		
		string &regbuf,
		CRegistryDownloadCallback &callback, int mode )
{
string extname, extpath;
string hostpath, hostfile, logbuf, extbuf, strmsg, destpath;

m_registrysettings.SetDownloadStatus( DOWNLOAD_ACTIVE );

// Get pointer to site information using index
CExtensionSiteInfo *psiteinfo = GetSiteInfo( site );

if ( !psiteinfo )
	{
	return false;
	}

// Convert index page network into host path and file
ExtractHostName( psiteinfo->GetIndexpagenet(), hostpath, hostfile );

// Send log message
callback.RegistryDownloadCallback( info_downloadingregistry, 0 );

// Check if local directory exists, and crete it if it doesn't exist
int res = CreateLocalRegistryDir(site, callback, mode );

if (res<0 )
	{
	return false;
	}

// At this point the directory now exists, so read the registry file
// and save it to permanent storage. Keep the user up to date as the
// process is performed.

logbuf = "Downloading registry web page |";
logbuf += psiteinfo->GetIndexpagenet().data();
logbuf += "|";

callback.RegistryDownloadCallback( logbuf.data(), 0 );

// Download the registry webpage into a buffer
CFileDownloader downloader;

regbuf = downloader.Fetch( psiteinfo->GetIndexpagenet() );

// Abort if we didn't get the webpage
if ( regbuf.length() == 0 )
	{
   	callback.RegistryDownloadCallback(
                (char *) "Web page not found, cancelling download", 0 );
	}
else
	{
	// Generate the page address
	psiteinfo->GenerateDestinationPath( destpath );

	m_registrysettings.SaveLocalCache( destpath, regbuf );
                                                                               
	callback.RegistryDownloadCallback(
		(char *) "Registry web page downloaded", 0 );
	}

m_registrysettings.SetDownloadStatus( DOWNLOAD_COMPLETE );

// Return success
return true;
}

// --------------------------------------------------------------------------
// Download a registry web page and all linked files
// --------------------------------------------------------------------------

void CExtensionViewer::DownloadRegistryWebpage( int site,
                CRegistryDownloadCallback &callback, int mode)
{
CExtensionSiteInfo *psiteinfo;
string regbuf;

psiteinfo = GetSiteInfo( site );

if ( NULL == psiteinfo )
	{
#ifdef DEBUG
	cout << "No site information available\n";
#endif
	return;
	}

// Download the index page
DownloadRegistryIndexPage( site, regbuf, callback, mode );

// If the toplevel flag is set, nothing else needs to be done
if (mode != DOWNLOAD_TOPLEVEL)
	{
#ifdef DEBUG
	cout << "Downloading registry extension\n";
#endif
	DownloadRegistryExtensions(site, regbuf, callback, mode );
	}
else
	{
#ifdef DEBUG
	cout << "Top-level mode only\n";
#endif
	}

callback.RegistryDownloadCallback( (char *)
       	"Download of all files complete", 0 );
}

// --------------------------------------------------------------------------
// Download registry extensions
// --------------------------------------------------------------------------

void CExtensionViewer::DownloadRegistryExtensions( int site,
		const string &regbuf,
                CRegistryDownloadCallback &callback, int mode)
{
string extbuf, pregtemp, srcpath, extname, extpath, logbuf, destpath;
int   done, index, found, dryrun;
CExtensionSiteInfo *psiteinfo;

psiteinfo = GetSiteInfo( site );
// Now download each file specified in the registry
// If the 'selmode' flag is set, then only download those selected extensions

index = 0;
done  = false;
dryrun = m_registrysettings.GetDryrunmode();

m_registrysettings.SetDownloadStatus( DOWNLOAD_ACTIVE );

while ( !done )
	{
	// Extract the n'th <a href="xx"> link from the registry
	// It will extract the extension name if any into "extname"
	// and the path into "extpath"
	found = psiteinfo->FindRegistryExtensionPathIndex( 
				regbuf, extname, extpath, index );

	if ( found ==-1)        // No extension was found
		{
#ifdef DEBUG
		cout << "Nothing found\n";
#endif
		done++;         // So, end search
		}
	else
		{
#ifdef DEBUG
		cout << "Found |" << extname.data() << "| = |" << extpath.data() << "|\n";
#endif
		index++;
		}

	// Check to see if the extension belongs to any of the extension
	// lists and whether it is selected for downloading.
	if ( !done && m_headerfileset.CheckExtensionDownload( extname, mode ) )
		{
		string fullpath, srcpath, destpath;

		// Generate the source and destination paths
		psiteinfo->GenerateTransferPaths( srcpath, destpath, extpath );

		// Check the save path
		int save = psiteinfo->CheckFileExtensionSave( srcpath );

#ifdef DEBUG
		cout << "Extpath = |" << extpath.data() << "|\n";
		cout << "Srcpath = |" << srcpath.data() << "|\n";
		cout << "Destpath = |" << destpath.data() << "|\n";
#endif

		if (true == dryrun)
			{
			logbuf = "(dry run) ";
			}
		else
			{
			logbuf = "";
			}

#ifdef DEBUG
		cout << "Save |" << srcpath.data() << "| = " << save << "\n"; 
#endif

		if (!save)
			{
			// Don't save file
			logbuf += string("Ignoring ");
			logbuf += srcpath;
			}
		else 
			{
			// Keep the user informed
			logbuf += string("Saving ");
			logbuf += srcpath + " to " + destpath;
			}

		if (save && !dryrun)
			{
			DownloadRegistryExtension( srcpath, destpath );
			}

		callback.RegistryDownloadCallback( logbuf.data(), 0 );
		}

// --------------------------------------------------------------------------

	if ( !done && m_registrysettings.GetDownloadStatus() == DOWNLOAD_CANCELLED )
		{
		callback.RegistryDownloadCallback( (char *)
        				"Download cancelled", 0 );

		m_registrysettings.SetDownloadStatus( DOWNLOAD_NONE );
		return;
		}
	}
m_registrysettings.SetDownloadStatus( DOWNLOAD_COMPLETE );
}

// --------------------------------------------------------------------------
// Download registry extension
//
// Inputs: fullpath - full web path
//         destpath - full destination path
//
// Outputs: None
//
// Results: None
// --------------------------------------------------------------------------

void CExtensionViewer::DownloadRegistryExtension( 
				const string &fullpath, 
				const string &destpath )
{
m_registrysettings.SetDownloadStatus( DOWNLOAD_ACTIVE );

string strhost, strpath;
ExtractHostName( fullpath, strhost, strpath );

#ifdef DEBUG
cout << "GetBuffer -------\n";
cout << "Fullpath = " << fullpath << endl;
cout << "Destpath = " << destpath << endl;
#endif

m_registrysettings.CheckLocalPath( destpath);

CFileDownloader downloader;

downloader.Download(fullpath, destpath);

m_registrysettings.SetDownloadStatus( DOWNLOAD_COMPLETE );
}
