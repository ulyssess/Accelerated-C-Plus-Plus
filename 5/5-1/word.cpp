#include <iostream>
#include <string.h>

#include "word.h"

using std::list;
using std::string;
using std::istream;

list<word> splitString(string& s)
{
    list<word> ret;
    typedef string::size_type size_type;

    size_type i = 0;

    while (i != s.size()) {
        // 忽略前面的空格
        while (i != s.size() && isspace(s[i]))
            i++;
    
        // 获取单词的终结点
        size_type j = i;
        while (j != s.size() && !isspace(s[j]))
            j++;

        // 找到了非空白字符
        if (i != j) {
            word w;
            w.w = s.substr(i, j - i);
            ret.push_back(w);
            i = j;
        }
    }

    return ret;
}

list<list<word>> readWords(istream& in)
{
    string s;
    list<list<word>> lines;

    // 读取并分割每一行输入
    while (getline(in, s)) {
        list<word> line = splitString(s);
        lines.push_back(line);
    }

    return lines;
}
