/**
 *  Lab3a output
 */
/**
 * This small program will be used to look at primitive I/O
 */
using namespace std;

#include <iostream> //allows input/output
#include <string> //allows the use of strings
#include <cstring> //allows the use of cstrings
#include <cctype> //allows classification/transformation of characters


void words(const char *buf)
{
    /*
    	Inputs
    		C-string
    	Ouputs
    		void
    	User output
    		The contents of the C-string, one word per line
    			(word = sequence of non-whitespace characters)
    */
    string oneWord; //uses no-argument string operator, makes it empty
    for (int i = 0; i < strlen(buf); i++)
    {
        //for each character in buf
        //note: 'strlen()' gets the length of a c-string, from '#include <cstring>'
        char c = buf[i]; //c set to current charactet of buf
        if (isspace(c))
        {
            //if c is a space (from '#include <cctype>')
            if (!oneWord.empty())  //if oneWord is not empty
            {
                cout << oneWord << endl; //output it
                oneWord.clear(); //clear contents of oneWord
            }
        }
        else    //if c is not a space
        {
            oneWord += c;
            //c appended to oneword
        }
    }
    //if there's still something on oneWord that still needs to be output
    if (!oneWord.empty())
    {
        cout << oneWord << endl; //outputs it
        oneWord.clear(); //clears it
    }
    return;
}





main()
{
    /*
      We will make a character buffer of a reasonable size later.
      We have an array of 10 characters. (EDITED TO 100) We read into it.
      It is legal but deadly to read in more.
    */
#define BUF_SIZE 100

    char buf[BUF_SIZE];

    /*
       FOR TEACHING PURPOSES ONLY,  we initialize the buffer with nonsense.
       We do a horrible thing to a character - increment it.
     */
    char a = 'a';
    for (int i=0; i<BUF_SIZE; ++i)
    {
        buf[i]= a;
        a++;
    }
    /*
    	this makes the 'buf' array contain characters
    	First character is a, then every following character is the following character
    	after the first character
    	Later on, when the input is put into the buffer, this has an effect on the output of 'buf'
    		The characters in the input are unchanged
    		The character following the last character in the input is blank
    		The following characters will be whatever they were set to within this loop
    */

    cout << " type a line: ";

    /*
     Note the check in the getline method. We should not read more characters than
     the available space will hold, + one for the zero terminating the C string.
     	Means that the final character of input will be shown as an empty character when output
     Note that getline throws away the newline.
     */
    cin.getline(buf, BUF_SIZE);

    //in case we want to do string manipulation with that line in a proper C++ string.
    string s = buf;

    //comparison printout just to check
    cout << '[' << s << ']' << endl;    //print the string
    cout << '<' << buf << '>' << endl;  //print the original array

    /* write out a part of the string,  delimited so we can see the strings
      clearly. This is very primitive I/O. all other I/O uses these to implement
      the more complex I/O behaviour.
     */
    cout.put('[');
    cout.write(buf, 9);
    cout.put(']');
    cout.put('\n');

    cout.put('[');
    cout.write(buf, 5);
    //too small to return a full output of '123456', will only display 5 characters
    cout.put(']');
    cout.put('\n');

    cout.put('[');
    cout.write(buf, 10);
    /*
    attempts to output 10 items from 'buf', which doesn't work
    the 10th chracter is not displayed, as, earlier on,
    	when buf was set to hold the input string, the end of the input string
    	was supposed to be declared as a 0 to show that the line was terminated,
    	however, as a 10-character input fills all of buf, the final input character
    	is overwritten to be the 0 to indicate the end of the string
    */
    cout.put(']');
    cout.put('\n');

    //not really necessary, as the newline has the same effect unless cout refers to a file.
    cout.flush();

    //int size = strlen(buf);
    //cout << size << endl;

    words(buf);

    return 0;
}

