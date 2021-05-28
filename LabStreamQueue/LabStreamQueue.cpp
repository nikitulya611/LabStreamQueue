#include <iostream>
#include <ctime>

#include "CPU.h"
#include "Queue.h"
#include "TaskFlow.h"

using namespace std;

int main() {

	setlocale(LC_ALL, "Russian");

	srand(time(NULL));
	int val;
	int id = 1;
	int ignor = 0;
	int dinamo = 0;
	bool isFirstTask = true;
	int taskInQueue = 1;

	int current = 1;

	cout << "Введите размер очереди \n";
	cin >> val;
	Queue myQueue(val);

	cout << "Введите мощность процессора от 0 до 100 \n";
	cin >> val;
	CPU myCPU(val);

	cout << "Введите интенсивность потока задач от 0 до 100 \n";
	cin >> val;
	TaskFlow myTaskFlow(val);

	cout << "Кол-во тактов \n";
	cin >> val;
	for (int takt = 1; takt <= val; takt++) 
	{
		cout << takt << " такт" << endl;
		if (myTaskFlow.isGeneration())
		{
			cout << "Задача была сгенерирована";

			if (!myQueue.isFull())
			{
				myQueue.push(id++);
				cout << ", добавлена в очередь." << endl;
			}
			else
			{
				ignor++;
				cout << " и проигнорирована." << endl;
			}

		}
		else
		{
			cout << "Задача не сгенерирована." << endl;
		}
		if (myCPU.isFree() || isFirstTask)
		{
			cout << "Процессор ";
			if (!myQueue.isEmpty())
			{
				isFirstTask = false;
				myQueue.pop();
				cout << " выполняет задачу " << current++ << endl;
			}
			else
			{
				dinamo++;
				cout << "простаивает." << endl;
			}
		}
		else
		{
			cout << "Процессор занят выполнением предыдущей задачи." << endl;
		}


	}

	while (!myQueue.isEmpty())
	{
		myQueue.pop();
		taskInQueue++;
	}

	float perc = ((float)ignor / (id + ignor)) * 100;

	float rest = ((float)dinamo / val) * 100;

	float srtime = 0;
	if (id - taskInQueue > 0)
		srtime = ((float)(val - dinamo) / (id - taskInQueue));
	else
		srtime = 0;


	cout << "\nПроцент проигнорированных задач равен " << perc << endl;
	cout << "Процент простоя процессора " << rest << endl;
	cout << "Среднее время выполнения задачи " << srtime << endl;



	system("pause");
	return 0;


}
