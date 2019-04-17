/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <iostream>
using namespace std;
template<class T>
class AutoPtr3 {
  T* m_ptr;  
  public :
  AutoPtr3(T* ptr = nullptr) 
      :m_ptr(ptr) {}
  ~AutoPtr3() { delete m_ptr;}
  
  // copy constructor
  AutoPtr3(AutoPtr3& newPtr) {
      m_ptr = new T;
      *m_ptr = *newPtr.m_ptr;
  }
  
  // assignment overload operator
  AutoPtr3& operator=(const AutoPtr3& ptr) {
      if(this == &ptr)
          return *this;
      
      delete m_ptr;
      m_ptr = new T;
      *m_ptr = *ptr.m_ptr;
      return *this;
  }
  
  //move constructor
  AutoPtr3(AutoPtr3&& ptr) {
      m_ptr = ptr.m_ptr;
      ptr.m_ptr = nullptr;
  } 
  
  // move assignment
  AutoPtr3& operator=(AutoPtr3&& ptr) {
      if(this == &ptr)
          return *this;
    delete m_ptr;
    m_ptr = ptr.m_ptr;
    ptr.m_ptr = nullptr;
    return *this;
  }
};

class Resource{
  public:
  Resource() {
      cout << "Resource made." << endl;
  }
  ~Resource() {
      cout << "Resource deleted." << endl;
  }
};

AutoPtr3<Resource> generateResource() {
    AutoPtr3<Resource> res(new Resource);
    return res;
}

int main() {
    AutoPtr3<Resource> myRes;
    myRes = generateResource();
}


