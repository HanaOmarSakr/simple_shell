#include "main.h"

/**
 * _strcpy - .....
 * @dest: .....
 * @src: ....
 * Return: Buffer
 */
char *_strcpy(char *dest, const char *src)
{
	char *start = dest;

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}

	*dest = '\0';
	return (start);
}

/**
 * _strlen - ....
 * @buffer: string
 * Return: length of "buffer"
 * Description: important func
*/
int _strlen(char *buffer)
{
	int i = 0;

	while (*buffer++ != '\0')
		i++;

	return (i);
}
