// --------------------------------------------------------------------------
// File:   io_byte.h
//
// Purpose: Routines to handle byteenthesis
//
// Author:  Michael S. A. Robb
//
// Date:    2005/01/27
// ---------------------------------------------------------------------------

#ifndef _IO_INTEGERARRAY_H_
#define _IO_INTEGERARRAY_H_

// --------------------------------------------------------------------------
// File system for byte management
// --------------------------------------------------------------------------

class CFileSystemIntegerArray : virtual public CFileSystemPar,
				virtual public CFileSystemString
{
// ----- Class members ------------------------------------------------------
public:

// ----- Read routines ------------------------------------------------------

void ReadIntegerArray1D( std::ifstream &stream,
                unsigned int nx, int *pdata );

void ReadIntegerArray2D( std::ifstream &stream,
                unsigned int nx, unsigned int ny, int *pdata );

void ReadIntegerArray3D( std::ifstream &stream,
                unsigned int nx, unsigned int ny, unsigned int nz, int *pdata );

// ----- Write routines -----------------------------------------------------

// ----- Integer arrays -----------------------------------------------------

void WriteIntegerArray1D( std::ofstream &stream, unsigned int nx, int *pdata );

void WriteNamedIntegerArray1D( std::ofstream &stream, unsigned int depth,
        const char *pstr, unsigned int nx, int *pdata );

void WriteIntegerArray2D( std::ofstream &stream, 
	unsigned int nx, unsigned int ny, int *pdata );

void WriteNamedIntegerArray2D( std::ofstream &stream, unsigned int depth,
        const char *pstr, unsigned int nx, unsigned int ny, int *pdata );

void WriteIntegerArray3D( std::ofstream &stream, 
	unsigned int nx, unsigned int ny, unsigned int nz, int *pdata );

void WriteNamedIntegerArray3D( std::ofstream &stream, unsigned int depth,
        const char *pstr, unsigned int nx, unsigned int ny, unsigned int nz, int *pdata );
};

#endif	// _IO_INTEGERARRAY_H_
