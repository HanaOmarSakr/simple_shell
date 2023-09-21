#include "main.h"

/**
 * iscommand - ........
 * @path: ............
 * Return: ..........
*/
int iscommand(char *filepath)
{
	struct stat file_stat;

	if (filepath == NULL || stat(filepath, &file_stat) != 0)
	{
		return 0;
	}

	if ((file_stat.st_mode & S_IFMT) == S_IFREG)
	{
		return 1;
	}

	return 0;
}
