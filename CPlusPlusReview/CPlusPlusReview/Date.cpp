#include "Date.h"
#include <iostream>
#include <algorithm>
namespace Date {
	constexpr uint32_t MONTH_IN_YEAR = 12;

	Date::Date(int year, int month, int date) : year_(year), month_(month), day_(date)
	{
	}

	void Date::SetDate(int year, int month, int date)
	{
		year_ = year;
		month_ = month;
		day_ = date;
	}

	void Date::AddDay(int inc)
	{
		day_ += inc;
		auto search = std::find_if(FULL_MONTH.begin(), FULL_MONTH.end(),
			[this](int month) {
				return month == month_;
			}
		);

		int daysInThisMonth;

		if (month_ != 2) {
			daysInThisMonth = search == FULL_MONTH.end() ? 30 : 31;
		}
		else if (year_ % 4 != 0) {//2월이고, 윤년이 아니면
			daysInThisMonth = 28;
		}
		else {//2월이고, 윤년이면
			daysInThisMonth = 29;
		}

		day_ %= (daysInThisMonth + 1);
		AddMonth(day_ / (daysInThisMonth + 1));
	}

	void Date::AddMonth(int inc)
	{
		year_ += (month_ + inc) / MONTH_IN_YEAR;
		month_ += (month_ + inc) % MONTH_IN_YEAR;
	}

	void Date::AddYear(int inc)
	{
		year_ += inc;
	}

	void Date::ShowDate()
	{
		printf("TODAY IS %d/%d/%d(YYYY/MM/DD)\n", year_, month_, day_);
	}
}