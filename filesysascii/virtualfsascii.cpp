// ---------------------------------------------------------------------------
// File:    virtualfsascii.cpp
// 
// Purpose: Virtual file system functions for generic file IO
//
// Author:  Michael Robb
// 
// Date:    Tue Apr 17 00:32:15 2012
// ----------------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#include "filesysascii.h"
#include "virtualfsascii.h"

// --------------------------------------------------------------------------
// Read data in from the selected file path
// --------------------------------------------------------------------------

int CVirtualFileSystem::ReadFile( const char *path )
{
ifstream stream;
bool result;

stream.open( path, ifstream::in );

if ( !stream.is_open() )
        {
        if ( g_verbose )
                {
                cout << "Failed to open source file <" << path << ">\n";
                }

        result = false;
        }
else
        {
        if ( g_verbose )
                {
                cout << "Successfully opened source file <" << path << ">\n";
                }

        result = ReadFileInternal( stream );

        if ( g_verbose )
                {
                cout << "Read source file with result <" << result << ">\n";
                }

        stream.close();
        }

return( result );
}

// --------------------------------------------------------------------------
// Read CAutoFlowSystemIO in from the selected string path
// --------------------------------------------------------------------------

int CVirtualFileSystem::ReadFile( const string &path )
{
ifstream stream;
int result;

stream.open( path.data(), ifstream::in );

if ( !stream.is_open() )
        {
        if ( g_verbose )
                {
                cout << "Failed to open source file <" << path << ">\n";
                }

        result = false;
        }
else
        {
        if ( g_verbose )
                {
                cout << "Successfully opened source file <" << path << ">\n";
                }

        result = ReadFileInternal( stream );

        if ( g_verbose )
                {
                cout << "Read source file with result <" << result << ">\n";
                }

        stream.close();
        }

return( result );
}

// --------------------------------------------------------------------------
// Write data out to the selected file path
// --------------------------------------------------------------------------

int CVirtualFileSystem::WriteFile( const char *path )
{
ofstream stream;
bool result;

stream.open( path, ofstream::out );

if ( stream.is_open() )
        {
        result = WriteFile( stream, 0 );

        stream.close();
        }
else
        {
        result = false;
        }

return( result );
}

// --------------------------------------------------------------------------
// Write data out to the selected file path defined as a STL string
// --------------------------------------------------------------------------

int CVirtualFileSystem::WriteFile( const string &path )
{
ofstream stream;
bool result;

stream.open( path.data(), ofstream::out );

if ( stream.is_open() )
        {
        result = WriteFile( stream, 0 );

        stream.close();
        }
else
        {
        result = false;
        }

return( result );
}
