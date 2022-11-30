#pragma once
#include <mutex>

class Chopstick
{
	std::mutex mutex;

public:

	Chopstick();

	std::mutex& GetMutex();
};