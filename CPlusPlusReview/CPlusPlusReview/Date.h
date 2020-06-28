#pragma once
#include <vector>

namespace Date {
	const std::vector<int> FULL_MONTH = { 1,3,5,7,8,10,12 };

	class Date {
	public:
		Date(int year, int month, int date);
		void SetDate(int year, int month, int date);
		void AddDay(int inc);
		void AddMonth(int inc);
		void AddYear(int inc);

		void ShowDate();

	private:
		int year_;
		int month_;  // 1 부터 12 까지.
		int day_;    // 1 부터 31 까지.
	};
}