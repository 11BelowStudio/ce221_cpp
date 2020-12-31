//main for the ReadArray stuff

#include "ReadArray.h"

int main()
{
    ReadArray reader("Data.dat");
    //creates a new instance of ReadArray, called 'reader'
    //initialised with the filename 'Data.dat'.
    reader.inputArray();
    //calls the inputArray function of the reader object
    return 0;
    //closes the program
}
