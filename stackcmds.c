#include "monty.h"

/**
	* push - void func
	* Description: adds arrcmd[1] to elements list
	* @elements: passed doubly list
	* @ln_num: passed line number of monty code
	* @arrcmd: array of cmds
	*/
void push(stack_t **elements, unsigned int ln_num, char **arrcmd)
{
	char *endptr = NULL;
	stack_t *tmp = NULL;
	stack_t *newnode = NULL;
	int value = 0;

	tmp = *elements;
	newnode = malloc(sizeof(stack_t));
	if (newnode == NULL)
		bad_malloc(elements, arrcmd);
	if (arrcmd[1] == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", ln_num);
		freelist(elements, arrcmd);
		exit(EXIT_FAILURE);
	}
	value = strtol(arrcmd[1], &endptr, 10);
	if (*endptr != '\0')
	{
		fprintf(stderr, "L%d: usage: push integer\n", ln_num);
		freelist(elements, arrcmd);
		free(newnode);
		exit(EXIT_FAILURE);
	}
	if (tmp == NULL)
	{
		newnode->n = value;
		newnode->next = NULL;
		newnode->prev = NULL;
		*elements = newnode;
		return;
	}
	while (tmp != NULL)
	{
		if (tmp->next == NULL)
		{
			newnode->n = value;
			newnode->next = NULL;
			newnode->prev = tmp;
			tmp->next = newnode;
			break;
		}
		tmp = tmp->next;
	}
}

/**
	* pall - void func
	* Description: prints whole doubly list
	* @elements: passed doubly list
	* @ln_num: passed line number of monty code
	* @arrcmd: array of cmds
	*/
void pall(stack_t **elements, unsigned int ln_num, char **arrcmd)
{
	stack_t *tmp = *elements;
	
	if (*elements == NULL || ln_num == 0 || arrcmd == NULL)
		return;
	while (tmp != NULL)
	{
		if (tmp->next == NULL)
			break;
		tmp = tmp->next;
	}
	while (tmp != NULL)
	{
		if (tmp->prev == NULL)
		{
			fprintf(stdout, "%d\n", tmp->n);
			break;
		}
		fprintf(stdout, "%d\n", tmp->n);
		tmp = tmp->prev;
	}
}

/**
        * pint - void func
        * Description: prints value at top stack
        * @elements: passed doubly list
        * @ln_num: passed line number of monty code
        * @arrcmd: array of cmds
        */
void pint(stack_t *elements, unsigned int ln_num, char **arrcmd)
{
	if (elements != NULL || ln_num > 0 || arrcmd != NULL)
		return;
}

/**
        * push - void func
        * Description: pops calue at top stack
        * @elements: passed doubly list
        * @ln_num: passed line number of monty code
        * @arrcmd: array of cmds
        */
void pop(stack_t **elements, unsigned int ln_num, char **arrcmd)
{
	stack_t *tmp = NULL;
	stack_t *prev = NULL;

	tmp = *elements;
	prev = *elements;
	if (tmp == NULL || ln_num == 0 || arrcmd == NULL)
		return;
	if (tmp->next == NULL)
		*elements = NULL;
	while (tmp != NULL)
	{
		if (tmp->next == NULL)
		{
			prev->next = NULL;
			free(tmp);
			break;
		}
		prev = tmp;
		tmp = tmp->next;
	}
}
