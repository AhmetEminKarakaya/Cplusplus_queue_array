#pragma once

#include "queue.h"

using namespace std;

template<class T>
class arrayQueue : public queue<T>
{
	int theFront;
	int theBack;
	int arrayLength;
	T* queue;

public:
	arrayQueue(int initialcapacity = 10)
	{
		if (initialcapacity < 1)
		{
			printf("Error...");
		}
		arrayLength = initialcapacity;
		queue = new T[arrayLength];
		theFront = 0;
		theBack = 0;
	}

	~arrayQueue() { delete[] queue };
	bool empty() const { return theFront == theBack; }
	int size() const { return (theBack - theFront + arrayLength) % arrayLength; }

	T& front()
	{
		if (theFront == theBack)
		{
			cout << "Queue is empty..." << endl;
		}
		return queue[(theFront + 1) % arrayLength];
	}

	T& back()
	{
		if (theFront == theBack)
		{
			cout << "Queue is empty..." << endl;
		}
		return queue[theBack];
	}

	void pop()
	{
		if (theFront == theBack)
		{
			cout << "Queue is empty..." << endl;
		}
		theFront = (theFront + 1) % arrayLength;
		queue[theFront].~T();
	}

	void push(const T& theElement)
	{
		if ((theBack + 1) % arrayLength == theFront)
		{
			T* newQueue = new T[2 * arrayLength];

			int start = (theFront + 1) % arrayLength;

			if (start < 2)
				copy(queue + start, queue + start + arrayLength - 1, newQueue);

			else
			{  
				copy(queue + start, queue + arrayLength - 1, newQueue);
				copy(queue, queue + theBack + 1, newQueue + arrayLength - start);
			}

			theFront = 2 * arrayLength - 1;
			theBack = arrayLength - 2;   
			arrayLength *= 2;
			queue = newQueue;
		}
		theBack = (theBack + 1) % arrayLength;
		queue[theBack] = theElement;
	}

};