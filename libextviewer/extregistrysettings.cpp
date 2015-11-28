// ---------------------------------------------------------------------------
// Copyright: (C) VFX Research 2002 - 2014. All Rights Reserved.
// ---------------------------------------------------------------------------

using namespace std;

#include "extensionlib.h"

// --------------------------------------------------------------------------
// Ensure that the local directory path exists
//
// Inputs: path - Pointer to the file name and path
//
// Outputs: None
//
// Results: None
//
// Effects: The local file path will be created if it does not already exist
// --------------------------------------------------------------------------

void CExtensionRegistrySettings::CheckLocalPath( const string &path )
{
struct stat statbuf;
string tempbuf;
int res;

tempbuf = path;

				// For each character in path
for (unsigned int pos = 0; pos < tempbuf.length(); pos++ )
	{
    	if ( tempbuf[pos] == '/' )       // Specifies a new path
		{
        	tempbuf[pos] = '\0';     // Ignore rest of path
       
				  // Check file existance
        	res = stat( tempbuf.data(), &statbuf );   

        	if ( res == -1 )  // No file, so create directory
			{
            		mkdir( tempbuf.data(),
				S_IRWXU|S_IRGRP|S_IXGRP|S_IROTH|S_IXOTH );        
			}

        	tempbuf[pos] = '/';      // Think about rest of path
        	}
	}
}

// --------------------------------------------------------------------------
// Save a file to the local cache
//
// Inputs: pname - Pointer to the name string
//         pdata - Pointer to the data buffer
//         dlen  - Length of the data buffer
//
// Outputs: None
//
// Results: None
//
// Effects: The file is saved to the local cache
//
// --------------------------------------------------------------------------

int CExtensionRegistrySettings::SaveLocalCache( const string &destpath,
						const string &data )
{
CheckLocalPath( destpath );

return( WriteStream( data, destpath ) );
}

// --------------------------------------------------------------------------
// Load a file from the local cache
// 
// Inputs: pname - Pointer to the name string
//         pdata - Pointer to the data buffer
//         dlen  - Length of the data buffer
//
// Outputs: dlen - Length of the data buffer if successfully read
//
// Results: Pointer to the data block containing the file information
//          NULL if the file could not be loaded
//      
// Effects: The file is read from the local cache
//
// --------------------------------------------------------------------------

int CExtensionRegistrySettings::LoadLocalCache( 
	string &name, string &destdir, string &destbuf )
{
string destpath, subdir;

const char *pstart;
ifstream stream;

pstart = name.data();

if ( strncmp( pstart, "GL_", 3 ) == 0 )
	{
	pstart += 3;
	}

if ( strncmp( pstart, "WGL_", 4 ) == 0 )	
	{
	pstart += 4;
	}

if ( strncmp( pstart, "GLX_", 4 ) == 0 )
	{
 	pstart += 4;
	}
	
while ( *pstart != '_' )
	{
	subdir += *pstart;
	pstart++;
	}

pstart++;

destpath = destdir + subdir + pstart + ".txt";

return( ReadStream( destbuf, destpath ) );
}


// --------------------------------------------------------------------------
// Examine an OpenGL specification for the list of new constants and 
// procedures defined. 
//
// Inputs: exbuf - Pointer to the buffer containing the extension
//
// Outputs: None
//
// Results: None
//
// Effects: The extension name, function and contant lists are added to the
//          internal list
// 
// --------------------------------------------------------------------------
//
// There are three sections which must be examined. These include:
//
// "Name" 
//     ARB_vertex_program
//
// "New Procedures and Functions"
//
//    void VertexAttrib1sARB(uint index, short x);
//	  void VertexAttrib1fARB(uint index, float x);
//	  void VertexAttrib1dARB(uint index, double x);
//	  void VertexAttrib2sARB(uint index, short x, short y);
//	  void VertexAttrib2fARB(uint index, float x, float y);
//	  void VertexAttrib2dARB(uint index, double x, double y);
//	  void VertexAttrib3sARB(uint index, short x, short y, short z);
//
// "New Tokens"
//
//    VERTEX_PROGRAM_ARB                              0x8620
//
// --------------------------------------------------------------------------

// --------------------------------------------------------------------------
// Search for the selected string inside another string
//
// This function does several things:
//
// [1] Skips the white space before the target string
// [2] Checks for match
// [3] Only checks for match at the beginning of a newline
// [4] Returns NULL if string could not be found
//
// Returns the start of the string if found, NULL otherwise
// --------------------------------------------------------------------------

const char *extbuffer_findnewlinestring( const char *exbuf, 
					const char *name, int &done )
{
int len;

done = 0;

len = strlen( name );	      // Calculate length of target string

while ( isspace( *exbuf ) && *exbuf)  // Skip white space
    exbuf++;

if ( strncmp( exbuf, name, len ) == 0 )   // Found match?
    return( exbuf+len );                  // Return buffer after match

while ( *exbuf )						  
	{
	while (*exbuf && (*exbuf != '\r') && (*exbuf != '\n') )
			// Skip over white space
		{
		exbuf++;
		}

	while ( *exbuf && isspace( *exbuf)  )
		{
		exbuf++;
		}

	if ( exbuf[0] == '\0' )
		{
		done++;
		return( NULL );
		}

	if ( strncasecmp( exbuf, name, len ) == 0 )
		{
		return( exbuf+len );
		}

	exbuf++;
	}

done = 1;

return( NULL );
}

const char *extbuffer_skipspace(const char *exbuf, int &done )
{
while ( ((*exbuf) && isspace( *exbuf ) )|| (*exbuf == '\r') || (*exbuf == '\n') )
	{
   	exbuf++;
	}

if ( (*exbuf) == '\0' )
	{
    	done = true;
	}

return( exbuf );
}

// --------------------------------------------------------------------------
// Copy the string until whitespace or newline or carriage return is 
// received
//
// Inputs: exbuf - source string
//
// Outputs: buffer - destination string
// 	    done   - completion flag
// -------------------------------------------------------------------------

const char *extbuffer_copystring( const string &exbuf, 
					string &buffer, int &done )
{
const char *psrc;

buffer.clear();

psrc =exbuf.data();

while ( *psrc && !isspace( *psrc ) && (*psrc != '\r') && (*psrc != '\n') )
	{
    	buffer += *psrc++;
	}

if ( *psrc == '\0' )   
	{
    	done = true;
	}

return( exbuf.data() );
}

int extname_getexpandedcount( string &extname, int *excounts, int &exnum )
{
const char *tptr;
int total, lcount;

total = 1;

tptr = extname.data();

exnum = 0;

while ( (*tptr != '\0') )
    {
    while ( (*tptr != '\0') && (*tptr != '{') && (*tptr != '[') )
	{
        tptr++;
	}

    if ( (*tptr == '[') || (*tptr == '{') )
        {
        if ( *tptr == '[' )
		{
		lcount = 1;			// The NUL string is another option
		}
	else
		{
		lcount = 0;
		}

	tptr++;
  
        while ( (*tptr) && (*tptr != ']') && (*tptr != '}'))
            {
            lcount++;
            tptr++;
            }

        tptr++;

        excounts[exnum] = lcount;
        exnum++;

        total *= lcount;
        }
    }

return( total );
}

void extname_generate( string &extname, int *excounts, int exnum,  
			string &newname, int expos )
{
int pn, pos, intpos[20];
const char *tptr;

newname.clear();

tptr = extname.data();		// Calculate index positions

for( pn = 0; pn < exnum; pn++ )
	if ( pn == exnum-1 )
		{
    		intpos[pn] = expos % excounts[pn];
		}
	else
		{
		intpos[pn] = expos / excounts[pn];
	    	expos -= excounts[pn] * intpos[pn];
		}

pos = 0;		// Reset counter

while ( *tptr )
    {
    while ( *tptr && (*tptr != '{') && (*tptr != '[') )	// Ordinary text
	{
        newname += *tptr++;
	}

    if ( (*tptr == '{') || (*tptr == '[') )		// Start of expansion block
        {
		if (*tptr == '[' && (intpos[pos] > 0 ) )
			{
		     	newname += tptr[ intpos[pos] ];
			}

		if (*tptr == '{' )
			{
		     	newname += tptr[ intpos[pos]+1 ];
			}

        while ( (*tptr != '}' ) && (*tptr != ']') ) // Find closing } or ]
		{
            	tptr++;
		}
	
        tptr++;				// Skip over it

        pos++;				// Move to next counter
        }
    }
}

const char *extname_cleanup( string &extname )
{
const char *pptr;
const char *pfirst;
int nopencurly, nopensquare, nopenround;
int nclosecurly, nclosesquare, ncloseround;

pptr = extname.data();
pfirst = NULL;

nopencurly = nopensquare = nopenround = 0;
nclosecurly = nclosesquare = ncloseround =0;

while ( *pptr != '\0' )
	{
	switch (*pptr )
		{
		case '{': 
			nopencurly++;  
			break;		// Count number of brackets

		case '}': 
			nclosecurly++;  
			break;    // parenthesis and ellipses

		case '[': 
			nopensquare++; 
			break;

		case ']': 
			nclosesquare++; 
			break;

		case '(': 
			nopenround++;  
			break;

		case ')': 
			ncloseround++;  
			break;

		default:				
			break;
		}

	pptr++;
	}

if ( (nopencurly == nclosecurly) &&			// Everything matches, so
     (nopensquare==nclosesquare) &&         // do nothing
     (nopenround == ncloseround) )	
	{
	return(NULL);
	}

if ( (nopencurly > nclosecurly) && (ncloseround > nopenround ) )
	{
	for ( unsigned int pos = 0; pos < extname.length() && (nopencurly != nclosecurly); pos++ )
		{
		if ( extname[pos] == '{' )
			{
			extname[pos] = '(';

			nopencurly--;
			nopenround++;

			if ( pfirst == NULL )
				{
				pfirst = extname.data() + pos;
				}
			}
		}
	}

return( pfirst );
}

// --------------------------------------------------------------------------
// Convert the long prototype to a short prototype
//
// Inputs: proshort - Pointer to short string
//         prolong  - Pointer to long string
//
// Outputs: proshort - New short parameter list
//
// Results: None
//
// Effects: The long parameter list is converted to a short parameter list
//
// Notes:
//
// The input string is of the format
//
// const GLenum type, GLint stride, const GLvoid **pointer, GLint ptrstride
// --------------------------------------------------------------------------

void extractglproto( string &proshort, 
			string &prolong, int longflag, int glflag )
{
int num;
const char *plong;

proshort.clear();

if ( prolong.length() == 0) 
	{
	return;
	}

plong = prolong.data();

while ( *plong != '\0' )
	{
	if ( isspace (*plong ) || *plong == ',' )
		{
		proshort += *plong++;
		}
	else
		if ( strncmp( plong, "const", 5 ) == 0 )
			{
			for ( num = 0; num < 5; num++ )
				{
				proshort += *plong++;
				}
			}
	else
		{
		switch ( glflag)
			{
			case FLAG_GL:
				if ( strncmp( plong, "GL", 2 ) != 0 )
					{
					proshort += "GL";
					}
				break;

			default:
				break;
			}

		while ( !isspace (*plong) && *plong && *plong != ',')
			{
			proshort+= *plong++;
			}

		if ( longflag )
			{
			while ( isspace( *plong ) && *plong ) 
				{
				proshort += *plong++;
				}

			while ( !isspace( *plong) && *plong && *plong != ',' )
				{
				proshort += *plong++;
				}
			}
		else
			{
			while ( isspace( *plong) && *plong)
				{
				plong++;
				}

			while ( !isspace( *plong) && *plong && *plong != ',')
				{
				plong++;
				}
			}
		}
	}
}

// --------------------------------------------------------------------------
// Given an OpenGL extension stored as an ASCII character, extract various
// useful pieces of information
//
// Inputs:  pbuf        - The OpenGL extension specification
//          exname      - The name to extract
//          exprefix    - The prefix of the name
//          done        - Reference to completion flag
// 
// Outputs: exname      - Extracted name
//          exprefix    - Extracted prefix
//
// Results: The remaining string after the name has been extracted
//
// Effects: None
// --------------------------------------------------------------------------

static char str_name[] = "Name";

const char *CExtensionRegistrySettings::ExtractExtensionName( 
				const char *pbuf,
                                 string &exname, 
			 	 string &exprefix, int &done )
{
const char *newbuf;
// Find string "Name"

newbuf = extbuffer_findnewlinestring( pbuf, str_name, done );

if ( done )
	{
	return(newbuf );
	}

// Skipped over "Name", so skip over space

newbuf = extbuffer_skipspace( newbuf, done );   

if ( done )
	{
	}

// Now we can get the extension name

newbuf = extbuffer_copystring( newbuf, exname, done );

if ( done )
	{
	return(NULL);
	}
   
// Now we can get the prefix

for ( int pos = exname.length()-1, done = 0; (pos >= 0) && !done; pos-- )
	{
	if ( exname[pos] == '_' )
		{
		exname[pos] = '\0';
	
		exprefix = exname;

		exname[pos] = '_';
		done++;
		}	
	}

return( newbuf );
}

// --------------------------------------------------------------------------
// Extract name strings
// --------------------------------------------------------------------------

const char *CExtensionRegistrySettings::ExtractExtensionNameStrings( 
			const char *pbuf,  
                        string &namestrings, int &done )
{
const char *newbuf;

newbuf = extbuffer_findnewlinestring( pbuf, "Name Strings", done );

if ( !newbuf )
	{
	newbuf = extbuffer_findnewlinestring( pbuf, "Name String", done );
	}

if ( done )
	{
    	return( pbuf );
	}

pbuf = extbuffer_skipspace( newbuf, done );

while ( *pbuf && (strncmp( pbuf, "Contributors", 12 ) != 0) 
              && (strncmp( pbuf, "Contact",      7  ) != 0) 
              && (strncmp( pbuf, "Version",      7  ) != 0) 
              && (strncmp( pbuf, "Notice",       6  ) != 0) 
	      && (*pbuf != '\n' ) 
	      && (*pbuf != '\r') )
	{
        namestrings+= *pbuf;

	pbuf++;
	}

if ( done )
	{
    	return( NULL );
	}

return( pbuf );
}

// --------------------------------------------------------------------------
// Extract Extension Contributors
// --------------------------------------------------------------------------

const char *CExtensionRegistrySettings::ExtractExtensionContributors( 
			const char *pbuf, 
			string &contributors, int &done )
{
const char *newbuf;

newbuf = extbuffer_findnewlinestring( pbuf, "Contributors", done );

if ( done )
	{
    	return( pbuf);
	}

pbuf = extbuffer_skipspace( newbuf, done );

if ( done)
	{
    	return(NULL);
	}

while ( strncmp( pbuf, "Contact", 7 ) != 0 )
	{
    	contributors += *pbuf++;
	}

if ( done )
	{
    	return(NULL);
	}

return( pbuf );
}

// --------------------------------------------------------------------------
// Extract Extension Contact
// --------------------------------------------------------------------------

const char *CExtensionRegistrySettings::ExtractExtensionContact( 
				const char *pbuf, 
				string &contact, int &done )
{
const char *newbuf;

newbuf = extbuffer_findnewlinestring( pbuf, "Contact", done );

if ( done )
	{
    	return( pbuf );
	}

pbuf = extbuffer_skipspace( newbuf, done );

if ( done ) 
	{
    	return( NULL );
	}

while ( *pbuf && (strncmp( pbuf, "IP Status", 9 ) != 0) 
              && (strncmp( pbuf, "Notice",    6 ) != 0)
              && (strncmp( pbuf, "Status",    6 ) != 0) 
              && (strncmp( pbuf, "Version",   7 ) != 0)
              && (strncmp( pbuf, "Number",    6 ) != 0)
	      && (strncmp( pbuf, "Dependencies", 12 )!= 0)
	      && (strncmp( pbuf, "Overview", 8 ) != 0 )
	      && (strncmp( pbuf, "Issues", 6 ) != 0 ) )
	{
    	contact+= *pbuf++;
	}

if ( done )
	{
    	return( NULL );
	}

return( pbuf );
}

// --------------------------------------------------------------------------
// Extract Extension IP Status
// --------------------------------------------------------------------------

const char *CExtensionRegistrySettings::ExtractExtensionIPStatus( 
					const char *pbuf,
                                        string &ipstatus, int &done )
{
const char *newbuf;

newbuf = extbuffer_findnewlinestring( pbuf, "IP Status", done );

if ( done )
	{
	return( pbuf );
	}

pbuf = extbuffer_skipspace( newbuf, done );

if ( done )
	{
	return( NULL );
	}

while ( *pbuf && strncmp( pbuf, "Status", 6 ) != 0 )
	{
	ipstatus+= *pbuf++;
	}

if ( done )
	{
	return( NULL );
	}

return( pbuf );
}

// --------------------------------------------------------------------------
// Extract Extension Status
// --------------------------------------------------------------------------

const char *CExtensionRegistrySettings::ExtractExtensionStatus( 
		const char *pbuf, 
		string &status, int &done )
{
const char *newbuf = extbuffer_findnewlinestring( pbuf, "Status", done );

if ( done )
	{
    	return( pbuf );
	}

pbuf = extbuffer_skipspace( newbuf, done );

if ( done )
	{
    	return( NULL );
	}

while ( *pbuf && strncmp( pbuf, "Version", 7 ) != 0 )
	{
    	status+= *pbuf++;
	}

if ( done )
	{
    	return( NULL );
	}

return( pbuf );
}

// --------------------------------------------------------------------------
// Extract Extension Version
// --------------------------------------------------------------------------

const char *CExtensionRegistrySettings::ExtractExtensionVersion( 	
					const char *pbufsrc, 
                                         string &version, int &done )
{
const char *pbuf = extbuffer_findnewlinestring( pbufsrc, "Version", done );

if ( done )
	{
    	return( pbuf );
	}

pbuf = extbuffer_skipspace( pbuf, done );

if ( done )
	{
    	return( NULL );
	}

while ( *pbuf && strncmp( pbuf, "Number", 6 ) != 0 )
	{
    	version+= *pbuf++;
	}

if ( done )
	{
    	return( NULL );
	}

return( pbuf );
}

// --------------------------------------------------------------------------
// Extract Extension Number
// --------------------------------------------------------------------------

const char *CExtensionRegistrySettings::ExtractExtensionNumber( 
					const char *pbuf,
                                        string &number, int &done )
{
const char *newbuf = extbuffer_findnewlinestring( pbuf, "Number", done );

if ( done )
	{
    	return( pbuf );
	}

pbuf = extbuffer_skipspace( newbuf, done );

if ( done )
	{
    	return( NULL );
	}

while ( *pbuf && (strncmp( pbuf, "Dependencies", 11 ) != 0 )
              && (strncmp( pbuf, "Overview", 8 ) != 0 )
              && (strncmp( pbuf, "Proposal:", 9 ) != 0 ) )
	{
    	number += *pbuf++;
	}

if ( done )
	{
    	return( NULL );
	}

return( pbuf );
}

// --------------------------------------------------------------------------
// Prepare to add a new extension to the lists
// --------------------------------------------------------------------------

void CExtensionRegistrySettings::ExtractExtensionInit( string &exname, 
		int &winflag, int &expos, 
		CExtensionHeaderFileSet &fileset )
{
string namebuf;

if ( strstr( exname.data(), "WGL" ) != NULL || strstr( exname.data(), "WIN" ) != NULL )
	{
    	expos = fileset.m_wgllist.AddStart( exname.data() );
 	winflag = FLAG_WGL;
    	}
else
	if ( strstr(exname.data(), "GLX" ) != NULL )
		{
		expos = fileset.m_glxlist.AddStart( exname.data() );
		winflag = FLAG_GLX;
		}
else
	if ( strstr(exname.data(), "GL" ) != NULL )

		{
		expos = fileset.m_gllist.AddStart( exname.data() );
  		winflag = FLAG_GL;
		}

for ( unsigned int pos = 0; pos <exname.length(); pos++ )
	{
	int oldch;
	while ( !islower(exname[pos]) )
		{
    		pos++;
		}

	oldch = exname[pos];
	exname[pos] = '\0';

	switch ( winflag )
		{
		case FLAG_GL:
    			fileset.m_vendorlist.Add( exname );
			break;

		case FLAG_WGL:
    			fileset.m_vendorlist.Add( exname );
			break;

		case FLAG_GLX:
    			fileset.m_vendorlist.Add( exname );
			break;
	
		default:
			break;
		}

	exname[pos] = oldch;
	}
}

// --------------------------------------------------------------------------
// Extract New Procedures and Functions
// --------------------------------------------------------------------------

const char *CExtensionRegistrySettings::ExtractExtensionProceduresAndFunctions( 
            const char *pbuf, int winflag, int expos,  int &done, 
		CExtensionHeaderFileSet &fileset )
{
int tokendone, spaceflag, extotal, excounts[100], exnum, en;
string returnbuf, namebuf, longproto, tempbuf, shortproto;
const char *newbuf;

newbuf = extbuffer_findnewlinestring( 
		pbuf, "New Procedures and Functions", done );
	
if (NULL == newbuf )
	newbuf = extbuffer_findnewlinestring( pbuf, "Proposal:", done );

if ( done )
	{
     	return(pbuf);
	}
     
pbuf = extbuffer_skipspace( newbuf, done );

tokendone = 0;

while ( (strncmp( pbuf, "New Tokens", 10 ) != 0 ) &&
        (strncmp( pbuf, "Issues",      6 ) != 0 ) && 
        (strncmp( pbuf, "An example", 10 ) != 0 ) &&
        (strncmp( pbuf, "Parameters", 10 ) != 0 ) && 
		(strncmp( pbuf, "Add two",     7 ) != 0 ) &&
        !tokendone )     // Wait for title
    {
    pbuf = extbuffer_skipspace( pbuf, tokendone );

	// Sometimes, the extension specifications include a preamble and
        // C/C++ data structures. These contain keywords that can be
        // misinterpreted as function or procedure definitions

    if ( strncmp( pbuf, "None", 4 ) == 0 )
        tokendone++;
    else
        {
	// This list defines all the possible return types known to the
	// current OpenGL API specification

        while (	!isspace( pbuf[-1] ) )
		{
		pbuf++;
		}

	while ( (strncmp( pbuf, "gl",              2 ) != 0 ) &&
                (strncmp( pbuf, "List",            4 ) != 0 ) &&
                (strncmp( pbuf, "GetList",         7 ) != 0 ) &&
                (strncmp( pbuf, "GLint",           5 ) != 0 ) &&
                (strncmp( pbuf, "bool",            4 ) != 0 ) &&
                (strncmp( pbuf, "BOOL",            4 ) != 0 ) &&
                (strncmp( pbuf, "Bool",            4 ) != 0 ) &&
                (strncmp( pbuf, "void",            4 ) != 0 ) &&
                (strncmp( pbuf, "VOID",            4 ) != 0 ) &&
                (strncmp( pbuf, "int ",            4 ) != 0 ) &&
                (strncmp( pbuf, "int\t",           4 ) != 0 ) &&
                (strncmp( pbuf, "int\n",           4 ) != 0 ) &&
		(strncmp( pbuf, "uint",            4 ) != 0 ) &&
                (strncmp( pbuf, "HANDLE",          6 ) != 0 ) &&
                (strncmp( pbuf, "New Tokens",     10 ) != 0 ) &&
                (strncmp( pbuf, "Issues",          6 ) != 0 ) &&
                (strncmp( pbuf, "const ",          6 ) != 0 ) &&
                (strncmp( pbuf, "const\t",         6 ) != 0 ) &&
                (strncmp( pbuf, "const\n",         6 ) != 0 ) &&
                (strncmp( pbuf, "GLXPixmap",       6 ) != 0 ) &&
                (strncmp( pbuf, "DECLARE_HANDLE", 14 ) != 0 ) &&
                (strncmp( pbuf, "HPBUFFERARB",    11 ) != 0 ) &&
                (strncmp( pbuf, "HPBUFFEREXT",    11 ) != 0 ) &&
                (strncmp( pbuf, "GLXFBConfigSGIX", 15 ) != 0 ) &&
                (strncmp( pbuf, "GLXContext",      10 ) != 0 ) &&
                (strncmp( pbuf, "GLXHyperpipeConfigSGIX", 22 ) != 0 ) &&
                (strncmp( pbuf, "GLXHyperpipeNetworkSGIX", 23 ) != 0 ) &&
                (strncmp( pbuf, "XVisualInfo",     11 ) != 0 ) &&
                (strncmp( pbuf, "handleARB",       9 ) != 0 ) &&
                (strncmp( pbuf, "HDC",             3 ) != 0 ) &&
		(strncmp( pbuf, "/*", 2 ) != 0 ) &&
		(strncmp( pbuf, "typedef", 7 ) != 0 ) )
	pbuf++;

    // Skip over comments
                                                                               
	while (strncmp( pbuf, "/*", 2) == 0 ||
               strncmp( pbuf, "typedef", 7) == 0 )
		{
		if ( strncmp( pbuf, "/*", 2 ) == 0 )
               		{
	                while ( strncmp( pbuf, "*/", 2 ) != 0 )
				pbuf++;

			pbuf+= 2;
			}
	
		while ( isspace( *pbuf ) || *pbuf == '\n' || *pbuf == '\r') 
			pbuf++;

        // Skip over function definitions
                                                                               
	        if ( strncmp( pbuf, "typedef", 7 ) == 0 )
			{
			while ( *pbuf != ';' )
				pbuf++;
                                                                               
                	pbuf++;
                	}

		while ( isspace( *pbuf ) || *pbuf == '\n' || *pbuf == '\r') 
			pbuf++;
		}
	
	// If we have found a keyword, begin the conversion
	if (
             strncmp( pbuf, "bool",         4 ) == 0 ||
             strncmp( pbuf, "BOOL",         4 ) == 0 ||
             strncmp( pbuf, "Bool",         4 ) == 0 ||
             strncmp( pbuf, "void",         4 ) == 0 ||
             strncmp( pbuf, "VOID",         4 ) == 0 ||
             strncmp( pbuf, "int ",         4 ) == 0 ||
             strncmp( pbuf, "int\t",        4 ) == 0 ||
             strncmp( pbuf, "int\n",        4 ) == 0 ||
	     strncmp( pbuf, "uint",         4 ) == 0 ||
             strncmp( pbuf, "HANDLE",       6 ) == 0 ||
             strncmp( pbuf, "const ",       6 ) == 0 ||
             strncmp( pbuf, "const\t",      6 ) == 0 ||
             strncmp( pbuf, "const\n",      6 ) == 0 ||
             strncmp( pbuf, "GLXPixmap",    6 ) == 0 ||
             strncmp( pbuf, "GLINT",        5 ) == 0 ||
             strncmp( pbuf, "HPBUFFERARB", 11 ) == 0 || 
             strncmp( pbuf, "HPBUFFEREXT", 11 ) == 0 ||
             strncmp( pbuf, "handleARB",    9 ) == 0 ||
             strncmp( pbuf, "GLXContext",  10 ) == 0 ||
             strncmp( pbuf, "GLXFBConfigSGIX", 15 ) == 0 ||
             strncmp( pbuf, "GLXHyperpipeConfigSGIX", 22 ) == 0 ||
             strncmp( pbuf, "GLXHyperpipeNetworkSGIX", 23 ) == 0 ||
             strncmp( pbuf, "XVisualInfo", 11 ) == 0 ||
             strncmp( pbuf, "handleARB",    9 ) == 0 ||
             strncmp( pbuf, "HDC",          3 ) == 0 )
             {

             pbuf = extbuffer_copystring( pbuf, returnbuf, tokendone );

             pbuf = extbuffer_skipspace( pbuf, tokendone );

			if ( strncmp( pbuf, "void", 4 ) == 0 )
				{
				pbuf += 4;	
				returnbuf += " void";
				}

			if ( strncmp( pbuf, "char", 4 ) == 0 )
				{
				pbuf += 4;	
				returnbuf += " char";
				}


             pbuf = extbuffer_skipspace( pbuf, tokendone );

	     	if ( *pbuf == '*' )
				{
				returnbuf += " *";
				pbuf++;	
				}

		if ( strncmp( pbuf, "(*", 2 ) == 0 )
			{
			returnbuf += "(*proc)(...)";
			pbuf += 2;
			}
             } // if
        else
             if ( ( (strncmp( pbuf, "New Tokens", 10 ) != 0 ) &&
                    (strncmp( pbuf, "Issues",      6 ) != 0 ) &&
                    (strncmp( pbuf, "An example", 10 ) != 0 )) ||
                     strncmp( pbuf, "List",        4 ) == 0 ||
                     strncmp( pbuf, "GetList",     7 ) == 0 ) 
                 {
                 returnbuf = "int";
                 }

// --------------------------------------------------------------------------
// The return call has been completed  - now get the function name
// --------------------------------------------------------------------------

         if ( (strncmp( pbuf, "New Tokens", 10 ) != 0 ) &&
              (strncmp( pbuf, "Issues",      7 ) != 0 ) &&
              (strncmp( pbuf, "An example", 10 ) != 0 ) &&
              (strncmp( pbuf, "Parameters", 10 ) != 0 ) )
        {
	namebuf.clear();

        if ( strncmp( pbuf, "(*", 2 ) == 0 )  // Functions returns func-pointer
            {
            spaceflag = 1;

            while ( (*pbuf != '\n') && (*pbuf != '\r') )
                 if ( !isspace(*pbuf) )
                     {
                     namebuf += *pbuf++;
                     spaceflag = 1;
                     } // if
                 else
                     if ( spaceflag )
                         {
                         namebuf += *pbuf++;
                         spaceflag = 0;
                         } // if
                 else
			{
			pbuf++;
			}
            } // if
        else                                  // Ordinary function
            {
            while ( *pbuf && (*pbuf != '(') ) // Save the name
		{
                 if ( !isspace( *pbuf ) )
			{
                     	namebuf += *pbuf++;                
			}
                 else
			{
                     	pbuf++;
			}
		}
            pbuf++;         // Skip over '('
        
            if ( *pbuf == '\0' )
		{
                 return(NULL);
               	} 
            // ----- Extract the prototype contents of the function -----

            spaceflag = 0;
	    longproto.clear();

            while ( *pbuf && (*pbuf != ')' && (*pbuf != ';') ) )                  // Save the long prototype
		{
                if ( !isspace( *pbuf) && *pbuf)
                    {
                    longproto += *pbuf++;                
                    spaceflag = 1;
                    }
                else
                    if ( spaceflag )
                         {
                         longproto += ' ';
                         pbuf++;
                         spaceflag = 0;
                         }
                else
                    pbuf++;
		}

             if ( *pbuf == '\0' )
		{
                 return(NULL);
		}
            }
  
        //     while ( strncmp( pbuf, "(...)", 5 ) != 0 )
        //          namebuf[pos++] = *pbuf++; 

        //      while ( *pbuf != ';' )                  // Skip over ';'
        //          pbuf++;

        // ---------------------------------------------------------------
        // Sometimes, a function may return a pointer - The const bit is
        // saved as the return value, but the actual data type and * is
        // bundled with the function name - this is corrected here
        // ---------------------------------------------------------------

        if ( ( strncmp( namebuf.data(), "(*", 2 ) != 0 ) &&
             ( strrchr( namebuf.data(), '*' ) != NULL ) )
             {
             const char *tptr;

             tptr=namebuf.data(); 
             returnbuf += ' ';  // Add a space
            
             while( *tptr != '*' )
		{
                 returnbuf += *tptr++;
		}

             if ( *tptr == '*' )
                 {
                 returnbuf += ' ';
                 returnbuf += '*';
		 tptr++;
                 }

	     while ( isspace( *tptr ) )
		{
		tptr++;
		}

		namebuf += tptr;

//             while ( *tptr ) 
//		namebuf += *tptr++;
             }

        // ---------------------------------------------------------------
        // Sometimes the function name has a gl or wgl prefix. Sometimes 
        // it doesn't. The solution is to append the correct string just
        // before printing out the final string
        // ---------------------------------------------------------------

        tempbuf = namebuf;

        if ( (strncmp( tempbuf.data(), "gl",  2 ) != 0 ) &&
             (strncmp( tempbuf.data(), "wgl", 3 ) != 0 ) &&
	     (strncmp( tempbuf.data(), "glX", 3 ) != 0 ) &&
             (strncmp( tempbuf.data(), "(*",  2 ) != 0 ) )
             {
	     switch ( winflag )
		{
		case FLAG_WGL:
			if ( strncmp( tempbuf.data(), "DECLARE", 7 ) != 0 )
				{
                 		namebuf = "wgl";
				namebuf += tempbuf;
				}
			break;

		case FLAG_GL:
                  	namebuf = "gl";
			namebuf += tempbuf;
			break;

		case FLAG_GLX:
			namebuf = "glX";
			namebuf += tempbuf;
			break;

		default:
			namebuf = tempbuf;
			break;
		}
             }

        // ---------------------------------------------------------------
        // Sometimes the function names have been compressed into wildcard
        // notation using [] and {} symbols. These have to be expanded
        // ---------------------------------------------------------------

	extname_cleanup( namebuf );

        extotal = extname_getexpandedcount( namebuf, excounts, exnum );
	
	if (extotal > 512 )
	{
	cout << "Error: More than 512 entries\n";
	}
	else
	for ( en = 0; en < extotal; en++ )
		{
		string newreturnbuf, newlongproto;
             	extname_generate( namebuf, excounts, exnum, tempbuf, en );

		switch ( winflag )
			{
			case FLAG_WGL:
				newreturnbuf = string("extern ") + returnbuf + string(" WINAPI");
				break;

			case FLAG_GLX:
			case FLAG_GL:
				newreturnbuf = string("GLAPI ") + returnbuf + string(" APIENTRY");
				break;

			default:
				break;
			}

		extractglproto( shortproto,   longproto, 0, winflag );
		extractglproto( newlongproto, longproto, 1, winflag );

		switch ( winflag )
			{
			case FLAG_WGL:	
				fileset.m_wgllist.AddPrefixNameValueProto( 	
					newreturnbuf, tempbuf, shortproto, newlongproto );
				fileset.m_wgllist.IncrementFuncNum(expos);
				break;

			case FLAG_GL:
             			fileset.m_gllist.AddPrefixNameValueProto( 
					newreturnbuf, tempbuf, shortproto, newlongproto );
				fileset.m_gllist.IncrementFuncNum(expos);
				break;

			case FLAG_GLX:
				fileset.m_glxlist.AddPrefixNameValueProto(
					newreturnbuf, tempbuf, shortproto, newlongproto );
				fileset.m_glxlist.IncrementFuncNum(expos);
				break;

			default:
				break;
			}
		}                
      
        // ---------------------------------------------------------------
        // Skip over the ); that terminates the function definition
        // ---------------------------------------------------------------

        if ( *pbuf == ')' )
		{
             	pbuf++;
		}
       
        if ( *pbuf == ';' )
		{
             	pbuf++;
		}
     
        pbuf = extbuffer_skipspace( pbuf, tokendone );
        }
    }
}      
         
return( pbuf );
}

// --------------------------------------------------------------------------
// Extract Tokens
// --------------------------------------------------------------------------

string info_unknown( "Unknown" );

const char *CExtensionRegistrySettings::ExtractExtensionTokens( 
	const char *pbuf, 
	int winflag, int expos, 
	string &exprefix, int &done,
	CExtensionHeaderFileSet &fileset)
{
string tempbuf, lastword, curword;
int   pos, lowercount, badcount, tokendone, pn;
const char *newbuf;

tokendone = 0;

if  (!pbuf )
	{
	return(NULL);
	}

newbuf = extbuffer_findnewlinestring( pbuf, "New Tokens", tokendone ); 

if ( newbuf )
	{
	pbuf = newbuf;
	}

while ( (*pbuf) && !tokendone )
	{
	pbuf = extbuffer_skipspace( pbuf, tokendone );

	if ( (strncmp( pbuf, "GLX Protocol", 12 ) == 0) ||
		(strncmp( pbuf, "Additions", 9 ) == 0) )
		tokendone++;
     
	if ( NULL != pbuf)
		{
		return(NULL);
		}
     
	pbuf = extbuffer_copystring( pbuf, curword, tokendone );

	if ( NULL != pbuf)
		{
		return(NULL);
		}
     
	lowercount = 0;
	badcount   = 0;
	pos        = lastword.length();

	const char *ptemp = lastword.data();

	for ( pn = 0; pn < pos; pn++ )
		{
		lowercount += ( islower(ptemp[pn] ) );

		if ( !isdigit( ptemp[pn] ) && 
              		!isalpha( ptemp[pn] ) &&
              		(ptemp[pn] != '_') )
			badcount++;
		}

	if (( curword.data() ) != NULL )
		{
	if ( (lowercount == 0 ) && 
		( (strncmp( curword.data(), "0x", 2 ) == 0) || 
			(isdigit( curword.data()[0] ) && 
			isdigit( curword.data()[1] ) ) ))
		{
		pos = 0;

		if ( ( strstr( lastword.data(), "GLX_" ) == NULL) &&
			( strstr( lastword.data(), "GLU_" ) == NULL) )
			{ 
			switch ( winflag )
				{
				case FLAG_WGL:
		    		if ( strncmp( lastword.data(), "WGL_", 4 ) != 0 )
			    		{
						tempbuf = "WGL_";
						pos = 4;
						}
		    		break;

				case FLAG_GL:
					if ( strncmp( lastword.data(), "GL_", 3 ) != 0 )
						{
						tempbuf = "GL_";
						pos = 3;
						}
					break;

				case FLAG_GLX:
					if ( strncmp( lastword.data(), "GLX_", 4 ) != 0 )
						{
						tempbuf = "GLX_";
						pos = 4;
						}
		    		break;

				default:
					tempbuf = lastword;
					break;
				}
			}

		const char *tcptr;

		tcptr = lastword.data();

		tempbuf.clear();

		while ( *tcptr )
			{
			if ( isalpha(*tcptr) || isdigit(*tcptr) || *tcptr == '_' )
				tempbuf += *tcptr;

			tcptr++;
			}      
   
		switch( winflag )
			{
			case FLAG_WGL:
				fileset.m_wgllist.AddConstNameValue( 
					tempbuf, curword, expos );
				break;
	
			case FLAG_GLX:
				fileset.m_glxlist.AddConstNameValue( 
					tempbuf, curword, expos );
				break;

			case FLAG_GL:
				fileset.m_gllist.AddConstNameValue( 
					tempbuf, curword, expos );
				break;
			}
		}
	else
		if ( strstr( lastword.data(), exprefix.data() ) && 
   	                 (lowercount == 0) && (badcount == 0) )
			{	
			string glbuf;

			switch ( winflag )
				{
				case FLAG_WGL:
					glbuf = "WGL_";	
					glbuf += lastword;

					if ( ( strncmp( lastword.data(), "wgl", 3) != 0) &&
   	        			(fileset.m_wgllist.FindName(glbuf.data())    == -1) &&
						(fileset.m_wgllist.FindName(lastword.data()) == -1) )
						{
						if ( lastword.data()[0] != 'W' )
							{
							glbuf = "WGL_";	
							glbuf += lastword;
	
							fileset.m_wgllist.AddConstNameValue( 
										glbuf, info_unknown, expos );
							}
						else
							fileset.m_wgllist.AddConstNameValue( 
									lastword, info_unknown, expos );

						}
					break;

				case FLAG_GL:
					if ( (strncmp( lastword.data(), "gl", 2) != 0) &&
						(fileset.m_gllist.FindName( lastword.data() ) == -1) &&
   	        			(fileset.m_gllist.FindName( glbuf.data()+1 ) == -1) )
						{
						if ( lastword.data()[0] != 'G' )
							{	
							glbuf = "GL_";
							glbuf += lastword;

							fileset.m_gllist.AddConstNameValue(
									 glbuf, info_unknown, expos );
							}
						else
							fileset.m_gllist.AddConstNameValue( 
									lastword, info_unknown, expos );

						}
					break;
					
				case FLAG_GLX:
					if ( ( strncmp( lastword.data(), "glX", 2) != 0) &&
						(fileset.m_gllist.FindName( lastword.data() ) == -1) &&
   	        			(fileset.m_gllist.FindName( glbuf.data()+1 ) == -1) )
						{
						if ( lastword.data()[0] != 'G' )
							{	
							glbuf = "GLX_";
							glbuf += lastword;

							fileset.m_gllist.AddConstNameValue(
										 glbuf, info_unknown, expos );
							}
						else
							{
							fileset.m_gllist.AddConstNameValue( 
									lastword, info_unknown, expos );
							}
						}
					break;

				default:
					break;
				}
			}

		if ( curword.length() >3 )
			{
         		lastword = curword;
			}
		}

    if ( strncmp( pbuf, "None", 4 ) == 0 )
	{
        tokendone++;
	}
    }		
   		
return( pbuf );
}

// --------------------------------------------------------------------------
// Read the extension buffer
// --------------------------------------------------------------------------

void CExtensionRegistrySettings::ReadExtensionBuffer( 
	string &exbuf,    
	CRegistryFileProgressCallback &callback,
        string &name, 
	int filepos, int filemax, 
	CExtensionHeaderFileSet &fileset )
{
const char *pbuf;
int   winflag, expos, done, buflen;
string exname, exprefix;
string localname, localprefix;

buflen = exbuf.length();

localname.reserve( buflen+2 );

pbuf = exbuf.data();
done = 0;

if ( pbuf )
	{ 
	pbuf = ExtractExtensionName( pbuf, localname, localprefix, done );

	if ( pbuf )
		{
		pbuf = ExtractExtensionNameStrings( pbuf, exname, done );

		callback.RegistryFileProgressCallback( 
				name.data(), exname.data(), 
				filepos, filemax );

		ExtractExtensionInit( exname, winflag, expos, fileset);

		pbuf = ExtractExtensionContributors( pbuf, localname, done );

		pbuf = ExtractExtensionContact( pbuf, localname, done );

		pbuf = ExtractExtensionStatus(   pbuf, localname, done );

		pbuf = ExtractExtensionVersion(  pbuf, localname, done );

		pbuf = ExtractExtensionNumber(   pbuf, localname, done );

		//pbuf = ExtractExtensionDependencies( pbuf, buffer, done );

		//pbuf = ExtractExtensionOverview( pbuf, buffer, done );

		//pbuf = ExtractExtensionIPStatus( pbuf, buffer, done );

		//pbuf = ExtractExtensionIssues( pbuf, buffer, done );

		pbuf = ExtractExtensionProceduresAndFunctions( pbuf, winflag, 
				expos, done, fileset);

		pbuf = ExtractExtensionTokens( pbuf, winflag, expos, exprefix, 
				done, fileset);
		}
	}
}

// --------------------------------------------------------------------------
// Load an OpenGL Extension Specification from a file and search for the
// constants and function prototypes
//
// Inputs: path - Path to the extension file
//         progressproc - Callback function to indicate progress
//
// Outputs: None
// 
// Results: None
//
// Effects: The extension name, function and constant lists are 
// --------------------------------------------------------------------------

void CExtensionViewer::ReadExtensionFile( string &path, 
	CRegistryFileProgressCallback &callback,
         int filepos, int filemax )
{
ifstream stream;
int res;
string pbuf;
string strname;

if ( (strstr(path.data(), ".html" ) != NULL) ||
     (strstr(path.data(), "/doc/" ) != NULL ) ||
     (strstr(path.data(), ".txt") == NULL) )
	return;

res = ReadStream( pbuf, path );

if ( !res )
	{
	return;
	}

strname = path.data();

m_registrysettings.ReadExtensionBuffer( 
	pbuf, callback, strname, filepos, filemax, m_headerfileset );
}

// --------------------------------------------------------------------------
// Count the number of items in the registry. The purpose of this routine
// is to provide an estimate of the number of files and directories to be
// processed.
//
// Inputs: pcallback - Pointer to the callback function
//
// Outputs: None
//
// Results: The number of files and directories found
//
// Effects: The registry directory system is explored and a callback is made
//          for each extension specification
// --------------------------------------------------------------------------

int CExtensionRegistrySettings::GetRegistryCount( string &localdir )
{
stack <string> stacklist;
string filename, path, tempbuf;
int     result, mode = CALLBACK_FILE, filecount;
DIR      *handle;
struct dirent *dirptr;
struct stat    statbuf;

filecount = 0;

stacklist.push( localdir );

while ( stacklist.size() > 0 )                  // While stack not empty
	{
	filename = stacklist.top();
	stacklist.pop();

	tempbuf = filename;

    	handle = opendir( tempbuf.data() ); // Begin extraction
	
	if ( handle )	
		{
		while ( (dirptr = readdir( handle ) ) != NULL )
	   		if ( dirptr->d_name[0] != '.' )
				{
				path = filename + "/" + dirptr->d_name;

	    			result = stat( path.data(), &statbuf );

				if (result == 0)
				{
	    				if ( statbuf.st_mode & S_IFDIR ) // Directory
						{		 	 // Push onto stack
						stacklist.push( path );

						if ( mode & CALLBACK_DIRECTORY )
							{
							filecount++;
							}
						}
	    				else
					if ( statbuf.st_mode & S_IFREG )
						{
						filecount++;
						}
					}
				}
		}

	closedir( handle );
	}

return( filecount );
}

// --------------------------------------------------------------------------
// Scan through all the files in the registry and use the callback function
// to indicate the progress being made
// 
// Inputs: site          - Which site to use
// 	   callback      - Reference to the callback function
//         selectionmode - Selection mode
//
// Outputs: None
//
// Results: The number of files and directories found
//
// Effects: The registry directory system is explored and a callback is made
//          for each extension specification
// --------------------------------------------------------------------------

int CExtensionViewer::ReadRegistry( int site,
		CRegistryFileProgressCallback &callback, int selectmode )
{
int     filepos, filemax, mode = CALLBACK_FILE;
DIR    *handle;
struct  dirent *dirptr;
struct stat statbuf;
CExtensionSiteInfo *psiteinfo;
string path, filename,tempbuf, dirlocal;
stack <string> stacklist;
string strdir;

if ( selectmode == READ_ALL )
    m_headerfileset.Init();

psiteinfo = GetSiteInfo( site );

dirlocal = psiteinfo->GetIndexdirlocal().data();
filemax = m_registrysettings.GetRegistryCount( dirlocal );
filepos = 0;

stacklist.push( dirlocal );

while ( stacklist.size() > 0 )                // While stack not empty
    {
    filename = stacklist.top();		// Pop directory from stack

    stacklist.pop();

    tempbuf = filename;

    handle = opendir( tempbuf.data() );	// Begin extraction

    if ( handle )                     // Valid directory
	while ( (dirptr = readdir( handle ) ) != NULL )
		if ( dirptr->d_name[0] != '.' )
    			{
    			path = filename + "/" + dirptr->d_name;

   			stat( path.data(), &statbuf );

   			if ( statbuf.st_mode & S_IFDIR ) // Directory
				{
				stacklist.push( path );

    				if ( mode & CALLBACK_DIRECTORY )
					{
					//ReadExtensionFile( path, callback, filepos, filemax );        // Process Directory
					filepos++;

					callback.RegistryFileProgressCallback( 
						strrchr(path.data(), '/' )+1, 
						path.data(), filepos, filemax );
					}
		           	}
		    	else
				if ( statbuf.st_mode & S_IFREG )
						{
   			        	    	ReadExtensionFile( path, callback, filepos, filemax );        // Process Ordinary file
   	       			 	    	filepos++;
						callback.RegistryFileProgressCallback( 
						strrchr(path.data(), '/' )+1, 
						path.data(), filepos, filemax );
						}	
			}

	closedir( handle );
	}    
   
return( 1 );
}

// --------------------------------------------------------------------------
// Read the registry extensions that occur in the the new extensions list
//
// Inputs:  None
//
// Outputs: None
//
// Results: None
//
// Effects: The files in the local registry are read
//
// --------------------------------------------------------------------------
                                                                                
void CExtensionRegistrySettings::ReadNewExtensions( string &localdir, 
				CExtensionHeaderFileSet &fileset,
				CRegistryFileProgressCallback &callback )
{
int result;
string exbuf;
vector <CExtensionEntry>::iterator it;

for (it = fileset.m_newlist.begin(); it != fileset.m_newlist.end(); it++ )
	{
    	result = LoadLocalCache( it->m_name, localdir, exbuf );
                                                                                
	if ( result )
		{
		ReadExtensionBuffer( exbuf, callback, it->m_name,
							0, 0, fileset );
		}
    	}
}

// --------------------------------------------------------------------------
// Search extension specifications depending on selected mode
//
// Inputs: mode     - search mode flags
//         strdata  - string data
//         callback - the search callback
//
// Outputs: None
//
// Results: 1 
//
// Effects: The callback function is activated with each successful search 
//          find
// --------------------------------------------------------------------------

int CExtensionViewer::SearchExtensionSpecs( int mode, const string &strdata,
                CRegistryStringSearchCallback &callback )
{
for (int site = 0; site < GetSiteCount(); site++ )
	{
	SearchRegistry( site, strdata, callback, mode );
	}

return(1);
};

// --------------------------------------------------------------------------
// Scan through all the files in the registry and use the callback function
// to indicate the progress being made
//
// Inputs: site          - Which site to use
//         callback      - Reference to the callback function
//         selectionmode - Selection mode
//
// Outputs: None
//
// Results: The number of files and directories found
//
// Effects: The registry directory system is explored and a callback is made
//          for each extension specification
// --------------------------------------------------------------------------

int CExtensionViewer::SearchRegistry( int site, const string &strdata,
                CRegistryStringSearchCallback &callback, int mode )
{
int       filepos, filemax;
DIR *handle;
struct dirent *dirptr;
struct stat  statbuf;
CExtensionSiteInfo *psiteinfo;
string path, filename, tempbuf;
stack <string> stacklist;
string strdir;
int done = 0, matches = 0;

psiteinfo = GetSiteInfo( site );

strdir = psiteinfo->GetIndexdirlocal().data();

filemax = m_registrysettings.GetRegistryCount( strdir );
filepos = 0;

stacklist.push( strdir );

while ( stacklist.size() > 0 )               // While stack not empty
	{
	filename = stacklist.top();          // Pop directory from stack
	stacklist.pop();

	tempbuf = filename;

	handle = opendir( tempbuf.data() );  // Begin extraction

	if ( handle )                        // Valid directory
		{
		while ( !done && (dirptr = readdir( handle ) ) != NULL )
			{
                	if ( !done && (dirptr->d_name[0] != '.') )
                        	{
                        	path = filename + "/" + dirptr->d_name;

				memset( &statbuf, 0, sizeof(statbuf) );
                        	stat( path.data(), &statbuf );

                        	if ( statbuf.st_mode & S_IFDIR ) // Directory
                                	{
                                	stacklist.push( path );

                                	if ( mode & CALLBACK_DIRECTORY )
                                        	{
                                       		filepos++;
						done = callback.RegistryStringSearchProgressCallback( filepos, filemax );
                                        	}
                                	}
                        	else
					{
                                	if ( statbuf.st_mode & S_IFREG )
                                                {
                                                filepos++;
						done = callback.RegistryStringSearchProgressCallback( filepos, filemax );
						matches = RegistryFileStringSearch( path, site, strdata, callback, mode );

						if ( (0 < matches) && (mode & MODE_FIRSTMATCH) )
							{
							done++;
							}
                                                }
					}
                        	}
			}
		}

	closedir( handle );
	}

return( 1 );
}

// --------------------------------------------------------------------------
// Search a file for a particular string
//
// Inputs: path - The path to search
//         site - Which site
//         string - The string to search
//         callback - The callback to call
//         mode -  Optional mode flags
//
// Outputs: None
//
// Results: None
//
// Effects: The callback is called according to string matches
// --------------------------------------------------------------------------

int CExtensionViewer::RegistryFileStringSearch( const string &path,
		int site, const string &strsearch, 
                CRegistryStringSearchCallback &callback, int mode )
{
ifstream stream;
string filename,tempbuf, strdata, buffer;
stack <string> stacklist;
int done, linecount, matches, lenbuf;

strdata = strsearch;

buffer.reserve(1025);
linecount = 0;
done 	  = 0;
matches   = 0;

// Don't care about case, so make buffer lowercase
if (!(mode & MODE_MATCHCASE)) 
	{
	strlwr(strdata);
	}

// Open the file
stream.open( path.data() );

// Sanity check
if ( !stream.is_open() )
	{
	cout << "Error: Could not open file |" << path.data() << "|\n";
	return(0);
	}

// Read the file in line by line
while ( !stream.eof() && !done )
	{
	buffer[0] = '\0';
	// Get one line of text
	stream.getline( &buffer[0], 1024, '\n' );

	// Save the length
	lenbuf = stream.gcount();

	// No characters read in, so work is done
	if (lenbuf > 0 )
		{
		// Another line to process
		linecount++;

		// Don't care about case, so make buffer lowercase
		if  ( !(mode & MODE_MATCHCASE) )
			{
			strlwr( buffer);
			}

		// Perform match here. We only need strstr here, as we	
		// at most ever need one match per line
#ifdef DEBUG
cout << "Searching for |" << strdata.data() << "| in |" << buffer.data() << "|\n";
#endif
#ifdef DEBUG
cout << "Trying line: " << linecount << "\n";
#endif
		if ( strstr( buffer.data(), strdata.data() ) != 0 )
			{
#ifdef DEBUG
cout << "Match found at " << path.data() << "|" << linecount << "\n";
#endif

			matches++;

			// Match found, so update dialog window
			if ( !done )
				{
				done |= callback.RegistryStringSearchCallback( 
					site, linecount, path, buffer, mode );
				}

			// First match in file, so we're all done
			if ( (mode & MODE_ONEMATCHPERFILE) )
				{
				done++;		
				}
#ifdef DEBUG
cout << "Done #1 = " << done << "\n";
#endif
			}
		}
	else
		{
		done++;
#ifdef DEBUG
cout << "Done #2 = " << done << "\n";
#endif
		}
	}

stream.close();

return(matches);
}
