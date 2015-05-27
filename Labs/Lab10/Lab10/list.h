#ifndef LIST_H
#define LIST_H

template <class NODETYPE> class List;  // forward declaration

// LIST NODE
template <class NODETYPE>
class ListNode
{
	friend class List <NODETYPE>; // make List a friend
	public:
	   ListNode (const NODETYPE &rhs);  // copy constructor
	   NODETYPE getData () const;      // return data in the node

	private:
	   NODETYPE data;                 // data
	   ListNode <NODETYPE> *nextPtr; // next node in the list
};

// LIST
template <class NODETYPE>
class List
{
	public:
	   List ();      // constructor
	   ~List ();     // destructor
	   void insertAtFront (const NODETYPE &newData);
	   void insertAtBack (const NODETYPE &newData);
	   bool removeFromFront (NODETYPE &oldData);
	   bool removeFromBack (NODETYPE &oldData);
	   bool isEmpty () const;
	   void print () const;

	private:
	   ListNode <NODETYPE> *firstPtr;  // pointer to first node
	   ListNode <NODETYPE> *lastPtr;   // pointer to last node
	   // Utility function to allocate a new node
	   ListNode <NODETYPE> *getNewNode (const NODETYPE &newData);
};

#endif