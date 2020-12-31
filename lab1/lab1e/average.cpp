
using namespace std;
#include <iostream>

void average(int nums[], int length)
{
    int sum = 0; //sum starts at 0
    for (int i = 0; i < length; i++)
        //for each value of i before it reaches the value of index
    {
        sum += nums[i]; //increase the value of sum by the current item in nums
    }
    float average = (sum/length);
    cout << "The average value which has been input was " << average << endl;
}


int main()
{
    int length;
    cout << "How many integers do you wish to enter?" << endl;
    cin >> length;
    //uses keyboard input to define the size of 'length'
    int nums[length];
    if (length > 0)
    {
        cout << "Please start entering the integers:" <<endl;
        for (int i = 0; i < length; i++)
        {
            cin >> nums[i];
            //uses keyboard input to change current index of 'numbers'
        }
        average(nums, length); //calls 'average'
    }
}
