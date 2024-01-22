#include "monty.h"

/**
	* interpreter - int func
	* Description: calls function pointers based on opcode
	* @arrcmd: array of pointers
	* @elements: stack_t doubly
	* @line_number: line number of monty code
	* Return: 0 on success or -1
	*/
int interpreter(char **arrcmd, stack_t **elements, unsigned int line_number)
{
	int i = 0;

	instruction_t opcodelist[] =  {
	{ "push", push},
	{ "pall", pall},
	{ "pop", pop}
};

	if (arrcmd == NULL)
		return (-1);
	for(i = 0; i < OPCODE_LEN; i++)
	{
		if (strcmp(opcodelist[i].opcode, arrcmd[0]) == 0)
		{
			(opcodelist[i].fptr)(elements, line_number, arrcmd);
			break;
		}
	}
	if (i == OPCODE_LEN)
		return (-1);
	return (0);
}
