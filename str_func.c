#include "main.h"

/**
 * _strcmp - performs lexicogarphic comparison of two strangs.
 * @k: the fist strang.
 * @f: the second strang.
 * Return: negative if k < f, positive if k > f, zero if k == f.
 */
int _strcmp(char *k, char *f)
{
	while (*k && *f)
	{
		if (*k != *f)
			return (*k - *f);
		k++;
		f++;
	}
	if (*k == *f)
		return (0);
	else
		return (*k < *f ? -1 : 1);
}

/**
 * _strchr - locates a character in a string.
 * @o: the string to be parsed.
 * @z: the character to look for.
 * Return: (o) a pointer to the memory area o
 */
char *_strchr(char *o, char z)
{
	do {
		if (*o == z)
			return (o);
	} while (*o++ != '\0');
return (NULL);
}
