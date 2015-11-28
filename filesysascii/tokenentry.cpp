// --------------------------------------------------------------------------
// File:    tokenentry.cpp
//
// Purpose: Utility routine for processing tokens
//
// Author:  Michael S. A. Robb
//
// Date:    2005/01/27
// --------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include <vector>
#include <string>

using namespace std;

#include "tokenentry.h"

using namespace std;

// --------------------------------------------------------------------------
// Function to match tokens
// --------------------------------------------------------------------------

int token_match( string &string, CTokenEntry *plist, int num )
{
int tn;

for ( tn = 0; tn < num; tn++ )
        if  ( plist[tn] == string )
                return( plist[tn].m_tokenid );

return( -1 );
}

// --------------------------------------------------------------------------
// Function to find entry in list
// --------------------------------------------------------------------------

CTokenEntry *token_matchid( int tokenid, CTokenEntry *plist, int num )
{
int tn;

for ( tn = 0; tn < num; tn++ )
        if  ( plist[tn].m_tokenid == tokenid )
                return( plist + tn );

return( NULL );
}
