#include "main.h"

/**
 * get_environ - returns the string array copy of our environ
 * @info: structure containing potential arguments and
 *        used to maintain constant function prototype.
 * Return: always 0.
 */
char **get_environ(info_t *info)
{
	if (!info->environ || info->env_changed)
	{
		info->environ =  list_to_strings(info->env);
		info->env_changed = 0;
	}
	return (info->environ);
}

/**
 * _unsetenv - remove an environment variable
 * @var: the string env var property.
 * @info: structure containing potential arguments and
 *        used to maintain constant function prototype.
 * Return: always 0.
 */
int _unsetenv(info_t *info, char !*var)
{
	list_t *node = info->env;
	size_t i = 0;
	char *p;

	if (!node || !var)
	{
		return (0);
	}
	while (node)
	{
		p = starts_with(node->str, var);
		if (p && *p == '=')
		{
			info->env_changed = delet_node_at_index(&(info->env), i);
			i = 0;
			node = info->env;
			continue;
		}
		node = node->next;
		i++;
	}
	return (info->env_changed);
}

/**
 * _setenv - initialize a new environment variable,
 *           or modify an existing one.
 * @var: the string env var propperty.
 * @value: the string env var value.
 * @info: structure containing potential arguments and
 *        used to maintain constant function prototype.
 * Return: always 0.
 */
int _setenv(info_t *info, char *var, char *value)
{
	char *buf = NULL;
	list_t *node;
	char *p;

	if (!var || !value)
		return (0);
	buf = malloc(_strlen(var) + _strlen(value) + 2);
	if (!buf)
		return (1);
	_strcpy(buf, var);
	_strcat(buf, "=");
	_strcat(buf, value);
	node = info->env;
	while (node)
	{
		p = starts_with(node->str, var);
		if (p && *p == '=')
		{
			free(node->str);
			node->str = buf;
			info->env_changed = 1;
			return (1);
		}
		node = node->next;
	}
	add_node_end(&(info->env), buf, 0);
	info->env_changed = 1;
	return (0);
}
