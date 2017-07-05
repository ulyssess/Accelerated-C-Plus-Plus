#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;
using std::istream;
using std::sort;

using std::cin;
using std::cout;
using std::endl;

vector<string> readWords(istream& in)
{
    string word;
    vector<string> words;

    // in >> word的返回还是in，只有in还是true的时候才说明读取正确
    while (in >> word) {
        words.push_back(word);
    }

    // 这种方式在读取出错时会将上一次读取的值push进vector中
    //while (in) {
    //    in >> word
    //    words.push_back(word);
    //}

    return words;
}

int main()
{
    vector<string> words;

    words = readWords(cin);

    cout << "input " << words.size() << " words" << endl;

    sort(words.begin(), words.end());

    int frequence = 1;
    for (vector<string>::size_type i = 0; i < words.size(); i++) {

        if (i + 1 < words.size() && words[i] == words[i+1])
            frequence++;
        else {
            cout << words[i] << " appear " << frequence << endl;
            frequence = 1;
        }
    }

    return 0;
}
