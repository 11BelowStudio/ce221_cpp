// header file for C++ assignment 1 exercise 1 2019

// you must not change any of the existing code in this file

// you may if you wish add extra data members to the class, such as an array
//   holding the numbers of days in each month and/or an array holding the
//   names of the months ("January" etc)

// you must not add any extra member functions or friends

// you may change, or add to, the comments below

#ifndef _DATE_H_

#define _DATE_H_

using namespace std;

#include <iostream>
#include <string>

class Date
{
private:
    unsigned int d; // 1-31
    unsigned int m; // 1-12
    unsigned int y; // 1000-9999 (must be a 4-digit year)


    //I added the following 4 member variables
    const static unsigned int monthLengths[];
    //holds the lengths of each month in days
    const static unsigned int leapLengths[];
    //same as above, but for leap years instead
    const static string monthNames[];
    //holds names of each month
    bool isLeap;
    //stores result of isLeapYear, saves some re-evaulations of isLeapYear();

public:
    Date();  // initialise members to valid default values, e.g. 1/1/2019
    Date(unsigned int day, unsigned int month, unsigned int year);
    // initialise using arguments
    // use default valid values and output a warning message
    //    if any argument is out of range
    //    or if day is 29, 30 or 31 and month has fewer days

    bool isLeapYear() const;
    // return true if the value of y is a leap year

    Date& operator++();  // prefix version; should return new value
    Date operator++(int);  // postfix version; should return old value
    Date& operator--();  // prefix version; should return new value
    Date operator--(int);  // postfix version; should return old value

    bool operator<(const Date& other) const;
    // return true if this date is before other, false otherwise
    bool operator==(const Date& other) const;
    // return true if this date is equal to other, false otherwise

    operator string() const;
    // return a string of the form "2nd November 2019"

    // you can generate a string containing digits using to_string(n)
    //    where n is a variable (or expression) of type int

    // you can use + and += to concatenate strings as in Python

    // expressions such as s + x and s += x are valid
    //    when s is a string and x is a char or a C-string
    //    (but not when x is a number)

    friend ostream& operator<<(ostream& o, const Date& d);
    // output date in format dd/mm/yyyy, e.g. 02/11/2019
};

// the following functions should be written
// they must not be members or friends of the class
//    and hence must not attempt to access the private members

bool operator<=(const Date& d1, const Date& d2);
// return true if d1 is equal to or before d2, false otherwise
bool operator>(const Date& d1, const Date& d2);
bool operator!=(const Date& d1, const Date& d2);
bool operator>=(const Date& d1, const Date& d2);

#endif
