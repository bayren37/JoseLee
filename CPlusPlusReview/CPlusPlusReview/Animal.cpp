#include "Animal.h"
#include <iostream>

namespace Animal {

	Animal::Animal()
	{
		std::cout << "������ �̸�? ";
		std::cin >> name_;

		std::cout << "������ ����? ";
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
		std::cout << name_ << "�� ����" << std::endl;
		std::cout << "ü��    : " << health_ << std::endl;
		std::cout << "��θ� : " << food_ << std::endl;
		std::cout << "û��    : " << clean_ << std::endl;
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
		std::cout << "1. ���� �߰��ϱ�" << std::endl;
		std::cout << "2. ��� " << std::endl;
		std::cout << "3. ���� ���� " << std::endl;

		int input;
		std::cin >> input;

		switch (input) {
			int play_with;
		case 1:
			Adopt();
			break;
		case 2:
			std::cout << "������ ���? : ";
			std::cin >> play_with;
			PlayWith(play_with);
			break;
		case 3:
			std::cout << "������ ����? : ";
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
