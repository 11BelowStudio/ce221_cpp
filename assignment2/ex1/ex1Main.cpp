//actual main function for the Student class

using namespace std;
#include <iostream>
#include <stdexcept>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include "Student.h"


void findMaxBenchmark(vector<Student> &sVec, float checkMax)
{

    sort(sVec.begin(),sVec.end()); //sorting sVec by reg number

    bool foundStudent = false;

    for (Student &s: sVec)
    {
        if (s.getMax() >= checkMax)
        {
            foundStudent = true;
            cout << s << endl;
            //details of students with max mark above checkMax output
        }
    }
    if (!foundStudent)
    {
        cout << "No students with a max mark equal to or above " << checkMax << '!' << endl;
        //message output if students could not be found
    }

}


void findModuleMarksBelowBenchmark(vector<Student> &sVec, string module, float checkMin)
{

    bool foundStudent = false;

    float temp;

    for (Student &s: sVec)
    {
        try
        {
            temp = s.getMark(module);
            if (temp <= checkMin)
            {
                foundStudent = true;
                cout << s.getName() << ": " << temp << endl;
                //outputs name and score for student if their mark for that module is equal/less than checkMin
            }
        }
        catch(NoMarkException e)    //nothing special happens if module not found
        {
        }
    }
    if (!foundStudent)
    {
        cout << "No students with a mark for " << module
             << " less than or equal to " << checkMin << '!' << endl;
        //message output if students could not be found
    }

}



int main()
{

    vector<Student> studentVector;

    string inputFileName;
    ifstream inputFile;

    cout << "Please enter the name of the file containing student info: " << endl;

    getline(cin, inputFileName); //user can input the student info file

    inputFile.open(inputFileName.c_str());

    if (!inputFile)
    {
        //terminates with error message if inputFile could not be opened
        cout << "Could not open " << inputFileName << "!";
        exit(1);
    }

    string regNoString;
    int regNo;
    string studentName;


    //now attempts to put all students in inputFile into the vector
    while (!inputFile.eof())
    {
        getline(inputFile, regNoString, ' ');
        //everything until 1st space of line: reg number

        if (regNoString == "")
        {
            break;
            //stops if regNoString is empty (end of file definitely reached)
        }

        regNo = stoi(regNoString);
        //converts regNoString to the regNo int

        getline(inputFile, studentName);
        //everything after 1st space: student name


        studentName.resize(studentName.length() - 1);
        //removes the newline which will be at the end of studentName from the end of studentName

        Student s(studentName, regNo);
        studentVector.push_back(s);
        //creates a new Student object using this data, adds it to studentVector


    }
    inputFile.close(); //closes the input file once finished

    cout << endl << "Student file read successfully!" << endl << endl;

    cout << "Please enter the name of the file containing module info: " << endl;

    //now attempts to read the module info, re-using the file variables.

    getline(cin, inputFileName); //user can input the module file

    cout << endl;

    inputFile.open(inputFileName.c_str());

    if (!inputFile)
    {
        //terminates with error message if inputFile could not be opened
        cout << "Could not open " << inputFileName << "!";
        exit(1);
    }

    //no need to re-declare 'regNo' and 'regNoString'
    string moduleCode;
    string markString;
    float mark;

    while (!inputFile.eof())
    {

        getline(inputFile, moduleCode, ' ');
        //everything until 1st space of line: module code
        getline(inputFile, regNoString, ' ');
        //everything until 2nd space of line: reg number
        getline(inputFile, markString, '\n');
        //everything after 2nd space: the mark


        if (moduleCode == "")
        {
            break;
            //stops if moduleCode is empty (end of file definitely reached)
        }

        regNo = stoi(regNoString);
        //regNoString converted to int

        markString.resize(markString.length() - 1);
        mark = stof(markString);
        //removes the newline from the end of markString before converting it to float




        for (Student &s: studentVector)
        {
            if (s.getRegNo() == regNo)
            {
                s.addMark(moduleCode, mark);
                break;
            }
        }


    }
    inputFile.close(); //closes the input file once finished

    cout << "Module file read successfully!" << endl << endl;


    //outputs the details about the marks for every student
    for (Student &s: studentVector)
    {
        s.outputMarkDetails();
        cout << endl;
    }

    bool closeProgram = false;

    string option;
    float temp;

    while (!closeProgram)
    {
        cout << endl << endl
             <<"Select what operation you want to perform: " << endl << endl
             << "1: Find students with a max mark equal to or above a specified mark" << endl
             << "2: Find students with a module mark less than or equal to a specified mark" << endl
             << "3: Close program" << endl << endl
             << "Please enter the number for the operation you want to perform." << endl;

        getline(cin, option);

        cout << endl;

        if (option == "1")
        {
            cout << "Enter the mark you want to search for:" << endl;
            getline(cin, option);
            cout << endl;
            try
            {
                temp = stof(option);
                findMaxBenchmark(studentVector, temp);
            }
            catch (exception e)
            {
                cout << "An error occurred!" <<endl;
            }
        }
        else if (option == "2")
        {
            cout << "Enter the mark you want to search for:" << endl;
            getline(cin, option);
            try
            {
                temp = stof(option);
                cout << endl << "Enter the module code:" << endl;
                getline(cin, option);
                cout << endl;
                findModuleMarksBelowBenchmark(studentVector,option,temp);
            }
            catch (exception e)
            {
                cout << "An error occurred!" <<endl;
            }
        }
        else if (option == "3")
        {
            cout << "Terminating the program now!" << endl;
            closeProgram = true;
        }
    }


    return 0;
}
