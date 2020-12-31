/**
 * Lab1a
 * This is the simplest of "hello world" programs.
 * Every line is commented (a bad idea, generally) in this first program.
 */

using namespace std;   // allows the use of the standard library.
#include <iostream>
// The line above includes the interface to simple input/output


/**
 * The following function is the main (and only, in this case)
 * function in this program. Its only purpose is to allow you
 * to learn how to compile simply using Textpad.
 */

int main() // can have arguments
{
    cout << "hello world" << endl;
    // cout is standard output stream
    // the precedence rules say that this expression means ((cout << "hello world") << endl)
    // it works since although an expression such as cout << x performs output the value of
    // the expression is a reference to the iostream

    int i = 3; //initialises i as an integer with value of 3
    int j = 4; //initialises j as an integer with value of 4
    cout << i+j << endl; ///outputs the value of i+j (7), followed by a newline (endl = newline)
}

//if endex1 is used, it says:
//error: 'endxl' was not declared in this scope
//{   cout << "hello world" << endxl;
//                             ^~~~~

//if final } is omitted, it says:
//error: expected '}' at end of input
// {   cout << "hello world" << endl;
//                                  ^

//if #include<iostream> is edited to not call iostream, it says:
//error: 'cout' was not declared in this scope
//{   cout << "hello world" << endl;
//    ^~~~
