#include <iostream>
#include "mystring.h"

template <typename T>
void my_swap(T& a, T& b) {
    T temp(std::move(a));
    a = std::move(b);
    b = std::move(temp);
}


int main()
{
    MyString a("korea");
    MyString b = "st";
    my_swap(a, b);
    a.println();
    return 0;
}
