#include <iostream>
#include <string>
#include <list>
#include <algorithm>

#include "word.h"
#include "cat.h"

using std::list;
using std::string;

using std::cin;
using std::cout;
using std::endl;

list<word> leftCycle(list<word> line, list<word>::size_type size)
{
    for (list<word>::size_type i = 1; i <= size; i++) {
        word w;
        w.w = line.begin()->w;
        // 记录当前单词是否被移动过
        w.flag = 1;

        line.erase(line.begin());
        line.push_back(w);
    }

    return line;
}

void showLines(list<list<word>> lines)
{
    list<word>::const_iterator iter;
    list<list<word>>::const_iterator liter;
    
    for (liter = lines.begin(); liter != lines.end(); liter++) {
        for (iter = liter->begin(); iter != liter->end(); iter++) {
            cout << iter->w << " " << iter->flag << " ";
        }
        cout << endl;
    }
}

bool compare(const list<word>& a, const list<word>& b)
{
    string aa = a.begin()->w;
    string bb = b.begin()->w;

    transform(aa.begin(), aa.end(), aa.begin(), ::tolower); 
    transform(bb.begin(), bb.end(), bb.begin(), ::tolower); 

    return aa <= bb;
}

int main()
{
    list<word> line;
    list<list<word>> lines;
    list<list<word>> newLines;

    // 读入将被置换的行 还需要进行split，可以用之前写的代码
    lines = readWords(cin);

    for (list<list<word>>::iterator iter = lines.begin(); iter != lines.end(); iter++) {
        for (list<word>::size_type i = 0; i != iter->size(); i++) {
            list<word> newLine = leftCycle(*iter, i);
            newLines.push_back(newLine);
        }
    }

    // 针对每行第一个单词进行排序
    newLines.sort(compare);

    // 循环处理每一行,将被轮转过的记录到A区，没有轮转过的记录到B区
    list<string> leftZone;
    list<string> rightZone;
    for (list<list<word>>::iterator iter = newLines.begin(); iter != newLines.end(); iter++) {
        string leftString;
        string rightString;
        for (list<word>::iterator it = iter->begin(); it != iter->end(); it++) {
            if (it->flag == 1) {
                leftString += it->w;
                leftString += " ";
            } else {
                rightString += it->w;
                rightString += " ";
            }
        }

        leftZone.push_back(leftString);
        rightZone.push_back(rightString);
    }

    // 将AB区进行横向合并
    list<string> resutl;
    resutl = hcat(leftZone, rightZone);

    // 输出结果
    for (list<string>::const_iterator i = resutl.begin(); i != resutl.end(); i++) {
        cout << *i << endl;
    }

    return 0;
}
