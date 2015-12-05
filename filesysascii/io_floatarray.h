// --------------------------------------------------------------------------
// File:   io_float.h
//
// Purpose: Routines to handle byteenthesis
//
// Author:  Michael S. A. Robb
//
// Date:    2005/01/27
// ---------------------------------------------------------------------------

#ifndef _IO_FLOATARRAY_H_
#define _IO_FLOATARRAY_H_

// --------------------------------------------------------------------------
// File system for byte management
// --------------------------------------------------------------------------

class CFileSystemFloatArray : virtual public CFileSystemPar,
				virtual public CFileSystemString
{
// ----- Class members ------------------------------------------------------
public:

// ----- Read routines ------------------------------------------------------

// ----- Float arrays -------------------------------------------------------

void ReadFloatArray1D( std::ifstream &stream,
                unsigned int nx, float *pdata );

void ReadFloatArray2D( std::ifstream &stream,
                unsigned int nx, unsigned int ny, float *pdata );

void ReadFloatArray3D( std::ifstream &stream,
                unsigned int nx, unsigned int ny, unsigned int nz, float *pdata );

// ----- Write routines -----------------------------------------------------

void WriteFloatArray1D(std::ofstream &stream, unsigned int nx, float *pdata );

void WriteNamedFloatArray1D(std::ofstream &stream, unsigned int depth,
        const char *pstr, unsigned int nx, float *pdata );

void WriteFloatArray2D(std::ofstream &stream, 
	unsigned int nx, unsigned int ny, float *pdata );

void WriteNamedFloatArray2D(std::ofstream &stream, unsigned int depth,
        const char *pstr, unsigned int nx, unsigned int ny, float *pdata );

void WriteFloatArray3D(std::ofstream &stream, 
	unsigned int nx, unsigned int ny, unsigned int nz, float *pdata );

void WriteNamedFloatArray3D(std::ofstream &stream, unsigned int depth,
        const char *pstr, unsigned int nx, unsigned int ny, unsigned int nz, float *pdata );
};

#endif	// _IO_FLOATARRAY_H_
