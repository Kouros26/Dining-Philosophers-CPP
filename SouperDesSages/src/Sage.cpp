#include "Sage.h"
#include <iostream>
#include <random>

Sage::Sage(unsigned thinkingTime, unsigned eatingTime, double timeNeededToEat, unsigned matriculeNumber)
{
	leftChopstick = new Chopstick();
	philosopher = nullptr;

	this->thinkingTime = thinkingTime;
	this->eatingTime = eatingTime;
	this->timeNeededToEat = timeNeededToEat;
	this->registrationNumber = matriculeNumber;
}

Sage::~Sage()
{
	delete philosopher;
}

void Sage::Run()
{
	Think();

	while (!finished)
	{
		if (!TryToEat())
		{
			Think();
		}
	}

	std::cout << "Sage " << registrationNumber << " is done eating" << std::endl;
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

void Sage::Think() const
{
	std::cout << "Sage " << registrationNumber << " is Thinking for : " << thinkingTime << "s" << std::endl;
	std::this_thread::sleep_for(std::chrono::seconds(thinkingTime));
}

bool Sage::TryToEat()
{
	if (TryGetChopstick(leftChopstick))
	{
		if (TryGetChopstick(rightChopstick))
		{
			Eat();

			return true;
		}

		leftChopstick->GetMutex().unlock();
	}

	return false;
}

bool Sage::TryGetChopstick(Chopstick*& chopstick)
{
	if (chopstick == nullptr)
		return false;

	return chopstick->GetMutex().try_lock();
}

void Sage::Eat()
{

	std::cout << "Sage " << registrationNumber << " is Eating for " << eatingTime << "s" << std::endl;

	std::this_thread::sleep_for(std::chrono::seconds(eatingTime));

	timeNeededToEat -= eatingTime;

	if (timeNeededToEat <= 0)
		finished = true;

	leftChopstick->GetMutex().unlock();
	rightChopstick->GetMutex().unlock();
}