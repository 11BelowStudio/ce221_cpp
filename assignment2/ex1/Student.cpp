#include <string>
#include <map>
#include <stdexcept>
#include <iterator>
#include <iostream>
#include "Student.h"

using namespace std;

//ok so basically this is the Student class


//initialises name and registration number using arguments, marks map empty
Student::Student(const string &name, int regNo):
    Person(name),
    regNo(regNo)
{
    map<string, float> marks;
}

//returns the regNo of this student
int Student::getRegNo() const
{
    return this->regNo;
}

//adds the mark to the map, automatically overwrites existing mark for that module
void Student::addMark(const string& module, float mark)
{
    marks.insert(make_pair(module, mark));
}


//attempts to return a mark for a specified module
float Student::getMark(const string &module) const throw(NoMarkException)
{
    map<string, float>::const_iterator iter = marks.find(module);
    if (iter != marks.end())
    {
        return iter->second;
        //returns the mark for the specified module if it exists
    }
    else
    {
        throw NoMarkException();
        //throws a NoMarkException if there is no mark present for the specified module
    }
}

bool Student::noMarks() const
{
    return (marks.empty());
    //returns true if 'marks' map is empty
}

float Student::getMin() const
{
    map<string, float>::const_iterator iter = marks.begin(); //'iter' starts at start of marks
    float min = iter->second; //'min' initialised to 1st mark from marks
    while (iter != marks.end())  //until iter reaches the end of marks
    {
        if (min > iter->second)
        {
            min = iter->second;
            //min set to current mark from marks if current mark is smaller than min
        }
        iter++; //next value checked
    }
    return min; //min returned
}

float Student::getMax() const
{
    map<string, float>::const_iterator iter = marks.begin(); //'iter' starts at start of marks
    float max = iter->second; //'max' initialised to 1st mark from marks
    while (iter != marks.end())  //until iter reaches the end of marks
    {
        if (max < iter->second)
        {
            max = iter->second;
            //max set to current mark from marks if current mark is bigger than max
        }
        iter++; //next value checked
    }
    return max; //max returned
}

float Student::getAvg() const
{
    map<string, float>::const_iterator iter = marks.begin(); //'iter' starts at start of marks
    float total = 0; //running total of marks

    while (iter != marks.end())
    {
        total += iter->second;
        iter++;
        //each mark from marks added to total
    }

    return (total / marks.size());
    //total divided by size of marks is returned
}

void Student::outputMarkDetails() const
{
    map<string, float>::const_iterator iter = marks.begin(); //'iter' starts at start of marks
    string theDetails;

    cout << this->name << ':' << endl;

    if (marks.empty())
    {
        cout << "No marks to show!" << endl;
    }
    else
    {
        while (iter != marks.end())
        {
            cout << iter->first << ": " << iter->second << endl;
            iter++;
        }
    }

}

bool Student::operator<(Student& s) const
{
    return regNo < s.getRegNo();
    //comparison between regNo attributes
}


// friend function to output details of student to stream
ostream& operator<<(ostream &str, const Student &s)
{

    str << s.getName() << ' ' << s.getRegNo() << ' ';
    //adds name and regNo to the stream

    if (s.noMarks())
    {
        str << "has no marks";
        //adds 'has no marks' instead of marks if the student has no marks

    }
    else
    {
        str << s.getMin() << ' ' << s.getMax() << ' ' << s.getAvg();
        //adds minimum, maximum, and average marks if the student has marks
    }

    return str;
    //returns the stream with the stuff added to it
}
