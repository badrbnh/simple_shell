#include "shell.h"

/**
 * execute - Function that executes the command
 * @cmd: Pointer to the command
 * @argv: Pointer to command's arguments
 * @av: Pointer to arguments
 * @envp: Pointer to environment variables
 * Return: Integer
 */
int execute(char *cmd, char *argv[], char **av, char **envp)
{
    pid_t pid;
    int status;
    char *full_path = NULL;

    if (cmd[0] == '/')
    {
        if (access(cmd, X_OK) == 0)
        {
            full_path = malloc((_strlen(cmd) + 1) * sizeof(char));
            if (full_path == NULL)
            {
                perror("Failed to allocate memory");
                return (-1);
            }
            _strcpy(full_path, cmd);
        }
        else
        {
            perror("command not found");
            return (-1);
        }
    }
    else
    {
        if (!path(cmd, &full_path))
        {
            perror("command not found");
            return (-1);
        }
    }

    pid = fork();
    if (pid == -1)
    {
        perror(av[0]);
        free(full_path);
        return (-1);
    }
    else if (pid == 0)
    {
        if (execve(full_path, argv, envp) == -1)
        {
            perror(av[0]);
            free(full_path);
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        if (waitpid(pid, &status, 0) == -1)
        {
            perror(av[0]);
            return (-1);
        }
    }
    
    if (full_path != NULL)
        free(full_path);
    
    return (0);
}
