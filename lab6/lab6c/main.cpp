
#include "Student.h"
#include <iostream>
#include <string>
#include <list>
#include <iterator>
#include <algorithm>
#include <numeric>


void printList(list<Student> sList)
{
    for (Student s : sList)
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

bool isFirstYear(const Student &s)
{
    if (s.getYear() == 1)
    {
        return true;
    }
    return false;
}

int main()
{

    list<Student> lStudent;

    Student s1(345,"an student",1);
    Student s2(237,"student 2",2);
    Student s3(161,"an name",1);
    Student s4(452,"generic student",24);
    Student s5(411,"insert joke here",4);

    lStudent.push_back(s1);
    lStudent.push_back(s2);
    lStudent.push_back(s3);
    lStudent.push_back(s4);
    lStudent.push_back(s5);

    printList(lStudent);


    cout << endl << endl;


    lStudent.sort();

    printList(lStudent);


    cout << endl << endl;

    lStudent.remove_if(isFirstYear);

    printList(lStudent);



    return 0;
}
