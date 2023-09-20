#include "main.h"

/**
 * _myhistory - display the history list, one command by line, preceded
 *              with line numbers, strating at 0.
 * @info: structure containing potential arguments. used to maintain
 *        constant function prototype.
 * Return: always 0.
 */
int _myhistory(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
 * unset_alias - remove alias.
 * @info: structure containing potential arguments. used to maintain
 *        constant function prototype.
 * Return: always 0 on success, 1 on error.
 */
int unset_alias(info_t *info, char *str)
{
	char *x, t;
	int ret;

	x = _strchr(str, '=');
	if (!x)
		return (1);
	t = *x;
	*x = 0;
	ret = delete_node_at_index(&(info->alias),
			get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*x = t;
	return (ret);
}

/**
 * print_alias - prints an alias string.
 * @node: the alias node.
 * Return: always  on success, 1 on error.
 */
int print_alias(list_t)
{
	char *v = NULL, *w = NULL;

	if (node)
	{
		v = _strchr(node->str, '=');
		for (w = node->str; w <= v; w++)
		{
			_putchar(*w);
		}
		_putchar('\'');
		_puts(v + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _myalias - mimics the alias builtin (man alias).
 * @info: structure containing potential arguments. used to maintain
 *        constant function prototype.
 * Return: always 0.
 */
int _myalias(info_t *info)
{
	int y = 0;
	char *n = NULL;

	list_t *node;
	node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (y = 1; info->argv[y]; y++)
	{
		n = _strchr(info->argv[y], '=');
		if (n)
			set_alias(info, info->argv[y]);
		else
			print_alias(node_starts_with(info->alias. info->argv[y], '='));
	}
	return (0);
}

