
#include "Employee.h"
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <numeric>

using namespace std;

int accEmployees(int currentTotal, const Employee &e)
{
    return (currentTotal + e.getSalary());
}

int main()
{

    vector<Employee> eVec;

    Employee e1(42,"bob",2411);
    Employee e2(13,"yoshikage kira",3156);
    Employee e3(66,"bobert",4122);
    Employee e4(1562,"dave",5315);
    Employee e5(125,"an employee",5312);

    eVec.push_back(e1);
    eVec.push_back(e2);
    eVec.push_back(e3);
    eVec.push_back(e4);
    eVec.push_back(e5);

    int sum = accumulate(eVec.begin(),eVec.end(),0,accEmployees);

    cout << to_string(sum) << endl;


    return 0;
}
