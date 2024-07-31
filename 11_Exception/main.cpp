#include <iostream>

using namespace std;

class Resource {
    int num;
public:
    explicit Resource(int num) : num(num) {
        std::cout << "생성자 실행" << std::endl;
    }
    ~Resource() {
        std::cout << "소멸자 실행" << std::endl;
    }
};

class Manager {
    Resource *resource;

public:
    explicit Manager() {
        resource = new Resource(1);
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
