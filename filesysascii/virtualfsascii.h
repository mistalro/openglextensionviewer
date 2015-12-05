// --------------------------------------------------------------------------
// File:    virtualfsascii.h
//
// Purpose: Class definitions for the autoflow application
//
// Author:  Michael S. A. Robb
//
// Date:    25th September 2009
// --------------------------------------------------------------------------

#ifndef _VIRTUALFSASCII_H_
#define _VIRTUALFSASCII_H_

#include "filesysascii.h"

extern int g_verbose;
extern class CFileSystem g_filesysascii;

// --------------------------------------------------------------------------
// Pure virtual class for implementing file system reading/writing
// --------------------------------------------------------------------------

class CVirtualFileSystem
{
public:
// ----- Reading files ------------------------------------------------------

int ReadFile( const char *path );
int ReadFile( const std::string &path );

virtual int ReadFileInternal( std::ifstream &stream ) = 0;
virtual int ReadFile( std::ifstream &stream ) = 0;

// ----- Writing files ------------------------------------------------------

int WriteFile( const char *path );
int WriteFile( const std::string &path );

virtual int WriteFile( std::ofstream &stream, unsigned int depth ) = 0;
virtual int WriteFile( std::ofstream &stream, unsigned int depth, const char *pstr ) = 0;
};

// --------------------------------------------------------------------------
// To support global class variable 
// --------------------------------------------------------------------------

class CVirtualFileSystemGlobalAscii : virtual public CVirtualFileSystem
{
public:

// ----- Reading files ------------------------------------------------------

using CVirtualFileSystem::ReadFile;

// ----- Writing files ------------------------------------------------------

using CVirtualFileSystem::WriteFile;
};

// --------------------------------------------------------------------------
// To support local inheritance of the file system
// --------------------------------------------------------------------------

class CVirtualFileSystemAscii : virtual public CFileSystem,
				virtual public CVirtualFileSystem
{

};

#endif
