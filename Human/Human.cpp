#include "Human.h"

void Human::show_age()
{
    std::cout << "AGE :: " << age << std::endl;
}

void Human::show_name()
{
    std::cout << "Name :: " << name << std::endl;
}

Human::Human() : age{0}, name{""} {};
Human::Human(int _age, std::string _name) : age{_age}, name{_name} {
    std::cout << name  << " was born\n";
};
Human::~Human() {
    std::cout << name << " died\n";
}