#include "shell.h"

/**
 * split - Function that splits a string into tokens
 * @line: Pointer to the string
 * Return: Array of tokens
 */

char **split(char *line)
{
	char *token;
	char **tokens = malloc(100 * sizeof(char *));
	int i = 0;

	if (!tokens)
	{
		perror("Failed to allocate memory");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, " \t\n");
	while (token != NULL && i < 99)
	{
		tokens[i] = token;
		token = strtok(NULL, " \t\n");
		i++;
	}
	tokens[i] = NULL;

	if (token == NULL && i == 99)
	{
		perror("Exceeded maximum number of tokens");
		exit(EXIT_FAILURE);
	}

	if (i < 99)
		tokens[i + 1] = NULL;

	return tokens;
}

