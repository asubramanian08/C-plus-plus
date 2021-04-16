#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <exception>
using namespace std;

#pragma region "function prototypes"
//String: 1 - 7, 14 - 17; Vector: 8 - 13
void TE1(void);
void TE2(void);
void TE3(void);
void TE4(void);
void TE5(void);
void TE6(void);
void TE7(void);
void TE8(void);
void TE9(void);
void TE10(void);
void TE11(void);
void TE12(void);
void TE13(void);
void TE14_CR1(void);
void TE15_CR3(void);
void TE16_PE1(void);
void TE17_PE2(void);
#pragma endregion "function prototypes"

int main(void)
{
    // TE1();
    // TE2();
    // TE3();
    // TE4();
    // TE5();
    // TE6();
    // TE7();
    // TE8();
    // TE9();
    // TE10();
    // TE11();
    // TE12();
    // TE13();
    // TE14_CR1();
    // TE15_CR3();
    // TE16_PE1();
    // TE17_PE2();
    return 0;
}

void TE1(void)
{
    string hello("Hello");
    string world("World");
    string hello_world(hello + world);
}

void TE2(void)
{
    string hello_world("Hello World");
    for (auto &i : hello_world)
        i = 'A';
}

void TE3(void)
{
    string sent("It was a bright cold day in April, and the clocks were striking thirteen");
    sent.insert(sent.find("clocks"), "cuckoo ");
    sent.erase(sent.find("bright "), strlen("bright "));
}

void TE4(void)
{
    cout << "Enter 2 word / strings: ";
    string str1, str2;
    cin >> str1 >> str2;
    cout << str1 << ((str1 < str2) ? " is less than " : " is greater than ") << str2 << endl;
}

void TE5(void)
{
    string line;
    cout << "Enter a line: ";
    getline(cin, line);
    string vowels = "aeiouAEIOU";
    auto pos = line.find_first_of(vowels);
    while (pos != string::npos)
    {
        line.erase(pos, 1);
        pos = line.find_first_of(vowels);
    }
    cout << line << endl;
}

#pragma region "TE6"
string to_trim("\t\n\v\f ");
string &ltrim(string &str)
{
    str.erase(0, str.find_first_not_of(to_trim));
    return str;
}
string &rtrim(string &str)
{
    str.erase(0, str.find_last_not_of(to_trim));
    return str;
}
string &trim(string &str)
{
    ltrim(str);
    rtrim(str);
    return str;
}
void TE6(void)
{
    cout << "Enter a line with spaces and tabs: ";
    string line;
    getline(cin, line);
    line = trim(line);
}
#pragma endregion "TE6"

void TE7(void)
{
    string nums("0123456789");
    string testcap;
    for (int i = 0; i < 100; i++)
    {
        testcap.append(nums);
        cout << "Capacity: " << testcap.capacity()
             << " Size: " << testcap.size() << endl;
    }
    testcap.shrink_to_fit();
    cout << "After strink to fit:" << endl;
    cout << "Capacity: " << testcap.capacity()
         << " Size: " << testcap.size() << endl;
}

void TE8(void)
{
    //make the array
    vector<int> vi(10);
    iota(vi.begin(), vi.end(), 1);
    /*vector<int> vi(10);
    for (int i = 0; i < 10; i++)
        vi.push_back(i + 1);*/

    //multiply everything by 10
    for (auto &i : vi)
        i *= 10;
}

void TE9(void)
{
    // key: cmd + z is cin's eof
    //read ints
    cout << "Enter a series of ints (Cmd + Z to end): ";
    int iTemp;
    vector<int> vi;
    while (cin >> iTemp)
        vi.push_back(iTemp);
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    //read strings
    string strTemp;
    vector<string> vs;
    while (cin >> strTemp)
        vs.push_back(strTemp);
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void TE10(void)
{
    //part a
    vector<int> v1({42, 42, 42, 42, 42, 42, 42, 42, 42, 42});
    vector<int> v2(10, 42);
    vector<int> v3 = vector<int>(10, 42);
    //part b
    vector<int> v4({10, 42});
    //part c
    vector<string> v5(10, "Monkeys");
}

void TE11(void)
{
    vector<int> vi = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for (int i = 0; i < 11; i++)
        try
        {
            cout << vi.at(i) << endl;
        }
        catch (out_of_range &exc)
        {
            cout << exc.what() << endl;
        }
}

void TE12(void)
{
    vector<string> vs;
    //using push pack
    vs.push_back("string 1");
    vs.push_back("string 2");
    vs.push_back("string 3");
    //using emplace back
    vs.emplace_back("string 1");
    vs.emplace_back("string 2");
    vs.emplace_back("string 3");

    // Emplace back is faster
    // push back has to copy the memory first
    // emplace back just make passes the arguments for the constructer
}

#pragma region "TE13"
bool OddsFirst(const int &x, const int &y)
{
    if (x % 2 != y % 2)
        return x % 2;
    return x < y;
}
void TE13(void)
{
    //Their code
    vector<int> test;
    for (int i = 0; i < 10; i++)
        test.push_back(i);                     // 0,1,2,3,4,5,6,7,8,9
    sort(test.begin(), test.end(), OddsFirst); // 1,3,5,7,9,0,2,4,6,8
}
#pragma endregion "TE13"

void TE14_CR1(void)
{
    //their code changed for string instead of char*
    class CR1
    {
    private:
        string st; // points to C-style string
    public:
        CR1() = default;
        CR1(const char *s) : st(s) {}
    };

    // you don't need: destructor, assignment operator, copy constructor
}

#pragma region "TE15_CR3"
void makeUpper(string &str)
{
    for (auto &i : str)
        i = toupper(i);
    //transform(str.begin(), str.end(), put some function here);
}
void TE15_CR3(void)
{
    string str;
    cout << "Enter a string: ";
    cin >> str;
    makeUpper(str);
    cout << "Upper case of string: " << str << endl;
}
#pragma endregion "TE15"

#pragma region "TE16_PE1"
bool isPalendrome(const string &str)
{
    string rStr(str);
    reverse(rStr.begin(), rStr.end());
    return str.compare(rStr) == 0;
}
void TE16_PE1(void)
{
    cout << "Enter a string: ";
    string str;
    cin >> str;
    if (isPalendrome(str))
        cout << "The string is a palendrome" << endl;
    else
        cout << "The string is not a palendrome" << endl;
}
#pragma endregion "TE16_PE1"

#pragma region "TE17_PE2"
bool isPalendrome_comp(const string &str)
{
    //remove complications (comp)
    string noComp;
    for (auto i : str)
        if (isalpha(i))
            noComp += tolower(i);
    string rStr(noComp);
    reverse(rStr.begin(), rStr.end());
    return noComp.compare(rStr) == 0;
}
void TE17_PE2(void)
{
    cout << "Enter a string: ";
    string str;
    cin >> str;
    if (isPalendrome_comp(str))
        cout << "The string is a palendrome" << endl;
    else
        cout << "The string is not a palendrome" << endl;
}
#pragma endregion "TE17_PE2"