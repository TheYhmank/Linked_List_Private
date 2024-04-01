// How to dealocate the memory proparly
// Memory leaks should be avoided
// valgrind commad to cheak

typedef struct Node
{
	int x;
	struct Node* next;
} Node;

#include <stdio.h>
#include <stdlib.h>

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

void deallocate(Node **root)
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

int main(int argc, char const *argv[])
{
	Node* root = NULL;

	insert_end(&root, 23);
	insert_end(&root, -9);

	Node* curr = root;

	while (curr)
	{
		printf("%d", curr->x);
		curr = curr->next;
		if (curr)
			printf(" ");
	}
	
	deallocate(&root); // MAIN PART
	return 0;
}

