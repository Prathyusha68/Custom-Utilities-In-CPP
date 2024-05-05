#include <bits/stdc++.h>
#include "MyString.hpp"

using namespace std;

MyString::~MyString()
{
    cout << "MyString destructor called" << endl;
    if (str)
    {
        cout << "Deleting " << str << endl;
        delete[] str;
    }
}
MyString::MyString() : str{nullptr}
{
    str = new char[1];
    str[0] = '\0';
    cout << "Default constructor" << endl;
}

MyString::MyString(const char *strVal)
{
    if (strVal == nullptr)
    {
        str = new char[1];
        str[0] = '\0';
    }
    else
    {
        this->str = new char[strlen(strVal) + 1];
        strcpy(this->str, strVal);
        this->str[strlen(strVal)] = '\0';
        cout << "Parameterized constructor (const string) : " << str << endl;
    }
}

MyString::MyString(char *str)
{
    if (str == nullptr)
    {
        str = new char[1];
        str[0] = '\0';
    }
    else
    {
        this->str = new char[strlen(str) + 1];
        strcpy(this->str, str);
        this->str[strlen(str)] = '\0';
        cout << "Parameterized constructor : " << str << endl;
    }
}

MyString::MyString(const MyString &srcStr)
{
    str = new char[strlen(srcStr.str) + 1];
    str[strlen(srcStr.str)] = '\0';
    strcpy(str, srcStr.str);
    cout << "Copy constructor : " << str << endl;
}

MyString::MyString(MyString &&srcStr)
{
    str = srcStr.str;
    srcStr.str = nullptr;
    cout << "Move constructor : " << str << endl;
}

MyString &MyString::operator=(const MyString &srcStr)
{
    this->str = srcStr.str;
    cout << "Copy assignement operator overloading : " << str << endl;

    return *this;
}

int MyString::length()
{
    cout << "Length of a string is  : " << strlen(str) << endl;
    return strlen(str);
}

istream &operator>>(istream &is, MyString &strObj)
{
    is >> strObj.str;
    return is;
}

ostream &operator<<(ostream &os, const MyString &str)
{
    os << str.str;
    return os;
}
