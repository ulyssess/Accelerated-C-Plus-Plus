#ifndef _WORD_H_
#define _WORD_H_

#include <list>
#include <string>
#include <iostream>

struct word {
    int flag;           // 是否被移动过
    std::string w;      // 一个单词
};

std::list<std::list<word>> readWords(std::istream& in);

#endif // word.h
