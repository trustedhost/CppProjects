#ifndef MYSTRING_H
#define MYSTRING_H
#include <iostream>

class MyString
{
    char* string_content;
    int memory_capacity;
    int string_length;
public:
    MyString();
    //문자열로부터 생성
    MyString(const char *str);
    //복사생성자
    MyString(const MyString &str);
    //이동생성자
    MyString(MyString&& str);
    //일반적인 대입연산자
    MyString& operator=(const MyString& s);
    //이동 대입연산자
    MyString& operator=(MyString&& s);

    ~MyString();
    int length() const;
    void println();

};

#endif // MYSTRING_H
