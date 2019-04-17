/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <iostream>
using namespace std;
void fun(const int &lref) // l-value arguments will select this function
{
	std::cout << "l-value reference to const\n";
}
 
void fun(int &&rref) // r-value arguments will select this function
{
	std::cout << "r-value reference\n";
}
 
void fun(int &lref) // r-value arguments will select this function
{
	std::cout << "l-value reference\n";
}

int main()
{
	int x = 5;
	fun(x); // l-value argument calls l-value version of function
	fun(5); // r-value argument calls r-value version of function
	const int y = 10;
	fun(y);
	return 0;
}

/*Output:
l-value reference                                                                                                              
r-value reference                                                                                                              
l-value reference to const*/

