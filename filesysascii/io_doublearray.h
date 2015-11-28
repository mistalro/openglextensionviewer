// --------------------------------------------------------------------------
// File:   io_double.h
//
// Purpose: Routines to handle byteenthesis
//
// Author:  Michael S. A. Robb
//
// Date:    2005/01/27
// ---------------------------------------------------------------------------

#ifndef _IO_DOUBLEARRAY_H_
#define _IO_DOUBLEARRAY_H_

// --------------------------------------------------------------------------
// File system for byte management
// --------------------------------------------------------------------------

class CFileSystemDoubleArray : virtual public CFileSystemPar,
				virtual public CFileSystemString
{
// ----- Class members ------------------------------------------------------
public:

// ----- Read routines ------------------------------------------------------

// ----- Double arrays -------------------------------------------------------

void ReadDoubleArray1D( ifstream &stream,
                unsigned int nx, double *pdata );

void ReadDoubleArray2D( ifstream &stream,
                unsigned int nx, unsigned int ny, double *pdata );

void ReadDoubleArray3D( ifstream &stream,
                unsigned int nx, unsigned int ny, unsigned int nz, double *pdata );

// ----- Write routines -----------------------------------------------------

void WriteDoubleArray1D( ostream &stream, unsigned int nx, double *pdata );

void WriteNamedDoubleArray1D( ostream &stream, unsigned int depth,
        const char *pstr, unsigned int nx, double *pdata );

void WriteDoubleArray2D( ostream &stream, unsigned int nx, unsigned int ny, double *pdata );

void WriteNamedDoubleArray2D( ostream &stream, unsigned int depth,
        const char *pstr, unsigned int nx, unsigned int ny, double *pdata );

void WriteDoubleArray3D( ostream &stream, unsigned int nx, unsigned int ny, unsigned int nz, double *pdata );

void WriteNamedDoubleArray3D( ostream &stream, unsigned int depth,
        const char *pstr, unsigned int nx, unsigned int ny, unsigned int nz, double *pdata );
};

#endif	// _IO_DOUBLEARRAY_H_
