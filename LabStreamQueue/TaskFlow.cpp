#include "TaskFlow.h"

TaskFlow::TaskFlow(int intens)
{
	taskintensity = intens;
}

bool TaskFlow::isGeneration()
{
	return (rand() % 100) < taskintensity;
}