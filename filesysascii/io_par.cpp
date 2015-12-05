// --------------------------------------------------------------------------
// File:   io_par.cpp
//
// Purpose: Routines to handle parenthesis
//
// Author:  Michael S. A. Robb
//
// Date:    2005/01/27
// --------------------------------------------------------------------------//

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "filesysascii.h"

// --------------------------------------------------------------------------
// Keep reading characters until an open parenthesis or EOF is read
// --------------------------------------------------------------------------

bool CFileSystemPar::ReadOpenPar( std::ifstream &stream )
{
int ch;

while ( !stream.eof() && ( (ch = stream.get() ) != '{' ) );

return '{' == ch;
}

// --------------------------------------------------------------------------
// Keep reading characters until an close parenthesis or EOF is read
// --------------------------------------------------------------------------

bool CFileSystemPar::ReadClosePar( std::ifstream &stream )
{
int ch;

while ( !stream.eof() && (( ch = stream.get() ) != '}' ) );

return '}' == ch;
}

// --------------------------------------------------------------------------
// Keep reading characters until an open parenthesis or EOF is read
// --------------------------------------------------------------------------

bool CFileSystemPar::ReadOpenClosePar( std::ifstream &stream )
{
int ch = 0;

while ( !stream.eof() && ((ch = stream.get() ) != '}' ) && (ch != '{' ) );

return '{' == ch;
}

// --------------------------------------------------------------------------
// Write Open parenthesis
// --------------------------------------------------------------------------

void CFileSystemPar::WriteOpenParBasic( std::ofstream &stream,
                                        unsigned int depth, const char *name )
{
stream << "{" << name << " ";
}

void CFileSystemPar::WriteOpenPar( std::ofstream &stream, 
					unsigned int &depth, const char *name )
{
WriteTabbedDepth( stream, depth );

stream << "{" << name << "\n";
depth++;
}

void CFileSystemPar::WriteOpenPar( std::ofstream &stream, 
					unsigned int &depth, std::string &str )
{
WriteTabbedDepth( stream, depth );

stream << "{" << str.c_str() << "\n";
depth++;
}

// --------------------------------------------------------------------------
// Write close parenthesis
// --------------------------------------------------------------------------

void CFileSystemPar::WriteCloseParBasic( std::ofstream &stream, unsigned int depth )
{
stream << "}";
}

void CFileSystemPar::WriteClosePar( std::ofstream &stream, unsigned int &depth )
{
depth--;
WriteTabbedDepth( stream, depth );
stream << "}\n";
}

// --------------------------------------------------------------------------
// Write tabbed depth
// --------------------------------------------------------------------------

void CFileSystemPar::WriteTabbedDepth( std::ofstream &stream, unsigned int depth )
{
while ( depth--)
	{
        stream << "\t";
	}
}
