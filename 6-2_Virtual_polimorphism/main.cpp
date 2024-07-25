#include <iostream>

class Base {
    std::string s;
public:
    Base() : s("기반") { std::cout << "기반 클래스" << std::endl; }
    virtual void what() { std::cout << s << std::endl; }
    //void printblabla() { std::cout << "blabla" << std::endl; };
};

class Derived : public Base {
    std::string s;
public:
    Derived() : s("파생"), Base() { std::cout << "파생 클래스" << std::endl; }
    void what() override { std::cout << s << std::endl; }
    //void what() const override { std::cout << s << std::endl; } 함수의 형태가 완전히 동일해야 override 가능.
    //void printblabla() override { std::cout << "bloblo" << std::endl; }; // virtual 함수에 대해서만 override 가능.

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
