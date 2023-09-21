#include "main.h"

/**
 * _isatty - returns true if shell is interactive mode
 * @info: struct address
 *
 * Return: 1 if interactive mode, 0 otherwise
 */

int _isatty()
{
	if (!isatty(STDIN_FILENO))
	{
		return (0);  /* noninteractive mode */
	}

	return (1); /* interactive mode */
}
