// --------------------------------------------------------------------------
// File:   io_float.h
//
// Purpose: Routines to handle floating-point
//
// Author:  Michael S. A. Robb
//
// Date:    2005/01/27
// ---------------------------------------------------------------------------

#ifndef _IO_FLOAT_H_
#define _IO_FLOAT_H_

// --------------------------------------------------------------------------
// File system for byte management
// --------------------------------------------------------------------------

class CFileSystemFloat : virtual public CFileSystemPar
{
// ----- Class members ------------------------------------------------------
public:

// ----- Read routines ------------------------------------------------------

// ----- Floats -----

void ReadFloat( ifstream &stream, float &fvalue )
	{
	stream >> fvalue;
	}

// ----- Write routines -----------------------------------------------------

void WriteFloat( ostream &stream, float fvalue )
	{
	stream << fvalue;
	}

void WriteNamedFloat( ostream &stream, unsigned int depth, const char *pname,
                                                        float fvalue )
	{
	WriteTabbedDepth( stream, depth );
	stream << "{" << pname << " " << fvalue << " }\n";
	}

void WriteNamedFloat( ostream &stream, unsigned int depth, string &strname,
                                                        float fvalue )
	{
	WriteTabbedDepth( stream, depth );
	stream << "{" << strname.c_str() << " " << fvalue << " }\n";
	}
};

#endif	// _IO_FLOAT_H_
