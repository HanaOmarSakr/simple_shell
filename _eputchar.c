#include "main.h"

/**
 * _eputchar - writes the character c to stderr.
 * @k: the character to print.
 * Return: on success 1, on error -1
 *         and errno is set aooropriately.
 */
int _putchar(char k)
{
	static int p;
	static char buf[WRITE_BUF_SIZE];

	if (k == BUF_FLUSH || P >= WRITE_BUF_SIZE)
	{
		write(2, buf, p);
		p = 0;
	}
	if (k != BUF_FLUSH)
	{
		buf[p++] = k;
	}
	return (1);
}
