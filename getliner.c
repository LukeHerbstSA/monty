#include "monty.h"

char **getln_split(stack_t **elements)
{
	char **arrcmd = NULL;
	char *unedit_ln = NULL;
	char *line = NULL;
	char *token = NULL;
	char *linecopy = NULL;
	size_t linesize = 0;
	int numtoken;
	int i = 0;

	if (getline(&unedit_ln, &linesize, stdin) == -1)
		return (NULL);
	line = malloc(strlen(unedit_ln));
	for (i = 0; unedit_ln[i] != '\n' && unedit_ln[i] != '\0'; i++)
		line[i] = unedit_ln[i];
	line[i] = '\0';
	i = 0;
	free(unedit_ln);
	linecopy = malloc(strlen(line) + 1);
	if (linecopy == NULL)
		bad_malloc(elements, arrcmd);
	strcpy(linecopy, line);
	token = strtok(line, " ");
	for (numtoken = 0; token != NULL; numtoken++)
		token = strtok(NULL, " ");
	free(line);
	arrcmd = malloc(numtoken * sizeof(char *));
	if (arrcmd == NULL)
		bad_malloc(elements, arrcmd);
	token = strtok(linecopy, " ");
	while (token != NULL)
	{
		if (strlen(token) > 0)
		{
			arrcmd[i] = malloc(strlen(token) + 1);
			if (arrcmd[i] == NULL)
			{
				free(linecopy);
				bad_malloc(elements, arrcmd);
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
