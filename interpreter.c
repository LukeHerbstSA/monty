#include "monty.h"

int interpreter(char **arrcmd)
{
	int i = 0;

	for(i = 0; i < OPCODE_LEN; i++)
	{
		if (strcmp(opcodelist[i].opcode, arrcmd[0]) == 0)
			(opcodelist[i].fptr)(arrcmd);
	}
	if (i == OPCODE_LEN)
		return (-1);
	return (0);
}
