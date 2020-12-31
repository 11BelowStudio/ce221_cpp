//main for the final program, edited from the main ReadArray class

#include "ReadArray.h"
#include "WriteNumber.h"
#include "Stats.h"

int main()
{
    ReadArray r("Data.dat");
    //creates a new instance of ReadArray, called 'r'
    //initialised with the filename 'Data.dat'.
    r.inputArray();
    //calls the inputArray function of the ReadArray object


    WriteNumber w("outputs.dat");
    //creates an instance of WriteNumber, called 'w'
    //will output to a new file called 'outputs.dat'

    w.writeString("The sum is ");
    //tells 'w' to write this message to the file
    w.writeInt(Stats::sum(r.array, r.count));
    //'w' will output the sum of the items from the read array to the file
    //uses the Stats::sum function to obtain the sum

    w.writeString("The average is ");
    //tells 'w' to write this message to the file
    w.writeDouble(Stats::average(r.array, r.count));
    //ouputs the average of the items from the read array to the file
    //uses Stats::average to obtain the average

    w.writeString("The largest number is ");
    //tells 'w' to write this message to the file
    w.writeInt(Stats::largest(r.array, r.count));
    //'w' will output the largest item from the read array to the file
    //uses the Stats::largest function to obtain the sum

    w.close();
    //calls 'w' to close the file which it has open
    return 0;
    //closes the program
}
