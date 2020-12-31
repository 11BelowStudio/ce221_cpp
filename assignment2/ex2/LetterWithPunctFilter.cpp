//header for the third filter derived class

//filter: letter count >= 1, punctuation count >= 1.

using namespace std;
#include "LetterWithPunctFilter.h"
#include <string>
#include <cctype>

/*
Returns true if:
	* 'word' has at least one letter (any case)
		and
	* 'word' has at least one punctuation character
Returns false otherwise
*/
bool LetterWithPunctFilter::filter(string word)
{
    bool foundLetter = false;
    bool foundPunct = false;
    char current;

    //tries to find letters and punctuation characters in the string
    for (int i=0; i < word.length(); i++)
    {
        current = word[i];
        if (isalpha(current))
        {
            foundLetter = true;
        }
        else if (ispunct(current))
        {
            foundPunct = true;
        }
    }

    //only true if foundLetter and foundPunct are true
    return (foundLetter && foundPunct);
}
