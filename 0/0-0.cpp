// A small C++ program
#include <iostream>

int main()
{
    std::cout << sizeof(std::cout) << std::endl;
    std::cout << sizeof(std::cout << "Hello World!" << std::endl) << std::endl;
    return 0;
}
