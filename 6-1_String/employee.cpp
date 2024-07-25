#include "employee.h"


Employee::Employee(std::string name, int age, std::string position, int rank)
    : name(name), age(age), position(position), rank(rank)
{}

Employee::Employee(const Employee &employee)
{
    name = employee.name;
    age = employee.age;
    position = employee.position;
    rank = employee.rank;
}

Employee::Employee()
{

}

void Employee::print_info()
{
    std::cout << "name : " << name << std::endl;
    std::cout << "age : " << age << std::endl;
    std::cout << "position : " << position << std::endl;
    std::cout << "rank : " << rank << std::endl;
    std::cout << "salary : " << calculate_pay() << "$" << std::endl;
}

int Employee::calculate_pay()
{
    return rank * 50 + 200;
}
