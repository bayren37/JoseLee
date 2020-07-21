#include <iostream>
#include <cstdlib>
#include "review.h"

int main()
{    
	jtd::MyString myString("0123456789");
	myString.print(); //abcdef
	std::cout << std::endl;

	const char* character = "xyz";
	myString.insert(character, 1); //abcdxyz 를 기대
	myString.print();//실제 abcdx

	return 0;
}