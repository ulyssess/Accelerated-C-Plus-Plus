#ifndef _GRADE_H_
#define _GRADE_H_

#include <vector>
#include "Student_info.h"

double grade(const Student_info& s);
double grade(double midterm, double final, const std::vector<double>& hw);
double grade(double midterm, double final, double homework);

#endif /* grade.h */
