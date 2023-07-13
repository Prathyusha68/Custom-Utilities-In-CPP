#include <bits/stdc++.h>
#include "MyUniquePointer.hpp"
using namespace std;

// Constructor without args
template <class T>
MyUniquePointer <T> :: MyUniquePointer() : res{nullptr}
{
    cout << "Constructor without args" << endl;
}

// Destructor
template <class T>
MyUniquePointer<T> :: ~MyUniquePointer()
{
    cout << "Destructor" << endl;
    delete res;
}

// Constructor with args
template <class T>
MyUniquePointer<T> :: MyUniquePointer(T *ptr) : res{ptr}
{
    cout << "Constructor with args" << endl;
}

// Move constructor
template <class T>
MyUniquePointer<T> :: MyUniquePointer(MyUniquePointer &&right)
{
    cout << "Move constructor" << endl;
    T *oldPtr = release();
    res = right.res;
    right.res = nullptr;
    if(oldPtr)
    {
        delete oldPtr;
    }
}

// Move assignment operator
template <class T>
MyUniquePointer<T>& MyUniquePointer<T> :: operator=(MyUniquePointer &&right)
{
    cout << "Move assignment operator" << endl;
    T *oldPtr = release();
    res = right.res;
    right.res = nullptr;
    if (oldPtr)
    {
        delete oldPtr;
    }

    return *this;
}

// Releases ownership of its stored pointer, by returning its value and replacing it with a null pointer
template <class T>
T* MyUniquePointer<T> :: release()
{
    T *oldPtr = res;
    res = nullptr;
    return res;
}

// Reset unique pointer "this" with "ptr"
template <class T>
void MyUniquePointer<T> :: reset(T *ptr)
{
    cout << "Reset" << endl;
    T *oldPtr = release();
    res = ptr;
    if(oldPtr)
    {
        delete oldPtr;
    }
}

// Swap unique pointers
template <class T>
void MyUniquePointer<T> :: swap(MyUniquePointer &other)
{
    cout << "swap()" << endl;
    std::swap(this->res, other.res);
}

// get unique pointer
template <class T>
T* MyUniquePointer<T> :: get()
{
    cout << "get() : " << res << endl;
    return res;
}

// * operator overloading
template <class T>
T& MyUniquePointer<T>::operator*()
{
    cout << "* operator overloading" << endl;
    return *res;
}

// -> operator overloading
template <class T>
T* MyUniquePointer<T>::operator->()
{
    cout << "-> operator overloading" << endl;
    return res;
}

// Bool operator overloading
template <class T>
MyUniquePointer<T>::operator bool()
{
    cout << "bool operator overloading" << endl;
    return (get() != nullptr);
}

// (cout) insertion operator oveloading
template <class T>
ostream &operator<<(ostream &os, const MyUniquePointer<T> &right)
{
    cout << "<< operator overload" << endl;
    os << right.res;
    return os;
}