// ---------------------------------------------------------------------------
// Copyright: (C) VFX Research 2002 - 2014. All Rights Reserved.
// ---------------------------------------------------------------------------

using namespace std;

#include <stdlib.h>
#include <string>
#include <iostream>

// --------------------------------------------------------------------------
// Extract a single pattern from a string
// --------------------------------------------------------------------------

static int StringExtractPattern( 
		string &strpat, 
		const string &strmask, 
		unsigned int &pos )
{
int done, literal;
unsigned int max;

if ( strmask.length() == 0 )	// No pattern, so always pass
	{
	return true;
	strpat = "*";
	}

max     = strmask.size();	// Length of mask pattern
strpat  = "";			// Clear pattern string
done    = false;		// Clear done flag
literal = false;		// Clear literal flag

if ( pos == max )
	{
	return false;
	}

while ( !done )
	{
	if ( pos == max )       // Reached end of pattern?
		{
		done++;	 	// Then done
		}
	else if ( literal )  // Last character was '\'?
			{
			strpat += strmask.at(pos);
			pos++;
			literal = false;
			}
	else if ( strmask.at(pos) == '\\' ) // Literal '\'
			{
			pos++;
			literal = true;
			}
	else if ( (strmask.at(pos) == ';' ) || // Separator?
			(strmask.at(pos) == ',') )
			{
			pos++;
			done++;
			}
	else
		{
		strpat += strmask.at(pos); // Regular character
		pos++;
		}
	}

return true;
}

// --------------------------------------------------------------------------
// Get a single token
// --------------------------------------------------------------------------

static int StringGetToken( 
		const string &strmask, 
		unsigned int &pos, 
		char &token )
{
unsigned int max = strmask.size();

if ( pos < max )
        {
        token = strmask.at(pos);
        pos++;

        if (token == '\\')
                {
                token = strmask.at(pos);
		pos++;
                }

        return true;
        }

return false;
}

// --------------------------------------------------------------------------
// Match a string against a pattern
// --------------------------------------------------------------------------

static int StringMatchPattern( const string &strpath, const string &strmask )
{
bool done = false;
unsigned int pathpos = 0;
unsigned int maskpos = 0;
unsigned int maskmax;
unsigned int pathmax;
char chmask;

#ifdef DEBUG
cout << "----- MatchPattern -----" << endl;
#endif

maskmax = strmask.size();
pathmax = strpath.size();

while ( !done )	 // While not done
	{
#ifdef DEBUG
cout << "pathpos = " << pathpos << endl;
cout << "maskpos = " << maskpos << endl;
#endif

	// In the case that strmask is something like *.txt and 
	//		    strpath is something like *.txt.old 
	// we need to do a test here

	if ( ( maskpos == maskmax ) && (pathpos < pathmax ) )
		{
		return false;
		}

	chmask = strmask.at(maskpos);
	maskpos++;

#ifdef DEBUG
cout << "chmask = " << (char) chmask << endl;
#endif

	if ( chmask == '\\' )
		{
		chmask = strmask.at(maskpos);
		maskpos++;

#ifdef DEBUG
cout << "literal" << endl;
#endif
		if ( strpath.at(pathpos) != chmask )
			{
#ifdef DEBUG
cout << "\tno match" << endl;
#endif
			return false;
			}
		}
	else
		{
		switch (chmask )
			{
			case '*':	
				// Wildcard - any or no chars
				// Get next character
				if ( StringGetToken( strmask, maskpos, chmask ) )
					{
#ifdef DEBUG
cout << "wildcard * ending with " << (char) chmask << endl;
#endif
					unsigned int pos = strpath.size()-1;

					while ( strpath.at(pos) != chmask)
						{
						pos--;
						}
						
					if ( pos > pathpos )
						{
						pathpos = pos;	
						}

#ifdef DEBUG
cout << "Pathpos now " << pathpos << endl;
cout << "Maskpos now " << maskpos << endl;
#endif
					// Skip over chmask
					if ( pathpos < pathmax )
						{
						pathpos++;
						}
					else
						{
						return false;
						}
					}
				else
					{
					return true;
					}
				break;

			case '?':	       // Wildcard - one character
#ifdef DEBUG
cout << "wildcard ? ending with " << (char) chmask << endl;
#endif

				if ( pathpos < pathmax )
					{
					pathpos += 1;
					}
				else
					{
					return false;
					}
				break;

			default:		// Normal character
#ifdef DEBUG
cout << "normal char " << (char) chmask << endl;
#endif
				if ( strpath.at(pathpos) != chmask )
					{
					return false;
					}
				else
					{
					pathpos += 1;
					}
				break;
			}
		}

	if ( pathpos == pathmax )
		{
		done++;
		}

	}

#ifdef DEBUG
cout << "Matched" << endl;
cout << "---------------" << endl;
#endif

return true;
}

// --------------------------------------------------------------------------
// Match a string against a mask filter
// --------------------------------------------------------------------------

int StringMatch( const string &strtarget, const string &strmask )
{
bool found = false;      // found = false
bool done = false;      // done = false
unsigned int pos = 0;
string strpat;

#ifdef DEBUG
cout << "Matching target |" << strtarget;
cout << "| with |" << strmask << "|" << endl;
#endif

while ( !done )	  // While not done
	{
	// Extract pattern from mask
	found = StringExtractPattern( strpat, strmask, pos );

#ifdef DEBUG
cout << "Pattern = |" << strpat << "|" << endl;
#endif

	if ( !found )	   // No more patterns
		{
		done = true;
		}
	else
		{
		//      Match string against pattern
		found = StringMatchPattern( strtarget, strpat );

		if ( found )
			{
#ifdef DEBUG
cout << "Pattern = |" << strpat << "|" << endl;
cout << "Match = " << found << endl;
#endif
			done = true;
			}
		}
	}

return found;
}
