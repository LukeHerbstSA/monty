#include "monty.h"

void push(stack_t **elements, unsigned int ln_num, char **arrcmd)
{
	char *endptr = NULL;
	stack_t *tmp = *elements;
	stack_t *newnode = malloc(sizeof(stack_t));
	int value = 0;

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

void pall(stack_t **elements, unsigned int ln_num, char **arrcmd)
{
	stack_t *tmp = *elements;
	
	if (tmp == NULL)
	{
		fprintf(stderr, "L%u: instruction on NULL list %s\n", ln_num, arrcmd[0]);
		freelist(elements, arrcmd);
		exit(EXIT_FAILURE);
	}
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

void pint(stack_t elements, unsigned int ln_num, char **arrcmd)
{

}

void pop(stack_t **elements, unsigned int ln_num, char **arrcmd)
{
	stack_t *tmp = NULL;
	stack_t *prev = NULL;

	tmp = *elements;
	prev = *elements;
	if (tmp == NULL)
	{
		fprintf(stderr, "L%u: instruction on NULL list %s\n", ln_num, arrcmd[0]);
		freelist(elements, arrcmd);
		exit(EXIT_FAILURE);
	}
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
