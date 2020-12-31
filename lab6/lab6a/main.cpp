
#include "Student.h"
#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
#include <numeric>


void printVec(vector<Student> sVec)
{
    for (Student s : sVec)
    {
        cout << s << endl;
    }
}


bool compareStudents(const Student &s1, const Student &s2)
{
    if (s1.getName() < s2.getName())
    {
        return true;
    }
    return false;
}

int main()
{

    vector<Student> vStudent;

    Student s1(345,"an student",2019);
    Student s2(237,"student 2",2018);
    Student s3(161,"an name",2014);
    Student s4(452,"generic student",1985);
    Student s5(411,"insert joke here",2001);

    vStudent.push_back(s1);
    vStudent.push_back(s2);
    vStudent.push_back(s3);
    vStudent.push_back(s4);
    vStudent.push_back(s5);

    printVec(vStudent);


    cout << endl << endl;

    sort(vStudent.begin(), vStudent.end());

    printVec(vStudent);

    cout << endl << endl;

    sort(vStudent.begin(), vStudent.end(),compareStudents);

    printVec(vStudent);


    return 0;
}
