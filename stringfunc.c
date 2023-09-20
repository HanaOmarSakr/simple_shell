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
int _strlen(const char *buffer)
{
	int i = 0;

	while (*buffer++ != '\0')
		i++;
	return (i);
}

/**
 * _strdup - ....
 * @string: string
 * Return: pointer to a duplicated buffer
 * Description: important func
*/

char *_strdup(const char *string)
{
	char *start;
	char *p;

	p = malloc(_strlen(string) + 1);
	if (p == NULL)
	{
		return (NULL);
	}
	start = p;
	while (*string)
		*p++ = *string++;
	*p = '\0';
	return (start);
}
/**
 * _strcat - ....
 * @dest: string
 * @src: pointer to a duplicated buffer
 * Return: pointer
 * Description: important func
*/

char *_strcat(char *dest, const char *src)
{
	char *ptr = dest + strlen(dest);

	while (*src != '\0')
		*ptr++ = *src++;
	*ptr = '\0';
	return (dest);
}

/**
 * _memcpy - ....
 * @dest: string
 * @src: pointer
 * @n: .....
 * Return: pointer
 * Description: important func
*/

void *_memcpy(void *dest, const void *src, size_t n)
{
	size_t i;
	char *csrc = (char *) src;
	char *cdest = (char *) dest;

	for (i = 0; i < n; i++)
	{
		cdest[i] = csrc[i];
	}

	return (dest);
}
