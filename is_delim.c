#include "main.h"

/**
 * is_delim - checks if character is a delimeter.
 * @g: the char to check.
 * @delim: the dekimeter string.
 * Return: 1 is true, 0 is false.
 */
int is_delim(char g, char *delim)
{
	while (*delim)

	{
		if (*delim++ == g)
			return (1);
	}
	return (0);
}
