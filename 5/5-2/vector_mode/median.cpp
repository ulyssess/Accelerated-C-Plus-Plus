#include <vector>
#include <algorithm>
#include <stdexcept>

using std::vector;
using std::sort;
using std::domain_error;

// 这里的vec会将参数进行复制，在函数内部对vec的操作不会影响参数原本的值
double median(vector<double> vec)
{
    typedef vector<double>::size_type vec_sz;

    vec_sz size = vec.size();
    if (size == 0)
        throw domain_error("median of an empty vector");

    sort(vec.begin(), vec.end());

    vec_sz mid = size/2;

    return size % 2 == 0? (vec[mid] + vec[mid - 1])/2 : vec[mid]; 
}
