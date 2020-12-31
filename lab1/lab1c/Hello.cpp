/**
 *  Lab1c
 */
/*
  This .cpp file contains the implementation of the class defined in Hello.h
  so the first thing to do is to include that file.
*/
using namespace std;

#include "Hello.h"
#include <iostream>

/*
  The first code line below is "Hello::Hello(string s)"
  Hello::Hello means the Hello function from the Hello class (ie.e the constructor) defined in the .h file
  We use a one-argument constructor
*/

/**
 * Constructor. Initialises the data item.
 * @param s - string to initialise the data item with.
 * I copied this from the .h file.
 */
Hello::Hello(string s)
{
    message = s;
}

/**
 * This void function prints the message.
 * If necessary, you might add comments on the clever way you did it, but
 * not in this case.
 * Again, we use the "::" operator. It's the doIt function from the hello class.
 */
void Hello::doIt()
{
    cout << "The message is " << message << endl;
}
