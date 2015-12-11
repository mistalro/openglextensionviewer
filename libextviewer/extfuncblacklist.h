// ---------------------------------------------------------------------------
// Copyright: (C) VFX Research 2002 - 2014. All Rights Reserved.
// ---------------------------------------------------------------------------

#ifndef _FUNCBLACKLIST_
#define _FUNCBLACKLIST_

#include <string>

// --------------------------------------------------------------------------
// Define the name of a single blacklisted function
// --------------------------------------------------------------------------

class CExtensionFuncBlacklistEntry
{
public:
std::string m_name;		// Name of function

CExtensionFuncBlacklistEntry( void )
	{
	m_name.clear();
	}

CExtensionFuncBlacklistEntry( const std::string &name )
	{
	m_name = name;
	}

~CExtensionFuncBlacklistEntry( void ) 
	{ 
	}
};

// --------------------------------------------------------------------------
// Define the list of blacklisted functions
// -------------------------------------------------------------------------

typedef std::vector <CExtensionFuncBlacklistEntry> CFuncBlacklist; 

class CExtensionFuncBlacklist
{
public:
CFuncBlacklist m_funclist;

// ----- Constructor and Destructor -----------------------------------------

CExtensionFuncBlacklist( void )  
	{ 
	Init(); 
	};

~CExtensionFuncBlacklist( void )
	{ 
	Deallocate(); 
	};

// ----- Functions and Prototypes -------------------------------------------

void Init( void ) 
	{
	AddFunctionName( "glBlendColor");
	AddFunctionName( "glBlendEquation");
	};

void Deallocate( void )
	{
	m_funclist.clear();
	};

void AddFunctionName( const std::string &name )
	{ 	
	CExtensionFuncBlacklistEntry entry(name);
	m_funclist.push_back( entry );
	};

int FindFunctionName( const std::string &name )
	{
	int found = -1;

	for (CFuncBlacklist::iterator it = m_funclist.begin(); it != m_funclist.end(); ++it)
		{
		if (it->m_name == name )
			{
			found = it - m_funclist.begin();
			}
		}

	return found;
	};
};

#endif // _FUNCBLACKLIST_
