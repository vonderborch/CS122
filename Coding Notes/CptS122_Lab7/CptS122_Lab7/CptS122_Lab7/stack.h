// stack.h
#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <cstdlib>
#include <string>

using std::ostream;
using std::cerr;
using std::endl;
using std::cout;

class StackNode {
	friend class Stack;
	friend ostream& operator<<(ostream& out, StackNode const& pMem);
public:
	StackNode();
	StackNode(char d);
	~StackNode();

	char getData(void);
	StackNode *getPtr(void);
private:
	char data;
	StackNode *ptr;
};

class Stack {
	friend ostream& operator<<(ostream& out, Stack const& s);
public:
	Stack();
	Stack(Stack &right);
	~Stack();

	Stack &operator=(Stack &right);

	void push(char d);
	void pop(void);
	char top(void);
	bool isEmpty(void);

private:
	int size;
	StackNode *mTop;
};

#endif // STACK_H
