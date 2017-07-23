#include "extract.h"

bool fgrade(const Student_info& s)
{
    return s.final_grade < 60;
}

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
