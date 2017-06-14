#include <iostream>
#include <string>

// 这个就是生存周期的问题
// 遇到}后，x已经被销毁了

int main()
{
    { std::string s = "a string";
    { std::string x = s + ", really";
      std::cout << s << std::endl; }
      std::cout << x << std::endl; // x is out of its scope here
    }

    return 0;
}
