#include <stdlib.h>
#include <stdio.h>

typedef struct s_list
{
	int x;
	struct s_list* next;
} t_list;

void deallocate(t_list** root)
{
	t_list* curr = *root;

	while (curr)
	{
		t_list* aux = curr;
		curr = curr->next;
		free(aux);
	}
	*root = NULL;
}

void insert_end(t_list** root, int value)
{
	t_list* new_node = malloc(sizeof(t_list));

	new_node->next = NULL;
	new_node->x = value;

	if (*root == NULL)
	{
		*root = new_node;
		return ;
	}
	
	t_list* curr = *root;
	while (curr->next)
		curr = curr->next;
	curr->next = new_node;
}

void rm_elem(t_list** root, int value)
{
	if (*root == NULL)
		return ;

	if ((*root)->x == value)
	{
		t_list* first = *root;
		*root = (*root)->next;
		free(first);
		return;
	}
	
	t_list* curr = *root;
	while (curr->next)
	{
		if (curr->next->x == value)
		{
			t_list* to_remove = curr->next;
			curr->next = curr->next->next;
			free(to_remove);
			return;
		}
		curr = curr->next;
	}
}

int main(int argc, char const *argv[])
{
	t_list* root = malloc(sizeof(t_list));
	root->next = NULL;
	root->x = 23;

	insert_end(&root, -98);
	insert_end(&root, 24);
	insert_end(&root, 3);

	rm_elem(&root, 23);

	t_list* curr = root;
	while (curr)
	{
		printf("%d\n", curr->x);
		curr = curr->next;
	}
	deallocate(&root);
	return 0;
}
