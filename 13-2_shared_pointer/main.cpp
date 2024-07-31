#include <iostream>
#include <vector>

class A : public std::enable_shared_from_this<A> {
    int i;
public:
    A(int i = 1) {
        std::cout << "일반 생성자 호출!" <<  std::endl;
    }
    A(const A& a) {
        std::cout << "복사 생성자 호출! " <<  std::endl;
    }
    ~A() = default;
    std::shared_ptr<A> get_shared_ptr() {
        return shared_from_this();
    }
};


int main()
{
    std::vector<std::shared_ptr<A>> vec;
    std::shared_ptr<A> ptr = std::make_shared<A>();
    std::shared_ptr<A> ptr2 = std::shared_ptr(ptr->get_shared_ptr());
    vec.push_back(ptr2);


}
