#include <iostream>

// 1. T::y 가 정의된 경우만 overload 를 결정.
template <typename T, typename = decltype(std::declval<T::y>())>
void test(typename T::x a) {
    typename T::y b;
}

// 2. T.func 가 정의되고, 그 리턴 값이 int 인 경우만 오버로딩 허용.
template <typename T, typename = std::enable_if_t<std::is_integral_v<decltype(std::declval<T>().func())>>>
void test() {
    return;
}

// 3. T::z 가 정의되고, T.func 가 int 로 정의된 경우만 허용
template <typename T,
         typename = std::enable_if_t<
             std::is_integral_v<decltype(std::declval<T>().func())> &&
             std::is_same_v<decltype(std::declval<typename T::y>()) , typename T::y>
             >>
void test(T t) {
    return;
}


template <typename T>
void test(typename T::y b) {
    std::cout << "T::y \n";
}

struct A {
    using x = int;
    int func();
};

struct B {
    using y = int;
};

int main() {
    // test<A>(11); // template ignored error 발생.
    test<B>(11);
    A a;
}
