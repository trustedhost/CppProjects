#ifndef EMPLOYEELIST_H
#define EMPLOYEELIST_H

#include "employee.h"
#include "manager.h"

class EmployeeList
{
    int alloc_employee; //할당한 총 직원 수
    int current_employee; // 현재 직원 수
    int current_manager; // 현재 매니저 수

    Employee** employee_list; // 전체 데이터
    Manager** manager_list;
public:
    EmployeeList(int alloc_employee);
    void add_employee(Employee* employee);
    void add_manager(Manager* manager);
    int getCurrent_employee() const;
    int getCurrent_manager() const;
    void print_employee_info() const;
    ~EmployeeList();
};

#endif // EMPLOYEELIST_H
