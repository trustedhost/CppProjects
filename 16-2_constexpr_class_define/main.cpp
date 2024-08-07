// constexpr 을 통해서 생성자를 정의할 수 있다.
// 함수를 정의할 때와 마찬가지로, constexpr 로 정의된 함수 내에는 literal 만 정의가 가능하다.
// constexpr 이 정의된 class 는 동적바인딩 허용 금지. -> virtual 상속, virtual 함수 모두 불가능하다.
#include <iostream>

class Vector {
public:
    constexpr Vector(int x, int y) : x_(x), y_(y) {}

    constexpr int x() const {return x_;};
    constexpr int y() const {return y_;};

private:
    int x_;
    int y_;
};

constexpr Vector addVec(Vector a, Vector b) {
    return {a.x() + b.x(), a.y() + b.y()};
}

template <int N>
struct A {
    constexpr int operator()(){ return N; };
};


int main()
{
    constexpr Vector a(1, 2);
    constexpr Vector b{2, 4};

    constexpr Vector c = addVec(a, b);

    std::cout << c.x() << ", " << c.y() << std::endl;
    std::cout << A<c.x()>()() <<std::endl;
}
