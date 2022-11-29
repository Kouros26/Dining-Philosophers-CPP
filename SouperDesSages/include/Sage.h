#pragma once
#include <thread>
#include <string>

class Sage
{
	std::thread philosopher;

	unsigned int minThinkingTime = 3;
	unsigned int maxThinkingTime = 10;

	unsigned int minEatingTime = 1;
	unsigned int maxEatingTime = 3;

	inline static unsigned int timeNeededToEat = 5;
	inline static unsigned int philosopherCount{};

public:

	Sage();
	Sage(unsigned int minThinkingTime, unsigned int maxThinkingTime,
		unsigned int minEatingTime, unsigned int maxEatingTime);

	static void SetPhilosopherCount(unsigned int count);
};