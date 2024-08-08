#include <iostream>

template <typename T, typename U>
auto add(T t, U u) -> decltype(t + u) {
    return t + u;
}

int main() {
    int a = 1;
    double b = 2.;

    decltype(a + b) result = add(a , b);

    std::cout << result;
}
