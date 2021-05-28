#pragma once

#include <random>
#include <ctime>

class TaskFlow
{
public:
	TaskFlow(int intens = 100);

	bool isGeneration();

private:
	int taskintensity;
};