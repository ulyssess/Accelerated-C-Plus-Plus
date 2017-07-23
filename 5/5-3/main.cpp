#include <ios>
#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <stdexcept>

#include "Student_info.h"
#include "extract.h"

using std::cin;
using std::cout;
using std::endl;

using std::max;
using std::setw;

using std::string;
using std::sort;
using std::domain_error;
using std::istream;
using std::streamsize;
using std::setprecision;

int main()
{
    sinfo students;
    sinfo failStudents;
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

    // 提取fail的学生
    failStudents = extract_fails(students);
    
    for (sinfo::iterator iter = students.begin(); iter != students.end(); iter++) {
        // 输出姓名，设置宽度用空格进行填充
        cout << setw(maxlen + 1) << iter->name;

        // 计算并输出成绩
        streamsize prec = cout.precision();
        cout << setprecision(3) << "   " << iter->final_grade
            << setprecision(prec);

        cout << endl;
    }

    return 0;
}
