#include "extract.h"

bool fgrade(const Student_info& s)
{
    return s.final_grade < 60;
}

sinfo extract_fails(sinfo& students)
{
    sinfo fail;
    sinfo::size_type success_size = 0;
    sinfo::iterator iter = students.begin();
    sinfo::iterator success_iter = students.begin();

    for (sinfo::iterator iter = students.begin(); iter != students.end(); iter++) {
        if (fgrade(*iter)) {
            fail.push_back(*iter);
        } else {
            *success_iter = *iter;

            success_iter++;
            success_size++;
        }
    }

    students.resize(success_size);

    return fail;
}

/*
sinfo extract_fails(sinfo& students)
{
    sinfo fail;
    sinfo::iterator iter = students.begin();

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
*/
