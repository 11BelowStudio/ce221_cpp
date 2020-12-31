//Date.cpp: member-function definitions for class Date

#include <iostream>
#include <iomanip>
#include <string>
#include "Date.h"

using namespace std;

//initialises these static arrays
const unsigned int Date::monthLengths[] = {31,28,31,30,31,30,31,31,30,31,30,31};
//lengths of each month in a normal year
const unsigned int Date::leapLengths[] = {31,29,31,30,31,30,31,31,30,31,30,31};
//lengths of each month in a leap year
const string Date::monthNames[] = {"January","February","March","April","May","June","July","August","September","October","November","December"};
//names of each month

Date::Date()
{
    //no-argument constructor sets it to 1/1/2019 (which is not a leap year)
    d = 1;
    m = 1;
    y = 2019;
    isLeap = false;
}

//constructor with arguments sets it to passed values
Date::Date(unsigned int day, unsigned int month, unsigned int year)
{
    /*
    validates 'y'.
    sets it to value of 'year' if it's in the range 1000-9999
    	2019 otherwise (and outputes warning message)
    */
    if (year>=1000 && year<=9999)
    {
        y = year;
    }
    else
    {
        cout << "Invalid 'year' value entered, has been set to 2019" << endl;
        y = 2019;
    }
    /*
    validates 'm'
    	sets it to value of 'month' if it's in the range 1-12
    	1 otherwise (outputs warning message)
    */
    if (month>=1 && month<=12)
    {
        m = month;
    }
    else
    {
        cout << "Invalid 'month' value entered, has been set to 1." << endl;
        m = 1;
    }
    isLeap = isLeapYear();
    //stores result of isLeapYear to save frequent re-evaluations of it

    if (isLeap)
    {
        //if this Date's 'y' value is making it a leap year
        if (day>=1 && day<=leapLengths[m - 1])
        {
            /*
            if day is between 1 and the number of days in the current month,
            	using leapLengths list to work it out
            		(leapLengths contains lengths of months for leap year)
            		(leapLengths[m-1] contains number of days for current month)
            	'd' will be set to value of 'day'
            if not
            	'd' is set to 1
            	outputs error message
            */
            d = day;
        }
        else
        {
            cout << "Invalid 'day' value entered, has been set to 1." << endl;
            d = 1;
        }
    }
    else
    {
        //same as above but using 'monthLengths' instead as it's not a leap year
        if (day>=1 && day<=monthLengths[m - 1])
        {
            d = day;
        }
        else
        {
            cout << "Invalid 'day' value entered, has been set to 1." << endl;
            d = 1;
        }
    }

}

/*
returns true if current year is leap year
	if modulo of y over 4 returns 0 = true
	false otherwise
*/
bool Date::isLeapYear() const
{
    if (y % 4 == 0)
    {
        return true;
    }
    return false;
}


//prefix '++' operator
Date& Date::operator++()
{
    d += 1; //increases 'd' by 1
    if (isLeap)
    {
        if (d > leapLengths[m - 1])
        {
            m++;
            d = 1;
            /*
            compares d to current month length from leapLengths
            increases m by 1 and sets d to 1 if d is after current month length
            */
        }
    }
    else
    {
        if (d > monthLengths[m-1])
        {
            m++;
            d = 1;
            //same as above but not with the leap year month lengths for non-leap years
        }
    }
    if (m > 12)
    {
        m = 1;
        ++y;
        isLeap = isLeapYear();
        /*
        resets m to 1 if it goes out of bounds (beyond 12)
        	Increases y by 1, and checks if this new value will be a leap year.
        I would have included this in the above if statements (to only check if m increased),
        	however, as I would need to include it in both versions that way, I opted to
        	check m regardless anyway, as that would be simpler
        */
        if (y > 9999)
        {
            y = 1000;
            /*
            resets y to 1000 if it goes out of bounds (only checks if y is increased)
            There is no need to re-check if it is a leap year, as the only
            	illegal y value reachable by this function is 10000, however,
            	both 10000 and 1000 are leap years.
            */
        }
    }
    return *this; //returns a pointer to this date
}

/*
postfix version of ++ operator

Creates a new Date object called 'CopyDate', which is a copy of this Date object
Uses the prefix ++ operator on this Date object, to increase it
Returns the unchanged CopyDate Date object
*/
Date Date::operator++(int n)
{
    Date copyDate = Date(d, m, y);
    ++*this;
    return copyDate;
}


//Prefix version of the -- operator
Date& Date::operator--()  //prefix
{

    d -= 1;
    if (d == 0)
    {
        m -= 1; //reduce m by 1 if d rolls back into prior month
        if (m == 0)
        {
            /*
            if m rolls back into prior year
            	reduce y by 1
            	set m to 12
            	re-evalulate isLeap
            */
            y -= 1;
            m = 12;
            isLeap = isLeapYear();
            if (y == 999)
            {
                y = 9999;
                /*
                set y to the year 9999 if it rolled back to 999.
                no need to check again if it's a leap year, as 999 and 9999
                are both not leap years
                */
            }
        }
        /*
        set d to the last day of the new month,
        using the appropriate list of month lengths
        */
        if (isLeap)
        {
            d = leapLengths[m - 1];
        }
        else
        {
            d = monthLengths[m - 1];
        }
    }
    return *this; //returns pointer to this object
}

/*
Postfix -- operator

Pretty much the same as the postfix ++ but with -- instead
	Creates a new Date object called 'CopyDate', which is a copy of this Date object
	Uses the prefix -- operator on this Date object, to decrease it
	Returns the unchanged CopyDate Date object

*/
Date Date::operator--(int n)
{
    Date copyDate = Date(d, m, y);
    --*this;
    return copyDate;
}

/*
d1 < d2
	True if d1 before d2, otherwise false
		If d1's year is larger than d2, return false
		Else
			If d1's month is larger than d2, return false
			Else
				If d1's day is smaller than d2
					Return true
				Else
					Return false
*/
bool Date::operator<(const Date& other) const
{
    if (y > other.y)
    {
        return false;
    }
    else if (m > other.m)
    {
        return false;
    }
    else if (d < other.d)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/*
d1 == d2
	If d1 and d2's 'd', 'm', and 'y' values all match
		Return true
	False otherwise
*/
bool Date::operator==(const Date& other) const
{
    if (y == other.y && m == other.m && d == other.m)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/*
Returns a string of the form "2nd November 2019" from a Date object
	(return type implicit)

	initialises dateString to hold the value of d (as a string)

	If d is a number that can followed by "st"
		"st " is added to dateString.
	Else if d can be followed with "nd"
		"nd " is added to dateString
	Else if d can be followed by "rd"
		"rd " is added to dateString
	Else d is followed by "th"
		"th " is added to dateString

	Adds these things to dateString
		Name of the current month (from monthNames)
		A space
		The value y as a string

	And then returns dateString
*/
Date::operator string() const
{

    string dateString = to_string(d);
    if (d == 1 || d == 21 || d == 31)
    {
        dateString += "st ";
    }
    else if (d == 2 || d == 22)
    {
        dateString += "nd ";
    }
    else if (d == 3 || d == 23)
    {
        dateString += "rd ";
    }
    else
    {
        dateString += "th ";
    }

    dateString += monthNames[m - 1];
    dateString += ' ';
    dateString += to_string(y);

    return dateString;
}

/*
allows 'cout << dateObject' to work

output date in format dd/mm/yyyy, e.g. 02/11/2019

	Sets fill for blank width to '0' (zeroes)
	Sets width for output to 2 before the day (d.d) and month (m.d)
	Sets width for output to 1 before the slashes which seperate each number
	Width not increased before year (d.y) output
		y will always be a 4-digit number
		setw(x) does not affect anything with more than x characters/digits.
	*/
ostream& operator<<(ostream& o, const Date& d)
{
    o << setfill('0') << setw(2) << d.d << setw(1) << '/'
      << setw(2) << d.m << setw(1) << '/' << d.y;
    return o;
}

/*
d1 <= d2
	True if (d1<d2) or (d1 == d2)
	False otherwise
*/
bool operator<=(const Date& d1, const Date& d2)
{
    if (d1 < d2 || d1 == d2)
    {
        return true;
    }
    return false;
}

/*
d1 > d2
	Just does d2 < d1 (same result)
*/
bool operator>(const Date& d1, const Date& d2)
{
    return (d2 < d1);
}

/*
d1 != d2
	Just gets the inverse of (d1 == d2)
*/
bool operator!=(const Date& d1, const Date& d2)
{
    return !(d1==d2);
}

/*
d1 >= d2
	True if (d2<d1) or (d2 == d1)
	False otherwise
*/
bool operator>=(const Date& d1, const Date& d2)
{
    if (d2 < d1  ||d2 == d1)
    {
        return true;
    }
    return false;
}
