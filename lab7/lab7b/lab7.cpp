
#include <string>
#include <cctype>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <vector>
#include <set>
#include <cctype>
#include <cstdlib>
#include <map>

using namespace std;

map<string, int> stringMap;

map<string,int>::iterator iter;



string reader(ifstream& read)
{

    string word;
    read >> word;

    if (!word.empty())
    {

        bool foundFirst = false;
        bool foundLetter = false;
        int wordStart;
        int wordEnd;
        int i = 0;

        while (i < word.size())
        {
            if (!ispunct(word[i]))
            {
                if (isalpha(word[i]))
                {
                    word.replace(i,1,1,tolower(word[i]));
                    if (!foundLetter)
                    {
                        foundLetter = true;
                    }
                }
                i++;
            }
            else
            {
                word.erase(i);
                //i not incremented if it is erased
                //prevents any letters from being skipped over after erasing tehm
            }
        }
    }
    return word;
}

/*
void addToSet(set<string> theSet, string addThis){
	theSet.insert(addThis);
}
*/


void outputResults(vector<set<string> > dataVector)
{

    char currentChar = 'a';

    for (set<string> &s: dataVector)
    {
        if (s.size() > 0)
        {
            cout << "There were " << s.size() << " words beginning with "
                 << currentChar << endl;
        }
        currentChar += 1;
    }
}

void iteratorLetterOutput(set<string> theSet, char theLetter)
{
    cout << "The words beginning with " << theLetter << " are: ";

    set<string>::const_iterator it;

    it = theSet.begin();

    while (it != theSet.end())
    {
        cout << *it;
        it++;
        if (it != theSet.end())
        {
            cout << ", ";
        }
        else
        {
            cout << '.';
        }
    }
    cout << endl;

}

void rangeBasedForLetterOutput(set<string> theSet, char theLetter)
{

    cout << "The words beginning with " << theLetter << " are: ";
    for (string s: theSet)
    {
        cout << s << ", ";
    }
    cout << endl;
}

int letterToInt(char letter)
{
    return (int)(letter - 97);
}

void updateMap(string addWord)
{
    if (!addWord.empty())
    {
        iter = stringMap.find(addWord);

        if (iter != stringMap.end())  //if the word has been found
        {
            iter->second++; //count for it increased by 1
        }
        else
        {
            stringMap[addWord] = 1;
            //creates entry for the word if it didn't already exist
        }
    }
}

void outputMap()
{

    iter = stringMap.begin();

    while (iter != stringMap.end())
    {
        cout << iter->first << ": " << iter->second << endl;
        iter++;
    }
}


int main()
{

    ifstream read;

    vector<set<string> > setVector(26);

    //map<string, int> stringMap;

    //theVector.push

    string fileToRead;

    /*
    cout << "What file do you want to read from?" << endl;
    getline(cin, fileToRead);
    */

    fileToRead = "unixcommands.txt";

    read.open(fileToRead);
    if (!read)
    {
        cout << "Couldn't open the file!";
        exit(1);
    }

    string theString;
    char firstChar;
    int firstCharInt;

    while (!read.eof())
    {
        theString = reader(read);



        firstChar = theString[0];
        firstCharInt = letterToInt(firstChar);

        //cout << "test A" << endl;

        if (firstCharInt >= 0)
        {
            //cout << "test B" << firstCharInt << endl;

            setVector[firstCharInt].insert(theString);
            updateMap(theString);

            //cout << "test C" << endl;
        }

    }

    outputResults(setVector);

    string inputString;

    inputString = "b";

    /*
    cout << "What letter do you want to see the contents of?" << endl;
    getline(cin, inputString);
    */
    char letterToFind = inputString[0];
    int setToFind = letterToInt(letterToFind);

    cout << endl << endl;

    iteratorLetterOutput(setVector[setToFind], letterToFind);

    rangeBasedForLetterOutput(setVector[setToFind], letterToFind);

    outputMap();


    return 0;
}
