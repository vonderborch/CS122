#include "queue.h"
		Queue ();
		~Queue ();

		bool enqueue (NODETYPE newData);
		bool dequeue (void);
		NODETYPE front (void);
		bool full ();
		bool empty ();