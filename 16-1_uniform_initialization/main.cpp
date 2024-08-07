#include <iostream>
#include <map>

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

    A a(1);
    A b{2};
    A c = {3};

    std::cout << a.get_k() << b.get_k() << c.get_k()<< std::endl;


    A {"hello", "my", "name", "is", "chae hoon"};

    return 0;
}
