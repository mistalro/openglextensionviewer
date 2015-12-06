// ---------------------------------------------------------------------------
// Copyright: (C) VFX Research 2002 - 2014. All Rights Reserved.
// ---------------------------------------------------------------------------

#ifdef _WINDOWS_
#include "stdafx.h"
#endif

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>

#include "extensionlib.h"

// ---------------------------------------------------------------------------
// Keyword strings
// ---------------------------------------------------------------------------

static const char *str_blockname = "entrylist";

static const char *str_listdata = "extentry";

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
CTokenEntry( TOKEN_LISTDATA, str_listdata )
};

static int token_num = sizeof(token_list)/sizeof(CTokenEntry);

// --------------------------------------------------------------------------
// Read CEntryListData in from an open stream
// --------------------------------------------------------------------------

int CEntryListDataAsciiIO::ReadFileInternal( std::ifstream &stream )
{
std::string tokenid;
int result;

while ( ReadOpenClosePar( stream ) != 0 )
	{
	ReadString( stream, tokenid );

	if (tokenid.compare( str_blockname ) == 0 )
		{
		result = ReadFile( stream );
		}
	else
		{
		result = false;
		}
	}

return result;
}

// --------------------------------------------------------------------------
// Read CEntryListData in from an open stream
// --------------------------------------------------------------------------

int CEntryListDataAsciiIO::ReadFile( std::ifstream &stream )
{
int result;
std::string tokenid;

CExtensionEntry entry_listdata;

result = true;

if ( g_verbose )
	{
	std::cout << "Reading CEntryListDataAsciiIO" << std::endl;
	}

while ( ReadOpenClosePar( stream ) != 0 )
	{
	ReadString( stream, tokenid );

	if ( g_verbose > 1 )
		{
		std::cout << "Read Token = <" << tokenid << ">\n";
		}

	switch( token_match( tokenid, token_list, token_num ) )
		{
		case TOKEN_LISTDATA:
			entry_listdata.ReadFile( stream );
			push_back( entry_listdata );

			if ( g_verbose )
				{
				std::cout << "Read <listdata>\n";
				}
			break;

		default:
			std::cout << "CExtensionEntryListIO::Unknown token <" << tokenid << ">\n";
			break;
		}

	ReadClosePar( stream );
	}

stream.putback( '}' );

if ( g_verbose )
	{
	std::cout << "Reading complete." << std::endl << std::endl;
	}

return result;
}

// --------------------------------------------------------------------------
// Write data out to an open stream at specified tab depth
// --------------------------------------------------------------------------

int CEntryListDataAsciiIO::WriteFile( std::ofstream &stream, unsigned int depth )
{
return WriteFile( stream, depth, str_blockname );
}

// --------------------------------------------------------------------------
// Write data out to an open stream at specified tab depth
// --------------------------------------------------------------------------

int CEntryListDataAsciiIO::WriteFile( std::ofstream &stream, unsigned int depth, const char *pstr )
{
int result;

result = true;

WriteOpenPar( stream, depth, pstr );


for ( iterator it = begin(); it != end(); ++it )
	{
	result &= it->WriteFile( stream, depth );
	}

WriteClosePar( stream, depth );

return result;
}
