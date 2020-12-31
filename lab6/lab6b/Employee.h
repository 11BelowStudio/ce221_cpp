#ifndef _EMPLOYEE_H_
#define _EMPLOYEE_H_

using namespace std;
#include <iostream>
#include <string>

class Employee
{
private:
    string name;
    int payroll, salary;
public:
    Employee(int payrollNumber, string name, int salary);

    int getPayroll() const
    {
        return payroll;
    }
    int getSalary() const
    {
        return salary;
    }
    string getName() const
    {
        return name;
    }

};

#endif
