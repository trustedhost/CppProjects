#include <iostream>

template <typename T, typename U>
void add(T t, U u, decltype(t + u)* result) {
    *result = t + u;
}

int main() {
    int a = 1;
    double b = 2.;

    decltype(a + b) result;

    add(a, b, &result);

        std::cout << result;
}
