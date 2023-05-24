#include "shell.h"

/**
 * main - main function of the program
 * @argc: number of arguments
 * @argv: the arguments
 * @envp: the environment
 * Return: Integer
*/
int main(int argc, char **argv, char **envp)
{
	int fd = 2;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
				exit(127);
			return (EXIT_FAILURE);
		}
	}
	signal(SIGINT, hundle_ctrl);

	prompt(argv, envp);

	return (0);
}
