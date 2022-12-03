#pragma once
#include "Chopstick.h"
#include <thread>

class Sage
{
	Chopstick* leftChopstick = nullptr;
	Chopstick* rightChopstick = nullptr;

	std::thread* philosopher{};

	unsigned int registrationNumber{};

	unsigned int thinkingTime{};
	unsigned int eatingTime{};
	double timeNeededToEat{};

	bool finished = false;
	bool eating = false;

public:

	Sage(unsigned int thinkingTime, unsigned int eatingTime, double timeNeededToEat, unsigned int matriculeNumber);
	~Sage();

	void Run();
	void InitThread();

	Chopstick*& GetLeftChopstick();
	std::thread*& GetThread();

	void SetRightChopstick(Chopstick*& chopstick);

private:

	void Think() const;
	bool TryToEat();
	static bool TryGetChopstick(Chopstick*& chopstick);
	void Eat();
};