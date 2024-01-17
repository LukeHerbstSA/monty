#include "monty.h"

char **getln_split()
{
	char **arrcmd = NULL;
	char *line = NULL;
	char *token = NULL;
	char *linecopy = NULL;
	size_t linesize = 0;
	int numtoken = 0;
	int i = 0;

	getline(&line, &linesize, stdin);
	linecopy = malloc(strlen(line) + 1);
	strcpy(linecopy, line);
	token = strtok(line, " ");
	while (token != NULL)
	{
		token = strtok(NULL, " ");
		numtoken += 1;
	}
	arrcmd = malloc(numtoken * sizeof(char *));
	token = strtok(linecopy, " ");
	while (token != NULL)
	{
		arrcmd[i] = malloc(strlen(token) + 1);
		strcpy(arrcmd[i], token);
		token = strtok(NULL, " ");
		i++;
	}
	arrcmd[i] = NULL;
	free(line);
	free(linecopy);
	printf("%s", arrcmd[i]);
	exit(0);
	return (arrcmd);
}
