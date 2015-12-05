// --------------------------------------------------------------------------
// File:   io_floatarray.cpp
//
// Purpose: Routines to handle parenthesis
//
// Author:  Michael S. A. Robb
//
// Date:    2005/01/27
// ---------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "filesysascii.h"

// ==========================================================================
// FILE READING
// ==========================================================================

static const char *str_yslice = "yslice";
static const char *str_zslice = "zslice";

#define STRING_YSLICE   str_yslice
#define STRING_ZSLICE   str_zslice

#define TOKEN_YSLICE 0x1001
#define TOKEN_ZSLICE 0x1002

CTokenEntry token_list[] =
{
CTokenEntry( TOKEN_YSLICE, STRING_YSLICE ),
CTokenEntry( TOKEN_ZSLICE, STRING_ZSLICE )
};

static int token_num = sizeof(token_list)/sizeof(CTokenEntry);

// ===========================================================================
// READ ROUTINES
// ===========================================================================

// --------------------------------------------------------------------------
// Read 1D integer arrays
// --------------------------------------------------------------------------

void CFileSystemFloatArray::ReadFloatArray1D( std::ifstream &stream,
			unsigned int nx, float *pdata )
{
for ( unsigned int pn = 0; pn < nx; pn++ )
        {
        stream >> pdata[pn];

        if ( g_verbose> 1 )
                {
                std::cout << "Read byte <" << pdata[pn] << ">\n";
                }
        }
}

// --------------------------------------------------------------------------
// Read 2D integer arrays
// --------------------------------------------------------------------------

void CFileSystemFloatArray::ReadFloatArray2D( std::ifstream &stream,
			unsigned int nx, unsigned int ny, float *pdata )
{
std::string buffer;

ReadOpenPar( stream );          //        {

while ( ReadOpenClosePar( stream ) != 0 )
        {
        ReadString( stream, buffer ); // str

        if ( g_verbose > 1)
                {
                std::cout << "Read token <" << buffer << ">\n";
                }

        switch( token_match( buffer, token_list, token_num ) )
                {
                case TOKEN_YSLICE:
			if ( g_verbose > 1 )
                                {
                                std::cout << "Reading Y-slice\n";
                                }

                        ReadFloatArray1D( stream, nx, pdata );
                        pdata += nx;
                        break;

                default:
                        std::cout << "ReadFloatArray2D::Unknown token <";
                        std::cout << buffer.c_str() << " >\n";
                        break;
                }

        ReadClosePar( stream );       // }
        }

stream.putback( '}' );
}

// --------------------------------------------------------------------------
// Read 3D integer arrays
// --------------------------------------------------------------------------

void CFileSystemFloatArray::ReadFloatArray3D( std::ifstream &stream,
         unsigned int nx, unsigned int ny, unsigned int nz, float *pdata )
{
std::string buffer;

ReadOpenPar( stream );          //        {

while ( ReadOpenClosePar( stream ) != 0 )
        {
        ReadString( stream, buffer ); // str

        if ( g_verbose > 1 )
                {
                std::cout << "Read token <" << buffer << ">\n";
                }

        switch( token_match( buffer, token_list, token_num ) )
                {
                case TOKEN_ZSLICE:
                        if ( g_verbose > 1 )
                                {
                                std::cout << "Reading Z-slice\n";
                                }

                        ReadFloatArray2D( stream, nx,ny, pdata );
                        pdata += ny*nz;
                        break;

                default:
                        std::cout << "ReadIntArray3D::Unknown token <";
                        std::cout << buffer.c_str() << " >\n";
                        break;
                }

        ReadClosePar( stream );       // }
        }

stream.putback( '}' );
}

// ==========================================================================
// FILE WRITING
// ==========================================================================

void CFileSystemFloatArray::WriteFloatArray1D( std::ofstream &stream,
			unsigned int nx, float *pdata )
{
for ( unsigned int px = 0; px < nx; px++ )
        {
        stream << pdata[px] << " ";
        }
}

// --------------------------------------------------------------------------
// Write 1D array
// --------------------------------------------------------------------------

void CFileSystemFloatArray::WriteNamedFloatArray1D( std::ofstream &stream, 
			unsigned int depth, const char *pstr, unsigned int nx, float *pdata )
{
WriteTabbedDepth( stream, depth );

stream << "{" << pstr << " ";

for ( unsigned int px = 0; px < nx; px++ )
        {
        stream << pdata[px] << " ";
        }

stream << "}\n";
}

// --------------------------------------------------------------------------
// Write 2D array
// --------------------------------------------------------------------------

void CFileSystemFloatArray::WriteFloatArray2D( std::ofstream &stream,
	unsigned int nx, unsigned int ny, float *pdata )
{
for ( unsigned int py = 0; py < ny; py++ )
        {
        WriteFloatArray1D( stream, nx, pdata+py*nx );
        }
}

void CFileSystemFloatArray::WriteNamedFloatArray2D( std::ofstream &stream, 
	unsigned int depth, const char *pstr, 	
	unsigned int nx, unsigned int ny, float *pdata )
{
WriteOpenPar( stream, depth, pstr );

for ( unsigned int py = 0; py < ny; py++ )
        {
        WriteNamedFloatArray1D( stream, depth, STRING_YSLICE, nx, pdata+py*nx);
        }

WriteClosePar( stream, depth );
}

// --------------------------------------------------------------------------
// Write 3D array
// --------------------------------------------------------------------------

void CFileSystemFloatArray::WriteFloatArray3D( std::ofstream &stream,
	unsigned int nx, unsigned int ny, unsigned int nz, float *pdata )
{
for ( unsigned int pz = 0; pz < nz; pz++ )
        {
        WriteFloatArray2D( stream, nx, ny, pdata+pz*nx*ny );
        }
}

void CFileSystemFloatArray::WriteNamedFloatArray3D( std::ofstream &stream, 
	unsigned int depth, const char *pstr, 
	unsigned int nx, unsigned int ny, unsigned int nz, float *pdata )
{
WriteOpenPar( stream, depth, pstr );

for ( unsigned int pz = 0; pz < nz; pz++ )
        {
        WriteNamedFloatArray2D( stream, depth, STRING_ZSLICE,
                                nx, ny, pdata+pz*nx*ny);
        }

WriteClosePar( stream, depth );
}
