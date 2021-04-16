#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void)
{
    string sent, word;
    cout << "Enter a sentence: ";
    getline(cin, sent);
    cout << "Enter a word in the sentence: ";
    cin >> word;
    int pos = sent.find(word);
    if (pos == sent.npos)
    {
        cout << "Word is not a substring" << endl;
        return EXIT_FAILURE;
    }
    rotate(sent.begin(), sent.begin() + pos, sent.end());
    cout << "New sentence: " << sent << endl;
    return EXIT_SUCCESS;
}