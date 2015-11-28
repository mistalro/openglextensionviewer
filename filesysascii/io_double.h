// --------------------------------------------------------------------------
// File:   io_double.h
//
// Purpose: Routines to handle byteenthesis
//
// Author:  Michael S. A. Robb
//
// Date:    2005/01/27
// ---------------------------------------------------------------------------

#ifndef _IO_DOUBLE_H_
#define _IO_DOUBLE_H_

// --------------------------------------------------------------------------
// File system for byte management
// --------------------------------------------------------------------------

class CFileSystemDouble : virtual public CFileSystemPar
{
// ----- Class members ------------------------------------------------------
public:

// ----- Read routines ------------------------------------------------------

// ----- Doubles -----

inline void ReadDouble( ifstream &stream, double &fvalue )
	{
	stream >> fvalue;
	}

// ----- Write routines -----------------------------------------------------

inline void WriteDouble( ostream &stream, double fvalue )
	{
	stream << fvalue;
	}

inline void WriteNamedDouble( ostream &stream, unsigned int depth, 
				const char *pname, double fvalue )
	{
	WriteTabbedDepth( stream, depth );
	stream << "{" << pname << " " << fvalue << " }\n";
	}

inline void WriteNamedDouble( ostream &stream, unsigned int depth, 
				string &strname, double fvalue )
	{
	WriteTabbedDepth( stream, depth );
	stream << "{" << strname.c_str() << " " << fvalue << " }\n";
	}
};

#endif	// _IO_DOUBLE_H_
