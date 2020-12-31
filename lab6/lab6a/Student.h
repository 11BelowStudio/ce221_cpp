#ifndef _STUDENT_H_
#define _STUDENT_H_

using namespace std;
#include <iostream>
#include <string>

class Student
{
private:
    string name;
    int regNumber, year;
public:
    Student(int regNo, string name, int year);
    bool operator<(const Student &s) const;
    friend ostream & operator<<(ostream &str, const Student &s);
    int getYear() const
    {
        return year;
    }
    int getRegNumber() const
    {
        return regNumber;
    }
    string getName() const
    {
        return name;
    }
};

#endif
