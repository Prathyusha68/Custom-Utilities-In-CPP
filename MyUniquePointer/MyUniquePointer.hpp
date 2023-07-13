#include<bits/stdc++.h>
#ifndef _UNIQUE_PTR_HPP_
#define _UNIQUE_PTR_HPP_
using namespace std;
template<class T>
class MyUniquePointer
{
private:
    T* res;

public:
    MyUniquePointer();                                              // Constructor without args
    ~MyUniquePointer();                                             // Destructor
    MyUniquePointer(T *ptr);                                        // Constructor with args
    MyUniquePointer(const MyUniquePointer &) = delete;              // Copy Constructor is deleted
    MyUniquePointer &operator=(const MyUniquePointer &) = delete;   // Copy assignment operator is deleted
    MyUniquePointer(MyUniquePointer &&);                            // Move constructor
    MyUniquePointer &operator=(MyUniquePointer &&);                 // Move assignment operator
    void reset(T *ptr = nullptr);                        // Reset unique pointer "this" with "ptr"
    T *release();                                                   // Releases ownership "res", by returning its value
    void swap(MyUniquePointer &);                                   // Swap unique pointers
    T *get();                                                       // get unique pointer
    T &operator*();                                                 // * operator overloading
    T *operator->();                                                // -> operator overloading
    operator bool();                                                // Bool operator overloading
    
    template<class U>
    friend ostream &operator<<(ostream &, const MyUniquePointer<U> &); // (cout) insertion operator oveloading
};
#endif