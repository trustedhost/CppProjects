#include <iostream>

template <typename T>
void show_value(T t) {
    if constexpr (std::is_pointer_v<T>) {
        std::cout << *t << std::endl;
    } else {
        std::cout << t << std::endl;
    }
}
int main()
{
    int i = 10;
    int* p = &i;

    show_value(i);
    show_value(p);

    return 0;
}
