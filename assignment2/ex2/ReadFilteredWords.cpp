//the body of ReadFilteredWords.h, for assignment 2

using namespace std;
#include <string>
#include <typeinfo>
#include "ReadFilteredWords.h"


/**
* Returns a string, being the next word in the file that satisfies the filter.
* @return - string - next word that satisfies the filter
* returns empty string if there's no such word
*/
string ReadFilteredWords::getNextFilteredWord()
{
    bool foundWord = false;
    string theWord;

    /*
    will read the next word from the file,
    and check it against the filter,
    until either a word satisfies the filter,
    or until the end of the file has been reached
    */
    while(isNextWord() && (!foundWord))
    {
        theWord = getNextWord();
        foundWord = this->filter(theWord);
    }

    if(!foundWord)
    {
        theWord = "";
        close();
        //theWord is empty string if no word exists/satisfies filter
    }
    return theWord;
    //returns theWord

}
