#pragma once
#include "structProfile.cpp"

template <typename T>
class SmartPark {
	public:

		// Constructor
		SmartPark(int (*hashFx)( T&));

		// SUPER BLOATED FUNCTION
		void insert(Profile& pres)
		{
			int presNameCount = ptrToHashFunc(pres);
			Profile& currentIndex = this->hashTable[presNameCount];

			if (currentIndex.nextNodePtr == NULL)
			{
				currentIndex.nextNodePtr = &pres;
				pres.prevNodePtr = &currentIndex;
			}
			else
			{
				int counter = 0;
				bool keepLooping = true;
				Profile* helperPtr = currentIndex.nextNodePtr;
				Profile* helperPtr2 = NULL;

				while (keepLooping)
				{
					if (counter == 4)
					{
						Profile* helperPtr = currentIndex.nextNodePtr;
						Profile* helperPtr2 = currentIndex.nextNodePtr->nextNodePtr;

						cout << "Removing from lot " << presNameCount << ": " << helperPtr->name << " " << helperPtr->state << endl;
						cout << endl;

						currentIndex.nextNodePtr = helperPtr2;

						helperPtr2->prevNodePtr = &currentIndex;

						helperPtr->nextNodePtr = NULL;
						helperPtr->prevNodePtr = NULL;

						delete helperPtr;
						helperPtr = NULL;

						counter--;
					}
					else if (helperPtr->nextNodePtr == NULL)
					{
						helperPtr->nextNodePtr = &pres;
						pres.prevNodePtr = helperPtr;
						keepLooping = false;
					}
					else if(helperPtr->nextNodePtr != NULL)
					{
						helperPtr = helperPtr->nextNodePtr; 
						counter++;
					}
				}
			}
		}

		void print()
		{
			int i = 0;

			for (i = 0; i < 7; i++)
			{
				Profile& currentIndex = this->hashTable[i];
				Profile* helperPtr = currentIndex.nextNodePtr;
				
				cout << "In lot " << i << " : ";
				while (helperPtr->nextNodePtr != NULL)
				{
					cout << helperPtr->name << " " << helperPtr->state << ", ";
					helperPtr = helperPtr->nextNodePtr;
				}
				cout << endl;
			}
		}

	private:
		Profile* hashTable;
		int (*ptrToHashFunc)(Profile &);
};

template <typename T>
SmartPark<T>::SmartPark(int (*hashFunc)( T&))
{
	hashTable = new Profile[7];
	ptrToHashFunc = hashFunc;
}