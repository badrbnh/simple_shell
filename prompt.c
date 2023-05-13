#include "shell.h"

int prompt(char **argv)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    int status = 1;

    while (status)
    {
        printf("$ ");
        read = getline(&line, &len, stdin);
        if (read == -1)
        {
            break;
        }
        if (line[0] == '\n' )
            continue;

        char *token;
        char *tokens[100];
        int i = 0;

        token = strtok(line, " \t\n");
        while (token != NULL && i < 99)
        {
            tokens[i] = token;
            token = strtok(NULL, " \t\n");
            i++;
        }
        tokens[i] = NULL;

        if (strcmp(tokens[0], "exit") == 0)
        {
            status = 0;
        }
        else if (i > 0)
        {
            execute(tokens[0], tokens, argv);
        }
    }

    free(line);
    return 0;
}
