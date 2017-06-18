#include <iostream>
#include <string>

using std::cout;
using std::endl;

int main()
{
    int rows = 5;
    int cols = 5;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (i == 0 || i == (rows - 1) || j == 0 || (j == cols - 1)) {
                cout << '*';
            } else {
                cout << ' ';
            }
        }
        cout << endl;
    }

    cout << endl;

    rows = 5;
    cols = 20;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (i == 0 || i == (rows - 1) || j == 0 || (j == cols - 1)) {
                cout << '*';
            } else {
                cout << ' ';
            }
        }
        cout << endl;
    }

    cout << endl;

    rows = 5;
    cols = 5;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if ((i + j == cols - 1) || i == (rows - 1) || (j == cols - 1)) {
                cout << '*';
            } else {
                cout << ' ';
            }
        }
        cout << endl;
    }

    cout << endl;

    rows = 5;
    cols = 9;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if ((i + j == cols/2) || (j - i) == cols/2 || i == (rows - 1)) {
                cout << '*';
            } else {
                cout << ' ';
            }
        }
        cout << endl;
    }

    return 0;
}
