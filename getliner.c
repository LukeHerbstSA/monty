#include "monty.h"

/**
	* getln_split - char ** array func
	* Description: returns char ** array from a line
	* @fp: passed file descriptor (not pointer)
	* Return: array pointers
	*/
char **getln_split(FILE *fp)
{
	char **arrcmd = NULL;
	char *unedit_ln = malloc(1024);
	char *line = NULL;
	char *token = NULL;
	char *linecopy = NULL;
	size_t linesize = 1024;
	int numtoken = 0;
	int i = 0;

	if (fgets(unedit_ln, linesize, fp) == NULL)
	{
		free(unedit_ln);
		return (NULL);
	}
	line = malloc(strlen(unedit_ln) + 1);
	for (i = 0; unedit_ln[i] != '\n' && unedit_ln[i] != '\0'; i++)
		line[i] = unedit_ln[i];
	line[i] = '\0';
	i = 0;
	free(unedit_ln);
	linecopy = malloc(strlen(line) + 1);
	if (linecopy == NULL)
		bad_malloc(NULL, arrcmd);
	strcpy(linecopy, line);
	token = strtok(line, " ");
	for (numtoken = 0; token != NULL; numtoken++)
		token = strtok(NULL, " ");
	free(line);
	arrcmd = malloc((numtoken + 1) * sizeof(char *));
	if (arrcmd == NULL)
		bad_malloc(NULL, arrcmd);
	token = strtok(linecopy, " ");
	while (token != NULL)
	{
		if (strlen(token) > 0)
		{
			arrcmd[i] = malloc(strlen(token) + 1);
			if (arrcmd[i] == NULL)
			{
				free(linecopy);
				bad_malloc(NULL, arrcmd);
			}
			strcpy(arrcmd[i], token);
			i++;
		}
		token = strtok(NULL, " ");
	}
	arrcmd[i] = NULL;
	free(linecopy);
	return (arrcmd);
}
