#include <map>
#include <string>
#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

int main(void)
{
    map<string, unsigned int> word_count;
    cout << "Enter text: ";
    string word;
    while (cin >> word)
        word_count[word]++;

    auto display = [](const pair<string, unsigned int> &word)
    { cout << word.first << ' ' << word.second << endl; };
    for (auto word : word_count)
        display(word);
    for_each(word_count.rbegin(), word_count.rend(), display);
    return 0;
}