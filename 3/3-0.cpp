#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <vector>

// 搞个别名
using std::cin;
using std::cout;
using std::endl;
using std::setprecision;

using std::sort;
using std::streamsize;
using std::string;
using std::vector;

int main()
{
    // 请求输入并读入学生的姓名
    cout << "Please input your first name: ";
    string name;
    cin >> name;
    cout << "Hello, " << name << "!" << endl;

    // 请求输入并读入期中和期末成绩
    cout << "Please enter your midterm and finl exam grades: ";
    double midterm, final;

    // 这里可以同时读取两个double，中间用空格隔开或者使用enter
    // 输多了就会被用于下一次cin的调用
    // 如果输入的不是数字，那么就会造成cin变为NULL
    if (! (cin >> midterm >> final)) {
        cout << "cin is error" << endl;
        return -1;
    }

    cout << "midterm is " << midterm << endl << "final is " << final << endl;
    
    // 请求输入家庭作业成绩
    cout << "Enter all your homework grades, "
            "followed by end-of-file: ";

    // 这里使用了向量vector, 类型为double
    vector<double> homework;
    double x;

    // 不变式: homework包含了所有的家庭作业成绩
    while (cin >> x)
        homework.push_back(x);

    // 检查homework是否为空
    // 这里把vec_sz定义为vector<double>::size_type的替代名
    typedef vector<double>::size_type vec_sz;
    vec_sz size = homework.size();
    if (size == 0) {
        cout << endl << "you must enter your grades."
                    << "Please try again." << endl;
        return 1;
    }

    // 对成绩排序
    sort(homework.begin(), homework.end());

    // 计算家庭作业的中值
    vec_sz mid = size / 2;
    double median;
    median = (size % 2 == 0) ? (homework[mid] + homework[mid -1]) / 2 : homework[mid];

    // 计算并输出总成绩
    streamsize prec = cout.precision();
    cout << "Your final grade is " << setprecision(3)
        << 0.2 * midterm + 0.4 * final + 0.4 * median
        << setprecision(prec) << endl;

    return 0;
}
