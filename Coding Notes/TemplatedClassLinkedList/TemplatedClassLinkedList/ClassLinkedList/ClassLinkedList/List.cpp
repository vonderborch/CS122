#include "List.h"
#include "ListNode.h"

ostream & operator<< (ostream &output, List &l)
{
	ListNode *tempPtr = l.getStartPtr ();

	while (tempPtr != NULL)
	{
		output << tempPtr -> getString ();
		tempPtr = tempPtr -> getNextPtr ();
	}

	return output;
}

List::List ()
{
	mStartPtr = NULL;
	mSize = 0;
}

List::List (List &copyList) // deep copy
{
	ListNode *tempPtr = NULL, *memPtr = NULL, *currentPtr = NULL;

	mSize = 0;

	tempPtr = copyList.getStartPtr (); // Starting point for list
	                                   // that we want to copy
	while (tempPtr != NULL)
	{
		memPtr = new ListNode (tempPtr -> getString ());
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

List::~List ()
{
	deleteList ();
}

List & List::operator= (const List &rhs)
{
	if (this != &rhs)
	{
		// Not complete
	}

	return *this;
}

ListNode * List::getStartPtr ()
{
	return mStartPtr;
}
		
void List::setStartPtr (ListNode *startPtr)
{
	mStartPtr = startPtr;
}

int List::getSize ()
{
	return mSize;
}

void List::setSize (int size)
{
	mSize = size;
}

bool List::insertAtFront (string newString)
{
	ListNode *newNodePtr = NULL;

	bool success = true;

	newNodePtr = new ListNode (newString);

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
		
bool List::deleteList ()
{
	ListNode *tempPtr = NULL, *deletePtr = NULL;
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

bool List::deleteNode (string &key)
{
	bool success = false;
	ListNode *previousPtr = NULL, *currentPtr = NULL, *tempPtr = NULL;

	currentPtr = mStartPtr;

	if (mStartPtr != NULL)
	{
		while ((currentPtr != NULL) && ((currentPtr -> getString ()) != key))
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