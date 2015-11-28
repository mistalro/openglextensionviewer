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

void strlwr( string &pstr );
void strupr( string &pstr );

// --------------------------------------------------------------------------
// File system for string management
// --------------------------------------------------------------------------

class CFileSystemString : virtual public CFileSystemPar
{
// ----- Class members ------------------------------------------------------
public:

// ----- Read routines ------------------------------------------------------

void ReadString( ifstream &ifs, string &string );
void ReadQuotedString( ifstream &ifs, string &string );

// ----- Write routines -----------------------------------------------------

void WriteQuotedString( ostream &stream, string &string );

void WriteNamedString( ostream &stream, unsigned int depth,
                                        string &strname, string &string );

void WriteNamedString( ostream &stream, unsigned int depth,
                                const char *name, string &string );
};

#endif	 // IO_STRING_H_
