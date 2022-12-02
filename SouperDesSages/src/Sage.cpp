#include "Sage.h"
#include <iostream>
#include <random>
#include <time.h>

Sage::Sage(unsigned thinkingTime, unsigned eatingTime, double timeNeededToEat)
{
	leftChopstick = new Chopstick();

	this->thinkingTime = thinkingTime;
	this->eatingTime = eatingTime;
	this->timeNeededToEat = timeNeededToEat;

	elapsedSeconds = std::chrono::duration<double>::zero();
}

void Sage::Run()
{
	std::chrono::time_point<std::chrono::system_clock> start, end;

	while (!finished)
	{
		start = std::chrono::system_clock::now();

		TryToEat();

		if (!eating)
			Think();

		end = std::chrono::system_clock::now();
		elapsedSeconds += end - start;
	}

	std::cout << "Done Eating" << std::endl;
}

void Sage::InitThread()
{
	philosopher = new std::thread(&Sage::Run, this);
}

Chopstick*& Sage::GetLeftChopstick()
{
	return leftChopstick;
}

std::thread*& Sage::GetThread()
{
	return philosopher;
}

void Sage::SetRightChopstick(Chopstick*& chopstick)
{
	rightChopstick = chopstick;
}

void Sage::Think()
{
	std::cout << "Thinking" << std::endl;
}

void Sage::TryToEat()
{
	if (elapsedSeconds.count() < thinkingTime)
	{
		elapsedSeconds = std::chrono::duration<double>::zero();

		if (TryGetChopstick(leftChopstick))
		{
			if (TryGetChopstick(rightChopstick))
			{
				eating = true;
				Eat();
			}

			else
				leftChopstick->GetMutex().unlock();
		}
	}
}

bool Sage::TryGetChopstick(Chopstick*& chopstick)
{
	if (chopstick == nullptr)
		return false;

	return chopstick->GetMutex().try_lock();
}

void Sage::Eat()
{
	std::chrono::time_point<std::chrono::system_clock> start, end;
	std::cout << "Eating" << std::endl;

	while (elapsedSeconds.count() < eatingTime)
	{
		start = std::chrono::system_clock::now();

		end = std::chrono::system_clock::now();
		elapsedSeconds += end - start;
	}

	timeNeededToEat -= elapsedSeconds.count();

	if (timeNeededToEat <= 0)
		finished = true;

	leftChopstick->GetMutex().unlock();
	rightChopstick->GetMutex().unlock();
}

//bool Sage::TryGetChopstick()
//{
//}
//
//void Sage::Eat()
//{
//}