#pragma once
#include "Chopstick.h"
#include <thread>

class Sage
{
	Chopstick* leftChopstick = nullptr;
	Chopstick* rightChopstick = nullptr;

	std::thread philosopher;

	unsigned int minThinkingTime = 3;
	unsigned int maxThinkingTime = 10;

	unsigned int minEatingTime = 1;
	unsigned int maxEatingTime = 3;

	inline static unsigned int philosopherCount{};
	inline static constexpr unsigned int timeNeededToEat = 5;

public:

	Sage();
	Sage(unsigned int minThinkingTime, unsigned int maxThinkingTime,
		unsigned int minEatingTime, unsigned int maxEatingTime);

	void Run();

	static void SetPhilosopherCount(unsigned int count);

	Chopstick*& GetChopstick();
	std::thread& GetThread();

private:

	void Think();
	//bool TryGetChopstick();
	//void Eat();
};