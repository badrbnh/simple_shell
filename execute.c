#include "shell.h"

/**
 * execute - Function that executes the command
 * @cmd: Pointer to the command
 * @argv: Pointer to command's arguments
 * @envp: Pointer to environment variables
 * @av: Pointer to arguments
 * Return: Integer
 */

int execute(char *cmd, char *argv[], char **av, char **envp)
{
	pid_t pid;
	int status;
	char *full_path = path(cmd);

	pid = fork();
	if (pid == (-1))
	{
		perror(av[0]);
		free(full_path);
		return (-1);
	}
	else if (pid == 0)
	{
		if (execve(full_path, argv, envp) == -1 && execve(cmd, argv, NULL) == -1)
		{
			errno = ENOENT;
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
			free(full_path);
			return (-1);
		}
	}
}
