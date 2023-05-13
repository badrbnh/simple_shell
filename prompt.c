#include "shell.h"
/**
 * prompt - Function that prompts the user for input
 * @argv: Pointer to array of arguments
 * Return: Integer
 */

int prompt(char **argv)
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
        if (read == -1)
            break;
        
        if (line[0] == '\n')
            continue;

        tokens = split(line);
        execute(tokens[0], tokens, argv);
        free(tokens);
    }

    free(line);
    return 0;
}
