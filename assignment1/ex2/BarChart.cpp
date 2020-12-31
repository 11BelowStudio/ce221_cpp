/* class body for BarChart class*/

using namespace std;

#include "BarChart.h"
#include <cstdlib>
#include <string>
#include <map>
#include <iostream>
#include <iomanip>

/*
Constructor for BarChart
	Opens the file containing the words to find
		associates it to input filestream (in)
	Opens the file which the output should be made to
		associates it to output filestream (out)
Parameters
	infile
		c-string containing the name of the file containing the words to find
			Will open this file if it exists
	ofile
		c-string containing the name of the file to output to
			Will open this file if it exists, or will create it if it doesn't exist

Closes program if either of the files cannot be opened/output file cannot be created
	Will output error message
*/
BarChart::BarChart(const char *infile, const char *ofile)
{
    in.open(infile);
    if (!in)
    {
        cout << "Error opening " << infile << endl;
        exit(1);
    }
    cout << infile << " opened successfully!" << endl;
    out.open(ofile);
    if (!out)
    {
        cout << "Error opening/creating " << ofile << endl;
        exit(1);
    }
    cout << ofile << " opened successfully!" << endl;
}


/*
Sets up the map which will contain the items being looked for

Initialises two member values
	highestCount set to 0
		will be the highest count of string instances encountered in the map
			(used to make the scaling factor for the bar chart easier to work out)
	longest set to 0
		will be the length of the longest string for the map values
			(easier bar chart formatting stuff)

Creates a few temporary variables
	temp
		String to store the current item from the input stream
	reading
		True whilst the end of file has not been reached

While reading == true
	Gets the next item from the 'in' input stream, stores it as 'temp'
	If the end of file for 'in' has not been reached
		Element in 'wordCounts' map created for the item 'temp' (key = temp)
			Value associated with it is set to 0
			If the length of 'temp' is higher than 'longest'
				'longest' updated to be the length of 'temp'
	Else
		Reading set to 'false'
		input stream is closed


*/
void BarChart::makeMap()
{
    highestCount = 0;
    longest = 0;
    string temp;
    bool reading = true;
    while (reading == true)
    {
        in >> temp;
        if (!in.eof())
        {
            wordCounts[temp] = 0;
            if (temp.size() > longest)
            {
                longest = temp.size();
            }
        }
        else
        {
            reading = false;
            closeIn();
        }
    }
}


/* updateCounts(string addWord)

Attempts to update the wordCounts map, depending on the addWord string passed

If addWord isn't an empty string
	It will attempt to use the 'iter' iterator object to find the entry of wordCounts with the 'addWord' string as the key
		'iter' iterates through 'wordCounts' until either finding the entry with key 'addWord' or reaching the very end of 'wordCounts'

	If 'iter' isn't at the very end of 'wordCounts' (because it stopped at 'addWord')
		Increments the value of the key-value pair it stopped at (increasing instance count of the word by 1)
		(Obtained via 'iter->second')

		If the value of the key-value pair is now larger than the 'highestCount' integer
			'highestCount' is updated to be the same as the current value of the key-value pair held in iter
*/
void BarChart::updateCounts(string addWord)
{
    if (!addWord.empty())
    {
        iter = wordCounts.find(addWord);
        if (iter != wordCounts.end())
        {
            iter->second++;
            if (iter->second > highestCount)
            {
                highestCount = iter->second;
            }
        }
    }
}



/* printResults()

uses 'wordCounts' map to construct a bar chart, which is output to the user-defined output file and to the console

note: all outputs in this function are sent to the console (via cout <<) and to the output file (via out <<)

sets up local variables
* double scalingFactor
	used to store the scaling factor which will be used for this bar chart
* int barLength
	Used to store the lengths of each bar in the bar chart
* int currentCount
	Used to store the value for the current key/value pair from getWords,
		to simplify process of getting it from the iterator every time it is used
* string bar
	Will be used to store the sequence of asterisks which make up the 'bar' for the word in the bar chart this will produce


Checks to see if highestCount is greater than 0
	Divides highestCount by 20 to obtain scalingFactor value
		(treates highestCount as a double for this to ensure scalingFactor is not an integer)
	Will output a message saying what scaling factor is being used
		Both to console (cout <<) and to the output stream (out <<)


Sets up the 'iter' iterator to begin at the start of wordCounts (so it can iterate through all of it)

(For the following loop, everything being output in a single iteration will all be on the same line
	in the console and in the output file)

Whilst 'iter' is not at the very end of the 'wordCounts' map:
	'currentCount' obtained from the iterator (iter->second)

	If at least one instance of a word was found (currentCount > 0)
		Will output the appropriate number of asterisks for the count of an item found

		'barLength' set to the result of dividing 'currentCount' by 'scalingFactor'

		if 'barLength' needs to be rounded up
			* found by seeing if there is any difference between 'barLength' and the result of dividing float 'currentCount' by 'scalingFactor'
			'barLength' will be incremented by 1 (rounded up)

		A sequence of asterisks of length 'barlength' will be appended to the empty 'bar' string
			so 'bar' is a bar with the appropriate length for the word it is associated with


	The 'key' string from the pair that 'iter' is at is output.
			* Width for the output set to 'longest' (length of the longest key string)
			* Output left-aligned
			* the string is gained from the iterator (iter->first)
		* two additional spaces will follow this formatted string
	the 'bar' string, two more spaces, the actual value of 'currentCount',
		and an 'endl' are also added to the outputs

	'iter' incremented (so it goes to the next <key,value> pair in 'wordCounts')

	'bar' is cleared

*/
void BarChart::printResults()
{

    double scalingFactor;
    int barLength;
    int currentCount;
    string bar;

    if (highestCount > 0)
    {
        scalingFactor = (double)highestCount/20;
        cout << "Scaling factor used: " << scalingFactor << endl;
        out << "Scaling factor used: " << scalingFactor << endl;
    }

    iter = wordCounts.begin();

    while(iter != wordCounts.end())  //while iter is not at the end of wordCounts
    {

        currentCount = iter->second;

        if (currentCount > 0)
        {
            barLength = currentCount / scalingFactor;

            if ((float)currentCount - (barLength * scalingFactor) != 0)
            {
                barLength++;
            }

            bar.append(barLength,'*');

        }
        //outputs the current line of the bar chart to the console, then to the output stream
        cout << setw(longest) << left << iter->first << "  "
             << bar << "  " << currentCount << endl;
        out << setw(longest) << left << iter->first << "  "
            << bar << "  " << currentCount << endl;


        iter++;
        bar.clear();
    }
}


//closes the input file
void BarChart:: closeIn()
{
    in.close();
}

//closes the output file
void BarChart:: closeOut()
{
    out.close();
}
