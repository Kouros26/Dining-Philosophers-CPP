#pragma once
#include "Chopstick.h"
#include <thread>
class Sage
{
	Chopstick* leftChopstick = nullptr;
	Chopstick* rightChopstick = nullptr;

	std::chrono::duration<double> elapsedSeconds{};

	std::thread* philosopher;
	
	unsigned int thinkingTime{};
	unsigned int eatingTime{};
	double timeNeededToEat{};

	bool finished = false;
	bool eating = false;

public:

	Sage(unsigned int thinkingTime, unsigned int eatingTime, double timeNeededToEat);

	void Run();
	void InitThread();

	Chopstick*& GetLeftChopstick();
	std::thread*& GetThread();

	void SetRightChopstick(Chopstick*& chopstick);

private:

	void Think();
	void TryToEat();
	static bool TryGetChopstick(Chopstick*& chopstick);
	void Eat();
};