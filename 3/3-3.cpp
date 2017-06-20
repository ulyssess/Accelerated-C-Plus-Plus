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

    while (cin >> word) {
        // find repeate word
        vector<string>::size_type i;
        for (i = 0; i < words.size(); i++) {
            if (words[i] == word) {
                frequency[i] += 1;
                break;
            }
        }

        // add new word
        if (i == words.size()) {
            words.push_back(word);
            frequency.push_back(1);
        }
    }

    for (vector<string>::size_type i = 0; i < words.size(); i++) {
        cout << words[i] << "   " << frequency[i] << endl;
    }
}
