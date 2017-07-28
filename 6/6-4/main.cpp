#include <iostream>
#include <string>
#include <vector>
#include <list>

using std::vector;
using std::string;
using std::list;

using std::cout;
using std::endl;

int main()
{
    vector<string> rv;
    vector<int>::const_iterator iter;

    vector<int> u(10, 100);
    vector<int> v;

    cout << "u = " << endl;
    for (iter = u.begin(); iter != u.end(); iter++) {
        cout << *iter << endl;
    }

#if 1
    // 这种方式需要事先把v初始化一下
    v.resize(u.size());
    copy(u.begin(), u.end(), v.begin());
#else
    // 这种方式比较好，v的长度会自动的变长
    copy(u.begin(), u.end(), std::back_inserter(v));
#endif

    cout << endl << "v = " << endl;
    for (iter = v.begin(); iter != v.end(); iter++) {
        cout << *iter << endl;
    }

    return 0;
}
