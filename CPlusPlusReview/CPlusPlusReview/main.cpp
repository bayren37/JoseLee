#include <iostream>
#include <cstdlib>
#include "review.h"

int main()
{    
	jtd::MyString myString("0123456789");
	myString.print(); //abcdef
	std::cout << std::endl;

	const char* character = "xyz";
	myString.insert(character, 1); //abcdxyz �� ���
	myString.print();//���� abcdx

	return 0;
}