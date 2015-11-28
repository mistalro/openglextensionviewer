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

void CFileSystemLongArray::ReadLongArray1D( ifstream &stream,
		unsigned int nx, long *pdata )
{
for ( unsigned int pn = 0; pn < nx; pn++ )
        {
        stream >> pdata[pn];

        if ( g_verbose> 1 )
                {
                cout << "Read byte <" << pdata[pn] << ">\n";
                }
        }
}

// --------------------------------------------------------------------------
// Read 2D integer arrays
// --------------------------------------------------------------------------

void CFileSystemLongArray::ReadLongArray2D( ifstream &stream,
		unsigned int nx, unsigned int ny, long *pdata )
{
string buffer;

while ( ReadOpenClosePar( stream ) != 0 )
        {
        ReadString( stream, buffer ); // str

        if ( g_verbose > 1)
                {
                cout << "Read token <" << buffer << ">\n";
                }

        switch( token_match( buffer, token_list, token_num ) )
                {
                case TOKEN_YSLICE:
                        if ( g_verbose > 1 )
                                {
                                cout << "Reading Y-slice\n";
                                }

                        ReadLongArray1D( stream, nx, pdata );
                        pdata += nx;
                        break;

                default:
                        cout << "ReadLongArray2D::Unknown token <";
                        cout << buffer.c_str() << " >\n";
                        break;
                }

        ReadClosePar( stream );       // }
        }

stream.putback( '}' );
}

// --------------------------------------------------------------------------
// Read 3D integer arrays
// --------------------------------------------------------------------------

void CFileSystemLongArray::ReadLongArray3D( ifstream &stream,
	unsigned int nx, unsigned int ny, unsigned int nz, long *pdata )
{
string buffer;

while ( ReadOpenClosePar( stream ) != 0 )
        {
        ReadString( stream, buffer ); // str

        if ( g_verbose > 1 )
                {
                cout << "Read token <" << buffer << ">\n";
                }

        switch( token_match( buffer, token_list, token_num ) )
                {
                case TOKEN_ZSLICE:
                        if ( g_verbose > 1 )
                                {
                                cout << "Reading Z-slice\n";
                                }

                        ReadLongArray2D( stream, nx,ny, pdata );
                        pdata += ny*nz;
                        break;

                default:
                        cout << "ReadLongArray3D::Unknown token <";
                        cout << buffer.c_str() << " >\n";
                        break;
                }

        ReadClosePar( stream );       // }
        }

stream.putback( '}' );
}

// ===========================================================================
// WRITE ROUTINES
// ===========================================================================

void CFileSystemLongArray::WriteLongArray1D( ostream &stream,
                                        unsigned int nx, long *pdata )
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

void CFileSystemLongArray::WriteNamedLongArray1D( ostream &stream, 
	unsigned int depth, const char *pstr, 
	unsigned int nx, long *pdata )
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

void CFileSystemLongArray::WriteLongArray2D( ostream &stream,
	unsigned int nx, unsigned int ny, long *pdata )
{
for ( unsigned int py = 0; py < ny; py++ )
        {
        WriteLongArray1D( stream, nx, pdata+py*nx );
        }
}

void CFileSystemLongArray::WriteNamedLongArray2D( ostream &stream, 
	unsigned int depth, const char *pstr, 
	unsigned int nx, unsigned int ny, long *pdata )
{
WriteOpenPar( stream, depth, pstr );

for ( unsigned int py = 0; py < ny; py++ )
        {
        WriteNamedLongArray1D( stream, depth, STRING_YSLICE,
                                nx, pdata+py*nx);
        }

WriteClosePar( stream, depth );
}

// --------------------------------------------------------------------------
// Write 3D array
// --------------------------------------------------------------------------

void CFileSystemLongArray::WriteLongArray3D( ostream &stream,
	unsigned int nx, unsigned int ny, unsigned int nz, long *pdata )
{
for ( unsigned int pz = 0; pz < nz; pz++ )
        {
        WriteLongArray2D( stream, nx, ny, pdata+pz*nx*ny );
        }
}

void CFileSystemLongArray::WriteNamedLongArray3D( ostream &stream, 
	unsigned int depth, const char *pstr, 
	unsigned int nx, unsigned int ny, unsigned int nz, long *pdata )
{
WriteOpenPar( stream, depth, pstr );

for ( unsigned int pz = 0; pz < nz; pz++ )
        {
        WriteNamedLongArray2D( stream, depth, STRING_ZSLICE,
                                nx, ny, pdata+pz*nx*ny);
        }

WriteClosePar( stream, depth );
}
