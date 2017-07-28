#include <vector>
#include <stdexcept>
#include <algorithm>
#include <numeric>

#include "grade.h"
#include "median.h"

using std::vector;
using std::domain_error;

double grade(const Student_info& s)
{
    return grade(s.midterm, s.final, s.homework);
}

// 这里的hw使用的是引用的方式，代表不需复制，直接操作原来的值
// 同时const又限定了，我们不能再函数内部对其进行修改
// 两个grade函数名称相同，但是参数不同，这就是重载
double grade(double midterm, double final, const vector<double>& hw)
{
    // 虽然median函数也会判断size，但是它给出的提示信息和现在的业务没有关系
    // 所以需要在这里根据业务判断size，给出有用的提示
    if (hw.size() == 0)
        throw domain_error("student has done no homework");

    return grade(midterm, final, median(hw));
}

double grade(double midterm, double final, double homework) 
{
    return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

double average(const vector<double>& v)
{
    return accumulate(v.begin(), v.end(), 0.0) / v.size();
}

double grade_aux(const Student_info& s)
{
    try {
        return grade(s);
    } catch (domain_error) {
        return grade(s.midterm, s.final, 0);
    }
}

double average_grade(const Student_info& s)
{
    return grade(s.midterm, s.final, average(s.homework));
}

double optimistic_median(const Student_info& s)
{
    vector<double> nonzero;

    remove_copy(s.homework.begin(), s.homework.end(), back_inserter(nonzero), 0);

    if (nonzero.empty()) {
        return grade(s.midterm, s.final, 0.0);
    } else {
        return grade(s.midterm, s.final, median(nonzero));
    }
}
