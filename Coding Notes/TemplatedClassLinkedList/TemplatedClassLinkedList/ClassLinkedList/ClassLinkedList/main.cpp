// Andrew S. O'Fallon
// This example implements some of the methods for a linked list class that we implemented in lecture
// This illustrates how to use templated container classes
// This example provides limited comments

#include "List.h"

int main (void)
{
	List<int> list1; // Templated list!
	List<string> list2;

	list1.insertAtFront (15);
	list1.insertAtFront (25);

	list2.insertAtFront ((std::string) "string1");
	list2.insertAtFront ((std::string) "string2");

	ListNode<int> *intNodePtr = list1.getStartPtr ();
	ListNode<string> *stringNodePtr = list2.getStartPtr ();

	cout << "List1: " << intNodePtr->getData () << " " << intNodePtr->getNextPtr ()->getData () << endl;
	cout << "List2: " << stringNodePtr->getData () << " " << stringNodePtr->getNextPtr ()->getData () << endl;

	cout << "Test List insertion operator: " << list1;

	return 0;
}