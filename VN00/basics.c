// The way of storing many elements of the same type in a very interesting manner

/*
	______________		  _______________	
	|	   |	  |		  |	     |	 	|
	| DATA | NODE |------>| DATA | NODE |---->NULL
	|______|______|		  |______|______|

*/

typedef struct Node
{
	int x;
	struct Node *next;
}			   Node;

#include <stdio.h>

// NON-dynamic way of using the linked list.

int main(int argc, char const *argv[])
{
	Node root, elem2;

	root.x = 15;
	root.next = &elem2;
	// to point to the next node elem2
	elem2.x = -2;

	elem2.next = NULL;

	printf("%d and %d", root.x, root.next->x);
	return 0;
}

