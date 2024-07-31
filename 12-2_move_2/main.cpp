#include <iostream>
//객체 생성 시 이동 프로젝트

class A {
public:
    A() {std::cout << "constructor" << std::endl;};
    A(const A& a) {std::cout << "copy constructor" << std::endl;};
    A(A&& a) {std::cout << "move constructor" << std::endl;};
};

class B {
    A a_;
public:
    B(const A& a_) : a_(a_) {}
};

int main()
{
    A a;
    std::cout << "create B" << std::endl;
    B b(a);
    return 0;
}
