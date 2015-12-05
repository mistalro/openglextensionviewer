// ---------------------------------------------------------------------------
// Copyright: (C) VFX Research 2002 - 2014. All Rights Reserved.
// ---------------------------------------------------------------------------

#ifndef _FUNCLIST_
#define _FUNCLIST_

#include <string>

// --------------------------------------------------------------------------
// Function Element Class - Used for script generation
// --------------------------------------------------------------------------

class CFuncElement
{
public:
std::string m_name;		// Name of function
int m_funcaddr;		// Token offset

CFuncElement( void )
{
m_name.clear();
m_funcaddr = 0;
};

CFuncElement( const std::string &name, int addr )
{
m_name = name;

m_funcaddr = addr;
};

~CFuncElement( void ) 
	{ 
	};
};

// --------------------------------------------------------------------------
// Function Element List Class
// --------------------------------------------------------------------------

class CFuncElementList
{
public:
CFuncElement *m_prefunclist;   // List of pre-defined functions
int           m_prefuncnum;    // Current number of functions
int           m_prefuncmax;    // Maximum number of functions

// ----- Constructor and Destructor -----------------------------------------

CFuncElementList( void )  { Init(); };

~CFuncElementList( void ) { Deallocate(); };

// ----- Functions and Prototypes -------------------------------------------

void Init( void ) 
    {
    m_prefuncnum = 0;
    m_prefuncmax = MAX_PREFUNCLIST;
    m_prefunclist = new CFuncElement[MAX_PREFUNCLIST];
    };

void Deallocate( void )
    {
    m_prefuncnum = 0;
    m_prefuncmax = 0;

    if ( m_prefunclist )
	{
        delete [] m_prefunclist;
	}

    m_prefunclist = NULL;
    };

void AddList( const std::string &name, int addr )
    { 	
    m_prefunclist[m_prefuncnum++] = CFuncElement( name, addr ); 
    };

int FindName( const std::string &name )
    {
    int found = -1;

    for ( int pn = 0; pn < m_prefuncnum; pn++ )
	{
        if ( strncmp( name.data(), m_prefunclist[pn].m_name.data(), sizeof(STRNAME) ) == 0 )
		{
            	found = pn;
		}
	}

    return( found );
    };
};

#endif // _FUNCLIST_
