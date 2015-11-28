// ---------------------------------------------------------------------------
// Copyright: (C) VFX Research 2002 - 2014. All Rights Reserved.
// ---------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>

using namespace std;

#include "extensionlib.h"

// ---------------------------------------------------------------------------
// Keyword strings
// ---------------------------------------------------------------------------

static const char *str_blockname = "registrysettings";

#define STRING_BLOCKNAME	str_blockname

static const char *str_downloadstatus = "downloadstatus";
static const char *str_dryrunmode = "dryrunmode";

#define STRING_DOWNLOADSTATUS	str_downloadstatus
#define STRING_DRYRUNMODE	str_dryrunmode
// --------------------------------------------------------------------------
// Token ID numbers
// --------------------------------------------------------------------------

#define TOKEN_BLOCKNAME	0x1001

#define TOKEN_DOWNLOADSTATUS	0x1002
#define TOKEN_DRYRUNMODE	0x1003

// --------------------------------------------------------------------------
// Token entry list
// --------------------------------------------------------------------------

static CTokenEntry token_list[] =
{
CTokenEntry( TOKEN_DOWNLOADSTATUS, STRING_DOWNLOADSTATUS ),
CTokenEntry( TOKEN_DRYRUNMODE, STRING_DRYRUNMODE )
};

static int token_num = sizeof(token_list)/sizeof(CTokenEntry);

// --------------------------------------------------------------------------
// Read CExtensionRegistrySettingsIOData in from an open stream
// --------------------------------------------------------------------------

int CExtensionRegistrySettingsIODataAsciiIO::ReadFileInternal( ifstream &stream )
{
string tokenid;
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
// Read CExtensionRegistrySettingsIOData in from an open stream
// --------------------------------------------------------------------------

int CExtensionRegistrySettingsIODataAsciiIO::ReadFile( ifstream &stream )
{
int result;
string tokenid;

int entry_downloadstatus;
int entry_dryrunmode;

result = true;


if ( g_verbose )
	{
	cout << "Reading CExtensionRegistrySettingsIODataAsciiIO" << endl;
	}

while ( ReadOpenClosePar( stream ) != 0 )
	{
	ReadString( stream, tokenid );

	if ( g_verbose > 1 )
		{
		cout << "Read Token = <" << tokenid << ">\n";
		}

	switch( token_match( tokenid, token_list, token_num ) )
		{
		case TOKEN_DOWNLOADSTATUS:
			ReadInteger( stream, entry_downloadstatus );
			m_downloadstatus = entry_downloadstatus;

			if ( g_verbose )
				{
				cout << "Read <downloadstatus> = <" << entry_downloadstatus << ">\n";
				}
			break;

		case TOKEN_DRYRUNMODE:
			ReadInteger( stream, entry_dryrunmode );
			m_dryrunmode = entry_dryrunmode;

			if ( g_verbose )
				{
				cout << "Read <dryrunmode> = <" << entry_dryrunmode << ">\n";
				}
			break;

		default:
			cout << "CExtensionRegistrySettingsIO::Unknown token <" << tokenid << ">\n";
			break;
		}

	ReadClosePar( stream );
	}

stream.putback( '}' );

if ( g_verbose )
	{
	cout << "Reading complete." << endl << endl;
	}

return( result );
}

// --------------------------------------------------------------------------
// Write data out to an open stream at specified tab depth
// --------------------------------------------------------------------------

int CExtensionRegistrySettingsIODataAsciiIO::WriteFile( ofstream &stream, unsigned int depth )
{
return( WriteFile( stream, depth, STRING_BLOCKNAME ) );
}

// --------------------------------------------------------------------------
// Write data out to an open stream at specified tab depth
// --------------------------------------------------------------------------

int CExtensionRegistrySettingsIODataAsciiIO::WriteFile( ofstream &stream, unsigned int depth, const char *pstr )
{
int result;

result = true;

WriteOpenPar( stream, depth, pstr );

WriteNamedInteger( stream, depth, STRING_DOWNLOADSTATUS, m_downloadstatus );
WriteNamedInteger( stream, depth, STRING_DRYRUNMODE, m_dryrunmode );

WriteClosePar( stream, depth );

return( result );
}
