#include "main.h"

/**
 * _strtok - .........
 * @str: ........
 * @delim: ......
 * Return: .......
 */

char *_strtok(char *str, const char *delim)
{
	static char *buffer;
	char *token_start;

	if (str != NULL)
		buffer = str;

	if (buffer == NULL)
		return (NULL);

	while (*buffer != '\0' && strchr(delim, *buffer) != NULL)
		buffer++;

	if (*buffer == '\0')
	{
		buffer = NULL;
		return (NULL);
	}

	token_start = buffer;
	while (*buffer != '\0')
	{
		if (strchr(delim, *buffer) != NULL)
		{
			*buffer = '\0';
			buffer++;
			return (token_start);
		}
		buffer++;
	}
	return (token_start);
}
