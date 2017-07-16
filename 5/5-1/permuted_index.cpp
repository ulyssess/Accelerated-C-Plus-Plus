#include <iostream>
#include <string>
#include <list>

using std::string;
using std::list;

struct word {
    int flag;   // 是否被移动过
    string w;   // 一个单词
};

int main()
{
    // 读入将被置换的行 还需要进行split，可以用之前写的代码
    
    // 循环处理每一行
        // 进行轮转,产生新的集合 list应该会比较适合这种情况
        // 
        // 同时记录当前单词是否被移动过
        // 
        // 用list将每行集中起来list<list<struct word>>
        // 
        list<list<struct word>> lines;
    
    
    // 针对每行第一个单词进行排序 需要重新实现compare
    
    // 反向循环处理每一行,将被轮转过的记录到A区，没有轮转过的记录到B区

    // 将AB区进行横向合并

    return 0;
}
