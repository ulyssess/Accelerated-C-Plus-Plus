#include <vector>
#include <iostream>

using std::vector;

using std::cout;
using std::endl;

vector<double> f()
{
    vector<double> v;

    v.push_back(1.1);

    return v;
}

int main()
{
    double d = f()[0];

    cout << "d = " << d << endl;
}
