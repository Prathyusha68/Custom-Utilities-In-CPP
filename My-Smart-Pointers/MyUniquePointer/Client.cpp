/**
 * Linking Issue:
 * =============
 * When the compiler encounters a declaration of a MyUniquePointer object of some specific type,
 * e.g., int, it must have access to the template implementation source. Otherwise, it will have
 * no idea how to construct the MyUniquePointer member functions. And, if you have put the
 * implementation in a source (MyUniquePointer.cpp) file and made it a separate part of the project,
 * the compiler will not be able to find it when it is trying to compile the client source file.
 * And, #includeing the header file (MyUniquePointer.h) will not be sufficient at that time.
 * That only tells the compiler how to allocate for the object data and how to build the calls to
 * the member functions, not how to build the member functions. And again, the compiler won't complain.
 * It will assume that these functions are provided elsewhere, and leave it to the linker to find them.
 * So, when it's time to link, you will get "unresolved references" to any of the class member functions
 * that are not defined "inline" in the class definition.
 *
 * Fix:
 * ===
 * You can #include the source file("MyUniquePointer.cpp") that implements your template class in your client source file.
 *
 * Refer : https://www.codeproject.com/Articles/48575/How-to-define-a-template-class-in-a-h-file-and-imp
 */
#include <bits/stdc++.h>
#include "MyUniquePointer.hpp"
#include "MyUniquePointer.cpp"
using namespace std;

class test
{
public:
    void print()
    {
        cout << "entered test class, print func" << endl;
    }
};

int main()
{
    int *ptr = new int(2);
    MyUniquePointer<int> ptr1(new int(5));            // Constructor with args
    MyUniquePointer<int> ptr2(ptr);                   // Constructor with args
    //MyUniquePointer<int> ptr2 = ptr1;      --> cannot make a copy of unique pointers
    //ptr2 = ptr1;                          --> cannot make a copy of unique pointers
    MyUniquePointer<int> ptr3 = std::move(ptr1); // Move constructor
    MyUniquePointer<int> ptr4;
    ptr4 = std::move(ptr1); // = operator oveload with rvalue
    MyUniquePointer<int> ptr5;
    ptr5.reset(new int(9));

    cout << ptr5 << endl; // Insertion operator (ostream) overload
    cout<<*ptr5 << endl;  // * operator overload

    MyUniquePointer<test> testPtr;

    testPtr->print(); // -> operator overload

    cout<< ptr5.get() << endl; // get() function

    ptr5.swap(ptr4); // swap() function

    ptr5.release(); // Release unique ptr

    if(ptr5) // bool overload
    {

    }
}
