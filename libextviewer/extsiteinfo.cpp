// ---------------------------------------------------------------------------
// Copyright: (C) VFX Research 2002 - 2014. All Rights Reserved.
// ---------------------------------------------------------------------------

#include "extensionlib.h"

// --------------------------------------------------------------------------
// Dump the value of all variable std::strings
// --------------------------------------------------------------------------

void CExtensionSiteInfo::DumpData( void )
{
std::cout << "Description      = <" << m_description.data()    << ">" << std::endl;
std::cout << "Index dir local  = <" << m_indexdirlocal.data()  << ">" << std::endl;
std::cout << "Index page net   = <" << m_indexpagenet.data()   << ">" << std::endl;
std::cout << "Index page local = <" << m_indexpagelocal.data() << ">" << std::endl;
std::cout << "Header GL net    = <" << m_glheadernet.data()    << ">" << std::endl;
std::cout << "Header GL local  = <" << m_glheaderlocal.data()  << ">" << std::endl;
std::cout << "Header GLX net   = <" << m_glxheadernet.data()   << ">" << std::endl;
std::cout << "Header GLX local = <" << m_glxheaderlocal.data() << ">" << std::endl;
std::cout << "Header WGL net   = <" << m_wglheadernet.data()   << ">" << std::endl;
std::cout << "Header WGL local = <" << m_wglheaderlocal.data() << ">" << std::endl;
std::cout << "Header CORE net   = <" << m_coreheadernet.data()   << ">" << std::endl;
std::cout << "Header CORE local = <" << m_coreheaderlocal.data() << ">" << std::endl;
}

// --------------------------------------------------------------------------
// Set the selected item
// --------------------------------------------------------------------------

void CExtensionSiteInfo::SetInfo( int itemid, const char *path )
{
switch ( itemid )
	{
	case INFO_DESCRIPTION:
		m_description = path;
		break;

	case INFO_INDEXDIRLOCAL:
		m_indexdirlocal = path;
		break;

	case INFO_INDEXPAGENET:
		m_indexpagenet = path;
		break;

	case INFO_INDEXPAGELOCAL:
		m_indexpagelocal = path;
		break;

	case INFO_GLHEADERNET:
		m_glheadernet = path;
		break;

	case INFO_GLHEADERLOCAL:
		m_glheaderlocal = path;
		break;

	case INFO_GLXHEADERNET:
		m_glxheadernet = path;
		break;

	case INFO_GLXHEADERLOCAL:
		m_glxheaderlocal = path;
		break;

	case INFO_WGLHEADERNET:
		m_wglheadernet = path;
		break;

	case INFO_WGLHEADERLOCAL:
		m_wglheaderlocal = path;
		break;

	default:
		break;
	}
}

// --------------------------------------------------------------------------
// Find the full path to the local file
//
// Inputs: pextpath - Pointer to file path
//         pextname - Pointer to name of extension
//
// Outputs: pextpath - character std::string containing the local file path
//
// Results: None
//
// Effects: None
// --------------------------------------------------------------------------
           
int CExtensionSiteInfo::FindExtensionLocalPath(
                         std::string &pextpath, std::string &pextname )
{
// Get the path to the index file
std::string filepath = m_indexdirlocal + "/" + m_indexpagelocal;

struct stat statbuf;
// Check to see if the file exists
int result = stat( filepath.data(), &statbuf );

std::string pbuffer;
// If the file exists, then try and load it into a buffer
if ( result == 0 )
	{
	result = ReadStream( pbuffer, filepath );	
	}

// If the file was successfully loaded into a buffer, then search for the
// reference to the extension
if ( result )
        {
        FindRegistryExtensionPath( pbuffer, pextname, filepath ); 

	pextpath = m_indexdirlocal + "/" + filepath;

	return(1);
        }

return(0);
}

// --------------------------------------------------------------------------
// Given the registry file as a text std::string, find the full path to the
// selected extension
//
// Inputs:  pregfile - Pointer to the web page in memory
//          pextname - Extension name to search for
//
// Outputs: pextpath - HTTP path to selected extension
//
// Results: zero, if extension was not found
//          positive number if extension was found
//
// Effects: None
//
// Notes: This routine searches for the following std::strings:
//
// <a href="EXT/abgr.txt">GL_EXT_abgr</a>
// <a href="EXT/blend_color.txt">GL_EXT_blend_color</a>
// <a href="EXT/polygon_offset.txt">GL_EXT_polygon_offset</a>
// <a href="EXT/texture.txt">GL_EXT_texture</a>
//
// --------------------------------------------------------------------------
                                                                                
int CExtensionSiteInfo::FindRegistryExtensionPath(
        std::string &pregfile, std::string &pextname, std::string &pextpath )
{
const char *pcur;
int   chprev, chcur;
std::string refmode, pextlabel;
                                                                                
if ( pregfile.length() == 0)        // If no webpage, no extensions
    {
    pextname.clear();
    pextpath.clear();
                                                                                
    return( -1 );
    }
                                                                                
// --------------------------------------------------------------------------
// Scan through the list of extension links
// --------------------------------------------------------------------------
                                                                                
pcur = pregfile.data();
chprev = -1;
                        
while ( *pcur != '\0' )         // While not at the end of the file
        {
        chcur = tolower( *pcur );
                                                                                
        if ( (chprev == '<') && (chcur == 'a') )// Get start of reference
                {
                pcur++;
                                                                               
		refmode.clear();
                                                                                
                while ( *pcur && (*pcur != '=' ) )
			{
                        refmode += *pcur++;
			}
                                                                                
                strlowercase( refmode );
                                                                                
                while ( (*pcur != '\"' ) )      // Wait for start of reference
			{
                        pcur++;
			}
                                                                                
                pcur++;
                                              
		pextpath.clear();
                                                                                
                while ( *pcur && (*pcur != '\"') ) // Copy until end
			{
                        pextpath += *pcur++;
			}
                                                                                
                while ( *pcur && (*pcur != '>' ) )  // Skip over '>'
			{
                        pcur++;
			}
                            		
		pcur++; 
		pextlabel.clear();

                while ( *pcur && (*pcur != '<') )   // Skip over '</a>'
			{
                        pextlabel += *pcur++;
			}
                                                                                
                while ( *pcur && (*pcur != '>' ) )
			{
                        pcur++;
			}
                                                                                
                chcur = -1;

                if (  strstr( pextlabel.data(), pextname.data() ) != NULL )
                        {
                        return( 1 );    // Extension was found, so return
                        }
                }
                                                                                
        chprev = chcur;
        pcur++;
        }
                                                 
return( -1 );                           // No extension was found, so return
}

// --------------------------------------------------------------------------
// Given the registry file as a text std::string, find the full path to the
// selected extension
//
// Inputs:  pregfile - Pointer to the text file
//          pextname - Extension name to search for
//          index    - Index to item
//
// Outputs: pextpath - Extension path to selected extension
//
// Results: zero, if extension was not found
//          positive number if extension was found
//
// Effects: None
//
// Notes: This routine searches for the following std::strings:
//
// <li value=1> <a href="EXT/abgr.txt">GL_EXT_abgr</a>
// <li value=2> <a href="EXT/blend_color.txt">GL_EXT_blend_color</a>
// <li value=3> <a href="EXT/polygon_offset.txt">GL_EXT_polygon_offset</a>
// <li value=4> <a href="EXT/texture.txt">GL_EXT_texture</a
//
// --------------------------------------------------------------------------
                                          
int CExtensionSiteInfo::FindRegistryExtensionPathIndex(
                const std::string &pregfile, 
                std::string &pextname, std::string &pextpath, int index )
{
char chcur = 0, chprev = -1;
int   indpos = 0;
//std::string extpath;

char const *pchcur = pregfile.data();

if  ( !pchcur )
	{
	return( -1 );
	}

while ( *pchcur != '\0' )     // While not at the end of the file
    {
    chcur = tolower( *pchcur );
                                                                                
    if ( (chprev == '<') && (chcur == 'a') )    // Get start of reference
        {
        pchcur++;

	ctrace << "Found tag\n";

	std::string refmode;

	refmode.clear();

        while ( *pchcur && (*pchcur != '=' ) )
		{
		refmode += *pchcur++;
		}
                                                                                
	ctrace << "Tag = " << refmode.data() << std::endl; 
	ctrace << "Start of tag" << std::endl;

        while ( (*pchcur != '\"' ) )      // Get the reference link
		{
            	pchcur++;
		}
                                                                                
        pchcur++;
                                                                                
	ctrace << "End of tag" << std::endl;

	pextpath.clear();

        while ( *pchcur && (*pchcur != '\"') )
		{
            	pextpath += *pchcur++;
		}
                                                                                
	ctrace << "Looking for end of open tag" << std::endl;
                                                                                
        while ( *pchcur && (*pchcur != '>' ) )  // Skip over '>'
		{
            	pchcur++;
		}
                                                                                
        pchcur++;
                                                                                
	ctrace << "Looking for start of close tag" << std::endl;

	pextname.clear();

        while ( *pchcur && (*pchcur != '<') )   // Skip over '</a>'
		{
		pextname += *pchcur;
            	pchcur++;
		}
                                                                                
        pchcur++;
                                                                                
	ctrace << "Looking for end of close tag" << std::endl;
                                                                                
        while ( *pchcur && (*pchcur != '>' ) )
		{
            	pchcur++;
		}                                                                                
        chcur = -1;
                                                                                
	ctrace << "Index matched - returning" << std::endl;
	ctrace << "Extension path found = <" << pextpath.data() << ">" << std::endl;
                                                                                
        if ( indpos == index )
		{
                return(1);
		}
                                                                                
        indpos++;
        }
                                                                                
    chprev = chcur;
    pchcur++;
    }
            
ctrace <<"No match found" << std::endl;
                                                                    
return( -1 );           // No match found
}

// --------------------------------------------------------------------------
// Check if two sites are identical
//
// Inputs: siteinfo - The other website
//
// Outputs: None
//
// Results: true if both sites are identical, false otherwise
//
// Effects: None
// --------------------------------------------------------------------------

int CExtensionSiteInfo::WebsiteMatch( CExtensionSiteInfo &siteinfo )
{
int result;

result = true;

result &= ( m_description    == siteinfo.m_description    );
result &= ( m_indexdirlocal  == siteinfo.m_indexdirlocal  );
result &= ( m_indexpagenet   == siteinfo.m_indexpagenet   );
result &= ( m_indexpagelocal == siteinfo.m_indexpagelocal );
result &= ( m_glheadernet    == siteinfo.m_glheadernet    );
result &= ( m_glheaderlocal  == siteinfo.m_glheaderlocal  );
result &= ( m_glxheadernet   == siteinfo.m_glxheadernet   );
result &= ( m_glxheaderlocal == siteinfo.m_glxheaderlocal );
result &= ( m_wglheadernet   == siteinfo.m_wglheadernet   );
result &= ( m_wglheaderlocal == siteinfo.m_wglheaderlocal );
 
return( result );
}

// --------------------------------------------------------------------------
// Download registry header files
// --------------------------------------------------------------------------

int CExtensionSiteInfo::DownloadRegistryHeaders( 	
				CHeaderDownloadProgressCallback &callback )
{
CFileDownloader downloader;

int resultgl, resultwgl, resultglx, resultcorearb;

if ( 0 == GetFlags(FLAG_DOWNLOADHEADERFILES) )
	{
	callback.HeaderDownloadProgressCallback(
		(char *) "Download skipped (download flag not set)", 0 );
	
	ctrace << "Download of registry headers abandoned" << std::endl;

	return 0;
	}

// ----- Send the description -----------------------------------------------

callback.HeaderDownloadProgressCallback( GetDescription(), 0 );

// ----- Download the GL header ---------------------------------------------

callback.HeaderDownloadProgressCallback( GetGlheadernet(), 0 );

resultgl = downloader.Download( GetGlheadernet(), GetGlheaderlocal() );

ctrace << "ResultGL = " << resultgl << std::endl;

// ----- Download the WGL header --------------------------------------------

callback.HeaderDownloadProgressCallback( GetWglheadernet(), 0 );      

resultwgl = downloader.Download( GetWglheadernet(), GetWglheaderlocal() );

ctrace << "ResultWGL = " << resultgl << std::endl;

// ----- Download the GLX header --------------------------------------------

callback.HeaderDownloadProgressCallback( GetGlxheadernet(), 0 );

resultglx = downloader.Download( GetGlxheadernet(), GetGlxheaderlocal() );

ctrace << "ResultGLX = " << resultgl << std::endl;

// ----- Download the Core ARB header ---------------------------------------

callback.HeaderDownloadProgressCallback( GetCoreheadernet(), 0 );

resultcorearb = downloader.Download( GetCoreheadernet(), GetCoreheaderlocal() );

// ----- All finished -------------------------------------------------------

callback.HeaderDownloadProgressCallback( (char *) "Download complete", 0 );      
ctrace << "Download of registry headers complete" << std::endl;

return( (resultwgl * FLAG_WGL)          // Calculate and return result code
      + (resultgl  * FLAG_GL)
      + (resultglx * FLAG_GLX)
      + (resultcorearb * FLAG_COREARB)  );
}

// --------------------------------------------------------------------------
// Create local registry directory
//
// Parameters: site     - index into site list
//             callback - log dialog callback function
//             mode     - which mode
//
// Results: -1 no directory and directory could not be created
//           0 no directory and directory was created
//           1 directory already exists
// --------------------------------------------------------------------------

int CExtensionSiteInfo::CreateLocalRegistryDir(
                CRegistryDownloadCallback &callback, int mode )
{
struct stat statbuf;
int result;

// Check if local directory exists, and crete it if it doesn't exist
result = stat( GetIndexdirlocal().data(), &statbuf );

if (-1 == result)
        {
        // Directory does not exist
        callback.RegistryDownloadCallback(
               (char *) "Registry directory not found ... creating", 0 );

        result = mkdir( GetIndexdirlocal().data(),
                        S_IRWXU|S_IRGRP|S_IXGRP|S_IROTH|S_IXOTH );  // So create                                                                                
        if (-1 == result)
                {
                // Directory cannot be created
                callback.RegistryDownloadCallback(
                (char *) "Registry directory not created ... terminating.", 0 ); 
                }
        }
else
        {
        // Directory already exists
        result = 1;
        }

return result;
}

// --------------------------------------------------------------------------
// Read a single registry webpage
//
// Inputs: strdata : std::string data
//         targetname : target name
// 
// Outputs: None
//
// Results: result of download
// --------------------------------------------------------------------------

int CExtensionSiteInfo::ReadRegistryWebpage(std::string &strdata, 
						const std::string &extwanted)
{
std::string destpath, srcpath;

// Calculate source and destination paths - only need destination path
GenerateTransferPaths( srcpath, destpath, extwanted );

destpath = GetIndexdirlocal() + "/" + GetIndexpagelocal();

ctrace << "Trying to read |" << destpath << "|\n";

// Try and read file
std::string strbuf;

int result = ReadStream( strbuf, destpath );

if (result <= 0)
	{
	ctrace << "Couldn't read file\n";

	return READ_EXTENSION_NOENTRY;
	}

ctrace << "Read registry file - looking for matching extension\n";
ctrace << "Extension wanted = " << extwanted << std::endl;

int success = READ_EXTENSION_NOENTRY;
int index = 0;
int done = 0;
bool found = false;
std::string extname, extpath;

while ( !done )
	{
	// Find the index of the extension
	found = FindRegistryExtensionPathIndex(
			strbuf, extname, extpath, index );

	if (0 < found )		// Found an extension?
		{
		// Is it the one we are looking for?
		if (extname == extwanted )	
			{
			ctrace << "Extension found " << extname << std::endl;

			done++;
			found = 1;
			}
		else
			{
			index++;
			}
		}
	else
		{
		done++;
		}
	}

if (true == found)
	{
	// If we have found the extension path, read the file
	std::string srcpath;
	struct stat statbuf;

	srcpath = GetIndexdirlocal() + "/" + extpath;

	// Check if extension file exists
	result = stat( srcpath.data(), &statbuf );

	if (0 == result)
		{
		// If the file exists, read the text data in, 
		// and set the widget field
		result = ReadStream( strdata, srcpath );

		if (result)
			{
			success = READ_EXTENSION_SUCCESS;
			}
		else
			{
			success = READ_EXTENSION_NOENTRY;
			}
                }
	else
		{
		success = READ_EXTENSION_NOENTRY;
		}
	}

return success;
}

// --------------------------------------------------------------------------
// Generate the full web path for a file
// 
// Inputs: extpath     - extension path
//         registrydir - registry directory
//
// Outputs: fullpath    - full path
//
// Notes:
//
// Generate source path = Server Hostname + directory + file
// http://www.opengl.org/registry/specs/ARB/half_float_pixel.txt
// Set registrydir and hostfile from the web page path
//
// Generation destination path
// eg. registry/specs/ARB/color_buffer_float.txt
// --------------------------------------------------------------------------

void CExtensionSiteInfo::GenerateTransferPaths( std::string &srcpath,
					  std::string &destpath,
                        		  const std::string &extpath )
{
// Extract the host directory
const char *psrc = GetIndexpagenet().data();
const char *pmid = strrchr( psrc, '/' );

std::string registrydir;

registrydir.clear();

while ( *psrc && (psrc < pmid) )
        {
        registrydir += *psrc++;
        }

srcpath.clear();

// If the link already has a http reference, use that
if  ( strncmp( extpath.data(), "ftp", 3 ) == 0 )
        {
	// Full path is ftp
	srcpath = extpath;
        }
else
        {
        if (  strncmp( extpath.data(), "http", 5 ) == 0 )
                {
		// Full path is http
		srcpath = extpath;
                }
        else  // The link is local, so recombine with the host name
                {
                if ( extpath.data()[0] == '/' )
                        {
			srcpath = registrydir + extpath;
                        }
                else
                        {
			srcpath = registrydir + "/" + extpath;
                        }
                }
        }

destpath = GetIndexdirlocal() + "/" + extpath; 	     // Step 3
}

// --------------------------------------------------------------------------
// Check that a prefix can be saved
// --------------------------------------------------------------------------

int CExtensionSiteInfo::CheckFileExtensionSave( const std::string &extpath )
{
int save = 0;

if (StringMatch(extpath, GetFiletypefilters() ))
        {
        save = 1;
        }

return save;
}
