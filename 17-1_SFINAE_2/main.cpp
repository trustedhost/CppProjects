#include <iostream>
#include <type_traits>
#include <vector>

template <typename T>
struct is_iterator {
private:
    template <typename U>
    static char test(typename std::iterator_traits<U>::iterator_category*);

    template <typename U>
    static long test(...);
public:
    static constexpr bool value = std::is_same_v<decltype(test<T>(nullptr)), char>;
};

template <typename T>
class vector {
public:
    vector(size_t num, const T& element) {
        std::cout << element << " 를 " << num << " 개 만들기" << std::endl;
    }


    template <typename Iterator, typename = typename std::enable_if<is_iterator<Iterator>::value>::type >
    vector(Iterator start, Iterator end) {
        std::cout << "반복자를 이용한 생성자 호출" << std::endl;
    }
};

int main() {
    vector<int> v(10, 3);

    std::vector<int> double_vec;
    vector<int> v2(double_vec.begin(), double_vec.end());

}
