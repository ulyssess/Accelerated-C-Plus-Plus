#include "extract.h"

#include <list>

using std::vector;
using std::list;

bool fgrade(const Student_info& s)
{
    return s.final_grade < 60;
}

vector<Student_info> extract_fails_1(vector<Student_info>& students)
{
    vector<Student_info> pass, fail;

    for (vector<Student_info>::size_type i = 0; i != students.size(); i++) {
        if (fgrade(students[i])) {
            fail.push_back(students[i]);
        } else {
            pass.push_back(students[i]);
        }
    }

    students = pass;

    return fail;
}

vector<Student_info> extract_fails_2(vector<Student_info>& students)
{
    vector<Student_info> fail;
    vector<Student_info>::size_type i = 0;

    /* 这里也需要注意，不能够预先获取size，需要每次重新获取才行 */
    while (i != students.size()) {
        if (fgrade(students[i])) {
            fail.push_back(students[i]);
            /* 这里删除了之后，后面的元素会复制过来，把空缺填上
             * 所以在这里i不能++
             * */
            students.erase(students.begin() + i);
        } else {
            i++;
        }
    }

    return fail;
}

vector<Student_info> extract_fails_3(vector<Student_info>& students)
{
    vector<Student_info> fail;
    vector<Student_info>::iterator iter = students.begin();

    while (iter != students.end()) {
        if (fgrade(*iter)) {
            fail.push_back(*iter);
            iter = students.erase(iter);
        } else {
            iter++;
        }
    }

    return fail;
}

list<Student_info> extract_fails(list<Student_info>& students)
{
    list<Student_info> fail;
    list<Student_info>::iterator iter = students.begin();

    while (iter != students.end()) {
        if (fgrade(*iter)) {
            fail.push_back(*iter);
            iter = students.erase(iter);
        } else {
            iter++;
        }
    }

    return fail;
}
