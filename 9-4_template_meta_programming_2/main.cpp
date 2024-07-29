#include <iostream>

template <int A, int B>
struct GCD {
    static const int value = GCD<B, B % A>::value;
};

template <int A>
struct GCD<A, 0> {
    static const int value = A;
};

template <int N, int D = 1>
struct Ratio {
    typedef Ratio<N, D> type;
    static const int num = N;
    static const int den = D;
};

template <class R1, class R2>
struct _Ratio_add {
    typedef Ratio<R1::num * R2::den + R2::num * R1::den, R1::den * R2::den> type;
};
template <class R1, class R2>
struct Ratio_add : _Ratio_add<R1, R2>::type {};

template <class R1, class R2>
struct _Ratio_minus {
    typedef Ratio<R1::num * R2::den - R2::num * R1::den, R1::den * R2::den> type;
};
template <class R1, class R2>
struct Ratio_minus : _Ratio_minus<R1, R2>::type {};

template <class R1, class R2>
struct _Ratio_multiply {
    typedef Ratio<R1::num * R2::num , R1::den * R2::den> type;
};
template <class R1, class R2>
struct Ratio_multiply : _Ratio_multiply<R1, R2>::type {};

template <class R1, class R2>
struct _Ratio_divide {
    typedef Ratio<R1::num * R2::den , R1::den * R2::num> type;
};
template <class R1, class R2>
struct Ratio_divide : _Ratio_divide<R1, R2>::type {};



int main()
{
    using three_on_two = Ratio<3, 2>;
    using four_on_three = Ratio<4, 3>;
    using result_add = Ratio_add<three_on_two, four_on_three>;
    using result_minus = Ratio_minus<three_on_two, four_on_three>;
    using result_multiply = Ratio_multiply<three_on_two, four_on_three>;
    using result_divide = Ratio_divide<three_on_two, four_on_three>;

    std::cout << GCD<24, 30>::value << std::endl;
    std::cout << result_add::num << "/" << result_add::den << std::endl;
    std::cout << result_minus::num << "/" << result_minus::den << std::endl;
    std::cout << result_multiply::num << "/" << result_multiply::den << std::endl;
    std::cout << result_divide::num << "/" << result_divide::den << std::endl;
    return 0;
}
