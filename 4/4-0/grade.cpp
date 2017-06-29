#include <vector>
#include <stdexcept>

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


/*
int main()
{
    // 请求并读入学生姓名
    cout << "Please enter your first name: ";
    string name;
    cin >> name;
    cout << "Hello, " << name << "!" << endl;

    // 请求输入期中和期末考试的成绩
    cout << "Please enter your midterm and final exam grades: ";
    double midterm, final;
    cin >> midterm >> final;

    // 请求用户输入家庭作业成绩
    cout << "Enter all your homework grades, "
            "followed by end-of-file: ";

    vector<double> homework;
    // 读入家庭作业成绩
    read_hw(cin, homework);

    // 如果可以的话，计算总成绩
    try {
        double final_grade = grade(midterm, final, homework);
        streamsize prec = cout.precision();
        cout << "Your final grade is " << setprecision(3)
             << final_grade << setprecision(prec) << endl;
    } catch (domain_error) {
        cout << endl << "You must enter your grades. "
             << "Please try again." << endl;
        return 1;
    }

    return 0;
}
*/
