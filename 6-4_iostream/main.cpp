// 주의할 점
#include <iostream>
using namespace std;
int main() {
    int t;
    while (true) {
        std::cin >> std::hex >> t;

        // std::cin.setf(std::ios_base::hex, std::ios_base::basefield);
        // std::cin >> t;

        char peek = std::cin.rdbuf()->snextc(); // read buffer 가지고 놀기

        std::cout << "입력 :: " << t << std::endl;
        if (std::cin.fail()) {
            std::cout << "제대로 된 값을 입력해주세요." << std::endl;
            std::cin.clear(); // 플래그들을 초기화.
            std::cin.ignore(100, 'n'); // 입력버퍼를 초기화..
        }
        if (t == 1) break;
    }
}
