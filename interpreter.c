#include "monty.h"

int interpreter(char **arrcmd, stack_t **elements, unsigned int line_number)
{
	int i = 0;
	int j = 0;

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
			printf("Entering stackcmds\n");
			for (j = 0; arrcmd[j] != NULL; j++)
			{
				printf("arrcmd[j]: %s\n", arrcmd[j]);
			}
			(opcodelist[i].fptr)(elements, line_number, arrcmd);
			break;
		}
	}
	printf("After calling function pointer\n");
	if (i == OPCODE_LEN)
		return (-1);
	return (0);
}
