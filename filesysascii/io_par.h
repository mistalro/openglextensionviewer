// --------------------------------------------------------------------------
// File:   io_par.h
//
// Purpose: Routines to handle parenthesis
//
// Author:  Michael S. A. Robb
//
// Date:    2005/01/27
// ---------------------------------------------------------------------------

#ifndef _IO_PAR_H_
#define _IO_PAR_H_

// --------------------------------------------------------------------------
// File system for parenthesis management
// --------------------------------------------------------------------------

class CFileSystemPar
{
// ----- Class members ------------------------------------------------------
public:

// ----- Read routines ------------------------------------------------------

bool ReadOpenPar( std::ifstream &ifs );
bool ReadClosePar( std::ifstream &ifs );
bool ReadOpenClosePar( std::ifstream &ifs );

// ----- Write routines -----------------------------------------------------

void WriteTabbedDepth( std::ofstream &stream, unsigned int depth );

void WriteOpenParBasic( std::ofstream &stream, unsigned int depth, const char *name );
void WriteOpenPar( std::ofstream &stream, unsigned int &depth, const char *name );
void WriteOpenPar( std::ofstream &stream, unsigned int &depth, std::string &string );
void WriteClosePar( std::ofstream &stream,unsigned int &depth );
void WriteCloseParBasic( std::ofstream &stream, unsigned int depth );
};

#endif	// _IO_PAR_H_
