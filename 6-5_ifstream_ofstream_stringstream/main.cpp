// 파일에서의 입출력
#include <fstream>
#include <iostream>
#include <string>

int main() {
    // 파일 읽기 준비
    std::ifstream in("test.txt");
    std::string s;

    if (in.is_open()) {
        in.seekg(0, std::ios::end); // 위치 지정자를 끝으로 옮기기
        int size = in.tellg(); //size 받아오기
        in.seekg(0, std::ios::beg); // 다시 시작점으로 불러오기
        s.resize(size); // string 의 메모리 할당.
        in.read(&s[0], size-1); //  s 로 메모리를 불러옴.

        std::cout << "입력 받은 문자열 :: " << s << std::endl;
    } else {
        std::cout << "파일을 찾을 수 없습니다!" << std::endl;
    }
    in.close();

    char buf[30];
    in.open("other.txt");
    if(in.is_open()) {
        in.getline(buf, 100);
        std::cout << "입력 받은 문자열 :: " << buf << std::endl;
    } else {
        std::cout << "파일을 찾을 수 없습니다!" << std::endl;
    }
    in.close();

    std::string s2;
    in.open("other.txt");
    if(in.is_open()) {
        getline(in,s2);
        std::cout << "입력 받은 문자열 :: " << s2 << std::endl;
    } else {
        std::cout << "파일을 찾을 수 없습니다!" << std::endl;
    }
    return 0;
}
