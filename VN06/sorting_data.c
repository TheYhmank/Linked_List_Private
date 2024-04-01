// how to sort your linked list from the min to max
// for instance: 2 0 3 5 4 1 -----> 0 1 2 3 4 5

#include <stdio.h>
#include <stdlib.h>

typedef struct s_type
{
	int x;
	struct s_type* next;
} t_type;

void insert_end(t_type** root, int value)
{
	t_type* new_node = malloc(sizeof(t_type));
	if (!new_node)
		exit(1);
	new_node->next = NULL;
	new_node->x = value;

	if (*root == NULL)
	{
		*root = new_node;
		return;
	}
	t_type* curr = *root;
	while (curr->next)
		curr = curr->next;
	curr->next = new_node;
}

int ascending(int a, int b)
{
	return a <= b;
}

void list_sort(t_type** root, int (*cmp)(int, int))
{
    /*do this part*/
}

int main(int argc, char const *argv[])
{
	t_type *root = NULL;

	insert_end(&root, 1);
	insert_end(&root, 3);
	insert_end(&root, 2);
	insert_end(&root, 5);

	list_sort(&root, ascending);

	t_type* curr = root;
	while (curr)
	{
		printf("%d", curr->x);
		curr = curr->next;
		if (curr)
			printf(" ");
	}

	return 0;
}
