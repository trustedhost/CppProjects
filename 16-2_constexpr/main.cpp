#include <iostream>
//constexpr - 상수식을 명시해주는 키워드.

// 상수식 	- 컴파일 타임에 값을 결정할 수 있는 식.
// 정수 상수식 - 상수식 중에서 정수로 결정되는 식.

//constexpr 은 무조건 const 이지만, 반대는 성립하지 않는다.
// const 		- 컴파일 타임에 결정될 필요는 없다.
// constexpr	- 컴파일 타임에 결정.

// const int i = 0; 이라고 하면, 컴파일 타임 혹은 런타임에 초기화 될 수 있지만,
// constexpr int i = 0;  이라고 하면 무조건 컴파일 타임에 초기화 된다.

//1
int factorial(int N) {
    if (N == 1) {
        return 1;
    } else {
        return N * factorial(N - 1);
    }
}

//2
template <int N>
struct Factorial {
    static const int value = N * Factorial<N-1>::value;
};

template <>
struct Factorial<1> {
    static const int value = 1;
};

template <int N>
struct A {
    int operator()() {return N;}
};


//3
constexpr int factorial_c(int N) {
    if (N == 1) {
        return 1;
    }
    return N * factorial_c(N - 1);
}

int main()
{
    // 1. runtime 에 factorial의 값을 결정.
    std::cout << factorial(10) << std::endl;

    // 2. compile time 에 값을 결정 (Template Meta Programming 활용)
    std::cout << A<Factorial<10>::value>()() << std::endl;

    // 3. compile time 에 값을 결정 (conexpr 활용)
    std::cout << factorial_c(10) << std::endl;
}
