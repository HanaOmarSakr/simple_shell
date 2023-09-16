#include "main"

/**
 * _eputs - prints an input string.
 * @str: the string to be printed.
 * Return: nothing.
 */
void _eputs(char *str)
{
	int u = 0;

	if (!str)
	{
		return;
	}
	while (str[u] != '\0')
	{
		_eputchar(str[u]);
		i++;
	}
}

