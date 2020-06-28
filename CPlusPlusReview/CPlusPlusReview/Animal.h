#pragma once
#include <vector>

namespace Animal {

	class Animal {
	public:
		Animal();

		void Play();
		void OneDayPass();
		void ShowStat();

	private:
		char name_[30];
		int age_;

		int health_ = 100;
		int food_ = 100;
		int clean_ = 100;
	};

	class Keeper
	{
	public:
		~Keeper();

		void DoWhatKeepersDo();
	private:
		void Adopt();
		void PlayWith(int index);
		void ShowStat(int index);

	private:
		std::vector<Animal*> animals_;
	};
}