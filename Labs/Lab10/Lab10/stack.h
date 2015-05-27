#ifndef STACK_H
#define STACK_H

#include "list.h"

template <class NODETYPE>
class Stack:private List<NODETYPE>
{
	public:
		Stack ();
		~Stack ();

		bool push ();
		bool pop ();
		bool top ();
		bool full ();
		bool empty ();
	private:
		int data;
};


#endif