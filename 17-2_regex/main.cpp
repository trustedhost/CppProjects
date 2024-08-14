#include <iostream>
#include <regex>
#include <vector>
#include <string>

int main()
{
    std::vector<std::string> phone_numbers = {"010-1234-5678", "010-123-4567",
                                            "011-1234-5567", "010-12345-6789",
                                            "123-4567-8901", "010-1234-567"};std::regex re("db-\\d*-log\\.txt");
    std::regex regex("[01]{3}-\\d{3,4}-\\d{4}");
    std::smatch match; // std::string 으로 반환.
    // std::cmatch match; // const char* 로 반환

    for (const auto& phone_number : phone_numbers) {
        if (std::regex_match(phone_number, match, regex)) {
            for (size_t i = 0; i < match.size(); i++) {
                std::cout << "Match : " << match[i].str() << '\n';
            }
        }
    }

}
