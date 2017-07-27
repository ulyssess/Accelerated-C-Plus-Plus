#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

using std::cout;
using std::endl;

vector<string> vcat(const vector<string>& top, const vector<string>& bottom)
{
    vector<string> ret = top;

    // 循环插入
    //for (vector<string>::const_iterator iter = bottom.begin();
    //        iter != bottom.end(); iter++) {
    //    ret.push_back(*iter);
    //}

    // insert插入
    //ret.insert(ret.end(), bottom.begin(), bottom.end());

    // copy添加
    // 最后面这个参数需要提供迭代器，而且迭代器还需要有元素
    // copy会将bottom的元素拷贝至第三个参数指向的元素
    copy(bottom.begin(), bottom.end(), back_inserter(ret));

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

    rv = vcat(v, v1);

    vector<string>::const_iterator iter;
    for (iter = rv.begin(); iter != rv.end(); iter++) {
        cout << *iter << endl;
    }
}
