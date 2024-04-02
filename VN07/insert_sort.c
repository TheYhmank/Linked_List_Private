#include <stdio.h>
#include <stdlib.h>

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

void insert_beginning(t_list** root, int value)
{
	t_list* new_node = malloc(sizeof(t_list));
	if (!(new_node))
		exit(1);
	new_node->next = *root;
	//Currect created node will point to the privious node
	new_node->x = value;

	*root = new_node;
	//our root becomes new node
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

void add_after(t_list* root, int value)
{
	t_list *new_node = malloc(sizeof(t_list));
	new_node->next = root->next;
	new_node->x = value;

	root->next = new_node;
}

void sort_insert(t_list** root, int value)
{
	if (*root == NULL || (**root).x >= value)
	{
		insert_beginning(root, value);
		return ;
	}
	
	t_list* curr = *root;
	while (curr->next)
	{
		if (curr->next->x >= value)
		{
			add_after(curr, value);
			return ;
		}
		curr = curr->next;
	}
	add_after(curr, value);
}

int main(int argc, char const *argv[])
{
	t_list* root = malloc(sizeof(t_list));
	root->next = NULL;
	root->x = 23;

	insert_end(&root, -98);
	insert_end(&root, 24);
	insert_end(&root, 3);
	insert_end(&root, 89);

	sort_insert(&root, 99);

	t_list* curr = root;
	while (curr)
	{
		printf("%d\n", curr->x);
		curr = curr->next;
	}
	deallocate(&root);
	return 0;
}
