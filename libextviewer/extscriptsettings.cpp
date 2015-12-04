// ---------------------------------------------------------------------------
// Copyright: (C) VFX Research 2002 - 2014. All Rights Reserved.
// ---------------------------------------------------------------------------

using namespace std;

#include "extensionlib.h"
#include "extcode.h"

// --------------------------------------------------------------------------
// String used to avoid generating the PROC for the static GLX function
// --------------------------------------------------------------------------

static string str_glxarbgetprocaddress = "GLX_ARB_get_proc_address";

// --------------------------------------------------------------------------
// Main initialiser
//
// Inputs: None
//
// Outputs: None
//
// Results: None
//
// Effects: The object is initialised 
// --------------------------------------------------------------------------

void CExtensionScriptSettings::Init( void )
{
m_replacemode = MODE_REPLACE;
m_scriptmode = false;

m_scriptinternal = string(internalscript);	// Internal script
m_scriptinternalsize = m_scriptinternal.length();
m_scriptinternalpos = 0;

m_scriptexternalsize = 0;
m_scriptexternal.clear();
m_scriptexternalpos = 0;
m_scriptsize = 0;

m_callback = NULL;
m_nomacros =0;
m_ltime = 0;
m_extpos = 0;
m_funcpos = 0;
m_constpos = 0;
m_versionpos = 0;
m_registrypos = 0;
m_pos = 0;
m_fileheader = 0;
m_activegl = 0;
m_activewgl = 0;
m_activefunc = 0;
m_activeversion = 0;
m_activeconst = 0;
m_activeregistry = 0;
m_filename = NULL;

m_ltime = 0;
m_casemode = 0;

ScriptInitTokens();
ScriptCopyInternal();
ScriptParse();
}

// --------------------------------------------------------------------------
// Set filename
//
// Inputs: filename - Name of the file
//
// Otputs: None
//
// Results: None
// --------------------------------------------------------------------------

void CExtensionScriptSettings::ScriptSetFilename( const string &str)
{
if ( m_filename )
	{
	free(m_filename);
	}

m_filename = (char *) malloc( str.length() + 2 );

strcpy(m_filename, str.data() );
}

// --------------------------------------------------------------------------
// Initialise the list of tokens used by the script parsing algorithm
//
// Inputs: None
//
// Outputs: None
//
// Results: None
//
// Effects: The list of tokens used to parse script files is initialised
// --------------------------------------------------------------------------

void CExtensionScriptSettings::ScriptInitTokens( void )
{
// Subroutines

m_tokenlist.TokenAdd( "<call>",        TOKEN_COMMAND_CALL      );
m_tokenlist.TokenAdd( "<begin>",       TOKEN_COMMAND_BEGIN     ); 
m_tokenlist.TokenAdd( "</begin>",      TOKEN_COMMAND_UNBEGIN  ); 
m_tokenlist.TokenAdd( "<end>",         TOKEN_COMMAND_END       );
m_tokenlist.TokenAdd( "<else>",        TOKEN_COMMAND_ELSE      );
m_tokenlist.TokenAdd( "<fileopen>",    TOKEN_COMMAND_FILEOPEN  );
m_tokenlist.TokenAdd( "<fileclose>",   TOKEN_COMMAND_FILECLOSE );
m_tokenlist.TokenAdd( "<nomacros>",    TOKEN_COMMAND_NOMACROS  );
m_tokenlist.TokenAdd( "<uppercase>",   TOKEN_COMMAND_CASEUPPER );
m_tokenlist.TokenAdd( "<lowercase>",   TOKEN_COMMAND_CASELOWER );
m_tokenlist.TokenAdd( "<normalcase>",  TOKEN_COMMAND_CASENORMAL);
m_tokenlist.TokenAdd( "<if>",          TOKEN_COMMAND_IF );
m_tokenlist.TokenAdd( "<not>",         TOKEN_COMMAND_NOT );
m_tokenlist.TokenAdd( "<endif>",       TOKEN_COMMAND_ENDIF );
m_tokenlist.TokenAdd( "<exit>",        TOKEN_COMMAND_EXIT );
m_tokenlist.TokenAdd( "<foreach>",     TOKEN_COMMAND_FOREACH );
m_tokenlist.TokenAdd( "<endfor>",      TOKEN_COMMAND_ENDFOR );

// Iterators

m_tokenlist.TokenAdd( "<extfunclist>", TOKEN_ITERATOR_EXTFUNCLIST  ); 
m_tokenlist.TokenAdd( "<extconstlist>", TOKEN_ITERATOR_EXTCONSTLIST );
m_tokenlist.TokenAdd( "<glext>",       TOKEN_ITERATOR_GLEXT        );
m_tokenlist.TokenAdd( "<wglext>",      TOKEN_ITERATOR_WGLEXT       );
m_tokenlist.TokenAdd( "<glxext>",      TOKEN_ITERATOR_GLXEXT       );
m_tokenlist.TokenAdd( "<version>",     TOKEN_ITERATOR_VERSION      );
m_tokenlist.TokenAdd( "<extregistry>", TOKEN_ITERATOR_EXTREGISTRY  );

// Variables

m_tokenlist.TokenAdd( "<cppmode>",    TOKEN_VARIABLE_CPPMODE      ); 
m_tokenlist.TokenAdd( "<cmode>",      TOKEN_VARIABLE_CMODE      ); 
m_tokenlist.TokenAdd( "<selected>",   TOKEN_VARIABLE_SELECTED     );

m_tokenlist.TokenAdd( "<glnum>",      TOKEN_VARIABLE_GLNUM        );
m_tokenlist.TokenAdd( "<wglnum>",     TOKEN_VARIABLE_WGLNUM       );
m_tokenlist.TokenAdd( "<glxnum>",     TOKEN_VARIABLE_GLXNUM       );
m_tokenlist.TokenAdd( "<extnum>",     TOKEN_VARIABLE_EXTNUM       );

m_tokenlist.TokenAdd( "<funcnum>",    TOKEN_VARIABLE_FUNCNUM      );

m_tokenlist.TokenAdd( "<gldef>",      TOKEN_VARIABLE_GLDEF        );
m_tokenlist.TokenAdd( "<wgldef>",     TOKEN_VARIABLE_WGLDEF       );
m_tokenlist.TokenAdd( "<glxdef>",     TOKEN_VARIABLE_GLXDEF       );

m_tokenlist.TokenAdd( "<glfuncnum>",     TOKEN_VARIABLE_GLFUNCNUM    );
m_tokenlist.TokenAdd( "<wglfuncnum>",    TOKEN_VARIABLE_WGLFUNCNUM   );
m_tokenlist.TokenAdd( "<glxfuncnum>",    TOKEN_VARIABLE_GLXFUNCNUM   );

// Names

m_tokenlist.TokenAdd( "<funcname>",     TOKEN_STRING_FUNCNAME );
m_tokenlist.TokenAdd( "<extname>",      TOKEN_STRING_EXTNAME  ); 
m_tokenlist.TokenAdd( "<pfnproc>",      TOKEN_STRING_PFNPROC  );

m_tokenlist.TokenAdd( "<wglmax>",       TOKEN_STRING_WGLMAX  );
m_tokenlist.TokenAdd( "<glmax>",        TOKEN_STRING_GLMAX   );
m_tokenlist.TokenAdd( "<glxmax>",       TOKEN_STRING_GLXMAX  );
m_tokenlist.TokenAdd( "<funcmax>",      TOKEN_STRING_FUNCMAX );

m_tokenlist.TokenAdd( "<wglcounter>",   TOKEN_STRING_WGLCOUNTER   );
m_tokenlist.TokenAdd( "<glcounter>",    TOKEN_STRING_GLCOUNTER    );
m_tokenlist.TokenAdd( "<glxcounter>",   TOKEN_STRING_GLXCOUNTER   );
m_tokenlist.TokenAdd( "<funccounter>",  TOKEN_STRING_FUNCCOUNTER  );
m_tokenlist.TokenAdd( "<funcproto>",    TOKEN_STRING_FUNCPROTO    );
m_tokenlist.TokenAdd( "<funcprefix>",   TOKEN_STRING_FUNCPREFIX   );
m_tokenlist.TokenAdd( "<funcheader>",   TOKEN_STRING_FUNCHEADER   );
m_tokenlist.TokenAdd( "<extregistrycounter>", TOKEN_STRING_EXTREGISTRYCOUNTER );

m_tokenlist.TokenAdd( "<constmax>",     TOKEN_STRING_CONSTMAX );
m_tokenlist.TokenAdd( "<constname>",    TOKEN_STRING_CONSTNAME );
m_tokenlist.TokenAdd( "<constvalue>",   TOKEN_STRING_CONSTVALUE );
m_tokenlist.TokenAdd( "<constcounter>", TOKEN_STRING_CONSTCOUNTER );

m_tokenlist.TokenAdd( "<tab>",          TOKEN_STRING_TAB     );
m_tokenlist.TokenAdd( "<newline>",      TOKEN_STRING_NEWLINE );
m_tokenlist.TokenAdd( "\\t",            TOKEN_STRING_TAB     );
m_tokenlist.TokenAdd( "\t",             TOKEN_STRING_TAB     );
m_tokenlist.TokenAdd( "\n",             TOKEN_STRING_NEWLINE );
m_tokenlist.TokenAdd( "<quotes>",       TOKEN_STRING_QUOTES  );
m_tokenlist.TokenAdd( "\\\"",           TOKEN_STRING_QUOTES  );
m_tokenlist.TokenAdd( "<classname::>",  TOKEN_STRING_DCOLON  );

// File accesses

m_tokenlist.TokenAdd( "<moduletype>",   TOKEN_STRING_MODULETYPE   );
m_tokenlist.TokenAdd( "<prefix>",       TOKEN_STRING_PREFIX       );
m_tokenlist.TokenAdd( "<filetype>",     TOKEN_STRING_FILETYPE     );
m_tokenlist.TokenAdd( "<classname>",    TOKEN_STRING_CLASSNAME );
m_tokenlist.TokenAdd( "<filename>",     TOKEN_STRING_FILENAME  ); 

// Filenames

m_tokenlist.TokenAdd( "<outputheader>", TOKEN_STRING_OUTPUTHEADER  ); 
m_tokenlist.TokenAdd( "<outputsource>", TOKEN_STRING_OUTPUTSOURCE  );
m_tokenlist.TokenAdd( "<wglheader>",    TOKEN_STRING_WGLHEADER );
m_tokenlist.TokenAdd( "<glxheader>",    TOKEN_STRING_GLXHEADER );
m_tokenlist.TokenAdd( "<glheader>",     TOKEN_STRING_GLHEADER  );
m_tokenlist.TokenAdd( "<configfile>",   TOKEN_STRING_CONFIGFILE    );
m_tokenlist.TokenAdd( "<scriptfile>",   TOKEN_STRING_SCRIPTFILE    );
m_tokenlist.TokenAdd( "<filepath>",     TOKEN_STRING_PATH          );

// File versions

m_tokenlist.TokenAdd( "<wglversion>",   TOKEN_STRING_WGLVERSION   ); 
m_tokenlist.TokenAdd( "<glversion>",    TOKEN_STRING_GLVERSION    );
m_tokenlist.TokenAdd( "<glxversion>",    TOKEN_STRING_GLXVERSION  );

// System configuration

m_tokenlist.TokenAdd( "<time>",         TOKEN_STRING_TIME         );  
m_tokenlist.TokenAdd( "<hostname>",     TOKEN_STRING_HOSTNAME     );
m_tokenlist.TokenAdd( "<username>",     TOKEN_STRING_USERNAME     );

m_tokenlist.TokenAdd( "<versionvar>",   TOKEN_STRING_VERSIONVAR   );
m_tokenlist.TokenAdd( "<versionname>",  TOKEN_STRING_VERSIONNAME  );
m_tokenlist.TokenAdd( "<versionnumber>", TOKEN_STRING_VERSIONNUMBERS );
}

// ==========================================================================
// PROCESSING FOR THE SCRIPT FILES
// ==========================================================================

// --------------------------------------------------------------------------
// Import external script file
//
// Inputs; pstring - String of the path
//
// Outputs: None
//
// Results: None
//
// Effects: The external script file
// --------------------------------------------------------------------------

void CExtensionScriptSettings::ScriptSetExternal( const string &path )
{
if ( path.length() > 0 )
	{
	m_scriptexternal = path;
	m_scriptexternalsize = m_scriptexternal.length();
	}
}

// --------------------------------------------------------------------------
// Read script file
//
// Inputs: path - Source path
//
// Outputs: None
//
// Results: 0 if file could not be read, 1 if file was read successfully
//
// Effects: The file is read in and parsed
// --------------------------------------------------------------------------

int CExtensionScriptSettings::ScriptReadExternal( const string &path )
{
struct stat buf;
ifstream stream;

stream.open( path.data(), ios::binary );

if ( stream.is_open() )
	{
	stat( path.data(), &buf );

	m_scriptexternalsize = buf.st_size+1;
	m_scriptexternal = new char[buf.st_size+1];
	
	m_scriptexternal.reserve(buf.st_size+1);
	stream.read( &m_scriptexternal[0], buf.st_size );
	m_scriptexternal[buf.st_size] = '\0';	
	stream.close();
	}
return(1);
}

// --------------------------------------------------------------------------
// Write script file
//
// Inputs: path - Source path
//
// Outputs: None
//
// Results: 0 if file could not be read, 1 if file was read successfully
//
// Effects: The file is read in and parsed
// --------------------------------------------------------------------------

int CExtensionScriptSettings::ScriptWrite( const string &path, int which )
{
const char *pscript = NULL;
int scriptlen = 0;

ofstream stream;

switch ( which )
	{
	case SCRIPT_INTERNAL:
		scriptlen = m_scriptinternalsize;
		pscript = m_scriptinternal.data();
		break;

	case SCRIPT_EXTERNAL:
		scriptlen = m_scriptexternalsize;
		pscript = m_scriptexternal.data();
		break;

	default:
		break;
	}
	
if ( scriptlen <= 0)
	{
	return( 0 );
	}

stream.open( path.data() );

if ( stream.is_open() )
	{
	stream.write( pscript, scriptlen );

	stream.close();
	}

return( 1 );
}

// --------------------------------------------------------------------------
// Copy the internal script
// --------------------------------------------------------------------------

void CExtensionScriptSettings::ScriptCopyInternal( void )
{
	m_scriptexternal = m_scriptinternal;
}

// --------------------------------------------------------------------------
// Parse the script
// --------------------------------------------------------------------------

void CExtensionScriptSettings::ScriptParse( void )
{
if ( m_scriptmode )
	{
   	ScriptParse( m_scriptexternal.data(), m_scriptexternalsize );
	}
else
	{
    	ScriptParse( m_scriptinternal.data(), m_scriptinternalsize );
	}
}
    
// --------------------------------------------------------------------------
// Parse a single token of the script
//
// Inputs:  pstart - First character in unparsed string
//          pend   - Last character in unparsed string
//
// Outputs: scrtoken - processed Script token
// 
// Results: New position in script file
//
// Effects: None 
// --------------------------------------------------------------------------

const char *CExtensionScriptSettings::ScriptReadToken(
				const char *pstart, const char *pend, 
				   CScriptToken &scrtoken )
{
const char *pstr;
int   done, strlen;
char  strbuf[1024];
CToken *ptoken;

pstr = pstart;
done = false;       // 0.  Done = false
strlen = 0;

while ( !done && (pstr<pend) ) // 1.  While ( !Done And (pbuffer<pend)
	{                 // 2. Check if current pointer matches a token
	ptoken = m_tokenlist.TokenFind( pstr );

        if ( ptoken == NULL )     // 3. If no match then
            {
            if ( *pstr == '\r' )        
                {       
                if ( strlen > 0 )
                    {
					// 7.   returntoken   = string
                    scrtoken.m_tokenid = TOKEN_STRING_STRING; 
                    scrtoken.m_strlen  = strlen;
                    scrtoken.m_pstrbuf = new char[strlen+2];
                    strbuf[strlen]     = '\0';

                    strncpy( scrtoken.m_pstrbuf, strbuf, strlen+1 );      
                    done++;
                    }
    
                pstr++;
                }        
            else
                strbuf[strlen++] = *pstr++;  // Add character to string
            }
        else        
            {
            if ( strlen > 0 )   //   Return string first
                {               //      returnpointer = curptr
				// 7.   returntoken   = string
                scrtoken.m_tokenid = TOKEN_STRING_STRING; 
                scrtoken.m_strlen  = strlen;
                scrtoken.m_pstrbuf = new char[strlen+2];
                strbuf[strlen]     = '\0';

                strncpy( scrtoken.m_pstrbuf, strbuf, strlen+1 );        
                done =true;
                }
            else     
                {
                scrtoken.m_tokenid = ptoken->m_tokenid;
                scrtoken.m_strlen  = 0;
                scrtoken.m_pstrbuf = NULL;
                      
                pstr += ptoken->m_name.size();   // Skip over token    
                done = true;
                } 
            }
        }  

return( pstr );  
} 

// --------------------------------------------------------------------------
// Parse the selected text file
//
// Inputs: pbuffer - Character pointer to the buffer
//         plen    - Length of the buffer
//
// Outputs: None
//
// Results: None
//
// Effects: The script file is parsed and placed into local storage
// --------------------------------------------------------------------------

void CExtensionScriptSettings::ScriptParse( const char *pbuffer, int plen )
{
CScriptToken stoken;
const char *pstart, *pend;
unsigned int pn;

pstart = pbuffer;
pend   = pstart + plen;

m_script.Deallocate();
m_script.Allocate(4000);

m_prefunclist.Init();

if ( pstart == NULL )
    return;

// ----- Stage 1: Convert the entire script into tokens ---------------------

while ( pstart < pend )
    {
    pstart = ScriptReadToken( pstart, pend, stoken );

    m_script.AddToken( stoken );
    }

// ----- Stage 2: For every begin statement preceded by a string name
//                add the name onto the function list

for ( pn = 0; pn < m_script.m_tokennum-1; pn++ )
	{
    	if ( (m_script.m_tokenlist[pn].m_tokenid == TOKEN_COMMAND_BEGIN) &&
             (m_script.m_tokenlist[pn+1].m_tokenid == TOKEN_STRING_STRING) )
       		{
		int templen;
		char tempbuf[128];

        	ExtractVariable( 
			(const char *) m_script.m_tokenlist[pn+1].m_pstrbuf, 
			(char *) tempbuf, templen );

        	m_prefunclist.AddList( tempbuf, pn );
        	}
	}
}

// --------------------------------------------------------------------------
// Dump the contents of the script file to the selected file
//
// Inputs:  pdumpfile - Pointer to the ASCII file pointer
//
// Outputs: None
//
// Results: None
//
// Effects: The contents of the tokenised script are saved to disk
// --------------------------------------------------------------------------

void CExtensionScriptSettings::ScriptDump( const string &strdump )
{
CScriptToken *pstoken;
CToken *ptoken;
unsigned int pn;
ofstream stream;

stream.open( strdump.data() );

if ( stream.is_open() )
	{
	for ( pn = 0; pn < m_script.m_tokennum; pn++ )
		{
		pstoken = m_script.m_tokenlist+pn;

		stream << "(" << pn << ") ";

		if ( pstoken->m_tokenid == TOKEN_STRING_STRING )
			{
			stream << "<STRING> " << pstoken->m_pstrbuf << endl;
			}
		else
			{
			ptoken = m_tokenlist.TokenFind( pstoken->m_tokenid );

			stream << "<TOKEN>  " << ptoken->m_name << endl;	
			}
		}

	stream.close();
	}
}

// ==========================================================================
// FILE GENERATION
// ==========================================================================

static STRNAME moduletype[2] = 
{
"module",
"class"
};

// --------------------------------------------------------------------------
// Find the opposite <endif> to the <if> statement at the current location
//
// Inputs: curaddr - Index of the first instruction to process
//
// Outputs: None
//
// Results: The index of the matching <endif> statement, -1 if no match
//          found
// 
// Effects: None
// --------------------------------------------------------------------------

int CExtensionScriptSettings::ScriptFindElse( int curaddr )
{
CScriptToken *pstoken;
int ifcount, done;
                                                                                
done = 0;
ifcount = 0;
                                                                                
while ( !done )
        {
        pstoken = m_script.m_tokenlist+curaddr;
                                                                                
        if ( pstoken->m_tokenid == TOKEN_COMMAND_IF )
		{
                ifcount++;
		}
                                                                                
        if ( pstoken->m_tokenid == TOKEN_COMMAND_ELSE )
		{
                ifcount--;
		}
                             
	if ( pstoken->m_tokenid == TOKEN_COMMAND_ENDIF )
		{
		ifcount--;
		}
                                                   
        if ( ifcount == 0 )
		{
                done++;
		}
        else
		{
                curaddr++;
		}
        }
                                                                                
return( curaddr );
}

int CExtensionScriptSettings::ScriptFindEndif( int curaddr )
{
CScriptToken *pstoken;
int ifcount, done;

done = 0;
ifcount = 0;

while ( !done )
	{
	pstoken = m_script.m_tokenlist+curaddr;

	if ( pstoken->m_tokenid == TOKEN_COMMAND_IF )
		{
		ifcount++;
		}

	if ( pstoken->m_tokenid == TOKEN_COMMAND_ENDIF )
		{
		ifcount--;
		}

        if ( pstoken->m_tokenid == TOKEN_COMMAND_ELSE )
		{
                ifcount--;
		}

	if ( ifcount == 0 )
		{
		done++;
		}
	else
		{
		curaddr++;
		}
	}

return( curaddr );
}

int CExtensionScriptSettings::ScriptFindEnd( int curaddr )
{
CScriptToken *pstoken;
int ifcount, done;
                                                                                
done = 0;
ifcount = 0;
                                                                                
while ( !done )
        {
        pstoken = m_script.m_tokenlist+curaddr;
                                                                                
        if ( pstoken->m_tokenid == TOKEN_COMMAND_BEGIN )
		{
                ifcount++;
		}
                                                                                
        if ( pstoken->m_tokenid == TOKEN_COMMAND_END )
		{
                ifcount--;
		}
                                                                                
        if ( ifcount == 0 )
		{
                done++;
		}
        else
		{
                curaddr++;
		}
        }
                                                                                
return( curaddr );
}

int CExtensionScriptSettings::ScriptFindEndfor( int curaddr )
{
CScriptToken *pstoken;
int ifcount, done;
                                                                                
done = 0;
ifcount = 0;
                                                                                
while ( !done )
        {
        pstoken = m_script.m_tokenlist+curaddr;
                                                                                
        if ( pstoken->m_tokenid == TOKEN_COMMAND_FOREACH )
		{
                ifcount++;
		}
                                                                                
        if ( pstoken->m_tokenid == TOKEN_COMMAND_ENDFOR )
		{
                ifcount--;
		}
                                                                                
        if ( ifcount == 0 )
		{
                done++;
		}
        else
		{
                curaddr++;
		}
        }
                                                                                
return( curaddr );
}

// --------------------------------------------------------------------------
// Process the script token list for external files
//
// Inputs:  curaddr    - Index of the first instruction to process
//          finishaddr - Index of the last instruction to process
//
// Outputs: None
//
// Results: None
//
// Effects: None
// --------------------------------------------------------------------------

void CExtensionViewer::DebugLevel0( CScriptToken *pstoken,
					 int curaddr, int lastaddr )
{
CToken *ptoken = m_scriptsettings.m_tokenlist.TokenFind( pstoken->m_tokenid );

cout << "Position = " << curaddr << ", Last = " << lastaddr << "\n";

if ( ptoken != NULL )
	{
	cout << "Token = " << ptoken->m_name  << "\n";
	}
else
	{
	cout << "Token = <STRING> |"<<pstoken->m_pstrbuf <<"|\n";
	}

cout << endl;
}

int CExtensionViewer::ProcessScript( int curaddr, int finishaddr )
{
int done, lastaddr;
CScriptToken *pstoken;
CScriptToken **ppstoken;

lastaddr = finishaddr;

done   = false;

ppstoken = &pstoken;

while ( !done )
	{
	if (m_scriptsettings.m_funcdepth==0)
		{
		m_scriptsettings.m_callback->GenerateProgressCallback(
            		m_scriptsettings.m_fileheader, curaddr, finishaddr );
		}

	(*ppstoken) = m_scriptsettings.m_script.m_tokenlist+curaddr;

#ifdef DEBUG
	DebugLevel0( *ppstoken, curaddr, lastaddr );
#endif

	if ( curaddr == lastaddr )
		{
		done++;
		}
	else
		{
		done = ProcessScriptToken( curaddr, lastaddr, ppstoken );
		}
	} // while

// By here, we have jumped out of the while loop and reached the last command

if ( (m_scriptsettings.m_funcdepth == 0) &&
     m_scriptsettings.m_outputstream.is_open() )
    {
    m_scriptsettings.m_outputstream.close();
    }

return( curaddr );
}

// --------------------------------------------------------------------------
// Process invididual script tokens
// --------------------------------------------------------------------------

int CExtensionViewer::ProcessScriptToken( int &curaddr, int &lastaddr,
					CScriptToken **pstoken )
{
int len, version, finishaddr;
char tempbuf[1024];
CExtensionSiteInfo *psiteinfo;
string outstr;
int done = 0;

/*
printf( "Processing token |%04X| %s\n", (*pstoken)->m_tokenid,
					(*pstoken)->m_pstrbuf );
*/
switch ( (*pstoken)->m_tokenid )
	{
	// ===== FILE ACCESS ================================================

	case TOKEN_COMMAND_FILEOPEN:
#ifdef DEBUG
cout << "Token: Command - fileopen";
#endif
		curaddr++;
		(*pstoken)++;
	
		if ( m_scriptsettings.m_outputstream.is_open() )
			{
			m_scriptsettings.m_outputstream.close();
			}
 
		if ( (*pstoken)->m_tokenid == TOKEN_STRING_OUTPUTHEADER )
			{
#ifdef DEBUG
cout << "(header file" << 
			m_outputfilesettings.m_outputheaderfile.data() << ")\n";
#endif

			m_scriptsettings.m_outputstream.open( 
				m_outputfilesettings.m_outputheaderfile.data() );

			m_scriptsettings.ScriptSetFilename( m_outputfilesettings.m_outputheaderfile );

			m_scriptsettings.m_fileheader = 1;
			}
       		else
		if ( (*pstoken)->m_tokenid == TOKEN_STRING_OUTPUTSOURCE )
			{
#ifdef DEBUG
cout << "(source file" << 
			m_outputfilesettings.m_outputsourcefile.data() << ")\n";
#endif
			m_scriptsettings.m_outputstream.open( 
				m_outputfilesettings.m_outputsourcefile.data() );

			m_scriptsettings.ScriptSetFilename( m_outputfilesettings.m_outputsourcefile );

			m_scriptsettings.m_fileheader = 0;
           		}
       	break;

	case TOKEN_COMMAND_FILECLOSE:
		if ( m_scriptsettings.m_outputstream.is_open() )
			{
#ifdef DEBUG
cout << "Token: Command - fileclose" << endl;
#endif
			m_scriptsettings.m_outputstream.close();
			}

       	break;

	case TOKEN_COMMAND_CALL:     
		curaddr++;     // Increment to get variable
		(*pstoken)++;

		{
		char tempbuf[1024];
		int funcid;

		m_scriptsettings.ExtractVariable( 
			(*pstoken)->m_pstrbuf, tempbuf, len );

#ifdef DEBUG
cout << "Token: Command - call" << tempbuf << endl;
#endif
		m_scriptsettings.m_funccuraddr[m_scriptsettings.m_funcdepth] = curaddr;
		m_scriptsettings.m_funclastaddr[m_scriptsettings.m_funcdepth] = lastaddr;
		m_scriptsettings.m_funcdepth++;

		funcid = m_scriptsettings.m_prefunclist.FindName( tempbuf );

		if ( funcid == -1 )
			{
        		cerr << "Error: Could not find first script function\n";
			}
		else
       			{
        // ----- Estimate how many stages are required ----------------------
                                                                                
       			curaddr = m_scriptsettings.m_prefunclist.m_prefunclist[funcid].m_funcaddr;

			lastaddr = m_scriptsettings.ScriptFindEnd( curaddr );
                                                                                
       			ProcessScript( curaddr+2, lastaddr );
       			}
               	}                                                                 
		m_scriptsettings.m_funcdepth--;

		curaddr  = m_scriptsettings.m_funccuraddr[m_scriptsettings.m_funcdepth];
		lastaddr = m_scriptsettings.m_funclastaddr[m_scriptsettings.m_funcdepth];

#ifdef DEBUG
cout << "Token: Command - call done\n";
#endif
		outstr.clear();
		break;

       // ===== FUNCTION BLOCK DEFINITIONS =================================

	case TOKEN_COMMAND_BEGIN:
		curaddr++;      // Skip over begin
		(*pstoken)++;
		m_scriptsettings.ExtractVariable( (*pstoken)->m_pstrbuf, tempbuf, len );    
		outstr.clear();
		break;

	case TOKEN_COMMAND_UNBEGIN:
		break;

	case TOKEN_COMMAND_END:
		done++;
       		break;
       
	case TOKEN_COMMAND_EXIT:
		exit(0);
		break;
 
        // ===== MACRO CONTROL ==============================================

	case TOKEN_COMMAND_NOMACROS:
		m_scriptsettings.m_nomacros = true;
		break;

	case TOKEN_COMMAND_CASENORMAL:
		m_scriptsettings.m_casemode = MODE_CASENORMAL;
		break;

	case TOKEN_COMMAND_CASEUPPER:
		m_scriptsettings.m_casemode = MODE_CASEUPPER;
		break;

	case TOKEN_COMMAND_CASELOWER:
		m_scriptsettings.m_casemode = MODE_CASELOWER;
		break;

	case TOKEN_COMMAND_FOREACH:
		// Really, a dummy command
	    break;

        // ===== ITERATORS ==================================================

	case TOKEN_ITERATOR_GLEXT:          
		if ( !m_scriptsettings.m_activegl && 
			!m_scriptsettings.m_activewgl && 
			!m_scriptsettings.m_activeglx )
			{
			m_scriptsettings.m_pextentry = &
				m_headerfileset.m_gllist.m_extlist.at(0);

			m_scriptsettings.m_pcurfunclist = 
				&m_headerfileset.m_gllist.m_funclist;

			m_scriptsettings.m_extmode   = MODE_GL;    
			m_scriptsettings.m_activegl  = true;

			finishaddr = m_scriptsettings.ScriptFindEndfor( curaddr-1 );

			for ( m_scriptsettings.m_pos = 0; 
				m_scriptsettings.m_pos < 	
				m_headerfileset.m_gllist.m_extlist.size(); 
				m_scriptsettings.m_pos++, m_scriptsettings.m_pextentry++ )
				{
				ProcessScript( curaddr+1, finishaddr );
            	}
       
			m_scriptsettings.m_activegl = false;

			curaddr = finishaddr;
            }
		break;

	case TOKEN_ITERATOR_WGLEXT:      
		if ( !m_scriptsettings.m_activewgl && 
			!m_scriptsettings.m_activegl && 
			!m_scriptsettings.m_activeglx )
			{ 
			m_scriptsettings.m_pextentry = &
				m_headerfileset.m_wgllist.m_extlist.at(0);

			m_scriptsettings.m_pcurfunclist = 
				&m_headerfileset.m_wgllist.m_funclist;

			m_scriptsettings.m_extmode   = MODE_WGL;
			m_scriptsettings.m_activewgl = true;

			finishaddr = m_scriptsettings.ScriptFindEndfor( curaddr-1 );

			for ( m_scriptsettings.m_pos = 0;
					m_scriptsettings.m_pos < 
					m_headerfileset.m_wgllist.m_extlist.size(); 
				m_scriptsettings.m_pos++, m_scriptsettings.m_pextentry++ )
				{
				ProcessScript( curaddr+1, finishaddr );            
                }    

			m_scriptsettings.m_activewgl = false;              

			curaddr = finishaddr;
			}
		break;

	case TOKEN_ITERATOR_GLXEXT:      
		if ( !m_scriptsettings.m_activewgl && 
			!m_scriptsettings.m_activegl && 
			!m_scriptsettings.m_activeglx )
			{ 
			m_scriptsettings.m_pextentry = &
				m_headerfileset.m_glxlist.m_extlist.at(0);

			m_scriptsettings.m_pcurfunclist = 
				&m_headerfileset.m_glxlist.m_funclist;

			m_scriptsettings.m_extmode   = MODE_GLX;
			m_scriptsettings.m_activeglx = true;

			finishaddr = m_scriptsettings.ScriptFindEndfor( curaddr-1 );

			for ( m_scriptsettings.m_pos = 0; 
				m_scriptsettings.m_pos < 
				m_headerfileset.m_glxlist.m_extlist.size(); 
				m_scriptsettings.m_pos++, m_scriptsettings.m_pextentry++ )
				{
				bool active = true;

				if ( m_headerfileset.m_glxlist.m_extlist[m_scriptsettings.m_pos].m_name == str_glxarbgetprocaddress )
					{
					active = m_outputfilesettings.m_useglxgetprocaddressARB;
					}

				if ( active )
					{
					ProcessScript( curaddr+1, finishaddr );            
					}
				}

			m_scriptsettings.m_activeglx = false;              

			curaddr = finishaddr;
			}
		break;

	case TOKEN_ITERATOR_VERSION:
		if ( !m_scriptsettings.m_activeversion )
			{
			m_scriptsettings.m_activeversion = true;

			finishaddr = m_scriptsettings.ScriptFindEndfor( curaddr-1 );

			for ( m_scriptsettings.m_versionpos = 0; 
					m_scriptsettings.m_versionpos < 
						m_headerfileset.m_versionlist.size(); 
					m_scriptsettings.m_versionpos++ )
				{
				ProcessScript( curaddr+1, finishaddr );
                		}    

			m_scriptsettings.m_activeversion = false;
			curaddr = finishaddr;
			}
		break;

	case TOKEN_ITERATOR_EXTFUNCLIST:
		if ( !m_scriptsettings.m_activefunc )
			{
			m_scriptsettings.m_activefunc = true;

			finishaddr = m_scriptsettings.ScriptFindEndfor( curaddr-1 );

			for ( m_scriptsettings.m_funcpos = 0; 
					m_scriptsettings.m_funcpos < 
					m_scriptsettings.m_pextentry->m_funcnum; 
					m_scriptsettings.m_funcpos++ )
				{
				ProcessScript( curaddr+1, finishaddr );
               	} 

			m_scriptsettings.m_activefunc = false;
			curaddr = finishaddr;
			}           
		break;

	case TOKEN_ITERATOR_EXTCONSTLIST:
		if ( !m_scriptsettings.m_activeconst )
			{
			m_scriptsettings.m_activeconst = true;

			finishaddr = m_scriptsettings.ScriptFindEndfor( curaddr-1 );
            
			for ( m_scriptsettings.m_constpos = 0; 
				m_scriptsettings.m_constpos < 
				m_scriptsettings.m_pextentry->m_constnum; 
				m_scriptsettings.m_constpos++ )
				{
				ProcessScript( curaddr+1, finishaddr );
				}

			m_scriptsettings.m_activeconst = false;
			curaddr = finishaddr;
			}
		break;

	case TOKEN_ITERATOR_EXTREGISTRY:
		if ( !m_scriptsettings.m_activeregistry )
			{
			m_scriptsettings.m_activeregistry = true;

			finishaddr = m_scriptsettings.ScriptFindEndfor( curaddr-1 );

			for ( m_scriptsettings.m_registrypos = 0; 
				m_scriptsettings.m_registrypos < GetSiteCount();
				m_scriptsettings.m_registrypos++ )
				{
	  	    	ProcessScript( curaddr+1, finishaddr );
				}

			m_scriptsettings.m_activeregistry = false;
			curaddr = finishaddr;
			}
	    break;

	// ===== OUTPUT STRINGS =============================================

	case TOKEN_STRING_STRING:
		outstr = (*pstoken)->m_pstrbuf;
//		strncpy( outbuf, (*pstoken)->m_pstrbuf, 1023 );
		break;

	// For C++, m_classnamedcolon is "ExtensionManager::"
	// For C    m_classname is an empty string

	case TOKEN_STRING_DCOLON:	
		outstr = m_outputfilesettings.m_classnamedcolon.data();
		break;

	case TOKEN_STRING_CLASSNAME:  
		outstr = m_outputfilesettings.m_classname.data();
		break;

	case TOKEN_STRING_EXTNAME:   
		outstr = m_scriptsettings.m_pextentry->m_name.data();
		break;

	case TOKEN_STRING_OUTPUTHEADER:
		outstr = m_outputfilesettings.m_outputheaderfile.data();
		break;

	case TOKEN_STRING_OUTPUTSOURCE:
		outstr = m_outputfilesettings.m_outputsourcefile.data();
		break;

	case TOKEN_STRING_WGLVERSION: 
		version = m_headerfileset.m_wgllist.GetVersion();

		if ( version == -1 )
			{
			outstr = "unknown";
			}
		else
			{
			stl_itoa( outstr, version);
			}
		break;

	case TOKEN_STRING_GLVERSION:
		version = m_headerfileset.m_gllist.GetVersion();

		if ( version == -1 )
			{
			outstr = "unknown";	
			}
		else
			{
			stl_itoa(  outstr, version );
			}
		break;

	case TOKEN_STRING_GLXVERSION:
	    version = m_headerfileset.m_glxlist.GetVersion();

	    if ( version == -1 )
			{
			outstr = "unknown";
			}
		else
			{
			stl_itoa( outstr, version );
			}
	    break;

	case TOKEN_STRING_TIME:  
		time( &m_scriptsettings.m_ltime );

		outstr = ctime( &m_scriptsettings.m_ltime );
		outstr.erase( outstr.length()-1 );
		break;

	case TOKEN_STRING_MODULETYPE: 
		outstr = moduletype[ m_outputfilesettings.m_cppmode];
		break;

	case TOKEN_STRING_PREFIX: 
	    switch ( m_scriptsettings.m_extmode )
			{
			case MODE_GL:
				outstr = "GL";
				break;

			case MODE_GLX:
				outstr = "GLX";
				break;
	
			case MODE_WGL:
				outstr = "WGL";
				break;

			default:
				break;
			}
		break;

	case TOKEN_STRING_FILETYPE:    
		if ( strncmp( m_scriptsettings.m_filename+strlen(
				m_scriptsettings.m_filename)-2, ".h", 2 ) == 0 )
			{
			outstr = "Header";
			}
		else
			{
			outstr = "Source";
			}
		break;

	case TOKEN_STRING_GLMAX:
		stl_itoa( outstr, m_headerfileset.m_gllist.m_extlist.size() );
		break;

	case TOKEN_STRING_WGLMAX:
		stl_itoa( outstr, m_headerfileset.m_wgllist.m_extlist.size() );
		break;

	case TOKEN_STRING_GLXMAX:
		stl_itoa( outstr, m_headerfileset.m_wgllist.m_extlist.size() );
		break;

	case TOKEN_STRING_FUNCMAX:
		stl_itoa( outstr, m_scriptsettings.m_pextentry->m_funcnum );
		break;

	case TOKEN_STRING_CONSTMAX:
		stl_itoa( outstr, m_scriptsettings.m_pextentry->m_constnum );
		break;

	case TOKEN_STRING_GLCOUNTER:
		stl_itoa( outstr, m_scriptsettings.m_pos+1 );
		break;

	case TOKEN_STRING_WGLCOUNTER:
		stl_itoa( outstr, m_scriptsettings.m_pos+1 );
		break; 

	case TOKEN_STRING_GLXCOUNTER:
		stl_itoa( outstr, m_scriptsettings.m_pos+1 );
		break;

	case TOKEN_STRING_FUNCCOUNTER: 
		stl_itoa( outstr, m_scriptsettings.m_pos+1 );
		break;

	case TOKEN_STRING_CONSTCOUNTER:
		stl_itoa( outstr, m_scriptsettings.m_constpos+1 );
		break;
	
	case TOKEN_STRING_EXTREGISTRYCOUNTER:
		stl_itoa( outstr, m_scriptsettings.m_registrypos+1 );
		break;

	case TOKEN_STRING_PFNPROC:
		if ( m_scriptsettings.m_activefunc )
			{
			outstr = m_scriptsettings.m_pcurfunclist->at(
				m_scriptsettings.m_pextentry->m_funcstart
			+ m_scriptsettings.m_funcpos).m_pfnproc.data();
			}
		break;

	case TOKEN_STRING_FUNCNAME:
		if ( m_scriptsettings.m_activefunc )
			{
			outstr = m_scriptsettings.m_pcurfunclist->at(
				m_scriptsettings.m_pextentry->m_funcstart
					+ m_scriptsettings.m_funcpos ).m_name.data();
			}
		break;

	case TOKEN_STRING_FUNCPROTO:
		if ( m_scriptsettings.m_activefunc )
			{
			outstr = m_scriptsettings.m_pcurfunclist->at(
				m_scriptsettings.m_pextentry->m_funcstart
					+ m_scriptsettings.m_funcpos ).m_value.data();
			}
		break;

	case TOKEN_STRING_FUNCPREFIX:
		if ( m_scriptsettings.m_activefunc )
			{
			outstr = m_scriptsettings.m_pcurfunclist->at(
				m_scriptsettings.m_pextentry->m_funcstart
			+ m_scriptsettings.m_funcpos ).m_prefix.data();
			}
		break;

	case TOKEN_STRING_CONSTNAME:
		if ( m_scriptsettings.m_activeconst )
			{
			if ( m_scriptsettings.m_extmode )
				{
				outstr = m_headerfileset.m_gllist.m_constlist.at( m_scriptsettings.m_pextentry->m_conststart + m_scriptsettings.m_constpos ).m_name.data();
				}
			else
				{
				outstr = m_headerfileset.m_wgllist.m_constlist.at( m_scriptsettings.m_pextentry->m_conststart + m_scriptsettings.m_constpos ).m_name.data();
                		}
			}
		break;

	case TOKEN_STRING_CONSTVALUE:
		if ( m_scriptsettings.m_activeconst )
			{
			if ( m_scriptsettings.m_extmode )
				{
				outstr = 
					m_headerfileset.m_gllist.m_constlist.at(
					m_scriptsettings.m_pextentry->m_conststart
					+ m_scriptsettings.m_constpos ).m_value.data();
				}
			else
				{
				outstr = 
					m_headerfileset.m_wgllist.m_constlist.at(
					m_scriptsettings.m_pextentry->m_conststart
					+ m_scriptsettings.m_constpos).m_value.data();
                		}
			}	
		break;

	case TOKEN_STRING_HOSTNAME:
		stl_hostname( outstr );
		break;

	case TOKEN_STRING_VERSIONVAR:
		if ( m_scriptsettings.m_activeversion )
			{
			outstr = m_headerfileset.m_versionlist.at(
				m_scriptsettings.m_versionpos).m_name.data();

			stl_strdel( outstr, '_');
			}
		break;

	case TOKEN_STRING_VERSIONNAME:
		if ( m_scriptsettings.m_activeversion )
			{
			outstr = "GL_VERSION" +
				m_headerfileset.m_versionlist.at(
					m_scriptsettings.m_versionpos).m_name;
			}
		break;

	case TOKEN_STRING_VERSIONNUMBERS:
		if ( m_scriptsettings.m_activeversion )
			{
			string str;

			str = m_headerfileset.m_versionlist.at(
                                        m_scriptsettings.m_versionpos).m_name;

			char *pch = (char *) str.data();

			while (*pch != '\0' && *pch == '_')
				pch++;
		
			while (*pch != '\0' && *pch != '_' )
				{
				outstr += *pch;
				pch++;
				}

			outstr += ", ";
	
			while (*pch != '\0' && *pch == '_')
				pch++;

			while (*pch != '\0' && *pch != '_' )
				{
				outstr += *pch;
				pch++;
				}
			}
		break;

	case TOKEN_STRING_USERNAME:
		stl_getusername( outstr );
		break;

	case TOKEN_STRING_WGLHEADER:
		if ( m_scriptsettings.m_activeregistry )
			{
			psiteinfo = 
				GetSiteInfo( m_scriptsettings.m_registrypos );
			
			if ( NULL != psiteinfo)
				{
				outstr = psiteinfo->GetWglheaderlocal();
				}
			}
		break;

	case TOKEN_STRING_GLXHEADER:
		if ( m_scriptsettings.m_activeregistry )
			{
			psiteinfo = 
				GetSiteInfo( m_scriptsettings.m_registrypos );

			if (NULL != psiteinfo)
				{
				outstr = psiteinfo->GetGlxheaderlocal();
				}
			else
				{
				outstr = "";
				}
			}
		break;

	case TOKEN_STRING_GLHEADER:
		if ( m_scriptsettings.m_activeregistry )
			{
			psiteinfo = GetSiteInfo( m_scriptsettings.m_registrypos );

			if (NULL != psiteinfo)
				{
				outstr = psiteinfo->GetGlheaderlocal();
				}
			else
				{
				outstr = "";
				}
			}
		break;

	case TOKEN_STRING_FILENAME:
		outstr = m_scriptsettings.m_filename;
		break;

	case TOKEN_STRING_CONFIGFILE:
		outstr = m_configfilesettings.m_configfile;
		break;

	case TOKEN_STRING_SCRIPTFILE:
		outstr = m_outputfilesettings.m_scriptfile;
		break;

	case TOKEN_STRING_PATH:
		stl_getcwd( outstr );
		break;

	case TOKEN_STRING_TAB:
		outstr = "\t";
		break;

	case TOKEN_STRING_NEWLINE:
		outstr = "\n";
		break;

	case TOKEN_STRING_QUOTES:
		outstr = "\"";

		if ( m_scriptsettings.m_outputstream.is_open() )
			{
			m_scriptsettings.m_outputstream << "\"";
			}

		break;

	// ===== CONDITIONALS ===============================================

	case TOKEN_COMMAND_IF:
		ProcessScript( curaddr+1, curaddr+3 ); // Get result code

		finishaddr = m_scriptsettings.ScriptFindEndif( curaddr);
//		elseaddr =   m_scriptsettings.ScriptFindElse( curaddr); 

		if ( m_scriptsettings.m_result )
			{
			ProcessScript( curaddr+2, finishaddr );
			}
/*
		else
			{
			if ( m_tokenlist[curaddr].m_tokenid == 	
				TOKEN_COMMAND_ELSE )
				ProcessScript( elseaddr+1, finishaddr );
			}
*/
		curaddr = finishaddr; // Incremented later
		break;
	
	case TOKEN_COMMAND_ENDIF:	
		// Nothing to be done
		break;

	// ==== LOGICAL OPERATIONS ==========================================

	case TOKEN_COMMAND_NOT:
		ProcessScript( curaddr+1, curaddr+3 );
		m_scriptsettings.m_result = !m_scriptsettings.m_result;
		done++;
		break;

	// ==== VARIABLE READ OPERATIONS ====================================

	case TOKEN_VARIABLE_WGLDEF:
		m_scriptsettings.m_result = ( (m_scriptsettings.m_activegl) &&
			(m_headerfileset.m_wgllist.m_extlist.FindName( 
				m_scriptsettings.m_pextentry->m_name.data() ) >= 0 ) );
		done++;
		break;

	case TOKEN_VARIABLE_GLXDEF:
		m_scriptsettings.m_result = ( (m_scriptsettings.m_activeglx) &&
			(m_headerfileset.m_glxlist.m_extlist.FindName( 
				m_scriptsettings.m_pextentry->m_name.data() ) >= 0 ) );
		done++;
	   	break;

	case TOKEN_VARIABLE_GLDEF:       
		m_scriptsettings.m_result = ( (m_scriptsettings.m_activewgl) &&
			(m_headerfileset.m_gllist.m_extlist.FindName( 
				m_scriptsettings.m_pextentry->m_name.data() ) >= 0 ) );
		done++;
		break;

	case TOKEN_VARIABLE_FUNCNUM:
		m_scriptsettings.m_result = ( (m_scriptsettings.m_activegl || 
			m_scriptsettings.m_activewgl || 
			m_scriptsettings.m_activeglx ) && 
		( m_scriptsettings.m_pextentry->m_funcnum > 0) );
		done++;
		break;

	case TOKEN_VARIABLE_SELECTED:
		m_scriptsettings.m_result = ( ( m_scriptsettings.m_activegl ||
			m_scriptsettings.m_activewgl || 
			m_scriptsettings.m_activeglx ) &&
       		 ( m_scriptsettings.m_pextentry->EntryGetFlag( FLAG_OUTPUT) ) );

		done++;
		break;

	case TOKEN_VARIABLE_CMODE:
		m_scriptsettings.m_result = !m_outputfilesettings.m_cppmode;
		done++;
		break;

	case TOKEN_VARIABLE_CPPMODE:    
		m_scriptsettings.m_result = m_outputfilesettings.m_cppmode;
		done++;
		break;

	case TOKEN_VARIABLE_GLNUM: 
		m_scriptsettings.m_result = 
			( m_headerfileset.m_gllist.m_selectednum > 0 );
		done++;
		break;

	case TOKEN_VARIABLE_WGLNUM:     
		m_scriptsettings.m_result = 
			( m_headerfileset.m_wgllist.m_selectednum > 0 );
		done++;
		break;

	case TOKEN_VARIABLE_GLXNUM:
		m_scriptsettings.m_result = 
			( m_headerfileset.m_glxlist.m_selectednum > 0 );
		done++;
		break;

	case TOKEN_VARIABLE_EXTNUM:
		m_scriptsettings.m_result = 
			( (m_headerfileset.m_gllist.m_selectednum > 0) ||
		  	 (m_headerfileset.m_wgllist.m_selectednum > 0) ||
		 	 (m_headerfileset.m_glxlist.m_selectednum > 0) );
		done++;
		break;

	case TOKEN_VARIABLE_GLFUNCNUM:
		m_scriptsettings.m_result = 
			( m_headerfileset.m_gllist.m_selectedfuncnum > 0 );
		done++;
		break;

	case TOKEN_VARIABLE_WGLFUNCNUM:
		m_scriptsettings.m_result = 
			( m_headerfileset.m_wgllist.m_selectedfuncnum > 0 );
		done++;
		break;

	case TOKEN_VARIABLE_GLXFUNCNUM:
		m_scriptsettings.m_result = 
			( m_headerfileset.m_glxlist.m_selectedfuncnum > 0 );
		done++;
		break;

	default:
		break;
	} // switch

// --------------------------------------------------------------------------
// END OF SWITCH STATEMENT
// --------------------------------------------------------------------------

#ifdef DEBUG   
if ( (*pstoken)->m_tokenid == TOKEN_COMMAND_ENDIF )
	{
	cout << "ENDIF here #1\n";
	}
#endif
 
if ( (*pstoken)->m_tokenid & TOKEN_STRING )
	{
	if ( m_scriptsettings.m_casemode == MODE_CASEUPPER )
		{
		stl_strupr( outstr);
		}

	if ( m_scriptsettings.m_casemode == MODE_CASELOWER )
		{
		stl_strlwr( outstr);
		}

	if ( m_scriptsettings.m_outputstream.is_open() )
		{
		m_scriptsettings.m_outputstream << outstr;
		}
	} // if
 
// ----- Test for END or ENDIF tokens --------------------------------------

if ( (*pstoken)->m_tokenid != TOKEN_COMMAND_END )
	{
#ifdef DEBUG
	cout << "Incrementing\n";
#endif
	(*pstoken)++;
	curaddr++;
	} // if

#ifdef DEBUG   
if ( (*pstoken)->m_tokenid == TOKEN_COMMAND_ENDIF )
	{
	cout << "ENDIF here #2\n";
	}
#endif

return( done );
}

// --------------------------------------------------------------------------
// Write generated files
//
// Inputs: None
//
// Outputs: None
//
// Results: None
//
// Effects: The generated files are written
// --------------------------------------------------------------------------

static const char *str_main = "main";

int CExtensionViewer::WriteGeneratedFiles( 
		CGenerateProgressCallback &callback )
{
int start, finish;

m_scriptsettings.m_callback = &callback;

if (m_outputfilesettings.m_cppmode )
	{
	m_outputfilesettings.m_classnamedcolon = 
		m_outputfilesettings.m_classname + "::";
	}
else
	{
	m_outputfilesettings.m_classnamedcolon = "";
	}

m_scriptsettings.m_tokenlist.ResetCount();

m_headerfileset.CountSelectedExtensions();

m_scriptsettings.m_activegl    = false;
m_scriptsettings.m_activewgl     = false;
m_scriptsettings.m_activeglx     = false;
m_scriptsettings.m_activefunc    = false;
m_scriptsettings.m_activeversion = false;
m_scriptsettings.m_activeconst   = false;
m_scriptsettings.m_activeregistry   = false;
m_scriptsettings.m_nomacros      = false;
m_scriptsettings.m_funcdepth     = 0;

m_scriptsettings.ScriptDump( "debug.txt" );

start = m_scriptsettings.m_prefunclist.FindName( str_main );

if ( start >= 0 )
	{
	finish = m_scriptsettings.ScriptFindEnd( start );

	ProcessScript( start, finish );
	}

m_scriptsettings.m_tokenlist.TokenSort();

return(1);
}

// --------------------------------------------------------------------------
// Extract a variable name from the surrounding parenthesis
//
// Inputs: pchlist - Character pointer to source string
//         tempbuf - Character pointer to destination string
//         len     - Reference to the final length of the new string
//
// Outputs: tempbuf - The extracted string is placed in this variable
//          len     - The length of the string is stored in len
//
// Results: None
//
// Effects: The string is extracted
// --------------------------------------------------------------------------
                                                                                
const char *CExtensionScriptSettings::ExtractVariable( 
					const char *pchsrc,
					char *pchtemp, int &len )
{
char *pchlist = (char *) pchsrc;
char *tempbuf = (char *) pchtemp;

while ( (*pchlist ) && isspace( *pchlist ) )
    pchlist++;
len=0;
                                                                                
if ( *pchlist == '<' )
    {
    pchlist++;

    while ( (*pchlist) && (*pchlist != '>') )
        tempbuf[len++] = *pchlist++;
    }
                                                                                
tempbuf[len] = '\0';
                                                                                
if ( *pchlist != '>' )
    {
    // Error ...
    }
pchlist++;
                                                                                
return(pchlist);
}
