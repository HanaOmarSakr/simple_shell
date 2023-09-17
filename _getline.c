#include "main.h"

/**
 * _getline - ....
 * @line: string
 * Return: int
*/

ssize_t _getline(char **line)
{
	size_t buffer = 0;
	ssize_t l;

	l = getline(line, &buffer, stdin);
	return (l);
}
