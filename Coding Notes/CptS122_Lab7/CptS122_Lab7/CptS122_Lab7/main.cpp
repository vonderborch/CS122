#include "stack.h"

int main (void) {

	Stack s, s1;

	s.push('A');
	s.push('R');
	s.push('E');

	cout << s;

	s.pop();

	s1 = s;

	cout << s1;

	return 0;
}