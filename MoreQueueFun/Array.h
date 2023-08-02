#pragma once

using namespace std;

template <class T>
class Array
{
public:
	// Constructor
	Array<T>(T* hashPtr, int size);

	// Destructor
	~Array();
	/*
	T operator[](int index)
	{
		return this->ptrToFollowers[index]->queueStart = pres;
	}

	T operator=(const Profile& pres)
	{
		this->ptrToFollowers[index] = pres;
	}
	*/

	// Returns ptrToFollowers
	T& getPtr();

private:
	T* ptrToFollowers;	 // pointer to array
	int capacity;		 // current array length
};

template<class T>
inline Array<T>::Array(T* hashPtr, int size)
{
	return new T[size];
}

template<class T>
inline Array<T>::~Array()
{
	delete[] ptrToFollowers;
}

template<class T>
inline T& Array<T>::getPtr()
{
	return ptrToFollowers;
}