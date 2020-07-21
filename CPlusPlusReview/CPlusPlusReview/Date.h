#pragma once
#include <vector>

namespace jtd {
	const std::vector<int> FULL_MONTH = { 1,3,5,7,8,10,12 };

	class Date {
	public:
		Date(int year, int month, int date);
		void SetDate(int year, int month, int date);
	private:
		void Verify();

	public:
		void AddDay(int inc);
		void AddMonth(int inc);
		void AddYear(int inc);

		void ShowDate();

	private:
		int DaysInThisMonth();
		int DaysInFormerMonth();


	private:
		int year_;
		int month_;
		int day_;
	};
}