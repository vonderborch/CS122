#include "stack.h"

StackNode::StackNode() {
	data = '\0';
	ptr = NULL;
}

StackNode::StackNode(char d) {
	data = d;
	ptr = NULL;
}

StackNode::~StackNode() {
}

char StackNode::getData(void) {
	return data;
}

StackNode *StackNode::getPtr(void) {
	return ptr;
}

ostream& operator<<(ostream& out, StackNode const& pMem) {
	out << pMem.data << " => ";
	return out;
}

Stack::Stack() {
	size = 0;
	mTop = NULL;
}

Stack::Stack(Stack &right) {
	Stack s;
	
	while(!right.isEmpty()) {
		s.push(right.top());
		right.pop();		
	}
	while(!s.isEmpty()) {
		right.push(s.top());
		push(s.top());
		s.pop();
	}
}

Stack::~Stack() {
	while (!this->isEmpty()) {
		this->pop();
	}
}

Stack &Stack::operator=(Stack &right)
{
	if (this != &right) // self-referential assignment
	{
		Stack s;
	
		while(!right.isEmpty()) {
			s.push(right.top());
			right.pop();		
		}
		while(!s.isEmpty()) {
			right.push(s.top());
			push(s.top());
			s.pop();
		}
	}

	return (*this);
}

void Stack::push(char d) {
	StackNode *pMem = new StackNode(d);

	if (pMem == NULL)
		cerr << "Could not allocate new StackNode!" << endl;
	else
	{
		pMem->ptr = mTop;
		mTop = pMem;
		size++;
	}
}

void Stack::pop(void) {
	StackNode *tmp = mTop;

	if (isEmpty())
		cerr << "Cannot pop from an empty stack" << endl;
	else
	{
		mTop = mTop->ptr;
		delete tmp;
		size--;
	}
}

char Stack::top(void) {
	if (isEmpty())
		cerr << "Cannot get top of an empty stack" << endl;
	else
		return mTop->data;
	return '\0';
}

bool Stack::isEmpty(void) {
	return (mTop == NULL);
}

ostream& operator<<(ostream& out, Stack const& s) {
	StackNode *tmp = s.mTop;

	out << "Stack (size=" << s.size << "): " << endl;
	while (tmp != NULL)
	{
		out << *tmp;
		tmp = tmp->getPtr();
	}
	out << "NULL" << endl;

	return out;
}