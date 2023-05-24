#include "shell.h"

/**
 * _history - Function that displays the history list.
 * @info: arguments
 *  Return: 0
 */
int _history(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
 * _un_set_alias - function that sets alias to string
 * @info: parameter
 * @str: the string
 *
 * Return: 0 if succes, 1 if failed.
 */
int _un_set_alias(info_t *info, char *str)
{
	char *p, c;
	int ret;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	c = *p;
	*p = 0;
	ret = delete_node_at_index(&(info->alias),
							   get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*p = c;
	return (ret);
}

/**
 * _set_alias - function that sets alias to string.
 * @info: parameter.
 * @str: the string.
 *
 * Return: 0 if succes, 1 if failed.
 */
int _set_alias(info_t *info, char *str)
{
	char *p;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	if (!*++p)
		return (_un_set_alias(info, str));

	_un_set_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * _print_alias - function that prints an alias string
 * @node: the alias node
 *
 * Return: 0 if succes, 1 if failed.
 */
int _print_alias(list_t *node)
{
	char *p = NULL, *a = NULL;

	if (node)
	{
		p = _strchr(node->str, '=');
		for (a = node->str; a <= p; a++)
			_putchar(*a);
		_putchar('\'');
		_puts(p + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _alias - implementation of the alias.
 * @info: Arguments
 *  Return: 0
 */
int _alias(info_t *info)
{
	int i = 0;
	char *p = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			_print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (i = 1; info->argv[i]; i++)
	{
		p = _strchr(info->argv[i], '=');
		if (p)
			_set_alias(info, info->argv[i]);
		else
			_print_alias(node_starts_with(info->alias, info->argv[i], '='));
	}

	return (0);
}
