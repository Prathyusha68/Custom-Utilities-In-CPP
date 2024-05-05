#include <bits/stdc++.h>
using namespace std;

class MyString
{
private:
    char *str = nullptr;

public:
    MyString();                            // constructor without args
    ~MyString();                           // destructor
    MyString(const char *);                // parameterized constructor
    MyString(char *);                      // parameterixed constructor
    MyString(const MyString &);            // copy constructor
    MyString(MyString &&);                 // move constructor
    MyString &operator=(const MyString &); // copy assignement operator
    int length();                          // length of a string

    friend istream &operator>>(istream &, MyString &);       // (cin) extraction operator overloading
    friend ostream &operator<<(ostream &, const MyString &); // (cout) insertion operator oveloading
};
