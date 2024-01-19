#include "monty.h"

void freelist(stack_t **elements, char **arrcmd)
{
	int i;
	stack_t *tmp = *elements;
	stack_t *prev = *elements;

	while (tmp != NULL)
	{
		tmp = tmp->next;
		free(prev);
		prev = tmp;
	}
	if (arrcmd != NULL)
	{
		for (i = 0; arrcmd[i] != NULL; i++)
		{
			free(arrcmd[i]);
			arrcmd[i] = NULL;
		}
	}
	if (arrcmd != NULL)
		free(arrcmd);
	*elements = NULL;
}
