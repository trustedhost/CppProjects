#include "mystring.h"



MyString::MyString()
{
    string_content = NULL;
    memory_capacity = 0;
    string_length = 0;
    std::cout << "생성자 호출" << std::endl;
}

MyString::MyString(const char *str)
{
    std::cout << "char 생성자 호출" << std::endl;
    string_length = strlen(str);
    if (memory_capacity <= string_length){
        memory_capacity = string_length * 2;
    }
    string_content = new char[memory_capacity];
    for (int i = 0; i < string_length; i++){
        string_content[i] = str[i];
    }
}

MyString::MyString(const MyString &str)
{
    std::cout << "복사 생성자 호출" << std::endl;
    if (memory_capacity <= str.string_length) {
        memory_capacity = str.string_length * 2;
    }
    string_content = new char[memory_capacity];
    for (int i = 0; i < string_length; i++) {
        string_content[i] = str.string_content[i];
    }
}

MyString::MyString(MyString &&str)
{
    std::cout << "이동 생성자 호출" << std::endl;
    string_length = str.string_length;
    string_content = str.string_content;
    memory_capacity = str.memory_capacity;

    str.string_length = 0;
    str.string_content = nullptr;
    str.memory_capacity = 0;
}

MyString& MyString::operator=(const MyString& s) {
    std::cout << "복사 호출" << std::endl;
    if (memory_capacity <= s.string_length) {
        delete[] string_content;
        string_content = new char[s.string_length];
        memory_capacity = s.string_length;
    }
    string_length = s.string_length;
    for (int i = 0; i < string_length; i++) {
        string_content[i] = s.string_content[i];
    }
    return *this;
}
MyString& MyString::operator=(MyString&& s) {
    std::cout << "이동 호출" << std::endl;
    string_length = s.string_length;
    string_content = s.string_content;
    memory_capacity = s.memory_capacity;

    s.string_length = 0;
    s.string_content = nullptr;
    s.memory_capacity = 0;
    return *this;
}

MyString::~MyString()
{
    if (string_content) delete[] string_content;
}

int MyString::length() const
{
    return string_length;
}

void MyString::println()
{
    for (int i = 0; i < string_length; i++) {
        std::cout << string_content[i];
    }
    std::cout << std::endl;
}


