// ---------------------------------------------------------------------------
// Copyright: (C) VFX Research 2002 - 2014. All Rights Reserved.
// ---------------------------------------------------------------------------

#include "extensionlib.h"

// --------------------------------------------------------------------------
// Extract a single pattern from a std::string
// --------------------------------------------------------------------------

static int StringExtractPattern( 
		std::string &strpat, 
		const std::string &strmask, 
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
strpat  = "";			// Clear pattern std::string
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
		const std::string &strmask, 
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
// Match a std::string against a pattern
// --------------------------------------------------------------------------

static int StringMatchPattern( const std::string &strpath, const std::string &strmask )
{
bool done = false;
unsigned int pathpos = 0;
unsigned int maskpos = 0;
unsigned int maskmax;
unsigned int pathmax;
char chmask;

ctrace << "----- MatchPattern -----" << std::endl;

maskmax = strmask.size();
pathmax = strpath.size();

while ( !done )	 // While not done
	{
	ctrace << "pathpos = " << pathpos << std::endl;
	ctrace << "maskpos = " << maskpos << std::endl;

	// In the case that strmask is something like *.txt and 
	//		    strpath is something like *.txt.old 
	// we need to do a test here

	if ( ( maskpos == maskmax ) && (pathpos < pathmax ) )
		{
		return false;
		}

	chmask = strmask.at(maskpos);
	maskpos++;

	ctrace << "chmask = " << (char) chmask << std::endl;

	if ( chmask == '\\' )
		{
		chmask = strmask.at(maskpos);
		maskpos++;

		ctrace << "literal" << std::endl;

		if ( strpath.at(pathpos) != chmask )
			{
			ctrace << "\tno match" << std::endl;

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
					ctrace << "wildcard * ending with " << (char) chmask << std::endl;

					unsigned int pos = strpath.size()-1;

					while ( strpath.at(pos) != chmask)
						{
						pos--;
						}
						
					if ( pos > pathpos )
						{
						pathpos = pos;	
						}

					ctrace << "Pathpos now " << pathpos << std::endl;
					ctrace << "Maskpos now " << maskpos << std::endl;
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

				ctrace << "wildcard ? ending with " << (char) chmask << std::endl;

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
				ctrace << "normal char " << (char) chmask << std::endl;
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

ctrace << "Matched" << std::endl;
ctrace << "---------------" << std::endl;

return true;
}

// --------------------------------------------------------------------------
// Match a std::string against a mask filter
// --------------------------------------------------------------------------

int StringMatch( const std::string &strtarget, const std::string &strmask )
{
bool found = false;      // found = false
bool done = false;      // done = false
unsigned int pos = 0;
std::string strpat;

ctrace << "Matching target |" << strtarget;
ctrace << "| with |" << strmask << "|" << std::endl;

while ( !done )	  // While not done
	{
	// Extract pattern from mask
	found = StringExtractPattern( strpat, strmask, pos );

	ctrace << "Pattern = |" << strpat << "|" << std::endl;

	if ( !found )	   // No more patterns
		{
		done = true;
		}
	else
		{
		//      Match std::string against pattern
		found = StringMatchPattern( strtarget, strpat );

		if ( found )
			{
			ctrace << "Pattern = |" << strpat << "|" << std::endl;
			ctrace << "Match = " << found << std::endl;

			done = true;
			}
		}
	}

return found;
}
