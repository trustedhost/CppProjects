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
    std::shared_ptr<A> ptr = std::make_shared<A>(); // +1
    std::shared_ptr<A> ptr2 = ptr->get_shared_ptr(); // +1
    vec.push_back(ptr2); // shared_ptr 을 하나 복사하여 vec 에 저장. +1
    vec.push_back(std::move(ptr2));// 기존 ptr 을 없애고 이동하여 vec 에 저장 . +0


    std::cout << ptr.use_count() << std::endl;


}
