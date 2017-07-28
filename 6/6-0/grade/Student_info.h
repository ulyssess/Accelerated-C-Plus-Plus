#ifndef _STUDENT_INFO_
#define _STUDENT_INFO_

#include <string>
#include <vector>
#include <iostream>


struct Student_info {
    std::string name;
    double midterm;
    double final;
    std::vector<double> homework;
};

bool compare(const Student_info& x, const Student_info& y);
std::istream& read(std::istream& is, Student_info& s);
bool did_all_hw(const Student_info& s);

#endif /* Student_info.h */
