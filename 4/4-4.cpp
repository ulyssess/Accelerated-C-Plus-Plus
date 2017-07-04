#include <iostream>
#include <iomanip>
#include <string>

using std::cout;
using std::endl;
using std::setw;
using std::string;
using std::to_string;

using std::streamsize;
using std::setprecision;
using std::setiosflags;
using std::resetiosflags;
using std::ios;

int main()
{
    double maxNum = 999.111;
    // 
    int digitWidth = to_string(maxNum).size() + 1;
    int squareWidth = to_string(maxNum * maxNum).size() + 1;

    // 设置小数精度
    streamsize prec = cout.precision();
    cout << setprecision(6);

    // 将精度设置为只对小数点后数据有效
    cout << setiosflags(ios::fixed);

    for (double i = 1.111; i <= maxNum; i++) {
        cout << setw(digitWidth) << i << "|";
        cout << setw(squareWidth) << i * i << endl;
    }

    // 清除将精度设置为只对小数点后数据有效的设置
    cout << resetiosflags(ios::fixed);

    // 还原小数精度
    cout << setprecision(prec);

    return 0;
}
