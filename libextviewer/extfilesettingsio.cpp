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

static const char *str_blockname = "outputsettings";

#define STRING_BLOCKNAME	str_blockname

static const char *str_outputheader = "outputheader";
static const char *str_outputsource = "outputsource";
static const char *str_scriptfile = "scriptfile";
static const char *str_classname = "classname";
static const char *str_classnamedcolon = "classnamedcolon";
static const char *str_cppmode = "cppmode";
static const char *str_useglxgetprocaddressarb = "useglxgetprocaddressarb";

#define STRING_OUTPUTHEADER	str_outputheader
#define STRING_OUTPUTSOURCE	str_outputsource
#define STRING_SCRIPTFILE	str_scriptfile
#define STRING_CLASSNAME	str_classname
#define STRING_CLASSNAMEDCOLON	str_classnamedcolon
#define STRING_CPPMODE		str_cppmode
#define STRING_USEGLXGETPROCADDRESSARB  str_useglxgetprocaddressarb

// --------------------------------------------------------------------------
// Token ID numbers
// --------------------------------------------------------------------------

#define TOKEN_BLOCKNAME	0x1001

#define TOKEN_OUTPUTHEADER	0x1002
#define TOKEN_OUTPUTSOURCE	0x1003
#define TOKEN_SCRIPTFILE	0x1004
#define TOKEN_CLASSNAME	0x1005
#define TOKEN_CLASSNAMEDCOLON	0x1006
#define TOKEN_CPPMODE	0x1007
#define TOKEN_USEGLXGETPROCADDRESSARB 0x1008

// --------------------------------------------------------------------------
// Token entry list
// --------------------------------------------------------------------------

static CTokenEntry token_list[] =
{
CTokenEntry( TOKEN_OUTPUTHEADER, STRING_OUTPUTHEADER ),
CTokenEntry( TOKEN_OUTPUTSOURCE, STRING_OUTPUTSOURCE ),
CTokenEntry( TOKEN_SCRIPTFILE, STRING_SCRIPTFILE ),
CTokenEntry( TOKEN_CLASSNAME, STRING_CLASSNAME ),
CTokenEntry( TOKEN_CLASSNAMEDCOLON, STRING_CLASSNAMEDCOLON ),
CTokenEntry( TOKEN_CPPMODE, STRING_CPPMODE ),
CTokenEntry( TOKEN_USEGLXGETPROCADDRESSARB, STRING_USEGLXGETPROCADDRESSARB )
};

static int token_num = sizeof(token_list)/sizeof(CTokenEntry);

// --------------------------------------------------------------------------
// Read COutputFileSettingsIOData in from an open stream
// --------------------------------------------------------------------------

int COutputFileSettingsIODataAsciiIO::ReadFileInternal( std::ifstream &stream )
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

return result;
}

// --------------------------------------------------------------------------
// Read COutputFileSettingsIOData in from an open stream
// --------------------------------------------------------------------------

int COutputFileSettingsIODataAsciiIO::ReadFile( std::ifstream &stream )
{
int result;
std::string tokenid;

std::string entry_outputheader;
std::string entry_outputsource;
std::string entry_scriptfile;
std::string entry_classname;
std::string entry_classnamedcolon;
int entry_cppmode;
int entry_useglxgetprocaddressARB;

result = true;


if ( g_verbose )
	{
	std::cout << "Reading COutputFileSettingsIODataAsciiIO" << std::endl;
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
		case TOKEN_OUTPUTHEADER:
			ReadQuotedString( stream, entry_outputheader );
			m_outputheaderfile = entry_outputheader;

			if ( g_verbose )
				{
				std::cout << "Read <outputheader> = <" << entry_outputheader << ">\n";
				}
			break;

		case TOKEN_OUTPUTSOURCE:
			ReadQuotedString( stream, entry_outputsource );
			m_outputsourcefile = entry_outputsource;

			if ( g_verbose )
				{
				std::cout << "Read <outputsource> = <" << entry_outputsource << ">\n";
				}
			break;

		case TOKEN_SCRIPTFILE:
			ReadQuotedString( stream, entry_scriptfile );
			m_scriptfile = entry_scriptfile;

			if ( g_verbose )
				{
				std::cout << "Read <scriptfile> = <" << entry_scriptfile << ">\n";
				}
			break;

		case TOKEN_CLASSNAME:
			ReadQuotedString( stream, entry_classname );
			m_classname = entry_classname;

			if ( g_verbose )
				{
				std::cout << "Read <classname> = <" << entry_classname << ">\n";
				}
			break;

		case TOKEN_CLASSNAMEDCOLON:
			ReadQuotedString( stream, entry_classnamedcolon );
			m_classnamedcolon = entry_classnamedcolon;

			if ( g_verbose )
				{
				std::cout << "Read <classnamedcolon> = <" << entry_classnamedcolon << ">\n";
				}
			break;

		case TOKEN_CPPMODE:
			ReadInteger( stream, entry_cppmode );
			m_cppmode = entry_cppmode;

			if ( g_verbose )
				{
				std::cout << "Read <cppmode> = <" << entry_cppmode << ">\n";
				}
			break;

		case TOKEN_USEGLXGETPROCADDRESSARB:
			ReadInteger( stream, entry_useglxgetprocaddressARB );

			m_useglxgetprocaddressARB = entry_useglxgetprocaddressARB;
			if ( g_verbose )
				{
				std::cout << "Read <useglxgetprocaddressarb> = <" << entry_cppmode << ">\n";
				}
			break;

		default:
			std::cout << "COutputFileSettingsIO::Unknown token <" << tokenid << ">\n";
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

int COutputFileSettingsIODataAsciiIO::WriteFile( std::ofstream &stream, unsigned int depth )
{
return WriteFile( stream, depth, STRING_BLOCKNAME );
}

// --------------------------------------------------------------------------
// Write data out to an open stream at specified tab depth
// --------------------------------------------------------------------------

int COutputFileSettingsIODataAsciiIO::WriteFile( std::ofstream &stream, unsigned int depth, const char *pstr )
{
int result;

result = true;

WriteOpenPar( stream, depth, pstr );

WriteNamedString( stream, depth, STRING_OUTPUTHEADER, m_outputheaderfile );
WriteNamedString( stream, depth, STRING_OUTPUTSOURCE, m_outputsourcefile );
WriteNamedString( stream, depth, STRING_SCRIPTFILE, m_scriptfile );
WriteNamedString( stream, depth, STRING_CLASSNAME, m_classname );
WriteNamedString( stream, depth, STRING_CLASSNAMEDCOLON, m_classnamedcolon );
WriteNamedInteger( stream, depth, STRING_CPPMODE, m_cppmode );
WriteNamedInteger( stream, depth, STRING_USEGLXGETPROCADDRESSARB, m_useglxgetprocaddressARB );

WriteClosePar( stream, depth );

return result;
}
