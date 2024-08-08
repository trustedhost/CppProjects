#include <iostream>

template <typename T, typename U>
auto add(T t, U u) -> decltype(t + u) {
    return t + u;
}

class A {
public:
    A(int x) {}
    int f() { return 1;}
};

template <typename T>
decltype(std::declval<T>().f()) func(T t) { // std::declval 을 통해서 생성자가 정의되지 않은 Class 에 대해서 처리할 수 있다.
    return t.f();
}

int main() {
    int a = 1;
    double b = 2.;

    decltype(a + b) result = add(a , b);

    std::cout << result << '\n';


    // decltype(A().f()) p; // decltype 내의 문장은 compile-time 에 정의될 수 있어야 한다.

    A instance = A(3);

    std::cout << func(instance);
}
