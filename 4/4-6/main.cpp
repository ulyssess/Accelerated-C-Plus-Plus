#include <ios>
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <stdexcept>

#include "Student_info.h"

using std::cin;
using std::cout;
using std::endl;

using std::max;
using std::setw;

using std::string;
using std::vector;
using std::sort;
using std::domain_error;
using std::istream;
using std::streamsize;
using std::setprecision;

int main()
{
    vector<Student_info> students;
    Student_info record;
    string::size_type maxlen = 0;

    // 读取并存储所有的记录，然后找出最长的姓名的长度
    try {
        while (read(cin, record)) {
            maxlen = max(maxlen, record.name.size());
            students.push_back(record);
        }
    } catch (domain_error e) {
        cout << e.what() << endl;
    }

    // 按字母顺序排序记录
    sort(students.begin(), students.end(), compare);

    for (vector<Student_info>::size_type i = 0; i != students.size(); i++) {
        // 输出姓名，设置宽度用空格进行填充
        cout << setw(maxlen + 1) << students[i].name;

        // 计算并输出成绩
        streamsize prec = cout.precision();
        cout << setprecision(3) << "   " << students[i].final_grade
            << setprecision(prec);

        cout << endl;
    }

    return 0;
}
