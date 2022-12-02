#include "Dinner.h"

#include <iostream>

Dinner::Dinner()
{
	InitSages();
}

Dinner::Dinner(const unsigned minThinkingTime, const unsigned maxThinkingTime, 
               const unsigned minEatingTime, const unsigned maxEatingTime, const unsigned timeNeededToEat)
{
	this->minThinkingTime = minThinkingTime;
	this->maxThinkingTime = maxThinkingTime;
	this->minEatingTime = minEatingTime;
	this->maxEatingTime = maxEatingTime;
	this->timeNeededToEat = timeNeededToEat;

	InitSages();
}

Dinner::~Dinner() noexcept
{
	for (int i = 0; i < philosopherCount; i++)
	{
		sages[i].GetThread()->join();
	}
}

void Dinner::SetPhilosopherCount(const unsigned int count)
{
	philosopherCount = count;
}

void Dinner::InitSages()
{
	for (int i = 0; i < philosopherCount; i++)
	{
		srand(i);

		Sage sage(rand() % maxThinkingTime + minThinkingTime, rand() % maxEatingTime + minEatingTime, timeNeededToEat);

		sages.push_back(sage);

		if (i == 0)
			continue;

		sages[i].SetRightChopstick(sages[i - 1].GetLeftChopstick());
	}

	sages[0].SetRightChopstick(sages[sages.size() - 1].GetLeftChopstick());

	for (int i = 0; i < philosopherCount; i++)
	{
		sages[i].InitThread();
	}
}

constexpr unsigned Dinner::GetMinThinkingTime() const
{
	return minThinkingTime;
}

constexpr unsigned Dinner::GetMaxThinkingTime() const
{
	return maxThinkingTime;
}

constexpr unsigned Dinner::GetMinEatingTime() const
{
	return minEatingTime;
}

constexpr unsigned Dinner::GetMaxEatingTime() const
{
	return maxEatingTime;
}

constexpr unsigned Dinner::GetTimeNeeded() const
{
	return timeNeededToEat;
}

void Dinner::SetMinThinkingTime(const unsigned newValue)
{
	minThinkingTime = newValue;
}

void Dinner::SetMaxThinkingTime(const unsigned newValue)
{
	maxThinkingTime = newValue;
}

void Dinner::SetMinEatingTime(const unsigned newValue)
{
	minEatingTime = newValue;
}

void Dinner::SetMaxEatingTime(const unsigned newValue)
{
	maxEatingTime = newValue;
}

void Dinner::SetTimeNeeded(const unsigned newValue)
{
	timeNeededToEat = newValue;
}