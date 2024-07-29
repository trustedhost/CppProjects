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



// //ver 2 (할당 한 번에 함.)
// size_t GetStringSize(const char* s) {
//     return strlen(s);
// }

// template <typename String>
// size_t GetStringSize(const String& s) {
//     return s.size();
// }

// template <typename String, typename... Strings>
// size_t GetStringSize(String& s, Strings... strs) {
//     return GetStringSize(s) + GetStringSize(strs...);
// }

// void AppendToString(std::string* concat_string) {
//     return ;
// }

// template <typename String, typename... Strings>
// void AppendToString(std::string* concat_string, String s, Strings... strs) {
//     concat_string->append(s);
//     AppendToString(concat_string, strs...);

// }

// template <typename String, typename... Strings>
// std::string StrCat(const String& s, Strings... strs) {
//     size_t total_size;
//     total_size = GetStringSize(s, strs...);

//     std::string concat_string;
//     concat_string.reserve(total_size);

//     AppendToString(&concat_string, s, strs...);

//     return concat_string;
// }


// // int 의 average 구하기 ver 1
// template <typename Int>
// unsigned int sizeofary(Int p) {
//     return 1;
// }
// // 여러 인자를 위한 재귀 케이스
// template <typename Int, typename... Ints>
// unsigned int sizeofary(Int p, Ints... nums) {
//     return sizeofary(p) + sizeofary(nums...);
// }
// template <typename Int>
// int sum(Int p) {
//     return p;
// }
// template <typename Int, typename... Ints>
// int sum(Int p, Ints... nums) {
//     return sum(p) + sum(nums...);
// }

// template <typename Int, typename... Ints>
// double average(Int p, Ints... nums) {
//     unsigned int total_counts;
//     double result;
//     int sum_arr;
//     total_counts = sizeofary(p, nums...);
//     sum_arr = sum(p, nums...);
//     result = (static_cast<double>(sum_arr) / total_counts);
//     return result;
// }

// // int average ver 2.2
// //재귀함수 종료를 위한 케이스
// int sum_all() {return 0;}

// template <typename... Ints>
// int sum_all(int n, Ints... nums) {
//     return n + sum_all(nums...);
// }

// int average ver 3
// C++ 17 에 도입.

template <typename... Ints>
int sum_all(Ints... nums) {
    return (... + nums);
}

template <typename... Ints>
double average(Ints... nums) {
    return static_cast<double>(sum_all(nums...))/sizeof...(nums);
}

int main()
{
    std::cout << average(1, 1, 17, 4, 5) << std::endl;
    return 0;
}
