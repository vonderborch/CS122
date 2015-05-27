#ifndef QUEUE_H
#define QUEUE_H

#include "list.h"

template <class NODETYPE>
class Queue:private List<NODETYPE>
{
	public:
		Queue ();
		~Queue ();

		bool enqueue (NODETYPE newData);
		bool dequeue (void);
		NODETYPE front (void);
		bool full ();
		bool empty ();
	private:
		int data;
};

#endif