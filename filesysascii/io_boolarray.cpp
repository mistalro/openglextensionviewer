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

static CTokenEntry token_list[] =
{
CTokenEntry( TOKEN_YSLICE, STRING_YSLICE ),
CTokenEntry( TOKEN_ZSLICE, STRING_ZSLICE )
};

static int token_num = sizeof(token_list)/sizeof(CTokenEntry);

// --------------------------------------------------------------------------
// Read 1D integer arrays
// --------------------------------------------------------------------------

void CFileSystemBooleanArray::ReadBoolArray1D( ifstream &stream,
                                        unsigned int nx, bool *pdata )
{
for ( unsigned int pn = 0; pn < nx; pn++ )
        {
        stream >> pdata[pn];

	if ( g_verbose> 1 )
		{
		cout << "Read boolean <" << pdata[pn] << ">\n";
		}
        }
}

// --------------------------------------------------------------------------
// Read 2D integer arrays
// --------------------------------------------------------------------------

void CFileSystemBooleanArray::ReadBoolArray2D( ifstream &stream,
			unsigned int nx, unsigned int ny, bool *pdata )
{
string buffer;

while ( ReadOpenClosePar( stream ) != 0 )
        {
        ReadString( stream, buffer ); // yslice

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

                        ReadBoolArray1D( stream, nx, pdata );
                        pdata += nx;
                        break;

                default:
                        cout << "ReadBooleanArray2D::Unknown token <";
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

void CFileSystemBooleanArray::ReadBoolArray3D( ifstream &stream,
       unsigned int nx, unsigned int ny, unsigned int nz, bool *pdata )
{
string buffer;

while ( ReadOpenClosePar( stream ) != 0 )
        {
        ReadString( stream, buffer ); // zslice

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

                        ReadBoolArray2D( stream, nx, ny, pdata );
                        pdata += ny*nz;
                        break;

                default:
                        cout << "ReadBooleanArray3D::Unknown token <";
                        cout << buffer.c_str() << ">\n";
                        break;
                }

        ReadClosePar( stream );       // }
        }

stream.putback( '}' );
}

// ===========================================================================
// WRITE ROUTINES
// ===========================================================================

// --------------------------------------------------------------------------
// Write 1D array
// --------------------------------------------------------------------------

void CFileSystemBooleanArray::WriteBoolArray1D( ostream &stream,
				unsigned int nx, bool *pdata )
{
stream << " ";

for ( unsigned int px = 0; px < nx; px++ )
        {
        stream << pdata[px] << " ";
        }
}

void CFileSystemBooleanArray::WriteNamedBoolArray1D( ostream &stream, 
				unsigned int depth, const char *pstr, 
				unsigned int nx, bool *pdata )
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

void CFileSystemBooleanArray::WriteBoolArray2D( ostream &stream,
			unsigned int nx, unsigned int ny, bool *pdata )
{
for ( unsigned int py = 0; py < ny; py++ )
        {
	WriteBoolArray1D( stream, nx, pdata+py*nx );
        }
}

void CFileSystemBooleanArray::WriteNamedBoolArray2D( ostream &stream, 
			unsigned int depth, const char *pstr, 
			unsigned int nx, unsigned int ny, bool *pdata )
{
WriteOpenPar( stream, depth, pstr );

for ( unsigned int py = 0; py < ny; py++ )
        {
        WriteNamedBoolArray1D( stream, depth, STRING_YSLICE,
                                nx, pdata+py*nx);
        }

WriteClosePar( stream, depth );
}

// --------------------------------------------------------------------------
// Write 3D array
// --------------------------------------------------------------------------

void CFileSystemBooleanArray::WriteBoolArray3D( ostream &stream,
			unsigned int nx, unsigned int ny, 
			unsigned int nz, bool *pdata )
{
for ( unsigned int py = 0; py < ny; py++ )
        {
	WriteBoolArray2D( stream, nx, ny, pdata+nz*nx*ny );
        }
}

void CFileSystemBooleanArray::WriteNamedBoolArray3D( ostream &stream, 
		unsigned int depth, const char *pstr, 
		unsigned int nx, unsigned int ny, unsigned int nz, bool *pdata )
{
WriteOpenPar( stream, depth, pstr );

for ( unsigned int pz = 0; pz < nz; pz++ )
        {
        WriteNamedBoolArray2D( stream, depth, STRING_ZSLICE,
                                nx, ny, pdata+pz*nx*ny);
        }

WriteClosePar( stream, depth );
}
