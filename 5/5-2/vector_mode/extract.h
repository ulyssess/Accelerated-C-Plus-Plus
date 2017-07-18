#ifndef _EXTRACT_H_
#define _EXTRACT_H_

#include <vector>
#include <list>

#include "Student_info.h"

std::vector<Student_info> extract_fails_3(std::vector<Student_info>& students);
std::list<Student_info> extract_fails(std::list<Student_info>& students);

#endif /* extract.h */
