//Adding elements to Linked list.

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int x;
	struct Node *next;
} 			   Node;

void insert_list(Node** root, int value)
{
	Node *new_node = malloc(sizeof(Node));
	if (!(new_node))
		exit(1);
	new_node->next = NULL;
	// for setting up the ending point
	new_node->x = value;

	if (*root == NULL)
	{
		*root = new_node;
		// if the staring elem is NULL make staring elem as new_node
		return;
	}

	Node *curr = *root;
	while (curr->next)
	{
		curr = curr->next;
	}
	curr->next = new_node;
}

int main(int argc, char const *argv[])
{
	Node* root = NULL;

	// staring elem is NULL

	insert_list(&root, -9);
	insert_list(&root, 7);

	Node *curr = root;
	while (curr)
	{
		printf("%d", curr->x);
		curr = curr->next;
		if (curr)
		{
			printf(" ");
		}
	}
	//free(root);	
}

