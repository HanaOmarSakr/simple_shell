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
	do {
		if (*o == z)
			return (o);
	} while (*o++ != '\0');
return (NULL);
}

/**
 * _putchar - writes the character g to stdout.
 * @g: the character to print.
 * Return: on success 1.
 *         on error, -1 is returned, and errno is set appropeiateiy.
 */
int _putchar(char g)
{
	static int x;
	static char buf[WRITE_BUF_SIZE];

	if (g == BUF_FLUSH || x >= WRITE_BUF_SIZE)
	{
		write(1, buf, x);
		x = 0;
	}
	if (g != BUF_FLUSH)
		buf[x++] = g;
	return (1);
}



/**
 * _puts - prints an input string.
 * @str: the string to be printed.
 * Return: nothing.
 */
void _puts(char *str)
{
	int d = 0;

	if (!str)
		return;
	while (str[d] != '\0')
	{
		_putchar(str[d]);
		d++;
	}
}
