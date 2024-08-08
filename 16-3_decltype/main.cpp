#include <iostream>

int main() {
    int&& r1 = 5;
    r1 = 10;  // OK: can modify through non-const rvalue reference

    const int&& r2 = 8;
    // r2 = 15;  // Error: cannot modify through const rvalue reference


    decltype(r1) p = 7; // int&&
    decltype(r2) q = 9; // const int&&

    auto r = r1; // int

    auto s = r2; // int


    static_assert(std::is_same_v<decltype(p), int&&>, "p is int&&");
    static_assert(std::is_same_v<decltype(q), const int&&>, "q is const int&&");
    static_assert(std::is_same_v<decltype(r), int>, "r is int");
    static_assert(std::is_same_v<decltype(s), int>, "s is int");

}
