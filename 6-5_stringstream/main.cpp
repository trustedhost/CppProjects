#include <iostream>
#include <sstream>

double to_number(std::string s) {
    std::istringstream ss(s);
    double x;
    ss >> x;
    return x;
}

int main()
{
    std::cout << to_number("1") + 7<< std::endl;
    return 0;
}
