#include <iostream>
#include <string>

// 声明使用的标准库名称
using std::cin;
using std::endl;
using std::cout;
using std::string;

int main()
{
    // 请求用户输入姓名
    cout << "Please enter your first name: ";

    // 读入用户输入的姓名
    string name;
    cin >> name;

    // 构造我们将要输出的信息
    const string greeting = "Hello, " + name + "!";
    
    // 围住问候语的空白个数
    const int pad = 5;

    // 待输出的行数与列数
    const int rows = pad * 2 + 3;
    const string::size_type cols = greeting.size() + pad * 2 + 2;

    // 待输出的空白行
    const string spaceLine(cols - 2, ' ');

    // 输出一个空行，把输入和输出隔开
    cout << endl;

    // 输出rows行
    // 不变式，到目前为止，我们已经输出了r行
    for (int r = 0; r != rows; ++r) {
        string::size_type c = 0;

        // 不变式，到目前为止，在当前行中我们已经输出了c个字符
        while (c != cols) {
            // 应该输出问候语句了吗?
            if (r == pad + 1 && c == pad + 1) {
                cout << greeting;
                c += greeting.size();
            } else {
                // 我们是位于边界上吗?
                if (r == 0 || r == rows - 1 || c == 0 || c == cols -1) {
                    cout << "*";
                    c++;
                // 位于问候语输出行?
                } else if (r == pad + 1) {
                    cout << " ";
                    c++;
                // 位于其他空行
                } else {
                    cout << spaceLine;
                    c += spaceLine.size();
                }
            }
        }

        cout << endl;
    }

    return 0;
}
