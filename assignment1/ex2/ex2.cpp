//main class for assignment 1 part 2

using namespace std;

#include "ReadWords.h"
#include "BarChart.h"
#include <iostream>

int main()
{

    string wordFile;
    cout << "Please enter the name of the file you want to search through: "<< endl;
    getline(cin, wordFile); //wordFile is the name of the file to be read
    ReadWords reader(wordFile.c_str());
    //passes the c-string version of wordFile to the ReadWords constructor

    string findFile;
    cout << "Please enter the name of the file containing the words you want to search for: " << endl;
    getline(cin, findFile);
    //findFile is the name of the file containing the words to be searched for

    string outFile;
    cout << "Please enter the name of the file you want to output data to: "<< endl;
    getline(cin, outFile);
    //outFile is the name of the file which the data is supposed to be output to



    BarChart outputs(findFile.c_str(), outFile.c_str());
    //passes the c-string versions of findFile and outFile to the ReadWords constructor

    //constructs the map containing the data for the 'outputs' BarChart object (which also closes the findFile input stream)
    outputs.makeMap();


    cout << endl << endl; //space between the last user input and the barchart

    /*
    While the reader has not reached the end of the file (checked via 'reader.isNextWord()')
    	It will get the next word from the file which is being searched through
    	And will use this to try updating the map holding the counts of how frequently each word has been found
    */

    while (reader.isNextWord())
    {
        outputs.updateCounts(reader.getNextWord());
    }

    //closes the reader input
    reader.close();

    //will output the results
    outputs.printResults();

    //closes the output stream
    outputs.closeOut();
}
