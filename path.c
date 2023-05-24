#include "shell.h"

/**
 * path - Function that finds the full path of a command
 * @cmd: Pointer to the command
 * @full_path: Pointer to store the full path of the command
 * Return: 1 on success, 0 if command not found
 */
int path(char *cmd, char **full_path)
{
    char *path = _getenv("PATH");
    char *token, *path_copy;

    path_copy = strdup(path);
    if (path_copy == NULL)
    {
        perror("Failed to allocate memory");
        return 0;
    }

    token = strtok(path_copy, ":");
    while (token != NULL)
    {
        *full_path = malloc(_strlen(token) + _strlen(cmd) + 2);
        if (*full_path == NULL)
        {
            perror("Failed to allocate memory");
            free(path_copy);
            return 0;
        }
        sprintf(*full_path, "%s/%s", token, cmd);
        if (access(*full_path, X_OK) == 0)
            break;
        free(*full_path);
        *full_path = NULL;
        token = strtok(NULL, ":");
    }
    free(path_copy);

    if (*full_path == NULL)
        return 0;

    return 1;
}
