#include <iostream>
#include <string>
// //verson 1 ( 할당 자주함 )
// template <typename String>
// std::string StrCat(String& s) {
//     return std::string(s);
// }

// template <typename String, typename... Strings>
// std::string StrCat(String& s, Strings... strs) {
//     return std::string(s) + StrCat(strs...);
// }



//ver 2 (할당 한 번에 함.)
size_t GetStringSize(const char* s) {
    return strlen(s);
}

template <typename String>
size_t GetStringSize(const String& s) {
    return s.size();
}

template <typename String, typename... Strings>
size_t GetStringSize(String& s, Strings... strs) {
    return GetStringSize(s) + GetStringSize(strs...);
}

void AppendToString(std::string* concat_string) {
    return ;
}

template <typename String, typename... Strings>
void AppendToString(std::string* concat_string, String s, Strings... strs) {
    concat_string->append(s);
    AppendToString(concat_string, strs...);

}

template <typename String, typename... Strings>
std::string StrCat(const String& s, Strings... strs) {
    size_t total_size;
    total_size = GetStringSize(s, strs...);

    std::string concat_string;
    concat_string.reserve(total_size);

    AppendToString(&concat_string, s, strs...);

    return concat_string;
}

int main()
{
    std::cout << StrCat("a", "b", "h" , " " ) << std::endl;
    return 0;
}
