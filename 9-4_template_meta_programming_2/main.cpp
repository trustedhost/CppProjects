#include <iostream>

template <int A, int B>
struct GCD {
    static const int value = GCD<B, A % B>::value;
};

template <int A>
struct GCD<A, 0> {
    static const int value = A;
};

template <int N, int D = 1>
struct Ratio {
private:
    const static int _gcd = GCD<N,D>::value;
public:
    typedef Ratio<N / _gcd, D/ _gcd> type;
    static const int num = N / _gcd;
    static const int den = D / _gcd;
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

template <typename U, typename V, typename W>
struct Dim {
    using M = U;
    using L = V;
    using T = W;

    using type = Dim<M, L, T>;
};

template <typename U, typename V>
struct add_dim_ {
    typedef Dim<typename Ratio_add<typename U::M, typename V::M>::type,
                typename Ratio_add<typename U::L, typename V::L>::type,
                typename Ratio_add<typename U::T, typename V::T>::type>
        type;
};
template <typename U, typename V>
struct minus_dim_ {
    typedef Dim<typename Ratio_minus<typename U::M, typename V::M>::type,
                typename Ratio_minus<typename U::L, typename V::L>::type,
                typename Ratio_minus<typename U::T, typename V::T>::type>
        type;
};

template <typename T, typename D>
struct quantity {
    T q;
    using dim_type = D;

    quantity operator+(quantity<T, D> quant) {
        return quantity<T, D>(q + quant.q);
    }
    quantity operator-(quantity<T, D> quant) {
        return quantity<T, D>(q - quant.q);
    }
    template <typename D2>
    quantity<T, typename add_dim_<D, D2>::type> operator*(quantity<T, D2> quant) {
        return quantity<T, typename add_dim_<D, D2>::type> (q * quant.q);
    }
    template <typename D2>
    quantity<T, typename minus_dim_ <D, D2>::type> operator/(quantity<T, D2> quant) {
        return quantity<T, typename minus_dim_<D, D2>::type> (q / quant.q);
    }
    quantity<T, D> operator*(T scalar) { return quantity<T, D>(q * scalar);}
    quantity<T, D> operator/(T scalar) { return quantity<T, D>(q / scalar);}
    quantity(T q): q(q) {}
};

template <typename T, typename D>
std::ostream& operator<<(std::ostream& o, const quantity<T, D>& q) {
    o << q.q << "kg" << D::M::num / D::M::den << "m^" << D::L::num / D::L::den << "s^" << D::T::num / D::T::den;
    return o;
}


int main()
{
    using three_on_two = Ratio<3, 2>;
    using four_on_three = Ratio<4, 3>;
    using result_add = Ratio_add<three_on_two, four_on_three>;
    using result_minus = Ratio_minus<four_on_three, three_on_two>;
    using result_multiply = Ratio_multiply<three_on_two, four_on_three>;
    using result_divide = Ratio_divide<three_on_two, four_on_three>;

    std::cout << GCD<24, 30>::value << std::endl;
    std::cout << result_add::num << "/" << result_add::den << std::endl;
    std::cout << result_minus::num << "/" << result_minus::den << std::endl;
    std::cout << result_multiply::num << "/" << result_multiply::den << std::endl;
    std::cout << result_divide::num << "/" << result_divide::den << std::endl;

    using one = Ratio<1, 1>;
    using zero = Ratio<0, 1>;

    quantity<double, Dim<one, zero, zero>> kg(2);
    quantity<double, Dim<zero, one, zero>> meter(3);
    quantity<double, Dim<zero, zero, one>> second(1);

    // F 의 타입은 굳이 알필요 없다!
    auto F = kg * meter / (second * second);
    std::cout << "2 kg 물체를 3m/s^2 의 가속도로 밀기 위한 힘의 크기는? " << F << std::endl;
    return 0;
}
