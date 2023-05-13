#include "shell.h"

/**
 * exexute - Function that execute the prompte commands
 * @cmd: Pointer to the command
 * @argv: Pointer to command's arguments
 * Return: Integer
*/

int execute(char *cmd, char *argv[], char **av)
{
    pid_t pid;
    int status;

    pid = fork();
    if (pid == -1)
    {
        perror("Failed to fork process");
        return -1;
    }
    else if (pid == 0)
    {
        if (execve(cmd, argv, NULL) == -1) {
            printf("%s: No such file or directory\n", av[0]);
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        if (waitpid(pid, &status, 0) == -1)
        {
            perror("Failed to wait for child process");
            return -1;
        }
        else
        {
            if (WIFEXITED(status))
            {
                return WEXITSTATUS(status);
            }
            else
            {
                printf("Child process exited abnormally\n");
                return -1;
            }
        }
    }
}
