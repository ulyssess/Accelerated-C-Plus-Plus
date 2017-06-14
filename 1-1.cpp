#include <iostream>
#include <string>

int main()
{
    const std::string hello = "Hello";
    const std::string message = hello + ", world" + "!";
    const std::string another_message = ", world" + "!" + hello;

    return 0;
}
