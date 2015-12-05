// --------------------------------------------------------------------------
// File:   io_generic.cpp
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

// ===========================================================================
// READ ROUTINES
// ===========================================================================

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

// --------------------------------------------------------------------------
// Read 1D integer arrays
// --------------------------------------------------------------------------

void CFileSystemShortArray::ReadShortArray1D( std::ifstream &stream,
	unsigned int nx, short *pdata )
{
for ( unsigned int pn = 0; pn < nx; pn++ )
        {
        stream >> pdata[pn];

        if ( g_verbose> 1 )
                {
                std::cout << "Read short <" << pdata[pn] << ">\n";
                }
        }
}

// --------------------------------------------------------------------------
// Read 2D integer arrays
// --------------------------------------------------------------------------

void CFileSystemShortArray::ReadShortArray2D( std::ifstream &stream,
	unsigned int nx, unsigned int ny, short *pdata )
{
std::string buffer;

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

                        ReadShortArray1D( stream, nx, pdata );
                        pdata += nx;
                        break;

                default:
                        std::cout << "ReadShortArray2D::Unknown token <";
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

void CFileSystemShortArray::ReadShortArray3D( std::ifstream &stream,
	unsigned int nx, unsigned int ny, unsigned int nz, short *pdata )
{
std::string buffer;

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

                        ReadShortArray2D( stream, nx,ny, pdata );
                        pdata += ny*nz;
                        break;

                default:
                        std::cout << "ReadShortArray3D::Unknown token <";
                        std::cout << buffer.c_str() << " >\n";
                        break;
                }

        ReadClosePar( stream );       // }
        }

stream.putback( '}' );
}

// ===========================================================================
// WRITE ROUTINES
// ===========================================================================

void CFileSystemShortArray::WriteShortArray1D( std::ofstream &stream,
                                        unsigned int nx, short *pdata )
{
stream << " ";

for ( unsigned int px = 0; px < nx; px++ )
        {
        stream << pdata[px] << " ";
        }
}

// --------------------------------------------------------------------------
// Write 1D array
// --------------------------------------------------------------------------

void CFileSystemShortArray::WriteNamedShortArray1D( std::ofstream &stream, 
	unsigned int depth, const char *pstr, unsigned int nx, short *pdata )
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

void CFileSystemShortArray::WriteShortArray2D( std::ofstream &stream,
                      unsigned int nx, unsigned int ny, short *pdata )
{
for ( unsigned int py = 0; py < ny; py++ )
        {
        WriteShortArray1D( stream, nx, pdata+py*nx );
        }
}

void CFileSystemShortArray::WriteNamedShortArray2D( std::ofstream &stream, 
		unsigned int depth, const char *pstr, 
		unsigned int nx, unsigned int ny, short *pdata )
{
WriteOpenPar( stream, depth, pstr );

for ( unsigned int py = 0; py < ny; py++ )
        {
        WriteNamedShortArray1D( stream, depth, STRING_YSLICE,
                                nx, pdata+py*nx);
        }

WriteClosePar( stream, depth );
}

// --------------------------------------------------------------------------
// Write 3D array
// --------------------------------------------------------------------------

void CFileSystemShortArray::WriteShortArray3D( std::ofstream &stream,
		unsigned int nx, unsigned int ny, unsigned int nz, short *pdata )
{
for ( unsigned int pz = 0; pz < nz; pz++ )
        {
        WriteShortArray2D( stream, nx, ny, pdata+pz*nx*ny );
        }
}

void CFileSystemShortArray::WriteNamedShortArray3D( std::ofstream &stream, 
		unsigned int depth, const char *pstr, 
		unsigned int nx, unsigned int ny, unsigned int nz,
        	short *pdata )
{
WriteOpenPar( stream, depth, pstr );

for ( unsigned int pz = 0; pz < nz; pz++ )
        {
        WriteNamedShortArray2D( stream, depth, STRING_ZSLICE,
                                nx, ny, pdata+pz*nx*ny);
        }

WriteClosePar( stream, depth );
}

