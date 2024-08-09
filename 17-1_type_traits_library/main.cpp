#include <iostream>
#include <type_traits>

class A {};


template <typename T>
void only_integer(const T& t){
    // static_assert(std::is_integral<T>::value);
    std::cout << " ";
}

int main()
{
    A a;
    only_integer(1);
    only_integer(a);
}
