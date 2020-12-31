#include <iostream>
using namespace std;
#include "Complex.h"

template <class T> T sum(const T arr[], int size)
{
    T total = arr[0]; //'total' (type T) set to value in arr[0] (first element)
    int i = 1; //int initialised to 1 (as arr[0] already added to total)
    while (i < size)  //while i is smaller than size
    {
        total = total + arr[i]; //adds element at index i to total
        i++; //increments i
    }
    return total; //returns total
}

template <class T> T product(const T arr[], int size)
{
    T total = arr[0]; //'total' (type T) set to value in arr[0] (first element)
    int i = 1; //int initialised to 1 (as arr[0] already added to total)
    while (i < size)  //while i is smaller than size
    {
        total = total * arr[i]; //multiplies total by element at index i
        i++; //increments i
    }
    return total; //returns total
}

int main()
{
    int intArray[] = {1, 42, 52, 64, 37};
    cout << to_string(sum(intArray,5)) << endl;
    cout << to_string(product(intArray,5)) << endl << endl;

    string stringArray[] = {"Ok","So","Basically","I'm","Confusion"};
    cout << sum(stringArray,5) << endl << endl;
    //cout << product(stringArray,5) << endl << endl;
    //strings cannot be multiplied themselves, so this line results in a compile error


    Complex x(2.9,1.7), y(4.3, 8.2), z(3.3, 1.1);
    Complex compArray[] = {x, y, z};
    cout << sum(compArray,3) << endl;
    cout << product(compArray,3) << endl << endl;
    return 0;
}
