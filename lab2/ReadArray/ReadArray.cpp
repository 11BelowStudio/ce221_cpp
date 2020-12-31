
using namespace std; //'std' namespace being used

#include "ReadArray.h" //includes the ReadArray.h header file
#include <fstream>
#include <iostream> //allows system outputs
#include <cstdlib> //allows the program to close


ReadArray::ReadArray(const char* filename)
{
    f.open(filename);
    //initialises 'f' to be the file stored as 'filename'
    if (!f)  //if the file cannot be opened
    {
        cout << "Error! Could not open " << filename << endl; //user informed
        exit(1); //program closes
    }
    cout << "Could open " << filename << endl;
    int count; //initialises count
    //inputArray();
}

void ReadArray::inputArray()
{
    int n; //temporary value to store the items in the array
    bool reading = true;
    count = 0; //counter (initialised in header)
    while (reading == true)
    {
        f >> n; //stores item from file as n

        if (!f.eof()) //if the end of file has not been reached
        {
            array[count++] = n;//stores the current n value in the next index of array
            //count++ incremements every iteration
        }
        else
        {
            reading = false;
            f.close();
        }
    }
    cout << "done" << endl;

    /*

    //loop through the array for debugging reasons
    int newCount = 0; //new version of counter (as counter is already the max of array)
    while (newCount < count){
    	n = array[newCount++];
    	cout << n << endl;
    }
    */
}
