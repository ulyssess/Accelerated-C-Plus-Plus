#include <string>
#include <vector>
#include <cctype>
#include <iostream>

using std::vector;
using std::string;

using std::cin;
using std::cout;
using std::endl;

vector<string> split(string& s)
{
    vector<string> ret;
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
            ret.push_back(s.substr(i, j - i));
            i = j;
        }
    }

    return ret;
}

int main()
{
    string s;

    // 读取并分割每一行输入
    while (getline(cin, s)) {
        vector<string> v = split(s);

        // 输出v中的每一个单词
        for (vector<string>::size_type i = 0; i != v.size(); i++)
            cout << v[i] << endl;
    }

    return 0;
}
