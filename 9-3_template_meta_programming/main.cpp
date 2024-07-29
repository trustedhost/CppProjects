#include <iostream>

template <typename T, unsigned int N>
class Array {
    T data[N];
public:
    Array(T (&arr)[N]) {
        for (int i = 0; i < N ; i++) {
            data[i] = arr[i];
        }
    }
    T* get_array() {
        return data;
    }
    unsigned int size() {
        return N;
    }
    void print_all() {
        for(int i = 0; i < N; i++) {
            std::cout << data[i] << std::endl;
        }
        std::cout << std::endl;
    }
};

int main()
{
    int arr[3] = {0, 2, 4};
    Array<int, 3> tem_arr(arr);
    tem_arr.print_all();
    std::cout << (typeid(Array<int, 3>) == typeid(Array<int, 3>)) << std::endl;
    return 0;
}
