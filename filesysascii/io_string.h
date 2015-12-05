// --------------------------------------------------------------------------
// File:   io_string.h
//
// Purpose: Routines to handle stringenthesis
//
// Author:  Michael S. A. Robb
//
// Date:    2005/01/27
// ---------------------------------------------------------------------------

#ifndef _IO_STRING_H_
#define _IO_STRING_H_

// --------------------------------------------------------------------------
// Utility functions
// --------------------------------------------------------------------------

void strlwr( std::string &pstr );
void strupr( std::string &pstr );

// --------------------------------------------------------------------------
// File system for string management
// --------------------------------------------------------------------------

class CFileSystemString : virtual public CFileSystemPar
{
// ----- Class members ------------------------------------------------------
public:

// ----- Read routines ------------------------------------------------------

void ReadString( std::ifstream &ifs, std::string &string );
void ReadQuotedString( std::ifstream &ifs, std::string &string );

// ----- Write routines -----------------------------------------------------

void WriteQuotedString( std::ofstream &stream, std::string &string );

void WriteNamedString( std::ofstream &stream, unsigned int depth,
                                        std::string &strname, std::string &string );

void WriteNamedString( std::ofstream &stream, unsigned int depth,
                                const char *name, std::string &string );
};

#endif	 // IO_STRING_H_
