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

#ifdef DEBUG
cout << "ExtensionHeaderFileData::Init\n";  
#endif

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

#ifdef DEBUG
cout << "ExtNum = " << m_extlist.GetCount() << endl;
cout << "FuncNum = " << m_funclist.GetCount() << endl;
cout << "ConstNum = " << m_constlist.GetCount() << endl;
#endif                                                                                
for ( unsigned int pn = 0; pn < m_extlist.size(); pn++ )
	{
	if ( m_extlist.at(pn).EntryGetFlag( FLAG_OUTPUT ) )
		{
		m_selectednum++;
		m_selectedfuncnum += m_extlist.at(pn).m_funcnum;
		}
	}
     
#ifdef DEBUG
cout << "SelectedNum = " << m_selectednum << endl;
cout << "SelectedFuncNum = " << m_selectedfuncnum << endl;
#endif
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
#ifdef DEBUG
		cout << "Adding version |" << name << "|" << endl;
#endif
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
#ifdef DEBUG
cout << "Setting version |" << value << "|" << endl;
#endif
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
                                int filelen, CExtensionEntryList &vendorlist, int pextlen )
{
#ifdef DEBUG
	cout << "vvvvv ReadExtensionBlockHeader" << endl;
#endif

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
#ifdef DEBUG
cout << "Adding block |" << curline+8 << "|" << endl;
#endif
                m_extlist.Add( curline+8 );     // Add to list of extensions
                VendorListAdd(curline+8, vendorlist);// and list of vendors
		return true;
                }
        }

#ifdef DEBUG
	cout << "^^^^^ ReadExtensionBlockHeader" << endl;
#endif

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

// ----- Find the name of the extension to add ----------------------

if ( strstr( lastline, "#ifndef" ) != NULL )
	{
	char tempbuf[1024];

	sscanf( lastline, "#ifndef %s", tempbuf );

	m_extpos = m_extlist.FindName( tempbuf );

	if ( (m_extpos != -1) && (strstr(lastline,name)==NULL) )
		{
		m_extlist.ResetConstEntry( m_extpos, m_constlist.GetCount(), 0 );
		}
	else
                {
                m_extpos = -1;
                }
	}

// ----- Add constant name and value --------------------------------

if ( (strncmp( name, m_prefix.data(), pextlen ) == 0) && (m_extpos != -1) )
	{
#ifdef DEBUG
cout << "Adding constant + name: " << name << " " << constant << endl;
cout << "ConstList count = " << m_constlist.GetCount() << endl;
#endif
	m_constlist.AddNameValue( name, constant );
	m_extlist.IncrementConstNum( m_extpos );

#ifdef DEBUG
cout << "ExtListList count = " << m_extlist.GetCount() << endl;
#endif
	}
}

// --------------------------------------------------------------------------
// Search for list of OpenGL functions
// --------------------------------------------------------------------------

void CExtensionHeaderFileData::ReadFileFunctions( char *curline, char *lastline,char *name, std::ifstream &stream )
{
int done = 0, curext;
char *pfuncname, *pchptr;
std::string funcreturn, funcname, funcparams;

#ifdef DEBUG
cout << "vvvvv ReadFileFunctions" << endl;
#endif

curext = m_extlist.FindName( name );

if ( curext >= 0 )
	{
	m_extlist.ResetFuncEntry( curext, m_funclist.GetCount(), 0 );
	}

while ( !done )
	{
	stream.getline( curline, 1024 );

	if ( strncmp( curline, "#endif", 6 ) == 0 )  // End of block
                {
                done++;
                }
	else
                {
                funcreturn.clear();
                funcname.clear();
                funcparams.clear();

                pfuncname = strstr( curline, m_funcprefix.data() );

                if ( !pfuncname )
                        {
#ifdef DEBUG
                        cout << "|" << m_funcprefix.data() << "| not found\n";
#endif
                        }
                else
                        {
                        pchptr = curline;

                        while ( pchptr < pfuncname )
                                {
                                funcreturn += *pchptr++;
                                }

                        while ( isspace( *pchptr ) )
                                {
                                pchptr++;
                                }

                        pchptr = pfuncname;

                        while ( *pchptr && (*pchptr != '(') )
                                {
                                if ( !isspace( *pchptr ) )
                                        funcname += *pchptr;

                                pchptr++;
                                }

                        while ( isspace( *pchptr ) )
                                {
                                pchptr++;
                                }

                        while ( *pchptr && (*pchptr != ';') )
                                {
                                funcparams += *pchptr++;
                                }

#ifdef DEBUG
cout << "AddingPrefixNameValue |" << funcreturn.data() << "| |" <<
                        funcname.data() << "| |" <<
                        funcparams.data() << "| |\n";
#endif

                        m_funclist.AddPrefixNameValue(
                                funcreturn,
                                funcname,
                                funcparams );

#ifdef DEBUG
cout << "FuncListCount = " << m_funclist.GetCount() << "\n";
#endif

                        if ( curext >= 0 )
                                {
                                m_extlist.IncrementFuncNum( curext );

#ifdef DEBUG
cout << "ExtListFuncCount = " << m_extlist.GetCount() << "\n";
#endif
                                }
                        else
                                {
                          //      cout << "Error: No current extension\n";
                                }
                        }
                }
        }

#ifdef DEBUG
cout << "^^^^^ ReadFileFunctions" << endl;
#endif
}

void CExtensionHeaderFileData::ReadFileFunctionPrototypes( 
					char *curline, std::ifstream &stream )
{
int done = 0;
char *pchptr, *pchptrb, *pchptrc, *pchptrd;

while ( !done )          // Read list of function pointer macros
	{
	stream.getline( curline, 1024 );

//            int len = strlen( curline );
/*      
                if (len>0)
            curline[len] = 0;
*/
	pchptr = strstr( curline, "PFN" );

	if ( pchptr != NULL )           // Found a prototype
		{
		pchptrb = strchr( pchptr, ')' );
		*pchptrb = '\0';
                pchptrb++;

                pchptrc = strchr( pchptrb+1, '(' ); // Find the body

		if ( pchptrc )
			{
			pchptrd = strchr( pchptrc, ';' );

			if ( pchptrd )
				{
				*pchptrd = '\0';     // Now have a function definition

#ifdef DEBUG
cout << "Adding Function prototype |" << pchptr << "| |" << pchptrc << "|\n";
#endif

				m_funclist.AddProtoVars( pchptr, pchptrc );

#ifdef DEBUG
cout << "FuncList count = " << m_funclist.GetCount() << "\n";
#endif
				}
			}
		}
	else
		{
		if ( strncmp( curline, "#endif", 6 ) == 0 )
			{
			done++;
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
#ifdef DEBUG
cout << "CExtensionHeaderFileData:: Reading header file <"<< filename << ">\n" << endl;
#endif

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
#ifdef DEBUG
	cout << "CExtensionHeaderFileData:: Could not open stream for |" << filename << "|" << endl;
#endif
	return false;
	}

pextlen = m_prefix.length();
 
if ( callback.HeaderFileProgressCallback( filename, " ",
                  stream.tellg(), filelen ) )
	{
#ifdef DEBUG
	cout << "Cancelled\n";
#endif
        return false;
	}

#ifdef DEBUG
cout << "------< Header file start >-----------" << endl;
#endif

// --------------------------------------------------------------------------
// Main header reading loop
// --------------------------------------------------------------------------

while ( !stream.eof() )
	{
	strcpy( lastline, curline );

	stream.getline( curline, 1024 );

#ifdef DEBUG
	cout << "|" << curline << "|\n";
#endif
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
#ifdef DEBUG
		cout << "Cancelled\n";
#endif
                	return false;
                	}
		}

	// Read GL constants
#ifdef DEBUG
	cout << "Reading constants\n";
#endif

	ReadFileConstants( curline, lastline, name, pextlen );

	// Search for list of OpenGL functions
    	if ( strstr( curline, m_prototype.data() ) != NULL )
		{
#ifdef DEBUG
		cout << "Reading functions\n";
#endif
		// Read File Functions
		ReadFileFunctions( curline, lastline, name, stream );
#ifdef DEBUG
		cout << "Reading prototypes\n";
#endif
		// Read File Function Prototypes
		ReadFileFunctionPrototypes( curline, stream );
		}
    	}

#ifdef DEBUG
cout << "------< Header file finish >-----------\n";
#endif

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
