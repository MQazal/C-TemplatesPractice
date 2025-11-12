#pragma once
#include <iostream>
#include "clsMyQueueArr.h"
using namespace std;

// Template Stack and Dynamic Array Library - 12/11/2025 - Developer: Mr.Key47

template <class T> class clsMyStackArr : public clsMyQueueArr<T>
{
public:
	void push(T Value)
	{
		clsMyQueueArr<T>::_MyArray.InsertAtBeginning(Value);
	}

	T Top()
	{
		return clsMyQueueArr<T>::front();
	}

	T Bottom()
	{
		return clsMyQueueArr<T>::back();
	}
};