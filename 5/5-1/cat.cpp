#include <iostream>

#include "cat.h"

using std::list;
using std::string;

using std::cout;
using std::endl;

string::size_type width(const list<string>& v)
{
    string::size_type maxlen = 0;
    list<string>::const_iterator iter;

    for (iter = v.begin(); iter != v.end(); iter++) {
        if (iter->size() > maxlen)
            maxlen = iter->size();
    }

    return maxlen;
}

list<string> hcat(const list<string>& left, const list<string>& right)
{
    list<string> ret;
    string::size_type maxlen;

    maxlen = width(left);

    list<string>::const_iterator i = left.begin();
    list<string>::const_iterator j = right.begin();

    while (i != left.end() || j != right.end()) {
        string line;

        // 添加左边
        if (i != left.end()) {
            // 添加Padding
            line += string(maxlen - (*i).size(), ' ');
            line += *i;
            i++;
        } else {
            // 添加Padding
            line += string(maxlen - line.size(), ' ');
        }

        line += "    ";

        // 添加右边
        if (j != right.end()) {
            line += *j;
            j++;
        }

        ret.push_back(line);
    }

    return ret;
}

list<string> vcat(const list<string>& top, const list<string>& bottom)
{
    list<string> ret = top;

    for (list<string>::const_iterator iter = bottom.begin();
            iter != bottom.end(); iter++) {
        ret.push_back(*iter);
    }

    return ret;
}
