/* Copyright (C) 2015 Dr. Michael Robb

   This program is free software; you can redistribute it and/or
   modify it under the terms of the GNU General License
   as published by the Free Software Foundation; either
   version 3 of the License, or (at your option) any later version.

   The program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Public License for more details.

   You should have received a copy of the GNU Public License 
   along with the GNU C Library; if not, write to the Free
   Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
   02111-1307 USA.  */
// --------------------------------------------------------------------------
// Simple trace class for logging data
// --------------------------------------------------------------------------

#ifndef _CTRACE_H_
#define _CTRACE_H_

// Utility class to maintain logs of events

class CTraceLog
{
private:
std::ostream *m_ostream;	// Customm output stream
bool          m_debug;		// Enable/Disable debug mode

public:

CTraceLog(void)
        {
        m_debug = false;
	m_ostream = &std::cout;
        }

template <typename T> 
CTraceLog& operator<<(const T& x)
	{
	if (true == m_debug)
		{
	       	*m_ostream << x;
		}

        return *this;
    	}

// Function that takes a custom stream, and returns it
typedef CTraceLog& (*CTraceLogManipulator)(CTraceLog&);

// Take in a function with the custom signature
CTraceLog& operator<<(CTraceLogManipulator manip)
	{
        // call the function, and return it's value
        return manip(*this);
    	}
/*
// Define the custom endl for this stream.
// Note how it matches the `CTraceLogManipulator` function signature
static CTraceLog& endl(CTraceLog& stream)
	{
        // print a new line
       	cout << std::endl;

       	// do other stuff with the stream
       	// std::cout, for example, will flush the stream
       	cout << "Called CTraceLog::endl!" << std::endl;

        return stream;
    	}
*/

// This the function signature of std::endl
typedef std::basic_ostream<char, std::char_traits<char> > CoutType;

// This is the function signature of std::endl
typedef CoutType& (*StandardEndLine)(CoutType&);

// Define an operator<< to take in std::endl
CTraceLog& operator<<(StandardEndLine manip)
	{
        // call the function, but we cannot return it's value
	if (m_debug)
		{
      		manip(*m_ostream);
		}

        return *this;
    	}

void on(void)
        {
        m_debug = true;
        }

void off(void)
        {
        m_debug = false;
        }

void toggle(void)
        {
        m_debug = !m_debug;
        }
};

// The one and ony debug logger
extern CTraceLog ctrace;
                              
#endif	// _CTRACE_H_
