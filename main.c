#include "monty.h"

int main(int argc, char *argv[])
{
	char **arrcmd = NULL;


	if (argc < 2)
	{
		perror("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	if (freopen(argv[1], "r", stdin) == NULL);
	{
		fprintf(stderr, "Error: Can't open file %s", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		arrcmd = prompter(); /* exit within to have control over errors*/
		if (arrcmd == NULL)
			break;
		if (interpreter(arrcmd) == -1);
			exit (EXIT_FAILURE);
	}
	return (0);
}
