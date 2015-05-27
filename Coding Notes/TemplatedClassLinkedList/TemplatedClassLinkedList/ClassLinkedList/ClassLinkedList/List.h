// Andrew S. O'Fallon
// This example implements some of the methods for a linked list class that we implemented in lecture
// This illustrates how to use templated container classes
// This example provides limited comments

#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <string>
#include "ListNode.h"

using std::cout;
using std::cin;
using std::string;
using std::ostream;
using std::endl;

template <class T>
class List
{
	// friend ostream & operator<< (ostream &output, List<T> &l);

	public:

		List ();
		List (List<T> & copyList); // deep copy
		~List ();

		List<T> & operator= (const List<T> &rhs);

		ListNode<T> * getStartPtr ();
		void setStartPtr (ListNode<T> *start);
		int getSize ();
		void setSize (int size);

		bool insertAtFront (T newData);
		bool deleteList (); // Destroy the list
		bool deleteNode (T &key);

	private:

		ListNode<T> *mStartPtr;
		int mSize;
		//ListNode<T> mlistArray[100]; // This is an alternative approach
};

template <typename T>
ostream & operator<< (ostream &output, List<T> &l)
{
	ListNode<T> *tempPtr = l.getStartPtr ();

	while (tempPtr != NULL)
	{
		output << tempPtr -> getData ()<< " ";
		tempPtr = tempPtr -> getNextPtr ();
	}

	output << endl;

	return output;
}

template <typename T>
List<T>::List ()
{
	mStartPtr = NULL;
	mSize = 0;
}

template <typename T>
List<T>::List (List<T> &copyList) // deep copy
{
	ListNode<T> *tempPtr = NULL, *memPtr = NULL, *currentPtr = NULL;

	mSize = 0;

	tempPtr = copyList.getStartPtr (); // Starting point for list
	                                   // that we want to copy
	while (tempPtr != NULL)
	{
		memPtr = new ListNode (tempPtr -> getData ());
		// Assume we are able to allocate memory successfully

		if (mSize == 0) // "This" list object is currently empty
		{
			mStartPtr = memPtr;
			currentPtr = mStartPtr;
		}
		else
		{
			currentPtr -> setNextPtr (memPtr);
			currentPtr = currentPtr -> getNextPtr ();
		}

		tempPtr = tempPtr -> getNextPtr ();

		mSize++;
	}
}

template <typename T>
List<T>::~List ()
{
	deleteList ();
}

template <typename T>
List<T> & List<T>::operator= (const List<T> &rhs)
{
	if (this != &rhs)
	{
		// Not complete
	}

	return *this;
}

template <typename T>
ListNode<T> * List<T>::getStartPtr ()
{
	return mStartPtr;
}

template <typename T>
void List<T>::setStartPtr (ListNode<T> *startPtr)
{
	mStartPtr = startPtr;
}

template <typename T>
int List<T>::getSize ()
{
	return mSize;
}

template <typename T>
void List<T>::setSize (int size)
{
	mSize = size;
}

template <typename T>
bool List<T>::insertAtFront (T newData)
{
	ListNode<T> *newNodePtr = NULL;

	bool success = true;

	newNodePtr = new ListNode<T> (newData);

	if (newNodePtr == NULL)
	{
		success = false;
	}
	else
	{
		if (mStartPtr == NULL) // empty list
		{
			mStartPtr = newNodePtr;
		}
		else // not empty
		{
			newNodePtr -> setNextPtr (mStartPtr);
			mStartPtr = newNodePtr;
		}

		mSize++;
	}

	return success;
}

template <typename T>
bool List<T>::deleteList ()
{
	ListNode<T> *tempPtr = NULL, *deletePtr = NULL;
	bool success = false;

	tempPtr = this -> mStartPtr;

	while (tempPtr != NULL)
	{
		deletePtr = tempPtr;
		tempPtr = tempPtr -> getNextPtr ();
		delete deletePtr;
		success = true;
	}

	return success;
}

template <typename T>
bool List<T>::deleteNode (T &key)
{
	bool success = false;
	ListNode<T> *previousPtr = NULL, *currentPtr = NULL, *tempPtr = NULL;

	currentPtr = mStartPtr;

	if (mStartPtr != NULL)
	{
		while ((currentPtr != NULL) && ((currentPtr -> getData ()) != key))
		{
			previousPtr = currentPtr;
			currentPtr = currentPtr -> getNextPtr ();
		}

		if ((currentPtr != NULL) && (previousPtr != NULL)) // found the node, but is not first node
		{
			tempPtr = currentPtr;
			previousPtr-> setNextPtr (currentPtr -> getNextPtr ());
			delete tempPtr;
			success = true;
		}
		else if (currentPtr != NULL) // first node needs to be deleted
		{
			tempPtr = currentPtr;
			mStartPtr = mStartPtr -> getNextPtr ();
			delete tempPtr;
			success = true;
		}
	}

	return success;
}

#endif