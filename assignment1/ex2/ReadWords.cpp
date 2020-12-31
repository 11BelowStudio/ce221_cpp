/* class body for ReadWords */

using namespace std;

#include "ReadWords.h"
#include <cctype>
#include <cstdlib>
#include <iostream>



/* removePunct(string word)

returns a lowercase copy of 'word' with all leading/trailing punctuation removed

If 'word' is not an empty string

	Initialises some local variables
	* foundFirst (noting if first non-punctuation character is found) boolean initialised as false
	* foundLetter (noting if a letter is actually in the word) boolean initialised as false
	* wordStart (index of first non-punctuation character) int initialised
	* wordEnd (index of last non-punctuation character) int initialised
	* i (counter integer) initialised to 0

	Whilst 'i' is smaller than the size of 'word'
		If the character at index i in 'word' is not punctuation
			If 'foundFirst' is still false
				It is set to true, wordStart copies current i (as word starts here)
			If the character at index i is a letter
				Set to lowercase
				If 'foundLetter' is still false
					set to true
			wordEnd updated to be 1 more than the current value of i
				(making it i+1 prevents the last non-punctuation character from being trimmed with the trailing punctuation)
		i incremented

	If 'foundLetter' is true (word contains letters and can be valid)
		'len' integer initialised, to be the difference between wordEnd and wordStart
		'word' is trimmed to be length 'len', starting from the character at wordStart
			This omits all leading and trailing punctuation
	Else
		No letters = not valid for purposes of this assignment
		so 'word' is turned into an empty string

'word' is returned
*/
string removePunct(string word)
{
    if (!word.empty())
    {

        bool foundFirst = false;
        bool foundLetter = false;
        int wordStart;
        int wordEnd;
        int i = 0;

        while (i < word.size())
        {
            if (!ispunct(word[i]))
            {
                if (!foundFirst)
                {
                    foundFirst = true;
                    wordStart = i;
                }
                if (isalpha(word[i]))
                {
                    word.replace(i,1,1,tolower(word[i]));
                    if (!foundLetter)
                    {
                        foundLetter = true;
                    }
                }
                wordEnd = i+1;
            }
            i++;
        }

        if (foundLetter)
        {
            int len = wordEnd - wordStart;
            word = word.substr(wordStart, len);
        }
        else
        {
            word.clear();
        }
    }
    return word;
}


/* ReadWords(const char *fname)

ReadWords constructor

Initalises 'wordfile' to be associated with the file referred to by 'fname'
If 'wordfile' could not be set up
	User informed that the 'fname' file could not be opened
	Program closes

Informs user if it could be opened successfully
Attempts to obtain the first item from 'wordfile', as 'nextword'

If the end of 'wordfile' has been reached already
	'eoffound' set to true, to reflect this.

*/
ReadWords::ReadWords(const char *fname)
{
    wordfile.open(fname);//opens file with the name that matches fname
    if (!wordfile)
    {
        cout << "Failed to open " << fname << endl;
        exit(1);
    }
    cout << fname << " opened successfully!" << endl;
    wordfile >> nextword; //1st word of the file is stored as nextword
    if (wordfile.eof())
    {
        eoffound = true;
    }
}


/* getNextWord()

Returns the next word from the file associated with the 'wordfile' filestream (as a string)

Initialises the string 'word' to be the current value of the 'nextWord' string
'nextWord' updated to be the next item from the 'wordfile' filestream

If the end of 'wordfile' has been reached
	'eoffound' set to true

Returns 'word', after processing it with the 'removePunct' method
	Ensures that only a valid word is returned
*/

string ReadWords::getNextWord()
{
    string word = nextword;
    wordfile >> nextword;

    if (wordfile.eof())
    {
        eoffound = true;
    }
    return removePunct(word);
}


bool ReadWords::isNextWord()
{
    return !eoffound; //'isNextWord()' just returns the inverse of 'eoffound'
}

void ReadWords::close()
{
    wordfile.close(); //'close()' closes the wordfile filestream
}
