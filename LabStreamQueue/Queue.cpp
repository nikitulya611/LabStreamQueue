#include "Queue.h"

Queue::Queue(int m_size)
{
	head = tail = count = 0;
	maxSize = m_size;
	data = new int[m_size];
}

Queue::~Queue()
{
	delete[] data;
}

bool Queue::isEmpty()
{
	return !count;
}

bool Queue::isFull()
{
	return count == maxSize;
}

void Queue::push(int elem)
{
	count++;
	data[tail] = elem;
	tail = getNextIndex(tail);

}

int Queue::pop()
{
	count--;
	int temp = data[head];
	head = getNextIndex(head);
	return temp;
}

int Queue::getNextIndex(int index)
{
	return (index + 1) % maxSize;
}

int Queue::size() const
{
	return count;
}
