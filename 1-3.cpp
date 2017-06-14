#include <iostream>
#include <string>

// 这个程序主要体现了局部变量的作用域和生存周期的情况
// 1. 作用域是在花括号之间，而不是函数
// 2. 函数中，花括号内部是可以使用外部定义的变量
// 3. 函数中，花括号内部可以定义与外部同名的变量，而且这时候将会覆盖外部变量
// 4. 当到了}时，局部变量就会被释放掉, 会调用析构函数

int main()
{
    const std::string s = "0 string";

    std::cout << s << std::endl;

    { std::cout << s << std::endl;
      const std::string s = "a string";
      std::cout << s << std::endl; }

    { const std::string s = "another string";
      std::cout << s << std::endl; }

    return 0;
}
