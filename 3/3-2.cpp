#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

using std::vector;
using std::sort;

int main()
{
    cout << "Please input int aggregate(Multiple of four number): ";

    int x;
    vector<int> aggregate;

    while (cin >> x) {
        aggregate.push_back(x);
    }

    typedef vector<int>::size_type vec_sz;

    vec_sz size = aggregate.size();

    if (size == 0)
        return -1;

    if (size % 4 != 0) {
        printf("Please input Multiple of four int digital\n");
        return -1;
    }

    int groupSize = size / 4;
    
    sort(aggregate.begin(), aggregate.end());

    for (unsigned long i = 0; i < size; i++) {
        cout << aggregate[i] << " ";
        if ((i + 1) % groupSize == 0)
            cout << "|";
    }

    cout << endl;
}
