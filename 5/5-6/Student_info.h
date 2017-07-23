#ifndef _STUDENT_INFO_
#define _STUDENT_INFO_

#include <string>
#include <iostream>
#include <list>
#include <vector>


struct Student_info {
    std::string name;
    double final_grade;
};

bool compare(const Student_info& x, const Student_info& y);
std::istream& read(std::istream& is, Student_info& s);

//typedef std::list<Student_info> sinfo;
typedef std::vector<Student_info> sinfo;

#endif /* Student_info.h */
