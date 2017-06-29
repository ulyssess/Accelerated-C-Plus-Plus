#include <string>
#include <algorithm>

using std::string;
using std::max;

int main()
{
    int maxlen;
    string s;
    string::size_type other_type_maxlen;
    // 这里max只能接受相同类型的参数做比较
    max(s.size(), maxlen);

    max(s.size(), s.size());
    max(maxlen, maxlen);

    max(s.size(), other_type_maxlen);
}
