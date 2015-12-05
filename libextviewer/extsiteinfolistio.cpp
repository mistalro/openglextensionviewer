// ---------------------------------------------------------------------------
// Copyright: (C) VFX Research 2002 - 2014. All Rights Reserved.
// ---------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>

#include "extensionlib.h"

// ---------------------------------------------------------------------------
// Keyword strings
// ---------------------------------------------------------------------------

static const char *str_blockname = "sitelist";

#define STRING_BLOCKNAME	str_blockname

static const char *str_listdata = "website";

#define STRING_LISTDATA	str_listdata

// --------------------------------------------------------------------------
// Token ID numbers
// --------------------------------------------------------------------------

#define TOKEN_BLOCKNAME	0x1001

#define TOKEN_LISTDATA	0x1002

// --------------------------------------------------------------------------
// Token entry list
// --------------------------------------------------------------------------

static CTokenEntry token_list[] =
{
CTokenEntry( TOKEN_LISTDATA, STRING_LISTDATA )
};

static int token_num = sizeof(token_list)/sizeof(CTokenEntry);

// --------------------------------------------------------------------------
// Read CExtensionSiteInfoListIOData in from an open stream
// --------------------------------------------------------------------------

int CExtensionSiteInfoListIODataAsciiIO::ReadFileInternal( std::ifstream &stream )
{
std::string tokenid;
int result;

while ( ReadOpenClosePar( stream ) != 0 )
	{
	ReadString( stream, tokenid );

	if (tokenid.compare( STRING_BLOCKNAME ) == 0 )
		{
		result = ReadFile( stream );
		}
	else
		{
		result = false;
		}
	}

return( result );
}

// --------------------------------------------------------------------------
// Read CExtensionSiteInfoListIOData in from an open stream
// --------------------------------------------------------------------------

int CExtensionSiteInfoListIODataAsciiIO::ReadFile( std::ifstream &stream )
{
std::string tokenid;

CExtensionSiteInfo entry_listdata;

int result = true;

while ( ReadOpenClosePar( stream ) != 0 )
	{
	ReadString( stream, tokenid );

	switch( token_match( tokenid, token_list, token_num ) )
		{
		case TOKEN_LISTDATA:
			entry_listdata.ReadFile( stream );
			push_back( entry_listdata );
			break;

		default:
			std::cout << "CExtensionSiteInfoListIO::Unknown token <" << tokenid << ">\n";
			break;
		}

	ReadClosePar( stream );
	}

stream.putback( '}' );

return( result );
}

// --------------------------------------------------------------------------
// Write data out to an open stream at specified tab depth
// --------------------------------------------------------------------------

int CExtensionSiteInfoListIODataAsciiIO::WriteFile( std::ofstream &stream, unsigned int depth )
{
return( WriteFile( stream, depth, STRING_BLOCKNAME ) );
}

// --------------------------------------------------------------------------
// Write data out to an open stream at specified tab depth
// --------------------------------------------------------------------------

int CExtensionSiteInfoListIODataAsciiIO::WriteFile( std::ofstream &stream, unsigned int depth, const char *pstr )
{
int result;

result = true;

WriteOpenPar( stream, depth, pstr );


for ( iterator it = begin(); it != end(); ++it )
	{
	result &= it->WriteFile( stream, depth );
	}

WriteClosePar( stream, depth );

return( result );
}
