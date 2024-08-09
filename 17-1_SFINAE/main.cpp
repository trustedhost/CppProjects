#include <iostream>

template <typename T, typename = decltype(std::declval<T::y>)>
void test(typename T::x a) {
    typename T::y b;
}

template <typename T>
void test(typename T::y b) {
    std::cout << "T::y \n";
}

struct A {
    using x = int;
};

struct B {
    using y = int;
};

int main() {
    // test<A>(11); // template ignored error 발생.
    test<B>(11);
}
