#include <ios>
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>


using std::cin;
using std::cout;
using std::endl;

using std::string;
using std::vector;
using std::sort;
using std::domain_error;
using std::istream;
using std::streamsize;
using std::setprecision;


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

double grade(double midterm, double final, double homework) 
{
    return 0.2 * midterm + 0.4 * final + 0.4 * homework;
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

istream& read_hw(istream& in, vector<double>& hw)
{
    if (in) {
        // 清除原先的内容
        hw.clear();

        // 读取家庭作业成绩
        double x;
        while (in >> x)
            hw.push_back(x);

        // 清除流，以便是的输入动作对下一个学生有效
        in.clear();
    }

    return in;
}

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
