#include "monty.h"

int main(int argc, char *argv[])
{
	FILE *open_check = NULL;
	char **arrcmd = NULL;
	stack_t **elements = malloc(sizeof(stack_t *));
	unsigned int line_number = 0;
	int gen_check = 0;
	int i;

	*elements = NULL;
	if (elements == NULL)
	{
		perror("Error: Malloc Failed\n");
		gen_check = -1;
	}
	if (argc < 2 && gen_check == 0)
	{
		perror("USAGE: monty file\n");
		gen_check = -1;
	}
	if (gen_check == 0)
		open_check = fopen(argv[1], "r");
	if (open_check == NULL && gen_check == 0)
	{
		fprintf(stderr, "Error: Can't open file %s", argv[1]);
		gen_check = -1;
	}
	while (gen_check != -1)
	{
		printf("Before getliner\n");
		arrcmd = getln_split(open_check); /* exit within to have control over errors*/
		line_number += 1;
		if (arrcmd == NULL)
		{
			printf("arrcmd is NULL\n");
			break;
		}
		printf("Before interpreter\n");
		gen_check = interpreter(arrcmd, elements, line_number);
		printf("After interpreter\n");
		if (gen_check == -1)
			fprintf(stderr, "L%u: unknown instruction %s", line_number, arrcmd[0]);
		if (arrcmd != NULL && *elements != NULL)
			printf("arrcmd[0]: %s, elements[0]: %d\n", arrcmd[0], (*elements)->n);
		if (*elements == NULL)
			printf("After interpreter *elements is NULL\n");
		for (i = 0; arrcmd[i] != NULL; i++)
			free(arrcmd[i]);
		free(arrcmd);
		printf("After freeing arrcmd\n");
	}
	printf("About to free and exit program\n");
	fclose(open_check);
	freelist(elements, arrcmd);
	if (gen_check == -1)
		exit(EXIT_FAILURE);
	return (0);
}
