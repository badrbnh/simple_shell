#include <string.h>
#include "main.h"

/**
 * str_split - Splits a string
 * @str: The string to split
 * Return: On success, it returns the new array
 * of strings. On failure, it returns NULL
 */
char **str_split(char *str)
{
    char *token = NULL, **args = NULL, *temp = NULL;
    int i = 0, n = 0;

    if (!str)
    {
        return (NULL);
    }
    temp = strdup(str);
    token = strtok(temp, " \n\t");
    while (token)
    {
        if (_strcmp(token, "\n") != 0)
        {
            n++;
        }
        token = strtok(NULL, " \n\t");
    }

    args = (char **)malloc(sizeof(char *) * (n + 1));
    if (!args) {
        perror("failed to allocate memory\n");
        return (NULL);
    }
    token = strtok(str, " \n\t");
    for (i = 0; token; i++)
    {
        args[i] = (char *)malloc(sizeof(char) * (_strlen(token) + 1));
        if (!args[i]) {
            perror("failed to allocate memory\n");
            free(args);
            return (NULL);
        }
        _strcpy(args[i], token);
        token = strtok(NULL, " \n\t");
    }

    args[n] = NULL;

    if (temp)
        free(temp);

    return (args);
}

