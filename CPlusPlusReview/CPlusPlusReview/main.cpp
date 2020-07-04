#include <iostream>

#include "review.h"

void main()
{    
	Date::Date myDay(2020, 7, 4);

	int i, j;

	while (true)
	{
		std::cin >> i>> j;
		switch (i)
		{
		case 0:
			myDay.AddDay(j);
			break;
		case 1:
			myDay.AddMonth(j);
			break;
		case 2:
			myDay.AddYear(j);
			break;
		}
		myDay.ShowDate();
	}
}