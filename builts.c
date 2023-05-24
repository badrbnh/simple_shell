#include "shell.h"

/**
 * exit_shell - Function that exits the shell
 * @status: Exit status
 * Return: Void
 */

void exit_shell(int status)
{
	exit(status);
}

/**
 * print_environment - Function that prints the current environment variables
 * @envp: Pointer to the environment variables
 */
void print_environment(char **envp)
{
	int i = 0;

	while (envp[i] != NULL)
	{
		_puts(envp[i]);
		_puts("\n");
		i++;
	}
}