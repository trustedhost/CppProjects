#include <iostream>
#include <vector>

class A : public std::enable_shared_from_this<A> {
    int i;
    std::weak_ptr<A> other;
public:
    A(int k = 1) {
        std::cout << "일반 생성자 호출!" <<  std::endl;
        i = k;
    }
    A(const A& a) {
        std::cout << "복사 생성자 호출! " <<  std::endl;
    }
    ~A() = default;
    std::shared_ptr<A> get_shared_ptr() {
        return shared_from_this();
    }
    void set_other(std::weak_ptr<A> ptr) {
        other = ptr;
    }
    void access_other() {
        std::shared_ptr<A> o = other.lock();
        if (o) {
            std::cout << (o->get_number()) << std::endl;
        } else {
            std::cout << "it's gone.." << std::endl;
        }
    }
    int get_number() {
        return i;
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

    std::vector<std::shared_ptr<A>> vec2;
    vec2.push_back(std::shared_ptr<A>(new A(1)));
    vec2.push_back(std::shared_ptr<A>(new A(2)));

    std::cout << vec2[0]->get_number() << std::endl;
    std::cout << vec2[1]->get_number() << std::endl;

    vec2[0]->set_other(vec2[1]);
    vec2[1]->set_other(vec2[0]);

    vec2[0]->access_other();
    vec2[1]->access_other();

    vec2.pop_back();
    vec2[0]->access_other();

}
