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

static const char *str_blockname = "headerfilesets";

#define STRING_BLOCKNAME	str_blockname

static const char *str_systemlist = "systemlist";
static const char *str_newlist = "newlist";
static const char *str_ignorelist = "ignorelist";
static const char *str_vendorlist = "vendorlist";
static const char *str_versionlist = "versionlist";
static const char *str_savedstates = "savedstates";

#define STRING_SYSTEMLIST	str_systemlist
#define STRING_NEWLIST	str_newlist
#define STRING_IGNORELIST	str_ignorelist
#define STRING_VENDORLIST	str_vendorlist
#define STRING_VERSIONLIST	str_versionlist
#define STRING_SAVEDSTATES	str_savedstates
// --------------------------------------------------------------------------
// Token ID numbers
// --------------------------------------------------------------------------

#define TOKEN_BLOCKNAME	0x1001

#define TOKEN_SYSTEMLIST	0x1006
#define TOKEN_NEWLIST	0x1007
#define TOKEN_IGNORELIST	0x1008
#define TOKEN_VENDORLIST	0x1009
#define TOKEN_VERSIONLIST	0x100A
#define TOKEN_SAVEDSTATES	0x100B

// --------------------------------------------------------------------------
// Token entry list
// --------------------------------------------------------------------------

static CTokenEntry token_list[] =
{
CTokenEntry( TOKEN_SYSTEMLIST, STRING_SYSTEMLIST ),
CTokenEntry( TOKEN_NEWLIST, STRING_NEWLIST ),
CTokenEntry( TOKEN_IGNORELIST, STRING_IGNORELIST ),
CTokenEntry( TOKEN_VENDORLIST, STRING_VENDORLIST ),
CTokenEntry( TOKEN_VERSIONLIST, STRING_VERSIONLIST ),
CTokenEntry( TOKEN_SAVEDSTATES, STRING_SAVEDSTATES )
};

static int token_num = sizeof(token_list)/sizeof(CTokenEntry);

// --------------------------------------------------------------------------
// Read CExtensionHeaderFileSettingsIOData in from an open stream
// --------------------------------------------------------------------------

int CExtensionHeaderFileSettingsIODataAsciiIO::ReadFileInternal( ifstream &stream )
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
// Read CExtensionHeaderFileSettingsIOData in from an open stream
// --------------------------------------------------------------------------

int CExtensionHeaderFileSettingsIODataAsciiIO::ReadFile( ifstream &stream )
{
int result;
string tokenid;

int entry_savedstates;

result = true;


if ( g_verbose )
	{
	cout << "Reading CExtensionHeaderFileSettingsIODataAsciiIO" << endl;
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
		case TOKEN_SYSTEMLIST:
			m_systemlist.ReadFile( stream );

			if ( g_verbose )
				{
				cout << "Read <systemlist>\n";
				}
			break;

		case TOKEN_NEWLIST:
			m_newlist.ReadFile( stream );

			if ( g_verbose )
				{
				cout << "Read <newlist>\n";
				}
			break;

		case TOKEN_IGNORELIST:
			m_ignorelist.ReadFile( stream );

			if ( g_verbose )
				{
				cout << "Read <ignorelist>\n";
				}
			break;

		case TOKEN_VENDORLIST:
			m_vendorlist.ReadFile( stream );

			if ( g_verbose )
				{
				cout << "Read <vendorlist>\n";
				}
			break;

		case TOKEN_VERSIONLIST:
			m_versionlist.ReadFile( stream );

			if ( g_verbose )
				{
				cout << "Read <versionlist>\n";
				}
			break;

		case TOKEN_SAVEDSTATES:
			ReadInteger( stream, entry_savedstates );
			m_savedstates = entry_savedstates;

			if ( g_verbose )
				{
				cout << "Read <savedstates> = <" << entry_savedstates << ">\n";
				}
			break;

		default:
			cout << "CExtensionHeaderFileSetIO::Unknown token <" << tokenid << ">\n";
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

int CExtensionHeaderFileSettingsIODataAsciiIO::WriteFile( ofstream &stream, unsigned int depth )
{
return( WriteFile( stream, depth, STRING_BLOCKNAME ) );
}

// --------------------------------------------------------------------------
// Write data out to an open stream at specified tab depth
// --------------------------------------------------------------------------

int CExtensionHeaderFileSettingsIODataAsciiIO::WriteFile( ofstream &stream, unsigned int depth, const char *pstr )
{
int result;

result = true;

WriteOpenPar( stream, depth, pstr );

m_systemlist.WriteFile( stream, depth, STRING_SYSTEMLIST );
m_newlist.WriteFile( stream, depth, STRING_NEWLIST );
m_ignorelist.WriteFile( stream, depth, STRING_IGNORELIST );
m_vendorlist.WriteFile( stream, depth, STRING_VENDORLIST );
m_versionlist.WriteFile( stream, depth, STRING_VERSIONLIST );
WriteNamedInteger( stream, depth, STRING_SAVEDSTATES, m_savedstates );

WriteClosePar( stream, depth );

return( result );
}
