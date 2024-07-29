#include <iostream>

// template <typename T, unsigned int N>
// class Array {
//     T data[N];
// public:
//     Array(T (&arr)[N]) {
//         for (int i = 0; i < N ; i++) {
//             data[i] = arr[i];
//         }
//     }
//     T* get_array() {
//         return data;
//     }
//     unsigned int size() {
//         return N;
//     }
//     void print_all() {
//         for(int i = 0; i < N; i++) {
//             std::cout << data[i] << std::endl;
//         }
//         std::cout << std::endl;
//     }
// };

template <int N>
struct Int {
    static const int n = N;
};

template <typename A, typename B>
struct add {
    typedef Int<A::n + B::n> result;
};

template <int N>
struct Factorial {
    static const int result = N * Factorial<N - 1>::result;
};
template <>
struct Factorial<1> {
    static const int result = 1;
};


template <int A, int B>
struct GCD {
    static const int value = GCD<B, A % B>::value;
};

template <int A>
struct GCD<A, 0> {
    static const int value = A;
};


int main()
{
    // int arr[3] = {0, 2, 4};
    // Array<int, 3> tem_arr(arr);
    // tem_arr.print_all();
    // std::cout << (typeid(Array<int, 3>) == typeid(Array<int, 3>)) << std::endl;
    typedef Int<1> One;
    using Two = Int<2>;
    using Three = add<One, Two>::result;

    Three three;
    std::cout << three.n << std::endl;

    std::cout << Factorial<6>::result << std::endl;

    std::cout << GCD<24, 30>::value << std::endl;
    return 0;
}
