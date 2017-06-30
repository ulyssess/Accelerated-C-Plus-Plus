#include <iostream>
#include <iomanip>
#include <string>

using std::cout;
using std::endl;
using std::setw;
using std::string;

int digitSize(int digit)
{
    int i = 0;

    // 即便是数字0, 这也是一位，所以先++
    do {
        i++;
    } while (digit /= 10);

    return i;
}

int main()
{
    int maxNum = 999;
    int digitWidth = digitSize(maxNum) + 2;
    int squareWidth = digitSize(maxNum*maxNum) + 2;

    for (int i = 1; i <= maxNum; i++) {
        cout << setw(digitWidth) << i << "|";
        cout << setw(squareWidth) << i * i << endl;
    }

    return 0;
}
