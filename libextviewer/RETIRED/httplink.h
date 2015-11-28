// ---------------------------------------------------------------------------
// Copyright: (C) VFX Research 2002 - 2014. All Rights Reserved.
// ---------------------------------------------------------------------------

#ifndef _HTTPLINK_
#define _HTTPLINK_

#define MODE_GET 0x0001
#define MODE_PUT 0x0002

#include <fstream>

typedef enum
{
SERVICE_HTTP = 80,
SERVICE_HTTPS = 443
} HttpService;

// --------------------------------------------------------------------------
// The CHttpLink class
// --------------------------------------------------------------------------

class CHttpLink
{
public:

CHttpLink() 
	{ 
	Init(); 
	};

~CHttpLink() 
	{ 
	Deallocate(); 
	};

void  Init( void );
void  Deallocate( void );
private:
void ExtractServerPath( HttpService &service, string &filepath, string &server, 
			string &httppath );

void  ExtractServerPath( HttpService &service, const char *pfilepath, char *lpServer, char *pfilename );
int   SendRequest(HttpService service, const char *pservername, const char *pfilename, int mode );
void  ErrorMessage( char *str );

void AppendUserAgent(string &requestbuf);

HttpService GetService( const char *path);

// ----- Get data -----------------------------------------------------------
public:
int GetBuffer( string &data, string &httplink );

char *GetBufferService(HttpService service, const char *pservername, const char *pfilename, int &rbufsize );
char *GetBuffer(const char *pfilepath,   int    &rbufsize );

int   GetFile(HttpService service,   const char *pservername, const char * pfilename, ofstream &stream);
void  GetFile(HttpService service,   const char *pfilepath,   ofstream &stream );
int   GetFile(const char *pfilepath,  const char *dstpath );

int  GetFile(HttpService service, const string &strhost, const string &strpath, const string &destpath );

// ----- Put data -----------------------------------------------------------

int   PutBuffer( const char *pservername, const char *pfilename, const char *pbuffer, int bufsize );
int   PutBuffer( const char *pfilepath, const char *pbuffer, int bufsize );

int   PutFile( const char *pservername, const char *pfilename, ifstream &stream, int nbytes );
void  PutFile( const char *pfilepath, ifstream &stream, int nbytes );
int   PutFile( const char *pfilepath, const char *dstpath );
};

#endif

