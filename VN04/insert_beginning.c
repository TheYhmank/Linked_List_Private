// How to insert at the beginning of the list
// Meaning that our first elem is the last one in the linked list

/*
	   New Node		   	   Staring point
    ______________		   _____________
	|	   |	  |		  | 	 |		|
	| Data | Node |<------| Data | Node |
	|______|______|		  |______|______|	

*/

// LAST-IN-FIRST-OUT acctual stack principles

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int x;
	struct Node* next;
} Node;

void deallocate(Node** root)
{
	Node* curr = *root;
	while (curr)
	{
		Node* aux = curr;
		curr = curr->next;
		free(aux);
	}
	*root = NULL;
}

void insert_beginning(Node** root, int value)
{
	Node* new_node = malloc(sizeof(Node));
	if (!(new_node))
		exit(1);
	new_node->next = *root;
	//Currect created node will point to the privious node
	new_node->x = value;

	*root = new_node;
	//our root becomes new node
}

int main(int argc, char const *argv[])
{
	Node* root = NULL;

	insert_beginning(&root, 23);
	insert_beginning(&root, -8);
	insert_beginning(&root, -2);

	Node *curr = root;
	while (curr)
	{
		printf("%d", curr->x);
		curr = curr->next;
		if (curr)
			printf(" ");
	}
	deallocate(&root);
	return 0;
}
