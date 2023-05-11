#include "shell.h"

int main(int argc, char **argv[])
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    int status = 1;

    signal(SIGINT, hundle_ctrl);

    while (status)
    {
        printf("$ ");
        read = getline(&line, &len, stdin);
        if (read == -1)
        {
            break;
        }

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
            execute(tokens[0], tokens);
        }
    }

    free(line);
    return 0;
}
