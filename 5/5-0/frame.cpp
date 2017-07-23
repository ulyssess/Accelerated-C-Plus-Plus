#include <iostream>
#include <string>
#include <vector>

using std::vector;
using std::string;

using std::cout;
using std::endl;

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

vector<string> frame(const vector<string>& v)
{
    vector<string> ret;
    string::size_type maxlen;
    vector<string>::const_iterator iter;

    maxlen = width(v);

    string board(maxlen + 4, '*');

    ret.push_back(board);

    for (iter = v.begin(); iter != v.end(); iter++) {
        ret.push_back("* " + *iter + string(maxlen - iter->size(), ' ') + " *");
    }

    ret.push_back(board);

    return ret;
}

vector<string> hcat(const vector<string>& left, const vector<string>& right)
{
    vector<string> ret;
    string::size_type maxlen;

    maxlen = width(left) + 1;

    vector<string>::size_type i = 0, j = 0;

    while (i != left.size() || j != right.size()) {
        string line;

        // 添加左边
        if (i != left.size())
            line = left[i++];

        // 添加Padding
        line += string(maxlen - line.size(), ' ');

        // 添加右边
        if (j != right.size())
            line += right[j++]; 

        ret.push_back(line);
    }

    return ret;
}

vector<string> vcat(const vector<string>& top, const vector<string>& bottom)
{
    vector<string> ret = top;

    for (vector<string>::const_iterator iter = bottom.begin();
            iter != bottom.end(); iter++) {
        ret.push_back(*iter);
    }

    return ret;
}

int main()
{
    vector<string> v;
    v.push_back("Hello");
    v.push_back("World World");
    v.push_back("!");


    vector<string> v1;
    v1.push_back("Hello");
    v1.push_back("Moto");
    v1.push_back("!");
    v1.push_back("!");

    vector<string> rv;

    //rv = frame(v);

    //rv = v;
    //rv.insert(rv.end(), v1.begin(), v1.end());

    //rv = hcat(v, v1);
    rv = vcat(v, v1);

    vector<string>::const_iterator iter;
    for (iter = rv.begin(); iter != rv.end(); iter++) {
        cout << *iter << endl;
    }

    return 0;
}
