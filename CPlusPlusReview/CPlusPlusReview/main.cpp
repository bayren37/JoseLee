#include <iostream>
#include <string>
#include "review.h"

void main()
{
	jtd::MyString abcdefghijk("01234567");

	abcdefghijk.erase(0, 9);
	abcdefghijk.print();
	std::cout << std::endl << abcdefghijk.strlen();
	//abcdefghijk.erase(0, 3);
	//abcdefghijk.erase(0, 3);
	//abcdefghijk.erase(0, 3);
	
}

