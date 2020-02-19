#include <iostream>

using namespace std;

template <class T>
class ListNode
{
public:
	ListNode();
	ListNode(float k, T d);
	~ListNode();
	T data;
	float key;
	ListNode *next;
	ListNode *prev;
};

/**
Default constructor
*/
template <class T>
ListNode<T>::ListNode()
{
	key = 0;
	data = NULL;
	next = NULL;
	prev = NULL;
}

/**
Overloaded constructor
@param d Data of node
*/
template <class T>
ListNode<T>::ListNode(float k, T d)
{
	key = k;
	data = d;
	next = NULL;
	prev = NULL;
}

/**
Destructor
*/
template <class T>
ListNode<T>::~ListNode()
{
	delete next;
	delete prev;
}
