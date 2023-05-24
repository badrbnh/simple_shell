#include "shell.h"

/**
 * _chain - function that test if current char in buffer is a chain delimeter.
 * @info: the parameter.
 * @buf: the buffer.
 * @p: Pointer.
 *
 * Return: integer.
 */
int _chain(info_t *info, char *buf, size_t *p)
{
	size_t i = *p;

	if (buf[i] == '|' && buf[i + 1] == '|')
	{
		buf[i] = 0;
		i++;
		info->cmd_buf_type = CMD_OR;
	}
	else if (buf[i] == '&' && buf[i + 1] == '&')
	{
		buf[i] = 0;
		i++;
		info->cmd_buf_type = CMD_AND;
	}
	else if (buf[i] == ';')
	{
		buf[i] = 0;
		info->cmd_buf_type = CMD_CHAIN;
	}
	else
		return (0);
	*p = i;
	return (1);
}

/**
 * _check_chain - function that checks the chain.
 * @info: the parameter.
 * @buf: the buffer
 * @p: Pointer
 * @i: THe start.
 * @len: length of buffer.
 *
 * Return: Void
 */
void _check_chain(info_t *info, char *buf, size_t *p, size_t i, size_t len)
{
	size_t j = *p;

	if (info->cmd_buf_type == CMD_AND)
	{
		if (info->status)
		{
			buf[i] = 0;
			j = len;
		}
	}
	if (info->cmd_buf_type == CMD_OR)
	{
		if (!info->status)
		{
			buf[i] = 0;
			j = len;
		}
	}

	*p = j;
}

/**
 * rep_alias - function that replaces an aliases.
 * @info: the parameter.
 *
 * Return: Integer
 */
int rep_alias(info_t *info)
{
	int j;
	list_t *node;
	char *p;

	for (j = 0; j < 10; j++)
	{
		node = node_starts_with(info->alias, info->argv[0], '=');
		if (!node)
			return (0);
		free(info->argv[0]);
		p = _strchr(node->str, '=');
		if (!p)
			return (0);
		p = _strdup(p + 1);
		if (!p)
			return (0);
		info->argv[0] = p;
	}
	return (1);
}

/**
 * repl_vars - function that replaces vars.
 * @info: the parameter.
 *
 * Return: Integer
 */
int repl_vars(info_t *info)
{
	int i = 0;
	list_t *node;

	for (i = 0; info->argv[i]; i++)
	{
		if (info->argv[i][0] != '$' || !info->argv[i][1])
			continue;

		if (!_strcmp(info->argv[i], "$?"))
		{
			repl_str(&(info->argv[i]),
						   _strdup(convert_number(info->status, 10, 0)));
			continue;
		}
		if (!_strcmp(info->argv[i], "$$"))
		{
			repl_str(&(info->argv[i]),
						   _strdup(convert_number(getpid(), 10, 0)));
			continue;
		}
		node = node_starts_with(info->env, &info->argv[i][1], '=');
		if (node)
		{
			repl_str(&(info->argv[i]),
						   _strdup(_strchr(node->str, '=') + 1));
			continue;
		}
		repl_str(&info->argv[i], _strdup(""));
	}
	return (0);
}

/**
 * repl_str - function that replaces string
 * @old: address of old string
 * @new: new string
 *
 * Return: 1 if replaced, 0 otherwise
 */
int repl_str(char **old, char *new)
{
	free(*old);
	*old = new;
	return (1);
}
