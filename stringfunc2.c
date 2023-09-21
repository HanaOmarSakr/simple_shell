#include "main.h"

/**
 * _strchr - ....
 * @s: string
 * @c: .......
 * Return: pointer
 * Description: important func
*/
char *_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
		{
			return ((char *)s);
		}
		s++;
	}

	if (c == '\0')
		return ((char *)s);

	return (NULL);
}

/**
 * _strcmp - ....
 * @s: string
 * @t: pointer
 * Return: int
 * Description: important func
*/

int _strcmp(const char *s, const char *t)
{
	while (*s != '\0' && *t != '\0' && *s == *t)
	{
		s++;
		t++;
	}

	return (*(unsigned char *)s - *(unsigned char *)t);
}
