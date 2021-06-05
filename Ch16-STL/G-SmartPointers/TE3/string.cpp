#include <cstring>
#include "string.hpp" // includes <iostream>
// initializing static class member

int String::num_strings = 0;

// static method
int String::HowMany() { return num_strings; }

// class methods
String::String(const char *s) // construct String from C string
{
    len = std::strlen(s);                    // set size
    str = std::make_unique<char[]>(len + 1); // allot storage
    std::strcpy(str.get(), s);               // initialize pointer
    num_strings++;                           // set object count
}

String::String() // default constructor
{
    len = 4;
    str = std::make_unique<char[]>(1);
    str[0] = '\0'; // default string
    num_strings++;
}

String::String(const String &st)
{
    num_strings++;                           // handle static member update
    len = st.len;                            // same length
    str = std::make_unique<char[]>(len + 1); // allot space
    std::strcpy(str.get(), st.str.get());    // copy string to new location
}

String::~String() // necessary destructor
{
    --num_strings; // required
}

// overloaded operator methods

// assign a String to a String
String &String::operator=(const String &st)
{
    if (this == &st)
        return *this;
    len = st.len;
    str = std::make_unique<char[]>(len + 1);
    std::strcpy(str.get(), st.str.get());
    return *this;
}

// assign a C string to a String
String &String::operator=(const char *s)
{
    len = std::strlen(s);
    str = std::make_unique<char[]>(len + 1);
    std::strcpy(str.get(), s);
    return *this;
}

// read-write char access for non-const String
char &String::operator[](int i) { return str[i]; }

// read-only char access for const String
const char &String::operator[](int i) const { return str[i]; }

// overloaded operator friends

bool operator<(const String &st1, const String &st2)
{
    return (std::strcmp(st1.str.get(), st2.str.get()) < 0);
}

bool operator>(const String &st1, const String &st2)
{
    return st2 < st1;
}

bool operator==(const String &st1, const String &st2)
{
    return (std::strcmp(st1.str.get(), st2.str.get()) == 0);
}

// simple String output
std::ostream &operator<<(std::ostream &os, const String &st)
{
    os << st.str;
    return os;
}

// quick and dirty String input
std::istream &operator>>(std::istream &is, String &st)
{
    char temp[String::CINLIM];
    is.get(temp, String::CINLIM);
    if (is)
        st = temp;
    while (is && is.get() != '\n')
        continue;
    return is;
}

//My stuff
String String::operator+(const String &s) const
{
    char *new_cStr = new char[len + s.len + 1];
    strncpy(new_cStr, str.get(), len);
    strncpy(new_cStr + len, s.str.get(), s.len);
    String newStr(new_cStr);
    delete[] new_cStr;
    return newStr;
}

String operator+(const char *s1, const String &s2)
{
    return String(s1) + s2;
}

void String::stringlow()
{
    for (int i = 0; i < len; i++)
        str[i] = tolower(str[i]);
}

void String::stringup()
{
    for (int i = 0; i < len; i++)
        str[i] = toupper(str[i]);
}

int String::has(char ch) const
{
    int count = 0;
    for (int i = 0; i < len; i++)
        count += str[i] == ch;
    return count;
}