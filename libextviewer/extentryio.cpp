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
// Keyword std::strings
// ---------------------------------------------------------------------------

static const char *str_blockname = "extentry";

static const char *str_prefix = "prefix";
static const char *str_name = "name";
static const char *str_value = "value";
static const char *str_header = "header";
static const char *str_pfnproc = "pfnproc";
static const char *str_funcstart = "funcstart";
static const char *str_funcnum = "funcnum";
static const char *str_conststart = "conststart";
static const char *str_constnum = "constnum";
static const char *str_flags = "flags";

// --------------------------------------------------------------------------
// Token ID numbers
// --------------------------------------------------------------------------

#define TOKEN_BLOCKNAME	0x1001

#define TOKEN_PREFIX	0x1002
#define TOKEN_NAME	0x1003
#define TOKEN_VALUE	0x1004
#define TOKEN_HEADER	0x1005
#define TOKEN_PFNPROC	0x1006
#define TOKEN_FUNCSTART	0x1007
#define TOKEN_FUNCNUM	0x1008
#define TOKEN_CONSTSTART	0x1009
#define TOKEN_CONSTNUM	0x100A
#define TOKEN_FLAGS	0x100B

// --------------------------------------------------------------------------
// Token entry list
// --------------------------------------------------------------------------

static CTokenEntry token_list[] =
{
CTokenEntry( TOKEN_PREFIX, str_prefix ),
CTokenEntry( TOKEN_NAME, str_name ),
CTokenEntry( TOKEN_VALUE, str_value ),
CTokenEntry( TOKEN_HEADER, str_header ),
CTokenEntry( TOKEN_PFNPROC, str_pfnproc ),
CTokenEntry( TOKEN_FUNCSTART, str_funcstart ),
CTokenEntry( TOKEN_FUNCNUM, str_funcnum ),
CTokenEntry( TOKEN_CONSTSTART, str_conststart ),
CTokenEntry( TOKEN_CONSTNUM, str_constnum ),
CTokenEntry( TOKEN_FLAGS, str_flags )
};

static int token_num = sizeof(token_list)/sizeof(CTokenEntry);

// --------------------------------------------------------------------------
// Read CExtensionEntryData in from an open stream
// --------------------------------------------------------------------------

int CExtensionEntryDataAsciiIO::ReadFileInternal( std::ifstream &stream )
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
// Read CExtensionEntryData in from an open stream
// --------------------------------------------------------------------------

int CExtensionEntryDataAsciiIO::ReadFile( std::ifstream &stream )
{
int result;
std::string tokenid;

std::string entry_prefix;
std::string entry_name;
std::string entry_value;
std::string entry_header;
std::string entry_pfnproc;
int entry_funcstart;
int entry_funcnum;
int entry_conststart;
int entry_constnum;
int entry_flags;

result = true;


#ifdef DEBUG
std::cout << "CExtensionEntryDataAsciiIO::ReadFile\n";
#endif


if ( g_verbose )
	{
	std::cout << "Reading CExtensionEntryDataAsciiIO" << std::endl;
	}

while ( ReadOpenClosePar( stream ) != 0 )
	{
	ReadString( stream, tokenid );

#ifdef DEBUG
std::cout << "Token = " << tokenid << std::endl;
#endif

	if ( g_verbose > 1 )
		{
		std::cout << "Read Token = <" << tokenid << ">\n";
		}

	switch( token_match( tokenid, token_list, token_num ) )
		{
		case TOKEN_PREFIX:
			ReadQuotedString( stream, entry_prefix );
			m_prefix = entry_prefix;

#ifdef DEBUG
			std::cout << "Reading prefix" << std::endl;
#endif

			if ( g_verbose )
				{
				std::cout << "Read <prefix> = <" << entry_prefix << ">\n";
				}
			break;

		case TOKEN_NAME:
			ReadQuotedString( stream, entry_name );
			m_name = entry_name;

#ifdef DEBUG
			std::cout << "Reading name" << std::endl;
#endif

			if ( g_verbose )
				{
				std::cout << "Read <name> = <" << entry_name << ">\n";
				}
			break;

		case TOKEN_VALUE:
			ReadQuotedString( stream, entry_value );
			m_value = entry_value;

#ifdef DEBUG
			std::cout << "Reading value" << std::endl;
#endif

			if ( g_verbose )
				{
				std::cout << "Read <value> = <" << entry_value << ">\n";
				}
			break;

		case TOKEN_HEADER:
			ReadQuotedString( stream, entry_header );
			m_header = entry_header;

#ifdef DEBUG
			std::cout << "Reading header" << std::endl;
#endif

			if ( g_verbose )
				{
				std::cout << "Read <header> = <" << entry_header << ">\n";
				}
			break;

		case TOKEN_PFNPROC:
			ReadQuotedString( stream, entry_pfnproc );
			m_pfnproc = entry_pfnproc;

#ifdef DEBUG
			std::cout << "Reading pfnproc" << std::endl;
#endif

			if ( g_verbose )
				{
				std::cout << "Read <pfnproc> = <" << entry_pfnproc << ">\n";
				}
			break;

		case TOKEN_FUNCSTART:
			ReadInteger( stream, entry_funcstart );
			m_funcstart = entry_funcstart;

#ifdef DEBUG
			std::cout << "Reading funcstart" << std::endl;
#endif

			if ( g_verbose )
				{
				std::cout << "Read <funcstart> = <" << entry_funcstart << ">\n";
				}
			break;

		case TOKEN_FUNCNUM:
			ReadInteger( stream, entry_funcnum );
			m_funcnum = entry_funcnum;

#ifdef DEBUG
			std::cout << "Reading funcnum" << std::endl;
#endif

			if ( g_verbose )
				{
				std::cout << "Read <funcnum> = <" << entry_funcnum << ">\n";
				}
			break;

		case TOKEN_CONSTSTART:
			ReadInteger( stream, entry_conststart );
			m_conststart = entry_conststart;

#ifdef DEBUG
			std::cout << "Reading conststart" << std::endl;
#endif

			if ( g_verbose )
				{
				std::cout << "Read <conststart> = <" << entry_conststart << ">\n";
				}
			break;

		case TOKEN_CONSTNUM:
			ReadInteger( stream, entry_constnum );
			m_constnum = entry_constnum;

#ifdef DEBUG
			std::cout << "Reading constnum" << endl;
#endif

			if ( g_verbose )
				{
				std::cout << "Read <constnum> = <" << entry_constnum << ">\n";
				}
			break;

		case TOKEN_FLAGS:
			ReadInteger( stream, entry_flags );
			m_flags = entry_flags;

#ifdef DEBUG
			std::cout << "Reading flags" << endl;
#endif

			if ( g_verbose )
				{
				std::cout << "Read <flags> = <" << entry_flags << ">\n";
				}
			break;

		default:
			std::cout << "CExtensionEntryIO::Unknown token <" << tokenid << ">\n";
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

int CExtensionEntryDataAsciiIO::WriteFile( std::ofstream &stream, unsigned int depth )
{
return WriteFile( stream, depth, str_blockname );
}

// --------------------------------------------------------------------------
// Write data out to an open stream at specified tab depth
// --------------------------------------------------------------------------

int CExtensionEntryDataAsciiIO::WriteFile( std::ofstream &stream, unsigned int depth, const char *pstr )
{
int result;

result = true;

WriteOpenPar( stream, depth, pstr );

WriteNamedString( stream, depth, str_name, m_name );
WriteNamedInteger( stream, depth, str_flags, m_flags );

WriteClosePar( stream, depth );

return result;
}
