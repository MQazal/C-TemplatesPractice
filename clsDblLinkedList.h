#pragma once
#include <iostream>
using namespace std;

// Template Doubly Linked List Library - 11/11/2025 - Developer: Mr.Key47

template <class T> class clsDblLinkedList
{
protected:
	int _Size = 0;

public:
	class Node
	{
	public:
		Node* Previous;
		T Data;
		Node* Next;
	};

public:
	Node* Head = NULL; // global variable points to first node only, to use it you create a node to save its content

	void InsertAtEnd(T Data)
	{
		// * set new tail node

		// Create
		Node* new_tail_node = new Node();
		// set data and points to NULL
		new_tail_node->Previous = NULL;
		new_tail_node->Data = Data;
		new_tail_node->Next = NULL;

		// check if list is empty
		if (Head == NULL)
		{
			// set tail node as head node
			Head = new_tail_node;
			_Size++;
			return;
		}

		// set tail node
		Node* temp = Head;
		while (temp->Next != NULL)
		{
			temp = temp->Next;
		}
		temp->Next = new_tail_node; // old tail node pointed to NULL , now it points to new tail node
		new_tail_node->Previous = temp;
		_Size++;
	}

	void InsertAtBeginning(T Data)
	{
		// * set new head node

		// Create
		Node* new_head_node = new Node();
		// set data and points to NULL
		new_head_node->Previous = NULL;
		new_head_node->Data = Data;
		new_head_node->Next = NULL;

		// check if list is empty
		if (Head == NULL)
		{
			Head = new_head_node;
			_Size++;
			return;
		}

		// set head node
		Head->Previous = new_head_node;
		new_head_node->Next = Head;
		Head = new_head_node;
		_Size++;
	}

	void InsertAfter(Node* Current, T Data)
	{
		// * set node in the middle of list by using an existing node

		if (IsNodeExist(Current))
		{
			Node* New_Node = new Node();
			New_Node->Previous = NULL;
			New_Node->Data = Data;
			New_Node->Next = NULL;

			// set next of New_Node to node after current node
			New_Node->Next = Current->Next;

			// set next of current node to New_Node
			Current->Next = New_Node;

			// set previous of New_Node to current node
			New_Node->Previous = Current;
			_Size++;
		}
		else
			cout << "\nNode not exist!\n";
	}

	void InsertAfter(short Index, T Data)
	{
		// * set node in the middle of list by using index of existing node
		Node* Current = GetNode(Index);
		if (Current != NULL)
			InsertAfter(Current, Data);
		else
			cout << "\nIndex not found :(\n";
	}

	Node* Find(T Data)
	{
		Node* Current = Head;
		while (Current != NULL)
		{
			if (Current->Data == Data)
				return Current;
			Current = Current->Next;
		}
		return NULL;
	}

	bool IsNodeExist(Node* NodeToSearch)
	{
		return NodeToSearch != NULL;
	}

	void DeleteNode(Node* NodeToDelete)
	{
		// List is empty
		if (Head == NULL)
		{
			cout << "\n\nOops, list is empty!\n\n";
			return;
		}

		// Node is not found
		if (NodeToDelete == NULL)
		{
			cout << "\n\nOops, node is not found!\n\n";
			return;
		}

		// 1 Node:
		// Case1: list has 1 node
		if (NodeToDelete->Next == NULL)
		{
			if (NodeToDelete->Previous == NULL)
			{
				Head = NULL;
				cout << "\n\nNode " << NodeToDelete->Data << " is deleted and list becomes empty.\n\n";
				_Size = 0;
			}
			// Case2: tail node
			else
			{
				// set new tail node
				NodeToDelete->Previous->Next = NULL;
				cout << "\n\ntail node " << NodeToDelete->Data << " is deleted.\n\n";
				_Size--;
			}
		}

		// Head Node
		if (NodeToDelete->Previous == NULL)
		{
			// set new Head Node
			Head = NodeToDelete->Next;
			NodeToDelete->Next->Previous = NULL;
			cout << "\n\nHead Node " << NodeToDelete->Data << " is deleted.\n\n";
			_Size--;
		}

		// Middle node
		if (NodeToDelete->Previous != NULL && NodeToDelete->Next != NULL)
		{
			NodeToDelete->Previous->Next = NodeToDelete->Next;
			NodeToDelete->Next->Previous = NodeToDelete->Previous;
			cout << "\n\nNode " << NodeToDelete->Data << " is deleted.\n\n";
			_Size--;
		}
	}

	void DeleteFirstNode()
	{
		Node* head_node = Head;

		if (head_node == NULL)
		{
			cout << "\nList is empty!\n";
			return;
		}

		if (head_node->Next == NULL)
		{
			Head = NULL;
			_Size = 0;
			return;
		}

		// set new head node
		Head = head_node->Next;
		head_node->Next->Previous = NULL;
		head_node->Next = NULL;
		_Size--;
	}

	void DeleteLastNode()
	{
		Node* tail_node = Head;

		if (tail_node == NULL)
		{
			cout << "\nList is empty!\n";
			return;
		}

		if (tail_node->Next == NULL)
		{
			Head = NULL;
			cout << "\nNode is deleted and list becomes empty!\n";
			_Size = 0;
			return;
		}

		// find tail node
		while (tail_node->Next != NULL)
		{
			tail_node = tail_node->Next;
		}
		// set new tail node
		tail_node->Previous->Next = NULL;
		cout << "\ntail node " << tail_node->Data << " is deleted.\n";
		_Size--;
	}

	int Size()
	{
		return _Size;
	}

	bool IsEmpty()
	{
		return _Size == 0;
	}

	void Clear()
	{
		while (_Size > 0)
		{
			DeleteFirstNode(); // delete each node from memory and decrease size
		}
	}

	void Reverse()
	{
		Node* Current = Head;
		Node* temp = nullptr;
		// reverse full list
		while (Current != nullptr)
		{
			temp = Current->Previous;
			Current->Previous = Current->Next;
			Current->Next = temp;
			Current = Current->Previous;
		}
		// set new head node
		if (temp != nullptr)
			Head = temp->Previous;
	}

	Node* GetNode(short Index)
	{
		if (Index > _Size || Index < 0)
			return NULL;

		Node* Current = Head;
		for (short i = 0; i < Index; i++)
		{
			if (i == Index - 1)
				return Current;
			Current = Current->Next;
		}
	}

	T GetItem(short Index)
	{
		//return GetNode(Index) == NULL ? NULL: GetNode(Index)->Data;
		Node* ItemNode = GetNode(Index);
		return ItemNode == NULL ? NULL : ItemNode->Data;
	}

	void UpdateItem(short Index, T NewData)
	{
		Node* NodeToUpdate = GetNode(Index);
		if (NodeToUpdate == NULL)
			return;
		NodeToUpdate->Data = NewData;
	}

	void PrintList()
	{
		Node* Current = Head;
		cout << "NULL <--> ";
		while (Current != NULL)
		{
			cout << Current->Data << " <--> ";
			Current = Current->Next;
		}
		cout << "NULL\n\n";
	}
};