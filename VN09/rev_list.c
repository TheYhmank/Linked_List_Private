
typedef struct s_list
{
	int x;
	struct s_list* next;
} t_list;

#include <stdio.h>
#include <stdlib.h>

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
	{
		curr = curr->next;
	}
	curr->next = new_node;
}

void deallocate(t_list **root)
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

void rev_list(t_list** root)
{
	t_list *prev = NULL;
    t_list *current = *root;
    t_list *next = NULL;

    while (current != NULL)
    {
        next = current->next;

        current->next = prev;

        prev = current;
        current = next;
    }
    *root = prev;
}

int main(int argc, char const *argv[])
{
	t_list* root = NULL;

	insert_end(&root, 1);
	insert_end(&root, 2);
	insert_end(&root, 3);

	rev_list(&root);

	t_list* curr = root;
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

