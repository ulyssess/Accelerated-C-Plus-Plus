#include <string>
#include <vector>
#include <map>
#include <iostream>

using std::map;
using std::string;
using std::vector;

using std::istream;
using std::cin;
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

map<string, vector<int> > xref(istream& in,
        vector<string> find_word(const string&) = split)
{
    int line_num = 0;
    string line;
    vector<string> words;
    map<string, vector<int> > ret;

    while (std::getline(in, line)) {
        line_num++;

        words = split(line);

        for (vector<string>::const_iterator iter = words.begin();
                iter != words.end(); iter++) {
            ret[*iter].push_back(line_num);
        }
    }

    return ret;
}

int main()
{
    map<string, vector<int> > ret = xref(cin);

    for (map<string, vector<int> >::const_iterator iter = ret.begin();
            iter != ret.end(); iter++) {
        cout << iter->first << " ";

        vector<int>::const_iterator viter = iter->second.begin();
        cout << *viter++;

        while (viter != iter->second.end()) {
            cout << ", ";
            cout << *viter++;
        }

        cout << endl;
    }

    return 0;
}
