/**
 *  Lab3b precision
 */

/**
 * This small program will be used to look at fields and precision I/O
 */
using namespace std;

#include <iostream>
#include <string>
#include <iomanip>

int main()
{
    double d = 39.9001;
    int num10 = 1234567890;
    unsigned long num20 = 12345678901234567890U;
    cout << d << endl; //outputs d as-is

    cout.width(10); //makes the next input right-aligned, at the 10th character
    cout << "ok" << endl; //'k' at space 10, 'o' at space 9
    cout.width(10);
    cout << d << endl; //ditto but for d instead
    cout.width(10);
    cout << num10 << endl; //demonstration with a 10 digit long number

    cout << endl;

    cout.width(10);
    cout << '<' << setw(20) << d<<'>' << d << 'x' << endl;
    /*
    Output:
    	         <             39.9001>39.9001x
    Notes:
    	The first '<' starts at the 10th character
    	The area within the '<' and '>' is 20 characters long
    		Defined by 'setw(20)'
    	d at the end is followed with an 'x'
    */
    cout.width(10);
    cout << '<' << setw(20) << num20 <<'>' << d << 'x' << endl;
    //demonstrates it a bit better with a 20-digit number

    cout << endl;

    cout << '<' << setw(20) << left << d << '>'<< d << 'x' << endl;
    /*
    Output:
    	<39.9001             >39.9001x
    Notes:
    	The area within the '<' and '>' is 20 characters long
    	The '<< left <<' declares that it is left-aligned
    	d at the end is followed with an 'x'
    */
    cout << '<' << setw(20) << left << num20 << '>'<< d << 'x' << endl;
    //demonstration using 20 digit long character
    cout << endl;

    cout.fill('*'); //sets the fill for empty spaces to use '*' instead
    cout << '<' << setw(20) << left << d << '>' << endl;
    /*
    Output:
    	<39.9001*************>
    Notes:
    	the 'cout.fill('*')' line declares that empty spaces will contain asterixes
    	Same as previous except with the empty spaces filled with asterixes and
    		with nothing following it at the end
    */

    cout << endl;

    cout << '<' << setw(20) << scientific << d << '>' << endl;
    /*
    Output:
    	<3.990010e+01********>
    Notes:
    	Same as above, but using scientific notation
    		* declared with 'scientific'
    		* One digit before decimal point
    		* Decimal point
    		* As many decimal digits as needed
    			* May be defined with 'cout.precision(int);'
    		* Exponential part
    			* e
    			* optional sign
    			* up to 3 digits for exponent
    */
    cout << endl;

    cout << '<' << setw(20) << setprecision(3) << setfill('h') << d << "><" << setw(20) << d << '>' << endl;
    /*
    Output:
    	<3.990e+01hhhhhhhhhhh><3.990e+01hhhhhhhhhhh>
    Notes:
    	* 'scientific' from previous output appeaars to persist here as well
    	* 'setw(20)' makes the following output 20 characters long
    	* 'setprecision(3)' makes the output have 3 decimal points of precision
    		* Persists throughout this 'cout' stream
    	* 'setfill('h')' makes the unfilled characters 'h' instead
    	* Followed by the same output
    		* Following output does not need a new 'setprecision' or 'setfill', persists
    */

    return 0;
}
