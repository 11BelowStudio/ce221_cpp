
#include "Student.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;


Student::Student(int regNo, string name, int year)
{
    this->regNumber = regNo;
    this->year = year;
    this->name = name;
}

bool Student::operator<(const Student &s) const
{
    if (getRegNumber() < s.getRegNumber())
    {
        return true;
    }
    return false;
}


ostream & operator<<(ostream &str, const Student &s)
{
    str << setfill(' ') << setw(3) << to_string(s.getRegNumber())
        << " | " <<  setw(4) << to_string(s.getYear()) << " | " << s.name;
    return str;
}



