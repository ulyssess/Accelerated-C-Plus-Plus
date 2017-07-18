#include <vector>
#include <stdexcept>

#include "grade.h"
#include "median.h"

using std::vector;
using std::domain_error;

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
