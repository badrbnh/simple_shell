#include "shell.h"

/**
 * hundle_ctrl - Function that hundles Ctrl-C signal
 * @signal: Argument to the singal function
 * Return : Void
*/

void hundle_ctrl(int signal)
{
	(void)signal;
	write(STDERR_FILENO, "\n", 1);
	write(STDERR_FILENO, "$ ", 2);
}
