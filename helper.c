#include "monty.h"

void bad_malloc(stack_t **elements, char **arrcmd)
{
	perror("Error: malloc failed");
	freelist(elements, arrcmd);
	exit(EXIT_FAILURE);
}
