/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <iostream>
using namespace std;
class Fraction{
    private:
    int number_;
    int denominator_;
  public :
  Fraction(int number, int denominator) {
      number_ = number;
      denominator_ = denominator;
  }
std::ostream& operator<<(std::ostream& out, Fraction& frac) {
    out << frac.number_ << "/" << frac.denominator_;
    return out;
}
};

int main()
{
    Fraction &&ref = Fraction(3,5);
    std::cout << ref << endl;
    printf("Hello World");

    return 0;
}
