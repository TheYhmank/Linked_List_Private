// Linked lists are able to add another Node in the middle or anywhere between
// How to implimet add after code

// 2 3 1 7 -> from the linked list, now let's add -4 between 3 and 1

typedef struct Node
{
	int x;
	struct Node* next;
}			   Node;

#include <stdio.h>
#include <stdlib.h>

void deallocate(Node** root)
{
	Node* curr = *root;
	while (curr)
	{
		Node *aux = curr;
		curr = curr->next;
		free(aux);
	}
	*root = NULL;
}

void insert_end(Node** root, int value)
{
	Node* new_node = malloc(sizeof(Node));

	new_node->next = NULL;
	new_node->x = value;

	if (*root == NULL)
	{
		*root = new_node;
		return ; 
	}
	
	Node* curr = *root;
	while (curr->next)
	{
		curr = curr->next;
	}
	curr->next = new_node;
}

void insert_after(Node* node, int value)
{
	Node* new_node = malloc(sizeof(Node));
	new_node->x = value;
	new_node->next = node->next;

	node->next = new_node;
}

int main(int argc, char const *argv[])
{
	Node* root = NULL;

	insert_end(&root, 2);
	insert_end(&root, 3);
	insert_end(&root, 1);
	insert_end(&root, 7);

	insert_after(root->next, -4);

	Node* curr = root;
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
