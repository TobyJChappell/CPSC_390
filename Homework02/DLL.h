#ifndef DLL_H
#define DLL_H

#include <iostream>
#include "ListNode.h"

using namespace std;

template <class T>
class DLL
{
private:
	ListNode<T> *front;
	ListNode<T> *back;
	unsigned int size;
public:
	DLL();
	~DLL();
	T& getFront();
	void insertFront(float key, T data);
	void insert(float key, T data);
	void insertBack(float key, T data);
	T removeFront();
	void printList();
	int find(float key);
	bool isEmpty();
	unsigned int getSize();
};

/**
Default constructor
*/
template <class T>
DLL<T>::DLL()
{
	size = 0;
	front = NULL;
	back = NULL;
}

/**
Destructor
*/
template <class T>
DLL<T>::~DLL()
{
	while(!isEmpty())
	{
		removeFront();
	}
	delete front;
	delete back;
}

/**
Returns the first node
@return T& The data of the first node
*/
template <class T>
T& DLL<T>::getFront()
{
	return front->data;
}

/**
Inserts a node to the front of the list
@param data Value being inserted
*/
template <class T>
void DLL<T>::insertFront(float key, T data)
{
	ListNode<T> *node = new ListNode<T>(key, data);
	if(size == 0)
	{
		back = node;
	}
	else
	{
		node->next = front;
		front->prev = node;
	}
	front = node;
	size++;
}

/**
Inserts a node to the list based on its key
@param data Value being inserted
*/
template <class T>
void DLL<T>::insert(float key, T data)
{
	if(size == 0)
	{
		insertFront(key, data);
		return;
	}
	ListNode<T> *current = front;

	while(current->key < key)
	{
		current = current->next;
		if(current == NULL)
		{
			insertBack(key, data);
			return;
		}
	}
	if(current == front)
	{
		insertFront(key, data);
		return;
	}
	ListNode<T> *node = new ListNode<T>(key, data);
	node->next = current;
	node->prev = current->prev;
	current->prev = node;
	current->prev->prev->next = node;

	size++;
}

/**
Inserts a node into the back of the list
@param data Value being inserted
*/
template <class T>
void DLL<T>::insertBack(float key, T data)
{
	ListNode<T> *node = new ListNode<T>(key, data);
	if(size == 0)
	{
		front = node;
	}
	else
	{
		back->next = node;
		node->prev = back;
	}
	back = node;
	size++;
}

/**
Removes the front node from the list
@return T value of the node
*/
template <class T>
T DLL<T>::removeFront()
{
	if(size == 0)
	{
		cerr << "ERROR: Doubly Linked List is empty." << endl;
		exit(EXIT_FAILURE);
	}
	ListNode<T> *node = front;
	if(front->next == NULL)
	{
		back = NULL;
	}
	else
	{
		front->next->prev = NULL;
	}
	front = front->next;
	T temp = node->data;
	node->next = NULL;

	delete node;
	size--;

	return temp;
}

/**
Prints the values of the list
*/
template <class T>
void DLL<T>::printList()
{
	ListNode<T> *current = front;
	while(current != NULL)
	{
		cout << current->key << " ";
		current = current->next;
	}
	cout << endl;
}

/**
Returns whether the list is empty
@return bool True if list is empty
*/
template <class T>
bool DLL<T>::isEmpty()
{
	return (size == 0);
}

/**
Returns the size of the list
*/
template <class T>
unsigned int DLL<T>::getSize()
{
	return size;
}

#endif
