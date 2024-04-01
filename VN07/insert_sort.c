// how to insert an element inside a linked list in such a way that it keeps liked list sorted.

#include <stdio.h>
#include <stdlib.h>

typedef struct s_list
{
	int x;
	struct s_list *next;
	
}			   t_list;

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

void insert_after(t_list* root, int value)
{
	t_list* new_node = malloc(sizeof(t_list));

	new_node->next = root->next;
	new_node->x = value;

	root->next = new_node;
}

void insert_beginning(t_list** root, int value)
{
	t_list* new_node = malloc(sizeof(t_list));

	new_node->next = *root;
	new_node->x = value;

	*root = new_node;
}

void insert_sorted(t_list** root, int value)
{
	if (*root == NULL || (**root).x	>= value)
	{
		insert_beginning(root, value);
		return;
	}

	t_list* curr = *root;
	while (curr->next)
	{
		if (curr->next->x >= value)
		{
			insert_after(curr, value);
			return ;
		}
		curr = curr->next;
	}
	insert_after(curr, value);
}

int main(void)
{
    t_list* root = NULL;

    insert_end(&root, 1);
    insert_end(&root, 9);
    insert_end(&root, 8);

	insert_sorted(&root, 10);

    t_list* curr = root;
    while (curr)
    {
        printf("%d", curr->x);
        curr = curr->next;
        if (curr)  // Check if curr is not NULL before accessing its members
            printf(" ");
    }

    return 0;
}


