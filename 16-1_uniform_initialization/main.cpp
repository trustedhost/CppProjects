#include <iostream>
#include <map>
#include <string>

using namespace std::string_literals;

class A {
    int k;
public:
    A(int a = 0) : k(a) {}
    int get_k() {
        return k;
    }
    A(std::initializer_list<std::string> lst) {
        for (auto iter = lst.begin(); iter != lst.end(); iter++) {
            std::cout << *iter << " ";
        }
    }
    A(std::initializer_list<double> lst) {
        for (auto iter = lst.begin(); iter != lst.end(); iter++) {
            std::cout << *iter << " ";
        }
    }
    // 주의사항. Initializer list 에서 암시적으로 형변환이 발생할 가능성이 있다면 ( 이 경우 int -> double ) 중의성을 가지게 되고,
    // 중의성을 가지는 경우 initializer list 를 인자로 하는 "함수" 가 최우선시된다. ( 이 경우 생성자보다 우선된다. )

};

A func() {
    return {4}; // 초기화 리스트를 통해서 이와 같이 리턴이 가능하다.
}

int main()
{
    // 문제 : () 는 함수의 인자를 의미하기도, class 의 생성자를 의미하기도 해서 중의적임.
    // 해결책 : {} 를 통해 class 생성자를 따로 표기함. (uniform initializer)

    // 유의사항 : uniform intitializer 는 일부 암시적 형변환을 거부한다.
    // A a(3.5);
    // A b{3.5}; // impilicit , narrowing(데이터 손실 존재) 형변환을 인정하지 않는다.

    A a(1); // OK
    A b{2}; //Error. (narrowing)
    A c = {3}; //Error. (narrowing)

    std::cout << a.get_k() << b.get_k() << c.get_k()<< std::endl;


    A {"hello", "my", "name", "is", "chae hoon"};


    // auto 를 통한 initializer_list 선언.
    auto p = {1};
    auto q{2};
    auto r = {1, 2};
    // auto s{1, 2}; // error


    auto const_chars = {"hello", "my", "name", "is", "chae hoon"};
    auto strings = {"hello"s, "my"s, "name"s, "is"s, "chae hoon"s};


    return 0;
}
