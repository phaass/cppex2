

#include <string>
#include <iostream>

int main()
{
    std::cout << "Enter your full name: ";
    std::string name;
    std::cin >> name; // this won't work as expected since std::cin breaks on whitespace

    std::cout << "Enter your age: ";
    std::string age;
    std::cin >> age;

    std::cout << "Your name is " << name << " and your age is " << age;
}