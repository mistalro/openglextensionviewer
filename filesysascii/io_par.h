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

bool ReadOpenPar( ifstream &ifs );
bool ReadClosePar( ifstream &ifs );
bool ReadOpenClosePar( ifstream &ifs );

// ----- Write routines -----------------------------------------------------

void WriteTabbedDepth( ostream &stream, unsigned int depth );

void WriteOpenParBasic( ostream &stream, unsigned int depth, const char *name );
void WriteOpenPar( ostream &stream, unsigned int &depth, const char *name );
void WriteOpenPar( ostream &stream, unsigned int &depth, string &string );
void WriteClosePar( ostream &stream,unsigned int &depth );
void WriteCloseParBasic( ostream &stream, unsigned int depth );
};

#endif	// _IO_PAR_H_
