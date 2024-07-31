#include <iostream>
#include <string>

// 이와 같이 new 를 전역 함수로 정의하면 모든 new 연산자를 오버로딩 해버린다.
// (어떤 클래스의 멤버 함수로 정의하면 해당 클래스의 new 만 오버로딩됨)
void* operator new(std::size_t count) {
    std::cout << count << "bytes 할당함.. " << std::endl;
    void* ptr = std::malloc(count);
    if(!ptr) throw std::bad_alloc();
    else return ptr;
}

int main() {
    std::cout << "s1 생성 --- " << std::endl;
    std::string s1 = "this is a pretty long sentence!!!";
    std::cout << "s1 크기 : " << sizeof(s1) << std::endl;
    std::cout << "s1 내의 data : " << s1.data() << std::endl;
    std::cout << "s1 내의 data : " << static_cast<void*>(s1.data()) << std::endl;
    std::cout << "s1 내의 string 길이 : " << s1.length() << std::endl;    std::cout << "s1 생성 --- " << std::endl;
    std::string s3 = "this is a pretty long sentence!!!";
    std::cout << "s3 크기 : " << sizeof(s3) << std::endl;
    std::cout << "s3 내의 data : " << s3.data() << std::endl;
    std::cout << "s3 내의 data : " << static_cast<void*>(s3.data()) << std::endl;
    std::cout << "s3 내의 string 길이 : " << s3.length() << std::endl;

    std::cout << "s4 생성 --- " << std::endl;
    std::string s4 = "short sentence";
    std::cout << "s4 크기 : " << sizeof(s4) << std::endl;
    std::cout << "s4 내의 data : " << s4.data() << std::endl;
    std::cout << "s4 내의 data : " << static_cast<void*>(s4.data()) << std::endl;
    std::cout << "s4 내의 string 길이 : " << s4.length() << std::endl;

    std::cout << "s2 생성 --- " << std::endl;
    std::string s2 = "short sentence";
    std::cout << "s2 크기 : " << sizeof(s2) << std::endl;
    std::cout << "s2 내의 data : " << s2.data() << std::endl;
    std::cout << "s2 내의 data : " << static_cast<void*>(s2.data()) << std::endl;
    std::cout << "s2 내의 string 길이 : " << s2.length() << std::endl;
}
