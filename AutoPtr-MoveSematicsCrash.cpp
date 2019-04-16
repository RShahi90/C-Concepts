/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
using namespace std;

template<class T>
class AutoPtr {
    T *m_ptr;
    public : 
    AutoPtr(T* ptr=nullptr) 
    : m_ptr(ptr) {}
    ~AutoPtr() {
        delete m_ptr;
    }
    // implement copy constructor and assignment operator-
    // with move semantics
    
    // copy constructor
    AutoPtr(AutoPtr& ptr) {
        m_ptr = ptr.m_ptr; // transfer our dumb pointer from the source to local  object
        ptr.m_ptr = nullptr; // make sure the source is pointed to  nullptr
    }
    
    AutoPtr& operator=(AutoPtr& ptr) {
        if(this == &ptr)
        return *this;
        
        delete  m_ptr; // deallocate any pointer which current pointer is holding to 
        m_ptr = ptr.m_ptr; // copy from source to local pointer
        ptr.m_ptr = nullptr; // make sure the source is pointing to nullptr
        return *m_ptr; // return local pointer
    }
    
    T* operator->() {return m_ptr;}
    T& operator*() {return *m_ptr;}
};

struct stt{
    stt(char* name_, int age_) {
        name = name_;
        age = age_;
    }
    char* name;
    int age;
};

template<typename T>
void func(AutoPtr<T> myPtr) {
    
}
int main()
{
    AutoPtr<int> myPtr(new int(10));
    cout << *myPtr << endl;
    func(myPtr);
    cout << *myPtr << endl;
    return 0;
}
