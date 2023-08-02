#pragma once

#include <iostream>

#include "structProfile.cpp"

using namespace std;

template <typename T>
class Queue {

public:

	void operator =(T* pro)
	{
		this->name = pro->name;
		this->state = pro->state;
	}

	void enqueue(const T& node)
	{
		if (this->queueStart == NULL && this->queueEnd == NULL)
		{
			T* pres = node;
			this->queueStart = pres;
			//this->queueStart = node;
			std::cout << "we're here!" << endl;
		}
		/*
		if (this->queueStart == NULL && this->queueEnd == NULL)
		{
			this->queueStart = node;
			this->queueEnd = node;
		}
		else if (this->queueStart == this->queueEnd)
		{
			this->queueStart->nextNodePtr = node;
			node->prevNodePtr = queueStart;
			this->queueEnd = node;
		}
		else
		{
			node->prevNodePtr = this->queueEnd;
			this->queueEnd->nextNodePtr = node;
			this->queueEnd = node;
		}
		*/
	}
	/*
	void dequeue()
	{
		if (this->queueStart != this->queueEnd)
		{
			cout << "Removing friend: " << this->queueStart->name << " " << this->queueStart->state << endl;
			this->queueStart = this->queueStart->nextNodePtr;

			delete this->queueStart->prevNodePtr;

			this->queueStart->prevNodePtr = NULL;
		}
		else if (this->queueStart == this->queueEnd && this->queueStart != NULL)
		{
			cout << "Removing friend: " << this->queueStart->name << " " << this->queueStart->state << endl;

			delete this->queueStart->prevNodePtr;

			this->queueStart = NULL;
			this->queueEnd = NULL;
		}
		else
		{
			isEmpty();
		}
	}

	bool isEmpty()
	{
		if (this->queueStart != NULL && this->queueEnd != NULL)
		{
			cout << "You have friends!" << endl;

			return false;
		}
		else
		{
			cout << "No friends." << endl;

			return true;
		}
	}

	void makeEmpty()
	{
		while (this->queueStart != NULL && this->queueEnd != NULL)
		{
			this->dequeue();
		}
	}

	void peek()
	{
		if (isEmpty())
		{
			return;
		}
		else
		{
			cout << "First friend: " << this->queueStart->name << " " << this->queueStart->state << endl;
		}
	}

	void print()
	{
		T* presToPrint = this->queueStart;

		cout << "Printing friends!" << endl;

		while (presToPrint != NULL)
		{
			cout << presToPrint->name << " " << presToPrint->state << endl;
			presToPrint = presToPrint->nextNodePtr;
		}
	}

	void reversePrint()
	{
		T* presToPrint = this->queueEnd;

		cout << "Printing friends in reverse!" << endl;

		while (presToPrint != NULL)
		{
			cout << presToPrint->name << " " << presToPrint->state << endl;
			presToPrint = presToPrint->prevNodePtr;
		}
	}
	
	*/

	Profile* getQueueStart()
	{
		return queueStart;
	}

	Profile* getQueueEnd()
	{
		return queueEnd;
	}

private:
	Profile* queueStart = NULL;	// Always points to the front of the queue
	Profile* queueEnd = NULL;		// Always points to the end of the queue
};
