#include "shell.h"

/**
 * prompt - Function that prompts the user for input
 * @argv: Pointer to array of arguments
 * @envp: Pointer the environment
 * Return: Integer
 */

int prompt(char **argv, char **envp)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	char **tokens;
	int status = 1;

	while (status)
	{
		printf("$ ");
		read = getline(&line, &len, stdin);
		if (read == -1 || feof(stdin))
		{
			_puts("exit");
			break;
		}
		if (line[0] == '\n')
			continue;

		tokens = split(line);
		if (strcmp(tokens[0], "exit") == 0) {
			status = 0;
			free(tokens);
			break;
		}
		execute(tokens[0], tokens, argv, envp);
		free(tokens);
	}
	exit_shell(status);
	free(line);
	return (0);
}
