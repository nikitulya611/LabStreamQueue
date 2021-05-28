#include "CPU.h"


bool CPU::isFree()
{
	return (rand() % 100) < powerCPU;
}

CPU::CPU(int power) : powerCPU(power)
{

}
