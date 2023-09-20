#include "main.h"

/**
 * _isatty - returns true if shell is interactive mode
 * @info: struct address
 *
 * Return: 1 if interactive mode, 0 otherwise
 */

int _isatty(info_t *info)
{
	if (!isatty(STDIN_FILENO))
	{
		return (0);  /* noninteractive mode */
	}

	if (info->readfd > 2)
	{
		return (0);
	}

	return (1); /* interactive mode */
}
