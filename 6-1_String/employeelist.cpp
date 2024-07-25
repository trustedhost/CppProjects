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

void EmployeeList::add_manager(Manager *manager)
{
    manager_list[current_manager] = manager;
    current_manager++;
}

int EmployeeList::getCurrent_employee() const
{
    return current_employee;
}

int EmployeeList::getCurrent_manager() const
{
    return current_manager;
}

void EmployeeList::print_employee_info() const
{
    int total_pay = 0;
    for (int i = 0; i < current_employee; i++) {
        employee_list[i]->print_info();
        total_pay += employee_list[i]->calculate_pay();
    }
    for (int i = 0; i < current_manager; i++) {
        manager_list[i]->print_info();
        total_pay += manager_list[i]->calculate_pay();
    }
    std::cout << "total payment : " << total_pay << "$" << std::endl;
}

EmployeeList::~EmployeeList()
{
    for (int i = 0 ; i < current_employee ; i++) {
        delete employee_list[i];
    }
    for (int i = 0 ; i < current_manager; i++) {
        delete manager_list[i];
    }
    delete[] employee_list;
    delete[] manager_list;
}
