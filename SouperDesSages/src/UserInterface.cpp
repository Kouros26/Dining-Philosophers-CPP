#include "UserInterface.h"
#include <iostream>
#include "Dinner.h"

UserInterface::UserInterface()
{
	std::cout << "PhilosopherCount : ";
	std::cin >> count;

	if (count <= 0)
		return;

	Dinner::SetPhilosopherCount(count);

	if (AskForValuesChanges() != 0)
	{
		std::cout << "Error while changing values" << std::endl;
		return;
	}

	InitDinner();
}

void UserInterface::AskForInput(const std::string& display, int& to)
{
	std::cout << display;
	std::cin >> to;
}

int UserInterface::AskForValuesChanges()
{
	char input;
	bool change = false;

	std::cout << "Change values ? (y/n) : ";
	std::cin >> input;

	switch (input)
	{
	case 'y':
		change = true;
		break;

	case 'n':
		break;

	default:
		std::cout << "Incorrect answer, values didn't change by default" << std::endl;
		break;
	}

	if (change)
		return ChangeValues();

	return 0;
}

int UserInterface::ChangeValues()
{
	AskForInput("Minimum thinking time : ", minThinkingTime);
	if (minThinkingTime <= 0)
		return -1;

	AskForInput("Maximum thinking time : ", maxThinkingTime);
	if (maxThinkingTime <= 0 || maxThinkingTime < minThinkingTime)
		return -1;

	AskForInput("Minimum eating time : ", minEatingTime);
	if (minEatingTime <= 0)
		return -1;

	AskForInput("Maximum eating time : ", maxEatingTime);
	if (maxEatingTime <= 0 || maxEatingTime < minEatingTime)
		return -1;

	AskForInput("Time needed to finish eating : ", timeNeededToEat);
	if (timeNeededToEat <= 0 || timeNeededToEat < maxEatingTime)
		return -1;

	valuesChanged = true;

	return 0;
}

void UserInterface::InitDinner() const
{
	if (valuesChanged)
	{
		Dinner dinner{ static_cast<unsigned int>(minThinkingTime),
			           static_cast<unsigned int>(maxThinkingTime),
			            static_cast<unsigned int>(minEatingTime),
			            static_cast<unsigned int>(maxEatingTime),
			           static_cast<unsigned int>(timeNeededToEat) };

		std::cout << "Dinner created with custom values" << std::endl;
	}

	else
	{
		Dinner dinner{};

		std::cout << "Dinner created with default values" << std::endl;
	}
}
