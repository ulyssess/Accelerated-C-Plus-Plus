#include <ios>
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <stdexcept>

#include "Student_info.h"
#include "grade.h"
#include "median.h"

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
using std::ostream;
using std::streamsize;
using std::setprecision;

double median_analysis(const vector<Student_info>& students)
{
    vector<double> grades;

    transform(students.begin(),
            students.end(), std::back_inserter(grades), grade_aux);

    try {
        return median(grades);
    } catch (domain_error) {
        return 0.0;
    }
}

double average_analysis(const vector<Student_info>& students)
{
    vector<double> grades;

    transform(students.begin(),
            students.end(), std::back_inserter(grades), average_grade);

    try {
        return median(grades);
    } catch (domain_error) {
        return 0.0;
    }
}

double optimistic_median_analysis(const vector<Student_info>& students)
{
    vector<double> grades;

    transform(students.begin(),
            students.end(), std::back_inserter(grades), optimistic_median);

    try {
        return median(grades);
    } catch (domain_error) {
        return 0.0;
    }
}

void write_analysis(ostream& out,
                    const string& name,
                    double analysis(const vector<Student_info>&),
                    const vector<Student_info>& did,
                    const vector<Student_info>& didnt)
{
    out << name << "median(did) = " << analysis(did)
                << ", median(didnt) = " << analysis(didnt) << endl;
}

int main()
{
    Student_info student;

    vector<Student_info> did;
    vector<Student_info> didnt;

    // 读取并存储所有的记录，然后找出最长的姓名的长度
    while (read(cin, student)) {
        if (did_all_hw(student)) {
            did.push_back(student);
        }
        else {
            didnt.push_back(student);
        }
    }

    // 展示分析的结果
    if (did.empty()) {
        cout << "No student did all the homework" << endl;
    } else if (didnt.empty()) {
        cout << "Every student did all the homework" << endl;
    }

    // 进行分析
    write_analysis(cout, "median", median_analysis, did, didnt);
    write_analysis(cout, "average", average_analysis, did, didnt);
    write_analysis(cout, "optimistic_median", optimistic_median_analysis, did, didnt);

    return 0;
}
