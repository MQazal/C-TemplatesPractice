#pragma once
#include <iostream>
using namespace std;

// Template Double Array Library - 12/11/2025 - Developer: Mr.Key47

template <class T> class clsDynamicArray
{
protected:
	short _Size = 0;
	// declare 2 global pointers in Stack memory
	T* OriginalArray;
	T* tempArray;

public:
	clsDynamicArray(short Size = 0)
	{
		if (Size < 0)
		{
			Size = 0;
		}
		_Size = Size;
		OriginalArray = new T[_Size]; // pointer points to dynamic array in heap memory
	}

	void setItem(short Index, T Value)
	{
		if (Index >= _Size || Index < 0)
			return;
		else
		OriginalArray[Index] = Value;
	}

	bool InsertAt(short Index, T Value)
	{
		if (Index > _Size || Index < 0)
		{
			cout << "\nInvalid Index!\n";
			return false;
		}

		_Size++;
		tempArray = new T[_Size];

		// Copy until index before Target index
		for (short i = 0; i < Index; i++)
		{
			tempArray[i] = OriginalArray[i];
		}

		tempArray[Index] = Value; // assign new value to Target index

		// Copy after Target index
		for (short i = Index + 1; i < _Size; i++)
		{
			tempArray[i] = OriginalArray[i - 1];
		}

		delete[]OriginalArray;
		OriginalArray = tempArray;
		return true;
	}

	bool InsertAtBeginning(T Value)
	{
		return InsertAt(0, Value);
	}

	bool InsertAtEnd(T Value)
	{
		return InsertAt(_Size, Value);
	}

	bool InsertBefore(short Index, T Value)
	{
		if (Index < 1)
			return InsertAtBeginning(Value);
		else
			return InsertAt(Index - 1, Value);
	}

	bool InsertAfter(short Index, T Value)
	{
		if (Index >= _Size)
			return InsertAtEnd(Value);
		else
			return InsertAt(Index + 1, Value);
	}

	short Size()
	{
		return _Size;
	}

	bool IsEmpty()
	{
		return _Size == 0;
	}

	void Resize(short NewSize)
	{
		if (NewSize < 0)
			NewSize = 0;

		tempArray = new T[NewSize];

		_Size = NewSize; // Update global size

		for (short i = 0; i < _Size; i++)
		{
			tempArray[i] = OriginalArray[i];
		}

		delete[] OriginalArray;   // delete the old array that pointer points to it from memory
		OriginalArray = tempArray; // Pointer points to a new memory block of new array
		// new T[NewSize] array will be deleted when function's scope is end
	}

	T GetItem(short Index)
	{
		return OriginalArray[Index];
	}

	void Reverse()
	{
		tempArray = new T[_Size];
		for (short i = 0; i < _Size; i++)
		{
			tempArray[i] = OriginalArray[_Size - 1 - i];
		}
		delete[]OriginalArray;
		OriginalArray = tempArray;
	}

	bool DeleteItemAt(short IndexToDelete)
	{
		if (IndexToDelete >= _Size || IndexToDelete < 0)
			return false;

		tempArray = new T[_Size - 1];
		short ValidIndex = 0;
		for (short i = 0; i < _Size; i++)
		{
			if (i != IndexToDelete)
			{
				tempArray[ValidIndex] = OriginalArray[i];
				ValidIndex++;
			}
		}

		_Size--;
		delete[] OriginalArray;
		OriginalArray = tempArray;
		return true;
	}

	void DeleteFirstItem()
	{
		DeleteItemAt(0); // first index
	}

	void DeleteLastItem()
	{
		DeleteItemAt(_Size - 1); // last index
	}

	short Find(T Value)
	{
		for (short i = 0; i < _Size; i++)
		{
			if (OriginalArray[i] == Value)
				return i;
		}
		return -1;
	}

	bool DeleteItem(T Value)
	{
		return DeleteItemAt(Find(Value));
	}

	void Clear()
	{
		_Size = 0;
		tempArray = new T[0];
		delete[] OriginalArray;
		OriginalArray = tempArray;
	}

	void Print()
	{
		for (short i = 0; i < _Size; i++)
		{
			cout << OriginalArray[i] << "   ";
		}
	}

	~clsDynamicArray()
	{
		delete[] OriginalArray; // delete constructor's dynamic Array from heap memory
	}
};