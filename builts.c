#include "shell.h"

/**
 * cmd_env - prints the current environment
 * @envp: Pointer to the environment variables
 */
void cmd_env(char **envp)
{
	unsigned int i;

	if (!envp)
	{
		write(STDERR_FILENO, "env: environ is NULL\n", 21);
		return;
	}

	for (i = 0; envp[i]; i++)
	{
		size_t len = strlen(envp[i]);

		write(STDOUT_FILENO, envp[i], len);
		write(STDOUT_FILENO, "\n", 1);
	}
}
/**
 * cmd_exit - exits the program
 * @args: Array of arguments
 * @status: Pointer to the status variable
 */
void cmd_exit(char **args, int *status)
{
	if (args[1])
	{
		if (!is_num(args[1]))
		{
			write(STDERR_FILENO, "exit: ", 6);
			write(STDERR_FILENO, args[1], strlen(args[1]));
			write(STDERR_FILENO, ": numeric required\n", 19);
			*status = 2;
			return;
		}

		if (args[2])
		{
			write(STDERR_FILENO, "exit: too many arguments\n", 24);
			*status = 1;
			return;
		}

		if (is_num(args[1]))
			*status = _atoi(args[1]);
	}

	*status = 0;
}
#include "shell.h"

/**
 * cmd_setenv - sets or updates an environment variable
 * @args: Array of arguments
 * Return: Void
 */
void cmd_setenv(char **args)
{
	if (args[1] && args[2])
	{
		if (setenv(args[1], args[2], 1) == -1)
			perror("setenv");
	}
	else
	{
		write(STDERR_FILENO, "setenv: Invalid number of arguments\n", 36);
	}
}

/**
 * cmd_unsetenv - removes an environment variable
 * @args: Array of arguments
 * Return: Void
 */
void cmd_unsetenv(char **args)
{
	if (args[1])
	{
		if (unsetenv(args[1]) == -1)
			perror("unsetenv");
	}
	else
	{
		write(STDERR_FILENO, "unsetenv: Missing argument\n", 27);
	}
}

