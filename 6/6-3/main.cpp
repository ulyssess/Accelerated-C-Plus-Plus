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
    list<int> l;

    cout << "u = " << endl;
    for (iter = u.begin(); iter != u.end(); iter++) {
        cout << *iter << endl;
    }

    //copy(u.begin(), u.end(), v);

    // 这里的v.begin()中元素是空的，没法进行复制
    //copy(u.begin(), u.end(), v.begin());

    // vector没有push_front方法，所以也不能用
    //copy(u.begin(), u.end(), std::front_inserter(v));

    // list有push_front方法
    copy(u.begin(), u.end(), std::front_inserter(l));

    copy(u.begin(), u.end(), std::back_inserter(v));

    cout << endl << "v = " << endl;
    for (iter = v.begin(); iter != v.end(); iter++) {
        cout << *iter << endl;
    }

    return 0;
}
