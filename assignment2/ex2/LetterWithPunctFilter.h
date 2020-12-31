//header for the third filter derived class

//filter: letter count >= 1, punctuation count >= 1.
#ifndef _LETTERWITHPUNCTFILTER_H
#define _LETTERWITHPUNCTFILTER_H

using namespace std;
#include <string>
#include <cctype>
#include "ReadFilteredWords.h"


class LetterWithPunctFilter: public ReadFilteredWords
{

public:

    /**
    * Constructor. Opens the file with the given filename.
    * Program exits with an error message if the file does not exist.
    * @param fname - a C string naming the file to read.
    */
    LetterWithPunctFilter(const char *fname): ReadFilteredWords(fname)
    {
    }

    /*
    Implementation of 'ReadFilteredWords' filter function
    @param 'word': a word to check against the filter

    Returns true if:
    	* 'word' has at least one letter (any case)
    		and
    	* 'word' has at least one punctuation character
    Returns false otherwise
    */
    bool filter(string word);

};

#endif
