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

static const char *str_blockname = "scriptsettings";

#define STRING_BLOCKNAME	str_blockname

static const char *str_scriptmode = "scriptmode";

#define STRING_SCRIPTMODE	str_scriptmode
// --------------------------------------------------------------------------
// Token ID numbers
// --------------------------------------------------------------------------

#define TOKEN_BLOCKNAME	0x1001

#define TOKEN_SCRIPTMODE	0x1002

// --------------------------------------------------------------------------
// Token entry list
// --------------------------------------------------------------------------

static CTokenEntry token_list[] =
{
CTokenEntry( TOKEN_SCRIPTMODE, STRING_SCRIPTMODE )
};

static int token_num = sizeof(token_list)/sizeof(CTokenEntry);

// --------------------------------------------------------------------------
// Read CExtensionScriptSettingsIOData in from an open stream
// --------------------------------------------------------------------------

int CExtensionScriptSettingsIODataAsciiIO::ReadFileInternal( ifstream &stream )
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
// Read CExtensionScriptSettingsIOData in from an open stream
// --------------------------------------------------------------------------

int CExtensionScriptSettingsIODataAsciiIO::ReadFile( ifstream &stream )
{
int result;
string tokenid;

int entry_scriptmode;

result = true;


if ( g_verbose )
	{
	cout << "Reading CExtensionScriptSettingsIODataAsciiIO" << endl;
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
		case TOKEN_SCRIPTMODE:
			ReadInteger( stream, entry_scriptmode );
			m_scriptmode = entry_scriptmode;

			if ( g_verbose )
				{
				cout << "Read <scriptmode> = <" << entry_scriptmode << ">\n";
				}
			break;

		default:
			cout << "CExtensionScriptSettingsIO::Unknown token <" << tokenid << ">\n";
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

int CExtensionScriptSettingsIODataAsciiIO::WriteFile( ofstream &stream, unsigned int depth )
{
return( WriteFile( stream, depth, STRING_BLOCKNAME ) );
}

// --------------------------------------------------------------------------
// Write data out to an open stream at specified tab depth
// --------------------------------------------------------------------------

int CExtensionScriptSettingsIODataAsciiIO::WriteFile( ofstream &stream, unsigned int depth, const char *pstr )
{
int result;

result = true;

WriteOpenPar( stream, depth, pstr );

WriteNamedInteger( stream, depth, STRING_SCRIPTMODE, m_scriptmode );

WriteClosePar( stream, depth );

return( result );
}
