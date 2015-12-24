// ---------------------------------------------------------------------------
// Copyright: (C) VFX Research 2002 - 2014. All Rights Reserved.
// ---------------------------------------------------------------------------

#include "extensionlib.h"

// --------------------------------------------------------------------------
// Initialisation
// --------------------------------------------------------------------------

void CExtensionHeaderFileData::Init( void )
{
m_version = -1;

ctrace << "ExtensionHeaderFileData::Init" << std::endl;  

m_extlist.Allocate( MAX_EXTLIST );
m_funclist.Allocate( MAX_FUNCLIST );
m_constlist.Allocate( MAX_CONSTANTLIST );
}

// --------------------------------------------------------------------------
// Set general parameters
// --------------------------------------------------------------------------

void CExtensionHeaderFileData::SetParameters(const std::string &prefix, 
			const std::string &funcprefix, const std::string &prototype )
{
m_prefix = prefix;
m_funcprefix = funcprefix;
m_prototype = prototype;
}

// --------------------------------------------------------------------------
// Get name flag
// --------------------------------------------------------------------------

int CExtensionHeaderFileData::GetNameFlag( const std::string &name, int flag )
{
int index = m_extlist.FindName( name );

if ( index< 0 )
	{
	return 0;
	}
else
	{
	return m_extlist.GetIndexFlag( index, flag );
	}
}

// --------------------------------------------------------------------------
// Delete selected index
// --------------------------------------------------------------------------

void CExtensionHeaderFileData::DeleteIndex( int index )
{
int funcstart, funcnum, conststart, constnum;

m_extlist.at(index).EntryGetConstInfo( conststart, constnum );
m_extlist.at(index).EntryGetFuncInfo(  funcstart, funcnum );

m_constlist.DeleteRange( conststart, constnum );
m_funclist.DeleteRange( funcstart, funcnum );

m_extlist.DeleteIndex( index );
};

// --------------------------------------------------------------------------
// Delete selected name
// --------------------------------------------------------------------------

int CExtensionHeaderFileData::DeleteName( const std::string &name )
{
int extid = m_extlist.FindName( name );

if ( extid != -1 )
	{	
	DeleteIndex( extid );
	}

return extid;
};

// --------------------------------------------------------------------------
// Count Functions
// --------------------------------------------------------------------------

void CExtensionHeaderFileData::CountFunctions( void )
{
m_selectednum = 0;
m_selectedfuncnum = 0;

ctrace << "ExtNum = " << m_extlist.GetCount() << std::endl;
ctrace << "FuncNum = " << m_funclist.GetCount() << std::endl;
ctrace << "ConstNum = " << m_constlist.GetCount() << std::endl;

for ( unsigned int pn = 0; pn < m_extlist.size(); pn++ )
	{
	if ( m_extlist.at(pn).EntryGetFlag( FLAG_OUTPUT ) )
		{
		m_selectednum++;
		m_selectedfuncnum += m_extlist.at(pn).m_funcnum;
		}
	}
     
ctrace << "SelectedNum = " << m_selectednum << std::endl;
ctrace << "SelectedFuncNum = " << m_selectedfuncnum << std::endl;
}

// --------------------------------------------------------------------------
// Add std::string to vendor list
//
// Inputs: str - The std::string to add
//
// Outputs: None
//
// Results: None
//
// Effects: If the std::string is not already in the list, it is added
//          otherwise, it is ignored
// --------------------------------------------------------------------------

static const char str_version[] = "VERSION";

void CExtensionHeaderFileData::VendorListAdd( 
			const char *str, CExtensionEntryList &vendorlist )
{
std::string vendor;

if ( strncmp( str, str_version, 7 ) != 0 )
	{
	while ( !islower(*str) && (*str != '\0') && ( *str != ' '))
		{
        	vendor += *str++;
		}
                                                                                
	vendorlist.Add( vendor );
	}
}

// --------------------------------------------------------------------------
// Check to see if an extension has a valid name 
//
// Inputs:  chptr - Pointer to the std::string 
//
// Outputs: None
//
// Results: Non-zero if true, zero if not
//
// Effects: None 
// --------------------------------------------------------------------------
       
int CExtensionHeaderFileData::CheckValidExtension( const char *chptr )
{
int hasdigits, haslowercase, hasversion;
const char *pchtemp;

hasversion = ( strstr( chptr, str_version ) != NULL );

pchtemp = chptr;

haslowercase = 0;
hasdigits = 0;

while ( *pchtemp )
	{
	if ( isdigit( *pchtemp ) )	
		{
		hasdigits++;
		}

	if ( islower( *pchtemp ) )
		{
		haslowercase++;
		}
	
	pchtemp++;
	}

return hasversion | haslowercase | hasdigits;
}

// --------------------------------------------------------------------------
// Search for OpenGL Version std::strings
// --------------------------------------------------------------------------                                                                        
void CExtensionHeaderFileData::ReadVersion( char *curline, 
					CExtensionEntryList &versionlist )
{
if ( strstr( curline, "GL_VERSION" ) != NULL )
	{
        char name[1024];
        if ( sscanf( curline, "#ifndef GL_VERSION%s", name ) >= 1)
		{
		ctrace << "Adding version |" << name << "|" << std::endl;

        	versionlist.Add( name );
		}
        }
}

void CExtensionHeaderFileData::TerminateFirstNewLine( char *curline )
{
char *ptemp = curline;

while ( *ptemp != '\0' )
	{
	if ( *ptemp == '\n' || *ptemp == '\r' )
		{
		*ptemp = '\0';
		}

	ptemp++;
	}
}

// --------------------------------------------------------------------------
// Search for header file version
// --------------------------------------------------------------------------

void CExtensionHeaderFileData::ReadFileVersion( char *curline )
{
	char name[1024], *nptr;
	int value;

if ( strstr( curline, "EXT_VERSION" ) != NULL )
        {
        sscanf( curline, "#define %s %d", name, &value );

        nptr = name;

        if ( strncmp( m_prefix.data(), nptr, m_prefix.length() ) == 0 )
                {
		ctrace << "Setting version |" << value << "|" << std::endl;

                SetVersion( value );
                }
        }
}

// --------------------------------------------------------------------------
// Search for the beginning of an Extension block 
//
// Inputs: curline - Pointer to current line
//         filename - Current filename
//	   callback - Callback function
//         stream  - Input stream
//         filelen - File length
//         vendorlist - Vendor list
//         pextlen    - Length of extension header file in characters
//
// Outputs: curline - Pointer to current line
// 
// Results: Cancel flag

// Valid lines contain the std::string #ifndef XXXXXXXX
// The #ifndef is discarded by skipping 8 characters from the start
// --------------------------------------------------------------------------

int CExtensionHeaderFileData::ReadExtensionBlockHeader( char *curline, 
				const char *filename, 
  				CHeaderFileProgressCallback &callback,
				std::ifstream &stream, 
                                int filelen, 
				CExtensionEntryList &vendorlist, int pextlen )
{
if ( (strncmp( curline, "#ifndef", 7 ) == 0 ) &&       // Must be #ifndef
     (strncmp( m_prefix.data(), curline+8, pextlen ) == 0 ) )
	{
        // Problem with Nvidia GLX extension header file ...
        // NVidia do #ifndef's with the GLX_SGIX_pbuffer constants
        //
        // There are various conditions that can be checked:
        //
        // [1] Has digits               Yes   Accept
        // [2] Has "VERSION"            Yes 
        // [3] Has lowercase            Yes
        //
        // If the std::string has no digits or version or lowercase then reject

        if ( CheckValidExtension( curline+8 ) )
                {
		ctrace << "Adding block |" << curline+8 << "|" << std::endl;

                m_extlist.Add( curline+8 );     // Add to list of extensions
                VendorListAdd(curline+8, vendorlist);// and list of vendors

		m_extpos = m_extlist.size() - 1;	// Save extension ID

		m_extlist.ResetConstEntry( m_extpos, m_constlist.GetCount(), 0 );
		m_extlist.ResetFuncEntry( m_extpos, m_funclist.GetCount(), 0);
		return true;
                }
        }

return false;
}

// --------------------------------------------------------------------------
// Search for OpenGL constants
//
// Inputs: curline  - Current line
//         lastline - Last line
//         name     - Name
//
// --------------------------------------------------------------------------

void CExtensionHeaderFileData::ReadFileConstants( char *curline, 
				char *lastline, char *name, int pextlen)
{
char constant[1024];

if ( strncmp( curline, "#define", 7 ) != 0 )
	{
	return;
	}

sscanf( curline, "#define %s %s", name, constant);

// ----- Add constant name and value --------------------------------

if ( (strncmp( name, m_prefix.data(), pextlen ) == 0) && (m_extpos != -1) )
	{
	ctrace << "Adding constant + name: " << name << " " << constant << std::endl;
	ctrace << "ConstList count = " << m_constlist.GetCount() << std::endl;

	m_constlist.AddNameValue( name, constant );
	m_extlist.IncrementConstNum( m_extpos );

	ctrace << "ExtListList count = " << m_extlist.GetCount() << std::endl;
	}
}

// --------------------------------------------------------------------------
// Search for list of OpenGL functions
//
// These are in the form:
// GLAPI <return> APIENTRY gl/wgl/glx <funcname>( <parameters> );
// --------------------------------------------------------------------------

void CExtensionHeaderFileData::ReadFileFunctions( char *curline, char *lastline,char *name, std::ifstream &stream )
{
std::string funcreturn, funcname, funcparams;

funcreturn.clear();
funcname.clear();
funcparams.clear();

// Sanity check
char *pfuncname = strstr( curline, m_funcprefix.data() );

if ( !pfuncname )
	{
        ctrace << "|" << m_funcprefix.data() << "| not found" << std::endl;
	return;
        }

// Now pick apart the function name and parameters

char *pchptr = curline;

// The return type
while ( pchptr < pfuncname )
	{
	funcreturn += *pchptr++;
	}

while ( isspace( *pchptr ) )
	{
	pchptr++;
	}

// The function name
pchptr = pfuncname;

while ( *pchptr && (*pchptr != '(') )
	{
	if ( !isspace( *pchptr ) )
		{
		funcname += *pchptr;
		}

	pchptr++;
	}

unsigned int funcnumparams = 0;

while ( *pchptr != '(' )	// Skip over white space
	{
	pchptr++;
	}

funcparams += *pchptr++;		// Get the (

// The function parameters from ( to )
// Function parameters can be many possibilities:
//
// No arguments ( )
// One arguments( GLvoid xxx )
// Many aruments( GLvoid xxx, GLint yyy )

while ( *pchptr && (*pchptr != ')') )
	{
	int nletters = 0;

	while ((*pchptr != '\0') && (*pchptr != ')' ) && (*pchptr != ','))
		{
		if (isalnum(*pchptr))
			{
			nletters++;
			}

		funcparams += *pchptr++;
		}

	if (nletters > 0)
		{
		funcnumparams++;
		}

	if ((*pchptr != '\0') && *pchptr != ')')
		{
		funcparams += *pchptr++;
		}
	}

funcparams += *pchptr++;		// Get the )
	
ctrace << "AddingPrefixNameValue |" << 
	funcreturn.data() << "| |" <<
	funcname.data() << "| |" <<
	funcparams.data() << "| |" << funcnumparams << std::endl;

m_funclist.AddPrefixNameValue( funcreturn, funcname, funcparams, funcnumparams );

m_extlist.IncrementFuncNum( m_extpos );

ctrace << "FuncListCount = " << m_funclist.GetCount() << std::endl;
}

// --------------------------------------------------------------------------
// Read a function prototype
//
// This is in the form:
//
// typedef <return> (APIENTRYP PFN<FUNCPROCNAME> ( <parameters); 
//                             |                 |            |
//                             |                 |            |
//                             pchptr            pchptrc      pchptrb
//
// --------------------------------------------------------------------------

void CExtensionHeaderFileData::ReadFileFunctionPrototypes( 
					char *curline, std::ifstream &stream )
{
char *pchptr = strstr( curline, "PFN" );

if ( pchptr == NULL)		// No prototype found
	{
	return;
	}

char *pchptrb = strchr( pchptr, ')' );	// Find the end
*pchptrb = '\0';
pchptrb++;

char *pchptrc = strchr( pchptrb+1, '(' ); // Find the body

if ( pchptrc )
	{
	char *pchptrd = strchr( pchptrc, ';' );

	if ( pchptrd )
		{
		*pchptrd = '\0';     // Now have a function definition

		ctrace << "Adding Function PFN |" << pchptr << "| |" << pchptrc << "|" << std::endl;

		// Pushes data onto entry list
		m_funclist.AddProtoVars( pchptr, pchptrc );

		ctrace << "FuncList count = " << m_funclist.GetCount() << std::endl;
		int curext = m_extlist.size() - 1;

		if ( curext >= 0 )
        		{
        		m_extlist.IncrementFuncNum( curext );

        		ctrace << "ExtListFuncCount = " << m_extlist.GetCount() << std::endl;
        		}
		else
        		{
        		// This is serious. Need a known extension
        		// to add the function to.
        		ctrace << "Error: No current extension\n";
        		}
		}
	}
}

// --------------------------------------------------------------------------
// Read the OpenGL extensions file
//
// Inputs: fpin - Source file
//
// Outputs: None
//
// Results: Whether the 
//
// Effects: The OpenGL extensions file is analyzed and used to build a list
//          of extensions and functions
// --------------------------------------------------------------------------

int CExtensionHeaderFileData::ReadHeaderFile(const std::string &filename,
        CHeaderFileProgressCallback &callback,
        CExtensionEntryList &versionlist, 
	CExtensionEntryList &vendorlist )
{
char curline[2048];
char lastline[2048];
char name[1024];
struct stat statbuf;
int  pextlen, filelen;
       
std::ifstream stream;

std::string funcreturn, funcname, funcparams;                                                                                
ctrace << "CExtensionHeaderFileData:: Reading header file <"<< filename << ">" << std::endl;

curline[0] = '\0';

if ( filename[0] == '\0' )
	{
    	return false;
	}

stat( filename.data(), &statbuf );

filelen = statbuf.st_size;

stream.open( filename.data() );

if ( !stream.is_open() )
	{
	ctrace << "CExtensionHeaderFileData:: Could not open stream for |" << filename << "|" << std::endl;

	return false;
	}

pextlen = m_prefix.length();
 
if ( callback.HeaderFileProgressCallback( filename, " ",
                  stream.tellg(), filelen ) )
	{
	ctrace << "Cancelled" << std::endl;
        return false;
	}

ctrace << "------< Header file start >-----------" << std::endl;

// --------------------------------------------------------------------------
// Main header reading loop
// --------------------------------------------------------------------------

while ( !stream.eof() )
	{
	strcpy( lastline, curline );

	stream.getline( curline, 1024 );

	ctrace << "|" << curline << "|" << std::endl;

	// Search for GL versions
	ReadVersion( curline, versionlist );

	// Search for file version
	ReadFileVersion( curline );

	// Terminate first new line character
	TerminateFirstNewLine( curline );
	
	// Look for extension block header
	if ( ReadExtensionBlockHeader( curline, filename.data(), callback, stream, 
				filelen, vendorlist, pextlen ) )
		{
        	if (callback.HeaderFileProgressCallback(
                	filename.data(), curline+8, stream.tellg(), filelen ) )
                	{
			ctrace << "Cancelled" << std::endl;

                	return false;
                	}

		bool done = false;

		while (!done )
			{
			// Match GL constants
			// These are of the form
			// #define <const> <value>
			ctrace << "|" << curline << "|" << std::endl;

			if (strstr(curline, "#define" ) != NULL)
				{
				ctrace << "Constant" << std::endl;
				ReadFileConstants( curline, lastline, name, pextlen );
				}
#ifdef NEW_VERSION
			// Match function prototypes 
			if (strstr(curline, "PFN") != NULL)
				{
				ctrace << "Function Prototype" << std::endl;
				ReadFileFunctionPrototypes( curline, stream );
				}
#endif

			// Match OpenGL functions
			// These are of the form 
			// GLAPI void APIENTRYP <prefix><funcname>(<parameters>)j
			// Add a space here to match start of function name
			// and not some lucky word like angle or rectangle
			std::string strprefix = " " + m_funcprefix;

			if (( strstr(curline, strprefix.data() ) != NULL) &&
				(strstr( curline, "#define" ) == NULL) &&
				(strstr( curline, "#ifdef" ) == NULL) &&
				(strstr( curline, "#endif" ) == NULL) &&
				(strstr( curline, "/*" ) == NULL))
				{
				ctrace << "Function Definition" << std::endl;
				ReadFileFunctions( curline, lastline, name, stream );
				}

			// Finish this extension when end of #ifdef block
			// is reached
			if ((strstr(curline, "endif" ) != NULL) &&
			    (strstr(curline, m_extlist[m_extpos].m_name.data() ) != NULL))
				{
				done = true;
				}
			else
				{
				// Get another line
				memcpy(lastline, curline, 2048 );
				stream.getline( curline, 1024 );
				}
			}
		}
    	}

ctrace << "------< Header file finish >-----------" << std::endl;

// --------------------------------------------------------------------------
// Inform user of progress
// --------------------------------------------------------------------------

if ( callback.HeaderFileProgressCallback( filename, 
	(char *) " ",
	stream.tellg(), filelen ) )
	{
	return false;
	}

stream.close();

Sort();

return true;
}
