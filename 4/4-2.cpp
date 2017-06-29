#include <iostream>
#include <iomanip>

using std::cout;
using std::endl;
using std::setw;

int main()
{
    for (int i = 1; i <= 100; i++) {
        cout << setw(4) << i << " ";
        cout << setw(6) << i * i << endl;
    }

    return 0;
}
