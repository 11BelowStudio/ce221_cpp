/*
header for BarChart.cpp

BarChart.cpp will be used to create and output the bar chart to the output file and console
*/

#ifndef BARCHART_H
#define BARCHART_H

using namespace std;
#include <iostream>
#include <fstream>
#include <string>
#include <map>

class BarChart
{

private:
    ifstream in;
    //input filestream called 'find'
    ofstream out;
    //output filestream called 'out'

    map<string,int> wordCounts;
    /*a map associating strings to integers, called 'wordCounts'
    Structure:
    	<word from the file containing words to search for, count of times it is encountered in the reader file>
    */
    map<string,int>::iterator iter;
    //iterator object for a map with the same structure as wordCounts, used for iterating through wordCounts

    int highestCount;
    //will store the highest int value of the items in wordCounts, for use with the scaling factor stuff

    int longest;
    //will store the size of the longest key value string from wordCounts, for use with aligning the bar chart

public:

    /*	Constructor
    		Initialises input stream
    			Opens input file, associating it with 'find' input stream
    		Initialises output stream
    			Opens output file, associating it with 'out' output stream
    			Creates output file if it doesn't exist
    	Parameters
    		infile
    			c-string containing name of file to get inputs from
    				File containing words to be found
    		ofile
    			c-string containing name of file to output to
    	Will exit with an error message if either file cannot be opened/read to
    */
    BarChart(const char *infile, const char *ofile);

    void makeMap();
    //sets up the map to contain the words from the input file

    void updateCounts(string addWord);
    //increases the count of an item in the map if the addWord string matches a key in the wordCounts map

    void printResults();
    //outputs the bar chart

    void closeIn();
    //used to close the input file

    void closeOut();
    //used to close the output file
};

#endif
