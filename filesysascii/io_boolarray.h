// --------------------------------------------------------------------------
// File:   io_byte.h
//
// Purpose: Routines to handle byteenthesis
//
// Author:  Michael S. A. Robb
//
// Date:    2005/01/27
// ---------------------------------------------------------------------------

#ifndef _IO_BOOLARRAY_H_
#define _IO_BOOLARRAY_H_

// --------------------------------------------------------------------------
// File system for byte management
// --------------------------------------------------------------------------

class CFileSystemBooleanArray : virtual public CFileSystemPar,
				virtual public CFileSystemString
{
// ----- Class members ------------------------------------------------------
public:

// ----- Read routines ------------------------------------------------------

void ReadBoolArray1D( ifstream &stream,
                unsigned int ncols, bool *pdata );

void ReadBoolArray2D( ifstream &stream,
                unsigned int ncols, unsigned int nrows, bool *pdata );

void ReadBoolArray3D( ifstream &stream,
                unsigned int ncols, unsigned int nrows, unsigned int ndep, bool *pdata );

// ----- Write routines -----------------------------------------------------

// ----- Bool arrays -----------------------------------------------------

void WriteBoolArray1D( ostream &stream, 
	unsigned int ncols, bool *pdata );

void WriteNamedBoolArray1D( ostream &stream, unsigned int depth,
        const char *pstr, unsigned int ncols, bool *pdata );

void WriteBoolArray2D( ostream &stream, 
	unsigned int ncols, unsigned int nrows, bool *pdata );

void WriteNamedBoolArray2D( ostream &stream, unsigned int depth,
        const char *pstr, 
	unsigned int ncols, unsigned int nrows, bool *pdata );

void WriteBoolArray3D( ostream &stream, 
	unsigned int ncols, unsigned int nrows, 
	unsigned int ndep, bool *pdata );

void WriteNamedBoolArray3D( ostream &stream, unsigned int depth,
        const char *pstr, 
	unsigned int ncols, unsigned int nrows, 
	unsigned int ndep, bool *pdata );
};

#endif	// _IO_BOOLARRAY_H_
