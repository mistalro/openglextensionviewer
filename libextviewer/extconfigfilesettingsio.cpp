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

static const char *str_blockname = "configfilesettings";

#define STRING_BLOCKNAME	str_blockname

static const char *str_newconfigflag = "newconfigflag";
static const char *str_configsettingsfile = "configsettingsfile";
static const char *str_autoreadheaderflags = "autoreadheaderflags";
static const char *str_autoloadconfigflags = "autoloadconfigflags";
static const char *str_autosaveconfigflags = "autosaveconfigflags";

#define STRING_NEWCONFIGFLAG	str_newconfigflag
#define STRING_CONFIGSETTINGSFILE	str_configsettingsfile
#define STRING_AUTOREADHEADERFLAGS	str_autoreadheaderflags
#define STRING_AUTOLOADCONFIGFLAGS	str_autoloadconfigflags
#define STRING_AUTOSAVECONFIGFLAGS	str_autosaveconfigflags
// --------------------------------------------------------------------------
// Token ID numbers
// --------------------------------------------------------------------------

#define TOKEN_BLOCKNAME	0x1001

#define TOKEN_NEWCONFIGFLAG	0x1002
#define TOKEN_CONFIGSETTINGSFILE	0x1003
#define TOKEN_AUTOREADHEADERFLAGS	0x1004
#define TOKEN_AUTOLOADCONFIGFLAGS	0x1005
#define TOKEN_AUTOSAVECONFIGFLAGS	0x1006

// --------------------------------------------------------------------------
// Token entry list
// --------------------------------------------------------------------------

static CTokenEntry token_list[] =
{
CTokenEntry( TOKEN_NEWCONFIGFLAG, STRING_NEWCONFIGFLAG ),
CTokenEntry( TOKEN_CONFIGSETTINGSFILE, STRING_CONFIGSETTINGSFILE ),
CTokenEntry( TOKEN_AUTOREADHEADERFLAGS, STRING_AUTOREADHEADERFLAGS ),
CTokenEntry( TOKEN_AUTOLOADCONFIGFLAGS, STRING_AUTOLOADCONFIGFLAGS ),
CTokenEntry( TOKEN_AUTOSAVECONFIGFLAGS, STRING_AUTOSAVECONFIGFLAGS )
};

static int token_num = sizeof(token_list)/sizeof(CTokenEntry);

// --------------------------------------------------------------------------
// Read CConfigurationFileSettingsData in from an open stream
// --------------------------------------------------------------------------

int CConfigurationFileSettingsDataAsciiIO::ReadFileInternal( std::ifstream &stream )
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
// Read CConfigurationFileSettingsData in from an open stream
// --------------------------------------------------------------------------

int CConfigurationFileSettingsDataAsciiIO::ReadFile( std::ifstream &stream )
{
int result;
std::string tokenid;

int entry_newconfigflag;
std::string entry_configsettingsfile;
int entry_autoreadheaderflags;
int entry_autoloadconfigflags;
int entry_autosaveconfigflags;

result = true;


if ( g_verbose )
	{
	std::cout << "Reading CConfigurationFileSettingsDataAsciiIO" << std::endl;
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
		case TOKEN_NEWCONFIGFLAG:
			ReadInteger( stream, entry_newconfigflag );
			m_newconfigflag = entry_newconfigflag;

			if ( g_verbose )
				{
				std::cout << "Read <newconfigflag> = <" << entry_newconfigflag << ">\n";
				}
			break;

		case TOKEN_CONFIGSETTINGSFILE:
			ReadQuotedString( stream, entry_configsettingsfile );
			m_configfile = entry_configsettingsfile;

			if ( g_verbose )
				{
				std::cout << "Read <configsettingsfile> = <" << entry_configsettingsfile << ">\n";
				}
			break;

		case TOKEN_AUTOREADHEADERFLAGS:
			ReadInteger( stream, entry_autoreadheaderflags );
			m_autoreadheaderflags = entry_autoreadheaderflags;

			if ( g_verbose )
				{
				std::cout << "Read <autoreadheaderflags> = <" << entry_autoreadheaderflags << ">\n";
				}
			break;

		case TOKEN_AUTOLOADCONFIGFLAGS:
			ReadInteger( stream, entry_autoloadconfigflags );
			m_autoloadconfigflags = entry_autoloadconfigflags;

			if ( g_verbose )
				{
				std::cout << "Read <autoloadconfigflags> = <" << entry_autoloadconfigflags << ">\n";
				}
			break;

		case TOKEN_AUTOSAVECONFIGFLAGS:
			ReadInteger( stream, entry_autosaveconfigflags );
			m_autosaveconfigflags = entry_autosaveconfigflags;

			if ( g_verbose )
				{
				std::cout << "Read <autosaveconfigflags> = <" << entry_autosaveconfigflags << ">\n";
				}
			break;

		default:
			std::cout << "CConfigurationFileSettingsIO::Unknown token <" << tokenid << ">\n";
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

int CConfigurationFileSettingsDataAsciiIO::WriteFile( std::ofstream &stream, unsigned int depth )
{
return WriteFile( stream, depth, STRING_BLOCKNAME );
}

// --------------------------------------------------------------------------
// Write data out to an open stream at specified tab depth
// --------------------------------------------------------------------------

int CConfigurationFileSettingsDataAsciiIO::WriteFile( std::ofstream &stream, unsigned int depth, const char *pstr )
{
int result;

result = true;

WriteOpenPar( stream, depth, pstr );

WriteNamedString( stream, depth, STRING_CONFIGSETTINGSFILE, m_configfile );
WriteNamedInteger( stream, depth, STRING_AUTOREADHEADERFLAGS, m_autoreadheaderflags );
WriteNamedInteger( stream, depth, STRING_AUTOLOADCONFIGFLAGS, m_autoloadconfigflags );
WriteNamedInteger( stream, depth, STRING_AUTOSAVECONFIGFLAGS, m_autosaveconfigflags );

WriteClosePar( stream, depth );

return result;
}
