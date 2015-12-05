// --------------------------------------------------------------------------
// File:   io_longarray.h
//
// Purpose: Routines to handle byteenthesis
//
// Author:  Michael S. A. Robb
//
// Date:    2005/01/27
// ---------------------------------------------------------------------------

#ifndef _IO_LONGARRAY_H_
#define _IO_LONGARRAY_H_

// --------------------------------------------------------------------------
// File system for byte management
// --------------------------------------------------------------------------

class CFileSystemLongArray : virtual public CFileSystemPar,
				virtual public CFileSystemString
{
// ----- Class members ------------------------------------------------------
public:

// ----- Read routines ------------------------------------------------------

void ReadLongArray1D( std::ifstream &stream,
                unsigned int nx, long *pdata );

void ReadLongArray2D( std::ifstream &stream,
                unsigned int nx, unsigned int ny, long *pdata );

void ReadLongArray3D( std::ifstream &stream,
                unsigned int nx, unsigned int ny, unsigned int nz, long *pdata );

// ----- Write routines -----------------------------------------------------

void WriteLongArray1D(std::ofstream &stream, unsigned int nx, long *pdata );

void WriteNamedLongArray1D(std::ofstream &stream, unsigned int depth,
        const char *pstr, unsigned int nx, long *pdata );

void WriteLongArray2D(std::ofstream &stream, unsigned int nx, unsigned int ny, long *pdata );

void WriteNamedLongArray2D(std::ofstream &stream, unsigned int depth,
        const char *pstr, unsigned int nx, unsigned int ny, long *pdata );

void WriteLongArray3D(std::ofstream &stream, unsigned int nx, unsigned int ny, unsigned int nz, long *pdata );

void WriteNamedLongArray3D(std::ofstream &stream, unsigned int depth,
        const char *pstr, unsigned int nx, unsigned int ny, unsigned int nz, long *pdata );

};

#endif	// _IO_LONGARRAY_H_
