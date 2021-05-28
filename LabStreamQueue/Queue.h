#pragma once

const int MAX = 200;

class Queue
{
public:
	Queue(int m_size = MAX);
	~Queue();

	bool isEmpty();
	bool isFull();

	void push(int elem);
	int pop();

	int size() const;

private:
	int getNextIndex(int index);
	int head;
	int tail;
	int count;
	int maxSize;
	int* data;
};

