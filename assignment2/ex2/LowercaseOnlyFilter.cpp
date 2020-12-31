//body for the first filter derived class

//filter: lowercase count >= 1, uppercase count = 0.

using namespace std;
#include "LowercaseOnlyFilter.h"
#include <string>
#include <cctype>


/*
returns true if:
	*'word' has one or more lowercase letter characters
		and
	*'word' has zero uppercase letter characters
false otherwise
*/
bool LowercaseOnlyFilter::filter(string word)
{
    bool foundLower = false;
    bool foundUpper = false;
    char current;

    //checks each character to see if they are lowercase/uppercase letters
    for (int i=0; i < word.length(); i++)
    {
        current = word[i];
        if (islower(current))
        {
            foundLower = true;
        }
        else if (isupper(current))
        {
            foundUpper = true;
            break;
            //stops the loop as soon as uppercase found
        }
    }

    //returns true if foundLower is true and foundUpper is false
    return (foundLower && !foundUpper);
}

