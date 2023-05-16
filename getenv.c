#include "shell.h"

/**
 * _getenv - Function that retrieves an environment variable
 * @name: Name of the environment variable to retrieve
 * Return: Pointer to the value of the environment variable,
 *         or NULL if not found
 */
char *_getenv(const char *name)
{
	extern char **environ;  // Access the environment variables array

	if (name == NULL || environ == NULL)
		return NULL;

	size_t name_len = strlen(name);

	// Iterate over each environment variable
	for (char **env = environ; *env != NULL; env++)
	{
		// Check if the current environment variable matches the given name
		if (strncmp(name, *env, name_len) == 0 && (*env)[name_len] == '=')
			return &(*env)[name_len + 1];  // Return the value of the environment variable
	}

	return NULL;  // Environment variable not found
}
