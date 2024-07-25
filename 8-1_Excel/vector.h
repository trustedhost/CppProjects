#ifndef VECTOR_H
#define VECTOR_H
#include <string>

using std::string;
class Vector
{
    string* data;
    int capacity;
    int length;

public:
    Vector(int n = 0);
    //맨 뒤에 원소를 추가한다.
    void push_back(string s);
    //임의의 위치의 원소에 접근한다.
    string operator[](int index);
    //index 위치의 원소를 제거한다.
    void remove(int index);
    //현재 vector 의 크기를 반환한다.
    int size();
    ~Vector();

};

#endif // VECTOR_H
