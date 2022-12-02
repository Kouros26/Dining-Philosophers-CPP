#pragma once
#include "Sage.h"
#include <vector>

class Dinner
{
	std::vector<Sage> sages;

	unsigned int minThinkingTime = 3;
	unsigned int maxThinkingTime = 10;

	unsigned int minEatingTime = 1;
	unsigned int maxEatingTime = 3;

	unsigned int timeNeededToEat = 5;

	inline static unsigned int philosopherCount{};

public:

	Dinner();
	Dinner(unsigned int minThinkingTime, unsigned int maxThinkingTime,
		unsigned int minEatingTime, unsigned int maxEatingTime, unsigned int timeNeededToEat);

	static void SetPhilosopherCount(unsigned int count);

	void InitSages();

	constexpr unsigned int GetMinThinkingTime() const;
	constexpr unsigned int GetMaxThinkingTime() const;
	constexpr unsigned int GetMinEatingTime() const;
	constexpr unsigned int GetMaxEatingTime() const;
	constexpr unsigned int GetTimeNeeded() const;

	void SetMinThinkingTime(const unsigned int newValue);
	void SetMaxThinkingTime(const unsigned int newValue);
	void SetMinEatingTime(const unsigned int newValue);
	void SetMaxEatingTime(const unsigned int newValue);
	void SetTimeNeeded(const unsigned int newValue);
};