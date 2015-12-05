// --------------------------------------------------------------------------
// File:    io_shortarray.h
//
// Purpose: Routines to handle byteenthesis
//
// Author:  Michael S. A. Robb
//
// Date:    2005/01/27
// ---------------------------------------------------------------------------

#ifndef _IO_SHORTARRAY_H_
#define _IO_SHORTARRAY_H_

// --------------------------------------------------------------------------
// File system for byte management
// --------------------------------------------------------------------------

class CFileSystemShortArray : virtual public CFileSystemPar,
				virtual public CFileSystemString
{
// ----- Class members ------------------------------------------------------
public:

// ----- Read routines ------------------------------------------------------

void ReadShortArray1D( std::ifstream &stream,
                unsigned int nx, short *pdata );

void ReadShortArray2D( std::ifstream &stream,
                unsigned int nx, unsigned int ny, short *pdata );

void ReadShortArray3D( std::ifstream &stream,
                unsigned int nx, unsigned int ny, unsigned int nz, short *pdata );

// ----- Write routines -----------------------------------------------------

void WriteShortArray1D(std::ofstream &stream, unsigned int nx, short *pdata );

void WriteNamedShortArray1D(std::ofstream &stream, unsigned int depth,
        const char *pstr, unsigned int nx, short *pdata );

void WriteShortArray2D(std::ofstream &stream, 
	unsigned int nx, unsigned int ny, short *pdata );

void WriteNamedShortArray2D(std::ofstream &stream, unsigned int depth,
        const char *pstr, 
	unsigned int nx, unsigned int rows, short *pdata );

void WriteShortArray3D(std::ofstream &stream, 
	unsigned int nx, unsigned int ny, unsigned int nz, short *pdata );

void WriteNamedShortArray3D(std::ofstream &stream, 
	unsigned int depth, const char *pstr, 
	unsigned int nx, unsigned int ny, unsigned int nz, short *pdata );
};

#endif	// _IO_SHORTARRAY_H_
