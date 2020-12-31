//body for the second filter derived class

//filter: letter count >= 2, numeric digit count >= 1.

using namespace std;
#include "TwoLettersWithNumberFilter.h"
#include <string>
#include <cctype>

/*
Returns true if:
	* 'word' has at least two letters (any case)
		and
	* 'word' has at least one number/numeric digit
Returns false otherwise
*/
bool TwoLettersWithNumberFilter::filter(string word)
{
    int letterCount = 0;
    bool digitFound = false;
    char current;

    //tries to find letters and digits in the string
    for (int i=0; i < word.length(); i++)
    {
        current = word[i];
        if (isalpha(current))
        {
            letterCount++;
        }
        else if(isdigit(current))
        {
            digitFound = true;
        }
    }

    /*
    If at least 2 letters were found
    	Value of digitFound returned (only true if digit was found)
    Returns false if not
    */
    if (letterCount >= 2)
    {
        return digitFound;
    }
    else
    {
        return false;
    }

}
