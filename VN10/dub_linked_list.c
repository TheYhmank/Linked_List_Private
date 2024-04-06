#include <stdio.h>
#include <stdlib.h>

typedef struct s_list
{
	int data;
	struct s_list *next;
	struct s_list *prev;
}				t_list;

void add_beginning(t_list **node, int value)
{
	t_list *new_node = malloc(sizeof(t_list));

	new_node->data = value;
	new_node->next = *node;
	new_node->prev = NULL;
	if (*node)
		(*node)->prev = new_node;
	*node = new_node;
}

void init(t_list** start, t_list** end, int value)
{
	t_list *new_node = malloc(sizeof(t_list));
	new_node->data = value;
	new_node->prev = NULL;
	new_node->next = NULL;

	*start = new_node;
	*end = new_node;
}

int main(int argc, char const *argv[])
{
	t_list *start = NULL;
	t_list *end = NULL;

	init(&start, &end, 4);

	add_beginning(&start, 9);
	add_beginning(&start, 5);
	add_beginning(&start, 2);


	t_list* curr = end;
	while (curr)
	{
		printf("%d\n", curr->data);
		curr = curr->prev;
	}
	
	return 0;
}
