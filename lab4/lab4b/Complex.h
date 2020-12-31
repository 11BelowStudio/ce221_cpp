using namespace std;

#include <iostream>

#ifndef _COMPLEX_H_
#define _COMPLEX_H_


class Complex
{
public:
    Complex(double = 0.0, double = 0.0);
    Complex operator+(const Complex &) const;
    Complex operator-(const Complex &) const;
    //void print() const;
    Complex operator*(const Complex &) const;
    bool operator==(const Complex &) const;
    bool operator!=(const Complex &) const;
private:
    double real;
    double imaginary;

    friend ostream& operator<<(ostream& o, const Complex & c);
};
#endif

