#include "shell.h"

/**
 * _getenv - Function that retrieves an environment variable
 * @name: Name of the environment variable to retrieve
 * Return: Pointer to the value of the environment variable,
 *         or NULL if not found
 */
char *_getenv(const char *name)
{
	extern char **environ;
	size_t name_len = strlen(name);
	char **env;

	if (name == NULL || environ == NULL)
		return (NULL);

	for (env = environ; *env != NULL; env++)
	{
		if (_strncmp(name, *env, name_len) == 0 && (*env)[name_len] == '=')
			return (&(*env)[name_len + 1]);
	}

	return (NULL);
}
