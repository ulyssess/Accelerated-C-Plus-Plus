
#include <string>
#include <vector>
#include <iostream>

#include "Student_info.h"
#include "grade.h"

using std::vector;
using std::istream;

using std::cout;
using std::endl;

bool compare(const Student_info& x, const Student_info& y)
{
    return x.name < y.name;
}

istream& read_hw(istream& in, vector<double>& hw)
{
    if (in) {
        // 清除原先的内容
        hw.clear();

        // 读取家庭作业成绩
        double x;
        while (in >> x) {
            hw.push_back(x);
        }

        // 清除流，以便是的输入动作对下一个学生有效
        in.clear();
    }

    return in;
}

istream& read(istream& is, Student_info& s)
{
    double midterm;
    double final;
    vector<double> homework;

    // 读入并存储学生的姓名以及期中、期末考试的成绩
    is >> s.name >> midterm >> final;

    read_hw(is, homework);

    if (homework.size() == 0) {
        return is;
    }

    s.final_grade = grade(midterm, final, homework);

    return is;
}
