/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <iostream>
using namespace std;

template <class T>
class AutoPtr {
    T *m_ptr;
    public:
    AutoPtr(T* ptr=nullptr)
    : m_ptr(ptr){}
        ~AutoPtr(){  
            delete m_ptr;
        }
        //AutoPtr(AutoPtr& ptr) = delete; // no copying allowed
        //AutoPtr& operator=(const AutoPtr& ptr) = delete; // no assignment allowed
        // move constructor
        AutoPtr(AutoPtr&& ptr) {
            m_ptr = ptr.m_ptr;
            ptr.m_ptr = nullptr;
        }
        // move  assignment operator
        AutoPtr& operator=(const AutoPtr&& ptr) {
            if(this == &ptr)
                return *this;
            delete m_ptr;
            m_ptr = ptr.m_ptr;
            ptr.m_ptr = nullptr;
            return *this;
        }
        T& operator*()  {return *m_ptr;}
        T* operator->() {return m_ptr;}
};

// make pointer of MyClass and dont worry about the deletion
class MyClass {
    public:
    MyClass() { cout << "MyClass init." << endl;}
    ~MyClass() { cout << "MyClass destroyed." << endl;}
};
int main()
{
    /*AutoPtr<int> myRes(10);*/
    AutoPtr<MyClass> obj1(new MyClass);
    AutoPtr<MyClass> obj2 = AutoPtr<MyClass>();
    AutoPtr<int> obj3(new int);
    printf("Hello World");
    return 0;
}
