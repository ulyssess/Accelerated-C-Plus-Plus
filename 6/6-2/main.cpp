#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include "find_urls.h"

using std::vector;
using std::string;

using std::cout;
using std::endl;

void show_vector_string(const vector<string>& v)
{
    vector<string>::const_iterator iter;
    for (iter = v.begin(); iter != v.end(); iter++) {
            cout << *iter << endl;
    }
}

bool test(const string& src, const vector<string>& dst)
{
    vector<string> result;

    result = find_urls(src);

    if (result == dst)
        return true;

    cout << "one test error " << endl;
    cout << "src = [" << src << "]" << endl;

    cout << "dst =" << endl;
    show_vector_string(dst);

    cout << "result =" << endl;
    show_vector_string(result);

    cout << endl;

    return false;
}

void test_normal()
{
    vector<string> dst;

    string src("http://www.baidu.com");

    dst.push_back("http://www.baidu.com");

    test(src, dst);
}

void test_url_beg()
{
    vector<string> dst;

    string src("://www.taobao.com ://www.alibaba.com  a://www.alibab.com 1://www.alibaba.com");

    dst.push_back("a://www.alibab.com");

    test(src, dst);
}

void test_url_end()
{
    vector<string> dst;

    string src("://http:// http://> http://&");

    dst.push_back("http://&");

    test(src, dst);
}

int main()
{
    test_normal();

    test_url_beg();

    test_url_end();
    
    return 0;
}
