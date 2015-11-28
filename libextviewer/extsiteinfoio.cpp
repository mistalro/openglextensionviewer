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

static const char *str_blockname = "website";

#define STRING_BLOCKNAME	str_blockname

static const char *str_description = "description";
static const char *str_indexdirlocal = "indexdirlocal";
static const char *str_indexpagenet = "indexpagenet";
static const char *str_indexpagelocal = "indexpagelocal";
static const char *str_glheadernet = "glheadernet";
static const char *str_glheaderlocal = "glheaderlocal";
static const char *str_glxheadernet = "glxheadernet";
static const char *str_glxheaderlocal = "glxheaderlocal";
static const char *str_wglheadernet = "wglheadernet";
static const char *str_wglheaderlocal = "wglheaderlocal";
static const char *str_coreheadernet = "coreheadernet";
static const char *str_coreheaderlocal = "coreheaderlocal";
static const char *str_downloadflags = "downloadflags";
static const char *str_filetypefilters = "filetypefilters";

#define STRING_DESCRIPTION	str_description
#define STRING_INDEXDIRLOCAL	str_indexdirlocal
#define STRING_INDEXPAGENET	str_indexpagenet
#define STRING_INDEXPAGELOCAL	str_indexpagelocal
#define STRING_GLHEADERNET	str_glheadernet
#define STRING_GLHEADERLOCAL	str_glheaderlocal
#define STRING_GLXHEADERNET	str_glxheadernet
#define STRING_GLXHEADERLOCAL	str_glxheaderlocal
#define STRING_WGLHEADERNET	str_wglheadernet
#define STRING_WGLHEADERLOCAL	str_wglheaderlocal
#define STRING_COREHEADERNET	str_coreheadernet
#define STRING_COREHEADERLOCAL	str_coreheaderlocal
#define STRING_DOWNLOADFLAGS	str_downloadflags
#define STRING_FILETYPEFILTERS	str_filetypefilters
// --------------------------------------------------------------------------
// Token ID numbers
// --------------------------------------------------------------------------

#define TOKEN_BLOCKNAME	0x1001

#define TOKEN_DESCRIPTION	0x1002
#define TOKEN_INDEXDIRLOCAL	0x1003
#define TOKEN_INDEXPAGENET	0x1004
#define TOKEN_INDEXPAGELOCAL	0x1005
#define TOKEN_GLHEADERNET	0x1006
#define TOKEN_GLHEADERLOCAL	0x1007
#define TOKEN_GLXHEADERNET	0x1008
#define TOKEN_GLXHEADERLOCAL	0x1009
#define TOKEN_WGLHEADERNET	0x100A
#define TOKEN_WGLHEADERLOCAL	0x100B
#define TOKEN_COREHEADERNET	0x100C
#define TOKEN_COREHEADERLOCAL	0x100D
#define TOKEN_DOWNLOADFLAGS	0x100E
#define TOKEN_FILETYPEFILTERS	0x100F

// --------------------------------------------------------------------------
// Token entry list
// --------------------------------------------------------------------------

static CTokenEntry token_list[] =
{
CTokenEntry( TOKEN_DESCRIPTION, STRING_DESCRIPTION ),
CTokenEntry( TOKEN_INDEXDIRLOCAL, STRING_INDEXDIRLOCAL ),
CTokenEntry( TOKEN_INDEXPAGENET, STRING_INDEXPAGENET ),
CTokenEntry( TOKEN_INDEXPAGELOCAL, STRING_INDEXPAGELOCAL ),
CTokenEntry( TOKEN_GLHEADERNET, STRING_GLHEADERNET ),
CTokenEntry( TOKEN_GLHEADERLOCAL, STRING_GLHEADERLOCAL ),
CTokenEntry( TOKEN_GLXHEADERNET, STRING_GLXHEADERNET ),
CTokenEntry( TOKEN_GLXHEADERLOCAL, STRING_GLXHEADERLOCAL ),
CTokenEntry( TOKEN_WGLHEADERNET, STRING_WGLHEADERNET ),
CTokenEntry( TOKEN_WGLHEADERLOCAL, STRING_WGLHEADERLOCAL ),
CTokenEntry( TOKEN_COREHEADERNET, STRING_COREHEADERNET ),
CTokenEntry( TOKEN_COREHEADERLOCAL, STRING_COREHEADERLOCAL ),
CTokenEntry( TOKEN_DOWNLOADFLAGS, STRING_DOWNLOADFLAGS ),
CTokenEntry( TOKEN_FILETYPEFILTERS, STRING_FILETYPEFILTERS )
};

static int token_num = sizeof(token_list)/sizeof(CTokenEntry);

// --------------------------------------------------------------------------
// Read CExtensionSiteInfoIOData in from an open stream
// --------------------------------------------------------------------------

int CExtensionSiteInfoIODataAsciiIO::ReadFileInternal( ifstream &stream )
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
// Read CExtensionSiteInfoIOData in from an open stream
// --------------------------------------------------------------------------

int CExtensionSiteInfoIODataAsciiIO::ReadFile( ifstream &stream )
{
int result;
string tokenid;

string entry_description;
string entry_indexdirlocal;
string entry_indexpagenet;
string entry_indexpagelocal;
string entry_glheadernet;
string entry_glheaderlocal;
string entry_glxheadernet;
string entry_glxheaderlocal;
string entry_wglheadernet;
string entry_wglheaderlocal;
string entry_coreheadernet;
string entry_coreheaderlocal;
int entry_downloadflags;
string entry_filetypefilters;

result = true;


if ( g_verbose )
	{
	cout << "Reading CExtensionSiteInfoIODataAsciiIO" << endl;
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
		case TOKEN_DESCRIPTION:
			ReadQuotedString( stream, entry_description );
			m_description = entry_description;

			if ( g_verbose )
				{
				cout << "Read <description> = <" << entry_description << ">\n";
				}
			break;

		case TOKEN_INDEXDIRLOCAL:
			ReadQuotedString( stream, entry_indexdirlocal );
			m_indexdirlocal = entry_indexdirlocal;

			if ( g_verbose )
				{
				cout << "Read <indexdirlocal> = <" << entry_indexdirlocal << ">\n";
				}
			break;

		case TOKEN_INDEXPAGENET:
			ReadQuotedString( stream, entry_indexpagenet );
			m_indexpagenet = entry_indexpagenet;

			if ( g_verbose )
				{
				cout << "Read <indexpagenet> = <" << entry_indexpagenet << ">\n";
				}
			break;

		case TOKEN_INDEXPAGELOCAL:
			ReadQuotedString( stream, entry_indexpagelocal );
			m_indexpagelocal = entry_indexpagelocal;

			if ( g_verbose )
				{
				cout << "Read <indexpagelocal> = <" << entry_indexpagelocal << ">\n";
				}
			break;

		case TOKEN_GLHEADERNET:
			ReadQuotedString( stream, entry_glheadernet );
			m_glheadernet = entry_glheadernet;

			if ( g_verbose )
				{
				cout << "Read <glheadernet> = <" << entry_glheadernet << ">\n";
				}
			break;

		case TOKEN_GLHEADERLOCAL:
			ReadQuotedString( stream, entry_glheaderlocal );
			m_glheaderlocal = entry_glheaderlocal;

			if ( g_verbose )
				{
				cout << "Read <glheaderlocal> = <" << entry_glheaderlocal << ">\n";
				}
			break;

		case TOKEN_GLXHEADERNET:
			ReadQuotedString( stream, entry_glxheadernet );
			m_glxheadernet = entry_glxheadernet;

			if ( g_verbose )
				{
				cout << "Read <glxheadernet> = <" << entry_glxheadernet << ">\n";
				}
			break;

		case TOKEN_GLXHEADERLOCAL:
			ReadQuotedString( stream, entry_glxheaderlocal );
			m_glxheaderlocal = entry_glxheaderlocal;

			if ( g_verbose )
				{
				cout << "Read <glxheaderlocal> = <" << entry_glxheaderlocal << ">\n";
				}
			break;

		case TOKEN_WGLHEADERNET:
			ReadQuotedString( stream, entry_wglheadernet );
			m_wglheadernet = entry_wglheadernet;

			if ( g_verbose )
				{
				cout << "Read <wglheadernet> = <" << entry_wglheadernet << ">\n";
				}
			break;

		case TOKEN_WGLHEADERLOCAL:
			ReadQuotedString( stream, entry_wglheaderlocal );
			m_wglheaderlocal = entry_wglheaderlocal;

			if ( g_verbose )
				{
				cout << "Read <wglheaderlocal> = <" << entry_wglheaderlocal << ">\n";
				}
			break;

		case TOKEN_COREHEADERNET:
			ReadQuotedString( stream, entry_coreheadernet );
			m_coreheadernet = entry_coreheadernet;

			if ( g_verbose )
				{
				cout << "Read <coreheadernet> = <" << entry_coreheadernet << ">\n";
				}
			break;

		case TOKEN_COREHEADERLOCAL:
			ReadQuotedString( stream, entry_coreheaderlocal );
			m_coreheaderlocal = entry_coreheaderlocal;

			if ( g_verbose )
				{
				cout << "Read <coreheaderlocal> = <" << entry_coreheaderlocal << ">\n";
				}
			break;

		case TOKEN_DOWNLOADFLAGS:
			ReadInteger( stream, entry_downloadflags );
			m_downloadflags = entry_downloadflags;

			if ( g_verbose )
				{
				cout << "Read <downloadflags> = <" << entry_downloadflags << ">\n";
				}
			break;

		case TOKEN_FILETYPEFILTERS:
			ReadQuotedString( stream, entry_filetypefilters );
			m_filetypefilter = entry_filetypefilters;

			if ( g_verbose )
				{
				cout << "Read <filetypefilters> = <" << entry_filetypefilters << ">\n";
				}
			break;

		default:
			cout << "CExtensionSiteInfoIO::Unknown token <" << tokenid << ">\n";
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

int CExtensionSiteInfoIODataAsciiIO::WriteFile( ofstream &stream, unsigned int depth )
{
return( WriteFile( stream, depth, STRING_BLOCKNAME ) );
}

// --------------------------------------------------------------------------
// Write data out to an open stream at specified tab depth
// --------------------------------------------------------------------------

int CExtensionSiteInfoIODataAsciiIO::WriteFile( ofstream &stream, unsigned int depth, const char *pstr )
{
int result;

result = true;

WriteOpenPar( stream, depth, pstr );

WriteNamedString( stream, depth, STRING_DESCRIPTION, m_description );
WriteNamedString( stream, depth, STRING_INDEXDIRLOCAL, m_indexdirlocal );
WriteNamedString( stream, depth, STRING_INDEXPAGENET, m_indexpagenet );
WriteNamedString( stream, depth, STRING_INDEXPAGELOCAL, m_indexpagelocal );
WriteNamedString( stream, depth, STRING_GLHEADERNET, m_glheadernet );
WriteNamedString( stream, depth, STRING_GLHEADERLOCAL, m_glheaderlocal );
WriteNamedString( stream, depth, STRING_GLXHEADERNET, m_glxheadernet );
WriteNamedString( stream, depth, STRING_GLXHEADERLOCAL, m_glxheaderlocal );
WriteNamedString( stream, depth, STRING_WGLHEADERNET, m_wglheadernet );
WriteNamedString( stream, depth, STRING_WGLHEADERLOCAL, m_wglheaderlocal );
WriteNamedString( stream, depth, STRING_COREHEADERNET, m_coreheadernet );
WriteNamedString( stream, depth, STRING_COREHEADERLOCAL, m_coreheaderlocal );
WriteNamedInteger( stream, depth, STRING_DOWNLOADFLAGS, m_downloadflags );
WriteNamedString( stream, depth, STRING_FILETYPEFILTERS, m_filetypefilter );

WriteClosePar( stream, depth );

return( result );
}
