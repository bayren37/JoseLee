#include <iostream>

#include "review.h"

void main()
{    
	Date::Date myDay(2020, 6, 29);

	int input;
	int otherInput;
	while (true)
	{
		std::cin >> input >> otherInput;

		switch (input)
		{
		case 1:myDay.AddDay(otherInput); break;
		case 2:myDay.AddMonth(otherInput); break;
		case 3:myDay.AddYear(otherInput); break;
		default:
			break;
		}

		myDay.ShowDate();
	}
}