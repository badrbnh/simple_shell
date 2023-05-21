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
	(void)argc;
	signal(SIGINT, hundle_ctrl);

	prompt(argv, envp);

	return (0);
}
