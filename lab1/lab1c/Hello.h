/**
 *  Lab1c
 */
/*
  This .h file contains the interface to our hello class which will be
  implemented in Hello.cpp.
  We describe the behaviour of this class here. We implement it in the .cpp file.
  We make sure that only one copy of this .h file is included.
*/
#ifndef _HELLO_H //checks to see if a header with the id '_HELLO_H_' is present in the file
#define _HELLO_H //if it's not already there, it will now create it.

using namespace std;
/*
  We need to include the interface to the string library.
*/
#include <string>

class Hello
{
public:
    /**
     * Constructor. Initialises the data item.
     * @param s - string to initialise the data item with.
     */
    Hello(string s); //no implementation of the constructor

    /**
     * this void function prints the message.
     */
    void doIt(); //also no implementation of the function
private:
    /*
       This is our instance of the message.
     */
    string message; //the string is uninitialized
};
// note the semicolon
// leave at least one empty line at the end so that if it's necessary to examine the temporary file generated
// by the C preprocessor there's a blank line between the class declaration and the next line of code

#endif //ends creating the new header
