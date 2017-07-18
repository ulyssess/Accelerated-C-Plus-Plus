#include <ios>
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <list>

#include "Student_info.h"
#include "extract.h"

using std::cin;
using std::cout;
using std::endl;

using std::max;
using std::setw;

using std::string;
using std::vector;
using std::list;
using std::sort;
using std::domain_error;
using std::istream;
using std::streamsize;
using std::setprecision;

int main()
{
    list<Student_info> students;
    list<Student_info> failStudents;
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
    students.sort(compare);

    // 提取fail的学生
    failStudents = extract_fails(students);

    return 0;
}
