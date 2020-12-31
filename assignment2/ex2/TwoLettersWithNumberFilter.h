//header for the second filter derived class

//filter: letter count >= 2, numeric digit count >= 1.
#ifndef _TWOLETTERSWITHNUMBERFILTER_H
#define _TWOLETTERSWITHNUMBERFILTER_H

using namespace std;
#include <string>
#include "ReadFilteredWords.h"


class TwoLettersWithNumberFilter: public ReadFilteredWords
{

public:

    /**
    * Constructor. Opens the file with the given filename.
    * Program exits with an error message if the file does not exist.
    * @param fname - a C string naming the file to read.
    */
    TwoLettersWithNumberFilter(const char *fname): ReadFilteredWords(fname)
    {
    }

    /*
    Implementation of 'ReadFilteredWords' filter function
    @param 'word': a word to check against the filter

    Returns true if:
    	* 'word' has at least two letters (any case)
    		and
    	* 'word' has at least one number/numeric digit
    Returns false otherwise
    */
    bool filter(string word);
};

#endif
