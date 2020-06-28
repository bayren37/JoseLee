#include <iostream>

#include "review.h"

int main()
{    
    if (false)
    {
		int a = 0;
		int& refA = a;
		review::Reference::makeItFive(a);
		review::Reference::makeItFive(refA);

		std::cout << a << std::endl;
		std::cout << refA;
    }

	int a = review::Reference::returnValue();
	int b = review::Reference::returnLocalVar();
	int c = review::Reference::returnLocalRefferenceVar();
	int d;
	int e = review::Reference::makeItFive(d);

	std::cout << "a :" << a << std::endl;
	std::cout << "b :" << b << std::endl;
	std::cout << "c :" << c << std::endl;
	std::cout << "e :" << e << std::endl;

    return 0;
}