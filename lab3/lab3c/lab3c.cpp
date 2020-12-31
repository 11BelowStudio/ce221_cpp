/*
lab3c

outputs amounts of money for use in an accounting program

takes integer argument representing number of pence, outputs value in pounds
*/

using namespace std;

#include <iostream>
#include <string>
#include <iomanip>


void poundFormat (const int constPence)
{
    //string pound; //initialises empty 'pound' string
    int pounds = constPence/100; //divides constPence by 100
    int pence = constPence%100; //pence is modulus of constPence/100
    bool isNegative = false;
    if (pounds < 0)
    {
        //pound += '-'; //appends minus to start of pound if pence is negative
        pounds = pounds * (-1); //pounds made positive
        isNegative = true;
    }
    if (pence < 0)  //if pence is negative
    {
        pence = pence * (-1); //pence made positive
        isNegative = true;
    }
    if (isNegative)
    {
        cout.put('-'); //puts a minus at the start of the output if it's been marked as negative
    }
    //pound += '£';
    //cout.put('£');
    //cout.precision(2);
    //cout.write(pounds);
    //cout.put('\n');
    cout << "\x9C" << pounds << '.' << setw(2) << setfill('0') << pence << endl;
    //\x9c is the pound sign
    return;
}

main()
{

    poundFormat(1002);

    poundFormat(-1000);

    poundFormat(24);

    poundFormat(-5);

    return 0;
}
