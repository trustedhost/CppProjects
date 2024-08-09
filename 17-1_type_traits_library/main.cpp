#include <iostream>
#include <type_traits>

class A {
public:
    int i;
    A(int i = 1) : i(i) {}
    ~A() = default;
};



int main()
{
    int A::* p_i = &A::i;

    A a(3);
    std::cout << a.i << '\n';
    std::cout << a.*p_i;
}
