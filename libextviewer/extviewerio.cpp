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

static const char *str_blockname = "extcreator";

#define STRING_BLOCKNAME	str_blockname

static const char *str_registrysettings = "registrysettings";
static const char *str_headerfileset = "headerfileset";
static const char *str_sitelist = "sitelist";
static const char *str_scriptsettings = "scriptsettings";
static const char *str_outputsettings = "outputsettings";
static const char *str_configfilesettings = "configfilesettings";

#define STRING_REGISTRYSETTINGS	str_registrysettings
#define STRING_HEADERFILESET	str_headerfileset
#define STRING_SITELIST	str_sitelist
#define STRING_SCRIPTSETTINGS	str_scriptsettings
#define STRING_OUTPUTSETTINGS	str_outputsettings
#define STRING_CONFIGFILESETTINGS	str_configfilesettings

// --------------------------------------------------------------------------
// Token ID numbers
// --------------------------------------------------------------------------

#define TOKEN_BLOCKNAME	0x1001

#define TOKEN_REGISTRYSETTINGS	0x1002
#define TOKEN_HEADERFILESET	0x1003
#define TOKEN_SITELIST	0x1004
#define TOKEN_SCRIPTSETTINGS	0x1005
#define TOKEN_OUTPUTSETTINGS	0x1006
#define TOKEN_CONFIGFILESETTINGS	0x1007

// --------------------------------------------------------------------------
// Token entry list
// --------------------------------------------------------------------------

static CTokenEntry token_list[] =
{
CTokenEntry( TOKEN_REGISTRYSETTINGS, STRING_REGISTRYSETTINGS ),
CTokenEntry( TOKEN_HEADERFILESET, STRING_HEADERFILESET ),
CTokenEntry( TOKEN_SITELIST, STRING_SITELIST ),
CTokenEntry( TOKEN_SCRIPTSETTINGS, STRING_SCRIPTSETTINGS ),
CTokenEntry( TOKEN_OUTPUTSETTINGS, STRING_OUTPUTSETTINGS ),
CTokenEntry( TOKEN_CONFIGFILESETTINGS, STRING_CONFIGFILESETTINGS )
};

static int token_num = sizeof(token_list)/sizeof(CTokenEntry);

// --------------------------------------------------------------------------
// Read CExtensionViewerIOData in from an open stream
// --------------------------------------------------------------------------

int CExtensionViewerIODataAsciiIO::ReadFileInternal( std::ifstream &stream )
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
// Read CExtensionViewerIOData in from an open stream
// --------------------------------------------------------------------------

int CExtensionViewerIODataAsciiIO::ReadFile( std::ifstream &stream )
{
int result = true;
std::string tokenid;

if ( g_verbose )
	{
	std::cout << "Reading CExtensionViewerIODataAsciiIO" << std::endl;
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
		case TOKEN_REGISTRYSETTINGS:
			m_registrysettings.ReadFile( stream );

			if ( g_verbose )
				{
				std::cout << "Read <registrysettings>\n";
				}
			break;

		case TOKEN_HEADERFILESET:
			m_headerfileset.ReadFile( stream );

			if ( g_verbose )
				{
				std::cout << "Read <headerfileset>\n";
				}
			break;

		case TOKEN_SITELIST:
			m_sitelist.ReadFile( stream );

			if ( g_verbose )
				{
				std::cout << "Read <sitelist>\n";
				}
			break;

		case TOKEN_SCRIPTSETTINGS:
			m_scriptsettings.ReadFile( stream );

			if ( g_verbose )
				{
				std::cout << "Read <scriptsettings>\n";
				}
			break;

		case TOKEN_OUTPUTSETTINGS:
			m_outputfilesettings.ReadFile( stream );

			if ( g_verbose )
				{
				std::cout << "Read <outputsettings>\n";
				}
			break;

		case TOKEN_CONFIGFILESETTINGS:
			m_configfilesettings.ReadFile( stream );

			if ( g_verbose )
				{
				std::cout << "Read <configfilesettings>\n";
				}
			break;

		default:
			std::cout << "CExtensionViewerIO::Unknown token <" << tokenid << ">\n";
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

int CExtensionViewerIODataAsciiIO::WriteFile( std::ofstream &stream, unsigned int depth )
{
return WriteFile( stream, depth, STRING_BLOCKNAME );
}

// --------------------------------------------------------------------------
// Write data out to an open stream at specified tab depth
// --------------------------------------------------------------------------

int CExtensionViewerIODataAsciiIO::WriteFile( std::ofstream &stream, unsigned int depth, const char *pstr )
{
int result;

result = true;

WriteOpenPar( stream, depth, pstr );

m_registrysettings.WriteFile( stream, depth, STRING_REGISTRYSETTINGS );
m_headerfileset.WriteFile( stream, depth, STRING_HEADERFILESET );
m_sitelist.WriteFile( stream, depth, STRING_SITELIST );
m_scriptsettings.WriteFile( stream, depth, STRING_SCRIPTSETTINGS );
m_outputfilesettings.WriteFile( stream, depth, STRING_OUTPUTSETTINGS );
m_configfilesettings.WriteFile( stream, depth, STRING_CONFIGFILESETTINGS );

WriteClosePar( stream, depth );

return result;
}
