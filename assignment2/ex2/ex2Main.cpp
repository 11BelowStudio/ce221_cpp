//main class for Exercise 2

using namespace std;
#include "LowercaseOnlyFilter.h"
#include "TwoLettersWithNumberFilter.h"
#include "LetterWithPunctFilter.h"
#include <string>
#include <map>
#include <vector>
#include <iostream>


/*
Prints the words from 'filterMap' that have an occurrence count 'freq'

Parameters:
	'filterMap': a map for words and their occurrence counts
	'freq': the desired occurrence count (words with this occurrence count are output to the user)

Only the first 10 encountered are actually displayed, any others are output in the form ", and x more words".

*/
void printFrequency(map<string,int> &filterMap, int freq)
{

    //this will go through the passed map, outputting all words with the specified occurrence count 'freq'

    //I put this into its own function because otherwise I'd have to repeat this 3 times in the main function.

    map<string,int>::const_iterator const_iter = filterMap.begin();

    bool notFirst = false;
    int countTied = 0;

    while (const_iter != filterMap.end())
    {
        if (const_iter->second == freq)
        {
            countTied++;
            if (countTied <= 10)
            {
                //will only attempt to print the first 10 words
                if (notFirst)
                {
                    cout << ", "; //comma before the word if it's not the first to be output
                }
                cout << const_iter->first;
                notFirst = true;
            }
        }
        const_iter++;
    }
    if (countTied > 10)
    {
        countTied -= 10;
        cout << ", and " << countTied << " other words" << endl;
        //lets the user know about any other words that had that frequency
    }

    cout << endl << endl;

}


int main()
{

    map<string,int> filterMap; //will store the words and their occurrence counts


    string userInput; //will store user inputs


    //asks user what file they want to read
    cout << "Please enter the name of the file you want to read from:" << endl;

    getline(cin,userInput);


    //userInput = "1787.txt";
    //userInput = "moreTestWords.txt";

    cout << endl;

    //creates pointers to the derived filter classes, constructed with the name of the file entered by the user, storing them in a vector
    vector<ReadFilteredWords*> filterVector;

    ReadFilteredWords *f1 = new LowercaseOnlyFilter(userInput.c_str());
    ReadFilteredWords *f2 = new TwoLettersWithNumberFilter(userInput.c_str());
    ReadFilteredWords *f3 = new LetterWithPunctFilter(userInput.c_str());

    filterVector.push_back(f1);
    filterVector.push_back(f2);
    filterVector.push_back(f3);

    cout << "File opened successfully!" << endl; //user informed that the file has been opened


    int filterInt; //will refer to the index holding the filter the user wants to use


    //asks user what they want to do, repeating the question until they enter a valid choice
    bool keepLooping = true;

    int selectionInt;
    while (keepLooping)
    {
        cout << endl;
        cout << "What filter do you want to use for reading this the file?" << endl << endl
             << "a: Find words with least 1 lowercase letter, and no uppercase letters" << endl
             << "b: Find words with at least 1 digit, and at least 2 letters" << endl
             << "c: Find words with at least 1 letter, and at least 1 punctuation character" << endl << endl
             << "Please enter the letter for the filter you wish to use." << endl;

        getline(cin, userInput);

        /*
        if the user has entered a valid filter choice,
        	sets 'filterInt' to the index of the appropriate filter
        	sets 'keepLooping' to false
        		(will allow this loop to end)
        	closes the file reading stuff for the filter classes that were not chosen
        this loop repeats if the user entered something apart from a, b, or c
        	User prompted to enter a valid input next time
        */
        if(userInput == "a" || userInput == "b" || userInput == "c")
        {

            if(userInput == "a")
            {
                filterInt = 0; //1 lowercase no upper in filterVector[0]
            }
            else if (userInput == "b")
            {
                filterInt = 1; //1 digit 2 letters in filterVector[1]
            }
            else if (userInput == "c")
            {
                filterInt = 2; //1 letter 1 punctuation in filterVector[2]
            }
            keepLooping = false;

            for (int i = 0; i < 3; i++)
            {
                if (i != filterInt)
                {
                    filterVector.at(i)->close();
                }
            }
        }
        else
        {
            cout << "Please only enter either 'a', 'b', or 'c'!" << endl;
        }
    }

    string currentWord;
    keepLooping = true;

    int totalCount = 0;

    //Will now attempt to use the ReadFilteredWords pointer at the appropriate index of filterVector to fill the contents of 'filterMap'
    while (keepLooping)
    {
        currentWord = filterVector.at(filterInt)->getNextFilteredWord();
        if (currentWord == "")
        {
            keepLooping = false;
        }
        else
        {
            filterMap[currentWord]++;
            totalCount++;
        }
    }

    cout << endl << endl;

    //outputs details about what has been read to the user

    cout << "A total of "<< totalCount << " filtered words were read." << endl;
    cout << "There were "<< filterMap.size() << " unique words." << endl;


    if (totalCount == 0)
    {
        //can't output any more info when there's no data for it, y'know?
        cout << endl << "No further information can be displayed about the complete lack of recorded words, so this program will now terminate." << endl;
        return 0;
    }

    int maxCount = 0;
    int secondCount = 0;
    int thirdCount = 0;

    map<string,int>::const_iterator const_iter = filterMap.begin();

    //works out the top 3 occurrence counts, updating the other counts if a new larger one is added
    while (const_iter != filterMap.end())
    {
        if ((const_iter->second) > secondCount)
        {
            thirdCount = secondCount;
            if ((const_iter->second) > maxCount)
            {
                secondCount = maxCount;
                maxCount = (const_iter->second);
            }
            else
            {
                secondCount = (const_iter->second);
            }
        }
        else if ((const_iter->second) > thirdCount)
        {
            thirdCount = (const_iter->second);
        }
        const_iter++;
    }


    //will now output the words with the top 3 occurrence counts, using the printFrequency function I made

    cout << endl << endl;

    //prints most frequent first

    cout << "The most frequent word(s), occurring "<< maxCount << " time(s) were:" << endl;
    printFrequency(filterMap,maxCount);

    if (maxCount != secondCount && secondCount > 0)
    {

        //prints second most frequent if secondCount isn't tied with maxCount and is above 0 (if they're tied, all 3 will be tied)

        cout << "The second most frequent word(s), occurring "<< secondCount << " time(s) were:" << endl;
        printFrequency(filterMap,secondCount);

        if (secondCount != thirdCount && thirdCount > 0)
        {

            //will then print third most frequent if it isn't tied with secondCount (and above 0)

            cout << "The third most frequent word(s), occurring "<< thirdCount << " time(s) were:" << endl;
            printFrequency(filterMap,thirdCount);

        }
        else
        {
            cout << "No words with a lower occurrence count could be displayed." << endl;
        }
    }
    else
    {
        cout << "No words with a lower occurrence count could be displayed." << endl;
    }


    return 0;
}
