#pragma once
#include <string>

class UserInterface
{
	bool valuesChanged = false;
	int minThinkingTime{};
	int maxThinkingTime{};
	int minEatingTime{};
	int maxEatingTime{};
	inline static int count{};

public:

	UserInterface();

private:

	static void AskForInput(const std::string& display, int& to);
	int AskForValuesChanges();
	int ChangeValues();

	void InitSages() const;
};