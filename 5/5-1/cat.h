#ifndef _CAT_H_
#define _CAT_H_

#include <string>
#include <list>

std::list<std::string> hcat(const std::list<std::string>& left,
                            const std::list<std::string>& right);

std::list<std::string> vcat(const std::list<std::string>& top,
                            const std::list<std::string>& bottom);

#endif // cat.h
