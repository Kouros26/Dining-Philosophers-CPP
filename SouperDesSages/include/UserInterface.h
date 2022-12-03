#pragma once
#include <string>

class UserInterface
{
	bool valuesChanged = false;
	int minThinkingTime{};
	int maxThinkingTime{};
	int minEatingTime{};
	int maxEatingTime{};
	int timeNeededToEat{};
	inline static int count{};

public:

	UserInterface();
	void InitDinner() const;

private:

	static void AskForInput(const std::string& display, int& to);

	int AskForValuesChanges();
	int ChangeValues();

};