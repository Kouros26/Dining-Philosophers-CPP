#include "Sage.h"

Sage::Sage()
= default;

Sage::Sage(unsigned minThinkingTime, unsigned maxThinkingTime, unsigned minEatingTime, unsigned maxEatingTime)
{
	this->minThinkingTime = minThinkingTime;
	this->maxThinkingTime = maxThinkingTime;
	this->minEatingTime = minEatingTime;
	this->maxEatingTime = maxEatingTime;
}

void Sage::SetPhilosopherCount(unsigned int count)
{
	philosopherCount = count;
}
