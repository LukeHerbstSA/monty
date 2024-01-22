#include "monty.h"

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
		fprintf(stderr, "L%u: unknown instruction %s\n", ln_num, arrcmd[0]);
		freelist(elements, arrcmd);
		exit(EXIT_FAILURE);
	}
	value = strtol(arrcmd[1], &endptr, 10);
	if (*endptr != '\0')
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", ln_num, arrcmd[0]);
		freelist(elements, arrcmd);
		free(newnode);
		exit(EXIT_FAILURE);
	}
	printf("just before tmp assignment\nValue: %d\n", value);
	if (tmp == NULL)
	{
		printf("before setting newnode->n\n");
		newnode->n = value;
		printf("After setting newnode->n\n");
		newnode->next = NULL;
		newnode->prev = NULL;
		printf("After newnode assignment\n");
		*elements = newnode;
		return;
	}
	printf("After tmp == NULL assignment\n");
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

void pall(stack_t **elements, unsigned int ln_num, char **arrcmd)
{
	stack_t *tmp = *elements;
	
	if (*elements == NULL)
	{
		fprintf(stderr, "L%d: NULL list, arrcmd[0]: %s\n", ln_num, arrcmd[0]);
		return;
	}
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

void pint(stack_t *elements, unsigned int ln_num, char **arrcmd)
{
	if (elements != NULL || ln_num > 0 || arrcmd != NULL)
		return;
}

void pop(stack_t **elements, unsigned int ln_num, char **arrcmd)
{
	stack_t *tmp = NULL;
	stack_t *prev = NULL;

	tmp = *elements;
	prev = *elements;
	if (tmp == NULL)
	{
		fprintf(stderr, "L%d: NULL list, arrcmd[0]: %s\n", ln_num, arrcmd[0]);
		return;
	}
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
