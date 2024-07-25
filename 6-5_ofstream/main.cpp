#include <fstream>
#include <iostream>
#include <string>

class Human {
    std::string name;
    int age;
public:
    Human(std::string name, int age) : name(name), age(age) {}
    std::string info_string() {
        return "이름 : " + name + " // 나이 : " + std::to_string(age);
    }
    friend std::ofstream& operator<<(std::ofstream& o, Human& h);
};

std::ofstream& operator<<(std::ofstream& o, Human& h) {
    o << h.info_string();
    return o;
}

int main()
{
    //적는 부분
    std::ofstream out("test.txt");
    Human h("정채훈", 28);
    out << h << std::endl;



    //읽어들이는 부분
    std::ifstream in;
    std::string s;
    in.open("test.txt");
    if(in.is_open()){
        getline(in, s);
        std::cout << s << std::endl;
    }
    in.close();

    return 0;
}
