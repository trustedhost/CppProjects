#include <iostream>
#include <string>

void* operator new(std::size_t count) {
    std::cout << count << " bytes 할당 " << std::endl;
    return malloc(count);
}

// // 문자열에 "very" 라는 단어가 있으면 true 를 리턴함
// bool contains_very(const std::string& str) {
//     return str.find("very") != std::string::npos;
// }

bool contains_very(std::string_view str) {
    return str.find("very") != std::string::npos;
}

std::string_view return_sv() {
    std::string* s = new std::string("hello");
    std::string_view s2 = *s;
    return s2;
}

int main() {
    // 암묵적으로 std::string 객체가 불필요하게 생성된다.
    std::cout << std::boolalpha << contains_very("c++ string is very easy to use")
              << std::endl;

    std::cout << contains_very("c++ string is not easy to use") << std::endl;

    //substr 의 경우
    //string.substr 의 경우 string 을 return 		-> O(N)
    //string_view.substr 의 경우 view 를 return  	-> O(1)

    std::string s = "c++ string substring experiment";
    std::cout << s.substr(0, s.find("string", 0)) << std::endl;

    std::string_view s_view = "c++ string substring experiment";
    std::cout << s.substr(0, s.find("string", 0)) << std::endl;

    std::cout << return_sv() << std::endl;

}
