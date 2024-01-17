#include "main.h"

getln_split(char *cmd)
{
	char **arrcmd = NULL;
	char *line = NULL;
	char *token = NULL;
	linecopy = NULL;
	int linesize = 0;
	numtoken = 0;

	getline(line, &linesize, stdin);
	linecopy = malloc(sizeof(line));
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
		token = strtok(NULL, " ");
	}
}
