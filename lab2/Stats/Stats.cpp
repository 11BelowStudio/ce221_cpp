
using namespace std; //allows the standard namespace stuff

#include "Stats.h"
#include <iostream>//allows inputs/outputs


double Stats::average(const int a[], int count)
{
    //this function should obtain the average of all items
    int total = 0; //defines the integer 'total' as 0
    int counter = 0; //defines integer 'counter' as 0
    int temp; //sets up the integer 'temp'
    double average; //sets up the double 'average'

    while (counter < count)  //while counter is below number of items in passed array
    {
        temp = a[counter++]; //item at current index of array 'a' sent to temp
        total += temp; //total incremented by temp
    }
    average = (double)total/(double)count; //obtains total by dividing total by count
    return average;
}

int Stats::largest(const int a[], int count)
{
    int largest = a[0]; //obtains the item at the start of array 'a'
    //this is initial largest
    int counter = 1; //sets up a counter variable as 1.
    //no need to start it at 0, as the item in index 0 of the array is
    //default value of 'largest', so it would just be checking it against itself.
    int temp;
    while (counter < count)
    {
        temp = a[counter++]; //temp stores current item of a[]
        if (temp > largest)  //if temp is greated than 'largest'
        {
            largest = temp; //it overwrites the value of 'largest'
        }
    }
    return largest; //final value of 'largest' is returned.
}

int Stats::sum(const int a[], int count)
{
    //this function should obtain the sum of all items
    int total = 0; //defines the integer 'total' as 0
    int counter = 0; //defines integer 'counter' as 0
    int temp; //sets up the integer 'temp'

    while (counter < count)  //while counter is below number of items in passed array
    {
        temp = a[counter++]; //item at current index of array 'a' sent to temp
        total += temp; //total incremented by temp
    }
    return total; //returns total to the user
}
