#include "list.h"

// CLASS: LISTNODE
template <class NODETYPE>
ListNode<NODETYPE>::ListNode (const NODETYPE &rhs)
{
	this->data = rhs->data;
}

template <class NODETYPE>
NODETYPE ListNode<NODETYPE>::getData () const
{
	return this->data;
}


// CLASS: LIST
template <class NODETYPE>
List<NODETYPE>::List ()
{
	this->*firstPtr = NULL;
	this->*lastPtr = NULL;
}

template <class NODETYPE>
List<NODETYPE>::~List ()
{
	ListNode<NODETYPE> temp = NULL;
	while (!isEmpty ())
	{
		removeFromFront (NODETYPE &temp);
	}
}

template <class NODETYPE>
void List<NODETYPE>::insertAtFront (const NODETYPE &newData)
{
	ListNode<NODETYPE> temp = this->firstPtr;
	ListNode<NODETYPE> tempB = new ListNode (newData);
}

template <class NODETYPE>
void List<NODETYPE>::insertAtBack (const NODETYPE &newData)
{
}

template <class NODETYPE>
bool List<NODETYPE>::removeFromFront (NODETYPE &oldData)
{
}

template <class NODETYPE>
bool List<NODETYPE>::removeFromBack (NODETYPE &oldData)
{
}

template <class NODETYPE>
bool List<NODETYPE>::isEmpty () const
{
	bool emptinessness = true;

	if (this->firstPtr != NULL)
	{
		emptinessness = false;
	}

	return emptinessness;
}

template <class NODETYPE>
void List<NODETYPE>::print () const
{
}