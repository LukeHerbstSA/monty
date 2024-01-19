#include "monty.h"

int main(int argc, char *argv[])
{
	FILE *open_check = NULL;
	char **arrcmd = NULL;
	stack_t **elements = malloc(sizeof(stack_t));
	unsigned int line_number = 0;
	int gen_check = 0;

	if (elements == NULL)
	{
		perror("Error: malloc failed");
		gen_check = -1;
	}
	if (argc < 2 && gen_check == 0)
	{
		perror("USAGE: monty file\n");
		gen_check = -1;
	}
	if (gen_check == 0)
		open_check = freopen(argv[1], "r", stdin);
	if (open_check == NULL && gen_check == 0)
	{
		fprintf(stderr, "Error: Can't open file %s", argv[1]);
		gen_check = -1;
	}
	while (gen_check == 0)
	{
		arrcmd = getln_split(elements); /* exit within to have control over errors*/
		line_number += 1;
		if (arrcmd == NULL)
			break;
		gen_check = interpreter(arrcmd, elements, line_number);
		if (gen_check == -1)
			fprintf(stderr, "L%u: unknown instruction %s", line_number, arrcmd[0]);
	}
	freelist(elements, arrcmd);
	if (gen_check == -1)
		exit(EXIT_FAILURE);
	return (0);
}
