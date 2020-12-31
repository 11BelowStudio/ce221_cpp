#include <iostream>

using namespace std;

#include "Complex.h"

Complex::Complex(double r, double i) : real(r), imaginary(i) {}

Complex Complex::operator+(const Complex &op2) const
{
    return Complex(real + op2.real, imaginary + op2.imaginary);
}

Complex Complex::operator-(const Complex &op2) const
{
    return Complex(real - op2.real, imaginary - op2.imaginary);
}

/*
// display a complex in the form (r, i)
void Complex::print() const
{ cout << '(' << real << ", " << imaginary << ')';
}
*/

//display a complex in the form 'real + imaginary i'
ostream& operator<<(ostream& o, const Complex & c)
{
    o << c.real << '+' << c.imaginary << 'i';
    return o;
}

Complex Complex::operator*(const Complex &op2) const
{
    //a+bi * c+di = (a*c - b*d) + (a*d + b*c)i
    return Complex(
               ((real * op2.real) - (imaginary * op2.imaginary)), //works out the real value
               //r = ((a*c) - (b*d))
               ((real * op2.imaginary) + (imaginary * op2.real)) //works out the i value
               //i = ((a*d) - (b*c))
           );
}

bool Complex::operator==(const Complex &op2) const
{
    if (real == op2.real && imaginary == op2.imaginary)
    {
        //return true if both real and imaginary values match
        return true;
    }
    else
    {
        //false if mismatch
        return false;
    }
}

bool Complex::operator!=(const Complex &op2) const
{
    if (real == op2.real && imaginary == op2.imaginary)
    {
        //return false if both real and imaginary values match
        return false;
    }
    else
    {
        //return true if mismatch
        return true;
    }
}
