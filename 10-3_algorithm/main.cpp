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

bool is_odd2(int i) {
    return i % 2 == 1;
}

struct is_odd3 {
    int remove_count;
    bool operator() (int i) {
        if (remove_count >= 3) return false;
        else {
            remove_count++;
            return i % 2 == 1;
        }
    }
};

struct is_odd4 {
    int* remove_count;
    is_odd4(int* remove_count) : remove_count(remove_count) {}
    bool operator() (int i) {
        if (*remove_count >= 3) return false;
        else {
            (*remove_count)++;
            return i % 2 == 1;
        }
    }
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


    int remove_count = 0;
    int_vec.erase(std::remove_if(int_vec.begin(), int_vec.end(), [&remove_count](int i) -> bool {
                      if (remove_count >= 3) {
                          return false;
                      } else {
                          remove_count++;
                          return i % 2 == 1;
                      }
                  }), int_vec.end());

    print_iter(int_vec.begin(), int_vec.end()); //42123

    std::vector<int> int_vec2(6, 0);//6칸의 벡터를 0으로 초기화.

    //transform (시작, 끝, 저장할 컨테이너의 시작 반복자, Predicate)
    std::transform(int_vec.begin(), int_vec.end(), int_vec2.begin(), [](int i) { return i + 1; });

    print_iter(int_vec.begin(), int_vec.end()); //42123

    print_iter(int_vec2.begin(), int_vec2.end()); //532340
}
