#include "shell.h"
/**
 * prompt - Function that prompts the user for input
 * @argv: Pointer to array of arguments
 * @envp: Pointer to the environment
 * Return: Integer
 */
int prompt(char **argv, char **envp)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    char **tokens;
    int status = 1;
    int execute_status = 0;
	int i;

    while (status)
    {
        line = NULL;
        if (isatty(STDIN_FILENO))
            write(STDOUT_FILENO, "$ ", 2);
        read = getline(&line, &len, stdin);
        if (read == -1)
        {
            if (line != NULL)
                free(line);
            break;
        }
        if (line[0] == '\n')
	{
		free(line);            
		continue;
	}

        tokens = split(line);
        if (tokens == NULL)
        {
            free(line);
            continue;
        }
        if (_strcmp(tokens[0], "exit") == 0)
        {
            status = 0;
			free(line);
            free(tokens);
            break;
        }
        execute_status = execute(tokens[0], tokens, argv, envp);
		for ( i = 0; tokens[i]; i++)
			free(tokens[i]);
		free(tokens);
        if (execute_status == -1)
            break;
    }
    return execute_status;
}
