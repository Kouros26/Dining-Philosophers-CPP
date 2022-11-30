#include "Chopstick.h"

Chopstick::Chopstick()
= default;

std::mutex& Chopstick::GetMutex()
{
	return mutex;
}
