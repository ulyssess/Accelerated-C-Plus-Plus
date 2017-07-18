#ifndef _STUDENT_INFO_
#define _STUDENT_INFO_

#include <string>
#include <vector>
#include <iostream>


struct Student_info {
    std::string name;
    double final_grade;
};

bool compare(const Student_info& x, const Student_info& y);
std::istream& read(std::istream& is, Student_info& s);
#endif /* Student_info.h */
