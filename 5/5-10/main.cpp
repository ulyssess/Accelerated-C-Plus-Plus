#include <string>
#include <vector>
#include <cctype>
#include <iostream>

using std::vector;
using std::string;

using std::cin;
using std::cout;
using std::endl;

bool is_palindrome(const string& s)
{
    string::const_iterator iter = s.begin();

    for (string::const_reverse_iterator citer = s.rbegin();
            citer != s.rend(); citer++, iter++) {
        if (*citer != *iter)
            return false;
    }

    return true;
}

string max_width_palindrome(const vector<string>& v)
{
    string::size_type maxlen = 0;
    vector<string>::const_iterator tmp;
    vector<string>::const_iterator iter;

    for (iter = v.begin(); iter != v.end(); iter++) {
        if (iter->size() > maxlen && is_palindrome(*iter)) {
            maxlen = iter->size();
            tmp = iter;
        }
    }

    return *tmp;
}

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

        // 输出v中的每一个回文
        for (vector<string>::size_type i = 0; i != v.size(); i++) {
            if (is_palindrome(v[i]))
                cout << v[i] << endl;
        }

        cout << "max len palindrome" << endl;

        cout << max_width_palindrome(v) << endl;
    }

    return 0;
}
