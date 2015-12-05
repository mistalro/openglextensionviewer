#ifndef _FILEDOWNLOADER_H_
#define _FILEDOWNLOADER_H_

#include <iostream>
#include <iostream>
#include <string>
#include <exception>

#include <curl/curl.h>

extern "C"
{
#include <curl/curl.h>
#include <stdlib.h>
}

// --------------------------------------------------------------------------
// Exception class for curl exception
// --------------------------------------------------------------------------

class CurlException : std::exception
{
private:
std::string m_message;

public:
CurlException(std::string message):m_message(message) {  }
CurlException(CURLcode error)
	{
	m_message = curl_easy_strerror(error);
	}

~CurlException() throw() { }

const char* what() throw()
	{
	return m_message.c_str();
	}
};

// --------------------------------------------------------------------------
// Wrapper class around the libcurl library
//
// The most important function is Fetch, which returns a std::string object
// downloaded from the specified URL
// --------------------------------------------------------------------------

class CFileDownloader
{
CURL *m_handle;		// CURL Handler
std::string m_url;	// URL std::string
std::string m_data;	// Data std::string

public:
CFileDownloader(void) throw (CurlException)
	{
	m_handle = curl_easy_init();

	if ( m_handle == NULL )
		throw CurlException("Unable to initialize curl handler");
	}

std::string Fetch(const std::string &url) throw (CurlException)
	{
	SetURL( url );
	SetOptions();
	SendGetRequest();
	
	return m_data;
	}

bool Download(const std::string &url, const std::string &path) throw (CurlException)
	{
	SetURL( url );
	SetOptions();
	SendGetRequest();
	bool result = false;
	
	std::ofstream stream;

	stream.open( path.data(), std::ios::binary | std::ios::out );

	if ( stream.is_open() )
		{
		stream.write( m_data.data(), m_data.size() );

		stream.close();
		result = true;
		}

	return result;
	}

~CFileDownloader() throw()
	{
	curl_easy_cleanup(m_handle);
	}

private:

// Stage #2 - Set URL
void SetURL(const std::string &url) 
	{
	if ( url.length() == 0 )
		throw CurlException("URL can't be of zero length");

	m_url = url;
	}

// Stage #3 - Set Options
void SetOptions() throw (CurlException)
	{
	CURLcode res;

	// Set the url
	res = curl_easy_setopt(m_handle, CURLOPT_URL, m_url.c_str());

	if ( res != CURLE_OK)
		throw CurlException(res);

	// Progress bar is not required
	res = curl_easy_setopt(m_handle, CURLOPT_NOPROGRESS, 1L);

	if ( res != CURLE_OK )
		throw CurlException(res);

	// Set the callback function for writing
	res = curl_easy_setopt(m_handle, CURLOPT_WRITEFUNCTION,
                              CFileDownloader::WriteDataCallback);

	if ( res != CURLE_OK )
		throw CurlException(res);

	// Set pointer in call back function
	res = curl_easy_setopt(m_handle, CURLOPT_WRITEDATA, this);

	if ( res != CURLE_OK )
		throw CurlException(res);
	}

// Stage #4 - Send HTTP Request
void SendGetRequest()
	{
	m_data.clear();

	CURLcode res = curl_easy_perform(m_handle);

	if ( res != CURLE_OK )
		throw CurlException(res);
   	}

// Stage #5 - Receive data from server and write it to buffer
static size_t WriteDataCallback(void *ptr, size_t size,
                                    size_t nmemb, void* pInstance)
	{
	return (static_cast<CFileDownloader*>(pInstance))->write_data(ptr, size, nmemb);
   	}

size_t write_data(void* ptr, size_t size, size_t nmemb)
	{
	size_t numOfBytes = size * nmemb;

	char *iter = (char*)ptr;
	char *iterEnd = iter + numOfBytes;

	m_data += std::string(iter, iterEnd);

	return numOfBytes;
   	}
};

#endif	// _FILEDOWNLOADER_H_
