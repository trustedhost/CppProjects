#include <iostream>
#include <sstream>

double to_number(std::string s) {
    std::istringstream iss(s);
    double x;
    iss >> x;
    return x;
}

std::string to_str(int x){
    std::ostringstream oss;
    oss << x;
    oss << 7;
    return oss.str();
}

int main()
{
    std::cout << to_number("8 a")<< std::endl;
    std::cout << to_str(2) << std::endl;
    return 0;
}
