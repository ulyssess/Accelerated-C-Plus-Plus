#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using std::vector;
using std::string;

using std::cout;
using std::endl;

bool space(char c)
{
    return isspace(c);
}

bool not_space(char c)
{
    return !isspace(c);
}

vector<string> split(const string& str)
{
    vector<string> ret;
    typedef string::const_iterator iter;

    iter i = str.begin();
    while (i != str.end()) {
        // 忽略前端空白
        i = find_if(i, str.end(), not_space);

        // 查找单词尾部
        iter j = find_if(i, str.end(), space);

        // 复制单词
        if (i != str.end()) {
            ret.push_back(string(i, j));
        }

        i = j;
    }

    return ret;
}

bool is_palindrome(const string& s)
{
    return equal(s.begin(), s.end(), s.rbegin());
}

int main()
{
    vector<string> v;
    string str("Life is keep and wait! eye level ");
    vector<string>::const_iterator iter;

    v = split(str);

    for (iter = v.begin(); iter != v.end(); iter++) {
        if (is_palindrome(*iter)) {
            cout << *iter << endl;
        }
    }
}
