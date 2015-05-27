// Andrew S. O'Fallon
// This example implements some of the methods for a linked list class that we implemented in lecture
// This illustrates how to use templated container classes
// This example provides limited comments

#ifndef LISTNODE_H
#define LISTNODE_H

#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::string;

template <typename T>
class ListNode
{
	public:
		ListNode (T newData, ListNode<T> *newPtr = NULL);
		ListNode (ListNode<T> &newNode);
		~ListNode ();

		ListNode & operator= (const ListNode<T> &rhs);

		T getData (void) const;
		void setData (T newData);

		ListNode<T> * getNextPtr (void) const;
		void setNextPtr (ListNode<T> *nextPtr);

	private:
		T mData;
		ListNode *mNextPtr;
};

template <typename T>
ListNode<T>::ListNode (T newData, ListNode<T> *newPtr)
{
	this -> mData = newData;
	this -> mNextPtr = newPtr;
}

template <typename T>
ListNode<T>::ListNode (ListNode<T> &newNode)
{
	// Shallow copy
	this -> mData = newNode.getData ();
	this -> mNextPtr = newNode.getNextPtr ();

	// Deep copy
	// same as shallow copy for this class
}

template <typename T>
ListNode<T>::~ListNode ()
{
	// All deleting will be done by List's destructor
}

template <typename T>
ListNode<T> & ListNode<T>::operator= (const ListNode<T> &rhs)
{
	if (this != &rhs)
	{
		this -> mData = rhs.getData ();
		this -> mNextPtr = rhs.getNextPtr ();
	}

	return *this;
}

template <typename T>
T ListNode<T>::getData (void) const
{
	return mData;
}

template <typename T>
void ListNode<T>::setData (T newData)
{
	mData = newData;
}

template <typename T>
ListNode<T> * ListNode<T>::getNextPtr (void) const
{
	return mNextPtr;
}

template <typename T>
void ListNode<T>::setNextPtr (ListNode<T> *nextPtr)
{
	mNextPtr = nextPtr;
}

#endif