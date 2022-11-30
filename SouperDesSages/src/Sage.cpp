#include "Sage.h"
#include <chrono>
#include <random>
#include <time.h>

Sage::Sage()
= default;

Sage::Sage(unsigned minThinkingTime, unsigned maxThinkingTime, unsigned minEatingTime, unsigned maxEatingTime)
{
	leftChopstick = new Chopstick();
	this->minThinkingTime = minThinkingTime;
	this->maxThinkingTime = maxThinkingTime;
	this->minEatingTime = minEatingTime;
	this->maxEatingTime = maxEatingTime;
}

void Sage::Run()
{
	//Think();
	//Eat();
}

void Sage::SetPhilosopherCount(unsigned int count)
{
	philosopherCount = count;
}

Chopstick*& Sage::GetChopstick()
{
	return leftChopstick;
}

std::thread& Sage::GetThread()
{
	return philosopher;
}

void Sage::Think()
{
	srand(time(nullptr));
	minThinkingTime -= rand() % 5;
	maxThinkingTime += rand() % 5;

	//if (!TryGetChopstick())
	//	Think();

	//else
	//	Eat();
}

//bool Sage::TryGetChopstick()
//{
//}
//
//void Sage::Eat()
//{
//}