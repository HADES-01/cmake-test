#include <string>
#include <iostream>

class Human {
    int age;
    std::string name;

    public:
    Human();
    Human(int _age, std::string _name);
    ~Human();
    void show_age();
    void show_name();
};