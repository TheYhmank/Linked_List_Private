// How to interatie over the linked lists

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node *next;
} Node;

int main(int argc, char const *argv[])
{
	Node root;

	root.data = 15;
	root.next = malloc(sizeof(Node));
	root.next->data = -2;
	root.next->next = NULL;

	Node *curr = &root;
	while (curr)
	{
		printf("%d\n", curr->data);
		curr = curr->next;
	}
	free(root.next); // avoid mammory leaks
	return 0;
}
