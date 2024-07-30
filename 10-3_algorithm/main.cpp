#include <iostream>
#include <vector>

template <typename T>
void print_vector(std::vector<T> vector) {
    for (auto elem : vector) {
        std::cout << elem;
    }
    std::cout << std::endl;
}

template <typename Iter>
void print_iter(Iter start, Iter end) {
    Iter itr = start;
    while (itr != end) {
        std::cout << *itr;
        itr++;
    }
    std::cout << std::endl;
}

struct is_odd {
    bool operator() (int i) {return i % 2 == 1; }
};

int main()
{
    std::vector<int> int_vec;
    int_vec.push_back(5);
    int_vec.push_back(4);
    int_vec.push_back(3);
    int_vec.push_back(2);
    int_vec.push_back(1);
    int_vec.push_back(2);
    int_vec.push_back(3);

    int_vec.erase(std::remove_if(int_vec.begin(), int_vec.end(), is_odd()), int_vec.end());

    print_iter(int_vec.begin(), int_vec.end());
    print_vector(int_vec);

}
