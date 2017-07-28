#include "extract.h"

#include <vector>

using std::vector;
using std::vector;

bool fgrade(const Student_info& s)
{
    return s.final_grade < 60;
}

bool pgrade(const Student_info& s)
{
    return !fgrade(s);
}

//vector<Student_info> extract_fails(vector<Student_info>& students)
//{
//    vector<Student_info> fail;
//    vector<Student_info>::iterator iter = students.begin();
//
//    while (iter != students.end()) {
//        if (fgrade(*iter)) {
//            fail.push_back(*iter);
//            iter = students.erase(iter);
//        } else {
//            iter++;
//        }
//    }
//
//    return fail;
//}

//vector<Student_info> extract_fails(vector<Student_info>& students)
//{
//    vector<Student_info> fail;
//
//    // 如果元素符合pgrade则跳过，其他的拷贝到fail
//    remove_copy_if(students.begin(), students.end(), back_inserter(fail), pgrade);
//
//    // 删除students中fail的记录
//    // remove_if 发现符合的就删除(位置还留着,后面发现了不符合的需要进行补位)
//    students.erase(remove_if(students.begin(), students.end(), pgrade), students.end());
//
//    return fail;
//}


vector<Student_info> extract_fails(vector<Student_info>& students)
{
    vector<Student_info>::iterator iter = 
        std::stable_partition(students.begin(), students.end(), pgrade);

    vector<Student_info> fail(iter, students.end());
    students.erase(iter, students.end());

    return fail;
}
