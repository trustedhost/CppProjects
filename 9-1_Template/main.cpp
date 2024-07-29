#include <iostream>
#include <array>

template <typename T>
struct Compare {
    bool operator() (const T& a, const T& b) { return (a < b); }
};

template <typename T, typename Comp = Compare<T>>
T max(const T& a, const T& b){
    Comp comp;
    return (comp(a, b)) ? a : b;
}

int main() {
    std::cout << max(1, 2) << std::endl;
}
