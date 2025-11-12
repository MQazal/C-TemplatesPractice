#pragma once
#include <iostream>
#include "clsDynamicArray.h"
using namespace std;

// Template Queue and Dynamic Array Library - 12/11/2025 - Developer: Mr.Key47

// This Queue's library supports Template Dynamic Array Library in its backend structure instaded of Template Doubly Linked List Library

template <class T> class clsMyQueueArr
{
protected:
	clsDynamicArray<T> _MyArray; // applying composition of object from Dynamic Array class by size of 0

public:
	void push(T Value)
	{
		_MyArray.InsertAtEnd(Value);
	}

	int Size()
	{
		return _MyArray.Size();
	}

	T front()
	{
		return _MyArray.GetItem(0);
	}

	T back()
	{
		return _MyArray.GetItem(Size() - 1);
	}

	T GetItem(short Index)
	{
		return _MyArray.GetItem(Index);
	}

	void Reverse()
	{
		_MyArray.Reverse();
	}

	void UpdateItem(short Index, T Value)
	{
		_MyArray.setItem(Index, Value);
	}

	void InsertAfter(short Index, T Value)
	{
		_MyArray.InsertAfter(Index, Value);
	}

	void InsertAtFront(T Value)
	{
		_MyArray.InsertAtBeginning(Value);
	}

	void InsertAtBack(T Value)
	{
		_MyArray.InsertAtEnd(Value);
	}

	void pop()
	{
		// FIFO (First In First Out)
		_MyArray.DeleteFirstItem();
	}

	bool IsEmpty()
	{
		return _MyArray.IsEmpty();
	}

	void Clear()
	{
		_MyArray.Clear();
	}

	void Print()
	{
		_MyArray.Print();
	}
};