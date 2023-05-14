#include <string.h>
#include "main.h"

/**
 * str_split - Splits a string
 * @str: The string that will be split
 * Return: On success, it returns the new array
 * of strings. On failure, it returns NULL
 */
char **str_split(char *str)
{
    char *token = NULL, **args = NULL, *temp = NULL;
    int i = 0, n = 0;

    if (!str || !" \n\t")
    {
        return (NULL);
    }
    temp = strdup(str);
    token = strtok(temp, " \n\t");
    while (token)
    {
        if (strcmp(token, "\n") != 0)
        {
            n++;
        }
        token = strtok(NULL, " \n\t");
    }

    args = (char **)malloc(sizeof(char *) * (n + 1));
    token = strtok(str, " \n\t");
    for (i = 0; token; i++)
    {
        args[i] = (char *)malloc(sizeof(char) * (strlen(token) + 1));
        strcpy(args[i], token);
        token = strtok(NULL, " \n\t");
    }

    args[n] = NULL;

    if (temp)
        free(temp);

    return (args);
}

