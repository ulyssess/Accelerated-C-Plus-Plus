#include <iostream>
#include <string>

// is >> s 会将s覆盖掉

int main()
{
    std::cout << "What is your name?";
    std:: string name;
    std::cin >> name;
    std::cout << "Hello, " << name
        << std::endl << "And what is yours?";

    std::cin >> name;
    std::cout << "Hello, " << name
        << "; nice to meet you too!" << std::endl;

    return 0;
}
 
