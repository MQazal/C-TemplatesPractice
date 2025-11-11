#pragma once
#include <iostream>
#include "clsDblLinkedList.h"
using namespace std;

// Template Queue Library - 11/11/2025 - Developer: Mr.Key47

/*
// In this project, I use Composition concept to create an object from Base Class (Template Double Linked List).
// I didn't use inheritance because I didn't use all methods of Base Class.
*/

template <class T> class clsMyQueue
{
protected:
	clsDblLinkedList<T> _MyList;

public:
	void push(T Data)
	{
		_MyList.InsertAtEnd(Data);
	}

	int Size()
	{
		return _MyList.Size();
	}

	T front()
	{
		return _MyList.GetItem(1); // Head Node's Data
	}

	T back()
	{
		return _MyList.GetItem(_MyList.Size()); // Tail Node's Data
	}

	T GetItem(short Index)
	{
		return _MyList.GetItem(Index);
	}

	void Reverse()
	{
		_MyList.Reverse();
	}

	void UpdateItem(short Index, T NewData)
	{
		_MyList.UpdateItem(Index, NewData);
	}

	void InsertAfter(short Index, T NewData)
	{
		_MyList.InsertAfter(Index, NewData);
	}

	void InsertAtFront(T NewData)
	{
		_MyList.InsertAtBeginning(NewData);
	}

	void InsertAtBack(T NewData)
	{
		_MyList.InsertAtEnd(NewData);
	}

	void pop()
	{
		_MyList.DeleteFirstNode(); // set new head node
	}

	bool IsEmpty()
	{
		return _MyList.IsEmpty();
	}

	void Clear()
	{
		_MyList.Clear();
	}

	void Print()
	{
		_MyList.PrintList();
	}
};