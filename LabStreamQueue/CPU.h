#pragma once

#include <random>
#include <ctime>

class CPU
{
public:
	CPU(int power = 100);

	bool isFree();

private:
	int powerCPU;
};


