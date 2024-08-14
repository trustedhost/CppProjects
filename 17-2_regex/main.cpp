#include <iostream>
#include <regex>
#include <vector>
#include <string>

int main()
{
    std::vector<std::string> file_names = {"db-123-log.txt", "db-124-log.txt",
                                         "not-db-log.txt", "db-12-log.txt",
                                         "db-12-log.jpg"};
    std::regex re("db-\\d*-log\\.txt");
    // std::regex re("db-\\d*-log\\.txt", std::regex::ECMAScript); // default
    // std::regex re("db-\\d*-log\\.txt", std::regex::icase); // 대,소문자 구분 X
    // std::regex re("db-\\d*-log\\.txt", std::regex::optimize); // regex 객체를 만드는 데에는 성능 안좋으나, 그 객체의 사용은 최적화를 보장함.
    for (const auto& file_name : file_names) {
        std::cout << file_name << ": " << std::boolalpha << std::regex_match(file_name, re) << '\n';
    }
}
