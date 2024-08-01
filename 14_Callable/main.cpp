#include <iostream>
#include <vector>

int main()
{
    std::vector<int> a(1);
    std::vector<int> b(2);
    std::vector<int> c(3);
    std::vector<int> d(4);
    std::vector<int> e(5);


    std::vector<std::vector<int>> container;
    container.push_back(a);
    container.push_back(b);
    container.push_back(c);
    container.push_back(d);
    container.push_back(e);


    std::vector<int> size_vec(container.size());

    struct func {
        int operator() (const std::vector<int>& vec) const {
            return vec.size();
        }
    };

    // std::transform(container.begin(), container.end(), size_vec.begin(), [](const auto &v)->int { return v.size();});
    // std::transform(container.begin(), container.end(), size_vec.begin(),func());

    // 멤버함수의 경우 객체에 먼저 접근해서 함수포인터를 끌어와야 한다.
    // std::transform(container.begin(), container.end(), size_vec.begin(), &std::vector<int>::size ); (X) 잘못된 접근.
    std::function<int(const std::vector<int>& vec)> size_func = &std::vector<int>::size;
    // std::transform(container.begin(), container.end(), size_vec.begin(), size_func);

    std::transform(container.begin(), container.end(), size_vec.begin(), std::mem_fn(&std::vector<int>::size));

    for (auto itr = size_vec.begin(); itr < size_vec.end(); itr++ ){
        std::cout << *itr << std::endl;
    }

}
