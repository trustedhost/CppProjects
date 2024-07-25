#include "employeelist.h"


EmployeeList::EmployeeList(int alloc_employee)
    : alloc_employee(alloc_employee)
{
    employee_list = new Employee*[alloc_employee];
    current_employee = 0;
}

void EmployeeList::add_employee(Employee *employee)
{
    employee_list[current_employee] = employee;
    current_employee++;
}

int EmployeeList::getCurrent_employee() const
{
    return current_employee;
}

void EmployeeList::print_employee_info() const
{
    int total_pay = 0;
    for (int i = 0; i < current_employee; i++) {
        employee_list[i]->print_info();
        total_pay += employee_list[i]->calculate_pay();
    }
    std::cout << "total payment : " << total_pay << "$" << std::endl;
}

EmployeeList::~EmployeeList()
{
    for (int i = 0 ; i < current_employee ; i++) {
        delete employee_list[i];
    }
    delete[] employee_list;
}
