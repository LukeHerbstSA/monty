#include "monty.h"

/**
	* bad_malloc - void func
	* Description: calls freelist and perror then exits
	* @elements: passed doubly
	* @arrcmd: passed array of cmds
	*/
void bad_malloc(stack_t **elements, char **arrcmd)
{
	perror("Error: malloc failed");
	freelist(elements, arrcmd);
	exit(EXIT_FAILURE);
}
