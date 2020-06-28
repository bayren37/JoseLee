#include "Animal.h"
#include <iostream>

namespace Animal {

	Animal::Animal()
	{
		std::cout << "동물의 이름? ";
		std::cin >> name_;

		std::cout << "동물의 나이? ";
		std::cin >> age_;
	}

	void Animal::Play() {
		health_ += 10;
		food_ -= 20;
		clean_ -= 30;
	}

	void Animal::OneDayPass() {
		health_ -= 10;
		food_ -= 30;
		clean_ -= 20;
	}

	void Animal::ShowStat() {
		std::cout << name_ << "의 상태" << std::endl;
		std::cout << "체력    : " << health_ << std::endl;
		std::cout << "배부름 : " << food_ << std::endl;
		std::cout << "청결    : " << clean_ << std::endl;
	}

	Keeper::~Keeper()
	{
		for (size_t i = 0; i < animals_.size(); i++)
		{
			delete animals_[i];
		}
	}

	void Keeper::DoWhatKeepersDo()
	{
		std::cout << "1. 동물 추가하기" << std::endl;
		std::cout << "2. 놀기 " << std::endl;
		std::cout << "3. 상태 보기 " << std::endl;

		int input;
		std::cin >> input;

		switch (input) {
			int play_with;
		case 1:
			Adopt();
			break;
		case 2:
			std::cout << "누구랑 놀게? : ";
			std::cin >> play_with;
			PlayWith(play_with);
			break;
		case 3:
			std::cout << "누구껄 보게? : ";
			std::cin >> play_with;
			ShowStat(play_with);
			break;
		}

		for (auto animal : animals_)
		{
			animal->OneDayPass();
		}
	}

	void Keeper::Adopt()
	{
		animals_.push_back(new Animal());
	}

	void Keeper::PlayWith(int index)
	{
		try
		{
			animals_[index]->Play();
		}
		catch (const std::exception& e)
		{
			std::cout << e.what();
		}
	}
	void Keeper::ShowStat(int index)
	{
		try
		{
			animals_[index]->ShowStat();
		}
		catch (const std::exception& e)
		{
			std::cout << e.what();
		}
	}
}
