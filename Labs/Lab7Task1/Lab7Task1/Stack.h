#include <iostream>
#include <cstdlib>
#include <string>

using std::iosteram;
using std::cerr;
using std::endl;
using std::cin;
using std::cout;
using std::cerr;

class StackNode
{
	friend class Stack;
	friend ostream & operator << (ostream &out, StackNode const &pNode);
	public:
		StackNode ();
		StackNode (char d);
		~StackNode ();
		
		char getData (void);
		StackNode *getPNext (void);
	private:
		char data;
		StackNode *pNext;
}

class Stack
{
	friend ostream & operator << (ostream &out, Stack const &s);
	public:
		Stack ();
		Stack (Stack &right);
		~Stack ();

		Stack& operator=(Stack &right);

		void push (char d);
		void pop (void);
		char top (void);
		bool isEmpty (void);
	private:
		int size;
		StackNode *mTop;
}