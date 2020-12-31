#include <iostream>

using namespace std;

#include "Complex.h"

int main()
{
    Complex x, y(4.3, 8.2), z(3.3, 1.1);

    /*
    cout << "x: ";
    x.print();
    cout << endl << "y: ";
    y.print();
    cout << endl << "z: ";
    z.print();
    */

    cout << "x :" << x << endl;
    cout << "y: " << y << endl;
    cout << "z: " << z << endl;

    x = y+z;

    /*
    cout << endl << endl << "x = y+z: ";
    x.print();
    cout << " = ";
    y.print();
    cout << " + ";
    z.print();
    */

    cout << endl;
    cout << "x = y+z: " << x << " = " << y << " + " << z << endl;

    x = y-z;

    /*
    cout << endl << endl << "x = y-z: ";
    x.print();
    cout << " = ";
    y.print();
    cout << " - ";
    z.print();
    cout << endl;
    */

    cout <<endl;
    cout << "x = y-z: " << x << " = " << y << " - " << z << endl;

    x = y*z;
    cout <<endl;
    cout << "x = y*z: " << x << " = " << y << " - " << z << endl;

    cout <<endl;

    cout << "y == z: " << boolalpha << (y == z) << endl;

    cout << "y != z: " << (y!=z) << endl;

    return 0;

}

