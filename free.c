#include "monty.h"

/**
	* freelist - void func
	* Description: frees passed args
	* @elements: passed doubly
	* @arrcmd: array of cmds
	*/
void freelist(stack_t **elements, char **arrcmd)
{
	int i;
	stack_t *tmp = NULL;
	stack_t *oldptr = NULL;

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
	free(elements);
	arrcmd = NULL;
	elements = NULL;
}
