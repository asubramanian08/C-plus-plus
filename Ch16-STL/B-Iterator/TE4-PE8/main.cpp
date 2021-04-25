#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void readFriends(vector<string> &vs)
{
    string temp;
    for (getline(cin, temp); !temp.empty(); getline(cin, temp))
        vs.push_back(temp);
}
void printFriends(const vector<string> &vs)
{
    for (string str : vs)
        cout << str << ' ';
    cout << endl
         << endl;
}

int main(void)
{
    //init
    vector<string> mat, pat, friends;
    string temp;

    //get mat friends
    cout << "Enter Mat's friends (enter blank line to stop)" << endl;
    readFriends(mat);
    sort(mat.begin(), mat.end());
    //print mat friends
    cout << "Mat's friends: " << endl;
    printFriends(mat);

    //get pat friends
    cout << "Enter Pat's friends (enter blank line to stop)" << endl;
    readFriends(pat);
    sort(pat.begin(), pat.end());
    //print pat friends
    cout << "Pat's friends: " << endl;
    printFriends(pat);

    //find and print all friends
    friends.resize(mat.size() + pat.size());
    set_union(mat.begin(), mat.end(), pat.begin(), pat.end(), friends.begin());
    friends.shrink_to_fit();
    cout << "All friends: " << endl;
    printFriends(friends);

    return 0;
}