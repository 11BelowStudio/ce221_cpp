
#include "Employee.h"
#include <string>

using namespace std;


Employee::Employee(int payrollNumber, string name, int salary)
{
    this->payroll = payrollNumber;
    this->name = name;
    this->salary = salary;
}

