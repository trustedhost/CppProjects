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


    std::transform(container.begin(), container.end(), size_vec.begin(), [](const auto &v)->int { return v.size();});
    for (auto itr = size_vec.begin(); itr < size_vec.end(); itr++ ){
        std::cout << *itr << std::endl;
    }

}
