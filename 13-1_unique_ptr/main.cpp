#include <iostream>
#include <vector>

template <typename Iter>
void print_vec(Iter start, Iter end) {
    while (start != end) {
        std::cout << *(*start)<< std::endl;
        start++;
    }
    std::cout << std::endl;
}

int main()
{
    std::vector<std::unique_ptr<int>> vec;
    std::unique_ptr<int> ptr(new int(1));
    vec.push_back(std::move(ptr));
    // vec.push_back(ptr);// 오류가 나게 됨. unique_ptr 은 단 하나의 포인터만 지목 가능.
    print_vec(vec.begin(), vec.end());
    return 0;
}
