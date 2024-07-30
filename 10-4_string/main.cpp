#include <iostream>
#include <string>



struct my_char_traits : public std::char_traits<char> {
    static int get_real_rank(char c) {
        if(isdigit(c)) {
            return c + 256;
        }
        return c;
    }

    static int compare(const char* s1, const char* s2, size_t n)  {
        while (n-- != 0) {
            if (get_real_rank(*s1) < get_real_rank(*s2)) {
                return -1;
            }
            if (get_real_rank(*s1) > get_real_rank(*s2)) {
                return 1;
            }
            ++s1;
            ++s2;
        }
        return 0;
    }
};

int main()
{
    std::basic_string<char, my_char_traits> my_s1 = "1a";
    std::basic_string<char, my_char_traits> my_s2 = "a1";

    std::cout << std::boolalpha << (my_s1 < my_s2) << std::endl;

    std::string s1 = "1a";
    std::string s2 = "a1";

    std::cout << std::boolalpha << (s1 < s2) << std::endl;

}
