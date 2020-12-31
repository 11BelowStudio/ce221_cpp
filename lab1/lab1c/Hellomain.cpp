/**
 *  Lab1c
 */
/*
  Here is a main program that is going to make use of the Hello class.
  It could make use of lots of other classes too (but it doesn't).
  It also demonstrates use of the heap (we could of course have written this program without using the heap)
*/

#include "Hello.h"

/**
 * Main program to test the Hello class.
 * @param args - unused command line items.
 */
int main()
{
    Hello h("shoutouts to simpleflips");  // invokes the one-argument constructor
    h.doIt();
    return 0; // end the program neatly, everything is ok.
}
