#include <iostream>

int main()
{
    int number = 1;

    for (int i = 1; i < 10; i++) {
        number *= i;
        std::cout << number << std::endl;
    }
}
