// --------------------------------------------------------------------------
// File:   io_string.cpp
//
// Purpose: Routines to handle strings
//
// Author:  Michael S. A. Robb
//
// Date:    2005/01/27
// ---------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "filesysascii.h"

// ==========================================================================
// UTILITY FUNCTIONS
// ==========================================================================

// --------------------------------------------------------------------------
// Utility function for making a string lower case
// --------------------------------------------------------------------------

void strlwr( std::string &pstr )
{
for (unsigned int pn = 0; pn < pstr.size(); pn++ )
        {
        pstr[pn] = tolower( pstr[pn] );
        }
}

// --------------------------------------------------------------------------
// Utility function for making a string upper case
// --------------------------------------------------------------------------

void strupr( std::string &pstr )
{
for ( unsigned int pn = 0; pn < pstr.size(); pn++ )
        {
        pstr[pn] = toupper( pstr[pn] );
        }
}

// ==========================================================================
// READ ROUTINES
// ==========================================================================

// --------------------------------------------------------------------------
// Read a single block of data from a file
// --------------------------------------------------------------------------

void CFileSystemString::ReadQuotedString( std::ifstream &stream, std::string &string )
{
int ch, oldch, done;

string.clear();

while ( stream.get() != '\"' );         // Wait until "

done = 0;
oldch = 0;

string = "";

while ( !done )                         // Wait until " or string filled
        {
        ch = stream.get();

        if ( (ch == '\"') && (oldch != '\\' ) ) // Found " but not \"
		{
                done++;
		}

        if ( ( ch == '\\' ) && ( oldch == '\\' ) )
		{
                string += ch;
		}
        else
        if ( ( ch != '\\' ) && ( !done ) )      // Save character
		{
                string += ch;
		}

        oldch = ch;                     // Keep 1 character cache
        }

if (ch != '\"')                         // If no " found, then keep looking
	{
        while ( stream.get() != '\"' );
	}
}

void CFileSystemString::WriteQuotedString( std::ofstream &stream, std::string &string )
{
const char *pdata;

stream << "\"";

pdata = string.c_str();

if ( pdata )
	{
        while ( *pdata )
                {
                if ( *pdata == '\"' )
			{
                        stream << "\\\"";
			}
                else
			{
                        stream << *pdata;
			}

                pdata++;
                }
	}
stream << "\" ";
}

// --------------------------------------------------------------------------
// Read a unquoted string
// --------------------------------------------------------------------------

void CFileSystemString::ReadString( std::ifstream &stream, std::string &string )
{
int ch;

string.clear();

while ( !stream.eof() && ( isspace( (ch = stream.peek()) ) ) )
	{
        stream.get();
	}


while ( !stream.eof() && ( !isspace( (ch = stream.peek()) ) ) && (ch!='}' ) )
	{
        string += stream.get();
	}
}

// ==========================================================================
// WRITE ROUTINES
// ==========================================================================

// --------------------------------------------------------------------------
// Write named string
// --------------------------------------------------------------------------

void CFileSystemString::WriteNamedString( std::ofstream &stream, unsigned int depth,
                                std::string &strname, std::string &string )
{
WriteTabbedDepth( stream, depth );

stream << "{" << strname.c_str() << " ";
WriteQuotedString( stream, string );
stream << " }\n";
}

void CFileSystemString::WriteNamedString( std::ofstream &stream, unsigned int depth,
                                const char *name, std::string &string )
{
WriteTabbedDepth( stream, depth );

stream << "{" << name << " ";
WriteQuotedString( stream, string );
stream << " }\n";
}

