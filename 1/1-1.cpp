#include <iostream>
#include <string>

// 这个程序说明了+运算的左结合律是自左向右
// 还有就是字符串常量或者char类型之间不可以相加

int main()
{
    const std::string hello = "Hello";
    const std::string message = hello + ", world" + "!";
    const std::string another_message = ", world" + "!" + hello;

    return 0;
}
