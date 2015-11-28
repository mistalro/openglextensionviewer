// --------------------------------------------------------------------------
// File:    tokenentry.h
//
// Purpose: Definition of the token entry class
//
// Author:  Michael S. A. Robb
//
// Date:    20th September 2009
// --------------------------------------------------------------------------

#ifndef _TOKENENTRY_H_
#define _TOKENENTRY_H_

class CTokenEntry
{
// ----- Class members ------------------------------------------------------
public:
int     m_tokenid;
string  m_string;

// ----- Constructor and destructor -----------------------------------------

CTokenEntry( int tokenid, const char *pstring )
        {
        m_tokenid = tokenid;
        m_string  = pstring;
        }

CTokenEntry( int tokenid, string &string )
        {
        m_tokenid = tokenid;
        m_string  = string;
        }

CTokenEntry( const char *pstring, int tokenid )
        {
        m_tokenid = tokenid;
        m_string  = pstring;
        }

CTokenEntry( string &string, int tokenid )
        {
        m_tokenid = tokenid;
        m_string  = string;
	}

~CTokenEntry( void )
        {
        }

// ----- Class members ------------------------------------------------------

int operator == (string &string )
        {
        return( m_string == string );
        }
};

extern int token_match( string &buffer, CTokenEntry *plist, int num );

extern int token_findentry( int tokenid, CTokenEntry *plist, int num );

extern CTokenEntry *token_matchid( int tokenid, CTokenEntry *plist, int num );

#endif	// _TOKENENTRY_H_

