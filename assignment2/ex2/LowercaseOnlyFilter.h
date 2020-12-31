//header for the first filter derived class

//filter: lowercase count >= 1, uppercase count = 0.
#ifndef _LOWERCASEONLYFILTER_H
#define _LOWERCASEONLYFILTER_H

using namespace std;
#include <string>
#include "ReadFilteredWords.h"


class LowercaseOnlyFilter: public ReadFilteredWords
{

public:

    /**
    * Constructor. Opens the file with the given filename.
    * Program exits with an error message if the file does not exist.
    * @param fname - a C string naming the file to read.
    */
    LowercaseOnlyFilter(const char *fname): ReadFilteredWords(fname)
    {
    };



    /*
    Implementation of 'ReadFilteredWords' filter function
    @param 'word': a word to check against the filter

    Returns true if:
    	* 'word' has at least one lowercase letter
    		and
    	* 'word' has no uppercase letters
    Returns false otherwise
    */
    bool filter(string word);

};

#endif
