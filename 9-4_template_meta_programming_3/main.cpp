#include <iostream>
//is_prime


template <int N, int d>
struct check_div {
    static const bool result = (N % d == 0) || check_div<N,d + 1>::result;
};

template <int N>
struct check_div<N, N /2> {
    static const bool result = (N % (N / 2)) == 0;
};

template <int N>
struct is_prime {
    static const bool result = !check_div<N, 2>::result;
};
template <>
struct is_prime<2> {
    static const bool result = true;
};
template <>
struct is_prime<3> {
    static const bool result = true;
};


int main() {
    using isPrime = is_prime<22>;
    std::cout << isPrime::result << std::endl;

    return 0;
}
