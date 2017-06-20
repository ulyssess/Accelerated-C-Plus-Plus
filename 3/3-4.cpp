#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

using std::string;
using std::vector;

int main()
{
    vector<int> frequency;
    vector<string> words;

    cout << "Please input words: ";

	string word;
    string smallWord;
    string bigWord;

    cin >> word;
    smallWord = word;
    bigWord = word;

    while (cin >> word) {
        if (word.size() > bigWord.size()) {
            bigWord = word;
        } else if (word.size() < smallWord.size()) {
            smallWord = word;
        }
    }

    cout << "bigWord = " << bigWord << endl;
    cout << "smallWord = " << smallWord << endl;

    return 0;
}
