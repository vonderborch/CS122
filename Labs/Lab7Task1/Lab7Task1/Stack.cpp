#include "Stack.h"

// STACKNODE
friend ostream & operator << (ostream &out, StackNode const &pNode)
{
	ouut << pNode.data << " => ";
	return out;
}

StackNode::StackNode ()
{
	pNext = NULL;
	data = '\0';
}

StackNode::StackNode (char d)
{
	pNext = NULL;
	data = d;
}

StackNode::StackNode (StackNode&right)
{
	data = right.data;
	pNext = right.pNext;
}

StackNode::~StackNode ()
{
	// nothing needed
}

char StackNode::getData (void)
{
}

StackNode StackNode::*getPNext (void)
{
}

// STACK
ostream & operator << (ostream &out, Stack const &s)
{
	StackNode *pTemp = s.mTop;
	out << "Stack (Size = " << s.size << "): "" << endl;
	while (pTemp != NULL)
	{
		out << pTemp;
		pTemp = pTemp->getPNext ();
	}
	out << "NULL" <<endl;
	return out;
}

Stack::Stack ()
{
	this->mTop = NULL;
	this->size = 0;
}

Stack::Stack (Stack &right)
{
	this = right;
	this->size = right->size;
}

Stack::~Stack ()
{
	while (!isEmpty ())
		this.pop ();
}

Stack& Stack::operator=(Stack &right)
{
}

void Stack::push (char d)
{
	StackNode *pNew = new StackNode (d);
	
	if (pNew == NULL)
	{
		cerr << "Could not allocate memory for a new Node!" << endl;
	}
	else
	{
		pNew->data = d;
		pNew->pNext = mTop;
		mTop = pNew;
		size+;
	}
}

void Stack::pop (void)
{
	StackNode *pTemp = mTop;

	if (!isEmpty ())
	{
		mTop = mTop->pNext;
		delete mTop;
		size--;
	}
}

char Stack::top (void)
{
	if (!isEmpty())
	{
		return mTop->data;
	}
}

bool Stack::isEmpty (void)
{
	return (mTop == NULL);
}