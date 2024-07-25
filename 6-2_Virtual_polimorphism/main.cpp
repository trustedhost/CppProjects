#include <iostream>

class Base {
    std::string s;
public:
    Base() : s("기반") { std::cout << "기반 클래스" << std::endl; }
    virtual void what() { std::cout << s << std::endl; }
};

class Derived : public Base {
    std::string s;
public:
    Derived() : s("파생"), Base() { std::cout << "파생 클래스" << std::endl; }
    void what() override { std::cout << s << std::endl; }
};

int main()
{
    Base base;
    Derived base2;

    Base* p_b;
    Base* p_d;

    p_b = &base;
    p_d = &base2;
    p_b->what();
    p_d->what();
}
