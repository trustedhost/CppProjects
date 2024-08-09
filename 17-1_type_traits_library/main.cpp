#include <iostream>
#include <type_traits>
// 정수만 받는 template 함수 구현하기


//1. static_assert 활용
template <typename T>
void only_integer_ver1(const T& t) {
    static_assert(std::is_integral<T>::value);
    return;
}


//2. enable_if 활용
template <typename T, typename = typename std::enable_if<std::is_integral<T>::value>::type>
void only_integer_ver2(const T& t) {
    return ;
}


//3. enable_if 와 alias 활용
template <typename T, typename = typename std::enable_if_t<std::is_integral_v<T>>>
void only_integer_ver3(const T& t) {
    return;
}

struct A {};

int main()
{
    A a;
    only_integer_ver1(1);
    // only_integer(a);// 컴파일 타임 에러 발생.
    only_integer_ver3(1);
    // only_integer_ver3(a); // 컴파일 타임 에러 발생.
    only_integer_ver2(1);
    // only_integer_ver2(a); // 컴파일 타임 에러 발생.
}
