#include <vector>
#include <string>
#include <cctype>
#include <iostream>

using std::string;
using std::vector;

using std::cout;
using std::endl;

bool parityCheck(const string& s)
{
    int len = 0;

    string::size_type headSpaces = 0;
    string::size_type tailSpaces = 0;

    for (string::const_iterator iter = s.begin(); iter != s.end(); iter++) {
        if (!isspace(*iter))
            break;

        headSpaces++;
    }

    for (string::const_reverse_iterator iter = s.rbegin();
            iter != s.rend(); iter++) {
        if (!isspace(*iter))
            break;

        tailSpaces++;
    }
    
    if (((s.size() - headSpaces - tailSpaces) & 1) == 0)
        return true;

    return false;
}

bool parityCheck(const vector<string>& v)
{
    bool parity;

    parity = parityCheck(*v.begin());

    // 判断每行除去前后空格后的字符长度奇偶性是否一致
    for (vector<string>::const_iterator iter = v.begin();
            iter != v.end(); iter++) {
        if (parity != parityCheck(*iter))
            return false;
    }

    return true;
}

string::size_type width(const vector<string>& v)
{
    string::size_type maxlen = 0;
    vector<string>::const_iterator iter;

    for (iter = v.begin(); iter != v.end(); iter++) {
        if (iter->size() > maxlen)
            maxlen = iter->size();
    }

    return maxlen;
}

vector<string> center(const vector<string>& v)
{
    vector<string> ret;

    if (v.empty())
        return ret;

    if (parityCheck(v) == false) {
        cout << "not parity picture" << endl;
        return ret;
    }

    // 获取最大值
    string::size_type maxlen = width(v);

    // 循环，并前后进行空格补充
    for (vector<string>::const_iterator iter = v.begin();
            iter != v.end(); iter++) {

        string new_s;
        string::size_type spaceSize = (maxlen - iter->size()) / 2;

        new_s += string(spaceSize, ' ');
        new_s += *iter;
        new_s+= string(spaceSize, ' ');
        ret.push_back(new_s);
    }

    return ret;
}

int main()
{
    vector<string> v;

    v.push_back("*");
    v.push_back("***");
    v.push_back("*****");

    vector<string> new_v = center(v);

    for (vector<string>::const_iterator iter = new_v.begin();
            iter != new_v.end(); iter++) {
        cout << *iter << endl;
    }

    return 0;
}
