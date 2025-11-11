#pragma once
#include <iostream>
#include "clsMyQueue.h"
using namespace std;

// Template Stack Library - 11/11/2025 - Developer: Mr.Key47

// I used inhertaince concept to do this prject because most of queue's methods are used here

template <class T> class clsMyStack : public clsMyQueue<T>
{
public:
	void push(T Data) // Overriding concept to change the behavior
	{
		clsMyQueue<T>::InsertAtFront(Data);
	}

	T Top()
	{
		return clsMyQueue<T>::front();
	}

	T Bottom()
	{
		return clsMyQueue<T>::back();
	}
};