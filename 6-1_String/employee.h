#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
class Employee
{
protected:
    std::string name;
    int age;

    std::string position;
    int rank;

public:
    Employee(std::string name, int age, std::string position, int rank);
    Employee(const Employee& employee);
    Employee();
    void print_info();
    int calculate_pay();
};

#endif // EMPLOYEE_H
