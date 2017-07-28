#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using std::vector;
using std::string;

using std::cout;
using std::endl;

typedef string::const_iterator iter;

bool not_url_char(char c)
{
    // 除了数字字母，其他可能出现在url中的字符
    static const string url_ch = "~;/?:@=&$-_.+!*'(),";

    // 看c是否能出现在一个URL中，并返回求反的结果
    return !(isalnum(c) ||
            find(url_ch.begin(), url_ch.end(), c) != url_ch.end());
}

iter url_beg(iter b, iter e)
{
    static const string sep = "://";

    // i标记查找到的sep
    iter i = b;

    while ((i = search(i, e, sep.begin(), sep.end())) != e) {
        // 确保分隔符不是本行唯一的符号
        if (i != b && i + sep.size() != e) {
            iter beg = i;
            while (beg != b && isalpha(beg[-1]))
                beg--;

            // 在分隔符前面及后面至少有一个字符
            if (beg != i && i + sep.size() != e
                && !not_url_char(i[sep.size()]))
                return beg;
        }

        // 找到的分隔符不是一个url一部分
        if (i != e)
            i += sep.size();
    }

    return e;
}

iter url_end(iter b, iter e)
{
    return find_if(b, e, not_url_char);
}

vector<string> find_urls(const string& str)
{
    vector<string> ret;

    iter b = str.begin();
    iter e = str.end();

    while (b != e) {
        // 查找一个或多个紧跟着://的字母
        b = url_beg(b, e);

        if (b != e) {
            // 查找URL剩余部分
            iter after = url_end(b, e);

            // 保存url
            ret.push_back(string(b, after));

            b = after;
        }
    }

    return ret;
}

