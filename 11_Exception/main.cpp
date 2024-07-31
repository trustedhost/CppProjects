#include <iostream>

using namespace std;

class Resource {
    int num;
public:
    Resource(int num = 1) : num(num) {
        std::cout << "생성자 실행" << std::endl;
    }
    ~Resource() {
        std::cout << "소멸자 실행" << std::endl;
    }
};

class Manager {
    std::unique_ptr<Resource> resource;

public:
    explicit Manager() {
        resource = std::make_unique<Resource>();
        if (true) {
            throw std::out_of_range("exception!!");
        }
    }
};

int main()
{
    try {
        Manager m;
    } catch (std::out_of_range& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
