#include "monty.h"

int interpreter(char **arrcmd, stack_t **elements, unsigned int line_number)
{
	int i;
	instruction_t opcodelist[] =  {
	{ .opcode = "push", .fptr = push},
	{ .opcode = "pall", .fptr = pall},
	{ .opcode = "pop", .fptr = pop}
};

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
