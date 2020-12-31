//readwords header for assignment 1 exercise 2

#ifndef READWORDS_H
#define READWORDS_H
/*
ReadWords class
	Reads from a text file
	Returns lowercase versions of words from that text file
		Will return an empty string if the 'word' does not contain any letters
			(as it looks like those are invalid for purposes of this assignment)
*/
using namespace std;

#include <string>
#include <fstream>

class ReadWords
{
public:

    /*
    Constructor for this class

    	Associates the 'wordfile' filestream with the file which has a name which matches the '*filename' c-string parameter

    	'nextWord' is set to the first item from 'wordfile'

    	'eoffound' initialised depending on whether the end of the file has been reached
    */
    ReadWords(const char *filename);

    //literally just closes the input filestream
    void close();

    /*
    gets the next 'word' string from the file

    Obtains the string 'word' from the 'nextWord' one-word lookahead
    Updates 'nextWord' to be the word following this one
    Updates 'eoffound' if needed

    Removes punctuation from 'word' (or clearing it if it does not contain letters, as, for purposes of this assignment, a word must contain a letter for it to be valid)
    	Does this using the 'removePunct(string word)' function in ReadWords.cpp

    returns 'word'
    */
    string getNextWord();


    //Literally just returns true if the end of the file has not been reached
    //(inverse of 'eoffound')
    bool isNextWord();

private:
    ifstream wordfile; //input filestream
    string nextword; //string to hold the next word from the input filestream
    bool eoffound; //boolean to declare if the end of the file has been reached
};

#endif
