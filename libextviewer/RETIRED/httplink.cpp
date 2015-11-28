// ---------------------------------------------------------------------------
// Copyright: (C) VFX Research 2002 - 2014. All Rights Reserved.
// ---------------------------------------------------------------------------

using namespace std;

#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fcntl.h>
#include <sys/io.h>
#include <sys/socket.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/stat.h>

#include "httplink.h"
#include "socketstream.h"
#include "strstream.h"

/* Structure describing an Internet (IP) socket address. */
#define __SOCK_SIZE__   16              /* sizeof(struct sockaddr)      */

struct sockaddr_in4 {
  sa_family_t           sin_family;     /* Address family               */
  unsigned short int    sin_port;       /* Port number                  */
  struct in_addr        sin_addr;       /* Internet address             */
                                                                                
  /* Pad to size of `struct sockaddr'. */
  unsigned char         __pad[__SOCK_SIZE__ - sizeof(short int) -
                        sizeof(unsigned short int) - sizeof(struct in_addr)];
};

#define sin_zero        __pad           /* for BSD UNIX comp. -FvK      */
                                                                                
#define SOCKET_ERROR -1
#define INVALID_SOCKET -1

#define closesocket(X) close((X))

void CHttpLink::ExtractServerPath( HttpService &service, 
			string &filepath, string &server, string &file )
{
const char *pserver, *pmid;

server.reserve( filepath.length()+1 );
file.reserve( filepath.length()+1 );

pserver = filepath.data();

if ( strncmp( pserver, "http://", 7 ) == 0 )
	{
	service = SERVICE_HTTP;
	pserver += 7;
	}

if ( strncmp( pserver, "https://", 8 ) == 0 )
	{
	service = SERVICE_HTTPS;
	pserver += 8;
	}

pmid = pserver;

while ( *pmid && (*pmid != '/') )
	{
	server += *pmid;
	pmid++;
	}

file.clear();

while ( *pmid != '\0' )
	{
	file += *pmid;	
	pmid++;	
	}
}

// --------------------------------------------------------------------------
// Extract the server path
// --------------------------------------------------------------------------

void CHttpLink::ExtractServerPath( HttpService &service, const char *pfilepath, char *lpServer, char *lpFile )
{
const char *pmid, *pserver;
int pos = 0;
                                                                                
pserver = pfilepath;
                                                                               
if ( strncmp( pserver, "http://", 7 ) == 0 )
	{
	service = SERVICE_HTTP;
	pserver += 7;
	}
else
if ( strncmp( pserver, "https://", 8 ) == 0 )
	{
	service = SERVICE_HTTPS;
	pserver += 8;
	}
                                                                                
pmid = pserver;

while ( (pmid[0] != '/') ||
       ( ((pmid>pfilepath) && (pmid[-1] == '/' )) || (pmid[1] == '/') ) )
	{
	pmid++;
	pos++;
	}
                                                                                
strncpy( lpServer, pserver, pos );
lpServer[pos] = '\0';
                                                                                
strcpy( lpFile,   pmid );
}

// --------------------------------------------------------------------------
// Handle error messages
// --------------------------------------------------------------------------

void CHttpLink::ErrorMessage( char *str )
{
cerr << "HttpLink::Error <" << str << "\n";
}

// --------------------------------------------------------------------------
// Initialise sockets
// --------------------------------------------------------------------------

static int init = 0;

void CHttpLink::Init( void )
{
#ifdef _WIN32
WORD	wVersionRequested = MAKEWORD(1,1);
WSADATA wsaData;
int		bytecount;
#endif

if ( init )
	return;

// ----- Initialize WinSock.dll ---------------------------------------------

#ifdef _WIN32
bytecount = WSAStartup(wVersionRequested, &wsaData);

if (bytecount)
	{
	cerr << "\nWSAStartup():" << bytecount << "\n";

	Deallocate();
	exit(0);
	}

// ----- Check WinSock version ----------------------------------------------

if (wsaData.wVersion != wVersionRequested)
	{
	cerr << "\nWinSock version not supported " << "\n";

	Deallocate();
	exit(0);
	}
#endif
init++;
}

// --------------------------------------------------------------------------
// Shutdown sockets
// --------------------------------------------------------------------------

void CHttpLink::Deallocate( void )
{
if ( !init )
	return;
#ifdef _WIN32
WSACleanup();
#endif
}

// --------------------------------------------------------------------------
// Append a user agent string to the request
// --------------------------------------------------------------------------

void CHttpLink::AppendUserAgent(string &requestbuf)
{
requestbuf += "User-Agent: Mozilla/5.0 (X11; Ubuntu; Linux x86_64; rv:42.0) Gecko/20100101 Firefox/42.0\r\n";
requestbuf += "Accept: text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8\r\n";
requestbuf += "Accept-Language: en-us,en;q=0.5\r\n";
requestbuf += "Connection: keep-alive\r\n";
requestbuf += "\r\n\r\n\r\n";
}

HttpService CHttpLink::GetService( const char *path)
{
HttpService portid = SERVICE_HTTP;

if (strncmp(path, "http://", 7) == 0)
        {
        portid = SERVICE_HTTP;
        }
else
if (strncmp(path, "https://", 8) == 0)
        {
        portid = SERVICE_HTTPS;
        }

return portid;
}

// --------------------------------------------------------------------------
// Open the socket and send a HTTP 1.1 request
// --------------------------------------------------------------------------

int CHttpLink::SendRequest(HttpService service, const char *pservername, const char *pfilename, int mode)
{
int	httpsocket, bytecount;	
struct in_addr		hostaddress;
hostent *phostentry;
servent *pserverentry;
sockaddr_in4 serveraddress;
string requestbuf;

if ( !pservername || !pfilename )	
	{
	cerr << "Error: No server or file path\n";
	return(-1);
	}

if (strncmp(pservername, "http://", 7) == 0)
	{
	pservername += 7;
	}
else
if (strncmp(pservername, "https://", 8) == 0)
	{
	pservername += 8;
	}

cout << "CHttpLink::SendRequest #1" << pservername << " " << pfilename  << "\n";

// ----- Use inet_addr() to determine if we're dealing with a ---------------
// ----- name or address                                      ---------------

hostaddress.s_addr = inet_addr(pservername);

if (hostaddress.s_addr == INADDR_NONE)
	{
	cout << "No s_addr, so looking up |" << pservername << "|" << endl;
	phostentry = gethostbyname(pservername);// Assume name
	}
else
	{
	cout << "Looking up host by address" << endl;
	phostentry = gethostbyaddr((const char *)&hostaddress, // Assume address
				sizeof(struct in_addr), AF_INET);
	}

if (phostentry == NULL)
	{
	cerr << "Error: No host entry\n";
	return -1;
	}

// ----- Create a TCP/IP stream socket --------------------------------------

httpsocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

if (httpsocket == INVALID_SOCKET)
	{
	cerr << "Error: No host socket\n";
	return -2;
	}

// ----- Find the port number for the HTTP service on TCP -------------------

pserverentry = getservbyname("http", "tcp");

if (pserverentry == NULL)
	{
	serveraddress.sin_port = htons(service);
	}
else
	{
	serveraddress.sin_port = pserverentry->s_port;
	}

// ----- Fill in the rest of the server address structure -------------------

serveraddress.sin_family = AF_INET;
serveraddress.sin_addr = *((in_addr *)*phostentry->h_addr_list);

// ----- Connect the socket -------------------------------------------------

bytecount = connect(httpsocket, (sockaddr *)&serveraddress, 
			sizeof(sockaddr_in4));

if (bytecount == SOCKET_ERROR)
	{
	closesocket(httpsocket);
	
	cout << "Error: No socket connection - bytecount negative" << endl;

	return(bytecount);
	}

// ----- Format the HTTP request --------------------------------------------

if ( mode == MODE_GET )	
	{
	requestbuf = "GET ";
	}
else
if ( mode == MODE_PUT )
	{
	requestbuf = "PUT ";
	}

requestbuf += string(pfilename);
//requestbuf += " HTTP/1.1\r\n";
//requestbuf += "Host: " + string( pservername) + "\r\n";

//AppendUserAgent(requestbuf);	

cout << "------- Request ---------" << endl;
cout << "|" << requestbuf << "|" << endl;
cout << "-------------------------" << endl;

// if dry_run
// return

bytecount = send(httpsocket, requestbuf.data(), requestbuf.length(), 0);

if (bytecount == SOCKET_ERROR)
	{
	cout << "Error: No socket send" << endl;
	closesocket(httpsocket);	
	return(-1);
	}

return httpsocket;
};

// --------------------------------------------------------------------------
// Open the socket
//
// Inputs: pservername - Server name
//         pfilename   - File name
//         fpout       - File handler
//        
// Outputs: None
//
// Results: 
// --------------------------------------------------------------------------

#define RECBUFFER_SIZE 1024
#define DEFAULT_SIZE (512*1024)

int CHttpLink::GetFile(HttpService service, const char *pservername, const char *pfilename, ofstream &stream)
{
char receivebuf[RECBUFFER_SIZE];
int httpsocket, bytecount;

if (service == SERVICE_HTTP)
	{
	cout << "Service HTTP get file |" << pservername << "|" << endl;
	}

if (service == SERVICE_HTTPS)
	{
	cout << "Service HTTPS get file |" << pservername << "|" << endl;
	}

// ----- Open the socket -----------------------------------------------------

httpsocket = SendRequest(service, pservername, pfilename, MODE_GET );

if ( httpsocket <= 0 )			// Less than zero? 
	{
	cout << "Error: Httplink could not get socket" << endl;
	return httpsocket;		// Then return error message
	}

// ----- Receive the file block by block ------------------------------------

bytecount =1;

while(bytecount != 0)
	{
	bytecount = recv(httpsocket, receivebuf, sizeof(receivebuf), 0);
		
	if (bytecount == SOCKET_ERROR)
		{
		closesocket(httpsocket);
		
		return bytecount;
		}

	stream.write(receivebuf, bytecount );	// Write to file
	}

// ----- Close the socket and return no errors ------------------------------

closesocket(httpsocket);	

return(0);
}

// --------------------------------------------------------------------------
// Read an HTTP file
// --------------------------------------------------------------------------

// --------------------------------------------------------------------------
// Utility routine to convert an ASCII string into an hexadecimal value
//
// Inputs:  pstr - Pointer to the string
//
// Outputs: None
//
// Results: Numeric value of the hexadecimal string
//
// Effects: None
// --------------------------------------------------------------------------

int atohex( char *pstr )
	{
	int result = 0;

	while ( *pstr != '\0' )
		{
		if ( ( *pstr >= '0') && (*pstr <= '9') )
			{
			result <<= 4;
			result += *pstr - '0';
			}
		else
		if ( ( *pstr >= 'a') && (*pstr <= 'f') )
			{
			result <<= 4;
			result += *pstr - 'a' + 10;
			}
		else
		if ( ( *pstr >= 'A') && (*pstr <= 'F') )
			{
			result <<= 4;
			result += *pstr - 'A' + 10;
			}
		else
			return(result);

		pstr++;
		}

	return( result );
	}

// --------------------------------------------------------------------------
// Get the buffer - string version
// --------------------------------------------------------------------------

int CHttpLink::GetBuffer(string &data, string &httpfile )
{
char *pbuffer;
int   len;
string server, filepath;
HttpService service;

cout << "GetBuffer #1" << endl;

if ( httpfile.length() == 0 )
	{
	return(0);
	}

ExtractServerPath( service, httpfile, server, filepath );

pbuffer = GetBufferService(service, server.data(), filepath.data(), len );

if ( pbuffer )
	{	
	data = pbuffer;

	delete [] pbuffer;

	return(1);
	}
else
	{
	data.clear();
	}

return(0);
}

// --------------------------------------------------------------------------
// Get the buffer 
//
// Inputs: pservername - Pointer to the server name
//         pfilename   - Pointer to the file name
//         rbuflen     - Reference to the resulting buffer
// 
// Outputs: rbuflen    - Set to the size of the buffer
//
// Results: Pointer string to the buffer
//
// Effects: None
// --------------------------------------------------------------------------

char *CHttpLink::GetBufferService(HttpService service, const char *pservername, const char *pfilename, int &rbuflen )
{
int  httpsocket, bytecount, bufferpos, buffermax, contlen, done, lengthval;
int  chunked;
char tempbuf[DEFAULT_SIZE], lengthbuffer[32], *pbufferdata, *btemp;

CSocketStream stream;

pbufferdata = NULL;
bufferpos = 0;
cout << "GetBufferService ----------------------------- BEGIN" << endl;

cout << "Http Get: " << pservername << "|" << pfilename << "|" << endl;

// --------------------------------------------------------------------------
// Open the socket
// --------------------------------------------------------------------------

httpsocket = SendRequest(service, pservername, pfilename, MODE_GET );

if ( httpsocket < 0 )			// Less than zero? 
	{
	cout << "Error: HttpLink Did not get file" << endl;
	cout << "GetBufferService ----------------------------- ENDFAIL" << endl;
	return( NULL );
	}

stream.SetSocket( httpsocket );

cout << "sendRequest successful" << endl;

// --------------------------------------------------------------------------
// First of all, read the header - this may or may not contain the content
// length.
// --------------------------------------------------------------------------

contlen   = 0;
done      = 0;
chunked   = 0;
buffermax = DEFAULT_SIZE;

while (!done )
	{
	stream.GetString( tempbuf, DEFAULT_SIZE-1 );

	cout << "Header: |" << tempbuf << "|" << endl;

	if ( strstr( tempbuf, "Content-Length" ) != NULL )
		{
		contlen = 1;
		buffermax = atoi( tempbuf+15);
		}

	if ( (strstr( tempbuf, "Transfer-Encoding:" ) != NULL ) &&
		(strstr( tempbuf, "chunked" ) != NULL ) )
			{
			chunked = 1;
			}

	if ( (strstr( tempbuf, "HTTP" ) != NULL ) && 
	     ((strstr( tempbuf, "40" ) != NULL  ) ||
	      (strstr( tempbuf, "30" ) != NULL )) ) 
		{
		close( httpsocket );

		pbufferdata = new char[32];

		strcpy(pbufferdata,"Error\n" );

		rbuflen = strlen(pbufferdata);

		return( pbufferdata );	
		}

	if ( strstr( tempbuf, "Bad Request" ) != NULL )
		{
		close( httpsocket );

		pbufferdata = new char[32];

		strcpy( pbufferdata, "Error 400 - Bad request\n" );
		
		rbuflen = strlen(pbufferdata );

		return( pbufferdata );
		}
		
	if ( strlen(tempbuf) == 2 )
		{
		done++;
		}
	}

// --------------------------------------------------------------------------
// If data is chunked, process it that way
// --------------------------------------------------------------------------

if ( chunked )
	{
	done = 0;
	bufferpos = 0;

	while ( !done) 
		{
		stream.GetString( lengthbuffer, 31 );

		lengthval = atohex( lengthbuffer );

		if ( lengthval == 0 )
			done = 1;

		if ( lengthval > 0 )
			{
			buffermax += lengthval;

			btemp = new char[buffermax];

			memcpy( btemp, pbufferdata, bufferpos );

			delete [] pbufferdata;

			pbufferdata = btemp;
			}

		while ( lengthval-- > 0 )
			{
			pbufferdata[bufferpos++] = stream.GetChar();
			}

		stream.GetChar();
		stream.GetChar();
		}
	}
else
// --------------------------------------------------------------------------
// Otherwise, if we know the length of the file, we can read it that way
// --------------------------------------------------------------------------

 if ( contlen )
	{
	cout << "Expecting " << buffermax << " bytes\n";

	pbufferdata = new char[buffermax+1];	

	bufferpos = stream.FlushBuffer( pbufferdata );
                                                                                
        // ------------------------------------------------------------------
        // Read the rest of the file
        // ------------------------------------------------------------------
                                                                                
        while ( bufferpos < buffermax )
                {
                bytecount = recv(httpsocket,
                        pbufferdata+bufferpos, 1024, 0);
                                                                                
                if (bytecount == SOCKET_ERROR)
                        {
                        stream.Close();
                                                                                
                        delete [] pbufferdata;
                                                                                
			cout << "GetBufferService ----------------------------- END SOCKETERROR" << endl;
                        return(NULL);
                        }
                                                                                
                bufferpos += bytecount;
                }
	}

// --------------------------------------------------------------------------
// Close the socket and return the data
// -------------------------------------------------------------------------- 

stream.Close();

rbuflen = bufferpos;

cout << "GetBufferService ----------------------------- END" << endl;

return( pbufferdata );
}

// --------------------------------------------------------------------------
// High level routine to read http file into a buffer
// --------------------------------------------------------------------------

char *CHttpLink::GetBuffer(const char *pfilepath, int &rbufsize )
{
int len = strlen(pfilepath );

cout << "GetBuffer #3 ---------------------------------- BEGIN" << endl;

char *psplitpath = new char[len+1];
char *pserver = new char[len+1];
HttpService service;

ExtractServerPath(service, pfilepath, pserver, psplitpath );

char *pbufferdata = GetBufferService(service, pserver, psplitpath, rbufsize );

delete [] psplitpath;	// Delete split path and server name
delete [] pserver;

cout << "GetBuffer #3 ---------------------------------- END" << endl;
return( pbufferdata );	// Return pointer to data
}

// --------------------------------------------------------------------------
// High level routine to read http file into an open file handler
// --------------------------------------------------------------------------                                                                                
void CHttpLink::GetFile(HttpService service, const char * pfilepath, ofstream &stream )
{
cout << "GetFile #1" << endl;

int len = strlen(pfilepath);
                                                                               
char *psplitpath = new char[len+1];
char *pserver = new char[len+1];
                                                        
ExtractServerPath(service, pfilepath, pserver, psplitpath );
int rbufsize;
char *pbufferdata = GetBufferService(service, pserver, psplitpath, rbufsize );

stream.write( pbufferdata, rbufsize );

delete [] psplitpath;	// Delete split path and server name
delete [] pserver;

delete [] pbufferdata;	// Delete pointer to file data
}

// --------------------------------------------------------------------------
// High level routine to read http file into the selected file
// --------------------------------------------------------------------------

int CHttpLink::GetFile(const char *pfilepath,const char *dstpath )
{
int buflen;
cout << "GetFile #2 ----------------------------------- BEGIN " << endl;
char *pbuffer = GetBuffer( pfilepath, buflen );
cout << "GetFile #2 ------------------------------------END   " << endl;

if ( !pbuffer )
	{
	return(false);
	}

cout << "Writing file <" << dstpath << ">\n";                                                                               
ofstream stream;

stream.open( dstpath );

if ( !stream.is_open() )
	{
	cout << "CHttpLink::GetFile failed to open <" <<dstpath<<">" << endl;
	return(false);
	}

stream.write( pbuffer, buflen );

stream.close();

return(true);
}

int CHttpLink::GetFile(HttpService service, const string &strhost, const string &strpath, 
			 const string &destpath)
{
const char *pbufdata;
int buflen;

cout << "GetFile #3" << endl;

pbufdata = GetBufferService(service, strhost.data(), strpath.data(), buflen);

// If we have the data, then try and save it
if ( buflen > 0 )       // Got the file
        {
        ::WriteStream( pbufdata, destpath, buflen);
        }

return buflen;
}

// ==========================================================================
// HTTP PUT REQUESTS
// ==========================================================================

// --------------------------------------------------------------------------
// Put the buffer to the server
// --------------------------------------------------------------------------

int  CHttpLink::PutBuffer( const char *pservername, const char *pfilename, 
			const char *pbuffer, int bufsize )
{
int   httpsocket;

HttpService service = GetService( pservername);
// Open the socket and make request
httpsocket = SendRequest(service, pservername, pfilename, MODE_PUT );

if ( httpsocket < 0 )			// Less than zero? 
	{
	return( httpsocket );		// Then return error message
	}

// TODO: #1009 Send the data to be uploaded

closesocket(httpsocket);	
return( 1 );
}

// --------------------------------------------------------------------------
// Split the file path and send it to the server
// --------------------------------------------------------------------------

int  CHttpLink::PutBuffer( const char *pfilepath, const char *pbuffer, 
			int bufsize )
{
char *pserver, *psplitpath;
int len;

len = strlen(pfilepath );

cout << "[1] Allocating\n" << endl;

psplitpath = new char[len+1];
pserver = new char[len+1];

cout << "[2] Extract server path\n" << endl;

HttpService service;
ExtractServerPath(service, pfilepath, pserver, psplitpath );

cout << "[3] Get buffer\n" << endl;

PutBuffer( pserver, psplitpath, pbuffer, bufsize );

cout << "[4] Deallocating\n" << endl;

delete [] psplitpath;	// Delete split path and server name
delete [] pserver;

cout << "[5] All done\n" << endl;

return(1);
}

// --------------------------------------------------------------------------
// Put the file to the server
// --------------------------------------------------------------------------

int CHttpLink::PutFile( const char *pservername, const char *pfilename, 
			  ifstream &stream, int   nbytes )
{
char receivebuf[RECBUFFER_SIZE];
int   httpsocket, bytecount, bytetotal;

HttpService service = GetService(pservername);

// ----- Open the socket -----------------------------------------------------

httpsocket = SendRequest(service, pservername, pfilename, MODE_PUT );

if ( httpsocket < 0 )			// Less than zero? 
	return( httpsocket );		// Then return error message

// ----- Receive the file block by block ------------------------------------

bytetotal = 0;
while(nbytes > 0)
	{	
	if( nbytes> RECBUFFER_SIZE )
		{
		stream.read(receivebuf, RECBUFFER_SIZE );	// Read buffer

		bytecount = send(httpsocket, receivebuf, sizeof(receivebuf), 0);

		nbytes -= RECBUFFER_SIZE;
		}
	else
		{
		stream.read(receivebuf, nbytes );

		bytecount = send(httpsocket, receivebuf, nbytes, 0);
		}

	if (bytecount == SOCKET_ERROR)
		{
		closesocket(httpsocket);
		
		return(bytecount);
		}

	bytetotal += bytecount;
	}

// ----- Close the socket and return no errors ------------------------------

closesocket(httpsocket);	

return(bytetotal);
}

// --------------------------------------------------------------------------
// Put the open file to the server
// --------------------------------------------------------------------------

void  CHttpLink::PutFile( const char *pfilepath, ifstream &stream, int nbytes )
{
int len = strlen(pfilepath );
                                                                               
char *psplitpath = new char[len+1];
char *pserver    = new char[len+1];
              
char *pbufferdata = new char[nbytes];

stream.read( pbufferdata, nbytes );
                                                                  
HttpService service;

ExtractServerPath(service, pfilepath, pserver, psplitpath );

PutBuffer(   pserver, psplitpath, pbufferdata, nbytes );

delete [] psplitpath;	// Delete split path and server name
delete [] pserver;
delete [] pbufferdata;	// Delete pointer to file data
}

// --------------------------------------------------------------------------
// Put the selected file to the server
// --------------------------------------------------------------------------

int CHttpLink::PutFile( const char *pfilepath, const char *srcpath )
{
struct stat statbuf;
ifstream stream;

stream.open( srcpath );

if ( !stream.is_open() )
	return(0);

stat( srcpath, &statbuf );

PutFile( pfilepath, stream, statbuf.st_size );

stream.close();

return(1);
}
