#include "monty.h"

void freelist(stack_t **elements, char **arrcmd)
{
	int i;
	stack_t *tmp = NULL;
	stack_t *oldptr = NULL;

	printf("Start of free.c\n");
	if (elements != NULL)
		tmp = *elements;
	oldptr = tmp;
	while (tmp != NULL)
	{
		tmp->prev = NULL;
		tmp = tmp->next;
		free(oldptr);
		oldptr = tmp;
	}
	free(tmp);
	printf("After freeing stack_t\n");
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
	printf("After freeing arrcmd\n");
	*elements = NULL;
	free(elements);
	printf("After freeing elements\n");
	arrcmd = NULL;
	elements = NULL;
}
