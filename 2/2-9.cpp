#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{

    cout << "Please input the first number: ";
    int first;
    cin >> first;

    cout << endl;

    cout << "Please input the second number: ";
    int second;
    cin >> second;

    cout << (first > second ? first : second) << endl;
    
    return 0;
}
