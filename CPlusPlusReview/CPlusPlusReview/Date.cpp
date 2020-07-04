#include "Date.h"
#include <iostream>
#include <algorithm>
namespace Date {
	constexpr uint32_t MONTH_IN_YEAR = 12;

	Date::Date(int year, int month, int date) : year_(year), month_(month), day_(date) 
	{
		Verify();
	}

	void Date::SetDate(int year, int month, int date)
	{
		year_ = year;
		month_ = month;
		day_ = date;
		Verify();
	}

	void Date::Verify()
	{
		while (day_ > DaysInThisMonth())
			--day_;
	}

	void Date::AddDay(int inc)
	{
		day_ += inc;

		if (day_ > 0) {
			int daysInThisMonth = DaysInThisMonth();

			while (day_ > daysInThisMonth) {
				day_ -= daysInThisMonth;
				AddMonth(1);
				daysInThisMonth = DaysInThisMonth();
			}
		}
		else {
			int daysInformerMonth = DaysInFormerMonth();

			do {
				day_ += daysInformerMonth;
				AddMonth(-1);
				daysInformerMonth = DaysInThisMonth();
			} while (day_ > daysInformerMonth || day_ < 0);
		}
		Verify();
	}

	void Date::AddMonth(int inc)
	{
		month_ += inc;
		if (month_ > 0) {
			while (month_ > MONTH_IN_YEAR) {
				month_ -= MONTH_IN_YEAR;
				AddYear(1);
			}
		}
		else {
			do {
				month_ += MONTH_IN_YEAR;
				AddYear(-1);
			} while (month_ > MONTH_IN_YEAR);
		}
		Verify();
	}

	void Date::AddYear(int inc)
	{
		year_ += inc;
	}

	void Date::ShowDate()
	{
		printf("TODAY IS %d/%d/%d(YYYY/MM/DD)\n", year_, month_, day_);
	}

	int Date::DaysInThisMonth()
	{
		auto search = std::find_if(FULL_MONTH.begin(), FULL_MONTH.end(),
			[this](int month) {
				return month == month_;
			});
		int daysInThisMonth;

		if (month_ != 2) {
			return daysInThisMonth = search == FULL_MONTH.end() ? 30 : 31;
		}
		else if (year_ % 4 != 0) {//Feb
			return daysInThisMonth = 28;
		}
		else {//Feb, leap year
			return daysInThisMonth = 29;
		}
	}

	int Date::DaysInFormerMonth()
	{
		Date formerMonth(year_, month_ - 1, day_);
		return formerMonth.DaysInThisMonth();
	}

}