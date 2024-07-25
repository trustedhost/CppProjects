#include <iostream>

class Parent {
private:
    virtual void printlala() = 0;
 public:
  Parent() { std::cout << "Parent 생성자 호출" << std::endl; }
  virtual ~Parent() { std::cout << "Parent 소멸자 호출" << std::endl; }
};
class Child : public Parent {
 public:
  Child() : Parent() { std::cout << "Child 생성자 호출" << std::endl; }
  ~Child() { std::cout << "Child 소멸자 호출" << std::endl; }
  void printlala() override {
      std::cout << "lala" << std::endl;
  }
};
int main() {
    Parent p;
    Child c;
}
