#include <vector>
#include <iostream>

using std::vector;

using std::cin;
using std::cout;

double average(vector<double>& v)
{
    double averageNum;

    if (v.size() == 0) {
        return 0;
    }

    averageNum = 0.0;

    for (vector<double>::size_type i = 0; i < v.size(); i++) {
        averageNum += v[i];
    }

    return averageNum / v.size();
}

int main()
{
    double x;

    vector<double> v;

    while (cin >> x) {
        v.push_back(x);
    }

    cout << average(v);

    return 0;
}
