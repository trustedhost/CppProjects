#ifndef MANAGER_H
#define MANAGER_H

#include "employee.h"
class Manager : public Employee {
    int year_of_service;

public:
    Manager(std::string name, int age, std::string position, int rank,
            int year_of_service);

    // 복사 생성자
    Manager(const Manager& manager);

    // 디폴트 생성자
    Manager();

    int calculate_pay();
    void print_info();
};

#endif // MANAGER_H
