// ---------------------------------------------------------------------------
// Copyright: (C) VFX Research 2002 - 2014. All Rights Reserved.
// ---------------------------------------------------------------------------

#ifndef _TOKENLIST_
#define _TOKENLIST_

#include <cstdio>
#include <cstdlib>
#include <assert.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <ios>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>

#include "sorters.h"

// --------------------------------------------------------------------------
// Definitions for the list of tokens used to generate the output files
// --------------------------------------------------------------------------

#define TOKEN_ITERATOR	 0x01000	   // Iterators - loop counters
#define TOKEN_CONDITION  0x02000	   // Conditionals
#define TOKEN_STRING	 0x04000	   // String
#define TOKEN_COMMAND	 0x08000	   // Command
#define TOKEN_VALUECONST 0x10000	   // Value
#define TOKEN_VARIABLE	 0x20000	   // Variable
#define TOKEN_OPERATOR	 0x40000	   // Operator

#define TOKEN_NONE	 0xFFFF

// ----- Commands -----------------------------------------------------------

#define TOKEN_COMMAND_FILEOPEN	  (0x0001|TOKEN_COMMAND)
#define TOKEN_COMMAND_FILECLOSE	  (0x0002|TOKEN_COMMAND)
#define TOKEN_COMMAND_CALL	  (0x0003|TOKEN_COMMAND)
#define TOKEN_COMMAND_BEGIN	  (0x0004|TOKEN_COMMAND)
#define TOKEN_COMMAND_END	  (0x0005|TOKEN_COMMAND)
#define TOKEN_COMMAND_NOMACROS	  (0x0006|TOKEN_COMMAND)
#define TOKEN_COMMAND_CASEUPPER	  (0x0007|TOKEN_COMMAND)
#define TOKEN_COMMAND_CASELOWER	  (0x0008|TOKEN_COMMAND)
#define TOKEN_COMMAND_CASENORMAL  (0x0009|TOKEN_COMMAND)
#define TOKEN_COMMAND_ELSE	  (0x000A|TOKEN_COMMAND)
#define TOKEN_COMMAND_IF	  (0x000B|TOKEN_COMMAND)
#define TOKEN_COMMAND_NOT	  (0x000C|TOKEN_COMMAND)
#define TOKEN_COMMAND_ENDIF	  (0x000D|TOKEN_COMMAND)
#define TOKEN_COMMAND_EXIT	  (0x000E|TOKEN_COMMAND)
#define TOKEN_COMMAND_FOREACH	  (0x000F|TOKEN_COMMAND)
#define TOKEN_COMMAND_ENDFOR	  (0x0010|TOKEN_COMMAND)
#define TOKEN_COMMAND_UNBEGIN	  (0x0011|TOKEN_COMMAND)

// ----- Operators ----------------------------------------------------------

#define TOKEN_OPERATOR_OPENPAR	  (0x0001|TOKEN_OPERATOR)
#define TOKEN_OPERATOR_CLOSEPAR	  (0x0002|TOKEN_OPERATOR)
#define TOKEN_OPERATOR_UNARYADD	  (0x0003|TOKEN_OPERATOR)
#define TOKEN_OPERATOR_UNARYSUB	  (0x0004|TOKEN_OPERATOR)
#define TOKEN_OPERATOR_UNARYTILDE (0x0005|TOKEN_OPERATOR)
#define TOKEN_OPERATOR_UNARYNOT	  (0x0006|TOKEN_OPERATOR)
#define TOKEN_OPERATOR_MULT	  (0x0007|TOKEN_OPERATOR)
#define TOKEN_OPERATOR_DIVIDE	  (0x0008|TOKEN_OPERATOR)
#define TOKEN_OPERATOR_MOD	  (0x0009|TOKEN_OPERATOR)
#define TOKEN_OPERATOR_ADD	  (0x0010|TOKEN_OPERATOR)
#define TOKEN_OPERATOR_MINUS	  (0x0011|TOKEN_OPERATOR)
#define TOKEN_OPERATOR_BIT_SHIFTL (0x0012|TOKEN_OPERATOR)
#define TOKEN_OPERATOR_BIT_SHIFTR (0x0013|TOKEN_OPERATOR)
#define TOKEN_OPERATOR_EQUAL	  (0x0014|TOKEN_OPERATOR)
#define TOKEN_OPERATOR_NOTEQUAL	  (0x0015|TOKEN_OPERATOR)
#define TOKEN_OPERATOR_BIT_AND	  (0x0016|TOKEN_OPERATOR)
#define TOKEN_OPERATOR_BIT_EOR	  (0x0017|TOKEN_OPERATOR)
#define TOKEN_OPERATOR_BIT_IOR	  (0x0018|TOKEN_OPERATOR)
#define TOKEN_OPERATOR_LOGIC_AND  (0x0019|TOKEN_OPERATOR)
#define TOKEN_OPERATOR_LOGIC_IOR  (0x001A|TOKEN_OPERATOR)		 

// ----- Iterators ----------------------------------------------------------

#define TOKEN_ITERATOR_GLEXT	    (0x0018|TOKEN_ITERATOR)
#define TOKEN_ITERATOR_WGLEXT	    (0x0019|TOKEN_ITERATOR)
#define TOKEN_ITERATOR_GLXEXT	    (0x001A|TOKEN_ITERATOR)
#define TOKEN_ITERATOR_EXTFUNCLIST  (0x001B|TOKEN_ITERATOR)
#define TOKEN_ITERATOR_EXTCONSTLIST (0x001C|TOKEN_ITERATOR)
#define TOKEN_ITERATOR_VERSION	    (0x001D|TOKEN_ITERATOR)
#define TOKEN_ITERATOR_EXTREGISTRY  (0x001E|TOKEN_ITERATOR)

#define TOKEN_ITERATOR_EXTFUNCBLACKLIST (0x001F|TOKEN_ITERATOR)

// ----- Strings ------------------------------------------------------------

#define TOKEN_STRING_CLASSX	    (0x0020|TOKEN_STRING)
#define TOKEN_STRING_CLASSNAME	    (0x0021|TOKEN_STRING)
#define TOKEN_STRING_EXTNAME	    (0x0022|TOKEN_STRING)
#define TOKEN_STRING_OUTPUTHEADER   (0x0023|TOKEN_STRING)
#define TOKEN_STRING_OUTPUTSOURCE   (0x0024|TOKEN_STRING)
#define TOKEN_STRING_WGLVERSION	    (0x0025|TOKEN_STRING)
#define TOKEN_STRING_GLVERSION	    (0x0026|TOKEN_STRING)
#define TOKEN_STRING_GLXVERSION	    (0x0027|TOKEN_STRING)
#define TOKEN_STRING_TIME	    (0x0028|TOKEN_STRING)
#define TOKEN_STRING_MODULETYPE	    (0x0029|TOKEN_STRING)
#define TOKEN_STRING_PREFIX	    (0x002A|TOKEN_STRING)
#define TOKEN_STRING_FILETYPE	    (0x002B|TOKEN_STRING)
#define TOKEN_STRING_GLHEADER	    (0x002C|TOKEN_STRING)
#define TOKEN_STRING_GLXHEADER	    (0x002D|TOKEN_STRING)
#define TOKEN_STRING_WGLHEADER	    (0x002E|TOKEN_STRING)
#define TOKEN_STRING_PFNPROC	    (0x002F|TOKEN_STRING)
#define TOKEN_STRING_DCOLON	    (0x0030|TOKEN_STRING)
#define TOKEN_STRING_HOSTNAME	    (0x0031|TOKEN_STRING)
#define TOKEN_STRING_USERNAME	    (0x0032|TOKEN_STRING)
#define TOKEN_STRING_FILENAME	    (0x0033|TOKEN_STRING)
#define TOKEN_STRING_VERSIONVAR	    (0x0034|TOKEN_STRING)
#define TOKEN_STRING_VERSIONNAME    (0x0035|TOKEN_STRING)
#define TOKEN_STRING_VERSIONNUMBERS (0x0036|TOKEN_STRING)

#define TOKEN_STRING_CONFIGFILE	    (0x0040|TOKEN_STRING)
#define TOKEN_STRING_SCRIPTFILE	    (0x0041|TOKEN_STRING)
#define TOKEN_STRING_PATH	    (0x0042|TOKEN_STRING)
#define TOKEN_STRING_WGLCOUNTER	    (0x0043|TOKEN_STRING)
#define TOKEN_STRING_GLCOUNTER	    (0x0044|TOKEN_STRING)
#define TOKEN_STRING_GLXCOUNTER	    (0x0045|TOKEN_STRING)
#define TOKEN_STRING_STRING	    (0x0046|TOKEN_STRING)
#define TOKEN_STRING_WGLMAX	    (0x0047|TOKEN_STRING)
#define TOKEN_STRING_GLMAX	    (0x0048|TOKEN_STRING)
#define TOKEN_STRING_GLXMAX	    (0x0049|TOKEN_STRING)
#define TOKEN_STRING_TAB	    (0x004A|TOKEN_STRING)
#define TOKEN_STRING_NEWLINE	    (0x004B|TOKEN_STRING)
#define TOKEN_STRING_QUOTES	    (0x004C|TOKEN_STRING)
#define TOKEN_STRING_FUNCMAX	    (0x004D|TOKEN_STRING)
#define TOKEN_STRING_FUNCPROTO	    (0x004E|TOKEN_STRING)
#define TOKEN_STRING_FUNCPREFIX	    (0x004F|TOKEN_STRING)
#define TOKEN_STRING_FUNCCOUNTER    (0x0050|TOKEN_STRING)
#define TOKEN_STRING_FUNCNAME	    (0x0051|TOKEN_STRING)
#define TOKEN_STRING_FUNCHEADER	    (0x0052|TOKEN_STRING)
#define TOKEN_STRING_CONSTMAX	    (0x0053|TOKEN_STRING)
#define TOKEN_STRING_CONSTVALUE	    (0x0054|TOKEN_STRING)
#define TOKEN_STRING_CONSTCOUNTER   (0x0055|TOKEN_STRING)
#define TOKEN_STRING_CONSTNAME	    (0x0056|TOKEN_STRING)
#define TOKEN_STRING_EXTREGISTRYCOUNTER (0x0057|TOKEN_STRING)

// ----- Variables ---------------------------------------------------------

#define TOKEN_VARIABLE_CPPMODE	   (0x0070|TOKEN_VARIABLE)
#define TOKEN_VARIABLE_CMODE	   (0x0071|TOKEN_VARIABLE)
#define TOKEN_VARIABLE_GLNUM 	   (0x0072|TOKEN_VARIABLE)
#define TOKEN_VARIABLE_WGLNUM	   (0x0073|TOKEN_VARIABLE)
#define TOKEN_VARIABLE_EXTNUM	   (0x0074|TOKEN_VARIABLE)
#define TOKEN_VARIABLE_GLXNUM	   (0x0075|TOKEN_VARIABLE)
#define TOKEN_VARIABLE_FUNCNUM	   (0x0076|TOKEN_VARIABLE)
#define TOKEN_VARIABLE_SELECTED	   (0x0077|TOKEN_VARIABLE)
#define TOKEN_VARIABLE_GLFUNCNUM   (0x0079|TOKEN_VARIABLE)
#define TOKEN_VARIABLE_WGLFUNCNUM  (0x007A|TOKEN_VARIABLE)
#define TOKEN_VARIABLE_GLXFUNCNUM  (0x007B|TOKEN_VARIABLE)

#define TOKEN_VARIABLE_GLDEF	   (0x0090|TOKEN_VARIABLE)
#define TOKEN_VARIABLE_WGLDEF	   (0x0091|TOKEN_VARIABLE)
#define TOKEN_VARIABLE_GLXDEF	   (0x0092|TOKEN_VARIABLE)
#define TOKEN_VARIABLE_NOTGLDEF	   (0x0093|TOKEN_VARIABLE)

//#define TOKEN_DEFINE	   0x001D
//#define TOKEN_ENDDEF	   0x001E
//#define TOKEN_CHAR		 0x001F
//#define TOKEN_NOT		  0x0029
//#define TOKEN_STRINGVAR	0x0081

// --------------------------------------------------------------------------
// Definition for the various constants
// --------------------------------------------------------------------------

#define MAX_TOKENSTRINGLENGTH 128

#define TOKEN_SORTNAME		0x0000
#define TOKEN_SORTVALUE		0x0001
#define TOKEN_SORTREVERSED	0x0004

#define TOKEN_SORTNAMEREVERSED  0x0004
#define TOKEN_SORTVALUEREVERSED 0x0005

// --------------------------------------------------------------------------
// Definition of the CToken class
// --------------------------------------------------------------------------

class CToken
{
public:
std::string	 m_name; 		// Name of token
int	 m_tokenid;  		// ID number
int	 m_tokencount; 		// Number of times token was found

CToken( void ) 
	{ 
	m_tokencount = m_tokenid = 0; 
	m_name[0] = '\0';
	};

~CToken( void ) { };

CToken( const CToken &token )
	{
	m_name = token.m_name;
	m_tokenid = token.m_tokenid;
	m_tokencount = token.m_tokencount;
	}

void Init( void )
	{
	m_tokencount = m_tokenid = 0; 
	m_name[0] = '\0';
	};

void Deallocate( void )
	{
	
	};

void Display( void )
	{

	};

void Duplicate( const CToken &token )
	{
	*this=  token;
	};

CToken( const char *name, int tokenid )
	{
	m_name = std::string(name);
	m_tokenid = tokenid;
	m_tokencount = 0;
	};

CToken( const std::string &name, int tokenid )
	{
	m_name = name;
	m_tokenid = tokenid;
	m_tokencount = 0;
	};

int Compare( const std::string &name )
	{
	return ( strncmp( name.data(), m_name.data(), m_name.length() ) == 0 );
	};

int SortCompare( const CToken &token )
	{
	return ( strncmp( token.m_name.data(), m_name.data(), token.m_name.length() ) == 0 );
	};

void IncCount( void ) 
	{ 
	m_tokencount++; 
	};

int  GetCount( void ) 
	{ 
	return m_tokencount; 
	};

void ResetCount( void ) 	
	{ 
	m_tokencount = 0; 
	};

int operator < ( const CToken &token )
	{
	return( strcmp( m_name.data(), token.m_name.data() ) );
	};

int operator > ( const CToken &token )
	{
	return( -strcmp( m_name.data(), token.m_name.data() ) );
	};
};

// --------------------------------------------------------------------------
// Definition of the token list class
// --------------------------------------------------------------------------

class CTokenList : public std::vector <CToken>,
			virtual public TSortFuncs <CToken>
{
public:
int	 m_sortmode;	 // Sorting mode

CTokenList( void )  
	{ 
	Init();	   
	};

~CTokenList( void ) 
	{ 
	Deallocate(); 
	};

void Init( void )
	{

	}

void Deallocate( void )
	{
	}

void TokenSetSortmode( int mode )
	{
	m_sortmode = mode;
	}

void TokenToggleSortmode( int mode );
void TokenSort( void );
void TokenAdd( const char *name, int tokenid );
void TokenAdd( const std::string &name, int tokenid );

CToken *TokenFind( const std::string &name );
CToken *TokenFind( int tokenid );

void ResetCount( void );
void WriteStats( const std::string &path );
};

#endif // _TOKENLIST_
