// ---------------------------------------------------------------------------
// Copyright: (C) VFX Research 2002 - 2014. All Rights Reserved.
// ---------------------------------------------------------------------------

#ifndef _SCRIPTTOKEN_
#define _SCRIPTTOKEN_

// --------------------------------------------------------------------------
// Definition of a script token
// --------------------------------------------------------------------------

class CScriptToken
{
public:
int   m_tokenid;    // Type of token
char *m_pstrbuf;      // Text for string
int   m_strlen;       // Length of string

CScriptToken( void ) { Init(); };
~CScriptToken( void ) { Deallocate(); };

void Init( void )
    {
    m_tokenid = TOKEN_NONE;
    m_pstrbuf  = NULL;
    m_strlen  = 0;
    };

void Deallocate( void )
    {
    if ( m_pstrbuf )
        delete [] m_pstrbuf;

    m_pstrbuf = NULL;
    };
};

// --------------------------------------------------------------------------
// Definition of the CScriptTokenlist class
// --------------------------------------------------------------------------

class CScriptTokenList
{
public:
unsigned int  m_tokenmax;        // Maximum number of tokens
unsigned int  m_tokennum;        // Current number of tokens
CScriptToken *m_tokenlist;       // List of tokens

// ----- Constructor and destructor -----------------------------------------

CScriptTokenList( void ) { Init(); };
~CScriptTokenList( void ) { Deallocate(); };

// ----- Function Prototypes ------------------------------------------------

void Init( void )
    {
    m_tokennum = 0;
    m_tokenmax = 0;
    m_tokenlist = NULL;
    };

void Deallocate( void )
    {
    m_tokenmax = 0;
    m_tokennum = 0;

    if ( m_tokenlist )
        delete [] m_tokenlist;

    m_tokenlist = NULL;
    };

void Allocate( unsigned int num )
    {
    unsigned int pn;

    Deallocate();

    m_tokenlist = new CScriptToken[num];
    m_tokenmax  = num;
    m_tokennum  = 0;

    for ( pn = 0; pn < m_tokenmax; pn++ )
        m_tokenlist[pn].Init();
    };

void Expand( unsigned int num )
    {
    CScriptToken *pnew;
    unsigned int pn;

    if (num <= m_tokenmax )
        return;

    pnew = new CScriptToken[num];

    if ( m_tokenlist )
        {
        for ( pn = 0; pn < m_tokennum; pn++ )
            pnew[pn] = m_tokenlist[pn];

        delete [] m_tokenlist;
        }

    m_tokenlist = pnew;
    m_tokenmax  = num;

    for ( pn = m_tokennum; pn < m_tokenmax; pn++ )
        m_tokenlist[pn].Init();
    };

int AddToken( CScriptToken &stoken )
    {   
    int pos;

    if ( m_tokennum == m_tokenmax )
        Expand( m_tokennum+10 );
    
    pos = m_tokennum;

    m_tokenlist[m_tokennum] = stoken;   // Copy pointer
    stoken.m_pstrbuf = NULL;            // Make sure we don't lose it

    m_tokennum++;

    return( pos );    
    };
};

#endif // _SCRIPTTOKEN_
