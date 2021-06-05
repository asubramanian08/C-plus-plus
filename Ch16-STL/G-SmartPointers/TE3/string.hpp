//copied from Ch12 q2 -> modified from unique_ptr
#ifndef STRING_H_
#define STRING_H_
#include <iostream>
#include <memory>

class String
{
private:
    std::unique_ptr<char[]> str;  // pointer to string
    int len;                      // length of string
    static int num_strings;       // number of objects
    static const int CINLIM = 80; // cin input limit

public:
    // constructors and other methods
    String(const char *s);             // constructor
    String();                          // default constructor
    String(const String &);            // copy constructor
    ~String();                         // destructor
    int length() const { return len; } // overloaded operator methods
    String &operator=(const String &);
    String &operator=(const char *);
    char &operator[](int i);
    const char &operator[](int i) const;
    // overloaded operator friends
    friend bool operator<(const String &st, const String &st2);
    friend bool operator>(const String &st1, const String &st2);
    friend bool operator==(const String &st, const String &st2);
    friend std::ostream &operator<<(std::ostream &os, const String &st);
    friend std::istream &operator>>(std::istream &is, String &st);
    // static function
    static int HowMany();

    //My changes below
    String operator+(const String &s) const;
    friend String operator+(const char *s1, const String &s2);
    void stringlow();
    void stringup();
    int has(char ch) const;
    //added after modification
    const char *data() { return str.get(); }
};
#endif