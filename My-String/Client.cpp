#include <bits/stdc++.h>
#include "MyString.hpp"
using namespace std;

int main()
{
    MyString str1;                   // Constructor with no args
    MyString str2 = "Prathyusha";    // Parameterized constructor (same for <<< MyString str2("Prathyusha"); >>>)
    str1 = str2;                     // Copy assignement operator overload
    MyString str3 = str2;            // Copy Constructor
    MyString str4 = std::move(str2); // move constructor (rvalue reference)

    int len = str4.length(); // length() funcion

    cin >> str1;          // Extraction operator (istream) overload
    cout << str1 << endl; // Insertion operator (ostream) overload
}
